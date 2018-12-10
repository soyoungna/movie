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
	char c;
	int i;
	//1. movie.dat 파일 읽기
	 
    fp=fopen("movie.dat","r");//파일 오픈
	
	
	list = list_genList();//
	
	//파일읽기  

	while (fscanf(fp,"%s %s %f %f ", &name, &country, &runTime, &score) != EOF )
	{	
	 
	     
	     printf("%s %s %f %f\n",name,country,runTime,score);
	 
	   // mvInfo = mv_genMvInfo();
	   
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
	//	list_addTail(mvInfo, list);
	}

	fclose(fp);//1.4 FILE close
	
	
	//2. program start
	while(exit_flag == 0)
	{
	    printf("-------------MENU-------------\n");
		printf("1.print all the movies\n");
		printf("2.search for specific country movies\n");
		printf("3.search for specific runtime movies\n");	//2.1 print menu message and get input option
		printf("4.search for specific score movies\n");
		printf("5.exit\n");
		
		printf("select an option : ");
		scanf("%i",&option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL;
				break;
				
			case 2: //print movies of specific country
                printf("select a country : \n");
                
                printf("----------------------------------------\n");
                
                repFunc = mv_getCountry;
				break;
				
			case 3: //print movies with long runtime

                repFunc = mv_getRunTime;
                
				break;
				
			case 4: //print movies with high score
				
				repFunc = mv_getScore;
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
