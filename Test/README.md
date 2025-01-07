Unit tests are useful for regresssion testing, meaning that when you make a change, they help prevent the introduction of new bugs.

Unit tests are short, independent and fast.

Unit testing is part of functional testing, i. e. the correctness of the code is checked. Individual functions/methods are usually tested.

A unit test is divided into three parts: Arrange (test setup), Act (call the method), Assert(check the result).

An assertion is where the test condition is checked. They are fatal (ASSERT) or non-fatal(EXPECT).

There are special assertions for strings.

Assertions can be used to check if an exception was thrown, or what type of exception was thrown.

Assertions Guide
<h3>Fatal vs non-fatal:</h3>
===========================================================================================|
|Fatal	                   |  	Non-Fatal	            | 	What it tests                  |
|==========================|============================|==================================|	
|ASSERT_TRUE(condition);   |  EXPECT_TRUE(condition);	|	condition is true		       |
|--------------------------|----------------------------|----------------------------------|
|ASSERT_FALSE(condition);  |  EXPECT_FALSE(condition);	|condition is not true			   |
|===========================================================================================

Basic assertions:|
==============================================================|
Fatal			 |  	Non-Fatal		|   What it tests     |
=================|======================|=====================|		
ASSERT_EQ(x, y); |  EXPECT_EQ(x, y);	|  x == y             |
-----------------|----------------------|---------------------|
ASSERT_NE(x, y); |  EXPECT_NE(x, y);	|  x != y             |
-----------------|----------------------|---------------------|
ASSERT_LT(x, y); |  EXPECT_LT(x, y);	|  x < y              |
-----------------|----------------------|---------------------|
ASSERT_LE(x, y); |  EXPECT_LE(x, y);	|  x <= y             |
-----------------|----------------------|---------------------|
ASSERT_GT(x, y); |  EXPECT_GT(x, y);	|  x > y              |
-----------------|----------------------|---------------------|
ASSERT_GE(x, y); |  EXPECT_GE(x, y);	|  x >= y             |
==============================================================|  

Assertions on C strings (char*):
================================================================================================|
Fatal					| 	Non-Fatal				| What it tests								|
========================|===========================|===========================================|
ASSERT_STREQ(x, y);		| EXPECT_STREQ(x, y);		| x and y have the same content             |
------------------------|---------------------------|-------------------------------------------|
ASSERT_STRNE(x, y);		| EXPECT_STRNE(x, y);		| x and y have different contents           |
------------------------|---------------------------|-------------------------------------------|
ASSERT_STRCASEEQ(x, y);	| EXPECT_STRCASEEQ(x, y);	| x and y have the same content, ignoring ca|
------------------------|---------------------------|-------------------------------------------|
ASSERT_STRCASENE(x, y);	| EXPECT_STRCASENE(x, y);	| x and y have different contents, ignoring |
=================================================================================================


Assertions on exceptions:
=================================================================================================================================================================|
Fatal											|	Non-Fatal									|	What it tests											     |
================================================|================================================|===============================================================|
ASSERT_THROW(some_statement, exceptionType);    |EXPECT_THROW(some_statement, exceptionType);    |some_statement throws an exception of the exact given type     |
------------------------------------------------|------------------------------------------------|---------------------------------------------------------------|
ASSERT_ANY_THROW(some_statement);				|EXPECT_ANY_THROW(some_statement);			    |some_statement throws an exception of any type                  |
=================================================================================================================================================================|
