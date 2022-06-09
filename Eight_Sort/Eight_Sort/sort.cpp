#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//�ȶ��ԣ� ������ȵ�ֵ A��A`  �������ʼǰ A��A`��ǰ��   �����A����A`��ǰ�� ����������㷨�ȶ�
//��ô�ж��Ƿ��ȶ���    ������㷨�����Ƿ�����Ծ����   
/*�˴�����
1.ð�����������Ƚϣ�������Ų��  //ʱ�临�Ӷ�O��n^2�� �ռ临�Ӷ�O��1��    �ȶ��ԣ��ȶ�
2.��ѡ������ÿһ���ҵ����������е���Сֵ�ʹ��������еĵ�һ��ֵ���н���   //ʱ�临�Ӷ�O��n^2��   �ռ临�Ӷ�O��1��   �ȶ��ԣ����ȶ�
3.ֱ�Ӳ����������δӴ�����������ȡֵ���������������зţ���֤�ٴ���ȫ����ֱ��������������������ֵȡ�� //ʱ�临�Ӷ�O��n^2��  �ռ临�Ӷ�O��1��  �ȶ��ԣ��ȶ�
4.ϣ������shell������С�������򣬶���ֱ�Ӳ���������Ż���ÿһ�������ݱ�ø����ȶ���ֱ������Ϊ1��ʱ�򣬳�����ȫ����  //ʱ�临�Ӷ�O��n^1.3~1.5��  �ռ临�Ӷ�O��1��    �ȶ��ԣ����ȶ�
5.��·�鲢�������Ƚ����е����鿴�������ĸ��壬Ȼ�����κϲ���ֱ�������е������ں���һ�飬��ֹͣ   //ʱ�临�Ӷ� O��nlogn��  �ռ临�Ӷȣ�nlogn��  �ȶ��ԣ��ȶ�
6.�������򣺽��������ݴ������ң����ΰ��յ�λ���ȣ�ȫ�����뵽Ͱ�ڣ��ٴ�Ͱ��ȡ��      //ʱ�临�Ӷ�O��dn�� �ռ临�Ӷ�O(dn) �ȶ��ԣ��ȶ�
7.�����������Ҫ������������Ҫ�󶥶ѣ���ȥ���ݵ���Ϊ�󶥶ѣ��ٽ����ڵ�����һ����֪�ڵ㽻����Ȼ���ظ��˲�����ֱ��ʣ��һ���ڵ�     //ʱ�临�Ӷ�O��nlogn��   �ռ临�Ӷ�O��1��  �ȶ��ԣ����ȶ�
8�����������ظ����֣��һ�׼ֵ����С�ڻ�׼ֵ��ֵȫ��������ߣ����ڻ�׼ֵ��ֵȫ�������ұߣ����������ұ�arr[left]��С��ֵ���ٴ��������ұ�arr[right]�����ֵ�Ź�ȥ���ظ��˲�����ֻ��left>=right �˳�   //���ţ���ÿһ�ν���׼ֵ�ŵ�����λ����   ʱ�临�Ӷ�O��nlogn�� �ռ临�Ӷ�O��logn��  �ȶ��ԣ����ȶ�
*/
/*
�ĸ��ȶ���ð�� ֱ�Ӳ�������  ��·�鲢���� ��������
�ĸ����ȶ�����ѡ������ ϣ������
*/

//ʱ�临�Ӷ�O��n^2�� �ռ临�Ӷ�O��1��    �ȶ��ԣ��ȶ�
//ȱ�㣺ʱ�临�Ӷȴ�   �ŵ㣺ʵ�ּ�  �ȶ�
//20:25�Ͽ�

void BubbleSort(int* arr, int len)
{
	//assert

	for (int i = 0; i < len - 1; i++)//��������
	{
		for (int j = 0; j < len - 1 - i; j++)//����ÿһ�ֱȽϵĴ���
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void Show(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ʱ�临�Ӷ�O��n^2��   �ռ临�Ӷ�O��1��   �ȶ��ԣ����ȶ�
void SelectSort(int* arr, int len)
{
	//assert
	int minindex;//������Сֵ���±꣬��������Сֵ����

	for (int i = 0; i < len - 1; i++)//���Ʋ���
	{
		minindex = i;
		for (int j = i + 1; j < len; j++)//�ҵ���һ�ִ��������е���Сֵ���±�
		{
			if (arr[j] < arr[minindex])
			{
				minindex = j;
			}
		}
		//�ڶ���forѭ��ִ�н���  ����ȷ����������������Сֵ���±� ������ minindex��
		//arr[minindex] arr[i]
		if (minindex != i)  //
		{
			int tmp = arr[minindex];
			arr[minindex] = arr[i];
			arr[i] = tmp;
		}

	}

}

void Swap1(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap2(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void Swap3(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void Reverse(int* arr, int len)
{
	int i = 0;
	int j = len - 1;

	while (i <= j)
	{
		Swap1(&arr[i], &arr[j]);
		i++;
		j--;
	}
}

int count = 0;
//ʱ�临�Ӷ�O��n^2��  �ռ临�Ӷ�O��1��  �ȶ��ԣ��ȶ�
void InsertSort(int arr[], int len)
{
	int tmp = 0;
	int j;//j���������������������Ҫ��tmp�Ƚϵ�ֵ
	for (int i = 1; i <= len - 1; i++)//i�������δ���������д˴���Ҫ�����ֵ�����ȶ���
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0; j--) //j���������������������Ҫ��tmp�Ƚϵ�ֵ   ���κ�tmp�Ƚ�
		{
			if (arr[j] > tmp)//���arr[j]��ֵ����tmp   ����Ų��һ������
			{
				arr[j + 1] = arr[j];
				count++;
			}
			else//���arr[j]��ֵС�ڵ���tmp   break  ��Ϊ��ʱarr[j+1]����tmpӦ�÷ŵ�λ��
			{
				break;
			}
		}
		//��ʱ�����������Ѿ��Ƚ����    ��ʱ��j+1���λ��  ��tmp�Ž�ȥ����
		arr[j + 1] = tmp;
	}

}

//��д д���������  9������д
void Shell(int arr[], int len, int gap)
{
	int tmp = 0;
	int j;//j���������������������ҪҪtmp�Ƚϵ�ֵ
	for (int i = gap; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (arr[j] > tmp)
			{
				arr[j + gap] = arr[j];
				count++;
			}
			else
			{
				break;
			}
		}
		//��ʱ �ڲ�for�˳���������tmp���յ�λ���Ѿ��ҵ�
		arr[j + gap] = tmp;
	}
}


//ʱ�临�Ӷ�O��n^1.3~1.5��(����������ȡֵ�й�)  �ռ临�Ӷ�O��1��    �ȶ��ԣ����ȶ�
void ShellSort(int* arr, int len)
{
	int brr[] = { 13,11,7,5,3,1 };
	int len_brr = sizeof(brr) / sizeof(brr[0]);//3
	for (int i = 0; i < len_brr; i++)
	{
		Shell(arr, len, brr[i]);
	}
}



//int main()
//{
//	int arr[] = {2,1,3,9,8,7};
//	//BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
//	SelectSort(arr, sizeof(arr)/sizeof(arr[0]));
//	Show(arr, sizeof(arr)/sizeof(arr[0]));
//
//	int brr[] = {1,2,3,4,5,6,7,8,9,10,11};
//	Reverse(brr, sizeof(brr)/sizeof(brr[0]));
//	Show(brr, sizeof(brr)/sizeof(brr[0]));
//	/*int a = 10;
//	int b = 20;
//
//	Swap2(&a, &b);
//	printf("%d %d\n", a, b);*/
//	return 0;
//}


//���ݴ��ݽ�����gap���м����ϲ�
static void Merge(int* arr, int len, int gap)
{
	//��Ϊ���ݱ���ռ䲻����  ����һ��������һ��������ȳ��Ķ�̬�ڴ�
	int* brr = (int*)malloc(sizeof(int) * len);
	assert(brr != NULL);


	int L1 = 0;
	int H1 = L1 + gap - 1;
	int L2 = H1 + 1;
	int H2 = L2 + gap - 1 < len ? L2 + gap - 1 : len - 1;
	int i = 0;//i����brr���±�

	while (L2 < len)
	{
		while (L1 <= H1 && L2 <= H2)
		{
			if (arr[L1] <= arr[L2])
			{
				brr[i++] = arr[L1++];
			}
			else
			{
				brr[i++] = arr[L2++];
			}
		}

		while (L1 <= H1)//�������黹�����ݣ�Ų����
		{
			brr[i++] = arr[L1++];
		}
		while (L2 <= H2)//����ұ��黹�����ݣ�Ų����
		{
			brr[i++] = arr[L2++];
		}

		L1 = H2 + 1;
		H1 = L1 + gap - 1;
		L2 = H1 + 1;
		H2 = L2 + gap - 1 < len ? L2 + gap - 1 : len - 1;
	}
	while (L1 < len)//�������黹�����ݣ�Ų����
	{
		brr[i++] = arr[L1++];
	}
	//��ʱ�������������ȫ����brr ��

	//���µ���arr�Ｔ��
	for (int i = 0; i < len; i++)
	{
		arr[i] = brr[i];
	}
	free(brr);

}

//ʱ�临�Ӷ� O��nlogn��  �ռ临�Ӷȣ�nlogn��  �ȶ��ԣ��ȶ�
void MergeSort(int* arr, int len)
{
	for (int i = 1; i < len; i *= 2)//i�������ϲ��ļ�
	{
		Merge(arr, len, i);//O(n)
	}

}

static int Get_Figure_Max(int arr[], int len)
{
	int max = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	int count = 0;
	while (max != 0)
	{
		count++;
		max /= 10;
	}
	return count;
}
//��ȥֵn��index���λ��ֵ�Ƕ���   123,3 ->0   123,1->2   69,0->9
int Get_Num(int n, int index)
{
	for (int i = 0; i < index; i++)
	{
		n = n / 10;
	}

	return n % 10;
}
static void Radix(int* arr, int len, int index)
{
	int brr[10][20];//�����0~9��Ͱ��ÿ��Ͱ�ڿռ�20��
	int crr[10] = { 0 };//��crr[i]���ֵ�������Ӧ��i��Ͱ���ж�����Чֵ

	for (int i = 0; i < len; i++)
	{
		int tmp = Get_Num(arr[i], index);//tmp������ֵarr[i]Ӧ�÷ŵ�Ͱ��
		brr[tmp][crr[tmp]++] = arr[i];
	}

	int k = 0;
	for (int i = 0; i <= 9; i++)//Ͱ��
	{
		for (int j = 0; j < crr[i]; j++)
		{
			arr[k++] = brr[i][j];
		}
	}

}

//ʱ�临�Ӷ�O��dn�� �ռ临�Ӷ�O(dn) �ȶ��ԣ��ȶ�
void Radix_Sort(int arr[], int len)
{
	int count = Get_Figure_Max(arr, len);

	for (int i = 0; i < count; i++)
	{
		Radix(arr, len, i);//i=0�Ը�λ����һ��  i=1��ʮλ����һ��
	}
}


//�������������һ�δ󶥶�   ʱ�临�Ӷ�O��log2n��
void AdjustHeap(int arr[], int start, int end)
{
	int tmp = arr[start];

	int i = start;
	int j = 2 * i + 1;

	for (j; j <= end; j = 2 * i + 1)
	{
		if (j<end && arr[j + 1]>arr[j])//����Һ��Ӵ��ڣ������Һ��ӵ�ֵ�������ӵ�ֵ
		{
			j++;
		}

		if (arr[j] > tmp)
		{
			arr[i] = arr[j];
			i = j;
		}
		else
		{
			break;
		}
	}

	arr[i] = tmp;
}

//ʱ�临�Ӷ�O��nlogn��   �ռ临�Ӷ�O��1��  �ȶ��ԣ����ȶ�
void HeapSort(int* arr, int len)
{
	//���һ��Ҷ�ӽ����len-1  �������Ƹ�  �õ����һ����Ҷ�ӽڵ���±�Ϊ((len-1)-1)/2
	//��ʼ״̬�£������󶥶���Ҫ�������һ����Ҷ�ӽڵ㿪ʼ���Ӻ���ǰ���������ϵ���
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustHeap(arr, i, len - 1);//�������������Ҳ�������ֱ��������±�λ�ü��ɣ�����ʽ��Ԯ��
	}
	//����ʱforѭ��  ִ�н�����   ��ʼ״̬������ĵ����󶥶Ѹ㶨��


	for (int i = 0; i < len - 1; i++)//���� 
	{
		int tmp = arr[0];//�������Ǹ��ڵ�arr[0] ������arr[i]
		arr[0] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;

		AdjustHeap(arr, 0, (len - 1 - i) - 1);//  (len-1-i)-1
	}


}

int Partition(int* arr, int left, int right)
{
	int tmp = arr[left];

	while (left < right)
	{
		while (left<right && arr[right]>tmp)
			right--;
		if (left == right)
		{
			break;
		}
		arr[left] = arr[right];


		while (left < right && arr[left] <= tmp)
			left++;
		if (left == right)
		{
			break;
		}
		arr[right] = arr[left];

	}

	arr[left] = tmp;//arr[left] == arr[right]
	return left;//return right;

}
void Quick(int* arr, int left, int right)
{
	if (left < right)
	{
		int index = Partition(arr, left, right);

		if (left < index - 1)//��֤��׼ֵ�������������ֵ
		{
			Quick(arr, left, index - 1);
		}

		if (index + 1 < right)//��֤��׼ֵ�ұ�����������ֵ
		{
			Quick(arr, index + 1, right);
		}


	}
}



//���ţ����ۺ���������������ģ�����Խ��Խ������ÿһ�ν���׼ֵ�ŵ�����λ����   ʱ�临�Ӷ�O��nlogn�� �ռ临�Ӷ�O��logn��  �ȶ��ԣ����ȶ�
void QuickSort(int* arr, int len)
{
	Quick(arr, 0, len - 1);
}
int main()
{
	int arr[] = { 9,7,10,2,5,6,12,99,55,3,2,6,5,21 };
	//BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr)/sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr)/sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr)/sizeof(arr[0]));
	//MergeSort(arr, sizeof(arr)/sizeof(arr[0]));
	//Radix_Sort(arr, sizeof(arr)/sizeof(arr[0]));
	//HeapSort(arr, sizeof(arr)/sizeof(arr[0]));
	QuickSort(arr, sizeof(arr) / sizeof(arr[0]));
	Show(arr, sizeof(arr) / sizeof(arr[0]));
	printf("swap:%d\n", count);

	return 0;
}