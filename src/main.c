#include <stdio.h>
#include <time.h>		
#include <stdlib.h>		//rand() srand()
//#include <stdbool.h>	//bool 
//poukazat na neschopnost C ze nema bool 

#include "array.c"
#include "sort.c"


int main()
{
	clock_t time;
	int *p_arr1, *p_arr2;
	int n,count;
	float avg_time1 = 0.0, avg_time2 = 0.0;
	int x = 50; // rand( 0-50)

	printf("Pocet prvkov v poli:\n");
	scanf("%d", &n);
	printf("Zadajte hornu hranicu generovanych cisel:\n");
	scanf("%d", &x);
	printf("Zadajte pocet opakovani:\n");
	scanf("%d", &count);
	printf("\n");

	if (n < 1 || count < 1 || x < 1) {			
		printf("Nespravne zadane vstupy.\n");
		return 0;
	}
	
	/* CREATE ARRAY AND FILL WITH RANDOM NUMBERS */
	//allocate_arr(&p_arr1,&p_arr2,n);
	p_arr1 = allocate_arr(p_arr1,n);
	p_arr2 = allocate_arr(p_arr2,n);

	for (int i = 0; i < count; ++i)
	{
		fill_arr(p_arr1,p_arr2,n,x);

		/*TEST SORTING*/
		/*Shell sort*/
		time = clock();
		shell_sort(p_arr1,n);
		time = clock() - time;
		if (check_arr(p_arr1,n)){
			printf("Pole[%d] je zoradene (0->9)\n", i);
		}
		else{
			printf("Pole[%d] NIE JE zoradene\n", i);
		}
		avg_time1 = avg_time1 + time;
		printf("SHELLSORT trval %f \n", ((float)time)/CLOCKS_PER_SEC);
		
		/*Insertion sort*/
		time = clock();
		insertion_sort(p_arr2,n);
		time = clock() - time;
		if (check_arr(p_arr2,n)){
			printf("Pole[%d] je zoradene (0->9)\n", i);
		}
		else{
			printf("Pole[%d] NIE JE zoradene\n",i);
		}
		avg_time2 = avg_time2 + time;
		printf("INSERTIONSORT trval %f \n\n", ((float)time)/CLOCKS_PER_SEC);
	}
		
	/* PRINT OUT */
	printf("___________________________\n");
	printf("---------SHELLSORT---------\n");
	printf("Priemerny cas: %f\n",(((float)avg_time1)/CLOCKS_PER_SEC)/count);
	printf("___________________________\n");
	printf("-------INSERTIONSORT-------\n");
	printf("Priemerny cas: %f\n",(((float)avg_time2)/CLOCKS_PER_SEC)/count);
	
	/*
	printf("ARR1:\n");
	vypis_arr(p_arr1,n);
	printf("\n\nARR2:\n");
	vypis_arr(p_arr2,n);
	*/

	//fly you fool
	free(p_arr1);
	free(p_arr2);

	getchar();
	getchar();
	getchar();
	getchar();
	return 1;
}