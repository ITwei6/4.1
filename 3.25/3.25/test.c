#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(int* a, int n, int parent)//实现的前提是左右子树都是堆
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中比较大的孩子，假设child为左边，假设左边孩子比较xiao
		if (child + 1 < n && a[child] > a[child + 1])//不过这里存在越界的风险，不能保证右边的孩子一定存在
		{//右边的孩子要存在的话也需要小于n才可以所以我们再加上去
			++child;//让右边的孩子成为比较大的child
		}
		//然后让根（父亲）与较大儿子比较，这里是大堆，父亲要大于儿子的
		if (a[parent] >a[child])
		{
			Swap(&a[parent], &a[child]);
			//交互完后，让parent跳到儿子位置上去，儿子继续往下找
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}


	}
}
void AdjustUp(int* a, int child)//向上调整的前提就是child之前的数是堆
{

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int* a, int n)//堆排序
{
	//for (int i = 1; i <10; i++)//模拟插入建堆，时间复杂度为N*logN
	//{
	//	AdjustUp(a, i);
	//}
	//通常建堆是使用向下调整建堆--怎么使用向下调整建堆呢？
	//从最后一个非空子叶开始向下调整，调整完后，再调整它的兄弟，再调整它们的父辈
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i); 
	}
	//建堆后，就可以进行排序，利用向下调整删除的思想，排序出升序或降序
	//升序--建大堆
	//将堆顶数据与堆尾部数据交换，然后不要删除最后这个数据，让剩下的n-1个结点继续变成堆，然后继续交换
	int end = n - 1;
	for (int i = 0; i < n; i++)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
//void TOPK(int* a, int n, int k)
//{
//	
//	//首先建小堆
//	//利用向下调整建堆
//	for (int i = (k - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, k, i);//先从a中读取k个数建一个小堆
//	}
//	//建堆后，让数组每个元素与堆顶元素比较，当大于堆顶数据时，就代替堆顶数据入堆
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] > a[0])
//		{
//			a[0] = a[i];
//			AdjustDown(a, k, 0);
//		}
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//int main()
//{
//	int a[10] = { 9,5,2,3,6,7,8,4,1,0 };
//	HeapSort(a, 10);
//}
//	TOPK(a, 10, 5);
//	//直接使用数组进行模拟建堆
//	//将数组第一个元素当作堆顶元素，而后面的元素进行向上调整操作
//	/*HeapSort(a, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//	return 0;
//}
//TOP_K问题 选出前k个数，最大数或者最小数
// n个数中选出前k个最大数，建小堆--选出多少数就建多大的堆,，然后遍历数组，当元素大于堆顶的就代替进去。
// n个数中选出前k个最小数，建大堆


//增加一个度为2的就会增加一个度为0的，所以度为0的个数永远比度为2的个数要多一
//#include <stdio.h>
//struct BTree
//{
//	struct BTree* left;
//	struct BTree* right;
//	char data;
//};
//struct BTree* CreatBTree(char* a, int* pi)
//{
//	if (a[*pi] == '#')
//	{
//		(*pi)++;
//		return NULL;
//	}
//
//	//如果不是 #就给数据创建结点
//	struct BTree* root = (struct BTree*)malloc(sizeof(struct BTree));
//	root->data = a[*pi];
//	(*pi)++;
//	root->left = CreatBTree(a, pi);//为左孩子创建结点
//	root->right = CreatBTree(a, pi);//为右孩子孩子创建结点
//
//	return root;
//
//
//}
//void Inorder(struct BTree* ret)
//{
//	if (ret==NULL)
//	{
//		return;
//	}
//	Inorder(ret->left);
//	printf("%c ", ret->data);
//	Inorder(ret->right);
//}
//int main()
//{
//	//首先要按照前序遍历形式创建一个二叉树
//	char a[100];
//	scanf("%s", a);
//	int i = 0;
//	struct BTree* ret = CreatBTree(a, &i);
//	Inorder(ret);
//	return 0;
//}
//#include <time.h>
//#include <stdlib.h>
//void TOPK(char*top,int k)
//{
//	int* topk = (int*)malloc(sizeof(int) * k);
//	//从文件里读取k个数进行建堆
//	FILE* fp = fopen("text", "r");
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fp, "%d", &topk[i]);
//	}
//	//建堆
//	for (int i = (k - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(topk, k, i);
//	}
//	//让文件里每一个数据都和堆顶数据比较，如果比堆顶数据大就代替堆顶数据入堆
//	
//	int val;
//	int ret = fscanf(fp, "%d", &val);
//	
//	while (ret!=EOF)
//	{
//		if (ret > topk[0])
//		{
//			topk[0] = ret;
//			AdjustDown(topk, k, 0);
//		}
//		ret = fscanf(fp, "%d", &val);
//	}
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", topk[i]);
//	}
//	
//}
//void CreatData()
//{
//	int n = 10000;
//	int* a = (int*)malloc(sizeof(int) * n);
//	srand(time(0));
//	FILE* pf = fopen("text", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	for (size_t i = 0; i < n; ++i)
//	{
//		int x = rand() % 1000000;
//		fprintf(pf, "%d\n", x);
//	}
//	
//}
//int main()
//{/*
//	CreatData();*/
//	TOPK("text",10);
//	return 0;
//}
#include <time.h>
void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆--用a中前k个元素建堆
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, k, i);
	}
	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	for (int i = k; i < n; i++)
	{
		if (a[i] > a[0])
		{
			a[0] = a[i];
			AdjustDown(a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
int main()
{
	TestTopk();
	return 0;
}