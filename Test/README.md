Unit tests are useful for regresssion testing, meaning that when you make a change, they help prevent the introduction of new bugs.

Unit tests are short, independent and fast.

Unit testing is part of functional testing, i. e. the correctness of the code is checked. Individual functions/methods are usually tested.

A unit test is divided into three parts: Arrange (test setup), Act (call the method), Assert(check the result).

An assertion is where the test condition is checked. They are fatal (ASSERT) or non-fatal(EXPECT).

There are special assertions for strings.

Assertions can be used to check if an exception was thrown, or what type of exception was thrown.


<h3>Fatal vs non-fatal:</h3>
![alt text](image.png)


<h3>Assertions on C strings (char*):</h3>
![alt text](image-1.png)


<h3>Assertions on exceptions:</h3>
![alt text](image-2.png)