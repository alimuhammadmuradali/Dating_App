#include<iostream>
#include <bits/stdc++.h> 
#include"HeapHeader.h"

using namespace std;


Heap::Heap():Current(-1) , Size(1000) 
{
	data = new UserPreference[Size];
	memset(this->data , 0 , sizeof( UserPreference) * Size);
}

Heap::Heap(int size):Current(-1)
{
	this->Size = size;
	data = new UserPreference[Size];
	memset(this->data , 0 , sizeof( UserPreference) * Size);
}

Heap::Heap(const Heap &rhs)
{
	this->Size = rhs.Size;
	this->Current = rhs.Current;
		  data = rhs.data;
}

Heap& Heap :: operator = (const Heap  &rhs)
{
	if(this != &rhs)
	{
		delete[] data;
		data = 0 ; Size = 0; Current = -1;
		this->Size = rhs.Size;
		this->Current = rhs.Current;
		data = rhs.data;
	}
}

Heap :: ~Heap()
{
	if(data != 0)
	{
		delete[] data;
		Current = -1;
		Size = 0;
		data = 0;
	}
}

void Heap::Delete()
{
	UserPreference temp = ExtractMax();
	for(int i = 0 ; i <=Current ; i++)
	{
		data[i].P_id = 0;
		data[i].UserTotal = 0.0;
	}
	Current = -1;
	Push(temp.UserTotal , temp.P_id);
}

void Heap ::Display()
{
	for(int i = 0 ; i <=Current ; i++)
	{
		cout<<data[i].P_id<<" "<<data[i].UserTotal<<endl;
	}
}

void Heap :: Push(double UserPreference , int id)
{
	Current++;
	data[Current].UserTotal = UserPreference;
	data[Current].P_id = id;
	Current++;
	Upheap();
}

UserPreference& Heap :: ExtractMax()
{
	UserPreference temp;
	temp.P_id = data[0].P_id;
	temp.UserTotal = data[0].UserTotal;
	data[0].P_id = data[Current].P_id ;
	data[0].UserTotal = data[Current].UserTotal ;
	Current--;
	Downheap();
}

void Heap :: Upheap()
{
	UserPreference temp;
	temp.P_id = data[Current].P_id;
	temp.UserTotal = data[Current].UserTotal;
	int index = Current;
	while(data[index/2].UserTotal < temp.UserTotal && index > 0)
	{
			data[index].P_id = data[index/2].P_id;
			data[index].UserTotal= data[index/2].UserTotal;
			index = index / 2;
	}
	 data[index].P_id = temp.P_id ;
	 data[index].UserTotal = temp.UserTotal ;
}
void Heap :: Downheap()
{
	int end = Current; int i = 0;
	int largest = 2 * i + 1;
	while(largest <= end)
	{
		if(largest < end && data[largest].UserTotal < data[largest+1].UserTotal)
		{
			largest++;
		}
		if(data[i].UserTotal < data[largest].UserTotal)
		{
			swap(data[i] , data[largest]);
			i = largest;
			largest = 2 * i +1;
		}else largest+1;
	}
}

