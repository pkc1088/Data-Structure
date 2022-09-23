/*
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 노드 타입
	int coef;
	int expon;
	struct ListNode *link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
	int size;
	ListNode *head;
	ListNode *tail;
} ListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create()
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터
// coef는 계수, 
// expon는 지수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	} else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) 
				insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  // a의 차수 == b의 차수 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {					// a의 차수 < b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d", p->coef, p->expon);
		if(!(p->link))
			break;
		printf(" + ");
	}
	printf("\n");
}

int main(void)
{
	ListType *list1, *list2, *list3;

	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();

	// 다항식 1을 생성 
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// 다항식 2를 생성 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);
}
*/




#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
	float coef;	// 밑
	int expon;	// 제곱
} polynomial;
polynomial terms1[MAX_TERMS];
polynomial terms2[MAX_TERMS];
polynomial terms3[MAX_TERMS];

static int cnt = 0;

char compare(int a, int b)
{
	if (a>b) return '>';
	else if (a == b) return '=';
	else return '<';
}

void attach(float coef, int expon)
{
	/*
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}*/
	terms3[cnt].coef = coef;
	terms3[cnt].expon = expon;
	cnt++;
}

// C = A + B, As는 배열 start, Ae는 배열 end
void poly_add2(int As, int Ae, int Bs, int Be)
{
	float tempcoef;
	while (As <= Ae && Bs <= Be)
		switch (compare(terms1[As].expon, terms2[Bs].expon)) {
		case '>': 	// A의 차수 > B의 차수
			attach(terms1[As].coef, terms1[As].expon);
			As++;			
			break;

		case '=': 	// A의 차수 == B의 차수
			tempcoef = terms1[As].coef + terms2[Bs].coef;
			if (tempcoef != 0)
				attach(tempcoef, terms1[As].expon);
			As++; Bs++;		
			break;

		case '<': 	// A의 차수 < B의 차수
			attach(terms2[Bs].coef, terms2[Bs].expon);
			Bs++;			
			break;
		}
	for (; As <= Ae; As++)
		attach(terms1[As].coef, terms1[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms2[Bs].coef, terms2[Bs].expon);
	
	cnt--;
}

void print_poly()
{
	for (int i = 0; i < cnt; i++)
		printf("%3.1fx^%d + ", terms3[i].coef, terms3[i].expon);
	printf("%3.1fx^%d\n", terms3[cnt].coef, terms3[cnt].expon);
}

int main(void)
{
	int len1, len2;

	scanf("%d", &len1);
	for(int i = 0; i < len1; i++)
		scanf("%f %d", &terms1[i].coef, &terms1[i].expon);
	scanf("%d", &len2);
	for(int i = 0; i < len2; i++)
		scanf("%f %d", &terms2[i].coef, &terms2[i].expon);

	poly_add2(0, len1, 0, len2);

	print_poly();
	return 0;
}




/*

#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct { 			// 다항식 구조체 타입 선언
	int degree;			// 다항식의 차수
	float coef[MAX_DEGREE];	// 다항식의 계수
} polynomial;

// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;				// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {			// B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i>0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

// 주함수
int main(void)
{
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("---------------------------------------\n");
	print_poly(c);
	return 0;
}
*/


////////////////////////

#include <vector>
#include <algorithm>
#include <iostream>
 
#define RESET_COLOR "\033[0m"
#define GREEN  "\033[32m"
 
using namespace std;
 
class Term
{
    friend class Polynomial;
private:
    float coef;
    int exp;
};
 
class Polynomial {
public:
    Polynomial();
    Polynomial Add(Polynomial b);
    Polynomial Substraction(Polynomial b);
    Polynomial Multiplication(Polynomial b);
    void NewTerm(const float theCoeff, const int theExp);
    int Display();
    void GetData();
private:
    static Term *termArray;
    static int capacity;
    static int free;
    int terms;
    int start, finish;
    void ClearTerm(int startPos, int endPos);
};
 
Polynomial::Polynomial() {
    terms = 0;
}
 
int Polynomial::Display() {
    int aPos = start;
    for (; aPos <= finish; aPos++) {
        cout << termArray[aPos].coef << "x^" << termArray[aPos].exp;
        if (aPos != finish && termArray[aPos].coef > 0)
            cout << "+";
    }
    cout << "\n";
    return 0;
}
 
void Polynomial::GetData() {
    start = free;
 
    float theCoeff;
    int theExp;
    int pos = start;
    int answer;
 
    while (1) {
        cout << "Enter Coefficient of the term : ";
        cin >> theCoeff;
        cout << "Enter Exponent of the term : ";
        cin >> theExp;
 
        NewTerm(theCoeff, theExp);
 
        cout << "Do you want to input next term?\n[Yes = 1, No = 0] : ";
        cin >> answer;
        if (termArray[pos].exp == 0 || answer == 0) {
            break;
        }
        else {
            pos++;
        }
    }
    finish = pos;
}
 
void Polynomial::ClearTerm(int startPos, int endPos) {
    Term *temp = new Term[capacity];
    Term *resultTerm = new Term[free - endPos];
 
    copy(termArray + endPos + 1, termArray + free, resultTerm);
    copy(termArray, termArray + startPos, temp);
    copy(resultTerm, resultTerm + (free - endPos - 1), temp + startPos);
 
    delete[] termArray;
    delete[] resultTerm;
    termArray = temp;
 
    free = endPos;
    finish = free - 1;
}
 
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    if (free == capacity)
    {
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray + free, temp);
        delete[] termArray;
        termArray = temp;
    }
    termArray[free].coef = theCoeff;
    termArray[free++].exp = theExp;
 
    terms++;
}
 
Polynomial Polynomial::Add(Polynomial b)
{
    Polynomial c;
    int aPos = start;
    int bPos = b.start;
    int aTerms = start + terms;
    int bTerms = b.start + b.terms;
 
    c.start = free;
 
    while ((aPos < aTerms) && (bPos < bTerms))
        if ((termArray[aPos].exp == termArray[bPos].exp))
        {
            float t = termArray[aPos].coef + termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if ((termArray[aPos].exp < termArray[bPos].exp))
        {
            c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
            bPos++;
        }
        else
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
 
    for (; aPos < aTerms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for (; bPos < bTerms; bPos++)
        c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
    c.finish = free - 1;
    return c;
}
 
Polynomial Polynomial::Substraction(Polynomial b)
{
    Polynomial c;
    int aPos = start;
    int bPos = b.start;
    int aTerms = start + terms;
    int bTerms = b.start + b.terms;
    c.start = free;
 
    while ((aPos < aTerms) && (bPos < bTerms))
        if ((termArray[aPos].exp == termArray[bPos].exp))
        {
            float t = termArray[aPos].coef - termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if ((termArray[aPos].exp < termArray[bPos].exp))
        {
            c.NewTerm(-termArray[bPos].coef, termArray[bPos].exp);
            bPos++;
        }
        else
        {
            c.NewTerm(-termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
 
    for (; aPos < aTerms; aPos++)
        c.NewTerm(-termArray[aPos].coef, termArray[aPos].exp);
    for (; bPos < bTerms; bPos++)
        c.NewTerm(-termArray[bPos].coef, termArray[bPos].exp);
    c.finish = free - 1;
    return c;
}
 
Polynomial Polynomial::Multiplication(Polynomial b)
{
    Polynomial c;
    int aPos = start;
    int aTerms = start + terms;
    int bTerms = b.start + b.terms;
    c.start = free++;
 
    for (; aPos < aTerms; aPos++) {
        Polynomial k, r;
        r = c;
        k.start = c.terms ? c.start + c.terms : (c.start + c.terms + 1);
 
        for (int bPos = b.start; bPos < bTerms; bPos++) {
            float multCoef = termArray[aPos].coef * termArray[bPos].coef;
            int multExp = termArray[aPos].exp + termArray[bPos].exp;
            k.NewTerm(multCoef, multExp);
            k.finish = free - 1;
        }
        r = r.Add(k);
        c.finish = k.start - 1;
        c.terms = r.terms;
        c.ClearTerm(c.start, k.finish);
    }
    return c;
}
 
int Polynomial::capacity = 1;
Term *Polynomial::termArray = new Term[capacity];
int Polynomial::free = 0;
 
int main() {
    int choice;
 
    Polynomial P1, P2, P3;
    cout << "Instruction:- \nExample:-\nP(x)=5x^3+3x^1\nEnter the Polynomial like\nP(x)=5x^3+0x^2+3x^1+0x^0\n";
    cout << "Enter Polynomial1:-" << endl;
    P1.GetData();
    cout << "Enter Polynomial2:-" << endl;
    P2.GetData();
 
    while (1) {
        cout << "\n****** Menu Selection ******" << endl;
        cout << "1: Addition\n2: Substraction\n3: Multiplication\n0: Exit" << endl;
        cout << "Enter ypur choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\n--------------- Addition ---------------\n";
            cout << "Polynomial1:";
            P1.Display();
            cout << "Polynomial2:";
            P2.Display();
            P3 = P1.Add(P2);
            cout << "Result :";
            P3.Display();
            cout << "----------------------------------------\n";
            break;
        case 2:
 
            cout << "\n------------- Substraction -------------\n";
            cout << "Polynomial1:";
            P1.Display();
            cout << "Polynomial2:";
            P2.Display();
            P3 = P1.Substraction(P2);
            cout << "Result :";
            P3.Display();
            cout << "----------------------------------------\n";
            break;
        case 3:
            cout << "\n----------- Multiplication -------------\n";
            cout << "Polynomial1:";
            P1.Display();
            cout << "Polynomial2:";
            P2.Display();
            P3 = P1.Multiplication(P2);
            cout << "Result :";
            P3.Display();
            cout << "----------------------------------------\n";
            break;
        case 0:
            cout << "Good Bye...!!!" << endl;
            exit(0);
        }
    }
    return 0;
}
 

