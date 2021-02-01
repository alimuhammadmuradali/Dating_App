#include<iostream>
#include"HeapHeader.h"

using namespace std;
int main()
{
	Heap *heap = new Heap;
	heap->Push(10 , 23);
	heap->Push(2 , 3);
	heap->Push(11 , 24);
	heap->Push(44 , 11);
	heap->Push(55 , 11);
	heap->Push(100 , 13);
	heap->Push(56 , 13);
	heap->Push(101 , 15);
	heap->Display();
	cout<<endl;
	heap->ExtractMax();
	heap->Display();
	cout<<endl;
	heap->ExtractMax();
	heap->Display();
	return 0;
}
