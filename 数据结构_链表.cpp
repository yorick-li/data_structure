#include <stdio.h>
#include <malloc.h>

// 定义存储的数据类型
typedef struct NODE {
	int data;
	struct NODE * pNext;
} NODE, *PNODE;


// 初始化链表
PNODE init_struct();
// 输出链表所有元素
void show(PNODE pHead);
// 判断链表是否为空
bool isEmpty(PNODE pHead);
// 输出链表长度
int length(PNODE pHead);
// 插入一个元素
bool insert(PNODE pHead, int position, int value);
// 删除一个元素
bool remove(PNODE pHead, int position, int * value);
// 排序
void sort(PNODE pHead);




int main(void) {
	// 创建一个链表
	PNODE pHead = init_struct();
	//show(pHead);
	/*
	printf("\n");
	if(isEmpty(pHead)) {
		printf("链表为空！\n");
	}else {
		printf("链表不空！\n");
	}
	int len = length(pHead);

	printf("链表长度为：%d\n", len);
	*/



	// 插入一个元素
	//insert(pHead, 7, 12);
	//show(pHead);
	//insert(pHead, 2, 15);
	//show(pHead);
	//insert(pHead, 1, -8);
	//show(pHead);

	
	printf("\n");
	printf("\n");
	printf("\n");

	// 删除一个元素
	int value = NULL;
	remove(pHead, 4, &value);
	show(pHead);
	printf("删除的元素是：%d\n", value);


	printf("\n");
	printf("\n");
	printf("\n");
	sort(pHead);
	show(pHead);



	// 释放内存
	if (pHead != NULL) {
		free(pHead);
		pHead = NULL;
	}
	

	return 0;
}



// 默认初始化长度为6的链表
PNODE init_struct() {

	int len = 6;

	// 头指针
	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	// 头结点
	pHead->data = NULL;
	
	PNODE pNow = pHead;

	// 链表有效节点
	for (int i=0; i<len; i++) {
		PNODE pNd = (PNODE)malloc(sizeof(NODE));
		pNd->data = i+1;
		pNd->pNext = NULL;

		pNow->pNext = pNd;
		pNow = pNd;

	}

	return pHead;
}

// 返回链表长度
void show(PNODE pHead) {
	// 不打印头节点
	while (pHead->pNext != NULL) {
		pHead = pHead->pNext;
		printf("%d  ", pHead->data);
	}
	printf("\n");
	return ;

}

// 判断链表是否为空
bool isEmpty(PNODE pHead) {
	bool result = false;

	if (pHead->pNext == NULL) {
		result = true;
	}

	return result;
}

// 输出链表长度
int length(PNODE pHead) {
	int length = 0;

	if (isEmpty(pHead)) {
		return length;
	}

	while (pHead->pNext != NULL) {
		pHead = pHead->pNext;
		length ++;
	}

	return length;
}

bool insert(PNODE pHead, int position, int value) {
	if (isEmpty(pHead)) {
		return false;
	}

	if (position > length(pHead) + 1 || position < 1) {
		return false;
	}

	// 找到position位置前的一个位置的指针
	int i=1;
	while (i < position && pHead->pNext != NULL) {
		pHead = pHead->pNext;
		i ++;
	}

	PNODE q = (PNODE)malloc(sizeof(NODE));
	q->data = value;
	q->pNext = pHead->pNext;
	pHead->pNext = q;
	return true;
}


bool remove(PNODE pHead, int position, int * deleted) {
	if(isEmpty(pHead)) {
		return false;
	}
	if (position > length(pHead) || position < 1) {
		return false;
	}

	int i=1;
	while(i<position && pHead->pNext != NULL) {
		pHead = pHead->pNext;
		i++;
	}

	PNODE removed = pHead->pNext;
	pHead->pNext = removed->pNext;
	*deleted = removed->data;

	return true;

}


// 大到小排序
void sort(PNODE pHead) {
	/*
	int i=0;
	while ( i<length(pHead)-1) {
		pHead = pHead->pNext;

		int j=i+1;
		PNODE pJ = pHead;
		while (j<=length(pHead)) {
			pJ = pJ->pNext;
			
			int temp;
			if (pHead->data < pJ->data) {
				temp = pJ->data;
				pJ->data = pHead->data;
				pHead->data = temp;
			}
			j++;

		}

		i ++;
	}

	return ;
	*/

	PNODE pI = pHead;
	for (int i=0; i<length(pHead)-1; i++) {

		// 第一个元素
		pI = pI->pNext;

		// 第二个元素到最后一个元素
		PNODE pJ = pI;
		for (int j=i+1; j<length(pHead); j++) {
			pJ = pJ->pNext;
			if (pJ->data > pHead->data) {
				int temp = pJ->data;
				pJ->data = pI->data;
				pI->data = temp;
//		show(pHead);
			}
		}
		//show(pHead);
	}
	return ;



}