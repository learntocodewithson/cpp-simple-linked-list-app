#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
 template <typename T>
 class Node {
  public:
   T data;
   Node<T>* next;
 
   Node(T newData) : data(newData), next(nullptr) {}
   /*
    Node(T newData){
     data = newData;
     next = nullptr
    }
   */
 };
 
 template <typename T>
 class SinglyLinkedList {
  Node<T>* head; // nullptr

  public:
   SinglyLinkedList() : head(nullptr) {}
   /*
    SinglyLinkedList(){
     head = nullptr;
    }
   */
   
   // Insert at the beginning of the list
   void insert(T newData){
    Node<T>* newNode = new Node<T>(newData);
    if(head != nullptr)
     newNode->next = head;
    head = newNode;
   }

   // Print the list
   void print(){
    Node<T>* current = head;
    while(current != nullptr){
     std::cout << current->data << " ";
     current = current->next;
    }
    std::cout << "\n";
   }

   void sortByAscendingOrder(){
    // 50 -> 30 -> 10 -> 20 -> 40 -> nullptr
    // 50 <- 30 <- 10 <- 20 <- 40 <- nullptr
    // data[0] = 50 (head)
    // data[1] = 30
    // data[2] = 10
    // data[3] = 20
    // data[4] = 40
    // nullptr

    // bubble sort
    // Node<T>* current = head;
    if(head == nullptr || head->next == nullptr){
     return;  // Nothing to sort if list is empty or has only one element
    }

    // 
    bool swapped;
    // Node<T>* temp;
    Node<T>* end = nullptr;

    std::cout << "\n\tTemp Value: " << end;

    do {

     swapped = false;
     // head = head[0]
     Node<T>* current = head;
     // std::cout << "\n\tCurrent Value Data: " << current->data;

     // current->next == nullptr ? true
     // 50 30 10 20 40 -> nullptr(next)
     // std::cout << "\n\tcurrent->next(" << current->next << ") != end("<< end << ")";
     while(current->next != end){
      std::cout << "\n\tcurrent->data(" << current->data << ") > current->next->data("<< current->next->data << ")";
      if(current->data > current->next->data){
       T tempData = current->data;
       std::cout <<"\n\t Temp Data: " << tempData;
       current->data = current->next->data;
       std::cout <<"\n\t Current Data: " << current->data;
       current->next->data = tempData;
        std::cout <<"\n\t Current Next Data: " << current->next->data;
       swapped = true;
       std::cout << "\n\n\tCurrent List: ";
       print();
      }
      // 0
      // 1
      current = current->next;
     }

     end = current;
      std::cout << "\n\n\tEnd Current Value: " << end->data;
      std::cout << "\n-------------------------------------\n";
    } while(swapped);
   }
 };
#endif