#include<iostream>
#include<stack>

using namespace std;

typedef int StackType;

const StackType StackMax = 10;


struct stack_my {

	int StackBase[StackMax] = { 0 };
	int S_top = -1;


	bool Stack_Empty()
	{
		if (S_top == -1)
			return true;
		else
			return false;
	}

	void push(StackType x)
	{
		if (S_top != StackMax - 1)
		{
			++S_top;
			StackBase[S_top] = x;
		}
	}

	int pop()
	{
		if (!Stack_Empty()) {
			--S_top;
			return StackBase[S_top + 1];
		}
	}
};

int main()
{
	stack<int> Stack;
	Stack.push(1);

	int a = Stack.top();

	cout << a << endl;

	system("pause");
	return 0;
}