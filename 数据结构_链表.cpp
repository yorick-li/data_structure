#include <stdio.h>
#include <malloc.h>

// ����洢����������
typedef struct NODE {
	int data;
	struct NODE * pNext;
} NODE, *PNODE;


// ��ʼ������
PNODE init_struct();
// �����������Ԫ��
void show(PNODE pHead);
// �ж������Ƿ�Ϊ��
bool isEmpty(PNODE pHead);
// ���������
int length(PNODE pHead);
// ����һ��Ԫ��
bool insert(PNODE pHead, int position, int value);
// ɾ��һ��Ԫ��
bool remove(PNODE pHead, int position, int * value);
// ����
void sort(PNODE pHead);




int main(void) {
	// ����һ������
	PNODE pHead = init_struct();
	//show(pHead);
	/*
	printf("\n");
	if(isEmpty(pHead)) {
		printf("����Ϊ�գ�\n");
	}else {
		printf("�����գ�\n");
	}
	int len = length(pHead);

	printf("������Ϊ��%d\n", len);
	*/



	// ����һ��Ԫ��
	//insert(pHead, 7, 12);
	//show(pHead);
	//insert(pHead, 2, 15);
	//show(pHead);
	//insert(pHead, 1, -8);
	//show(pHead);

	
	printf("\n");
	printf("\n");
	printf("\n");

	// ɾ��һ��Ԫ��
	int value = NULL;
	remove(pHead, 4, &value);
	show(pHead);
	printf("ɾ����Ԫ���ǣ�%d\n", value);


	printf("\n");
	printf("\n");
	printf("\n");
	sort(pHead);
	show(pHead);



	// �ͷ��ڴ�
	if (pHead != NULL) {
		free(pHead);
		pHead = NULL;
	}
	

	return 0;
}



// Ĭ�ϳ�ʼ������Ϊ6������
PNODE init_struct() {

	int len = 6;

	// ͷָ��
	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	// ͷ���
	pHead->data = NULL;
	
	PNODE pNow = pHead;

	// ������Ч�ڵ�
	for (int i=0; i<len; i++) {
		PNODE pNd = (PNODE)malloc(sizeof(NODE));
		pNd->data = i+1;
		pNd->pNext = NULL;

		pNow->pNext = pNd;
		pNow = pNd;

	}

	return pHead;
}

// ����������
void show(PNODE pHead) {
	// ����ӡͷ�ڵ�
	while (pHead->pNext != NULL) {
		pHead = pHead->pNext;
		printf("%d  ", pHead->data);
	}
	printf("\n");
	return ;

}

// �ж������Ƿ�Ϊ��
bool isEmpty(PNODE pHead) {
	bool result = false;

	if (pHead->pNext == NULL) {
		result = true;
	}

	return result;
}

// ���������
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

	// �ҵ�positionλ��ǰ��һ��λ�õ�ָ��
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


// ��С����
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

		// ��һ��Ԫ��
		pI = pI->pNext;

		// �ڶ���Ԫ�ص����һ��Ԫ��
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