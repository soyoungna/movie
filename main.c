#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"
int main(int argc, char *argv[]) {
	
	FILE *fp;  //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
	
	 
    fp=fopen("movie.dat","r");//파일 오픈
	
	
	list = list_genList();//
	
	//파일읽기  

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
		printf("3.search for specific runTime movies\n");	//2.1 print menu message and get input option
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
                printf("input a country : \n");
                scanf("%s",country);
                printf("----------------------------------------\n");
                
                repFunc = mv_printCountry;
                arg=country;
                list_repeatFunc(repFunc,arg,list);
				break;
				
			case 3: //print movies with long runtime


                repFunc = mv_printRunTime;
                arg = runTime;
                list_repeatFunc(repFunc,arg,list);
                

				break;
				
			case 4: //print movies with high score
				
				repFunc = mv_printScore;
				arg=score;
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
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}
