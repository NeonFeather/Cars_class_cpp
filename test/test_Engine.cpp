#include "Engines.h"

#include <gtest.h>

//ASSERT_NO_THROW()
//EXPECT_EQ(a,b)
//ASSERT_ANY_THROW
TEST(BaseEngine, can_createEngine){ASSERT_NO_THROW(T_BaseEngine e());}
TEST(BaseEngine, can_negativePower){
    ASSERT_ANY_THROW(T_BaseEngine e(-2););
}
TEST(BaseEngine, can_getPower){
    T_BaseEngine e(2);
    EXPECT_EQ(e.GetPower(), 2);
}
TEST(BaseEngine, can_addnegativeMileage){
    T_BaseEngine e(2);
    ASSERT_ANY_THROW(e.AddMileage(-2));
}

TEST(BaseEngine, can_getMileage){
    T_BaseEngine a(2);
    EXPECT_EQ(a.GetMileage(), 0);
    a.AddMileage(100);
    EXPECT_EQ(a.GetMileage(), 100);
}

TEST(BaseEngine, CopyConstructorWorks) {

    T_BaseEngine a(123);
  
    T_BaseEngine b(a);
  
    EXPECT_EQ(a.GetPower(), b.GetPower());
  }

TEST(Gamma, can_createEngine){ASSERT_NO_THROW(Gamma e(123,100));}
TEST(Gamma, can_negativeVolume){
    ASSERT_ANY_THROW(Gamma e(-1,123););
}
TEST(Gamma, can_GetInjectionType){
    Gamma e(2,2);
    EXPECT_EQ(e.GetInjectionType(), "MSI");
}
TEST(Gamma, CopyConstructorWorks) {

    Gamma a(1.6, 123);

    Gamma b(a);

    EXPECT_EQ(a.GetVolume(), 1.6);
}
  
