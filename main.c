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
	 
    fp=fopen("movie.dat","r");
	
	
	list = list_genList();
	
	 

	while (fscanf(fp,"%s %s %d %f ", name, country, &runTime, &score) != EOF )
	{	
	 
	     mvInfo = mv_genMvInfo(name,score,runTime,country);
	     
	     list_addTail(mvInfo, list);
	     
	 
	}

	fclose(fp);
	
	printf("reading done ! find %i movies \n\n\n",list_len(list));
	
	while(exit_flag == 0)
	{
	    printf("-------------MENU-------------\n");
		printf("1.print all the movies\n");
		printf("2.search for specific country movies\n");
		printf("3.search for specific runTime movies\n");	
		printf("4.search for specific score movies\n");
		printf("5.exit\n");
		
		printf("select an option : ");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: 
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				repFunc = mv_printAll;
				arg = NULL;
				list_repeatFunc(repFunc,arg,list);
				break;
				
			case 2: 
                printf("input a country : ");
                scanf("%s",country);
                printf("----------------------------------------\n");
                
                repFunc = mv_printCountry;
                arg=country;
                list_repeatFunc(repFunc,arg,list);
				break;
				
			case 3: 

                printf("input a runTime : ");
                scanf("%i",&runTime);
                
                repFunc = mv_printRunTime;
                arg = &runTime;
                list_repeatFunc(repFunc,arg,list);
                

				break;
				
			case 4: 
				printf("input a score : ");
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
