#include "fixed_point.h"
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/////////////////////////////////////
// TESTS under this line

TEST(ConstractorTests, OnlyDolar)
{
    Price p(5);
    EXPECT_EQ(p.getDolar(),5);
    EXPECT_EQ(p.getCents(),0);
    EXPECT_EQ(p.getSign(),'+');
    Price p1(5,'-');
    EXPECT_EQ(p1.getDolar(),5);
    EXPECT_EQ(p1.getCents(),0);
    EXPECT_EQ(p1.getSign(),'-');
}
TEST(ConstractorTests, WithCents)
{
    Price p(5,20);
    EXPECT_EQ(p.getDolar(),5);
    EXPECT_EQ(p.getCents(),20);
    EXPECT_EQ(p.getSign(),'+');
    Price p1(-5,-20);
    EXPECT_EQ(p1.getDolar(),5);
    EXPECT_EQ(p1.getCents(),20);
    EXPECT_EQ(p1.getSign(),'-');

    Price p2(5,INT_MAX);//maxint cents
    EXPECT_EQ(p2.getDolar(),(INT_MAX/100)+5);
    EXPECT_EQ(p2.getCents(),INT_MAX%100);
    EXPECT_EQ(p2.getSign(),'+');

    ASSERT_THROW(Price p3(INT_MAX-1,200),std::overflow_error);//together maxint 

    Price p8(-5,-20,'-');
    EXPECT_EQ(p8.getDolar(),5);
    EXPECT_EQ(p8.getCents(),20);
    EXPECT_EQ(p8.getSign(),'-');

    Price p9(5,20,'-');
    EXPECT_EQ(p9.getDolar(),5);
    EXPECT_EQ(p9.getCents(),20);
    EXPECT_EQ(p9.getSign(),'-');

    Price p10(-5,'+');
    EXPECT_EQ(p10.getDolar(),5);
    EXPECT_EQ(p10.getSign(),'-');


    Price p11(-5,20,'+');
    EXPECT_EQ(p11.getDolar(),5);
    EXPECT_EQ(p11.getCents(),20);
    EXPECT_EQ(p11.getSign(),'-');

    Price p12(5,-20,'+');//4.8
    EXPECT_EQ(p12.getDolar(),4);
    EXPECT_EQ(p12.getCents(),80);
    EXPECT_EQ(p12.getSign(),'+');

    Price p13(5,-20,'-');//-4.8
    EXPECT_EQ(p13.getDolar(),4);
    EXPECT_EQ(p13.getCents(),80);
    EXPECT_EQ(p13.getSign(),'-');

    Price p14(5,200);//7
    EXPECT_EQ(p14.getDolar(),7);
    EXPECT_EQ(p14.getCents(),0);
    EXPECT_EQ(p14.getSign(),'+');

    Price p15(5,220);//7.2
    EXPECT_EQ(p15.getDolar(),7);
    EXPECT_EQ(p15.getCents(),20);
    EXPECT_EQ(p15.getSign(),'+');
   
}

TEST(ConstractorTests, Test16)
{
    Price p16(-5,-200);//-7
    EXPECT_EQ(p16.getDolar(),7);
    EXPECT_EQ(p16.getCents(),0);
    EXPECT_EQ(p16.getSign(),'-');
}

TEST(ConstractorTests, Test17)
{
    Price p17(5,-200);//3
    EXPECT_EQ(p17.getDolar(),3);
    EXPECT_EQ(p17.getCents(),0);
    EXPECT_EQ(p17.getSign(),'+');
}
TEST(ConstractorTests, Test18)
{
    Price p18(5,-200,'-');//-3
    EXPECT_EQ(p18.getDolar(),3);
    EXPECT_EQ(p18.getCents(),0);
    EXPECT_EQ(p18.getSign(),'-');
}
TEST(ConstractorTests, Test19)
{
    Price p19(5,200,'-');//-7
    EXPECT_EQ(p19.getDolar(),7);
    EXPECT_EQ(p19.getCents(),0);
    EXPECT_EQ(p19.getSign(),'-');
}

TEST(TestsOpPlus, Plus)
{
    Price p(5,20);//regular
    Price p1(6,40);
    EXPECT_EQ((p+p1).getDolar(),11);
    EXPECT_EQ((p+p1).getCents(),60);
    EXPECT_EQ((p+p1).getSign(),'+');
    Price p2(5,70);//change dolar
    Price p3(6,40);
    EXPECT_EQ((p2+p3).getDolar(),12);
    EXPECT_EQ((p2+p3).getCents(),10);
    EXPECT_EQ((p2+p3).getSign(),'+');

}

TEST(TestOpBig,OneNegative)
{
    Price p1(-5,20);
    Price p2(6,40);
    EXPECT_FALSE(p1>p2);
    EXPECT_TRUE(p2>p1);
}
TEST(TestOpBig,twoNegative)
{
    Price p1(-5,20);
    Price p2(-6,40);
    EXPECT_TRUE(p1>p2);
    EXPECT_FALSE(p2>p1);
}

TEST(TestOpBig,twoPositive)
{
    Price p1(5,20);
    Price p2(6,40);
    EXPECT_FALSE(p1>p2);
    EXPECT_TRUE(p2>p1);
}

TEST(TestOpBig,twoAqualDolars)
{
    Price p1(5,20);
    Price p2(5,40);
    EXPECT_FALSE(p1>p2);
    EXPECT_TRUE(p2>p1);
}

TEST(TestOpBig,twoAqual)
{
    Price p1(5,40);
    Price p2(5,40);
    EXPECT_FALSE(p1>p2);
    EXPECT_FALSE(p2>p1);
}

TEST(TestOpSmall,twoNegative)
{
    Price p1(-5,20);
    Price p2(-6,40);
    EXPECT_FALSE(p1<p2);
    EXPECT_TRUE(p2<p1);
}

TEST(TestOpSmall,twoPositive)
{
    Price p1(5,20);
    Price p2(6,40);
    EXPECT_TRUE(p1<p2);
    EXPECT_FALSE(p2<p1);
}

TEST(TestOpSmall,twoAqualDolars)
{
    Price p1(5,20);
    Price p2(5,40);
    EXPECT_TRUE(p1<p2);
    EXPECT_FALSE(p2<p1);
}

TEST(TestOpSmall,twoAqual)
{
    Price p1(5,40);
    Price p2(5,40);
    EXPECT_FALSE(p1<p2);
    EXPECT_FALSE(p2<p1);
}

TEST(TestOpEq,regular)
{
    Price p1(5,40);
    Price p2(5,40);
    Price p3(8,40);
    Price p4(5,30);
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
    Price p1(5,40);
    Price p2(-5,40);
    EXPECT_EQ((-p1).getSign(),'-');
    EXPECT_EQ((-p2).getSign(),'+');
}
TEST(TestMinusOp,regular)//5-3
{
    Price p1(5,40);
    Price p2(6,20);
    EXPECT_EQ((p2-p1).getDolar(),0);
    EXPECT_EQ((p2-p1).getCents(),80);
    EXPECT_EQ((p2-p1).getSign(),'+');
}
TEST(TestMinusOp,oposite)//3-5
{
    Price p1(5,40);
    Price p2(6,20);
    Price p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),0);
    EXPECT_EQ(p3.getCents(),80);
    EXPECT_EQ(p3.getSign(),'-');
}

TEST(TestMinusOp,SecondNegative)//5 - (-6)
{
    Price p1(5,40);
    Price p2(-6,20);
    Price p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),11);
    EXPECT_EQ(p3.getCents(),60);
    EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestMinusOp,FirstNegative)//(-5)-7
{
    Price p1(-5,40);
    Price p2(6,20);
    Price p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),11);
    EXPECT_EQ(p3.getCents(),60);
    EXPECT_EQ(p3.getSign(),'-');
}
	
TEST(TestMinusOp,TwoNegatives)//(-4)-(-2)
{
    Price p1(-5,40);
    Price p2(-6,20);
    Price p3=p1-p2;
    EXPECT_EQ(p3.getDolar(),0);
    EXPECT_EQ(p3.getCents(),80);
    EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestsOpPlus, regular)
{
    Price p1(5,20);
    Price p2(6,90);
    Price p3=p1+p2;
    EXPECT_EQ(p3.getDolar(),12);
    EXPECT_EQ(p3.getCents(),10);
    EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestsOpPlus, SecondNegative)//5+(-8)
{
    	Price p1(5,20);
    	Price p2(-6,90);
    	Price p3=p1+p2;
   	EXPECT_EQ(p3.getDolar(),1);
    	EXPECT_EQ(p3.getCents(),70);
    	EXPECT_EQ(p3.getSign(),'-');
}

TEST(TestsOpPlus, FirstNegative)//(-8)+5
{
    	Price p1(-5,20);
    	Price p2(6,90);
    	Price p3=p1+p2;
    	EXPECT_EQ(p3.getDolar(),1);
    	EXPECT_EQ(p3.getCents(),70);
    	EXPECT_EQ(p3.getSign(),'+');
}
TEST(TestsOpPlus, ChekOverflow)
{	
    	Price p1(5,INT_MAX-8);//maxint cents
    	Price p2(5,100);
    	Price p3=p1+p2;
    	EXPECT_EQ(p3.getDolar(),21474847);
    	EXPECT_EQ(p3.getCents(),(INT_MAX-8)%100);
    	EXPECT_EQ(p3.getSign(),'+');
}

TEST(TestsOpPlus, ChekOverflow2)
{
    	Price p1(INT_MAX-7);//maxint cents
    	Price p2(8);
    	ASSERT_THROW(p1+p2,std::overflow_error);//together maxint 

}

TEST(TestsOpPlusEq, regular)
{
    	Price p1(5,70);//maxint cents
    	Price p2(5,90);
    	p1+=p2;
    	EXPECT_EQ(p1.getDolar(),11);
   	EXPECT_EQ(p1.getCents(), 60);
    	EXPECT_EQ(p1.getSign(),'+');
}
TEST(TestsOpMinusEq, regular)
{
    	Price p1(5,70);//maxint cents
    	Price p2(5,90);
    	p1-=p2;
    	EXPECT_EQ(p1.getDolar(),0);
    	EXPECT_EQ(p1.getCents(), 20);
    	EXPECT_EQ(p1.getSign(),'-');
}
TEST(TestsOpPlusPlus, regular)
{
    	Price p(5,70);
    	p++;
    	EXPECT_EQ(p.getDolar(),6);
    	EXPECT_EQ((p++).getDolar(),6);
    	EXPECT_EQ(p.getDolar(),7);
}

TEST(TestsOpCastToDouble, regular)
{
    	Price p(5,70);
    	EXPECT_EQ(double(p),5.7);
}
TEST(TestsOpCastToDouble, negative)
{
    	Price p(-5,70);
    	EXPECT_EQ(double(p),-5.7);
}/*
TEST(TestsOpDevision, regular)
{
    	Price p1(5,70);
  	Price p2(3,40);
	Price p3=p1/p2;
    	EXPECT_EQ(p3.getDolar(),1);
	EXPECT_EQ(p3.getCents(),60);
}*/
