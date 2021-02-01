#include "SSL.h"


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
string line, csvItem;
ifstream myfile ("DataBase.csv");
int lineNumber = 0;
int lineNumberSought = 2;  // you may get it as argument
Heap *heap = new Heap(1000);
string input[12];
string Questions[questions] = {"WHAT IS YOUR NAME ?"
,"SPECIFY YOUR GENDER?"
,"SPECIFY YOUR GENDER PREFERENCE?\n""MALE\n""FEMALE\n"
,"WHAT SHOULD BE THE AGE OF YOUR UNKNOWN PARTNER ?"
,"WHAT IS YOUR AGE?"
,"WHAT IS YOUR CAREER ?\n" "lawyer\n" "Economist\n"  "policy work\n"   "Banking\n"  "Corporate Lawyer\n"  "Corporate attorney\n"
,"WHAT IS YOUR RELATIONSHIP STATUS ?\n"  "SINGLE\n"  "MARRIED\n"
,"WHAT IS YOUR FOOD PREFERENCE ?\n""veg\n" "non-veg\n"  "semi-veg\n"
,"WHAT IS YOUR RELEGION?\n""ISLAM\n""HINDUSIM\n" "christianity\n"
,"WHAT IS YOUR MUSIC PREFERENCE ?\n""CLASSICAL\n" "JAZZ\n" "COUNTRY MUSIC\n""HIP-HOP\n"
,"WHAT IS YOUR FAVOURITE PET ?\n""DOG\n" "CAT\n""NONE\n"
,"WHAT IS YOUR FAVOURITE PERSONALITY TYPE ?\n""SJ\n" "SP\n" "NT\n"
};
int j;
for(int i = 0 ; i < 12 ; i++)
{
	cout<<Questions[i]<<endl;
	getline(cin , input[i]); 
	insertAtLast(input[i]);
}

cout<<"display"<<endl;
print();
int countComma = 0;
Node<T> *current = head->nextPtr->nextPtr->nextPtr->nextPtr;
Node<T> *current2 = head->nextPtr->nextPtr;
Node<T> *current1 = head->nextPtr->nextPtr->nextPtr;
double Score = 0;
int count = 0;
int term = 0;
string temp , temp2 , temp1;
if (myfile.is_open()) {
     while (getline(myfile,line)) {
   	    lineNumber++;
   	    
            if(lineNumber == lineNumberSought) {
            	int i = 0;
            	for( i = 0 ;  countComma != 2  ; i++)
                {
                	if(line[i] == ',')
                	{
                		countComma++;
					}
				}
				countComma = 0;
					for(int l =i ; line[l] != ','  ; l++ )
					{
						temp2 += line[l];
					}
				for( i = 0 ;  countComma != 5  ; i++)
                {
                	if(line[i] == ',')
                	{
                		countComma++;
					}
				}
				countComma = 0;
				for(int l =i ; line[l] != ','  ; l++ )
				{
					temp1 += line[l];
				}
				stringstream integer(temp1);
				stringstream integer1(current1->data);
				int age = 0;
				integer>>age;
				int age1 = 0;
				integer1>>age1;
				
				if(comparestrings(temp2 , current2->data) == 1)
				{ 	
					if(age <= age1)
					{
					
					Score += 200;
			
                for( i = 0 ;  countComma != 5  ; i++)
                {
                	if(line[i] == ',')
                	{
                		countComma++;
					}
				}
				countComma = 0;
			
				for(int j = i ; j< line.size() ; j++)
				{int k;
					for(k =j ; line[k] != ','  ; k++ )
					{
						temp += line[k];
					}
				//	temp[k]='\0';
					//cout<<temp<<" "<<current->data<<endl;
					if(comparestring(temp , current->data) == 1)
					{
						Score += 100;
						//cout<<temp<<" "<<current->data<<endl;
					//	cout<<Score<<endl;
					}else
					{
				//		cout<<temp<<" "<<current->data<<endl;
						Score+= 0;
					}
					if(current->nextPtr != 0)
					current = current->nextPtr;
					temp = "";
					j = k;
				}
				}
				}
				count++;
				temp2 = "";
				temp1 = "";
				current = head->nextPtr->nextPtr->nextPtr->nextPtr;
				current1 = head->nextPtr->nextPtr->nextPtr;
				current2 = head->nextPtr->nextPtr;
				if(Score !=0 )
				heap->Push((Score/9) ,line);
                lineNumber++;
                lineNumberSought+=2;
                
                if(count == 10)
                {
                //	heap->Delete();
                	count = 0;
				}
				Score = 0;
            }
        }
        myfile.close();
       heap->Display();
    }
}

