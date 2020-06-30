#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdio.h>

#include <iostream>
#include <cstring>
#include <math.h>
#include <limits.h>
#include <stdexcept>
#include <stdbool.h>

template <class T> class Price
{
public:
	Price();
	Price(T dolar ,T cents ,char sign='+');
	Price(T dolar ,char sign='+');
	Price(const Price<T>& p);
	Price<T>& operator =(T centsAmount);
	Price<T> operator -()const;
	Price<T>& operator +=(const Price<T>& p);
	Price<T>& operator -=(const Price<T>& p);
	Price<T>& operator --();
	Price<T>& operator ++();
	Price<T> operator --(int);
	Price<T> operator ++(int);
	operator double(){
		if(m_sign=='-')return (double)-m_dolar+ m_cents/-100.0;
		else return (double)m_dolar+ m_cents/100.0;}

	T getDolar()const;
	T getCents()const;
	char getSign()const;
	void setSign();
	bool isNegative()const;

private:
	void init(T dolar,char sign, T cents=0);
	T m_dolar;
	T m_cents;
	char m_sign;

template<class U>
friend std::ostream& operator << (std::ostream& os,const Price<T>& p);
};

template<class T>
inline void Price<T>::init(T dolar,char sign, T cents)
{
	if(sign=='+')
	{
	     if(dolar+(cents/100)<0)
		sign='-';

	}
	if(dolar<0)
	{
	     cents=abs(cents);
	     dolar=abs(dolar);
	}

	m_dolar=dolar + (cents/T(100));
	m_cents=(cents%T(100));

	m_sign=sign;	
        if(cents<0 && dolar>0)
	{
		m_dolar=T((dolar*100+cents)/100);
		m_cents=T((dolar*100+cents)%100);
	}
	if(cents>0&&T(dolar+(cents/100))<T(dolar))
  		throw std::overflow_error("overflow. You put very big int!");
}

template< class T>
inline Price<T>::Price(const Price<T>& p)
{
	init(p.getDolar(),p.getSign(),p.getCents());
}

template< class T>
inline Price<T> operator +(const Price<T> p1,const Price<T> p2)
{
	if((!p1.isNegative()&&!p2.isNegative())||( p1.isNegative()&& p2.isNegative()))
	{
		if((p1.getDolar()+p2.getDolar())<p1.getDolar()||(p1.getCents()+p2.getCents())<p1.getCents())
			throw std::overflow_error("overflow. You put very big int!");
		return Price<T> (p1.getDolar()+p2.getDolar(),p1.getCents()+p2.getCents(),'+');
	}
	else
	{
		if(p1.isNegative())
		{
			return p2-(-p1);
		}
		else
		{
			return p1-(-p2);
		}
	}
	
}
 
template< class T>
inline Price<T> operator -(const Price<T> p1,const Price<T> p2)
{
	
	if(p2.isNegative())
	{
		return (p1+-p2);	
	}
	else
	{
		if(p1.isNegative())
		{
			return -(-p1+p2);
		}
		else
		{
			if(p1>=p2)
			{
			    return Price<T> (p1.getDolar()-p2.getDolar(),p1.getCents()-p2.getCents(),'+');
			}
			else
			{
			    return Price<T> (p2.getDolar()-p1.getDolar(),p2.getCents()-p1.getCents(),'-');
			}
		}
			
	}
}

template< class T>
inline bool operator >(const Price<T>& p1,const Price<T>& p2)
{
	bool temp;
	if(p1.isNegative())
	{
		if(!p2.isNegative())
			return false;
	}
	else
	{
		if(p2.isNegative())
			return true;
	}
	if(p1.getDolar()>p2.getDolar())
	{
		temp=true;	
	}
	else if (p2.getDolar()>p1.getDolar())
	{
		temp=false;
	}
	else
	{
		if(p1.getCents()>p2.getCents())
			temp=true;
		else 
			temp=false;
	}
	if(p1.isNegative())
		return !temp;
	else
		return temp;
}

template< class T>
inline bool operator ==(const Price<T>& p1,const Price<T>& p2)
{
	if(p1.getDolar()==p2.getDolar()&&p1.getCents()==p2.getCents()&&p1.getSign()==p2.getSign())
		return true;
	else
		return false;
}

template< class T>
inline bool operator <=(const Price<T>& p1,const Price<T>& p2)
{
	return !(p1>p2);

}

template< class T>
inline bool operator <(const Price<T>& p1,const Price<T>& p2)
{
	return !(p1>p2) && !(p1==p2);
}


template< class T>
inline bool operator >=(const Price<T>& p1,const Price<T>& p2)
{
	return !(p1<p2);

}

template< class T>
inline bool operator !=(const Price<T>& p1,const Price<T>& p2)
{
	return !(p1==p2);
}

template< class T>
inline Price<T>::Price():m_dolar(0),m_cents(0),m_sign('0')
{}

template< class T>
inline Price<T>::Price(T dolar, T cents,char sign):m_dolar(0),m_cents(0),m_sign('0')
{
	
	init(dolar,sign,cents);
}

template< class T>
inline Price<T>::Price(T dolar,char sign):m_dolar(0),m_cents(0),m_sign('0')
{
       init(dolar,sign);
}

template< class T>
inline Price<T>& Price<T>::operator =(T centsAmount)
{
	int dolar=centsAmount/100;
	int cents=centsAmount%100;
	init(dolar,'+', cents);
	return *this;
}


template< class T>
inline T Price<T>::getDolar()const
{
	return m_dolar;
}

template< class T>
inline T Price<T>::getCents()const
{
	return m_cents;
}

template< class T>
inline char Price<T>::getSign()const
{
	return m_sign;
}

template< class T>
inline void Price<T>::setSign()
{
	if(m_sign=='-')
		m_sign='+';
	else
		m_sign='-';
}

template< class T>
inline bool Price<T>::isNegative()const
{
	if(m_sign=='+')
		return false;
	else
		return true;
}

template< class T>
inline std::ostream& operator <<(std::ostream& os,const Price<T>& p)
{
	os<<p.m_dolar<<"."<<p.m_cents<<std::endl;
	return os;
}

template< class T>
inline Price<T> Price<T>::operator -()const
{
	if(isNegative())
		return Price(m_dolar,m_cents,'+');
	else
		return Price(m_dolar,m_cents,'-');
} 

template< class T>
inline Price<T>& Price<T>::operator +=(const Price<T>& p)
{
	*this=*this+p;
	return *this;
	
}

template< class T>
inline Price<T>& Price<T>::operator -=(const Price<T>& p)
{
	*this=*this-p;
	return *this;
	
}

template< class T>
inline Price<T>& Price<T>::operator--()
{
	*this-=Price(1);
	return *this;
}


template< class T>
inline Price<T>& Price<T>::operator++()
{
	*this+=Price(1);
	return *this;
}

template< class T>
inline Price<T> Price<T>::operator--(int)
{
	Price<T> res(m_dolar, m_cents,m_sign);
	*this-=Price<T>(1);
	return res;
}

template< class T>
inline Price<T> Price<T>::operator++(int)
{
	Price<T> res(*this);
	*this+=Price<T>(1);
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
