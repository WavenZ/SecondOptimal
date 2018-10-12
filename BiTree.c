#define _CRT_SECURE_NO_WARNINGS
#include "BiTree.h"

Status CreateBiTree(BiTree *T) {
	char ch;
	scanf("%c", &ch);
	if (ch == ' ') 
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return 1;
}
Status PreOderTraverse(BiTree T) {
	if (T) {
		visit(T);
		if(PreOderTraverse(T->lchild))
			if(PreOderTraverse(T->rchild)) return 1;
		return 0;
	}
	else return 1;
}
void visit(BiTree T) {
	printf("%c", T->data);
}
