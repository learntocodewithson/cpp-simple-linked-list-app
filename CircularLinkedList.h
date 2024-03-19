#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
// Node structure for a circular linked list
 template <typename T>
 class CircularNode {
  public:
   T data;         // Data stored in the node
   CircularNode* next;     // Pointer to the next node in the list

   // Constructor to initialize a node with data and next pointer
   CircularNode(T newData) : data(newData), next(nullptr) {}
   /*
        CircularNode(T newData){
            data = newData;
            next = nullptr;
        }
   */
 };

 // Circular linked list class
 template <typename T>
 class CircularLinkedList {
  CircularNode<T>* head;   // Pointer to the first node in the list
  
  public:
   // Constructor
   CircularLinkedList() : head(nullptr) {}
   /*
    CircularLinkedList(){
     head = nullptr;
    }
   */

   // Destructor
   ~CircularLinkedList() {
    if (head == nullptr) {
        return;
    }

    CircularNode<T>* current = head->next;
    while (current != head) {
        CircularNode<T>* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
   }

   // Function to insert a new node at the end of the list
   void insertEnd(T newData) {
    // 5
       CircularNode<T>* newNode = new CircularNode<T>(newData);
    //    std::cout << "\nHEAD = " << head;
       if (head == nullptr) {
           head = newNode; // 5
           std::cout << "\nNEW HEAD: " << newNode->data;
           head->next = head;  // Point back to itself to form circular structure
           std::cout << "\nNEXT HEAD: " << head->next->data; // 5
       } else {
           CircularNode<T>* current = head;
           std::cout << "\nCurrent Data: " << current->data;
           std::cout << "\nCurrent NEXT Data: " << current->next->data;
           std::cout << "\ncurrent->next != head ? " << (current->next != head);
           // 5 4 3 1
           while (current->next != head) {
            // initial node is head (5)
            // for traversing from head to the last but check the next pointer
            // if next pointer will be the same to head, exit loop

                // std::cout << "\nCurrent data in while loop: " << current->next->data;
               current = current->next;
                std::cout << "\nCurrent data in while loop: " << current->data;
                // 4
                // 3
           }
           current->next = newNode; // 1
           std::cout << "\nCurrent NEXT Data: " << current->next->data;
           newNode->next = head;  // Point back to the head to complete the circle
           // 5(head) 4(newNode)-> next(5) -> head
           std::cout << "\nNEXT new node Data: " << newNode->next->data;
       }
       std::cout << "\n\n";
   }

   // Function to print the elements of the list
   void printList() const {
       if (head == nullptr) {
           return; 
       }

       CircularNode<T>* current = head;
       do {
           std::cout << current->data << " ";
           current = current->next;
       } while (current != head);
       std::cout << std::endl;
   }
};
#endif