#pragma once
#include<iostream>

#ifndef LIST_PTR
#define LIST_PTR

typedef int NodeType;

class List
{
private:
	struct ListNode {
		NodeType value;
		ListNode* next;
	};
	

public:
	ListNode* First_Node;;


	List();
	~List();

	bool empty() const;

	void insert(NodeType item, int pos);
	void delNode(int pos);

	int find(NodeType item);
	
	void display() const;

};

#endif LIST_PTR