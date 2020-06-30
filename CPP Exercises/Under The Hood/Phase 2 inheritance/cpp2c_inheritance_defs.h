#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/*Materials*/
typedef enum Types
{
	PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
}Types;

typedef struct Materials
{
	char solution;
}Materials;

typedef struct Material_t /*TODO : public Materials*/
{
    	Types material;
}Material_t;


/*PhysicalBox*/

typedef struct PhysicalBox/*TODO : public Box*/
{
	Box b;
    	Material_t material;
}PhysicalBox;

/*PhysicalBox Defs */

void _ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h);
void _ZN11PhysicalBoxC1EdddTypesE(PhysicalBox* const this,double l, double w, double h, Types t);
void _ZN11PhysicalBoxC1ETypesE(PhysicalBox* const this, Types t);
void _ZN11PhysicalBoxD1Ev(PhysicalBox* const this);
void _ZNK11PhysicalBox6printpEv(const PhysicalBox* const this);

/*WeightBox*/

typedef struct WeightBox/* TODO : public Box*/
{
	Box b;
    	double weight;
}WeightBox;

/*WeightBox Defs */

void _ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt);
void _ZN9WeightBoxC2ERKS_(WeightBox* const this, const WeightBox* const other);
void _ZN9WeightBoxD1Ev(WeightBox* const this);
WeightBox _ZN9WeightBoxaSERKS_(WeightBox* const this,const WeightBox* const other);
void _ZNK9WeightBox6printwEv(const WeightBox* const this);

#endif /* __CPP2C_INHERITANCE_DEFS_H__*/

