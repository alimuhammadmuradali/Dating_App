#include<iostream>

using namespace std;



template <class T>
class Node {
// declare class List a friend so that it can access //Node's private vars.
//friend class List;

 public:
   // constructors
   Node()  { nextPtr = 0;  }
   Node(const T & d)  { data = d; nextPtr = 0; }
   Node(const T & d, Node<T> *n)
         {data = d; nextPtr = n; }
   void setNext(Node<T>* n){ this->nextPtr=n;}
   Node<T>* getNext(){ return this->nextPtr;}
   T& getData(){ return this->data;}
   void setData(const T & d){ data=d ;}
   T data;                     // data
   Node<T> *nextPtr;   // next node in the list
};

// The List will contain nodes linked together by pointers
template <class T>
class List {
public:
  List() { head = 0; size = 0; }  // constructor
  List(const List<T> &); // copy constructor
  ~List();     // destructor
  void deleteList();
  void removeAtFront();
  void insertAtLast(T );
  void removeAtLast();
  void print() const;
  int getSize() const  { return size;  }
  List<T>&  getHead(){ return  this->*head;}
  List<T>& operator = (const List<T> &);
  List<T>& ReverseList();
  void MoveTwice();
  DatingApplication();
 public:        
  Node<T> *head;  // pointer to first node
  int size;
};

// Destructor
template<class T>
List<T>::~List()
{
  deleteList();
  size = 0;
}


template<class T>
void List<T>::deleteList()
{
  if (head != 0) {    // List is not empty
     cout << "Destroying nodes ...\n";
     Node<T> *currentPtr = head;
     Node<T> *tempPtr;

     while ( currentPtr != 0 ) {  // not end of list
        tempPtr = currentPtr;
        cout << "Deleting " << tempPtr->data << endl;
        currentPtr = currentPtr->nextPtr; // move ptr
        delete tempPtr; // delete last node
     }
  }
  cout << "All nodes destroyed\n\n";
}

template<class T>
void List<T>::insertAtLast(T value )
{
   // create a new node with the value in it.
   Node<T> *temp= new Node<T>(value , 0);
   Node<T> *current = head;
   if (head !=0)
   {
   	while(current->nextPtr !=0) { current=current->nextPtr; }
   	current->nextPtr = temp;
   }else
   {
   	head = temp;
   }
   size++;
  // temp=0;
}


// Delete a node from the end of the list
template<class T>
void List<T>::removeAtLast()
{
  if ( head == 0 )             // List is empty
  {cout << "Error: list is empty!\n";}
  Node<T> *temp = head;
  while(temp->nextPtr !=0) { temp=temp->nextPtr; }
  cout <<"Deleting " << temp->data << endl;// deleting data or pointer//
  delete temp;
  --size;
  }

// Delete a node from the front of the list
template<class T>
void List<T>::removeAtFront()
{
  if ( head == 0 )             // List is empty
      cout << "Error: list is empty!\n";
  else {
     Node<T> *tempPtr = head;
     cout <<"Deleting " << tempPtr->data << endl;
     head = head->nextPtr; // move to next node
     delete tempPtr;
     size--;
  }
}


// Display the contents of the List
template<class T>
void List<T>::print() const
{
  if ( head == 0 ) {
     cout <<"The list is empty\n\n";
  }
  else   {
    Node<T> *currentPtr = head;
    cout <<"The list's Contents are : ";
    while ( currentPtr != 0 ) { // not end of list
        cout <<currentPtr->data << " -> ";
        currentPtr = currentPtr->nextPtr;
    }
    cout <<"\n";
  }
}


// copy constructor
template<class T>
List<T>::List(const List<T> &rhs) {
  this.size = rhs.size;
  this->head = 0;
  Node<T> *ptr = rhs.head;
  Node<T> *newPtr, *lastPtr;
  while (ptr != 0) {
      // create a new node with the value in it.
      newPtr = new Node<T>(ptr->data);
      assert(newPtr != 0);
      if(head == 0)
        head = newPtr; // first node
      else
         lastPtr->nextPtr = newPtr; // set up last link
      lastPtr = newPtr; // save last ptr
      ptr = ptr->nextPtr; // move up ptr
 }
}


// assignment operator
template<class T>
List<T> & List<T>::operator =(const List<T> &rhs) {
  if (this != &rhs) {
      deleteList();
      size = rhs.size;
      head = 0;
      Node<T> *ptr = rhs.head;
      Node<T> *newPtr, *lastPtr;
      while (ptr != 0) {
        // create a new node with the value in it.
        newPtr = new Node<T>(ptr->data);
        assert(newPtr != 0);
        if(head == 0)
          head = newPtr; // first node
        else
        lastPtr->nextPtr = newPtr; // set up last link
        lastPtr = newPtr; // save last ptr
        ptr = ptr->nextPtr; // move up ptr
     }
     return(*this);
 }
 
}
 
template<class T>
void List<T>::MoveTwice()
{
	Node<T> *current = head->nextPtr->nextPtr;
	head = current;
}

template<class T>
void List<T>::DatingApplication()
{
	
}



