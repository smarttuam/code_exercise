/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。


#include<iostream>
#include<cstdio>



bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;

	for (int i = 0; i < length; ++i)
	{
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}

	for (int i = 0; i < length;++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}
	return false;
}

void test(const char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
	printf("%s begins: ",testName);

	int duplication;
	bool validInput = duplicate(numbers, lengthNumbers, &duplication);

	if (validArgument == validInput)
	{
		if (validArgument)
		{
			if (contains(expected, expectedExpected, duplication))
				printf("Passed.\n");
			else
				printf("Failed.\n");
		}

		else
			printf("Passed.\n");
	}

	else printf("Faild.\n");
	
}





void test1()
{
	int numbers[]= { 2, 1, 3, 1, 4 };
	int duplication[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplication, sizeof(duplication) / sizeof(int), true);
}

void test2()
{
	int numbers[] = { 2,4,1,4,3 };
	int duplication[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplication, sizeof(duplication) / sizeof(int), true);
}

void test3()
{
	int numbers[] = { 2,4,2,4,3 };
	int duplication[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplication, sizeof(duplication) / sizeof(int), true);
}


// 没有重复的数字
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test5()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


void main03_()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	system("pause");
}