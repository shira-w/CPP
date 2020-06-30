#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

Box box99;
Box box88;
Box largeBox;
int flagB99=0;
int flagB88=0;
extern const char* message;

void _Z8thisFuncv()
{
    	printf("\n--- thisFunc() ---\n\n"); 
	if (flagB99==0)
	{
		_ZN3BoxC1Eddd(&box99,99, 99, 99);
		flagB99=1;
	}
    	_ZN3BoxmLEd(&box99,10);
}

void _Z8thatFuncv()
{
    	printf("\n--- thatFunc() ---\n\n"); 
	if(flagB88==0)
	{
    		_ZN3BoxC1Eddd(&box88,88, 88, 88);
		flagB88=1;
	}
	_ZN3BoxmLEd(&box88 ,10);
}

void  _Z7doBoxesv()
{
    	Box b1, b2, b3, b4;
	printf("\n--- Start doBoxes() ---\n\n");
	_ZN3BoxC1Ed(&b1,3);
	_ZN3BoxC1Eddd(&b2,4, 5, 6);
    
    	printf("b1 volume: %f\n", b1.length*b1.width*b1.height);
    	printf("b2 volume: %f\n", b2.length*b2.width*b2.height);

    	_ZN3BoxmLEd(&b1,1.5);
    	_ZN3BoxmLEd(&b2,0.5);

    	printf("b1 volume: %f\n",b1.length*b1.width*b1.height);
    	printf("b2 volume: %f\n",b2.length*b2.width*b2.height);
	
	b3=b2;
   
	b4=b2;
	_ZN3BoxmLEd(&b4,3);

    	printf("b3 does not equal b4\n");

    	_ZN3BoxmLEd(&b3, 1.5);
    	_ZN3BoxmLEd(&b4 , 0.5);
	
  	 printf("Now, b3 equals b4\n");
	_ZN3BoxD1Ev(&b4);
	_ZN3BoxD1Ev(&b3);
	_ZN3BoxD1Ev(&b2);
	_ZN3BoxD1Ev(&b1);
    	printf("\n--- End doBoxes() ---\n\n");
}


void _Z9doShelvesv()
{
    	Box aBox, b7, b8, b9,btemp;
	Shelf aShelf;

	printf("\n--- start doShelves() ---\n\n");
	
	_ZN3BoxC1Ed(&aBox, 5);
    	
	_ZN3BoxC1Ed(&b7,1);
	aShelf.boxes[0]=b7;
	_ZN3BoxC1Ed(&b8,1);
	aShelf.boxes[1]=b8;
	_ZN3BoxC1Ed(&b9,1);
	aShelf.boxes[2]=b9;
	
    	_ZNK5Shelf5printEv(&aShelf);
    	_ZN5Shelf6setBoxEiRK3Box(&aShelf,1, &largeBox);
    	_ZN5Shelf6setBoxEiRK3Box(&aShelf,0, &aBox);

    	_ZNK5Shelf5printEv(&aShelf);
    	message ="This is the total volume on the shelf:";
    	_ZNK5Shelf5printEv(&aShelf);
    	message="Shelf's volume:";
     	_ZNK5Shelf5printEv(&aShelf);
	
	_ZN3BoxC1Eddd(&btemp,2, 4, 6);
     	_ZN5Shelf6setBoxEiRK3Box(&aShelf,1, &btemp);

	_ZN3BoxC1Ed(&btemp,2);
     	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 2,&btemp);

    	_ZNK5Shelf5printEv(&aShelf);
	_ZN3BoxD1Ev(&(aShelf.boxes[0]));
	_ZN3BoxD1Ev(&(aShelf.boxes[1]));
	_ZN3BoxD1Ev(&(aShelf.boxes[2]));
    	printf("\n--- end doShelves() ---\n\n");
}

int main()
{
    	_ZN3BoxC1Eddd(&largeBox,10, 20, 30);
     	printf("\n--- Start main() ---\n\n");

     	_Z7doBoxesv();

    	_Z8thisFuncv();
    	_Z8thisFuncv();
    	_Z8thisFuncv();
    	_Z8thatFuncv();
    	_Z8thatFuncv();

    	_Z9doShelvesv();
        
    	printf("\n--- End main() ---\n\n");
	if(flagB99==1)
		_ZN3BoxD1Ev(&box99);
	if(flagB88==1)
		_ZN3BoxD1Ev(&box88);
	_ZN3BoxD1Ev(&largeBox);

    return 0;
}

