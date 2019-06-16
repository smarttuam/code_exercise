#include<iostream>
#include<stack>
#include"list_struct_stl.h"


void Iterative_reverse(List* list)
{
	stack<int> list_stack;
	auto  temp = list.head;

	//while (temp != nullptr)
	//{
	//	list_stack.push(temp->key);
	//	temp = temp->next;
	//	if (temp->next == nullptr) break;
	//}

	//while (!list_stack.empty())
	//{
	//	cout << "after sort: " << list_stack.top() << "\t";
	//	list_stack.pop();
	//}
}


void Test1()
{
	int arr[] = { 1,2,3,4,5,6 };
	List list_1;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		list_1.LIST_INSERT(arr[i]);
	}
	list_1.LIST_SHOW();

	Iterative_reverse(&list_1);

}

void main()
{
	Test1();
	system("pause");
}