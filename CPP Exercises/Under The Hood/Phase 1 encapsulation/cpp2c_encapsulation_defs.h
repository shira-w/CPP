#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

/*Box*/

typedef struct Box
{
	double length;
    	double width;
    	double height;    
    
}Box;

/*Shelf*/

typedef struct Shelf
{
    Box boxes[3];
}Shelf;

/*Box Defs*/
void _ZN3BoxC1Ed(Box* const b, double dim);
void _ZN3BoxC1Eddd(Box* const b, double l, double w, double h);
void _ZN3BoxD1Ev(Box* const b);
Box _ZN3BoxmLEd(Box* const b, double mult);
void _ZNK3Box5printEv(const Box* const b);

/*Shelf Defs*/

void _ZN5Shelf6setBoxEiRK3Box(Shelf* const s,int index, const Box* dims);
double _ZNK5Shelf9getVolumeEv(const Shelf* const s);
void _ZNK5Shelf5printEv(const Shelf* const s);


#endif /*__CPP2C_ENCAPSULATION_DEFS_H__*/

