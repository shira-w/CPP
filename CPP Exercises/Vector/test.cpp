#include "test.h"
/*
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/////////////////////////////////////
// TESTS under this line

TEST(ConstractorTests, shortT)
{
    	FixedPoint<2,char> p(120,35,'+');
	EXPECT_EQ(p.getDolar(),120);
    	EXPECT_EQ(p.getCents(),35);
    	EXPECT_EQ(p.getSign(),'+');
}
*/
/*
void TestClass()
{
	try	
	{
		Vector v1(10,1);
	}
	catch(std::exception& e)
	{
		std::cout<<e.what();
	}
	Vector v2(v1);
	Vector v3(1,2);
	v3=v2;
	printf("%d %d %d",v1.getSize(),v2.getSize(),v3.getSize());
	printf("%d %d %d",v1.getCapacity(),v2.getCapacity(),v3.getCapacity());
	size_t i;
	for(i=0;i<v1.getSize();i++)
	{
		printf("%d %d %d \n",v1.getArr()[i],v2.getArr()[i],v3.getArr()[i]);
	}
	if(v1.isEmpty())
		printf("NOT OK");
	else
		printf("OK");
	printf("insert");
	try	
	{
		v1.insert(2,2);
	}
	catch(std::exception& e)
	{
		std::cout<<e.what();
	}
	
	for(i=0;i<v1.getSize();i++)
	{
		printf("%d ",v1.getArr()[i]);
	}
	printf("push");
	v1.pushBack(9);
	for(i=0;i<v1.getSize();i++)
	{
		printf("%d ",v1.getArr()[i]);
	}
	printf("pop");
	v1.popBack();
	
	for(i=0;i<v1.getSize();i++)
	{
		printf("%d ",v1.getArr()[i]);
	}
	v1.removeByValue(1);
	printf("REMOVE by value\n");
	for(i=0;i<v1.getSize();i++)
	{
		printf("%d ",v1.getArr()[i]);
	}
	try	
	{
		v1.removeByIndex(0);
	}
	catch(std::exception& e)
	{
		std::cout<<e.what();
	}
	
	printf("REMOVE by index\n");
	for(i=0;i<v1.getSize();i++)
	{
		printf("%d ",v1.getArr()[i]);
	}
	printf("operator []\n");
	printf("%d",v2[5]);
	printf("operator [] const\n");
	const Vector v4=v2;
	printf("%d",v4[5]);
}
void TestGlobalFuncs()
{
	Vector v1(5,1);
	Vector v2(5,2);
	printf("%d",(v1==v2));
	printf("%d",(v1!=v2));
	printf("%d",(v1<v2));
	printf("%d",(v1>v2));
	printf("%d",(v1<=v2));
	printf("%d",(v1>=v2));
	printf("+");
	Vector v3(v1+v2);
	v1+=v2;
	size_t i;
	for ( i = 0; i < v3.getSize(); i++)
	{
		printf("%d ",v3.getArr()[i]);
	}
	printf("+=");
	for ( i = 0; i < v1.getSize(); i++)
	{
		printf("%d ",v1.getArr()[i]);
	}
	printf("<<");
	std::cout<<v1;
}*/
