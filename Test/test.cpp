#include <gtest/gtest.h>
#include "MyMathLib.h"
#include "Account.h"
#include <vector>
#include <iostream>
// in case of failure there are fatal and no-fatal failure
//ASSERT_# is fatal. fatal means no further execution
//EXPECT_# is non-fatal. non-fatal means further execution and test continue

TEST(TestSuiteSample, TestSample)
{
    int s = sum(2, 4);
    ASSERT_EQ(6,s);
}

TEST(TestSuiteSample, AddsNegativeNumbers) {
    ASSERT_EQ(-7, sum(-2, -5));
}

TEST(TestCountPositive, countPositive) {
    std::vector<int> inputVector{1,-2,3,-4,5,-6,-7};
    
    int count = countPositives(inputVector);
    ASSERT_EQ(3, count);
}

TEST(TestCountPositive, emptyVectorTest) {
    std::vector<int> inputVector{};
    
    int count = countPositives(inputVector);
    ASSERT_EQ(0, count);
}

TEST(TestCountPositive, allNegativeValueTest) {
    std::vector<int> inputVector{-1,-1,-3,-4,-5,-9};
    
    int count = countPositives(inputVector);
    ASSERT_EQ(0, count);
    //ASSERT_GE(0, count);
    //if the test failed with ASSERT it will not exexute the next statment for example:
    //ASSERT_EQ(20, count); 
    //but with expect it continues 
    //EXPECT_EQ(20, count);
    //std::cout<<"line 40"<<"\n";
}
//for c-string we use ASSERT_STREQ
TEST(StringTest, upperTest) {
    std::vector<int> inputVector{-1,-1,-3,-4,-5,-9};
    
    char inputString[] = "Hello World";
    toUpper(inputString);
    //ASSERT_EQ("HELLO WORLD", inputString); fails
    //std::string str(inputString); 
    //ASSERT_EQ("HELLO WORLD", str); pass
    ASSERT_STREQ("HELLO WORLD", inputString);
    
}

TEST(SqurtTest, negativeArgumentTEst)
{
    //ASSERT_ANY_THROW(mySqrt(-9));
    ASSERT_THROW(mySqrt(-9), std::runtime_error);
}

TEST(SqurtTest, positiveArgumentTEst)
{
    //ASSERT_ANY_THROW(mySqrt(-9));
    ASSERT_NO_THROW(mySqrt(9));
}


TEST(AccountTest, EmptyAccountTest)
{
    Account acc;
    double balance = acc.getBalance();
    ASSERT_EQ(0, balance);
}

class AccountTestFixture: public testing::Test
{
    public:
    void SetUp() override;
    void TearDown() override;
    static void SetUpTestCase();
    static void TearDownTestCase();
    protected:
    Account account;
};

void AccountTestFixture::SetUpTestCase()
{
    std::cout<<"SetUpTestCase called"<<"\n";
}

void AccountTestFixture::TearDownTestCase()
{
    std::cout<<"TearDownTestCase called"<<"\n";
}


void AccountTestFixture::SetUp()
{
    std::cout<<"SetUp called"<<"\n";
    account.deposite(200);
}

void AccountTestFixture::TearDown()
{
    std::cout<<"Teardown called"<<"\n";
}

TEST_F(AccountTestFixture, DepositeTest)
{
    double balance = account.getBalance();
    ASSERT_EQ(200, balance);
}

TEST_F(AccountTestFixture, TestWithdrwal)
{
    account.withdraw(100);
    ASSERT_EQ(100, account.getBalance());
}

TEST_F(AccountTestFixture, TestWithdrwalInsufficientFund)
{
    ASSERT_THROW(account.withdraw(300), std::runtime_error);
}

TEST_F(AccountTestFixture, TransferTest)
{
    Account to;
    account.transfer(to,100);
    ASSERT_EQ(100, account.getBalance());
    ASSERT_EQ(100, to.getBalance());
}

TEST_F(AccountTestFixture, TransferInsufficientFundTest)
{
    Account to;
    ASSERT_THROW(account.transfer(to,300), std::runtime_error);
}

int main(int argc, char**argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
