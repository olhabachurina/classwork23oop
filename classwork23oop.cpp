// classwork23oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"Singlylinkedlist.h"
#include <iostream>
int main() {
    MyLinkedList::SinglyLinkedList<int> list;
    list.AddToTail(4);
    list.Show();
    list.InsertAtPosition(5, 1);
    list.Show();
    list.DeleteAtPosition(2);
    list.Show();
    int position = list.FindElement(5);
    if (position != -1) {
        std::cout << "Element found at position: " << position << std::endl;
    }
    else {
        std::cout << "Element not found." << std::endl;
    }
    int replacements = list.Replace(2, 6);
    std::cout << "Replaced " << replacements << " element(s)." << std::endl;
    list.Show();
    list.Reverse();
    list.Show();
    list.DeleteAll();
    list.Show();
    list.DeleteFromHead();
    list.DeleteFromTail();
    list.Show();

    list.DeleteAll();
    list.Show();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
