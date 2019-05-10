//BusinessCardBook.c
#include"BusinessCardBook.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#if 0
int main(int argc, char *argv[]) {
	BusinessCardBook businessCardBook;
	BusinessCard *index;
	BusinessCard businessCard;
	BusinessCard* (*indexes);
	Long count;

	//1.
	BusinessCardBook_Create(&businessCardBook);
	//2. 

	//3. 
	strcpy(businessCard.personal.name, "홍길동");
	strcpy(businessCard.personal.position, "사장");
	strcpy(businessCard.personal.telephoneNumber, "010");
	strcpy(businessCard.personal.emailAddress, "hong@");
	strcpy(businessCard.company.name, "LG");
	strcpy(businessCard.company.addreess, "서초");
	strcpy(businessCard.company.telephoneNumber, "02");
	strcpy(businessCard.company.faxNumber, "02-2");
	strcpy(businessCard.company.url, "LG.com");
	index = TakeIn(&businessCardBook, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position, index->personal.telephoneNumber, index->personal.emailAddress,
		index->company.name, index->company.addreess, index->company.telephoneNumber, index->company.faxNumber, index->company.url);



	return 0;
}

void BusinessCardBook_Create(BusinessCardBook *businessCardBook) {

	Create(&businessCardBook->businessCards);
	businessCardBook->length = 0;
	businessCardBook->current = NULL;
}

BusinessCard* TakeIn(BusinessCardBook *businessCardBook, BusinessCard businessCard) {
	Node *node;

	node = AppendFromTail(&businessCardBook->businessCards, &businessCard, sizeof(BusinessCard));
	businessCardBook->current = (BusinessCard*)node + 1;
	businessCardBook->length++;

	return businessCardBook->current;
}

BusinessCard TakeOut(BusinessCardBook *businessCardBook, BusinessCard *index) {
	Node *node;
	BusinessCard businessCard;

	node = LinearSearchUnique(&businessCardBook->businessCards, index, ComparePointers);
	businessCardBook->current = (BusinessCard*)node + 1;
	GetAt(&businessCardBook->businessCards, node, &businessCard, sizeof(BusinessCard));
	node = Delete(&businessCardBook->businessCards, node);
	businessCardBook->current = (BusinessCard*)businessCardBook->businessCards.current + 1;
	businessCardBook->length--;

	return businessCard;
}

int ComparePointers(void *one, void *other) {
	BusinessCard *one_ = (BusinessCard*)one;
	BusinessCard *other_ = (BusinessCard*)other;
	int ret = 1;

	if (one == other) {
		ret = 0;
	}

	return ret;
}

void Find(BusinessCardBook *businessCardBook, char(*name), BusinessCard* *(*indexes), Long *count) {
	Node* (*nodes);
	Long i = 0;

	LinearSearchDuplicate(&businessCardBook->businessCards, name, &nodes, &count, CompareNames);
	*indexes = (BusinessCard*(*))calloc(businessCardBook->length, sizeof(BusinessCard*));
	while (i < *count) {
		(*indexes)[i] = (BusinessCard*)nodes[i] + 1;
		i++;
	}
	if (nodes != NULL) {
		free(nodes);
		nodes = NULL;
	}
}

int CompareNames(void *one, void *other) {
	BusinessCard *one_ = (BusinessCard*)one;
	char(*other_) = (char(*))other;
	int ret;

	strcmp(one_->personal.name, other);

	return ret;
}


BusinessCard* FindByCompanyName(BusinessCardBook *businessCardBook, char(*companyName)) {
	Node *node;

	node = LinearSearchUnique(&businessCardBook->businessCards, companyName, CompareCompanyName);
	businessCardBook->current = (BusinessCard*)node + 1;

	return businessCardBook->current;
}

int CompareCompanyName(void *one, void *other) {
	BusinessCard *one_ = (BusinessCard*)one;
	char(*other_) = (char(*))other;
	int ret;

	strcmp(one_->company.name, other);

	return ret;
}

BusinessCard* BusinessCardBook_Move(BusinessCardBook *businessCardBook, BusinessCard *index) {
	Node *node;

	node = LinearSearchUnique(&businessCardBook->businessCards, index, ComparePointers);
	node = Move(&businessCardBook->businessCards, node);
	businessCardBook->current = (BusinessCard*)node + 1;

	return businessCardBook->current;
}

#endif