#include "fixed_point.h"

void Price::init(int dolar, int cents,char sign)
{
	if(sign=='+')
	{
	     if(dolar+(cents/100)<0)
		sign='-';

	}
	if(dolar<0)
	{
	     cents=abs(cents);
	}
	m_sign=sign;
	dolar=abs(dolar);	
	m_dolar=(abs(dolar)+(cents/100));
	m_cents=(cents%100);
        if(cents<0 && dolar>0)
	{
		m_dolar=(dolar*100+cents)/100;
		m_cents=(dolar*100+cents)%100;
	}
	if(cents>0&&(dolar+(cents/100))<dolar)
  		throw std::overflow_error("overflow. You put very big int!");
}

bool operator >(const Price& p1,const Price& p2)
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


Price operator -(const Price& p1,const Price& p2)
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
			    return Price (p1.getDolar()-p2.getDolar(),p1.getCents()-p2.getCents());
			}
			else
			{
			    Price p(p2.getDolar()-p1.getDolar(),p2.getCents()-p1.getCents());
			    return (-p);
			}
		}
			
	}
}
Price operator +(const Price& p1,const Price& p2)
{
	if((!p1.isNegative()&&!p2.isNegative())||( p1.isNegative()&& p2.isNegative()))
	{
		if((p1.getDolar()+p2.getDolar())<p1.getDolar()||(p1.getCents()+p2.getCents())<p1.getCents())
			throw std::overflow_error("overflow. You put very big int!");
		return Price (p1.getDolar()+p2.getDolar(),p1.getCents()+p2.getCents());
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
 

