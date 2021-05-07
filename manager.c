

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int selectMenu()
{
   int menu;
   printf("\n*** People.c ***\n");
   printf("1. 명부 출력\n");
   printf("2. 인부 추가\n");
   printf("3. 인부 수정\n");
   printf("4. 인부 제거\n");
   printf("5. 출결 관리\n");
   printf("6. 보험 관리\n");
   printf("7. 검색\n");
   printf("8. 파일 저장\n");
   printf("0. 종료\n\n");
   printf("=> 원하는 버튼은? ");
   scanf("%d", &menu);
   return menu;
}

int addPeople(People *p)
{ // 제품을 추가하는 함수 2
   printf("새 인부의 이름은? \n>> ");
   scanf(" %[^\n]", p->name);
   printf("새 인부의 직급은(0:사장,1:과장,2:부장,3:말단,4:인턴,5:알바)? \n>> ");
   scanf(" %d", &p->tier);
   printf("새 인부의 출퇴근 현황은(1:출근,2:퇴근,3:야근,4:조퇴)? \n>> ");
   scanf(" %d", &p->work);
   return 1;
}

void readPeople(People p)
{ // 하나의 제품 출력 함수
   printf(" %6s ",p.name);
   printtier(p.tier);
   printwork(p.work);
   printbohum(p.bohum);
}





void printList(int count, People **p)
{ // 전체 등록된 제품 리스트 출력 1
   int i = 0;
   printf("번호 이름  직급 출결   보험  \n");
   for (i = 0; i < count; i++)
   {
      if (p[i] == NULL)
         continue;
      printf("%2d ", i + 1);
      readPeople(*p[i]);
   }
}

void printtier(int tier)
{ // 하나의 제품 출력 함수
   if(tier==0){
      printf("사장 ");
   }
   else if(tier==1){
      printf("과장 ");
   }
   else if(tier==2){
      printf("부장 ");
   }
   else if(tier==3){
      printf("말단 ");
   }
   else if(tier==4){
      printf("인턴 ");
   }
   else if(tier==5){
      printf("알바 ");
   }
   else{
      printf("X");
   }
}

void printwork(int work){
   if(work==1){
      printf("출근");
   }
   else if(work==2){
      printf("퇴근");
   }
   else if(work==3){
      printf("야근");
   }
   else if(work==4){
      printf("조퇴");
   }
   else{
      printf("X");
   }

}

void printbohum(int bohym){
   if(bohym==1){
      printf(" 보험 처리\n");
   }
   else if(bohym==2){
      printf(" 정보 없음\n");
   }
   else{
      printf(" 정보 없음\n");
   }
}

int changePeople(People *p)
{ //제품 수정 3
   printf("새 인부 이름은?\n>> ");
   scanf(" %[^\n]", p->name);
   printf("새 인부의 출퇴근 현황은?(1:출근,2:퇴근,3:야근,4:조퇴)\n>> ");
   scanf(" %d", &p->work);
   printf("새 인부의  직급은(0:사장,1:과장,2:부장,3:말단,4:인턴,5:알바)?\n>> ");
   scanf(" %d", &p->tier);
   return 1;
}
int manage_attend(People *p)
{
   printf("출결 관리(1:출근, 2:퇴근, 3:야근, 4:조퇴)\n>> ");
   scanf("%d", &p->work);
   return 1;
}

int insuranceManage(People *p)
{
   printf("보험 신청(1: 보험처리, 2: 취소)\n>> ");
   scanf("%d", &p->bohum);
   return 1;
}

int deletePeople(People **p, int count)
{ // 제품 삭제 4
   int deleteok, no;
   printList(count, p);
   printf("삭제할 인부의 번호를 선택하시오.\n>> ");
   scanf(" %d", &no);
   printf("정말로 삭제하시겠습니까?(삭제:1)\n>> ");
   scanf("%d", &deleteok);
   if (deleteok == 1)
      free(p[no - 1]);
   p[no - 1] = NULL;
   count--;
   return count;
}

