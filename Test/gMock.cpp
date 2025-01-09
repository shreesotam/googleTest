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
};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{

}

TEST(TestEmploye, TestConnection)
{
    MockDatabaseConnection dbConnection("dummystring");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
    EmployeeManager employeeManager(&dbConnection);
    
}
int main(int argc, char**argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
