#include<iostream>

using namespace std;


void print_char(char str[], int length)
{
	for (int i = 0; i <length; i++)
	{
		cout << str[i];
	}
}

void baoli(char str[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			for (int j = len - 1; j > i+2; j--)
			{
				str[j] = str[j - 2];
			}

			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
			i += 3;
		}

	}
	print_char(str,len);
}


void change_one(char str[],int i)
{
	str[i] = '%';
	str[i + 1] = '2';
	str[i + 2] = '0';
}

int get_end(char str[],int len)
{
	int pos = 0;
	for (int i = 0; i < len; i++)
	{
		cout << str[i] << "\t";
		if (str[i] == NULL) return i;
	}
	cout << endl;

	
}

void change_blank(char str[], int len)
{
	int *position = new int[len];
	int *position_change = new int[len];

	int j = 0;
	int j_change = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			position[j] = i;
			j += 1;
		}
	}

	for (int k = 0; k < j; k++)
	{
		cout << position[k] << '\t';
	}

	cout << endl;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			position_change[j_change] =2*j_change+ i;
			j_change += 1;
		}
	}
	for (int k = 0; k < j; k++)
	{
		cout << position_change[k] << '\t';
	}

	cout <<j <<endl;


	j_change -= 1;
	

	int pos = get_end(str,len);
	cout << "the position is: " << pos << endl;

	for (int i = pos; i >0; i--)
	{
		
		if (str[i] == ' ') j--;
		else
		{
			str[i + j * 2] = str[i];
		}
	}
	for (int i = len - 1; i > 0; i--)
	{
		if (i == position_change[j_change])
		{
			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
			j_change--;
		}
	}

	

	print_char(str,len);
	delete[] position;
}

void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	char str_2[length] = "I love China very much";

	baoli(str,length);
	cout << "==========================" << endl;
	change_blank(str_2, length);
}

void main()
{
	Test1();
	system("pause");
}