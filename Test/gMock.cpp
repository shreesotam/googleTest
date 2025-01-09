#include <gtest/gtest.h>
#include "MyMathLib.h"
#include "Account.h"
#include "Validator.h"
#include <vector>
#include <iostream>
#include <tuple>
#include <gmock/gmock.h>
#include "IDatabaseConnection.h"
#include "EmployeeManager.h"
// in case of failure there are fatal and no-fatal failure
//ASSERT_# is fatal. fatal means no further execution
//EXPECT_# is non-fatal. non-fatal means further execution and test continue

class MockDatabaseConnection: public IDatabaseConnection
{
    public:
    MockDatabaseConnection(std::string serverAddress);
    MOCK_METHOD(void, connect, ()); // mocking connect() method because we donot want to have real connection to database
    MOCK_METHOD(void, disconnect, ()); // mocking disconnect() method because we donot want to have real dis-connection to database
    //MOCK_METHOD(float, getSalary, (int id), (const, override));
    MOCK_METHOD(float, getSalary, (int),(const));
    MOCK_METHOD(void, updateSalary, (int, float));
    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float, float), (const));
    MOCK_METHOD((std::map<std::string, int>), something, ()); //mocking something() method but it is not declared in IDatabaseConnection
    /*void someMemberMethod()
    {
        throw std::runtime_error("Connection error");
    }*/
    void someMemberMethod(std::string param) 
    {
        throw std::runtime_error("Connection error");
    }
};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{

}

TEST(TestEmployeManager, TestConnection)
{
    MockDatabaseConnection dbConnection("dummystring");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
    EmployeeManager employeeManager(&dbConnection);
    
}

TEST(TestEmployeManager, TestUpdateSalary)
{
    MockDatabaseConnection dbConnection("dummystring");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
   // EXPECT_CALL(dbConnection, updateSalary(50, 1000)).Times(1); //this will fail because we are not passing 50 as id
    EXPECT_CALL(dbConnection, updateSalary(testing::_, testing::_)).Times(1); //if donot care about the value of id and salary
    EmployeeManager employeeManager(&dbConnection);
    employeeManager.setSalary(50, 1000);
    //EXPECT_CALL(dbConnection, updateSalary(1, 1000));
    
}

TEST(TestEmployeManager, TestGeteSalary)
{
    const int employeeId = 50;
    const float salary = 6100;
    MockDatabaseConnection dbConnection("dummystring");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
   // EXPECT_CALL(dbConnection, getSalary(50).Times(1); //this will fail because we are not passing 50 as id
    EXPECT_CALL(dbConnection, getSalary(testing::_)).WillOnce(testing::Return(salary)); //if donot care about the value of id and salary
    EmployeeManager employeeManager(&dbConnection);
    float returendSalary = employeeManager.getSalary(employeeId);

    ASSERT_EQ(returendSalary, 6100);
   
    
}
ACTION(myThrow) //define a custom action
{
    throw std::runtime_error("Connection error");
}
TEST(TestEmployeManager, TestConnectionError)
{
    MockDatabaseConnection dbConnection("dummystring");
    //EXPECT_CALL(dbConnection, connect()).WillOnce(testing::Throw(std::runtime_error("Connection error")));
    EXPECT_CALL(dbConnection, connect()).WillOnce(myThrow()); //with custom action
    //EXPECT_CALL(dbConnection, disconnect());
    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
    
}

void someMethod()
{
    throw std::runtime_error("Connection error");
}

TEST(TestEmployeManager, TestConnectionErrorInvoke)
{
    MockDatabaseConnection dbConnection("dummystring");
    //EXPECT_CALL(dbConnection, connect()).WillOnce(testing::Invoke(someMethod));  //with invoking the function
    //or can use lambda function
    //EXPECT_CALL(dbConnection, connect()).WillOnce([](){throw std::runtime_error("Connection error");});
    //auto boundMethod = std::bind(&MockDatabaseConnection::someMemberMethod, &dbConnection); // someMemberMethod() without any argument
    auto boundMethod = std::bind(&MockDatabaseConnection::someMemberMethod, &dbConnection, "something"); // someMemberMethod() without any argument
    EXPECT_CALL(dbConnection, connect()).WillOnce(testing::InvokeWithoutArgs(boundMethod));  //with invoking the member function})
    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
    
}
  

int main(int argc, char**argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
