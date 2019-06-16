#include<iostream>
#include"list_ptr.h"

using namespace std;

List::List()
{
	First_Node = new struct ListNode;
	First_Node->value = NULL;
	First_Node->next = nullptr;

}

List::~List()
{
	ListNode* delete_ptr;
	ListNode* delete_next;

	delete_ptr = First_Node;
	while (delete_ptr != nullptr)
	{
		delete_next = delete_ptr->next;

		cout << "delete node value is: " << delete_ptr->value << endl;
		delete delete_ptr;
		delete_ptr = delete_next;
		
	}
}


bool List::empty() const
{
	if (First_Node->next == nullptr)
	{
		return false;
	}
	else return true;
}

void List::insert(NodeType item, int pos)
{
	ListNode* pre =First_Node;

	ListNode* newNode = new struct ListNode;
	newNode->value = item;

    //找到前一节点
	for (int i = 0; i < pos-1; i++)
	{
		pre = First_Node->next;
	}

	ListNode* temp = pre->next;
	pre->next = newNode;
	newNode->next = temp;
}


void List::delNode(int pos)
{
	ListNode* temp;
	ListNode* pre = First_Node;

	for (int i = 0; i < pos - 1; i++)
	{
		pre = pre->next;
	}

	temp = pre->next;
	pre->next = pre->next->next;
	delete temp;

}

int List::find(NodeType item)
{
	ListNode* temp = First_Node;
	int count = 0;
	while (temp->value != item)
	{
		temp = temp->next;
		count += 1;
	}
	return count;
}

void List::display() const
{
	ListNode* temp = First_Node->next;
	
	if (First_Node->next == nullptr)
		cout << "the list is empty,please add item" << endl;

	else
	{
		while (temp->value != NULL)
		{
			cout << temp->value << "\t";
			if (temp->next == NULL) break;
			temp = temp->next;
		}
		cout << endl;

	}
}