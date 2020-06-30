#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

void _Z11doMaterialsv()
{
    	/*Materials mat*/
	Material_t mat1,mat2;
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };

	struct MatTest{ Materials mat; Material_t mat_t; };

	printf("\n--- Start doMaterials() ---\n\n");
    	
    	printf("Size of Materials: 1\n");/* TODO sizeof(Materials)*/
    	printf("Size of mat: 1\n"); /* TODO sizeof(mat));*/
    	printf("Size of Materials::Types: 4\n");/* TODO sizeof(Types));*/
    	printf("Size of Material_t: 4\n");/* TODO sizeof(Material_t));*/

    	printf("Size of Materials + Material_t: 8 \n");/*TODO sizeof(struct MatTest));*/
    	
	/*TODO Material_t mat1;*/
	mat1.material=OTHER;/*TODO check*/
	printf("Material created, set to %s\n",names[mat1.material]);/*TODO name()*/

    	/*TODO Material_t mat2(Materials::METAL);*/
	mat2.material=METAL;
	printf("Material created, set to %s\n",names[mat2.material]);/*TODO name()*/

    	printf("\n--- End doMaterials() ---\n\n");
}

void _Z13doPhysicalBoxv()
{
  	PhysicalBox pb1, pb2, pb3, pb4;	

	printf("\n--- Start doPhysicalBox() ---\n\n");
	
    	/*TODO PhysicalBox pb1(8, 6, 4, Materials::PLASTIC);*/
	_ZN11PhysicalBoxC1EdddTypesE(&pb1, 8, 6 ,4, PLASTIC);
    	/*TODO PhysicalBox pb2(Materials::WOOD);*/
	_ZN11PhysicalBoxC1ETypesE(&pb2, WOOD);
    	/*TODO PhysicalBox pb3(7, 7, 7);*/
	_ZN11PhysicalBoxC1Eddd(&pb3, 7, 7 ,7);
    
    	printf("\npb4 is copy-constructed from pb1\n");
    	/*TODO PhysicalBox pb4 = pb1;*/
	pb4=pb1;
    	/*TODO pb4.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb4);
    	/*TODO pb1.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb1);
    	printf("pb4 %s pb1\n", pb1.b.width == pb4.b.width && pb1.b.height == pb4.b.height && pb1.b.length == pb4.b.length && (pb1.material.material==pb4.material.material) ? "equals" : "does not equal");

    	printf("\npb4 is copy-assigned from pb3\n");
    	pb4 = pb3;
    	/*TODO pb4.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb4);
    	/*TODO pb3.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb3);
    	 printf("pb4 %s pb3\n", pb3.b.width == pb4.b.width && pb3.b.height == pb4.b.height && pb3.b.length == pb4.b.length && pb3.material.material==pb4.material.material ? "equals" : "does not equal");

	printf("\n--- End doPhysicalBox() ---\n\n");
	_ZN11PhysicalBoxD1Ev(&pb4);
	_ZN11PhysicalBoxD1Ev(&pb3);
	_ZN11PhysicalBoxD1Ev(&pb2);
	_ZN11PhysicalBoxD1Ev(&pb1);
}

void _Z11doWeightBoxv()
{
    	WeightBox pw1, pw2, pw3, pw4;

	printf("\n--- Start doWeightBox() ---\n\n");

    	/*TODO WeightBox pw1(8, 6, 4, 25);*/
	_ZN9WeightBoxC1Edddd(&pw1, 8, 6, 4, 25);
    	/*TODO WeightBox pw2(1, 2, 3);*/
	_ZN9WeightBoxC1Edddd(&pw2, 1, 2, 3 ,0.0);
    	/*TODO WeightBox pw3(10, 20, 30, 15);*/
	_ZN9WeightBoxC1Edddd(&pw3, 10, 20, 30 ,15);
    
    	printf("\npw4 is copy-constructed from pw1\n");
    	/*TODO WeightBox pw4 = pw1;*/
	_ZN9WeightBoxC2ERKS_(&pw4, &pw1);
	/*TODO pw4.printw();*/
	_ZNK9WeightBox6printwEv(&pw4);
    	/*TODO pb1.printw();*/
	_ZNK9WeightBox6printwEv(&pw1);
    	 printf("pb4 %s pb3\n", pw1.b.width == pw4.b.width && pw1.b.height == pw4.b.height && pw1.b.length == pw4.b.length && pw1.weight==pw4.weight? "equals" : "does not equal");

    	printf("\npw4 is copy-assigned from pw3\n");
    	/*TODO  pw4 = pw3;*/
	_ZN9WeightBoxaSERKS_(&pw4, &pw3);
    	/*TODO pw4.printw();*/
	_ZNK9WeightBox6printwEv(&pw4);
    	/*TODO pb3.printw();*/
	_ZNK9WeightBox6printwEv(&pw3);

   	printf("pw4 %s pw3\n", pw3.b.width == pw4.b.width && pw3.b.height == pw4.b.height && pw3.b.length == pw4.b.length && (pw3.weight==pw4.weight) ? "equals" : "does not equal");

   	printf("\n--- End doWeightBox() ---\n\n");
	_ZN9WeightBoxD1Ev(&pw4);
	_ZN9WeightBoxD1Ev(&pw3);
	_ZN9WeightBoxD1Ev(&pw2);
	_ZN9WeightBoxD1Ev(&pw1);
}

int main()
{
    	printf("\n--- Start main() ---\n\n");

    	_Z11doMaterialsv();

   	 _Z13doPhysicalBoxv();

    	_Z11doWeightBoxv();

    	printf("\n--- End main() ---\n\n");
	return 1;
}
