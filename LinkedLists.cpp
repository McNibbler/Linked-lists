/ * Signally linked list implementation in c++
  *  
  * Thomas Kaunzinger
  * May 7, 2018
  * 
  * References: codementor.io, Matt Stancliff
  * /

// Struct creation
struct cons{
  double data;
  cons *next;
};

// Lists class and all associated methods
class LinkedList{
  private:
  cons *head, *tail;  // important pointers (tail isn't really required, but useful)

  // Useful constructor to point to NULL to avoid unwanted address locations upon creation
  public:
  LinkedList(){
    head = NULL;
    tail = NULL;
  }

  // Creates the tail node of the cons linked list
  void newCons(double dataByte){
    cons *temporary = new cons;
    temporary->data = dataByte;
    temporary->next = NULL;
    if(head==NULL){
      head = temporary;
      tail = temporary;
      temporary = NULL;
    }
    else{
      tail->next = temporary;
      tail = temporary;
    }
  }

  // Creates a new cons at the front of the linked list and moves the header to point to this new node
  void frontInsert(double dataByte){
    cons *temporary = new cons;
    temporary->data = dataByte;
    temporary->next = head;
    head = temporary;
  }

  // Creates a temporary cons to reassign the header pointer to point to the next item in a list and deletes the temporary node
  void frontDelete(){
    cons *temporary = new cons;
    temporary = head;
    head = head->next;
    delete temporary;
  }

  // Dumb function to purge the contents of a list. Not even sure if it works.
  void purge(){
    tail = NULL;
    head = NULL;
  }

  // Prints all values out the serial communication port
  void printList(){
    cons *temporary = new cons;
    temporary = head;
    while(temporary != NULL){
      Serial.print(temporary->data);
      temporary = temporary->next;
    }
    Serial.println();
  }

  // Getters
  double getHead(){
    return head->data;
  }
  double getTail(){
    return tail->data;
  }
};