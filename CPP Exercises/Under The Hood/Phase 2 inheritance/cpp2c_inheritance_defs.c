#include <stdio.h>
#include "cpp2c_inheritance_defs.h"


/*PhysicalBox Defs */


void _ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h)/*TODO :Box(l, w, h)*/
{
	_ZN3BoxC1Eddd(&(this->b), l, w, h);
	this->material.material=OTHER;
	printf("Material created, set to Other\n");
	_ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1EdddTypesE(PhysicalBox* const this,double l, double w, double h, Types t)/*TODO  :Box(l, w, h),material(t)*/
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	_ZN3BoxC1Eddd(&(this->b), l, w, h);
	this->material.material=t;
	printf("Material created, set to %s\n",names[t]);
	_ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1ETypesE(PhysicalBox* const this, Types t) /*TODO : material(t)*/
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	_ZN3BoxC1Ed(&(this->b),1);
	this->material.material=t;
	printf("Material created, set to %s\n",names[t]);
	_ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxD1Ev(PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->b.length,  this->b.width, this->b.height, names[this->material.material]);/*TODO this->material.name()*/
	 _ZN3BoxD1Ev(&(this->b));
}

void _ZNK11PhysicalBox6printpEv(const PhysicalBox* const this) /*TODO const*/
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox, made of %s ; ", names[this->material.material]);/*TODO material.name()*/
	
    	_ZNK3Box5printEv(&(this->b));   
}


/*WeightBox Defs */

void _ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt)/*TODO :Box(l, w, h), weight(wgt)*/
{
    	_ZN3BoxC1Eddd(&(this->b), l, w, h);
	this->weight=wgt;
	_ZNK9WeightBox6printwEv(this);
}

void _ZN9WeightBoxC2ERKS_(WeightBox* const this, const WeightBox* const other)/*TODO:weight(other.weight)*/
{
	_ZN3BoxC1Ed(&(this->b),1);
	this->weight=other->weight;
	_ZNK9WeightBox6printwEv(this);
}

void _ZN9WeightBoxD1Ev(WeightBox* const this)
{
    	printf("Destructing WeightBox; ");
    	_ZNK9WeightBox6printwEv(this);
	_ZN3BoxD1Ev(&(this->b));
	
}

WeightBox _ZN9WeightBoxaSERKS_(WeightBox* const this,const WeightBox* const other)
{
	this->weight = other->weight;
    	return *this;
}

void _ZNK9WeightBox6printwEv(const WeightBox* const this) /*TODO const*/
{
    	printf("WeightBox, weight: %f; ", this->weight);

	_ZNK3Box5printEv(&(this->b));   
}


