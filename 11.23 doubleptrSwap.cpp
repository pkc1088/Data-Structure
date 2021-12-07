#include <stdio.h>

void swap_ptr(char **ppa, char **ppb);

int main(void){
	char *pa = "success"; // (.text)에 저장된 문자열 주소 저장
	char *pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb); //문자열 출력시 주소 불러옴.
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}
void swap_ptr(char **ppa, char **ppb){ //포인터 변수의 주소를 저장할 때 이중 포인터 사용.
	char *pt; //주소를 담는 변수 (문자열 주소를 담을 거라서)

	pt = *ppa; // = *(&pa) = pa = &문자열
	*ppa = *ppb;
	*ppb = pt;
}

void str_prn(char **sp) // 매개변수는 이중포인터변수
{
 while(*sp != 0) { // 포인터배열의 값이 널 포인터가 아닐 때 까지
  printf("%s\n", *sp); // 포인터배열이 연결하고 있는 문자열 출력
  sp++;
 }
}
