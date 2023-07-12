#include "Singlylinkedlist.h"
#include <iostream>

    namespace MyLinkedList {
    template <typename T>
    SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}

    template <typename T>
    SinglyLinkedList<T>::~SinglyLinkedList() {
        DeleteAll();
    }

    template <typename T>
    void SinglyLinkedList<T>::AddToTail(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    template <typename T>
    void SinglyLinkedList<T>::DeleteFromHead() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete from head." << std::endl;
            return;
        }

        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }

    template <typename T>
    void SinglyLinkedList<T>::DeleteFromTail() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete from tail." << std::endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    template <typename T>
    void SinglyLinkedList<T>::DeleteAll() {
        while (head != nullptr) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
    }

    template <typename T>
    void SinglyLinkedList<T>::Show() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    template <typename T>
    void SinglyLinkedList<T>::InsertAtPosition(const T& value, int position) {
        if (position < 0) {
            std::cout << "Invalid position. Cannot insert element." << std::endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            std::cout << "Invalid position. Cannot insert element." << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    template <typename T>
    void SinglyLinkedList<T>::DeleteAtPosition(int position) {
        if (position < 0) {
            std::cout << "Invalid position. Cannot delete element." << std::endl;
            return;
        }

        if (position == 0) {
            DeleteFromHead();
            return;
        }

        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr || current->next == nullptr) {
            std::cout << "Invalid position. Cannot delete element." << std::endl;
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    template <typename T>
    typename SinglyLinkedList<T>::Node* SinglyLinkedList<T>::Find(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    template <typename T>
    int SinglyLinkedList<T>::Replace(const T& oldValue, const T& newValue) {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldValue) {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }
        return count;
    }

    template <typename T>
    void SinglyLinkedList<T>::Reverse() {
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head = previous;
    }

    template <typename T>
    int SinglyLinkedList<T>::FindElement(T value) {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }

        return -1;

    };