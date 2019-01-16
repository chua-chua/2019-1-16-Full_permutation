#include <iostream>
using namespace std;


//��������
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


//ȫ����
//ÿ��Ԫ�ض���Ϊһ����Ԫ�أ�������Ԫ�صݹ�����
void FullPermutation(int *arr, int count, int n)
{
	int i = 0;
	//�������һ��Ԫ��ʱ��ֻ��һ�������ֱ��������
	if (n == count - 1)
	{
		for (i = 0; i < count; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}

	//�ֱ���ÿ��Ԫ�ط��ڵ�һλ���������Ԫ�ؽ���ȫ����
	for (i = n; i < count; i++)
	{
		int j = 0;
		//�����������ͬ��Ԫ�أ��Ȳ�����������ѡ��
		for (j = n; j < count; j++)
		{
			if (arr[j] == arr[i])
				break;
		}
		if (j != i)
			continue;



		//���ú����Ԫ�غ͵�һλ����
		Swap(arr[i], arr[n]);

		//�ٽ������Ԫ�ؽ���ȫ����
		FullPermutation(arr, count, n + 1);

		//��ԭ���飬�Ա��´�ѭ���ٴ�����
		Swap(arr[i], arr[n]);

	}
}



//����ȫ����
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