#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"


typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;

void* mv_genMvInfo(char* name, float score, int runTime, char* country)//main함수에거 받은 정보를 구조체 안에 넣기 
{
	movInfo_t* mvPtr; //구조체 movInfo_t를 포인터 mvPtr로 선언해줌. 
	
	mvPtr = (movInfo_t*) malloc(sizeof(movInfo_t));//동적메모리 선언 
	
	strcpy(mvPtr->name,name);//문자열 복사 구조체의 name이 내가 받은 name과 같다 
	strcpy(mvPtr->madeIn,country);
	mvPtr->runTime=runTime;//숫자들은 문자열 복사 함수를 쓸 필요없음. 
	mvPtr->score=score;

	
	return (void*)mvPtr;
}

void printMv(void* obj)//영화들의 정보를 출력하는 함수 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	printf("\n");
	
	return;
}

int mv_printAll(void* obj, void* arg)//모든 영화정보를 출력하는 함수. 
{
	printMv(obj);
	
	return;
}

int mv_printScore(void* obj, void* arg)//내가 입력한 점수보다 높은 점수들의 영화를 출력하는 함수.  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
   if((*(float*)arg)<=mvPtr->score){
   	
   	printMv(obj);//void 포인터를 float포인터로 형변환하였다. 
   	printf("\n");
   }
   return;
}

int mv_printRunTime(void* obj, void* arg)//내가 입력한 runtime보다 긴 영화들을 출력하는 함수  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
   if((*(int*)arg)<=mvPtr->runTime){
   	
   	printMv(obj); //void 포인터를 int포인터로 형변환하였다.  
   	
   }
   return;
}

int mv_printCountry(void* obj, void* arg)//내가 입력한 특정 나라의 영화들을 출력하는 함수  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
   if(!strcmp(arg,mvPtr->madeIn)){
   	
   	printMv(obj);
   	
   }
   return;
}



