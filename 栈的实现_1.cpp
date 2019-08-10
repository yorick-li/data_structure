#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/**
 * 使用链表实现的栈
 * 
 */

// 定义栈的节点
typedef struct Node {
	int data;
	struct Node * pNext;
} NODE, *PNODE;

// 定义栈结构
typedef struct Stack {
	// 栈的最顶端的元素指针
	PNODE pTop;
	// 栈的最底端的元素指针
	PNODE pBottom;
} STACK, *PSTACK;

// 初始化栈
void init(PSTACK pS);

// 元素入栈
void push(PSTACK pS, int elementVal);

// 元素出栈，需要校验：栈是否为空
bool pop(PSTACK pS, int * node);

// 栈是否为空
bool isEmpty(PSTACK pS);

// 栈的长度
int length(PSTACK pS);

// 遍历栈的元素, 需要校验：栈是否为空
void traverse(PSTACK pS);

// 清空栈，需要将动态分配的内存释放
void clear(PSTACK pS);



// 测试方法
int main(void){

	STACK stack;
	
	init(&stack);
	//traverse(&stack);
	//printf("\n");

	/*
	if (isEmpty(&stack)) {
		printf("空栈\n");
	}else {
		printf("非空栈\n");
	}
	*/


	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	traverse(&stack);
	printf("\n");
	printf("栈共有:%d个元素\n", length(&stack));

	int value;
	if (pop(&stack, &value)) {
		printf("删除的元素是: %d\n", value);
	}else {
		printf("出栈失败!\n");
	}
	
	traverse(&stack);
	printf("\n");
	printf("栈共有:%d个元素\n", length(&stack));


	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	clear(&stack);
	traverse(&stack);



	return 0;
}

void init(PSTACK pS) {
	// 栈结构的初始化
	pS = (PSTACK)malloc(sizeof(STACK));
	if (pS == NULL) {
		printf("栈的初始化失败！（动态分配内存失败）");
		exit(-1);
	}
	// 栈元素的初始化
	pS->pTop = (PNODE)malloc(sizeof(PNODE));
	pS->pBottom = pS->pTop;

	return ;
}

bool isEmpty(PSTACK pS) {
	// 默认为空
	bool result = true;
	if (pS->pTop != pS->pBottom) {
		result = false;
	}
	return result;
}

void traverse(PSTACK pS) {
	if (isEmpty(pS)) {
		printf("栈为空！");
		return ;
	}
	PNODE pCurrent = pS->pTop;	// 当前指向的节点
	while (pCurrent != pS->pBottom) {
		printf("%d  ", pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
	printf("\n");
}

void push(PSTACK pS, int elementVal) {
	// 构建一个栈节点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));//一定要是NODE类型,不然释放内存时会出错
	if (pNew == NULL) {
		printf("构建新元素失败！（动态分配内存失败）");
		exit(-1);
	}
	pNew->data = elementVal;

	// 将新的栈节点入栈
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

	return ;
}

bool pop(PSTACK pS, int * node) {

	if(isEmpty(pS)) {
		printf("出栈失败!栈空!");
		return false;
	}else {
		// 删除第一个元素(栈中删除元素,并释放内存)
		PNODE r = pS->pTop;
		*node = r->data;
		pS->pTop = r->pNext;

		free(r);
		r = NULL;

		return true;
	}

	
}

int length(PSTACK pS) {
	if (isEmpty(pS)) {
		return 0;
	}
	int count = 0;
	PNODE pCurrent = pS->pTop;	// 当前指向的节点
	while (pCurrent != pS->pBottom) {
		pCurrent = pCurrent->pNext;
		count ++;
	}
	return count;
}

void clear(PSTACK pS) {
	if (isEmpty(pS)) {
		return ;
	}

	PNODE pCurrent;
	while (pS->pTop != pS->pBottom) {
		pCurrent = pS->pTop;
		pS->pTop = pCurrent->pNext;
		free(pCurrent);
		pCurrent = NULL;
	}
}