#define _CRT_SECURE_NO_WARNINGS

#include "SecondOptimal.h"
#include "BiTree.h"

int FinMax(float a, float b, float c)
{
	float max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max == a) return -1;
	else if (max == b) return 0;
	else return 1;
}
void  SecondOptimal(BiTree *T,elemtType R[], float sw[], int low, int high) {
	//R[low..high] �����
	//sw[] �ۼ�Ȩֵ��
	//��Pi=|(sw(h)-sw(i))-(sw(i-1)-sw(l-1))|=|(sw(h)+sw(l-1))-sw(i)-sw(i-1)|
	int i = low;
	int min = abs(sw[high] - sw[low]);//��ʼ��min
	int dw = sw[high] + sw[low - 1];//dw=(sw(h)+sw(l-1))
	for (int j = low + 1; j <= high; ++j) {//Ѱ����С�Ħ�Pj
		if (abs(dw - sw[j] - sw[j - 1]) < min) {
			i = j;
			min = abs(dw - sw[j] - sw[j - 1]);//��Pj
		}
	}
	if (i > low&&i < high) {//���ܴ��ڸ��ڵ�ȨֵС�����ڽڵ�������ȡ���ڽڵ�ϴ�ֵ
		i += FinMax(sw[i - 1] - sw[i - 2], sw[i] - sw[i - 1], sw[i + 1] - sw[i]);
	}
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = R[i];
	if (i == low) (*T)->lchild = NULL;
	else SecondOptimal(&(*T)->lchild, R, sw, low, i - 1);
	if (i == high) (*T)->rchild = NULL;
	else SecondOptimal(&(*T)->rchild, R, sw, i + 1, high);
}

void FindSw(float *sw, SSTable ST) {
	sw[0] = 0;
	for (int i = 1; i <= ST.length; ++i) {
		sw[i] = sw[i - 1] + ST.w[i];
	}
}
Status CreateSOSTree(SOSTree *T, SSTable ST)
{
	float *sw;
	sw = (float *)malloc(sizeof(float)*ST.length);
	if (ST.length == 0) T = NULL;
	else {
		FindSw(sw, ST);
		SecondOptimal(T, ST.elem, sw, 1, ST.length);
	}
	return 1;
}