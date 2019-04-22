#ifndef CIRCULAR_QUEUE_
#define CIRCULAR_QUEUE_

#include <iostream>
using namespace std;

template <class type> 
class cir_queue
{

public:

	cir_queue(unsigned int size);

	cir_queue(void);

	~cir_queue(void);

	void push(type val);

	type pop(void);


private:

	unsigned int fix_size;
	unsigned int state_no;
	unsigned int first;
	unsigned int last;
	type *cir_array;

	void allocate_mem(void);

};

/* State 0 -> ready to write, but not read
 * State 1 -> ready to read, but not write
 * State 2 -> ready to both
 */
template <class type>
cir_queue<type>::cir_queue(unsigned int size)
{
	last  		= 0;
	first 		= 0;
	state_no 	= 0;
	fix_size 	= size;
	cir_array	= NULL;

	allocate_mem();
}

template <class type>
cir_queue<type>::cir_queue(void)
{
	last  		= 0;
	first 		= 0;
	state_no 	= 0;
	fix_size 	= 10;
	cir_array	= NULL;

	allocate_mem();
}

template <class type>
cir_queue<type>::~cir_queue(void)
{
	delete[] cir_array;
}

template <class type>
void cir_queue<type>::allocate_mem(void)
{
	cir_array = new type[fix_size];
}

template <class type>
void cir_queue<type>::push(type val)
{
	if (state_no == 1)
		cout << "Error writing, no space" <<endl;
	else
	{
		cir_array[last] = val;
		last = (last+1)%fix_size;
		
		if (last == first) state_no = 1;
		else state_no = 2;
	}
	return;
}

template <class type>
type cir_queue<type>::pop(void)
{
	if (state_no == 0)
		cout << "Error reading, empty queue" <<endl;
	else
	{
		type temp;
		temp = cir_array[first];
		first = (first+1)%fix_size;

		if (first == last) state_no = 0;
		else state_no = 2;

		return temp;

	}
	return 0;
}

#endif