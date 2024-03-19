#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
 template <typename T>
 class DoublyNode {
  public:
  T data;
  DoublyNode* prev;
  DoublyNode* next;

  DoublyNode(T newData){
   data = newData;
   prev = nullptr;
   next = nullptr;
  }
 };

 template <typename T>
 class DoublyLinkedList {
  DoublyNode<T> * head;
  DoublyNode<T> * tail;

  public:
   // Constructor
   DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
   }

   // Destructor
   ~DoublyLinkedList(){
    while(head != nullptr){
     DoublyNode<T>*  temp = head;
     head = head->next;
     delete temp;
    }
   }
  
   void print(){
    DoublyNode<T>* current = head;
    while(current != nullptr){
     std::cout << current->data << " ";
     current = current->next;
    }
    std::cout << "\n";
   }

   void insertFront(T newData){
     DoublyNode<T>* newNode = new DoublyNode<T>(newData);
     if (head == nullptr) {
         head = tail = newNode;
         std::cout << "\nHEAD: " << head->data;
         std::cout << "\nTAIL: " << tail->data;
         std::cout << "\n";
     } else {
        //  (prev)<- NODE(2) ->(next)
         newNode->next = head; // 2 (next) -> 4
         std::cout << "\nNEW NODE: " << newNode->data;
         head->prev = newNode; // 2 <- (prev) 4
         std::cout << "\nPrev Node: " << head->prev->data;
         head = newNode; // head = 2
         std::cout << "\n HEAD Next Node: " << head->next->data;
         std::cout << "\n HEAD Prev Node: " << head->next->prev->data;
     }
      std::cout << "\n";

    
   }

    // Function to insert a new node at the end of the list
    void insertEnd(T newData) {
        DoublyNode<T>* newNode = new DoublyNode<T>(newData);
        if (tail == nullptr) {
            head = tail = newNode;
            std::cout << "\nHEAD: " << head->data;
            std::cout << "\nTAIL: " << tail->data;
            std::cout << "\n";
        } else {
            // (add here) <-- HEAD TAIL --> (add here)
            tail->next = newNode;
            std::cout << "\nTail Next Node: " << newNode->data; 
            newNode->prev = tail;
            std::cout << "\nNew Node Prev: " << newNode->prev->data;
            tail = newNode;
            std::cout << "\nTail Node: " << tail->data;

            std::cout << "\n Tail Prev Node: " << tail->prev->data;
            std::cout << "\n Tail NExt Node: " << tail->prev->next->data;
        }
          std::cout << "\n";
    }

    // Function to print the elements of the list forward
    void printForward() const {
        DoublyNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next; // ->>>>
        }
        std::cout << std::endl;
    }

    // Function to print the elements of the list backward
    void printBackward() const {
        DoublyNode<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev; // <<<<--
        }
        std::cout << std::endl;
     }
 };
#endif