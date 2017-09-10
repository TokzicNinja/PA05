#ifndef LINEARSTRUCTURE_H
#define LINEARSTRUCTURE_H

#include <iostream>

using namespace std;

template<class T>
class LinearStructure
{
	public:
		
		virtual ~LinearStructure(){}
		
		virtual LinearStructure<T>* clone() = 0;
		
		virtual void insert(int index, T element) = 0;
		
		virtual T remove(int index) = 0;
		
		virtual T get(int index) const = 0;
				
		virtual bool isEmpty() = 0;
		
		virtual void clear() = 0;
	
};
 
#endif
