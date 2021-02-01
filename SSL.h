#include "Node.h"
#include "HeapHeader.h"
#include<conio.h>
template <class T>
class List 
{
public:
  
  List() { head = 0; size = 0; } 
  List(const List<T> &); 
  ~List();    
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
  void DatingApplication();
  bool comparestring(string st1 , string st2);
  bool comparestrings(string st1 , string st2);
  
 public:        
  Node<T> *head;  // pointer to first node
  int size;
};


template<class T>
List<T>::~List()
{
  deleteList();
  size = 0;
}

template<class T>
void List<T>::deleteList()
{
    if (head != 0) 
    {   
      	cout << "Destroying nodes ...\n";
     	Node<T> *currentPtr = head;
     	Node<T> *tempPtr;

     	while ( currentPtr != 0 ) 
	 	{  
         	tempPtr = currentPtr;
        	cout << "Deleting " << tempPtr->data << endl;
         	currentPtr = currentPtr->nextPtr; 
         	delete tempPtr; 
     	}
   	}
 	
	cout << "All nodes destroyed\n\n";
}

template<class T>
void List<T>::insertAtLast(T value )
{
   Node<T> *temp= new Node<T>(value , 0);
   Node<T> *current = head;
   
   	if (head !=0)
    {
   	 	while(current->nextPtr !=0)
		{ 
		 	current=current->nextPtr; 
	 	}
   	 	
		current->nextPtr = temp;
    }
	else
    {
   	 	head = temp;
    }
    
	size++;
}

template<class T>
void List<T>::removeAtLast()
{
 	if ( head == 0 )          
   	{
	    cout << "Error: list is empty!\n";
	}
    else
    {
    	Node<T> *temp = head;
  
 	   	while(temp->nextPtr !=0) 
	 	{
	 	 	temp=temp->nextPtr;
 	  	}
  
   	 	cout <<"Deleting " << temp->data << endl;
 	   	delete temp;
   	 	--size;
	}
}

template<class T>
void List<T>::removeAtFront()
{
    if ( head == 0 )           
     	cout << "Error: list is empty!\n";
  
   	else 
	{
     	Node<T> *tempPtr = head;
     	cout <<"Deleting " << tempPtr->data << endl;
     	head = head->nextPtr; // move to next node
     	delete tempPtr;
     	size--;
   	}
}


template<class T>
void List<T>::print() const
{ 	
    Node<T> *currentPtr = head;
    int j=0;
    
    string information[12] = { "NAME" , "GENDER" , "GENDER PREFERENCE" , "AGE PREFERENCE" , "AGE",
		 "CAREER" , "RELATIONSHIP STATUS" , "FOOR PREFERENCE" , "RELIGION" , "MUSIC GENRE" ,"PET" , "PERSONALITY TYPE" };
    
    cout <<"Your Information : "<<endl;
    
	while ( currentPtr != 0 ) 
	{   
	    cout <<information[j]<<"  : " <<currentPtr->data <<endl;
	    j++;
        currentPtr = currentPtr->nextPtr;
    }
    cout <<"\n";
}

template<class T>
List<T>::List(const List<T> &rhs)
{
  	this.size = rhs.size;
   	this->head = 0;
   	Node<T> *ptr = rhs.head;
   	Node<T> *newPtr, *lastPtr;
   	
	while (ptr != 0)
	{
       	newPtr = new Node<T>(ptr->data);
       	assert(newPtr != 0);
      
	   	if(head == 0)
         	head = newPtr;
      
	   	else
          	lastPtr->nextPtr = newPtr; 
      
	   	lastPtr = newPtr;
      	ptr = ptr->nextPtr;
  	}
}


template<class T>
List<T> & List<T>::operator =(const List<T> &rhs)
{
  	if (this != &rhs) 
	{
       	deleteList();
       	size = rhs.size;
       	head = 0;
       	Node<T> *ptr = rhs.head;
       	Node<T> *newPtr, *lastPtr;
      
	   	while (ptr != 0) 
		{
         	newPtr = new Node<T>(ptr->data);
         	assert(newPtr != 0);
        
		 	if(head == 0)
           	head = newPtr; // first node
        
			else
			{
				lastPtr->nextPtr = newPtr; // set up last link
         	 	lastPtr = newPtr; // save last ptr
         	 	ptr = ptr->nextPtr; // move up ptr
			}
        }
  	}
  	return(*this);
 
}
 
 
template<class T>
bool List<T>::comparestring(string st1 , string st2)
{
  	 	if(st1 == st2)
  	 	{
  		 	return true;	
	 	}
		else
	 	{
		 	return false;
	 	}
}

template<class T>
bool List<T>::comparestrings(string st1 , string st2)
{
  	int size = st2.size();
  		
	if(st1.size() == size)
  	{
  		return true;
	}
	else
	{
		return false;
	}
} 

template<class T>
void List<T>::DatingApplication()
{
 	string line;
 	int lineNumber = 0;
 	int lineNumberSought = 2;  
 	
	ifstream myfile ("DataBase.csv");
 	
 	Heap *heap = new Heap(1000);
 	
	string input[12];
 	
	string Questions[questions] = {"WHAT IS YOUR NAME ?"
	,"SPECIFY YOUR GENDER?"
	,"SPECIFY YOUR GENDER PREFERENCE?\n""MALE\n""FEMALE\n"
 	,"WHAT SHOULD BE THE AGE OF YOUR UNKNOWN PARTNER ?" , "WHAT IS YOUR AGE?"
 	,"WHAT IS YOUR CAREER ?\n" "lawyer\n" "Economist\n"  "policy work\n"   "Banking\n"  "Corporate Lawyer\n"  "Corporate attorney\n"
 	,"WHAT IS YOUR RELATIONSHIP STATUS ?\n"  "SINGLE\n"  "MARRIED\n"
 	,"WHAT IS YOUR FOOD PREFERENCE ?\n""veg\n" "non-veg\n"  "semi-veg\n"
 	,"WHAT IS YOUR RELEGION?\n""ISLAM\n""HINDUSIM\n" "christianity\n"
 	,"WHAT IS YOUR MUSIC PREFERENCE ?\n""CLASSICAL\n" "JAZZ\n" "COUNTRY MUSIC\n""HIP-HOP\n"
 	,"WHAT IS YOUR FAVOURITE PET ?\n""DOG\n" "CAT\n""NONE\n"
 	,"WHAT IS YOUR FAVOURITE PERSONALITY TYPE ?\n""SJ\n" "SP\n" "NT\n"};

 	int j;
 	
	for(int i = 0 ; i < 12 ; i++)
 	{
	 	cout<<Questions[i]<<endl;
	 	getline(cin , input[i]); 
	 	insertAtLast(input[i]);
 	}

  	print();

 	int countComma = 0;
 	Node<T> *UserData = head->nextPtr->nextPtr->nextPtr->nextPtr;
 	Node<T> *Gender_Preference = head->nextPtr->nextPtr;
 	Node<T> *Age_Preference = head->nextPtr->nextPtr->nextPtr;
 	
	double Score = 0;
	string User_DataBase , Gender_DataBase , Age_DataBase;

	if (myfile.is_open()) 
	{
     	while (getline(myfile,line)) 
		{
   	     	lineNumber++;
   	    
            if(lineNumber == lineNumberSought) 
			{
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
					Gender_DataBase += line[l];
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
					Age_DataBase += line[l];
				}
				
				stringstream integer(Age_DataBase);
				stringstream integer1(Age_Preference->data);
				int AgeDataBase = 0;
				integer>>AgeDataBase;
				int UserAge = 0;
				integer1>>UserAge;
				
				if(comparestrings(Gender_DataBase , Gender_Preference->data) == 1)
				{ 	
					if(AgeDataBase <= UserAge)
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
				 	 	{
					  	 	int k;
					
					 	 	for(k =j ; line[k] != ','  ; k++ )
					 	 	{
						 		User_DataBase += line[k];
					 	 	}

 						 	if(comparestring(User_DataBase , UserData->data) == 1)
	 					 	{
		 					 	Score += 100;

					 	 	}
						 	else
					 	 	{
						 	 	Score+= 0;
					 	 	}
					 	
					 	 	if(UserData->nextPtr != 0)
					 		 	UserData = UserData->nextPtr;
					 	
						  	User_DataBase = "";
					 	 	j = k;
				 		}
				 	}
				}
			
				Gender_DataBase = "";
				Age_DataBase = "";
				UserData = head->nextPtr->nextPtr->nextPtr->nextPtr;
				if(Score !=0 )
				heap->Push((Score/9) ,line);
                lineNumber++;
                lineNumberSought+=2;
                Score = 0;
            }
        }
        myfile.close();
       heap->Display();
    }
}

