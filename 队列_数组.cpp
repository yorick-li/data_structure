#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


/**
 * ��ѭ������ʵ�֡��Ƚ��ȳ����Ķ���
 */


// ������нṹ
typedef struct Queue {
	int * data;		// ������ݵ�����
	int front;		// ��һ��Ԫ�ص��±�
	int rear;		// ���һ��Ԫ�ص���һ���±�
} QUEUE, *PQUEUE;


// ��ʼ������
void init_Queue(PQUEUE pQ);

// ��Ӳ���
bool in_Queue(PQUEUE pQ, int eleValue);

// ���Ӳ���
bool out_Queue(PQUEUE pQ, int * ele);

// �������е�Ԫ��
void traverse(PQUEUE pQ);

// �ж϶����Ƿ�Ϊ��
bool isEmpty(PQUEUE pQ);

// �ж϶����Ƿ�����
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
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);

	if (out_Queue(&queue, &val)) {
		printf("���ӳɹ������ӵ�Ԫ���ǣ� %d\n", val);
	}
	traverse(&queue);


	return 0;
}

void init_Queue(PQUEUE pQ) {
	int len = 6;

	pQ->data = (int *)malloc(sizeof(int) * len);
	if (pQ->data == NULL) {
		printf("��̬�ڴ�ֲ�ʧ��!\n");
		exit(-1);
	}

	pQ->front = 0;
	pQ->rear = 0;

	return ;
}

void traverse(PQUEUE pQ) {
	if (isEmpty(pQ)) {
		printf("����Ϊ��\n");
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
		printf("��������!\n");
		return false;
	}
	// ��ֵ
	pQ->data[pQ->rear] = eleValue;
	// �±����һλ
	pQ->rear = (pQ->rear + 1) % 6;

	return true;
}

bool out_Queue(PQUEUE pQ, int * ele) {

	if (isEmpty(pQ)) {
		printf("�������ѿ�!\n");
		return false;
	}

	*ele = pQ->data[pQ->front];
	pQ->front = (pQ->front + 1) % 6;
	return true;
}