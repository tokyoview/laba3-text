#include <gtest.h>
#include "TString.h"

TEST(TStringTest, DefaultConstructor) {
    TString s;
    EXPECT_EQ(nullptr, s.GetStr());
    EXPECT_EQ(0, s.GetLen());
}

TEST(TStringTest, CharConstructor) {
    char test[] = "hello";
    TString s(test, 5);
    EXPECT_STREQ("hello", s.GetStr());
    EXPECT_EQ(5, s.GetLen());
}

TEST(TStringTest, CharConstructorWithNull) {
    TString s(nullptr, 0);
    EXPECT_EQ(nullptr, s.GetStr());
    EXPECT_EQ(0, s.GetLen());
}

TEST(TStringTest, CopyConstructor) {
    char test[] = "copy";
    TString s1(test, 4);
    TString s2(s1);
    EXPECT_STREQ("copy", s2.GetStr());
    EXPECT_EQ(4, s2.GetLen());
}

/* TEST(TStringTest, MoveConstructor) {
    char test[] = "move";
    TString s1(test, 4);
    TString s2(std::move(s1));
    EXPECT_STREQ("move", s2.GetStr());
    EXPECT_EQ(4, s2.GetLen());
    EXPECT_EQ(nullptr, s1.GetStr());
} */

TEST(TStringTest, AssignmentOperator) {
    char test[] = "assign";
    TString s1(test, 6);
    TString s2;
    s2 = s1;
    EXPECT_STREQ("assign", s2.GetStr());
    EXPECT_EQ(6, s2.GetLen());
}

TEST(TStringTest, ConcatenationOperator) {
    char test1[] = "hello";
    char test2[] = "world";
    TString s1(test1, 5);
    TString s2(test2, 5);
    TString s3 = s1 + s2;
    EXPECT_STREQ("helloworld", s3.GetStr());
    EXPECT_EQ(10, s3.GetLen());
}

TEST(TStringTest, MultiplicationOperator) {
    char test[] = "ab";
    TString s1(test, 2);
    TString s2 = s1 * 3;
    EXPECT_STREQ("ababab", s2.GetStr());
    EXPECT_EQ(6, s2.GetLen());
}

TEST(TStringTest, EqualityOperator) {
    char test1[] = "test";
    char test2[] = "test";
    char test3[] = "diff";
    TString s1(test1, 4);
    TString s2(test2, 4);
    TString s3(test3, 4);
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(TStringTest, InequalityOperator) {
    char test1[] = "test";
    char test2[] = "test";
    char test3[] = "diff";
    TString s1(test1, 4);
    TString s2(test2, 4);
    TString s3(test3, 4);
    EXPECT_FALSE(s1 != s2);
    EXPECT_TRUE(s1 != s3);
}

/* TEST(TStringTest, ComparisonOperators) {
    char test1[] = "abc";
    char test2[] = "def";
    TString s1(test1, 3);
    TString s2(test2, 3);
    EXPECT_TRUE(s1 < s2);
    EXPECT_FALSE(s1 > s2);
    EXPECT_TRUE(s2 > s1);
    EXPECT_FALSE(s2 < s1);
} */

TEST(TStringTest, IndexOperator) {
    char test[] = "index";
    TString s(test, 5);
    EXPECT_EQ('i', s[0]);
    EXPECT_EQ('e', s[3]);
    EXPECT_THROW(s[5], const char*);
}

TEST(TStringTest, WordCount) {
    char test[] = "abababa";
    TString s(test, 7);
    EXPECT_EQ(3, s.WordCount("ab"));
    EXPECT_EQ(3, s.WordCount("aba"));
    EXPECT_EQ(0, s.WordCount("abc"));
}

/* TEST(TStringTest, Split) {
    char test[] = "a,b,c";
    TString s(test, 5);
    TString* res = new TString[3];
    s.Split(",", res);
    EXPECT_STREQ("a", res[0].GetStr());
    EXPECT_STREQ("b", res[1].GetStr());
    EXPECT_STREQ("c", res[2].GetStr());
    delete[] res;
} */

TEST(TStringTest, FirstIndex) {
    char test[] = "find me";
    TString s(test, 7);
    EXPECT_EQ(5, s.FirstIndex("me"));
    EXPECT_EQ(-1, s.FirstIndex("you"));
}

TEST(TStringTest, CountSymbols) {
    char test[] = "aab";
    TString s(test, 3);
    int* counts = s.CountSymbols();
    EXPECT_EQ(2, counts['a']);
    EXPECT_EQ(1, counts['b']);
    delete[] counts;
}

TEST(TStringTest, UniqueSymbols) {
    char test[] = "aabc";
    TString s(test, 4);
    testing::internal::CaptureStdout();
    s.UniqueSymbols();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(std::string::npos, output.find("\"a\""));
    EXPECT_NE(std::string::npos, output.find("\"b\""));
    EXPECT_NE(std::string::npos, output.find("\"c\""));
}

TEST(TStringTest, MostCommonChar) {
    char test[] = "aabbbcc";
    TString s(test, 7);
    testing::internal::CaptureStdout();
    s.MostCommonChar();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(std::string::npos, output.find("\"b\""));
}