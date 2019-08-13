#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


/**
 * 用循环数组实现“先进先出”的队列
 */


// 定义队列结构
typedef struct Queue {
	int * data;		// 存放数据的数组
	int front;		// 第一个元素的下标
	int rear;		// 最后一个元素的下一个下标
} QUEUE, *PQUEUE;


// 初始化队列
void init_Queue(PQUEUE pQ);

// 入队操作
bool in_Queue(PQUEUE pQ, int eleValue);

// 出队操作
bool out_Queue(PQUEUE pQ, int * ele);

// 遍历队列的元素
void traverse(PQUEUE pQ);

// 判断队列是否为空
bool isEmpty(PQUEUE pQ);

// 判断队列是否已满
bool isFull(PQUEUE pQ);

int main(void) {
	QUEUE queue;

	init_Queue(&queue);
	traverse(&queue);

	in_Queue(&queue, 1);
	in_Queue(&queue, 2);
	in_Queue(&queue, 3);
	in_Queue(&queue, 4);
	in_Queue(&queue, 5);
	in_Queue(&queue, 6);
	in_Queue(&queue, 7);
	in_Queue(&queue, 8);
	traverse(&queue);


	int val;
	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("出队成功，出队的元素是： %d\n", val);
	}
	traverse(&queue);


	return 0;
}

void init_Queue(PQUEUE pQ) {
	int len = 6;

	pQ->data = (int *)malloc(sizeof(int) * len);
	if (pQ->data == NULL) {
		printf("动态内存分布失败!\n");
		exit(-1);
	}

	pQ->front = 0;
	pQ->rear = 0;

	return ;
}

void traverse(PQUEUE pQ) {
	if (isEmpty(pQ)) {
		printf("队列为空\n");
		return ;
	}
	int p = pQ->front;
	while (p != pQ->rear) {
		printf("%d ", pQ->data[p]);
		p ++;
	}
	printf("\n");
}

bool isEmpty(PQUEUE pQ) {
	if (pQ->front == pQ->rear) {
		return true;
	}
	return false;
}

bool isFull(PQUEUE pQ) {
	if ((pQ->rear + 1) % 6 == pQ->front) {
		return true;
	}
	return false;
}

bool in_Queue(PQUEUE pQ, int eleValue) {
	if (isFull(pQ)) {
		printf("队列已满!\n");
		return false;
	}
	// 赋值
	pQ->data[pQ->rear] = eleValue;
	// 下标后移一位
	pQ->rear = (pQ->rear + 1) % 6;

	return true;
}

bool out_Queue(PQUEUE pQ, int * ele) {

	if (isEmpty(pQ)) {
		printf("队列以已空!\n");
		return false;
	}

	*ele = pQ->data[pQ->front];
	pQ->front = (pQ->front + 1) % 6;
	return true;
}