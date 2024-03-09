#include<iostream>
#include<string>
#include "LinkedList.h"

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
}

void doublyLinkedList(LinkedList &linked_list){
 linked_list.header("Doubly Linked List");
}

void circularLinkedList(LinkedList &linked_list){
 linked_list.header("Circular Linked List");
}
