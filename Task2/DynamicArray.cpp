#include "DynamicArray.h"
#include <string>

template<class T>
DynamicArray<T>::DynamicArray(int s)
{
		if(s <= 0)
	{
		throw "Invalid size provided";
		//throw error;
	}

	size = s;

	elements = new T*[size];
	for(int e = 0; e < size; e++)
	{
		elements[e] = 0;
	}
	numElements = 0;
	
	

}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	size=other.size;
	elements = new T*[size];
	
	for(int i=0;i<size;i++)
	{
		elements[i] =other.elements[i];
	}
	numElements=other.numElements;
	
}

template<class T>
DynamicArray<T>*DynamicArray<T>::clone()
{
	
	DynamicArray<T> *other=  new DynamicArray<T>(*this);
	
	return other;
	
}

template<class T>
DynamicArray<T>:: ~DynamicArray()
{
	for(int i=0;i<size;i++)
		delete elements[i];
	
	delete [] elements;
	elements=0;
}

template<class T>
void DynamicArray<T>:: insert(int index, T element)//re-check
{
	int newIndex=index;
	
	if(index<0)
		return;
	if(index>=size)
	{	
		resize(newIndex + 1);
	}
	if(elements[index]!=0)	
	{
		for(int y=size;y>=index;y--)
		{
			resize(newIndex + 1);
			if(elements[y])
			{
				elements[y+1]= elements[y];
			}
			else
			{
				elements[y+1]= elements[y];
			}
			newIndex++;
		}
		elements[index] = new T(element);
	} 
	else
	{
		elements[index] = new T(element);
	}

	numElements++;
	
}

template<class T>
T  DynamicArray<T>::remove(int index)
{	
	
	T other;
	
		if(elements[index] == 0)
		{
			throw "empty structure";
		}
		
		else
		{
			other=*(elements[index]);
			elements[index]=0;
			for(int i = index; i < size; i++)
			{
				elements[i] = elements[i + 1];
			}
			elements[size - 1] = 0;
		}
		numElements--;
	

	return other;
	
}

template<class T>
T DynamicArray<T>::get(int index) const
{	
	if(elements[index]==0)
	{
		throw "empty structure";
	}
	else if(index < 0 || index > numElements)
	{
		throw "invalid index";
	}
	return *(elements[index]);
	
}

template<class T>
bool DynamicArray<T>::isEmpty()
{
	if(numElements==0)
	{
		return true;
	}
	else
		return false;
	
}

template<class T>
void DynamicArray<T>:: clear()
{
	for(int s=0;s<size;s++)
	{
		elements[s]=0;
	}
	numElements=0;
}

template<class T>
void  DynamicArray<T>::resize(int howMuch)
{
		T** Array = new T *[howMuch];
		
		for(int i = 0; i < howMuch; i++)
		{
			Array[i] = 0;
		}
		
		if(howMuch < numElements)
		{
			for(int i = 0; i < howMuch; i++)
			{
				Array[i] = new T(*(elements[i]));
			}
			numElements = howMuch;
		}
		else
		{
			for(int i = 0; i < numElements; i++)
			{
				Array[i] = new T(*(elements[i]));
			}
		}
		
		delete [] elements;
		
		elements = Array;
		size = howMuch;
}