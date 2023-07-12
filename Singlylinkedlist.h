#pragma once
namespace MyLinkedList {
    template <typename T>
    class SinglyLinkedList {
    private:
        struct Node {
            T data;
            Node* next;
        };

        Node* head;

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void AddToTail(const T& value);
        void DeleteFromHead();
        void DeleteFromTail();
        void DeleteAll();
        void Show() const;
        void InsertAtPosition(const T& value, int position);
        void DeleteAtPosition(int position);
        Node* Find(const T& value) const;
        int Replace(const T& oldValue, const T& newValue);
        void Reverse();
        int FindElement(T value);
    };
}
