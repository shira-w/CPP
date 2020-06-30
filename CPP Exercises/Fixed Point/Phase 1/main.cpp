#include "fixed_point.h"
int main()
{
    Price p(5);
    //EXPECT_EQ(p.getDolar(),5);
    //EXPECT_EQ(p.getCents(),0);
    //EXPECT_EQ(p.getSign(),'+');
    //std::cout<<(abs(INT_MAX )+5)<<std::endl;
    //std::cout<<((INT_MIN ))<<std::endl;
    int i=INT_MAX;
    std::cout<<i <<std::endl;
    Price p1(5,'-');
    //EXPECT_EQ(p.getDolar(),-5);
    //EXPECT_EQ(p.getCents(),0);
    //EXPECT_EQ(p.getSign(),'-');
    //Price p3(INT_MAX,200);
    //std::cout<<p3;

return 1;
}
