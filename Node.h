#include<iostream>
#include <bits/stdc++.h> 
#define questions 22

using namespace std;
template <class T>
class Node
{

public:
	
	T data;             
    Node<T> *nextPtr;   	

    Node()
    {
    	nextPtr = 0;  
 	}
 	
    Node(const T & d)  
	{ 
	 	data = d; 
	 	nextPtr = 0; 
	}
   
    Node(const T & d, Node<T> *n)
    {
	 	data = d; 
		nextPtr = n; 
	}
   
    void setNext(Node<T>* n)
	{
	 	this->nextPtr=n;
	}
   
    Node<T>* getNext()
	{ 
	 	return this->nextPtr;
	}
	
    T& getData()
	{ 
	 	return this->data;
	}
   
    void setData(const T & d)
	{ 
	 	data=d ;
 	}
};

