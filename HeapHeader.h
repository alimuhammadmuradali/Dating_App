#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

struct UserPreference
{
	double UserTotal;// preference total of the user
	int P_id; // the unique id of the user
};
class Heap
{
private:
	UserPreference *data; // preference of the user
	int Size; //total size of the heap
	int Current;//points to the current position in arrray
public:
	
Heap():Current(-1) , Size(1000) 
{
	data = new UserPreference[Size];
	memset(this->data , 0 , sizeof( UserPreference) * Size);
}

Heap(int size):Current(-1)
{
	this->Size = size;
	data = new UserPreference[Size];
	memset(this->data , 0 , sizeof( UserPreference) * Size);
}
Heap(const Heap &rhs)
{
	this->Size = rhs.Size;
	this->Current = rhs.Current;
		  data = rhs.data;
}

Heap&  operator = (const Heap  &rhs)
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

~Heap()
{
	if(data != 0)
	{
		delete[] data;
		Current = -1;
		Size = 0;
		data = 0;
	}
}

void Delete()
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

void Display()
{
	for(int i = 0 ; i <=Current ; i++)
	{
		cout<<"UserTotal = "<<data[i].UserTotal<<" P_id = "<<data[i].P_id<<endl;
	}
}

void Push(double UserPreference , int id)
{
	Current++;
	data[Current].UserTotal = UserPreference;
	data[Current].P_id = id;
	Upheap();
}

UserPreference& ExtractMax()
{
	UserPreference temp;
	temp.P_id = data[0].P_id;
	temp.UserTotal = data[0].UserTotal;
	data[0].P_id = data[Current].P_id ;
	data[0].UserTotal = data[Current].UserTotal ;
	Current--;
	Downheap();
}

void Upheap()
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
void Downheap()
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
};
