// 5.1.PE4ALBA-DynArray.cpp
#include <iostream>
using namespace std;

int* boxes = NULL ; // dynArray can NOT be short type, however a vector CAN be short.
int n, p, q,
	k,  currentBox, tmp,
	profit ;
void finish ()
{ // finish() CLOSES and prepare to EXIT.
	if (boxes != NULL) // if the array is not empty then
	{ 	// to get memory back as a free, re-usable memory.
		delete [] boxes ; // to reuse memory
		boxes = NULL ;	 // to reuse an array name 
	} ;
	cout <<profit ;
	return ;
}

int main ()
{
	cin >>n ; // number of array components, boxes
	boxes = new int [n] ; // to allocate memory now.

	for (k=0; k<n; k++)	// to init an array
		cin >>boxes[k] ;

	cin >>p >>q; // 3rd line

	for (profit=0, currentBox=p-1, k=0 ; k<q; k++)
		if (0==boxes[currentBox])
		{ // box TYPE 1
			profit = 0 ;
			finish() ;
			return 0;
		}
		else if (boxes[currentBox] >= 1 && boxes[currentBox] <= n)
		{ // box TYPE 2
			tmp = boxes[currentBox];
			//boxes[currentBox] = 0 ; // no key yet, i.e now it is box TYPE 1.
			currentBox = tmp - 1;
		}
		else
		{
			profit+=boxes[currentBox] ;
			currentBox = boxes[currentBox] % n ;
		}

	finish () ;
	return 0;
}
