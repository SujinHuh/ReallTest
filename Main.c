//Main.c
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int CompareIntegers(void* one, void* other);

int main(int argc, char *argv[])
{
	LinkedList linkedList;
	Node *index;
	Long object;
	Long key;
	Node* (*indexes);
	Long count;
	Long i;
	Long ret;

	Node* it;
	Node* previous;

	//1. ���Ḯ��Ʈ�� �����Ѵ�.
	Create(&linkedList);
	//2. "20"�� �� �տ� �����Ѵ�. / 20
	object = 20;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//3. "30"�� �� �ڿ� �����Ѵ�. / 20 30
	object = 30;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 1000;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//4. �� ���� ����Ѵ�.
	index = First(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//5. "10"�� �� �տ� �����Ѵ�. / 10 20 30
	object = 10;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//�˻�
	printf("--------�˻�--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//6. "30"�� ã�´�.
	key = 30;
	index = LinearSearchUnique(&linkedList, &key, CompareIntegers);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//7. �� �ڸ� ����Ѵ�. 10 20 30
	index = Last(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//8. �� �ڿ� "20"�� �����Ѵ�. 10 20 30 20
	object = 20;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//�˻�
	printf("--------�˻�--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//9. "20"���� ã�´�.
	printf("========20 �˻�========\n");
	key = 20;
	LinearSearchDuplicate(&linkedList, &key, &indexes, &count, CompareIntegers);
	i = 0;
	while (i < count)
	{
		GetAt(&linkedList, indexes[i], &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");
	if (indexes != NULL)
	{
		free(indexes);
		index = NULL;
	}
	printf("========20 �˻�========\n");

	//10. ù��°�� �����.
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("ù��° �׸� ���� �Ϸ�\n");
	}

	//�˻�
	printf("--------�˻�--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//11. ù��° �����׸��� �����.
	index = First(&linkedList);
	index = Next(&linkedList);
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("���� �Ϸ�\n");
	}

	//�˻�
	printf("--------�˻�--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//12. �������� �����.
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("������ �׸� ���� �Ϸ�\n");
	}

	//�˻�
	printf("--------�˻�--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	Destroy(&linkedList);

	return 0;
}

int CompareIntegers(void* one, void* other)
{
	int ret;

	if (*(int*)one > *((int*)other)) {
		ret = 1;
	}
	else if (*(int*)one == *((int*)other))
	{
		ret = 0;
	}
	else if (*(int*)one < *((int*)other))
	{
		ret = -1;
	}

	return ret;
}