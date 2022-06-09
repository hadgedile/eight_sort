#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//稳定性： 两个相等的值 A和A`  如果排序开始前 A在A`的前面   排序后A还在A`的前面 则这个排序算法稳定
//怎么判断是否稳定？    看这个算法里面是否有跳跃交换   
/*八大排序：
1.冒泡排序：两两比较，大的向后挪动  //时间复杂度O（n^2） 空间复杂度O（1）    稳定性：稳定
2.简单选择排序：每一轮找到待排序序列的最小值和待排序序列的第一个值进行交换   //时间复杂度O（n^2）   空间复杂度O（1）   稳定性：不稳定
3.直接插入排序：依次从待排序序列中取值，向已排序排序中放，保证再次完全有序，直到将待排序序列中所以值取完 //时间复杂度O（n^2）  空间复杂度O（1）  稳定性：稳定
4.希尔排序：shell排序，缩小增量排序，对于直接插入排序的优化，每一次让数据变得更加稳定，直到增量为1的时候，彻底完全有序  //时间复杂度O（n^1.3~1.5）  空间复杂度O（1）    稳定性：不稳定
5.二路归并排序：首先将所有的数组看做单独的个体，然后依次合并，直到将所有的数据融合在一组，则停止   //时间复杂度 O（nlogn）  空间复杂度（nlogn）  稳定性：稳定
6.基数排序：将所有数据从左向右，依次按照低位优先，全部进入到桶内，再从桶内取出      //时间复杂度O（dn） 空间复杂度O(dn) 稳定性：稳定
7.堆排序，如果需要升序排序，则需要大顶堆，则将去数据调整为大顶堆，再将根节点和最后一个已知节点交换，然后重复此操作，直到剩余一个节点     //时间复杂度O（nlogn）   空间复杂度O（1）  稳定性：不稳定
8：快速排序，重复划分，找基准值，将小于基准值的值全部放在左边，大于基准值的值全部放在右边：从右向左找比arr[left]更小的值，再从左向右找比arr[right]更大的值放过去，重复此操作，只能left>=right 退出   //快排，是每一次将基准值放到合适位置上   时间复杂度O（nlogn） 空间复杂度O（logn）  稳定性：不稳定
*/
/*
四个稳定：冒泡 直接插入排序  二路归并排序 基数排序
四个不稳定：简单选择排序 希尔排序
*/

//时间复杂度O（n^2） 空间复杂度O（1）    稳定性：稳定
//缺点：时间复杂度大   优点：实现简单  稳定
//20:25上课

void BubbleSort(int* arr, int len)
{
	//assert

	for (int i = 0; i < len - 1; i++)//控制轮数
	{
		for (int j = 0; j < len - 1 - i; j++)//控制每一轮比较的次数
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

//时间复杂度O（n^2）   空间复杂度O（1）   稳定性：不稳定
void SelectSort(int* arr, int len)
{
	//assert
	int minindex;//保存最小值的下标，而不是最小值本身

	for (int i = 0; i < len - 1; i++)//控制层数
	{
		minindex = i;
		for (int j = i + 1; j < len; j++)//找到这一轮待排序序列的最小值的下标
		{
			if (arr[j] < arr[minindex])
			{
				minindex = j;
			}
		}
		//第二层for循环执行结束  可以确定待排序序列中最小值的下标 保存在 minindex里
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
//时间复杂度O（n^2）  空间复杂度O（1）  稳定性：稳定
void InsertSort(int arr[], int len)
{
	int tmp = 0;
	int j;//j代表的是已排序序列中需要和tmp比较的值
	for (int i = 1; i <= len - 1; i++)//i代表的是未排序序列中此次需要插入的值（变稳定）
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0; j--) //j代表的是已排序序列中需要和tmp比较的值   依次和tmp比较
		{
			if (arr[j] > tmp)//如果arr[j]的值大于tmp   向右挪动一个格子
			{
				arr[j + 1] = arr[j];
				count++;
			}
			else//如果arr[j]的值小于等于tmp   break  因为此时arr[j+1]就是tmp应该放的位置
			{
				break;
			}
		}
		//此时已排序排序已经比较完毕    此时的j+1这个位置  将tmp放进去即可
		arr[j + 1] = tmp;
	}

}

//先写 写完可以讨论  9点我来写
void Shell(int arr[], int len, int gap)
{
	int tmp = 0;
	int j;//j代表的是已排序序列中需要要tmp比较的值
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
		//此时 内层for退出，代表着tmp最终的位置已经找到
		arr[j + gap] = tmp;
	}
}


//时间复杂度O（n^1.3~1.5）(和增量数组取值有关)  空间复杂度O（1）    稳定性：不稳定
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


//根据传递进来的gap进行几几合并
static void Merge(int* arr, int len, int gap)
{
	//因为数据本身空间不够用  所以一进来申请一个和数组等长的动态内存
	int* brr = (int*)malloc(sizeof(int) * len);
	assert(brr != NULL);


	int L1 = 0;
	int H1 = L1 + gap - 1;
	int L2 = H1 + 1;
	int H2 = L2 + gap - 1 < len ? L2 + gap - 1 : len - 1;
	int i = 0;//i代表brr的下标

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

		while (L1 <= H1)//如果左边组还有数据，挪下来
		{
			brr[i++] = arr[L1++];
		}
		while (L2 <= H2)//如果右边组还有数据，挪下来
		{
			brr[i++] = arr[L2++];
		}

		L1 = H2 + 1;
		H1 = L1 + gap - 1;
		L2 = H1 + 1;
		H2 = L2 + gap - 1 < len ? L2 + gap - 1 : len - 1;
	}
	while (L1 < len)//如果左边组还有数据，挪下来
	{
		brr[i++] = arr[L1++];
	}
	//此时，调整后的数据全部在brr 内

	//重新导入arr里即可
	for (int i = 0; i < len; i++)
	{
		arr[i] = brr[i];
	}
	free(brr);

}

//时间复杂度 O（nlogn）  空间复杂度（nlogn）  稳定性：稳定
void MergeSort(int* arr, int len)
{
	for (int i = 1; i < len; i *= 2)//i代表几几合并的几
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
//过去值n的index这个位的值是多少   123,3 ->0   123,1->2   69,0->9
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
	int brr[10][20];//申请的0~9号桶，每个桶内空间20个
	int crr[10] = { 0 };//用crr[i]里的值来代表对应的i号桶内有多少有效值

	for (int i = 0; i < len; i++)
	{
		int tmp = Get_Num(arr[i], index);//tmp保存着值arr[i]应该放的桶号
		brr[tmp][crr[tmp]++] = arr[i];
	}

	int k = 0;
	for (int i = 0; i <= 9; i++)//桶号
	{
		for (int j = 0; j < crr[i]; j++)
		{
			arr[k++] = brr[i][j];
		}
	}

}

//时间复杂度O（dn） 空间复杂度O(dn) 稳定性：稳定
void Radix_Sort(int arr[], int len)
{
	int count = Get_Figure_Max(arr, len);

	for (int i = 0; i < count; i++)
	{
		Radix(arr, len, i);//i=0以个位排序一次  i=1以十位排序一次
	}
}


//这个函数：调整一次大顶堆   时间复杂度O（log2n）
void AdjustHeap(int arr[], int start, int end)
{
	int tmp = arr[start];

	int i = start;
	int j = 2 * i + 1;

	for (j; j <= end; j = 2 * i + 1)
	{
		if (j<end && arr[j + 1]>arr[j])//如果右孩子存在，并且右孩子的值大于左孩子的值
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

//时间复杂度O（nlogn）   空间复杂度O（1）  稳定性：不稳定
void HeapSort(int* arr, int len)
{
	//最后一个叶子结点是len-1  所以子推父  得到最后一个非叶子节点的下标为((len-1)-1)/2
	//初始状态下，调整大顶堆需要，从最后一个非叶子节点开始，从后向前，从下向上调整
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustHeap(arr, i, len - 1);//第三个参数，找不到规则，直接填最大下标位置即可（饱和式救援）
	}
	//当此时for循环  执行结束，   初始状态下最繁琐的调整大顶堆搞定了


	for (int i = 0; i < len - 1; i++)//轮数 
	{
		int tmp = arr[0];//交换个是根节点arr[0] 而不是arr[i]
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

		if (left < index - 1)//保证基准值左边至少有两个值
		{
			Quick(arr, left, index - 1);
		}

		if (index + 1 < right)//保证基准值右边至少有两个值
		{
			Quick(arr, index + 1, right);
		}


	}
}



//快排，（综合情况来看，是最快的，数组越乱越有序）是每一次将基准值放到合适位置上   时间复杂度O（nlogn） 空间复杂度O（logn）  稳定性：不稳定
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