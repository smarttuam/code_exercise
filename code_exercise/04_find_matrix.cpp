#include<iostream>


using namespace std;

int baoli(int arr[][4], int target,int wide,int hight)
{
	for(int i=0;i<wide;i++)
		for (int j = 0; j < hight; j++)
		{
			if (arr[i][j] == target)
			{
				cout << arr[i][j] << endl;
				return true;
			}
		}
	return false;

}

int sort_find(int arr[][4], int target, int wide, int hight)
{
	for (int i = wide; i>0; --i)
	{
		for (int j = hight; j > 0; --j)
		{
			if (arr[i][j] == target)
			{
				cout << arr[i][j] << endl;
				return true;
			}
			else if(arr[i][j] < target)
				continue;
		}
	}
}


void test()
{
	int array[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int target = 7;
	
	int result = baoli(array, target, sizeof(array) / sizeof(array[0]), sizeof(array[0]) / sizeof(array[0][0]));
	
	if (result)
		printf("Pass.\n");
	else
		printf("Faild.\n");
	//int result = find_matrix(array);

}

void main04()
{
	test();
	system("pause");
}