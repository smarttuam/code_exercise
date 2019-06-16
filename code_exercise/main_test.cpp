#include<iostream>
#include"list_ptr.h"
using namespace std;



void main1()
{
	List List1 = List();
	List1.display();
	

	int arr[] = { 1,2,3,4,5,6 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		List1.insert(arr[i], 1);
	}

	List1.display();

	List1.delNode(4);
	List1.display();

	system("pause");
}

