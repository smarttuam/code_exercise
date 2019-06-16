/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��


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


// û���ظ�������
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
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