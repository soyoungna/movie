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

void* mv_genMvInfo(char* name, float score, int runTime, char* country)//main�Լ����� ���� ������ ����ü �ȿ� �ֱ� 
{
	movInfo_t* mvPtr; //����ü movInfo_t�� ������ mvPtr�� ��������. 
	
	mvPtr = (movInfo_t*) malloc(sizeof(movInfo_t));//�����޸� ���� 
	
	strcpy(mvPtr->name,name);//���ڿ� ���� ����ü�� name�� ���� ���� name�� ���� 
	strcpy(mvPtr->madeIn,country);
	mvPtr->runTime=runTime;//���ڵ��� ���ڿ� ���� �Լ��� �� �ʿ����. 
	mvPtr->score=score;

	
	return (void*)mvPtr;
}

void printMv(void* obj)//��ȭ���� ������ ����ϴ� �Լ� 
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

int mv_printAll(void* obj, void* arg)//��� ��ȭ������ ����ϴ� �Լ�. 
{
	printMv(obj);
	
	return;
}

int mv_printScore(void* obj, void* arg)//���� �Է��� �������� ���� �������� ��ȭ�� ����ϴ� �Լ�.  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
   if((*(float*)arg)<=mvPtr->score){
   	
   	printMv(obj);//void �����͸� float�����ͷ� ����ȯ�Ͽ���. 
   	printf("\n");
   }
   return;
}

int mv_printRunTime(void* obj, void* arg)//���� �Է��� runtime���� �� ��ȭ���� ����ϴ� �Լ�  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
   if((*(int*)arg)<=mvPtr->runTime){
   	
   	printMv(obj); //void �����͸� int�����ͷ� ����ȯ�Ͽ���.  
   	
   }
   return;
}

int mv_printCountry(void* obj, void* arg)//���� �Է��� Ư�� ������ ��ȭ���� ����ϴ� �Լ�  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
   if(!strcmp(arg,mvPtr->madeIn)){
   	
   	printMv(obj);
   	
   }
   return;
}



