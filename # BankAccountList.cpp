#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account{
	int id;
	int balance;	
	char name[50];
	struct account *next;
};

void display(void)
{
	printf("\n-----Menu-----");
	printf("\n1. Make Account");
	printf("\n2. Deposit");
	printf("\n3. Withdraw");
	printf("\n4. Print all saved accounts");	
	printf("\n5. Terminates");
	printf("\nselection : ");
}
/*	
struct account *MakeAccount(struct account *acc)
{
	
	while(acc!=NULL)	//처음엔 널이니까 while 노상관 
	{
		acc = acc->next;
	}
	acc = (struct account*)malloc(sizeof(struct account));
	
	printf("\n[계좌개설]\n");
	printf("계좌ID : ");		scanf("%d", &acc->id);
	printf("이름 : ");			scanf("%s", acc->name);	
	printf("입금액: ");			scanf("%d", &acc->balance);
	
	return acc;
}*/
	
/*
void MakeAccount( struct account *acc)
{	
  struct account *newacc=(struct account *)malloc(sizeof(struct account));
  printf("\n계좌 ID: ");  	scanf("%d", &newacc->id);
  printf("이름 : "); 		scanf("%s", newacc->name); 	 
  printf("입금액 : ");  	scanf("%d", &newacc->balance);
//  newacc->next=acc->next;
  acc->next=newacc;
  newacc->next=NULL;
}*/

void DepositMoney(struct account **acc)
{
	int money2, id2;
	printf("\nID : ");		scanf("%d", &id2);
	
	for(; *acc!=NULL; acc=&(*acc)->next)
	{
		if((*acc)->id==id2)
	 	{
	 	printf("Deposit money: ");			scanf("%d", &money2);	
		(*acc)->balance+=money2;
		printf("\nDeposit completed\n");
		return;
		}
	}
	printf("\nInvalid ID\n");
	
	return;
}

void WithdrawMoney(struct account **acc)
{
	int money2, id2;
	printf("\nID : ");		scanf("%d", &id2);
	
	while(*acc!=NULL)
	{
		if((*acc)->id==id2)
		{	
			printf("Withdraw money : ");			scanf("%d", &money2);

			if((*acc)->balance<money2)
			{
				printf("\nLack of money\n");
				return;
			}
		
			(*acc)->balance-=money2;
			printf("\nWithdraw completed\n");
			
			return;
		}
		acc=&(*acc)->next;
	}
		printf("\nInvalid ID\n");
		return;
}

void AccInfo(struct account **acc)
{
	while(*acc!=NULL)
	{
	printf("\nID : %d\n", (*acc)->id);
	printf("Name : %s\n", (*acc)->name);
	printf("Balance : %d\n\n", (*acc)->balance);	
	acc=&(*acc)->next;
	}
}
/*
void MakeAccount( struct account **acc)
{
	struct account *curr = NULL, *prev = NULL;
		
	curr = (struct account *)malloc(sizeof(struct account));

	printf("\nID: ");			scanf("%d", &(curr)->id);
	printf("Name : "); 			scanf("%s", (curr)->name); 
    printf("Deposit money : "); scanf("%d", &(curr)->balance);	
	
	(curr)->next = NULL;

	if(prev == NULL)
		*acc = curr; 
	else 
		prev->next = curr;

	prev = (curr);
}*/
void MakeAccount( struct account **acc)
{
	struct account *newacc;
	newacc = (struct account *)malloc(sizeof(struct account));	
	
	printf("\nID: ");			scanf("%d", &(newacc)->id);
	printf("Name : "); 			scanf("%s", (newacc)->name); 
    printf("Deposit money : "); scanf("%d", &(newacc)->balance);	

	newacc->next=*acc;
	*acc=newacc;
	
//함수의 리턴 값으로 받을 수 있겠지만 이중 포인터로 넘겨서 받기도 합니다.
//*pHead 는 포인터변수가 가지고 있는 값(메모리 주소값 - 이중포인터 이므로) 입니다. 
//거기에 값을 쓰거나 읽을 수 있죠.
}

int main(void)
{
	struct account *acc=NULL;

	int num;
	while(1)
	{
		
 	 display();
	 scanf("%d", &num);
	
	 switch(num)
	 {
		case 1:
			MakeAccount(&acc);			break;		//acc는 로컬하니까 이중포인터 무조건		
		case 2:										//써야하는듯... 
			DepositMoney(&acc); 		break;		//반환된걸 받는게 아니라 void니까  
		case 3:
			WithdrawMoney(&acc); 		break;
		case 4:			
			AccInfo(&acc);				break;
		case 5:
			return 0;
	 }

	}
	
	//need to do deallocation.
	return 0;
}
