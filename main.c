#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"
int main(int argc, char *argv[]) {
	
	FILE *fp;  
	char name[200]; 
	char country[10]; 
	int runTime; 
	float score; 
	
	int exit_flag = 0; 
	int option; 
	void *list, *mvInfo; 
	int (*repFunc)(void* obj, void* arg); 
	void *arg; 
	int cnt; 
	 
    fp=fopen("movie.dat","r");//파일 열기 
	
	list = list_genList();//liked list를 만든다고 선언 
	
	while (fscanf(fp,"%s %s %d %f ", name, country, &runTime, &score) != EOF )//파일을 읽기 문자열을 name,country,runTime,score로 받아 놓기 그리고 node하나 추가
	  
	{	
	 
	     mvInfo = mv_genMvInfo(name,score,runTime,country);
	     
	     list_addTail(mvInfo, list);
	     
	 
	}

	fclose(fp);
	
	printf("\n reading done! find %i movies! \n\n\n",list_len(list));
	
	while(exit_flag == 0)//main menu 만들기  
	{
	    printf("----------------MENU----------------\n");
		printf("1.print all the movies\n");
		printf("2.search for specific country movies\n");
		printf("3.search for specific runTime movies\n");	
		printf("4.search for specific score movies\n");
		printf("5.exit\n");
		
		printf("select an option : ");//option 1,2,3,4,5중에서 받기 switch함수로 넘어간다. 
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: 
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				repFunc = mv_printAll; //repFunc 포인터가 mv_printAll함수와 같다. 
				arg = NULL;
				list_repeatFunc(repFunc,arg,list);//위 함수들 실행.  
				break;
				
			case 2: 
                printf("input a country : ");//country받기  
                scanf("%s",country);
                printf("----------------------------------------\n");
                
                repFunc = mv_printCountry;
                arg=country;//내가 쓴 country가 arg 포인터로 넘어감.  
                list_repeatFunc(repFunc,arg,list);
                
				break;
				
			case 3: 

                printf("input a runTime : ");//runTime 받기,내가쓴 runTime보다 큰 영화들이 출력될 것이다. 
                scanf("%i",&runTime);
                
                repFunc = mv_printRunTime;
                arg = &runTime;
                list_repeatFunc(repFunc,arg,list);

				break;
				
			case 4: 
				printf("input a score : ");//score받기, 내가 입력한 score보다 높은 영화들이 출력된다.  
                scanf("%f",&score);
                
				repFunc = mv_printScore;
				arg = &score;
				list_repeatFunc(repFunc,arg,list);
				
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		

	}
	
	return 0;
}
