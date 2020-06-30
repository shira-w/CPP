#include "cpp2c_polymorphism_defs.h"

//using std::printf;
/*TextFormatter defs*/
typedef void (*virtualTableTextFormatter[2])(TextFormatter* const)={_ZN13TextFormatterD1Ev,NULL};
void _ZN13TextFormatterC1Ev(TextFormatter* const this)
{
	this->vptr=virtualTableTextFormatter;

}
void _ZN13TextFormatterD1Ev(TextFormatter* const this)
{
	this->vptr=NULL;
};

/*DefaultTextFormatter Defs*/
/*
typedef  void (*distractorPtr)(DefaultTextFormatter* const this);
typedef  void (*printPtr)(const DefaultTextFormatter* const this,const char* text);*/
virtualDefaultTableTextFormatter ={_ZN20DefaultTextFormatterD1Ev,_ZNK20DefaultTextFormatter5printEPKc};

int next_id = 0;

void _ZN20DefaultTextFormatterC1Ev(DefaultTextFormatter* const this)/*TODO :id(Ider::getId())*/
{
	_ZN13TextFormatterC1Ev(this->tf);
	this->tf->vptr=virtualTableDefaultTextFormatter;
	this->id=next_id++;
	printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void _ZN20DefaultTextFormatterD1Ev(DefaultTextFormatter* const this)/*distractor*/
{
	printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
	this->tf->vptr=virtualTableTextFormatter;
	_ZN20DefaultTextFormatterD1Ev(&(this->tf));
}  

void _ZN20DefaultTextFormatterC2ERKS_(DefaultTextFormatter* const this,const DefaultTextFormatter* const other)/*copy constractor*/ /*TODO :id(Ider::getId())*/
{
    	this->id=next_id++;
	printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

DefaultTextFormatter DefaultTextFormatterAsERKS_(DefaultTextFormatter* const this, const DefaultTextFormatter* const other)
{
    	printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    	return *this;
}

void _ZNK20DefaultTextFormatter5printEPKc(const DefaultTextFormatter* const this,const char* text) /*TODO const*/
{
    	/*TODO printFunc("[DefaultTextFormatter::print(const char*)]");  */
	printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]" );
    	printf("%s\n", text);
}

DefaultTextFormatter* _Z22generateFormatterArrayv()
{
    	formatterArray=(DefaultTextFormatter*)malloc(3);
	return formatterArray;
}


/*PrePostFixer Defs*/


virtualTablePrePostFixer ={_ZN12PrePostFixerD1Ev,_ZNK12PrePostFixer5printEPKc,_ZNK12PrePostFixer5printElc,_ZNK12PrePostFixer16getDefaultSymbolEv};

void _ZN12PrePostFixerC1EPKcPKc(PrePostFixer* const this,const char* prefix, const char* postfix)/*TODO :pre(prefix),post(postfix)*/
{
    	this->dtf->tf->vptr=virtualTablePrePostFixer;
	strcpy(this->pre,prefix);
	strcpy(this->post,postfix);
	printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre,this->post);
}

void _ZN12PrePostFixerD1Ev(PrePostFixer* const this)
{
	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	this->dtf->tf->vptr=virtualTableDefaultTextFormatter;
	_ZN20DefaultTextFormatterD1Ev(&(this->dtf));
}

void _ZNK12PrePostFixer5printEPKc(const PrePostFixer* const this, const char* text) /*TODO const*/
{
    	/*TODO printFunc("[PrePostFixer::print(const char*)]");*/
	printf("%-60s | ", "[PrePostFixer::print(const char*)]" );

    	printf("%s%s%s\n", this->pre, text, this->post);
}

void _ZNK12PrePostFixer5printElc(const PrePostFixer* const this,long num, char symbol) /*TODO const*/
{
	/*TODO printFunc("[PrePostFixer::print(long, char)]");*/
	printf("%-60s | ", "[PrePostFixer::print(long, char)]" );
    	printf("-->\n");
    
   	if (symbol)   
	{ 
        	/*TODO print_num(num, symbol);*/
		/*TODO printFunc("[PrePostFixer::print_num(long, char)]"); */
		printf("%-60s | ", "[PrePostFixer::print_num(long, char)]" );
    		printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
	}
    	else
	{
        	/*TODO print_num(num);*/
		/*TODO printFunc("[PrePostFixer::print_num(long, char)]"); */
		printf("%-60s | ", "[PrePostFixer::print_num(long, char)]" );
    		printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
	}
}

char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer* const this) /*TODO const*/
{
    	return '\0';
}

/*PrePostDollarFixer Defs */

//char DEFAULT_SYMBOL = '$';
virtualTablePrePostDollarFixer={_ZN18PrePostDollarFixerD1Ev,_ZNK12PrePostFixer5printEPKc,_ZNK18PrePostDollarFixer5printElc,_ZNK18PrePostDollarFixer16getDefaultSymbolEv};
void _ZN18PrePostDollarFixerC1EPKcPKc(PrePostDollarFixer* const this,const char* prefix, const char* postfix)/*TODO :   PrePostFixer(prefix, postfix)*/
{
    	_ZN12PrePostFixerC1EPKcPKc(&(this->ppf),prefix,postfix);
	this->ppf->dtf->tf->vptr=virtualTablePrePostDollarFixer;
	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppf->pre, this->ppf->post);
}

void _ZN18PrePostDollarFixerC2EPKS_(PrePostDollarFixer* const this,const PrePostDollarFixer* other)/*TODO :   PrePostFixer(other)*/
{
	_ZN20DefaultTextFormatterC2ERKS_(&(DefaultTextFormatter*)this,&other);
	(TextFormatter*)this->vptr=(TextFormatter*)other->vptr;
	(PrePostFixer*)this->pre=other->pre;
	(PrePostFixer*)this->post=other->post;
	(TextFormatter*)this->vptr=virtualTablePrePostDollarFixer;
	printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->ppf->pre, this->ppf->post);
}

void _ZN18PrePostDollarFixerD1Ev(PrePostDollarFixer* const this)
{
    	printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->ppf->pre, this->ppf->post);
	this->ppf->dtf->tf->vptr=virtualTablePrePostFixer;
	_ZN12PrePostFixerD1Ev(&(this->ppf));
}

void _ZNK18PrePostDollarFixer5printEic(const PrePostDollarFixer* const this,int num, char symbol) /*TODO const*/
{
    	/*TODO printFunc("[PrePostDollarFixer::print(int, char)]");*/
	printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]" );
    	printf("-->\n");

    	_ZNK18PrePostDollarFixer5printElc(&this,long(num), symbol);
}

void _ZNK18PrePostDollarFixer5printElc(const PrePostDollarFixer* const this,long num, char symbol) /*TODO const*/
{
    	/*TODO printFunc("[PrePostDollarFixer::print(long, char)]");*/
	printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]" );
    	printf("-->\n");
    	_ZNK12PrePostFixer5printElc(&((PrePostFixer*)this),num, symbol);
}

void _ZNK18PrePostDollarFixer5printEdc(const PrePostDollarFixer* const this,double num, char symbol) /*TODO const*/
{
    	/*TODO printFunc("[PrePostDollarFixer::print(double, char)]"); */
	printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]" );
    	printf("%s%c%f%s\n", this->ppf->pre, symbol, num, this->ppf->post);
}

char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(const PrePostDollarFixer* const this) /*TODO const*/
{
    	return '$';
}

/*PrePostHashFixer Defs*/
virtualTablePrePostHashFixer={_ZN16PrePostHashFixerD1Ev,_ZNK12PrePostFixer5printEPKc,_ZNK16PrePostHashFixer5printElc,_ZNK16PrePostHashFixer16getDefaultSymbolEv};
void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer* const this,int prc)/*TODO :   PrePostDollarFixer("===> ", " <==="),   precision(prc)*/
{
    	_ZN18PrePostDollarFixerC1EPKc((ppdf*)this,"===> ", " <===");
	this->ppdf->precision=prc;
	this->ppdf->ppf->dtf->tf->vptr=virtualTablePrePostHashFixer;
	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->ppdf->ppf, this->ppdf->ppf->post, this->ppdf->precision);   

    	/*TODO print(9999.9999);*/
	 /*TODO printFunc("[PrePostHashFixer::print(double, char)]"); */
	printf("%-60s | ", "[PrePostHashFixer::print(double, char)]" );
    	printf("%s[%c%.*f]%s\n", this->ppdf->ppf->pre, '#', this->precision, 9999.9999, this->ppdf->ppf->post);
}

void _ZN16PrePostHashFixerD1Ev(PrePostHashFixer* const this)
{
    	printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->ppdf->ppf->pre, this->ppdf->ppf->post);
	this->ppdf->ppf->dtf->tf->vptr=virtualTablePrePostDollarFixer;
}
    
void _ZNK16PrePostHashFixer5printEic(const PrePostHashFixer* const this,int num, char symbol) /*TODO const*/
{
    	/*TODO printFunc("[PrePostHashFixer::print(int, char)]"); */
	printf("%-60s | ", "[PrePostHashFixer::print(int, char)]" );
    	printf("-->\n");

    	/*TODO print(double(num), symbol);*/
	printf("%-60s | ", "[PrePostHashFixer::print(double, char)]" );
    	printf("%s[%c%.*f]%s\n", this->ppdf->ppf->pre, '#', this->precision, double(num), this->ppdf->ppf->post);
}

void _ZNK16PrePostHashFixer5printElc(const PrePostHashFixer* const this,long num, char symbol) /*TODO const*/
{
    	/*TODO printFunc("[PrePostHashFixer::print(long, char)]"); */
	printf("%-60s | ", "[PrePostHashFixer::print(long, char)]" );
    	printf("-->\n");

   	/*TODO print(double(num), symbol);*/
	printf("%-60s | ", "[PrePostHashFixer::print(double, char)]" );
    	printf("%s[%c%.*f]%s\n", this->ppdf->ppf->pre, '#', this->precision, (double)num, this->ppdf->ppf->post);
}
char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const PrePostHashFixer* const this) /*TODO const*/
{
    	return '#';
}

/*PrePostFloatDollarFixer Defs*/
virtualTablePrePostFloatDollarFixer={_ZN23PrePostFloatDollarFixerD1Ev,_ZNK12PrePostFixer5printEPKc,_ZNK18PrePostDollarFixer5printElc,_ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv};
void _ZN23PrePostFloatDollarFixerC1EPKcPKc(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix)/*TODO : PrePostDollarFixer(prefix, postfix)*/
{
	_ZN18PrePostDollarFixerC1EPKc(&this, prefix, postfix);
    	printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",  (PrePostFixer*)this->pre, (PrePostFixer*)this->post);
	(TextFormatter*)this->vptr=virtualTablePrePostFloatDollarFixer;
}

void _ZN23PrePostFloatDollarFixerD1Ev(PrePostFloatDollarFixer* const this)
{
    	printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->ppdf->ppf->pre,  this->ppdf->ppf->post);
	this->ppdf->ppf->dtf->tf->vptr=virtualTablePrePostDollarFixer;
	_ZN18PrePostDollarFixerD1Ev(&(this->ppdf));
}

void _ZNK23PrePostFloatDollarFixer5printEf(const PrePostFloatDollarFixer* const this,float num) /*TODO const*/
{
    	/*TODO printFunc("[PrePostFloatDollarFixer::print(float)]");*/
	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]" );
    	printf("-->\n");
	/*TODO 
    	print(num, DEFAULT_SYMBOL);*/
	_ZNK23PrePostFloatDollarFixer5printEfc(this, num, '#');
}

void _ZNK23PrePostFloatDollarFixer5printEfc(const PrePostFloatDollarFixer* const this,float num, char symbol) /*TODO const*/
{
   	 /*TODO printFunc("[PrePostFloatDollarFixer::print(float, char)]");*/
	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]" );
    	printf("%s%c%.2f%s\n", this->ppdf->ppf->pre, symbol, num, this->ppdf->ppf->post);
}

char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(const PrePostFloatDollarFixer* const this) /*TODO const*/
{
    	return '@';
}

/*PrePostChecker Defs*/
virtualTablePrePostChecker={_ZN14PrePostCheckerD1Ev,_ZNK12PrePostFixer5printEPKc,_ZNK18PrePostDollarFixer5printElc,_ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv};

void _ZN14PrePostCheckerC1Ev(PrePostChecker* const this)/*TODO :   PrePostFloatDollarFixer("[[[[ ", " ]]]]")*/
{
    	_ZN23PrePostFloatDollarFixerC1EPKcPKc(this->ppfdf,"[[[[ "," ]]]]");
	this->ppfdf->ppdf->ppf->dtf->tf->vptr=virtualTablePrePostChecker;
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->ppfdf->ppdf->ppf->pre, this->ppfdf->ppdf->ppf->post);
}    

void _ZN14PrePostCheckerD1Ev(PrePostChecker* const this)
{
    	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->ppfdf->ppdf->ppf->pre, this->ppfdf->ppdf->ppf->post);
	this->ppfdf->ppdf->ppf->dtf->tf->vptr=virtualTablePrePostFloatDollarFixer;
	_ZN23PrePostFloatDollarFixerD1Ev(&this);
}

void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(const PrePostChecker* const this) /*TODO const*/
{
    	/*TODO printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");*/
	printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]" );
    	printf("Default symbol is %c\n",*(this->ppfdf->ppdf->ppf->dtf->tf->vptr)[3](&this));
}

void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(const PrePostChecker* const this) /*TODO const*/
{
    	/*TODO printFunc("[PrePostChecker::printThisSymbolDirectly()]");*/
	printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]" );
    	printf("Default symbol is @\n"/*TODO, this->DEFAULT_SYMBOL*/);
}

void _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(const PrePostChecker* const this)/*TODO const*/
{
    	/*TODO printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");*/
	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]" );
    	printf("Default symbol is %c\n", *(((PrePostDollarFixer*)(this))->->ppfdf->ppdf->ppf->dtf->tf->vptr)[3]((PrePostDollarFixer*)(this));//ask
}

void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(const PrePostChecker* const this) /*TODO const*/
{
    	/*TODO printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");*/
	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]" );
    	printf("Default symbol is %c\n", getDefaultSymbol((PrePostDollarFixer*)this));
}

void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(const PrePostChecker* const this) /*TODO const*/
{
    	/*TODO printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");*/
	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]" );
    	printf("Default symbol is @\n"/*, TODO ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL*/'$' );
}

void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(const PrePostChecker* const this) /*TODO const*/
{
    	/*TODO printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");*/
	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]" );
   	printf("Default symbol is $\n" /*,TODO this->PrePostDollarFixer::DEFAULT_SYMBOL*/'$');
}


/*Multiplier Defs*/
VirtualTableDefaultTextFormatter={_ZN10MultiplierD1Ev,_ZNK10Multiplier5printEPKc};
void _ZN10MultiplierD1Ev(Multiplier* const this)
{
    	printf("--- Multiplier DTOR: times = %d\n", this->times);
	((TextFormater*)this)->vptr=VirtualTableDefaultTextFormatter;
	_ZN20DefaultTextFormatterD1Ev(this->dtf);
}
    
void _ZNK10Multiplier5printEPKc(Multiplier* const this,const char* text) /*TODO const*/
{
    	/*TODO printFunc("[Multiplier::print(const char*)]");*/
    	printf("%-60s | ", "[Multiplier::print(const char*)]" );
   	for (int i = 0; i < this->times; ++i)
        	printf("%s", text);
    	printf("\n");
}


