#include<iostream>
#include<string>
#include "LinkedList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"

using namespace std;

void singlyLinkedList(LinkedList &linked_list);
void doublyLinkedList(LinkedList &linked_list);
void circularLinkedList(LinkedList &linked_list);

int main(){
 LinkedList linked_list;
 int choice;
 bool exit_program = false;
 
 do{

  cout << linked_list.displayTitle();
  cout << linked_list.displayMenu();

  cout << "\n\n< Enter from 1 to 4 >";
  cout << "\nWhat do you want to do?: ";
  cin >> choice;

   switch (choice){
    case 1:
     singlyLinkedList(linked_list);
     break;
    case 2:
     doublyLinkedList(linked_list);
     break;
    case 3:
     circularLinkedList(linked_list);
     break;
    default:
     exit_program = true;
     cout << "\nThank you for using this app.\n";
     break;
    }

 }while(!exit_program);

 return 0;
}

void singlyLinkedList(LinkedList &linked_list){
 linked_list.header("Singly Linked List");
 cout << "\n";
 SinglyLinkedList<int> list; // head = nullptr
 
 list.insert(40);
 list.insert(20);
 list.insert(10);
 list.insert(30);
 list.insert(50);
 // 50 -> 30 -> 10 -> 20 -> 40 -> nullptr

 cout << "\n\nUnsorted Linked List: ";
 list.print();
 list.sortByAscendingOrder();
 cout << "\n\nAscending Order Linked List: ";
 list.print();
}

void doublyLinkedList(LinkedList &linked_list){
 linked_list.header("Doubly Linked List");
 cout << "\n";

  // Create a doubly linked list
  DoublyLinkedList<int> list;

// 2 4 1 5

  // Insert elements into the list
  list.insertFront(4); // 4
  list.insertFront(2); // ? (prev) 2 <-> 4
  // list.insertFront(5) // 5 (next) <-> (prev) 2 (next) <-> (prev) 4
  list.insertEnd(1); // 1
  list.insertEnd(5); // 1 -> 5
  // 2 -> 4 -> 1 -> 5
  // 
  // list.insertEnd(1); // 2 -> 4 -> 1
  // list.insertEnd(5); // 2 -> 4 -> 1 -> 5

  // std::cout << "\n\nUnsorted Linked List: ";
  // list.print();

  // Print the list forward
  std::cout << "List forward: ";
  list.printForward();

  // Print the list backward
  std::cout << "List backward: ";
  list.printBackward();
}

void circularLinkedList(LinkedList &linked_list){
  linked_list.header("Circular Linked List");
  cout << "\n";

  {
    CircularLinkedList<int> list;

    // Insert elements into the list
    list.insertEnd(5);
    list.insertEnd(4);
    list.insertEnd(3);
    list.insertEnd(1);
    // list.insertEnd(2);
    // 5 -> 4 -> 3 -> 1 -> 2

    // Print the list
    std::cout << "Circular Linked List: ";
    list.printList();
  } 
  
}
