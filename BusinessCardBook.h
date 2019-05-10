//BusinessCardBook.h
#ifndef _BUSINESSCARDBOOK_H
#define _BUSINESSCARDBOOK_H
#include"LinkedList.h"

typedef signed long int Long;

typedef struct _company {
	char name[32];
	char addreess[64];
	char telephoneNumber[12];
	char faxNumber[12];
	char url[64];
}Company;

typedef struct _personal {
	char name[11];
	char position[16];
	char telephoneNumber[12];
	char emailAddress[64];
}Personal;

typedef struct _businessCard {
	Personal personal;
	Company company;
}BusinessCard;

typedef struct _businessCardBook {
	LinkedList businessCards;
	Long length;
	BusinessCard *current;
}BusinessCardBook;

void BusinessCardBook_Create(BusinessCardBook *businessCardBook);
Long Load(BusinessCardBook *businessCardBook);
BusinessCard* TakeIn(BusinessCardBook *businessCardBook, BusinessCard businessCard);
BusinessCard TakeOut(BusinessCardBook *businessCardBook, BusinessCard *index);
void Find(BusinessCardBook *businessCardBook, char(*name), BusinessCard* *(*indexes), Long *count);

BusinessCard* FindByCompanyName(BusinessCardBook *businessCardBook, char(*companyName));
BusinessCard* BusinessCardBook_Move(BusinessCardBook *businessCardBook, BusinessCard *index);

int ComparePointers(void *one, void *other);
int CompareNames(void *one, void *other);
int CompareCompanyName(void *one, void *other);

#endif //_BUSINESSCARDBOOK_H
