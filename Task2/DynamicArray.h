#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "LinearStructure.h"

template<class T>
class DynamicArray : public LinearStructure<T>
{
	public:
		
		DynamicArray(int s);
		
		DynamicArray(const DynamicArray<T>& other);
		
		virtual DynamicArray<T>* clone();
		
		virtual ~DynamicArray();
		
		virtual void insert(int index, T element);
		
		virtual T remove(int index);
		
		virtual T get(int index) const;
		
		virtual bool isEmpty();
		
		
		virtual void clear();
		
	private:
		
		void resize(int howMuch);
				
		T ** elements;
		
		int size;

		int numElements;
};

#include "DynamicArray.cpp"

#endif
