#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/**
 * ʹ������ʵ�ֵ�ջ
 * 
 */

// ����ջ�Ľڵ�
typedef struct Node {
	int data;
	struct Node * pNext;
} NODE, *PNODE;

// ����ջ�ṹ
typedef struct Stack {
	// ջ����˵�Ԫ��ָ��
	PNODE pTop;
	// ջ����׶˵�Ԫ��ָ��
	PNODE pBottom;
} STACK, *PSTACK;

// ��ʼ��ջ
void init(PSTACK pS);

// Ԫ����ջ
void push(PSTACK pS, int elementVal);

// Ԫ�س�ջ����ҪУ�飺ջ�Ƿ�Ϊ��
bool pop(PSTACK pS, int * node);

// ջ�Ƿ�Ϊ��
bool isEmpty(PSTACK pS);

// ջ�ĳ���
int length(PSTACK pS);

// ����ջ��Ԫ��, ��ҪУ�飺ջ�Ƿ�Ϊ��
void traverse(PSTACK pS);

// ���ջ����Ҫ����̬������ڴ��ͷ�
void clear(PSTACK pS);



// ���Է���
int main(void){

	STACK stack;
	
	init(&stack);
	//traverse(&stack);
	//printf("\n");

	/*
	if (isEmpty(&stack)) {
		printf("��ջ\n");
	}else {
		printf("�ǿ�ջ\n");
	}
	*/


	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	traverse(&stack);
	printf("\n");
	printf("ջ����:%d��Ԫ��\n", length(&stack));

	int value;
	if (pop(&stack, &value)) {
		printf("ɾ����Ԫ����: %d\n", value);
	}else {
		printf("��ջʧ��!\n");
	}
	
	traverse(&stack);
	printf("\n");
	printf("ջ����:%d��Ԫ��\n", length(&stack));


	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	clear(&stack);
	traverse(&stack);



	return 0;
}

void init(PSTACK pS) {
	// ջ�ṹ�ĳ�ʼ��
	pS = (PSTACK)malloc(sizeof(STACK));
	if (pS == NULL) {
		printf("ջ�ĳ�ʼ��ʧ�ܣ�����̬�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	// ջԪ�صĳ�ʼ��
	pS->pTop = (PNODE)malloc(sizeof(PNODE));
	pS->pBottom = pS->pTop;

	return ;
}

bool isEmpty(PSTACK pS) {
	// Ĭ��Ϊ��
	bool result = true;
	if (pS->pTop != pS->pBottom) {
		result = false;
	}
	return result;
}

void traverse(PSTACK pS) {
	if (isEmpty(pS)) {
		printf("ջΪ�գ�");
		return ;
	}
	PNODE pCurrent = pS->pTop;	// ��ǰָ��Ľڵ�
	while (pCurrent != pS->pBottom) {
		printf("%d  ", pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
	printf("\n");
}

void push(PSTACK pS, int elementVal) {
	// ����һ��ջ�ڵ�
	PNODE pNew = (PNODE)malloc(sizeof(NODE));//һ��Ҫ��NODE����,��Ȼ�ͷ��ڴ�ʱ�����
	if (pNew == NULL) {
		printf("������Ԫ��ʧ�ܣ�����̬�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	pNew->data = elementVal;

	// ���µ�ջ�ڵ���ջ
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

	return ;
}

bool pop(PSTACK pS, int * node) {

	if(isEmpty(pS)) {
		printf("��ջʧ��!ջ��!");
		return false;
	}else {
		// ɾ����һ��Ԫ��(ջ��ɾ��Ԫ��,���ͷ��ڴ�)
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
	PNODE pCurrent = pS->pTop;	// ��ǰָ��Ľڵ�
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