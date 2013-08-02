#include "Tests.hpp"

TEST(TypesTests, DefaultVectorConstructors) {
    float2 v;
    EXPECT_EQ(0.0f, v.x);
    EXPECT_EQ(0.0f, v.y);

    float3 v2;
    EXPECT_EQ(0.0f, v2.x);
    EXPECT_EQ(0.0f, v2.y);
    EXPECT_EQ(0.0f, v2.z);

    int2 v3;
    EXPECT_EQ(0, v3.x);
    EXPECT_EQ(0, v3.y);

    int3 v4;
    EXPECT_EQ(0, v4.x);
    EXPECT_EQ(0, v4.y);
    EXPECT_EQ(0, v4.z);
}

TEST(TypesTests, ValuedVectorConstructors) {
    float2 f2(1.1f, -2.0f);
    EXPECT_EQ(1.1f, f2.x);
    EXPECT_EQ(-2.0f, f2.y);

    float3 f3(1.2f, -2.0f, 4.0f);
    EXPECT_EQ(1.2f, f3.x);
    EXPECT_EQ(-2.0f, f3.y);
    EXPECT_EQ(4.0f, f3.z);

    int2 i2(-2, 3.2f);
    EXPECT_EQ(-2, i2.x);
    EXPECT_EQ(3, i2.y);

    int3 i3(-2, 2000, 0);
    EXPECT_EQ(-2, i3.x);
    EXPECT_EQ(2000, i3.y);
    EXPECT_EQ(0, i3.z);
}

TEST(TypesTests, VectorLength) {
    float2 f2(-1.0f, 1.0f);
    EXPECT_FLOAT_EQ(1.414213562f, f2.length());

    float3 f3(2.0, 0.5, -1.0f);
    EXPECT_FLOAT_EQ(2.291287847, f3.length());

    int2 i2(4, 2);
    EXPECT_FLOAT_EQ(4.472135955, i2.length());

    int3 i3(-2, 0, 3);
    EXPECT_FLOAT_EQ(3.605551275, i3.length());
}

TEST(TypesTests, VectorDistance) {
    float2 f2_1(1.0f, -2.0f);
    float2 f2_2(4.0f, 1.0f);
    EXPECT_FLOAT_EQ(0.0, f2_1.distance(f2_1));
    EXPECT_FLOAT_EQ(4.242640687, f2_1.distance(f2_2));
    EXPECT_FLOAT_EQ(4.242640687, f2_2.distance(f2_1));

    float3 f3_1(1.0f, 0.5f, -1.0f);
    float3 f3_2(2.0f, 1.0f, -1.0f);
    EXPECT_FLOAT_EQ(0.0, f3_1.distance(f3_1));
    EXPECT_FLOAT_EQ(1.118033989,f3_1.distance(f3_2));
    EXPECT_FLOAT_EQ(1.118033989,f3_2.distance(f3_1));

    int2 i2_1(1,-2);
    int2 i2_2(4,1);
    EXPECT_FLOAT_EQ(0.0, i2_1.distance(i2_1));
    EXPECT_FLOAT_EQ(4.242640687, i2_1.distance(i2_2));
    EXPECT_FLOAT_EQ(4.242640687, i2_2.distance(i2_1));

    int3 i3_1(1,0,-1);
    int3 i3_2(2,1,1);
    EXPECT_FLOAT_EQ(0.0f, i3_1.distance(i3_1));
    EXPECT_FLOAT_EQ(2.449489743, i3_1.distance(i3_2));
    EXPECT_FLOAT_EQ(2.449489743, i3_2.distance(i3_1));

    EXPECT_FLOAT_EQ(0.0,f2_1.distance(i2_1));
    EXPECT_FLOAT_EQ(0.0,i2_1.distance(f2_1));

    EXPECT_FLOAT_EQ(0.5,f3_1.distance(i3_1));
    EXPECT_FLOAT_EQ(0.5,i3_1.distance(f3_1));
}

TEST(TypesTests, VectorNormalize) {
   float2 f2(-2.0, 1.0);
   float2 f2_n = f2.normalize();
   EXPECT_FLOAT_EQ(1.0, f2_n.length());
   EXPECT_FLOAT_EQ(-0.894427191, f2_n.x);
   EXPECT_FLOAT_EQ(0.4472135955, f2_n.y);
   // f2 is unchanged?
   EXPECT_FLOAT_EQ(-2.0, f2.x);
   EXPECT_FLOAT_EQ(1.0, f2.y);

   float3 f3(-2.0, 1.0, 2.4);
   float3 f3_n = f3.normalize();
   EXPECT_FLOAT_EQ(1.0, f3_n.length());
   EXPECT_FLOAT_EQ(-0.6097107608, f3_n.x);
   EXPECT_FLOAT_EQ(0.3048553804, f3_n.y);
   EXPECT_FLOAT_EQ(0.731652913, f3_n.z);
   // f3 is unchanged?
   EXPECT_FLOAT_EQ(-2.0, f3.x);
   EXPECT_FLOAT_EQ(1.0, f3.y);
   EXPECT_FLOAT_EQ(2.4, f3.z);

   int2 i2(-2,1);
   float2 i2_n = i2.normalize();
   EXPECT_FLOAT_EQ(1.0, i2_n.length());
   EXPECT_FLOAT_EQ(-0.894427191, i2_n.x);
   EXPECT_FLOAT_EQ(0.4472135955, i2_n.y);
   // f2 is unchanged?
   EXPECT_EQ(-2, i2.x);
   EXPECT_EQ(1, i2.y);

   int3 i3(-2, 1, 2);
   float3 i3_n = i3.normalize();
   EXPECT_FLOAT_EQ(1.0, i3_n.length());
   EXPECT_FLOAT_EQ(-0.6666666667, i3_n.x);
   EXPECT_FLOAT_EQ(0.3333333333, i3_n.y);
   EXPECT_FLOAT_EQ(0.6666666667, i3_n.z);
   // f3 is unchanged?
   EXPECT_EQ(-2, i3.x);
   EXPECT_EQ(1, i3.y);
   EXPECT_EQ(2, i3.z);
}

TEST(TypesTests, Equal) {
    float2 f2_1(1.0f, -2.0f);
    float2 f2_2(4.0f, 1.0f);
    EXPECT_TRUE(f2_1 == f2_1);
    EXPECT_FALSE(f2_1 == f2_2);

    float3 f3_1(1.0f, 0.5f, -1.0f);
    float3 f3_2(2.0f, 1.0f, -1.0f);
    EXPECT_TRUE(f3_1 == f3_1);
    EXPECT_FALSE(f3_1 == f3_2);

    int2 i2_1(1,-2);
    int2 i2_2(4,1);
    EXPECT_TRUE(i2_1 == i2_1);
    EXPECT_FALSE(i2_1 == i2_2);

    int3 i3_1(1,0,-1);
    int3 i3_2(2,1,-1);
    EXPECT_TRUE(i3_1 == i3_1);
    EXPECT_FALSE(i3_1 == i3_2);

    EXPECT_TRUE(f2_1 == i2_1);
    EXPECT_FALSE(f2_1 == i2_2);

    EXPECT_TRUE(f3_2 == i3_2);
    EXPECT_FALSE(f3_1 == i3_1);
}
