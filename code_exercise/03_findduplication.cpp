#include<iostream>
#include<stdio.h>
#include<cstdio>


using namespace std;

void change_value(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int baoli(int arr[],int len)
{
	cout <<"len of arr is: "<< len << endl;
	for (int i = 0; i < len; i++)
		for (int j = i+1; j < len; j++)
			if (arr[i] == arr[j])
				return arr[j];
}


int duplication(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		while(arr[i]!=i)
		{
			if (arr[arr[i]] == arr[i])
				return arr[i];
			else
			{
				change_value(&arr[i], &arr[arr[i]]);
			}
		}
	}
}

void main3()
{
	int array[] = { 1,2,4,3,4,6,3,4 };
	cout << "hello" << endl;
	

	int result;
	//result = baoli(array,sizeof(array)/sizeof(array[0]));
	result = duplication(array, sizeof(array) / sizeof(array[0]));

	int a = 3, b = 4;
	change_value(&a, &b);
	cout << a << '\t' << b << endl;

	cout << "the dunplication is: " << result << endl;
	
	system("pause");
	
}