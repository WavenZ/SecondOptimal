#pragma once

#include <stdio.h>
#include <stdlib.h>
#define Status 
typedef char elemtType;
typedef struct BiTNode {
	elemtType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void visit(BiTree T);
Status CreateBiTree(BiTree *T);
Status PreOderTraverse(BiTree T);