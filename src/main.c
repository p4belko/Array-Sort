#include <stdio.h>
#include <time.h>		
#include <stdlib.h>		//rand() srand()
//#include <stdbool.h>	//bool 
//poukazat na neschopnost C ze nema bool 

#include "array.c"
#include "sort.c"

void show_menu(){
	printf(">>>>>>>>>MENU<<<<<<<<<\n");
	printf("s - spustit program sekvencne\n");  //start
	printf("c - vytvorit pole\n");				//create
	printf("p - vypisat pole\n");				//print
	printf("d - zoradit pole\n");				//do sort
	printf("t - kontrola pola\n");				//test
	printf("e - koniec\n");						//end
}


void start(){
	//TODO: tu sa spusti vytvorenie, naplnenie, sort, check vypis;

}
void create(int **arr1, int **arr2, int n, int x){
	//printf("SMERNIKY_predalloc\n");
	//printf("%d %d\n", *arr1,*arr2);
	*arr1 = allocate_arr(*arr1,n);
	*arr2 = allocate_arr(*arr2,n);
	//printf("SMERNIKY_poalloc\n");
	//printf("%d %d\n", *arr1,*arr2);

	fill_arr(*arr1,*arr2,n,x);

	//printf("SMERNIKY_create\n");
	//printf("%d %d\n", *arr1,*arr2);
	//printf("%d %d\n", *arr1,*arr2);
	//printf("%d %d\n", &arr1, &arr2);
	//printf("---------------\n");



}
void print(int *arr1, int *arr2, int n){
	//TODO: vypise sa pole
	printf("ARR1:\n");
	vypis_arr(arr1,n);
	printf("\n\nARR2:\n");
	vypis_arr(arr2,n);
	printf("\n");
	/*printf("SMERNIKY2222\n");
	printf("%p %p\n", arr1,arr2);
	printf("%d %d\n", arr1,arr2);
	printf("%d %d\n", *arr1,*arr2);
	printf("%p %p\n", *arr1,*arr2);
	printf("%p %p\n", &arr1, &arr2);
	printf("%d %d\n", &arr1, &arr2);
	printf("---------------\n");*/

}
void sort(int **arr1, int **arr2, int n){
	//TODO: sortc
	
		
	/*TEST SORTING*/
	/*Shell sort*/
	clock_t time;
	time = clock();
	shell_sort(*arr1,n);
	time = clock() - time;
	if (check_arr(*arr1,n)){
		printf("Pole[1] je zoradene (0->9)\n");
	}
	else{
		printf("Pole[1] NIE JE zoradene\n");
	}
	//avg_time1 = avg_time1 + time;
	printf("SHELLSORT trval %f \n", ((float)time)/CLOCKS_PER_SEC);
	
	/*Insertion sort*/
	time = clock();
	insertion_sort(*arr2,n);
	time = clock() - time;
	if (check_arr(*arr2,n)){
		printf("Pole[2] je zoradene (0->9)\n");
	}
	else{
		printf("Pole[2] NIE JE zoradene\n");
	}
	//avg_time2 = avg_time2 + time;
	printf("INSERTIONSORT trval %f \n\n", ((float)time)/CLOCKS_PER_SEC);
}
void test(){
	//TODO: test
}
void end(){
	//TODO: end
}






int main()
{
	clock_t time;

	int *p_arr1, *p_arr2;
	int n= 0,count;

	float avg_time1 = 0.0, avg_time2 = 0.0;
	int x = 50; // rand( 0-50)
	char singleLine[150];
	char menu_option;

	//TODO: file 
	/*FILE *file_vysledky;

  	file_vysledky = fopen ("vysledky12.txt", "r");

  	while(!feof(file_vysledky)){
  		fgets(singleLine, 150, file_vysledky);
  		puts(singleLine);
  	}
	fclose(file_vysledky);*/

	show_menu();
	while (1){
		menu_option = getchar();
		
		if(menu_option == 's'){
			return 1;
		}else if (menu_option == 'c'){

			//printf("SMERNIKY_main\n");
			//printf("%d %d\n", p_arr1, p_arr2);

			printf("Pocet prvkov v poli:\n");
			scanf("%d", &n);
			printf("Zadajte hornu hranicu generovanych cisel:\n");
			scanf("%d", &x);
			create(&p_arr1, &p_arr2, n, x);

			//printf("SMERNIKY_main2\n");
			//printf("%d %d\n", p_arr1,p_arr2);



			printf("C - DONE\n");
		}else if (menu_option == 'p'){
			if (!n){
					printf("Najskor vytvorte pole.\n");
					continue;
			}
			print(p_arr1, p_arr2, n);
			printf("P - DONE\n");
		}else if (menu_option == 'd'){
			if (!n){
					printf("Najskor vytvorte pole.\n");
					continue;
			}
			sort(&p_arr1, &p_arr2, n);
			printf("D - DONE\n");
		}else if (menu_option == 't'){
			;
		}else if (menu_option == 'e'){
			;
		}
	}
			/*case 'c': 
				
			case 'p': 
				//nova funkcia by vyzerala len takto
				if (!n){
					printf("Najskor vytvorte pole.\n");
					break;
				}
				print(p_arr1, p_arr2, n);
				
				
				//p_arr1 = allocate_arr(p_arr1,n);
				//p_arr2 = allocate_arr(p_arr2,n);
				printf("P - DONE\n");
			case 'd': 
				if (!n){
					printf("Najskor vytvorte pole.\n");
					break;
				}
				sort(p_arr1, p_arr2, n);
			case 't': 
				return 1;
			case 'e': 
				return 1;
			default: printf("ineeeee\n");

		}
	}*/

	/*printf("Pocet prvkov v poli:\n");
	scanf("%d", &n);
	printf("Zadajte hornu hranicu generovanych cisel:\n");
	scanf("%d", &x);
	printf("Zadajte pocet opakovani:\n");
	scanf("%d", &count);
	printf("\n");

	if (n < 1 || count < 1 || x < 1) {			
		printf("Nespravne zadane vstupy.\n");
		return 0;
	}*/
	
	/* CREATE ARRAY AND FILL WITH RANDOM NUMBERS */
	//allocate_arr(&p_arr1,&p_arr2,n);
	/*p_arr1 = allocate_arr(p_arr1,n);
	p_arr2 = allocate_arr(p_arr2,n);

	for (int i = 0; i < count; ++i)
	{
		fill_arr(p_arr1,p_arr2,n,x);
*/
		/*TEST SORTING*/
		/*Shell sort*/
	/*	time = clock();
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
		/*
		/*Insertion sort*/
		/*time = clock();
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
	}*/
		
	/* PRINT OUT */
	/*printf("___________________________\n");
	printf("---------SHELLSORT---------\n");
	printf("Priemerny cas: %f\n",(((float)avg_time1)/CLOCKS_PER_SEC)/count);
	printf("___________________________\n");
	printf("-------INSERTIONSORT-------\n");
	printf("Priemerny cas: %f\n",(((float)avg_time2)/CLOCKS_PER_SEC)/count);
	*/
	
	printf("ARR1:\n");
	vypis_arr(p_arr1,n);
	printf("\n\nARR2:\n");
	vypis_arr(p_arr2,n);
	

	//fly you fool
	free(p_arr1);
	free(p_arr2);

	getchar();
	return 1;
}