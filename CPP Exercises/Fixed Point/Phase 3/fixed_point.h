#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <iostream>
#include <cstring>
#include <math.h>
#include <limits.h>
#include <stdexcept>
#include <stdbool.h>
		

template <unsigned int SIZE,class T=int> class FixedPoint
{
	
public:
	FixedPoint();
	FixedPoint(T dolar ,int cents ,char sign='+');
	FixedPoint(T dolar ,char sign='+');
	FixedPoint(const FixedPoint<SIZE,T>& p);
	FixedPoint<SIZE,T>& operator =(int centsAmount);
	FixedPoint<SIZE,T> operator -()const;
	FixedPoint<SIZE,T>& operator +=(const FixedPoint<SIZE,T>& p);
	FixedPoint<SIZE,T>& operator -=(const FixedPoint<SIZE,T>& p);
	FixedPoint<SIZE,T>& operator --();
	FixedPoint<SIZE,T>& operator ++();
	FixedPoint<SIZE,T> operator --(int);
	FixedPoint<SIZE,T> operator ++(int);
	operator double(){
		if(m_sign=='-')
			return (double)m_dolar+ m_cents/double(transe);
		else 
			return (double)m_dolar+ abs(m_cents)/double(transe);}

	T getDolar()const;
	int getCents()const;
	char getSign()const;
	void setSign();
	bool isNegative()const;
	const unsigned int getSize();

private:
	void init(T dolar,char sign, int cents=0);
	T m_dolar;
	int m_cents;
	char m_sign;
	static const unsigned int transe=pow(10,SIZE);


template<class U>
friend std::ostream& operator << (std::ostream& os,const FixedPoint<SIZE,T>& p);
};



template<unsigned int SIZE, class T>
inline void FixedPoint<SIZE,T>::init(T dolar,char sign, int cents)
{
	if(dolar<0)
	{
	     sign='-';
	     dolar=(-1)*(dolar);
	     if(cents<0)
		cents=(-1)*(cents);
	}
	if(cents<0)
	{
		unsigned int digits=int(std::to_string(-1*(cents)).length());
		int p=pow(10,digits);
		int tempd=(dolar*p+cents)/p;
		cents=(dolar*p+cents)%p;
		dolar=tempd;
	}  
	while(cents%10==0&&cents!=0)
	{
		cents=cents/10;
	}  
	unsigned int digits=int(std::to_string(cents).length());
	if(SIZE<digits)
	{
		cents=cents/pow(10,digits-SIZE);
	}
	m_sign=sign;	
        m_dolar=dolar;
	m_cents=cents;
	/*if(cents>0&&T(dolar+(cents/transe))<T(dolar))
  		throw std::overflow_error("overflow. You put very big int!");*/
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>::FixedPoint(const FixedPoint<SIZE,T>& p)
{
	init(p.getDolar(),p.getSign(),p.getCents());
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T> operator +(const FixedPoint<SIZE,T> p1,const FixedPoint<SIZE,T> p2)
{
	if((!p1.isNegative()&&!p2.isNegative())||( p1.isNegative()&& p2.isNegative()))
	{
		if((p1.getDolar()+p2.getDolar())<p1.getDolar()||(p1.getDolar()+p2.getDolar())<p2.getDolar()||(p1.getCents()+p2.getCents())<p1.getCents()||(p1.getCents()+p2.getCents())<p2.getCents())
			throw std::overflow_error("overflow. You put very big int!");
		unsigned int digits=int(std::to_string(abs(p1.getCents())).length());
		int dolar=p1.getDolar()+p2.getDolar();
		int cents=p1.getCents()+p2.getCents();
		int p=pow(10,digits);
                int tempdolar=(dolar*p+cents)/p;
		cents=(dolar*p+cents)%p;
		dolar=tempdolar;
		return FixedPoint<SIZE,T> (dolar,cents,'+');
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
 
template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T> operator -(const FixedPoint<SIZE,T> p1,const FixedPoint<SIZE,T> p2)
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
				if((p1.getDolar()-p2.getDolar())>p1.getDolar())
					throw std::overflow_error("overflow. You put very big int!");
			    	return FixedPoint<SIZE,T> (p1.getDolar()-p2.getDolar(),p1.getCents()-p2.getCents(),'+');
			}
			else
			{
			    return FixedPoint<SIZE,T> (p2.getDolar()-p1.getDolar(),p2.getCents()-p1.getCents(),'-');
			}
		}
			
	}
}

template<unsigned int SIZE, class T>
inline bool operator >(const FixedPoint<SIZE,T>& p1,const FixedPoint<SIZE,T>& p2)
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

template<unsigned int SIZE, class T>
inline bool operator ==(const FixedPoint<SIZE,T>& p1,const FixedPoint<SIZE,T>& p2)
{
	if(p1.getDolar()==p2.getDolar()&&p1.getCents()==p2.getCents())
		return true;
	else
		return false;
}

template<unsigned int SIZE, class T>
inline bool operator <=(const FixedPoint<SIZE,T>& p1,const FixedPoint<SIZE,T>& p2)
{
	return !(p1>p2);

}

template<unsigned int SIZE, class T>
inline bool operator <(const FixedPoint<SIZE,T>& p1,const FixedPoint<SIZE,T>& p2)
{
	return !(p1>p2) && !(p1==p2);
}


template<unsigned int SIZE,class T>
inline bool operator >=(const FixedPoint<SIZE,T>& p1,const FixedPoint<SIZE,T>& p2)
{
	return !(p1<p2);

}

template<unsigned int SIZE, class T>
inline bool operator !=(const FixedPoint<SIZE,T>& p1,const FixedPoint<SIZE,T>& p2)
{
	return !(p1==p2);
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>::FixedPoint():m_dolar(0),m_cents(0),m_sign('0')
{}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>::FixedPoint(T dolar, int cents,char sign):m_dolar(0),m_cents(0),m_sign('0')
{
	
	init(dolar,sign,cents);
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>::FixedPoint(T dolar,char sign):m_dolar(0),m_cents(0),m_sign('0')
{
       init(dolar,sign);
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator =(int centsAmount)
{
	int dolar=centsAmount/transe;
	int cents=centsAmount%transe;
	init(dolar,'+', cents);
	return *this;
}


template<unsigned int SIZE, class T>
inline T FixedPoint<SIZE,T>::getDolar()const
{
	return m_dolar;
}

template<unsigned int SIZE, class T>
inline int FixedPoint<SIZE,T>::getCents()const
{
	return m_cents;
}

inline int FixedPoint<SIZE,T>::getSize()const
{
	return transe;
}

template<unsigned int SIZE, class T>
inline char FixedPoint<SIZE,T>::getSign()const
{
	return m_sign;
}

template<unsigned int SIZE, class T>
inline void FixedPoint<SIZE,T>::setSign()
{
	if(m_sign=='-')
		m_sign='+';
	else
		m_sign='-';
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE,T>::isNegative()const
{
	if(m_sign=='+')
		return false;
	else
		return true;
}

template<unsigned int SIZE, class T>
inline std::ostream& operator <<(std::ostream& os,const FixedPoint<SIZE,T>& p)
{
	os<<p.m_dolar<<"."<<p.m_cents<<std::endl;
	return os;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T> FixedPoint<SIZE,T>::operator -()const
{
	if(isNegative())
		return FixedPoint(m_dolar,m_cents,'+');
	else
		return FixedPoint(m_dolar,m_cents,'-');
} 

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator +=(const FixedPoint<SIZE,T>& p)
{
	*this=*this+p;
	return *this;
	
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator -=(const FixedPoint<SIZE,T>& p)
{
	*this=*this-p;
	return *this;
	
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator--()
{
	*this-=FixedPoint(1);
	return *this;
}


template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator++()
{
	*this+=FixedPoint(1);
	return *this;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T> FixedPoint<SIZE,T>::operator--(int)
{
	FixedPoint<SIZE,T> res(m_dolar, m_cents,m_sign);
	*this-=FixedPoint<SIZE,T>(1);
	return res;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T> FixedPoint<SIZE,T>::operator++(int)
{
	FixedPoint<SIZE,T> res(*this);
	*this+=FixedPoint<SIZE,T>(1);
	return res;

}
template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>  operator/(const FixedPoint<SIZE,T> & p1,const FixedPoint<SIZE,T> & p2)//to chek if not 0
{
	char sign;
	if((p1.getSign()=='+' && p1.getSign()=='+')||(p1.getSign()=='-' && p1.getSign()=='-'))
		 sign ='+';
	else
		sign='-';
	if((p2.getDolar()!=0)||(p2.getCents()!=0))
	{
        	int cents=(p1.getDolar()*transe+p1.getCents())*(p2.getDolar()*transe+p2.getCents());
		int dolar=cents/transe;
		cents=cents%transe;
		return FixedPoint<SIZE,T> (dolar,cents,sign);
	}
	else
	{
		throw std::runtime_error("Math error: Attempted to divide by Zero\n"); 
	}
}
/*
inline FixedPoint& operator%(FixedPoint& p1, FixedPoint& p2)
{
	FixedPoint& p3;


}*/
template<unsigned int SIZE, class T>
inline FixedPoint<SIZE,T>  operator*(const FixedPoint<SIZE,T> & p1,const FixedPoint<SIZE,T> & p2)
{
	char sign;
	if((p1.getSign()=='+' && p1.getSign()=='+')||(p1.getSign()=='-' && p1.getSign()=='-'))
		 sign ='+';
	else
		sign='-';
	int dolar=p1.getDolar()*p2.getDolar();
	int cents=p1.getDolar()*p2.getCents()*transe;
	cents+=	p2.getDolar()*p1.getCents()*transe;
	cents+=p1.getCents()*p2.getCents();
        int tempdolar=(dolar*transe+cents)/transe;
	cents=(dolar*transe+cents)%transe;
	dolar=tempdolar;
	return<SIZE,T>  FixedPoint(dolar,cents,sign);

}

#endif
