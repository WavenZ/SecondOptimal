/*
	@brief:构造次优查找树
	@author:WavenZ
	@time:2018/10/12
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "SecondOptimal.h"
#include "BiTree.h"



int main(int argc, char *argv[]) {

	BiTree T=NULL;
	SSTable ST;
	ST.elem = (char*)malloc(sizeof(char) * 20);
	ST.w = (float*)malloc(sizeof(float) * 20);
	ST.length = 0;
	char data, space;
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	space = ' ';
	for (int i = 1; space == ' '; i++) {
		scanf("%c%c", &data, &space);
		ST.length += 1;
		ST.elem[i] = data;
	}
	space = ' ';
	for (int i = 1; space == ' '; i++) {
		scanf("%d%c", &data, &space);
		ST.w[i] = data;
	}
	CreateSOSTree(&T, ST);
	PreOderTraverse(T);
	free(ST.elem);
	free(ST.w);
	fclose(stdin);
	fclose(stdout);
	system("pause");
	return 1;
}