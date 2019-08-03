#include <stdio.h>
#include <malloc.h>

/*
 C构建一个类似javaArrayList的列表
*/

/**
 * 结构定义
 */
struct ArrayList {
	int * data;		//存储的数组的第一个元素的地址
	int size;		// 数组实际元素的数量
	int length;		// 数组的长度
};

struct ArrayList * init_arr(int len);

// 添加一个元素(末尾添加)
bool append_arr(struct ArrayList * pArLt, int element);

// 添加一个元素(指定添加)
bool insert_arr(struct ArrayList * pArLt, int element, int index);

// 删除某个元素
int delete_arr(struct ArrayList * pArLt, int element);

// 获取某个元素
int get(struct ArrayList * pArLt, int index);

// 列表是否为空
bool is_empty(struct ArrayList * pArLt);

// 列表是否满了
bool is_full(struct ArrayList * pArLt);

// 排序(大->小)
void sort_arr(struct ArrayList * pArLt);

// 输出列表元素
void show(struct ArrayList * pArLt);

// 元素倒置
void inverse_arr(struct ArrayList * pArLt);

// 释放列表内存空间

int main(void) {

	// 初始化一个列表, 默认可存储10个元素
	struct ArrayList * pArLt = init_arr(10);
	//printf("1.初始化列表\n");
	//show(pArLt);

	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("2.添加元素\n");
	append_arr(pArLt, 5);
	append_arr(pArLt, 8);
	append_arr(pArLt, -4);
	append_arr(pArLt, 11);
	append_arr(pArLt, 17);
	append_arr(pArLt, -2);
	append_arr(pArLt, 59);
	//printf("3.添加元素后的列表\n");
	//show(pArLt);


	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("4.删除元素\n");
	//delete_arr(pArLt, 5);
	//show(pArLt);
	//printf("\n");
	//delete_arr(pArLt, 4);
	//show(pArLt);


	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("4.插入元素\n");
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




	printf("5.排序(大->小)\n");
	sort_arr(pArLt);
	show(pArLt);


	printf("\n");
	printf("\n");
	printf("6.倒置元素(小->大)\n");
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
	printf("列表的信息如下:===============\n");
	printf("列表的元素有%d个\n", pArLt->size);

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
		printf("列表已满,不可添加元素\n");
		return false;
	}

	pArLt->data[pArLt->size] = element;
	pArLt->size ++;
	
	return true;
}


int delete_arr(struct ArrayList * pArLt, int element) {
	int delIndex = -1;
	if (is_empty(pArLt)) {
		printf("列表为空,不可删除元素\n");
		return delIndex;
	}
	
	for (int i=0; i<pArLt->size; i++) {
		if (pArLt->data[i] == element) {
			delIndex = i;
			break;
		}
	}

	if (delIndex == -1) {
		printf("列表无此元素,不可删除\n");
		return delIndex;
	}

	for (int j=delIndex; j<pArLt->size-1; j++) {
		pArLt->data[j] = pArLt->data[j+1];
	}
	pArLt->size --;

	printf("删除的元素的索引为: %d\n", delIndex);

	return delIndex;
}


bool insert_arr(struct ArrayList * pArLt, int element, int index) {
	if (is_full(pArLt)) {
		printf("列表已满,不可添加元素\n");
		return false;
	}

	if(index <= 0) {
		printf("插入的位置不对,请输入正整数:如1,2,3...\n");
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
		printf("列表为空,无法获取元素\n");
		return NULL;
	}

	if (index < 1 || index > pArLt->size) {
		printf("元素不存在\n");
		return NULL;
	}

	printf("取出的元素为: %d\n", pArLt->data[index-1]);
	return pArLt->data[index-1];
}


// 冒泡排序
void sort_arr(struct ArrayList * pArLt) {
	if (is_empty(pArLt)) {
		printf("列表为空");
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

// 倒置元素
void inverse_arr(struct ArrayList * pArLt) {

	if (is_empty(pArLt)) {
		printf("列表为空");
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