#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/*Box*/

 void _ZN3BoxC1Ed(Box* const b, double dim) /*Box::constractor*/
{ 
	b->length=dim;
	b->width=dim;
	b->height=dim; 
	_ZNK3Box5printEv(b);
}

void _ZN3BoxC1Eddd(Box* const b, double l, double w, double h) /*Box::constractor2*/
{ 
  	b->length=l;
	b->width=w;
	b->height=h; 
	_ZNK3Box5printEv(b); 
}

void _ZN3BoxD1Ev(Box* const b)/*Box::distractor*/
{
    printf("Box destructor, %f x %f x %f\n", b->width, b->height, b->length);
}

Box _ZN3BoxmLEd(Box* const b, double mult)/*Box::operator*=*/
{
    b->width *= mult;
    b->height *= mult;
    b->length *= mult;

    return *b;
}

void _ZNK3Box5printEv(const Box* const b)/*Box::print const*/
{
    printf("Box: %f x %f x %f\n", b->length, b->width, b->height); 
}


/*Shelf*/

/*const char* const DEF_MSG*/
const char* message = "The total volume held on the shelf is";

void _ZN5Shelf6setBoxEiRK3Box(Shelf* const s,int index, const Box* dims)/*Shelf::setBox*/
{
    s->boxes[index] = *dims;
}

double _ZNK5Shelf9getVolumeEv(const Shelf* const s) /*Shelf::getVolume const*/
{
    
	double vol = 0;
	size_t i;
    for (i = 0; i < 3; ++i)
        vol += s->boxes[i].width * s->boxes[i].length * s->boxes[i].height;

    return vol;
}

void _ZNK5Shelf5printEv(const Shelf* const s) /*Shelf::print const*/
{
    printf("%s %f\n", message, _ZNK5Shelf9getVolumeEv(s));
}



