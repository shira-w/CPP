#include "fixed_point.h"
#include <gtest/gtest.h>
//flagim-warnings~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~````
//plus of ethe digits etgar?????????????????????????????????????????
//ambigous-----------------------------------------------------------------
//long long to chek from now!!!!!!!!!!!!!!!!!!!!!!!!
//give me 2 and want 4
//digit to function
//testim al plus minus 
//operator hamara

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

TEST(ConstractorTests, Test2)
{
	FixedPoint<2> p1(99999,1234,'-');
    	EXPECT_EQ(p1.getDolar(),99999);
    	EXPECT_EQ(p1.getCents(),12);
    	EXPECT_EQ(p1.getSign(),'-');
}

TEST(ConstractorTests, Test3)
{
    	FixedPoint<7,short> p(5,20,'+');
    	EXPECT_EQ(p.getDolar(),5);
    	EXPECT_EQ(p.getCents(),2);
    	EXPECT_EQ(p.getSign(),'+');
}

TEST(ConstractorTests, Test4)
{
	FixedPoint<2,int> p1(-5,-20,'+');
    	EXPECT_EQ(p1.getDolar(),5);
   	EXPECT_EQ(p1.getCents(),2);
    	EXPECT_EQ(p1.getSign(),'-');
}

TEST(ConstractorTests, Test5)
{
    	FixedPoint<9,long> p2(5,888888888,'+');//maxint cents
    	EXPECT_EQ(p2.getDolar(),5);
    	EXPECT_EQ(p2.getCents(),888888888);
    	EXPECT_EQ(p2.getSign(),'+');
}

TEST(ConstractorTests, Test7)
{

    FixedPoint<1> p8(-5000,-20,'-');
    EXPECT_EQ(p8.getDolar(),5000);
    EXPECT_EQ(p8.getCents(),2);
    EXPECT_EQ(p8.getSign(),'-');
}

TEST(ConstractorTests, Test8)
{
    FixedPoint<9,long long> p9(5000000000,2000000,'-');
    EXPECT_EQ(p9.getDolar(),5000000000);
    EXPECT_EQ(p9.getCents(),2);
    EXPECT_EQ(p9.getSign(),'-');
}

TEST(ConstractorTests, Test9)
{

    FixedPoint<1,short> p10(-5,'+');
    EXPECT_EQ(p10.getDolar(),5);
    EXPECT_EQ(p10.getSign(),'-');
}

TEST(ConstractorTests, Test10)
{
    FixedPoint<3,char> p11(-5,21234,'+');
    EXPECT_EQ(p11.getDolar(),5);
    EXPECT_EQ(p11.getCents(),212);
    EXPECT_EQ(p11.getSign(),'-');
}

TEST(ConstractorTests, Test11)
{
    FixedPoint<1,int> p12(5,-22,'+');//4.8
    EXPECT_EQ(p12.getDolar(),4);
    EXPECT_EQ(p12.getCents(),7);
    EXPECT_EQ(p12.getSign(),'+');
}

TEST(ConstractorTests, Test12)
{
    FixedPoint<1,char> p13(5,-20,'-');//-4.8
    EXPECT_EQ(p13.getDolar(),4);
    EXPECT_EQ(p13.getCents(),8);
    EXPECT_EQ(p13.getSign(),'-');
}

TEST(ConstractorTests, Test13)
{
    FixedPoint<0,short> p14(7,'+');//7
    EXPECT_EQ(p14.getDolar(),7);
    EXPECT_EQ(p14.getCents(),0);
    EXPECT_EQ(p14.getSign(),'+');

    FixedPoint<6,short> p15(5,220,'+');//7.2
    EXPECT_EQ(p15.getDolar(),5);
    EXPECT_EQ(p15.getCents(),22);
    EXPECT_EQ(p15.getSign(),'+');
   
}
TEST(ConstractorTests, Test14)
{
    FixedPoint<1,int> p13(1,-20,'-');//0.8
    EXPECT_EQ(p13.getDolar(),0);
    EXPECT_EQ(p13.getCents(),8);
    EXPECT_EQ(p13.getSign(),'-');
}

TEST(TestsOpPlus, Plus)
{
    FixedPoint<1,char> p(5,20,'+');//regular
    FixedPoint<1,char> p1(6,40,'+');
    EXPECT_EQ((p+p1).getDolar(),11);
    EXPECT_EQ((p+p1).getCents(),6);
    EXPECT_EQ((p+p1).getSign(),'+');

    FixedPoint<1,char> p2(5,70,'+');//change dolar
    FixedPoint<1,char> p3(6,40,'+');
    EXPECT_EQ((p2+p3).getDolar(),12);
    EXPECT_EQ((p2+p3).getCents(),1);
    EXPECT_EQ((p2+p3).getSign(),'+');

}

TEST(TestOpBig,OneNegative)
{
    FixedPoint<1> p1(-5,20,'+');
    FixedPoint<1> p2(6,40,'+');
    EXPECT_FALSE(p1>p2);
    EXPECT_TRUE(p2>p1);
}

TEST(TestOpBig,twoNegative)
{
    FixedPoint<1> p1(-5,20);
    FixedPoint<1> p2(-6,40);
    EXPECT_TRUE(p1>p2);
    EXPECT_FALSE(p2>p1);
}

TEST(TestOpBig,twoPositive)
{
    FixedPoint<1> p1(5,20);
    FixedPoint<1> p2(6,40);
    EXPECT_FALSE(p1>p2);
    EXPECT_TRUE(p2>p1);
}

TEST(TestOpBig,twoAqualDolars)
{
    FixedPoint<1,char> p1(5,20,'+');
    FixedPoint<1,char> p2(5,40,'+');
    EXPECT_FALSE(p1>p2);
    EXPECT_TRUE(p2>p1);
}

TEST(TestOpBig,twoAqual)
{
    FixedPoint<1,char> p1(5,40,'+');
    FixedPoint<1,char> p2(5,40,'+');
    EXPECT_FALSE(p1>p2);
    EXPECT_FALSE(p2>p1);
}

TEST(TestOpSmall,twoNegative)
{
    FixedPoint<4,char> p1(-5,20,'+');
    FixedPoint<4,char> p2(-6,40,'+');
    EXPECT_FALSE(p1<p2);
    EXPECT_TRUE(p2<p1);
}

TEST(TestOpSmall,twoPositive)
{
    FixedPoint<2,short> p1(5,20,'+');
    FixedPoint<2,short> p2(6,40,'+');
    EXPECT_TRUE(p1<p2);
    EXPECT_FALSE(p2<p1);
}

TEST(TestOpSmall,twoAqualDolars)
{
    FixedPoint<2,char> p1(5,20,'+');
    FixedPoint<2,char> p2(5,40,'+');
    EXPECT_TRUE(p1<p2);
    EXPECT_FALSE(p2<p1);
}

TEST(TestOpSmall,twoAqual)
{
    FixedPoint<2,char> p1(5,40,'+');
    FixedPoint<2,char> p2(5,40,'+');
    EXPECT_FALSE(p1<p2);
    EXPECT_FALSE(p2<p1);
}

TEST(TestOpEq,regular)
{
    FixedPoint<2,char> p1(5,40,'+');
    FixedPoint<2,char> p2(5,40,'+');
    FixedPoint<2,char> p3(8,40,'+');
    FixedPoint<2,char> p4(5,30,'+');
    EXPECT_TRUE(p1==p2);
    EXPECT_FALSE(p2==p3);
    EXPECT_FALSE(p4==p1);
    EXPECT_FALSE(p1!=p2);
    EXPECT_TRUE(p2!=p3);
    EXPECT_TRUE(p4!=p1);
    EXPECT_TRUE(p2<=p3);
    EXPECT_TRUE(p1<=p2);
    EXPECT_FALSE(p2>=p3);
    EXPECT_TRUE(p1>=p2);
}

TEST(TestUnaryOp,regular)
{
    FixedPoint<2,char> p1(5,40,'+');
    FixedPoint<2,char> p2(-5,40,'+');
    EXPECT_EQ((-p1).getSign(),'-');
    EXPECT_EQ((-p2).getSign(),'+');
}

TEST(TestMinusOp,regular)//5-3
{
    FixedPoint<2,char> p1(5,40,'+');
    FixedPoint<2,char> p2(6,20,'+');
    EXPECT_EQ((p2-p1).getDolar(),0);
    EXPECT_EQ((p2-p1).getCents(),8);
    EXPECT_EQ((p2-p1).getSign(),'+');
}

TEST(TestMinusOp,oposite)//3-5
{
    FixedPoint<1,char> p1(5,40,'+');
    FixedPoint<1,char> p2(6,20,'+');
    FixedPoint<1,char> p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),0);
    EXPECT_EQ(p3.getCents(),8);
    EXPECT_EQ(p3.getSign(),'-');
}

TEST(TestMinusOp,SecondNegative)//5 - (-6)
{
    FixedPoint<1,char> p1(5,40,'+');
    FixedPoint<1,char> p2(-6,20,'+');
    FixedPoint<1,char> p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),11);
    EXPECT_EQ(p3.getCents(),6);
    EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestMinusOp,FirstNegative)//(-5)-7
{
    FixedPoint<1> p1(-5,40,'+');
    FixedPoint<1> p2(6,20,'+');
    FixedPoint<1> p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),11);
    EXPECT_EQ(p3.getCents(),6);
    EXPECT_EQ(p3.getSign(),'-');
}
	
TEST(TestMinusOp,TwoNegatives)//(-4)-(-2)
{
    FixedPoint<1> p1(-5,40,'+');
    FixedPoint<1> p2(-6,20,'+');
    FixedPoint<1> p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),0);
    EXPECT_EQ(p3.getCents(),8);
    EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestsOpPlus, regular)
{
    FixedPoint<1> p1(5,20,'+');
    FixedPoint<1> p2(6,90,'+');
    FixedPoint<1> p3=p1+p2;
    EXPECT_EQ(p3.getDolar(),12);
    EXPECT_EQ(p3.getCents(),1);
    EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestsOpPlus, SecondNegative)//5+(-8)
{
    	FixedPoint<1,char> p1(5,20,'+');
    	FixedPoint<1,char> p2(-6,90,'+');
    	FixedPoint<1,char> p3=p1+p2;
   	EXPECT_EQ(p3.getDolar(),1);
    	EXPECT_EQ(p3.getCents(),7);
    	EXPECT_EQ(p3.getSign(),'-');
}

TEST(TestsOpPlus, FirstNegative)//(-8)+5
{
    	FixedPoint<1,char> p1(-5,20,'+');
    	FixedPoint<1,char> p2(6,90,'+');
    	FixedPoint<1,char> p3=p1+p2;
    	EXPECT_EQ(p3.getDolar(),1);
    	EXPECT_EQ(p3.getCents(),7);
    	EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestsOpPlus, ChekOverflow2)
{
    	FixedPoint<0,int> p1(INT_MAX-7);//maxint cents
    	FixedPoint<0,int> p2(8);
    	ASSERT_THROW(p1+p2,std::overflow_error);//together maxint 

}

TEST(TestsOpPlusEq, regular)
{
    	FixedPoint<2,int> p1(5,70);
    	FixedPoint<2,int> p2(5,90);
    	p1+=p2;
    	EXPECT_EQ(p1.getDolar(),11);
   	EXPECT_EQ(p1.getCents(), 6);
    	EXPECT_EQ(p1.getSign(),'+');
}

TEST(TestsOpMinusEq, regular)
{
    	FixedPoint<2,int> p1(5,70);
    	FixedPoint<2,int> p2(5,90);
    	p1-=p2;
    	EXPECT_EQ(p1.getDolar(),0);
    	EXPECT_EQ(p1.getCents(), 2);
    	EXPECT_EQ(p1.getSign(),'-');
}

TEST(TestsOpPlusPlus, regular)
{
    	FixedPoint<2,long> p(5,70,'+');
    	p++;
    	EXPECT_EQ(p.getDolar(),6);
    	EXPECT_EQ((p++).getDolar(),6);
    	EXPECT_EQ(p.getDolar(),7);
}

TEST(TestsOpCastToDouble, regular)
{
    	FixedPoint<1,int> p(5,70);
    	EXPECT_EQ(double(p),5.7);
}
/*
TEST(TestsOpCastToDouble, negative)
{
    	FixedPoint<2,int> p(-5,70);
    	EXPECT_EQ(double(p),-5.7);
}
*/

TEST(TestsOpDevision, regular)
{
    	FixedPoint<2,int> p1(5,70);
  	FixedPoint<2,int> p2(3,40);
	FixedPoint<2,int> p3=p1/p2;
    	EXPECT_EQ(p3.getDolar(),1);
	EXPECT_EQ(p3.getCents(),6);
}
