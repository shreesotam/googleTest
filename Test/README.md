Unit tests are useful for regresssion testing, meaning that when you make a change, they help prevent the introduction of new bugs.

Unit tests are short, independent and fast.

Unit testing is part of functional testing, i. e. the correctness of the code is checked. Individual functions/methods are usually tested.

A unit test is divided into three parts: Arrange (test setup), Act (call the method), Assert(check the result).

An assertion is where the test condition is checked. They are fatal (ASSERT) or non-fatal(EXPECT).

There are special assertions for strings.

Assertions can be used to check if an exception was thrown, or what type of exception was thrown.


<h3>Fatal vs non-fatal:</h3>
![image](https://github.com/user-attachments/assets/af7c54ef-deab-44ef-b7be-dab7700046b2)



<h3>Assertions on C strings (char*):</h3>
![image](https://github.com/user-attachments/assets/c473378f-e162-4a84-b358-ba1ef938f927)



<h3>Assertions on exceptions:</h3>
![image](https://github.com/user-attachments/assets/8aa31690-3617-4b7a-be7c-4607961edf3e)
