#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "BiTree.h"

typedef BiTree SOSTree;

typedef struct {
	elemtType *elem;
	float *w;
	int length;
}SSTable;

Status CreateSOSTree(SOSTree *T, SSTable ST);