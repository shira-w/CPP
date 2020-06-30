#include "cpp2c_polymorphism_defs.h"

void  _Z14doPrePostFixerv()
{
    	PrePostFixer angleBrackets;
	printf("\n--- start doPrePostFixer() ---\n\n");
	/*TODO  PrePostFixer angleBrackets("<<< ", " >>>");*/
    	_ZN12PrePostFixerC1EPKcPKc(&angleBrackets,"<<< ", " >>>");
    	/*TODO angleBrackets.print("Hello World!");*/
	_ZNK12PrePostFixer5printEPKc(&angleBrackets,"Hello World!");
    	/*TODO angleBrackets.print(-777);*/
	_ZNK12PrePostFixer5printElc(&angleBrackets,-777,'\0');
    	/*TODO angleBrackets.print(350, '#');*/
	_ZNK12PrePostFixer5printElc(&angleBrackets,350,'#');
    	/*TODO angleBrackets.print(static_cast<long int>(3.14));*/
	_ZNK12PrePostFixer5printElc(&angleBrackets,(long int)3.14,'\0');

    	printf("\n--- end doPrePostFixer() ---\n\n");
	_ZN12PrePostFixerD1Ev(&angleBrackets);
}

void _Z20doPrePostDollarFixerv()
{
    	PrePostDollarFixer asterisks;
	printf("\n--- start doPrePostDollarFixer() ---\n\n");
	
    	/*TODO PrePostDollarFixer asterisks("***** ", " *****");*/
	_ZN18PrePostDollarFixerC1EPKcPKc(&asterisks,"***** ", " *****");
    	/*TODO asterisks.print(-777);*/
	_ZNK18PrePostDollarFixer5printEic(&asterisks,-777,'$');
	/*TODO asterisks.print(350, '#');*/
	_ZNK18PrePostDollarFixer5printElc(&asterisks,350,'#');
    
    	_ZNK18PrePostDollarFixer5printEdc(&asterisks,3.14f,'$');

    	printf("\n--- end doPrePostDollarFixer() ---\n\n");
	_ZN18PrePostDollarFixerD1Ev(&asterisks);
}

void _Z16doPrePostCheckerv()
{
    	PrePostChecker check;
	printf("\n--- start doPrePostChecker() ---\n\n");

    	/*TODO PrePostChecker check;*/
	
	_ZN14PrePostCheckerC1Ev(&check);
    	/*TODO check.printThisSymbolUsingFunc();*/
	_ZNK14PrePostChecker24printThisSymbolUsingFuncEv(&check);
    	/*TODO check.printThisSymbolDirectly();*/
	_ZNK14PrePostChecker23printThisSymbolDirectlyEv(&check);
    	/*TODO check.printDollarSymbolByCastDirectly();*/
	_ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(&check);
    	/*TODO check.printDollarSymbolByScopeDirectly();*/
	_ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(&check);
    	/*TODO check.printDollarSymbolByCastUsingFunc();*/
	_ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(&check);
    	/*TODO check.printDollarSymbolByScopeUsingFunc();*/
	_ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(&check);

    	printf("\n--- end doPrePostChecker() ---\n\n");
	_ZN14PrePostCheckerD1Ev(&check);
}

void _Z25doPrePostFloatDollarFixerv()
{
    	PrePostFloatDollarFixer hashes;
	PrePostDollarFixer hashes2;
	printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    	/*TODO PrePostFloatDollarFixer hashes("### ", " ###");*/
	_ZN23PrePostFloatDollarFixerC1EPKcPKc(&hashes,"### ", " ###");
    	/*TODO hashes.print(-777);*/
	_ZNK23PrePostFloatDollarFixer5printEf(&hashes,-777);
    	/*TODO hashes.print(350, '#');*/
	_ZNK23PrePostFloatDollarFixer5printEfc(&hashes,350,'#');
    	/*TODO hashes.print(3.14f);*/
	_ZNK23PrePostFloatDollarFixer5printEf(&hashes,3.14f);
    	/*TODO PrePostDollarFixer hashes2(hashes);*/
	_ZN18PrePostDollarFixerC2EPKS_(&hashes2,&hashes);
    	/*TODO hashes2.print(7.5);*/
	_ZNK18PrePostDollarFixer5printEdc(&hashes2, 7.5, '$');
    	/*TODO hashes2.print(100);*/
	_ZNK18PrePostDollarFixer5printEic(&hashes2,100, '$');

    	printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}

void _Z20runAsPrePostFixerRefRK12PrePostFixer(const PrePostFixer* pp)//the object vptr of him and not of the pointer
{
    	printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    	/*TODO pp.print(123);//defaolt like the pointer /0*/
	(TextFormater*)pp->vptr[2](&pp,123,'\0');
	
    	printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void _Z26runAsPrePostDollarFixerRefRK18PrePostDollarFixer(const PrePostDollarFixer* pp)
{
    	printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    	/*TODO pp.print(123);*/
	(TextFormater*)pp->vptr[2](&pp,123,'$');

    	printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void _Z26runAsPrePostDollarFixerObj18PrePostDollarFixer(const PrePostDollarFixer pp)
{
    	printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    	/*TODO pp.print(123);*/
	_ZNK18PrePostDollarFixer5printEic(&pp,123);

    	printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void _Z24runAsPrePostHashFixerRefRK16PrePostHashFixer(const PrePostHashFixer& pp)
{
    	printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    	/*TODO pp.print(123);*/
	(TextFormatter*)pp->vptr[1](&pp,123);

    	printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void  _Z12doMultiplierv()//static
{
    	Multiplier m1,m2,m3,m4;
	printf("\n--- start doMultiplier() ---\n\n");

    	/*TODO Multiplier m1(3);*/
	m1.times=3;
    	printf("--- Multiplier CTOR: times = %d\n", m1.times);
    	/*TODO Multiplier m2 = 5;*/
	_ZN14PrePostCheckerC1Ev(&((DefaultTextFormatter*)m2));
	m2.times=5;
    	printf("--- Multiplier CTOR: times = %d\n", m2.times);
    	/*TODO Multiplier m3 = m1;*/
	_ZN20DefaultTextFormatterC2ERKS_(&((DefaultTextFormatter*)m3),&((DefaultTextFormatter*)m1));
	(TextFormatter*)m3->vptr=(TextFormatter*)m1->vptr;
	m3.times=other.times;
    	/*TODO Multiplier m4(m2);*/
	_ZN20DefaultTextFormatterC2ERKS_(&((DefaultTextFormatter*)m4),&((DefaultTextFormatter*)m2));
	(TextFormatter*)m4->vptr=(TextFormatter*)m2->vptr;
	m4.times=m2.times;
    	/*TODO m1.print("abc ");*/
	_ZNK10Multiplier5printEPKc(&m1,"abc ");
	 /*TODO m2.print("abc ");*/
	_ZNK10Multiplier5printEPKc(&m2,"abc ");
   	/*TODO m3.print("abc ");*/
	_ZNK10Multiplier5printEPKc(&m3,"abc ");
    	/*TODO m4.print("abc ");*/
	_ZNK10Multiplier5printEPKc(&m4,"abc ");

    	printf("\n--- end doMultiplier() ---\n\n");
	_ZN10MultiplierD1Ev(&m4);
	_ZN10MultiplierD1Ev(&m3);
	_ZN10MultiplierD1Ev(&m2);
	_ZN10MultiplierD1Ev(&m1);
}

void _Z16doFormatterArrayv()
{
    	PrePostDollarFixer temp;
	Multiplier m;
	PrePostChecker p;
	DefaultTextFormatter temp2,m2,p2;

	printf("\n--- start doFormatterArray() ---\n\n");

    	/*TODO PrePostDollarFixer("!!! ", " !!!"),*/
	ZN23PrePostFloatDollarFixerC1EPKcPKc(&temp,"!!! ", " !!!");
        /*TODO Multiplier(4),*/
	_ZN14PrePostCheckerC1Ev(&((DefaultTextFormatter*)m));
	m.times=5;
    	printf("--- Multiplier CTOR: times = %d\n", m.times);
        /*TODO PrePostChecker()*/
	_ZN14PrePostCheckerC1Ev(&p);
	_ZN20DefaultTextFormatterC2ERKS_(&temp2,&temp);
	_ZN20DefaultTextFormatterC2ERKS_(&m2,&m);
	_ZN20DefaultTextFormatterC2ERKS_(&p2,&p)
	DefaultTextFormatter formatters[] =
    	{
       		temp2,m2,p2			
    	};

    	for (int i = 0; i < 3; ++i)
	{
        	/*TODO formatters[i].print("Hello World!");*/
		_ZNK20DefaultTextFormatter5printEPKc(&formatters[i],"Hello World!");
	}

    	printf("\n--- end doFormatterArray() ---\n\n");
}

void _Z15doFormatterPtrsv()
{
    	PrePostDollarFixer tempppdf;
	Multiplier tempm;
	PrePostChecker temppc;
	printf("\n--- start doFormatterPtrs() ---\n\n");
	tempppdf=malloc(sizeof(tempppdf));
	tempm=malloc(sizeof(tempm));
	tempppc=malloc(sizeof(tempppc));
	_ZN18PrePostDollarFixerC1EPKc(&tempppdf,"!!! ", " !!!");
	_ZN14PrePostCheckerC1Ev(&((DefaultTextFormatter*)tempm));
	tempm.times=5;
	printf("--- Multiplier CTOR: times = %d\n", tempm.times);
	_ZN14PrePostCheckerC1Ev(&temppc);
    	DefaultTextFormatter* pfmt[] =
    	{
        	/*TODO new PrePostDollarFixer("!!! ", " !!!"),
        	new Multiplier(4),
        	new PrePostChecker()*/
		(DefaultTextFormatter*)tempppdf,
		(DefaultTextFormatter*)tempm,
		(DefaultTextFormatter*)temppc
    	};

    	for (int i = 0; i < 3; ++i)
	{
        	/*TODO pfmt[i]->print("Hello World!");*/
		(TextFormatter*)(pfmt[i])->vptr[1]("Hello World!");
	}

    	for (int i = 2; i >= 0; --i)
	{
        	free(pfmt[i]);
	}

    	printf("\n--- end doFormatterPtrs() ---\n\n");
	_ZN18PrePostDollarFixerD1Ev(&tempppdf);
	_ZN10MultiplierD1Ev(&tempm);
	_ZN14PrePostCheckerD1Ev(&temppc);
}

void _Z23doFormatterDynamicArrayv()
{
    	printf("\n--- start doFormatterDynamicArray() ---\n\n");
	
    	DefaultTextFormatter* formatters = _Z22generateFormatterArrayv();
    
    	for (int i = 0; i < 3; ++i)
        	_ZNK20DefaultTextFormatter5printEPKc(&formatters[i],"Hello World!");
	
    	free(formatters);
	
    	printf("\n--- end doFormatterDynamicArray() ---\n\n");
}

int main()
{
    	PrePostHashFixer hfix;
	printf("\n--- Start main() ---\n\n");

    	_Z14doPrePostFixerv();
    	_Z20doPrePostDollarFixerv();
   	_Z25doPrePostFloatDollarFixerv();
   	_Z16doPrePostCheckerv();

    	/*TODO PrePostHashFixer hfix;*/
	
    	_Z20runAsPrePostFixerRefRK12PrePostFixer(&hfix);
    	_Z26runAsPrePostDollarFixerRefRK18PrePostDollarFixer(hfix);
    	_Z26runAsPrePostDollarFixerObj18PrePostDollarFixer(hfix);
    	 _Z24runAsPrePostHashFixerRefRK16PrePostHashFixer(hfix);

    	_Z12doMultiplierv();

    	_Z16doFormatterArrayv();
    	_Z15doFormatterPtrsv();
    	_Z23doFormatterDynamicArrayv();

    	printf("\n--- End main() ---\n\n");

    	return 0;
}



