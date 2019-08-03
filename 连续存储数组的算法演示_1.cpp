#include <stdio.h>
#include <malloc.h>

/*
 C����һ������javaArrayList���б�
*/

/**
 * �ṹ����
 */
struct ArrayList {
	int * data;		//�洢������ĵ�һ��Ԫ�صĵ�ַ
	int size;		// ����ʵ��Ԫ�ص�����
	int length;		// ����ĳ���
};

struct ArrayList * init_arr(int len);

// ���һ��Ԫ��(ĩβ���)
bool append_arr(struct ArrayList * pArLt, int element);

// ���һ��Ԫ��(ָ�����)
bool insert_arr(struct ArrayList * pArLt, int element, int index);

// ɾ��ĳ��Ԫ��
int delete_arr(struct ArrayList * pArLt, int element);

// ��ȡĳ��Ԫ��
int get(struct ArrayList * pArLt, int index);

// �б��Ƿ�Ϊ��
bool is_empty(struct ArrayList * pArLt);

// �б��Ƿ�����
bool is_full(struct ArrayList * pArLt);

// ����(��->С)
void sort_arr(struct ArrayList * pArLt);

// ����б�Ԫ��
void show(struct ArrayList * pArLt);

// Ԫ�ص���
void inverse_arr(struct ArrayList * pArLt);

// �ͷ��б��ڴ�ռ�

int main(void) {

	// ��ʼ��һ���б�, Ĭ�Ͽɴ洢10��Ԫ��
	struct ArrayList * pArLt = init_arr(10);
	//printf("1.��ʼ���б�\n");
	//show(pArLt);

	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("2.���Ԫ��\n");
	append_arr(pArLt, 5);
	append_arr(pArLt, 8);
	append_arr(pArLt, -4);
	append_arr(pArLt, 11);
	append_arr(pArLt, 17);
	append_arr(pArLt, -2);
	append_arr(pArLt, 59);
	//printf("3.���Ԫ�غ���б�\n");
	//show(pArLt);


	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("4.ɾ��Ԫ��\n");
	//delete_arr(pArLt, 5);
	//show(pArLt);
	//printf("\n");
	//delete_arr(pArLt, 4);
	//show(pArLt);


	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("4.����Ԫ��\n");
	insert_arr(pArLt, 10, 6);
	//show(pArLt);
	
	insert_arr(pArLt, 15, 3);
	//show(pArLt);
	insert_arr(pArLt, 0, 1);
	//show(pArLt);

	printf("\n");
	printf("\n");
	//insert_arr(pArLt, 0, -1);
	//show(pArLt);


	/*printf("\n");
	printf("\n");
	get(pArLt, 10);
	get(pArLt, 0);
	get(pArLt, -1);
	get(pArLt, 1);
	get(pArLt, 5);
	get(pArLt, 9);*/




	printf("5.����(��->С)\n");
	sort_arr(pArLt);
	show(pArLt);


	printf("\n");
	printf("\n");
	printf("6.����Ԫ��(С->��)\n");
	inverse_arr(pArLt);
	show(pArLt);

	

	return 0;
}


struct ArrayList * init_arr(int len) {

	struct ArrayList * pArLt = (struct ArrayList * )malloc(sizeof(struct ArrayList));
	pArLt->length = len;
	pArLt->size = 0;
	pArLt->data = (int *)malloc(sizeof(int) * len);

	return pArLt;

}

void show(struct ArrayList * pArLt) {
	printf("\n");
	printf("�б����Ϣ����:===============\n");
	printf("�б��Ԫ����%d��\n", pArLt->size);

	if (is_empty(pArLt)) {
		return ;
	}

	for (int i=0; i<pArLt->size; i++) {
		printf("%d  ", pArLt->data[i]);
	}
	printf("\n");
	

}

bool is_empty(struct ArrayList * pArLt) {

	if (pArLt->size > 0) {
		return false;
	}else {
		return true;
	}

}

bool is_full(struct ArrayList * pArLt) {

	if (pArLt->size == pArLt->length) {
		return true;
	}else {
		return false;
	}

}

bool append_arr(struct ArrayList * pArLt, int element) {

	if (is_full(pArLt)) {
		printf("�б�����,�������Ԫ��\n");
		return false;
	}

	pArLt->data[pArLt->size] = element;
	pArLt->size ++;
	
	return true;
}


int delete_arr(struct ArrayList * pArLt, int element) {
	int delIndex = -1;
	if (is_empty(pArLt)) {
		printf("�б�Ϊ��,����ɾ��Ԫ��\n");
		return delIndex;
	}
	
	for (int i=0; i<pArLt->size; i++) {
		if (pArLt->data[i] == element) {
			delIndex = i;
			break;
		}
	}

	if (delIndex == -1) {
		printf("�б��޴�Ԫ��,����ɾ��\n");
		return delIndex;
	}

	for (int j=delIndex; j<pArLt->size-1; j++) {
		pArLt->data[j] = pArLt->data[j+1];
	}
	pArLt->size --;

	printf("ɾ����Ԫ�ص�����Ϊ: %d\n", delIndex);

	return delIndex;
}


bool insert_arr(struct ArrayList * pArLt, int element, int index) {
	if (is_full(pArLt)) {
		printf("�б�����,�������Ԫ��\n");
		return false;
	}

	if(index <= 0) {
		printf("�����λ�ò���,������������:��1,2,3...\n");
		return false;
	}

	if (index > pArLt->size) {
		append_arr(pArLt, element);
		return true;
	}

	for (int i=pArLt->size-1; i>=index-1; i--) {
		pArLt->data[i+1] = pArLt->data[i];
	}

	pArLt->data[index-1] = element;
	pArLt->size ++;

	return true;

}

int get(struct ArrayList * pArLt, int index) {
	if (is_empty(pArLt)) {
		printf("�б�Ϊ��,�޷���ȡԪ��\n");
		return NULL;
	}

	if (index < 1 || index > pArLt->size) {
		printf("Ԫ�ز�����\n");
		return NULL;
	}

	printf("ȡ����Ԫ��Ϊ: %d\n", pArLt->data[index-1]);
	return pArLt->data[index-1];
}


// ð������
void sort_arr(struct ArrayList * pArLt) {
	if (is_empty(pArLt)) {
		printf("�б�Ϊ��");
		return ;
	}

	int temp = NULL;
	for (int i=0; i<pArLt->size; i++) {
		for (int j=0; j<pArLt->size-i; j++) {

			if (pArLt->data[j] < pArLt->data[j+1]) {
				temp = pArLt->data[j];
				pArLt->data[j] = pArLt->data[j+1];
				pArLt->data[j+1] = temp;
			}
			
		}
	}

	return ;
}

// ����Ԫ��
void inverse_arr(struct ArrayList * pArLt) {

	if (is_empty(pArLt)) {
		printf("�б�Ϊ��");
		return ;
	}

	int temp = NULL;
	for (int i=0; i<pArLt->size; i++) {
		for (int j=pArLt->size-1-i; j>0; j--) {
			if (i == j || i > j) {
				return ;
			}
			
			temp = pArLt->data[i];
			pArLt->data[i] = pArLt->data[j];
			pArLt->data[j] = temp;

			//show(pArLt);
			break;

			
		}
	}
	
	
}