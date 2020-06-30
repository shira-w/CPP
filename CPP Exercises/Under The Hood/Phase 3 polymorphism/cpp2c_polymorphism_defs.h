#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__

#include <stdio.h>
#include <malloc.h>
/*
inline void printFunc(const char* fname)
{
    printf("%-60s | ", fname); 
}*/

/*TextFormatter */

typedef void (*virtualTableTextFormatter[])(void,...);

typedef struct TextFormatter
{
   	/*TODO virtual ~TextFormatter() { };*/
    	/*TODO virtual void print(const char* text) const = 0;*/
	virtualTableTextFormatter* vptr;
}TextFormatter;

/*TextFormatter defs*/
void _ZN13TextFormatterD1Ev(DefaultTextFormatter* const this);

/*DefaultTextFormatter*/
typedef void (*virtualTableDefaultTextFormatter[])(void*,...);

typedef struct DefaultTextFormatter /*: TODO public TextFormatter*/
{
/*TODO public:
    DefaultTextFormatter();
    DefaultTextFormatter(const DefaultTextFormatter&);
    DefaultTextFormatter& operator=(const DefaultTextFormatter&);
    ~DefaultTextFormatter();

    virtual void print(const char* text) const;*/
	
/*TODO private:*/ 
	TextFormatter tf;//vptr

/*TODO class Ider
    {
     private:
        static int next_id;
    public:
        TODO inline static int getId() { return next_id++; }
    };*/
    	const int id;
}DefaultTextFormatter;

/*DefaultTextFormatter defs*/
void _ZN20DefaultTextFormatterC1Ev(DefaultTextFormatter* const this);
/*virtual*/void _ZN20DefaultTextFormatterD1Ev(DefaultTextFormatter* const this);
void _ZN20DefaultTextFormatterC2ERKS_(DefaultTextFormatter* const this,const DefaultTextFormatter* const other);
DefaultTextFormatter DefaultTextFormatterAsERKS_(DefaultTextFormatter* const this, const DefaultTextFormatter* const other);
/*virtual*/void _ZNK20DefaultTextFormatter5printEPKc(const DefaultTextFormatter* const this,const char* text);
DefaultTextFormatter* _Z22generateFormatterArrayv();


/*PrePostFixer*/
typedef void (*virtualTablePrePostFixer[])(void*,...);

typedef struct PrePostFixer/*TODO : public DefaultTextFormatter*/
{
	
/*TODO public:
    PrePostFixer(const char* prefix, const char* postfix);
    ~PrePostFixer();

    virtual void print(const char* text) const;
    virtual void print(long num, char symbol = '\0') const;

    virtual char getDefaultSymbol() const;

protected:
    const char* getPrefix() const;
    const char* getPostfix() const;

private:*/
	DefaultTextFormatter dtf;
/*
    void print_num(long num) const;
    void print_num(long num, char symbol) const;*/

    	const char* pre;
    	const char* post;
}PrePostFixer;

/*PrePostFixer Defs*/
void _ZN12PrePostFixerC1EPKcPKc(PrePostFixer* const this,const char* prefix, const char* postfix);
void _ZN12PrePostFixerD1Ev(PrePostFixer* const this);
void _ZNK12PrePostFixer5printEPKc(const PrePostFixer* const this, const char* text);
void _ZNK12PrePostFixer5printElc(const PrePostFixer* const this,long num, char symbol);
char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer* const this);
/*
inline const char* PrePostFixer::getPrefix() const
{
    return pre;
}

inline const char* PrePostFixer::getPostfix() const
{
    return post;
}

inline char PrePostFixer::getDefaultSymbol() const
{
    return '\0';
}

inline void PrePostFixer::print(long num, char symbol) const
{
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");
    
    if (symbol)    
        print_num(num, symbol);
    else
        print_num(num);
}

inline void PrePostFixer::print_num(long num) const
{
    printFunc("[PrePostFixer::print_num(long)]"); 
    printf("%s%ld%s\n", pre, num, post);
}

inline void PrePostFixer::print_num(long num, char symbol) const
{
    printFunc("[PrePostFixer::print_num(long, char)]"); 
    printf("%s%c%ld%s\n", pre, symbol, num, post);
}
*/

/*PrePostDollarFixer */

typedef void (*virtualTablePrePostDollarFixer[])(void,...);

typedef struct PrePostDollarFixer/*TODO : public PrePostFixer*/
{
	PrePostFixer ppf;
/*TODO
protected:
    static const char DEFAULT_SYMBOL = '$';

public:
    PrePostDollarFixer(const char* prefix, const char* postfix);
    PrePostDollarFixer(const PrePostDollarFixer& other);
    virtual ~PrePostDollarFixer();

    void print(int num, char symbol = DEFAULT_SYMBOL) const;
    virtual void print(long num, char symbol = DEFAULT_SYMBOL) const;
    void print(double num, char symbol = DEFAULT_SYMBOL) const;
    virtual char getDefaultSymbol() const;*/
}PrePostDollarFixer;

/*PrePostDollarFixer Defs*/
void _ZN18PrePostDollarFixerC1EPKcPKc(PrePostDollarFixer* const this,const char* prefix, const char* postfix);
void _ZN18PrePostDollarFixerC2EPKS_(PrePostDollarFixer* const this,const PrePostDollarFixer* other)
void _ZN18PrePostDollarFixerD1Ev(PrePostDollarFixer* const this);
void _ZNK18PrePostDollarFixer5printEic(const PrePostDollarFixer* const this,int num, char symbol);
void _ZNK18PrePostDollarFixer5printElc(const PrePostDollarFixer* const this,long num, char symbol);
void _ZNK18PrePostDollarFixer5printEdc(const PrePostDollarFixer* const this,double num, char symbol);
char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(const PrePostDollarFixer* const this);


/*
inline char PrePostDollarFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}*/

/*PrePostHashFixer*/
typedef void (*virtualTablePrePostHashFixer[])(void,...);

typedef struct PrePostHashFixer/*TODO : public PrePostDollarFixer*/
{
	PrePostDollarFixer ppdf;
/*
private:
    //static const char DEFAULT_SYMBOL = '#';
public:
    PrePostHashFixer(int prc = 4);
    virtual ~PrePostHashFixer();

    void print(int num, char symbol = DEFAULT_SYMBOL) const;
    virtual void print(long num, char symbol = DEFAULT_SYMBOL) const;
    void print(double num, char symbol = DEFAULT_SYMBOL) const;
    virtual char getDefaultSymbol() const;

private:*/
    	int precision;
}PrePostHashFixer;

/*PrePostHashFixer Defs */
void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer* const this,int prc);
void _ZN16PrePostHashFixerD1Ev(PrePostHashFixer* const this);
void _ZNK16PrePostHashFixer5printEic(const PrePostHashFixer* const this,int num, char symbol);
void _ZNK16PrePostHashFixer5printElc(const PrePostHashFixer* const this,long num, char symbol);
char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const PrePostHashFixer* const this);

/*
inline void PrePostHashFixer::print(double num, char symbol) const
{
    printFunc("[PrePostHashFixer::print(double, char)]"); 

    printf("%s[%c%.*f]%s\n", getPrefix(), symbol, precision, num, getPostfix());
}

inline char PrePostHashFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}
*/

/*PrePostFloatDollarFixer*/
typedef void (*virtualTablePrePostFloatDollarFixer[])(void,...);

typedef struct PrePostFloatDollarFixer/*TODO : public PrePostDollarFixer*/
{
	PrePostDollarFixer ppdf;
/*
protected:
    static const char DEFAULT_SYMBOL = '@';

public:
    PrePostFloatDollarFixer(const char* prefix, const char* postfix);
    virtual ~PrePostFloatDollarFixer();
    void print(float num) const;
    void print(float num, char symbol) const;
    virtual char getDefaultSymbol() const;*/
}PrePostFloatDollarFixer;

/*PrePostFloatDollarFixer Defs*/
void _ZN23PrePostFloatDollarFixerC1EPKcPKc(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix);
void _ZN23PrePostFloatDollarFixerD1Ev(PrePostFloatDollarFixer* const this);
void _ZNK23PrePostFloatDollarFixer5printEf(const PrePostFloatDollarFixer* const this,float num);
void _ZNK23PrePostFloatDollarFixer5printEfc(const PrePostFloatDollarFixer* const this,float num, char symbol);
char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(const PrePostFloatDollarFixer* const this);

/*
inline char PrePostFloatDollarFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}*/

/*PrePostChecker*/
typedef void (*virtualTablePrePostChecker[])(void,...);

typedef struct PrePostChecker/*TODO : public PrePostFloatDollarFixer*/
{
	PrePostFloatDollarFixer* ppfdf;
/*
public:
    PrePostChecker();
    virtual ~PrePostChecker();
    
    void printThisSymbolUsingFunc() const;
    void printThisSymbolDirectly() const;    
    void printDollarSymbolByCastUsingFunc() const;
    void printDollarSymbolByScopeUsingFunc() const;
    void printDollarSymbolByCastDirectly() const;
    void printDollarSymbolByScopeDirectly() const;*/
}PrePostChecker;
/*PrePostChecker defs*/
void _ZN14PrePostCheckerC1Ev(PrePostChecker* const this);
void _ZN14PrePostCheckerD1Ev(PrePostChecker* const this);
void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(const PrePostChecker* const this);
void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(const PrePostChecker* const this);
void _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(const PrePostChecker* const this);
void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(const PrePostChecker* const this);
void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(const PrePostChecker* const this);
void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(const PrePostChecker* const this);

/*Multiplier*/
typedef void (*virtualTableMultiplier[])(void,...);

typedef struct Multiplier/*TODO: public DefaultTextFormatter*/
{
	DefaultTextFormatter dtf;
    	int times;
}Multiplier; 

/*Multiplier Defs */
void _ZN10MultiplierD1Ev(Multiplier* const this);
void _ZNK10Multiplier5printEPKc(Multiplier* const this,const char* text);
/*
inline Multiplier::Multiplier(int t)
:   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}

not inline Multiplier::~Multiplier()
{
    printf("--- Multiplier DTOR: times = %d\n", times);
}
    
inline int Multiplier::getTimes() const
{
    return times;
}

inline void Multiplier::setTimes(int t)
{
    times = t;*/
}
#endif // __CPP2C_POLYMORPHISM_H__

