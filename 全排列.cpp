#include <iostream>
using namespace std;


//交换函数
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


//全排列
//每个元素都作为一次首元素，将后面元素递归排列
void FullPermutation(int *arr, int count, int n)
{
	int i = 0;
	//到达最后一个元素时，只有一种情况，直接输出结果
	if (n == count - 1)
	{
		for (i = 0; i < count; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}

	//分别让每个元素放在第一位，将后面的元素进行全排列
	for (i = n; i < count; i++)
	{
		int j = 0;
		//如果后面有相同的元素，先不交换，减少选择
		for (j = n; j < count; j++)
		{
			if (arr[j] == arr[i])
				break;
		}
		if (j != i)
			continue;



		//先让后面的元素和第一位交换
		Swap(arr[i], arr[n]);

		//再将后面的元素进行全排列
		FullPermutation(arr, count, n + 1);

		//还原数组，以便下次循环再次排列
		Swap(arr[i], arr[n]);

	}
}



//测试全排列
void test()
{
	int arr[] = { 1, 2, 2, 3 };
	FullPermutation(arr, 4, 0);
}

int main(void)
{
	test();

	system("pause");
	return 0;
}