#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(int* a, int n, int parent)//ʵ�ֵ�ǰ���������������Ƕ�
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ����бȽϴ�ĺ��ӣ�����childΪ��ߣ�������ߺ��ӱȽ�xiao
		if (child + 1 < n && a[child] > a[child + 1])//�����������Խ��ķ��գ����ܱ�֤�ұߵĺ���һ������
		{//�ұߵĺ���Ҫ���ڵĻ�Ҳ��ҪС��n�ſ������������ټ���ȥ
			++child;//���ұߵĺ��ӳ�Ϊ�Ƚϴ��child
		}
		//Ȼ���ø������ף���ϴ���ӱȽϣ������Ǵ�ѣ�����Ҫ���ڶ��ӵ�
		if (a[parent] >a[child])
		{
			Swap(&a[parent], &a[child]);
			//���������parent��������λ����ȥ�����Ӽ���������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}


	}
}
void AdjustUp(int* a, int child)//���ϵ�����ǰ�����child֮ǰ�����Ƕ�
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
void HeapSort(int* a, int n)//������
{
	//for (int i = 1; i <10; i++)//ģ����뽨�ѣ�ʱ�临�Ӷ�ΪN*logN
	//{
	//	AdjustUp(a, i);
	//}
	//ͨ��������ʹ�����µ�������--��ôʹ�����µ��������أ�
	//�����һ���ǿ���Ҷ��ʼ���µ�������������ٵ��������ֵܣ��ٵ������ǵĸ���
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i); 
	}
	//���Ѻ󣬾Ϳ��Խ��������������µ���ɾ����˼�룬������������
	//����--�����
	//���Ѷ��������β�����ݽ�����Ȼ��Ҫɾ�����������ݣ���ʣ�µ�n-1����������ɶѣ�Ȼ���������
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
//	//���Ƚ�С��
//	//�������µ�������
//	for (int i = (k - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, k, i);//�ȴ�a�ж�ȡk������һ��С��
//	}
//	//���Ѻ�������ÿ��Ԫ����Ѷ�Ԫ�رȽϣ������ڶѶ�����ʱ���ʹ���Ѷ��������
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
//	//ֱ��ʹ���������ģ�⽨��
//	//�������һ��Ԫ�ص����Ѷ�Ԫ�أ��������Ԫ�ؽ������ϵ�������
//	/*HeapSort(a, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//	return 0;
//}
//TOP_K���� ѡ��ǰk�����������������С��
// n������ѡ��ǰk�����������С��--ѡ���������ͽ����Ķ�,��Ȼ��������飬��Ԫ�ش��ڶѶ��ľʹ����ȥ��
// n������ѡ��ǰk����С���������


//����һ����Ϊ2�ľͻ�����һ����Ϊ0�ģ����Զ�Ϊ0�ĸ�����Զ�ȶ�Ϊ2�ĸ���Ҫ��һ
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
//	//������� #�͸����ݴ������
//	struct BTree* root = (struct BTree*)malloc(sizeof(struct BTree));
//	root->data = a[*pi];
//	(*pi)++;
//	root->left = CreatBTree(a, pi);//Ϊ���Ӵ������
//	root->right = CreatBTree(a, pi);//Ϊ�Һ��Ӻ��Ӵ������
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
//	//����Ҫ����ǰ�������ʽ����һ��������
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
//	//���ļ����ȡk�������н���
//	FILE* fp = fopen("text", "r");
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fp, "%d", &topk[i]);
//	}
//	//����
//	for (int i = (k - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(topk, k, i);
//	}
//	//���ļ���ÿһ�����ݶ��ͶѶ����ݱȽϣ�����ȶѶ����ݴ�ʹ���Ѷ��������
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
	// 1. ����--��a��ǰk��Ԫ�ؽ���
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, k, i);
	}
	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
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