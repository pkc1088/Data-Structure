#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct subject {
   char *name; 					// 과목 이름
   double score; 				// 과목 점수
}SUBJ;

typedef struct student {
   char *name; 					// 학생 이름
   char id[5]; 					// 학생 학번
   int numSubject; 				// 과목 개수
   struct subject *psub; 		// 과목 구조체 포인터
   double avg; 					// 모든 과목의 평균 점수
}STUD;

void save_subject(SUBJ *sb, char tmp_sbj[], int N);

int main() {
   int N;
   scanf("%d", &N);

   // 정보 입력 //
   STUD *st = (STUD*)malloc(sizeof(STUD) *N);
   char tmp_name[100] = "", tmp_sbj[100] = "";
   
   for (int i = 0; i < N; i++) 
   {
      scanf("%s", tmp_name);
      st[i].name = (char*)malloc(sizeof(char)*(strlen(tmp_name) + 1));
      strcpy(st[i].name, tmp_name);
      
	  scanf("%s", st[i].id);
      getchar();
      
	  gets(tmp_sbj);

      int N_cnt = 1;
	  for (int i = 0; tmp_sbj[i] != 0; i++) 
	  	if (tmp_sbj[i] == ' ') 
		  	N_cnt++;
	  st[i].numSubject = N_cnt/2;

      st[i].psub = (SUBJ*)malloc(sizeof(SUBJ)*st[i].numSubject);
      save_subject(st[i].psub, tmp_sbj, st[i].numSubject);
   }

   // 평균값 계산 //
   double avg = 0;
   for (int i = 0; i < N; i++) 
   {
      avg = 0;
      
	  for (int j = 0; j < st[i].numSubject; j++) 
         avg += st[i].psub[j].score;
      
      avg /= st[i].numSubject;
      st[i].avg = avg;
   }

   // 평균값 기준 내림차순 정리 //
   STUD tmp_stud;
   for (int i = 0; i < N - 1; i++) {
      for (int j = 0; j < N - 1 - i; j++) {
         if (st[j].avg < st[j + 1].avg) {
            tmp_stud = st[j];
            st[j] = st[j + 1];
            st[j + 1] = tmp_stud;
         }
      }
   }

   // 등수 입력 및 정보 출력(평균 내림차순) //
   int K;
   printf("\n등수입력\n"); 
   scanf("%d", &K);
   K--;

   int save_idx = 0;
   double max_score = -99999;
   for (int i = 0; i < st[K].numSubject; i++) {
      if (max_score < st[K].psub[i].score) {
         max_score = st[K].psub[i].score;
         save_idx = i;
      }
   }

   printf("%s %s %.2lf %s %.2lf", st[K].name, st[K].id, st[K].avg, 
   								  st[K].psub[save_idx].name, st[K].psub[save_idx].score);


}

void save_subject(SUBJ *sb, char tmp_sbj[], int N) 
{
   char tmp[3] = "", tmp_s[100]="", tmp_save[100][100] = { "" };
   int idx = 0;
  
   for (int i = 0; i < strlen(tmp_sbj)+1; i++) 
   {
      if ((tmp_sbj[i] == ' ' || tmp_sbj[i] == '\0')) 
	  {
         strcpy(tmp_save[idx], tmp_s); 						// 저장된 단어 복사하여 저장후
         idx++; 											//인덱스값 증가
         for (int j = 0; j < 99; j++) tmp_s[j] = '\0';
      }
      else 
	  {
         tmp[0] = tmp_sbj[i], tmp[1] = '\0';				 // 나머지의 경우는 단어 형성을 위한 작업을 한 뒤
         strcat(tmp_s, tmp);								 //기존의 임시변수에 접붙이기
      }
   }

   int idx1 = 0, idx2=0;
   for (int i = 0; i < N*2; i++) 
   {
      if (i % 2 == 0) 
	  {
         sb[idx1].name = (char*)malloc(sizeof(char)*(strlen(tmp_save[i]) + 1));
         strcpy(sb[idx1].name, tmp_save[i]);
         idx1++;
      }
      else 
	  {
         sb[idx2].score = atof(tmp_save[i]);
         idx2++;
      }
   }

}
