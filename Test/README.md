Unit tests are useful for regresssion testing, meaning that when you make a change, they help prevent the introduction of new bugs.

Unit tests are short, independent and fast.

Unit testing is part of functional testing, i. e. the correctness of the code is checked. Individual functions/methods are usually tested.

A unit test is divided into three parts: Arrange (test setup), Act (call the method), Assert(check the result).

An assertion is where the test condition is checked. They are fatal (ASSERT) or non-fatal(EXPECT).

There are special assertions for strings.

Assertions can be used to check if an exception was thrown, or what type of exception was thrown.

Assertions Guide
<h3>Fatal vs non-fatal:</h3>
## Assertions Guide

## Assertions Guide

### Fatal vs Non-Fatal

| Fatal                        | Non-Fatal                    | What it tests           |
|------------------------------|------------------------------|-------------------------|
| `ASSERT_TRUE(condition);`    | `EXPECT_TRUE(condition);`    | condition is true       |
| `ASSERT_FALSE(condition);`   | `EXPECT_FALSE(condition);`   | condition is not true   |

### Basic assertions

| Fatal              | Non-Fatal          | What it tests |
|--------------------|--------------------|---------------|
| `ASSERT_EQ(x, y);` | `EXPECT_EQ(x, y);` | x == y        |
| `ASSERT_NE(x, y);` | `EXPECT_NE(x, y);` | x != y        |
| `ASSERT_LT(x, y);` | `EXPECT_LT(x, y);` | x < y         |
| `ASSERT_LE(x, y);` | `EXPECT_LE(x, y);` | x <= y        |
| `ASSERT_GT(x, y);` | `EXPECT_GT(x, y);` | x > y         |
| `ASSERT_GE(x, y);` | `EXPECT_GE(x, y);` | x >= y        |

### Assertions on C strings (char*)

| Fatal                         | Non-Fatal                     | What it tests                                  |
|-------------------------------|-------------------------------|------------------------------------------------|
| `ASSERT_STREQ(x, y);`         | `EXPECT_STREQ(x, y);`         | x and y have the same content                  |
| `ASSERT_STRNE(x, y);`         | `EXPECT_STRNE(x, y);`         | x and y have different contents                |
| `ASSERT_STRCASEEQ(x, y);`     | `EXPECT_STRCASEEQ(x, y);`     | x and y have the same content, ignoring case   |
| `ASSERT_STRCASENE(x, y);`     | `EXPECT_STRCASENE(x, y);`     | x and y have different contents, ignoring case |

### Assertions on exceptions

| Fatal                                            | Non-Fatal                                        | What it tests                                                       |
|--------------------------------------------------|--------------------------------------------------|---------------------------------------------------------------------|
| `ASSERT_THROW(some_statement, exceptionType);`   | `EXPECT_THROW(some_statement, exceptionType);`   | some_statement throws an exception of the exact given type          |
| `ASSERT_ANY_THROW(some_statement);`              | `EXPECT_ANY_THROW(some_statement);`              | some_statement throws an exception of any type                      |
| `ASSERT_NO_THROW(some_statement);`               | `EXPECT_NO_THROW(some_statement);`               | some_statement throws no exception                                  |


<h2>Fixtures Summary</h2>
A fixture is useful for removing code duplication.

It's used where the setup phase and cleanup phase are similar.

It's a class where the test setup is written in the SetUp() method and the cleanup is in TearDown().

A new fixture is created for each test.



Parameterized tests can be used to generate tests that have the same body, but different input values.

When you generate a test, the expected output values can be packed together with the input values using complex data structures.

Generators can be used to generate input values for the test.

<h2>G MOck</h2>
Mocking is usually down by extending the class and mocking some of its method. Either overriding the method to do nothing or you can set the behaviour through the test. It can also be used to check if certain method was call or not.

MOCK_METHOD0(return type, method name, parameter in paranthesis"(int, int))

MOCK_METHOD0(someMethod, void()); //legacy way

Others are Fake and STUB