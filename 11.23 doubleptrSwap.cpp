#include <stdio.h>

void swap_ptr(char **ppa, char **ppb);

int main(void){
	char *pa = "success"; // (.text)�� ����� ���ڿ� �ּ� ����
	char *pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb); //���ڿ� ��½� �ּ� �ҷ���.
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}
void swap_ptr(char **ppa, char **ppb){ //������ ������ �ּҸ� ������ �� ���� ������ ���.
	char *pt; //�ּҸ� ��� ���� (���ڿ� �ּҸ� ���� �Ŷ�)

	pt = *ppa; // = *(&pa) = pa = &���ڿ�
	*ppa = *ppb;
	*ppb = pt;
}

void str_prn(char **sp) // �Ű������� ���������ͺ���
{
 while(*sp != 0) { // �����͹迭�� ���� �� �����Ͱ� �ƴ� �� ����
  printf("%s\n", *sp); // �����͹迭�� �����ϰ� �ִ� ���ڿ� ���
  sp++;
 }
}
