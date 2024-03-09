#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 class LinkedList {
  public:
   std::string displayLine(){
    return "===========================";
   }

   std::string displayTitle(){
    return "\n\t" + displayLine() + "\n\tSimple Linked List App\n";
   }

   std::string displayMenu(){
    return "\t\tMain Menu\n"
     "\t1.) Singly Linked List\n"
     "\t2.) Doubly Linked List\n"
     "\t3.) Circular Linked List\n"
     "\t4.) Exit\n\t" + 
     displayLine();
   }

   void header(std::string title){
    std::cout << displayLine();
    std::cout << title;
    std::cout << displayLine();
   }
 };
#endif