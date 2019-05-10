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

	//1. 연결리스트를 생성한다.
	Create(&linkedList);
	//2. "20"을 맨 앞에 저장한다. / 20
	object = 20;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//3. "30"을 맨 뒤에 저장한다. / 20 30
	object = 30;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 1000;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//4. 맨 앞을 출력한다.
	index = First(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//5. "10"을 맨 앞에 저장한다. / 10 20 30
	object = 10;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//검사
	printf("--------검사--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//6. "30"을 찾는다.
	key = 30;
	index = LinearSearchUnique(&linkedList, &key, CompareIntegers);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//7. 맨 뒤를 출력한다. 10 20 30
	index = Last(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//8. 맨 뒤에 "20"을 저장한다. 10 20 30 20
	object = 20;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//검사
	printf("--------검사--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//9. "20"들을 찾는다.
	printf("========20 검색========\n");
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
	printf("========20 검색========\n");

	//10. 첫번째를 지운다.
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("첫번째 항목 삭제 완료\n");
	}

	//검사
	printf("--------검사--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//11. 첫번째 다음항목을 지운다.
	index = First(&linkedList);
	index = Next(&linkedList);
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("삭제 완료\n");
	}

	//검사
	printf("--------검사--------\n");
	previous = NULL;
	index = First(&linkedList);
	while (index != previous) {
		previous = index;
		GetAt(&linkedList, index, &ret, sizeof(Long));
		printf("%d ", ret);
		index = Next(&linkedList);
	}
	printf("\n");

	//12. 마지막을 지운다.
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("마지막 항목 삭제 완료\n");
	}

	//검사
	printf("--------검사--------\n");
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