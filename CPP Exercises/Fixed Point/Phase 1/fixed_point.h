#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <iostream>
#include <cstring>
#include <math.h>
#include <limits.h>
#include <stdexcept>
#include <stdbool.h>

class Price
{
public:
	Price();
	Price(int dolar ,int cents=0 ,char sign='+');
	Price(const Price& p);
	Price& operator =(int centsAmount);
	Price operator -()const;
	Price& operator +=(const Price& p);
	Price& operator -=(const Price& p);
	Price& operator --();//frefix
	Price& operator ++();
	Price operator --(int);//postfix
	Price operator ++(int);
	operator double(){
		if(m_sign=='-')return (double)-m_dolar+ m_cents/-100.0;
		else return (double)m_dolar+ m_cents/100.0;}

	int getDolar()const;
	int getCents()const;
	char getSign()const;
	void setSign();
	bool isNegative()const;

private:
	void init(int dolar, int cents=0,char sign='+');
	int m_dolar;
	int m_cents;
	char m_sign;

friend std::ostream& operator <<(std::ostream& os,const Price& p);
};
inline Price::Price(const Price& p)
{
	init(p.getDolar(),p.getCents(),p.getSign());
}
Price operator +(const Price& p1,const Price& p2);
Price operator -(const Price& p1,const Price& p2);
bool operator >(const Price& p1,const Price& p2);

inline bool operator ==(const Price& p1,const Price& p2)
{
	if(p1.getDolar()==p2.getDolar()&&p1.getCents()&&p1.getSign()==p2.getSign())
		return true;
	else
		return false;
}
inline bool operator <=(const Price& p1,const Price& p2)
{
	return !(p1>p2);

}
inline bool operator <(const Price& p1,const Price& p2)
{
	return !(p1>p2) && !(p1==p2);
}
inline bool operator >=(const Price& p1,const Price& p2)
{
	return !(p1<p2);

}
inline bool operator !=(const Price& p1,const Price& p2)
{
	return !(p1==p2);
}
inline Price::Price():m_dolar(0),m_cents(0),m_sign('0')
{}

inline Price::Price(int dolar, int cents,char sign):m_dolar(dolar),m_cents(cents),m_sign(sign)
{
	
	init(dolar,cents,sign);
}

inline Price& Price::operator =(int centsAmount)
{
	int dolar=centsAmount/100;
	int cents=centsAmount%100;
	init(dolar,cents);
	return *this;
}

inline int Price::getDolar()const
{
	return m_dolar;
}

inline int Price::getCents()const
{
	return m_cents;
}

inline char Price::getSign()const
{
	return m_sign;
}
inline void Price::setSign()
{
	if(m_sign=='-')
		m_sign='+';
	else
		m_sign='-';
}
inline bool Price::isNegative()const
{
	if(m_sign=='+')
		return false;
	else
		return true;
}

inline std::ostream& operator <<(std::ostream& os,const Price& p)
{
	os<<p.m_dolar<<"."<<p.m_cents<<std::endl;
	return os;
}

inline Price Price::operator -()const
{
	if(isNegative())
		return Price(m_dolar,m_cents);
	else
		return Price(m_dolar,m_cents,'-');
} 

inline Price& Price::operator +=(const Price& p)
{
	*this=*this+p;
	return *this;
	
}
inline Price& Price::operator -=(const Price& p)
{
	*this=*this-p;
	return *this;
	
}
inline Price& Price::operator--()
{
	*this-=Price(1);
	return *this;
}
inline Price& Price::operator++()
{
	*this+=Price(1);
	return *this;
}
inline Price Price::operator--(int)
{
	Price res(*this);
	*this-=Price(1);
	return res;
}
inline Price Price::operator++(int)
{
	Price res(*this);
	*this+=Price(1);
	return res;

}
/*
inline Price operator/(const Price& p1,const Price& p2)//to chek if not 0
{
	if((p2.getDolar()!=0)||(p2.getCents()!=0))
	{
        	return Price ((p1.getDolar()*100+p1.getCents())/(p2.getDolar()*100+p2.getCents()),(p1.getDolar()*100+p1.getCents())%(p2.getDolar()*100+p2.getCents()));
	}
	else
	{
		throw std::runtime_error("Math error: Attempted to divide by Zero\n"); 
	}
}

inline Price& operator%(Price& p1, Price& p2)
{
	Price& p3;


}*/

#endif
