#include <stdio.h>
#include <time.h>		
#include <stdlib.h>		//rand() srand()
//#include <stdbool.h>	//bool 
//poukazat na neschopnost C ze nema bool 
//#include "cJSON.h"
#include "array.c"
#include "sort.c"

void show_menu(){
	printf(">>>>>>>>>MENU<<<<<<<<<\n");
	printf("r - spustit program sekvencne\n");  //run
	printf("c - vytvorit pole\n");				//create
	printf("p - vypisat pole\n");				//print
	printf("s - zoradit pole\n");				//sort
	printf("t - kontrola pola\n");				//test
	printf("m - menu\n");						//menu
	printf("e - koniec\n");						//end
}
void run(int **arr1, int **arr2, int n, int x, int count){
	//TODO: tu sa spusti vytvorenie, naplnenie, sort, check vypis;
	//ma to: vypytat pocet opakovani, velkost pola, ohranicenia generovania, 
	// a potom v cykle plnit tieto polia a triedit  a vysledny cas 
	//zapisat do suboru	

	int test_result;
	float avg_time1 = 0.0, avg_time2 = 0.0;
	
	time_t current_time;
    char* c_time_string;

    FILE *file_vysledky;
    /*char *out;
   	cJSON *root, *runs, *run;*/

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

  	file_vysledky = fopen ("history.log", "a");
	/*char singleLine[150];
  	while(!feof(file_vysledky)){
  		fgets(singleLine, 150, file_vysledky);
  		puts(singleLine);
  	}*/
	
	*arr1 = allocate_arr(*arr1,n);
	*arr2 = allocate_arr(*arr2,n);
	
	for (int i = 0; i < count; ++i)
	{
		fill_arr(*arr1,*arr2,n,x);
		
		clock_t time;
		/*TEST SORTING*/
		/*Shell sort*/
		time = clock();
		shell_sort(*arr1,n);
		time = clock() - time;

		
		test_result = check_arr(*arr1,n);
		if (test_result == -1){
			printf("Pole[%d] je zoradene (0->9)\n", i);
		}
		else{
			printf("Pole[%d] NIE JE zoradene\n", i);
		}
		avg_time1 = avg_time1 + time;
		printf("SHELLSORT trval %f \n", ((float)time)/CLOCKS_PER_SEC);
		
		/*Insertion sort*/
		time = clock();
		insertion_sort(*arr2,n);
		time = clock() - time;

		test_result = check_arr(*arr2,n);
		if (test_result == -1){
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


	/*PRINT INTO FILE*/

	fprintf(file_vysledky, "Date: \t\t\t %s", c_time_string);
	fprintf(file_vysledky, "n: \t\t\t\t %d\n", n);
	fprintf(file_vysledky, "x: \t\t\t\t %d\n", x);
	fprintf(file_vysledky, "count: \t\t\t %d\n", count);
	fprintf(file_vysledky, "shell_sort: \t %f\n", (((float)avg_time1)/CLOCKS_PER_SEC)/count);
	fprintf(file_vysledky, "insertion_sort:  %f\n", (((float)avg_time2)/CLOCKS_PER_SEC)/count);
	fprintf(file_vysledky, "-------------------------------------------------------\n");
	fclose(file_vysledky);

	/*CREATE JSON*/
	/* create root node and array */
	//root = cJSON_CreateObject();
	//runs = cJSON_CreateArray();
	/* add cars array to root */
	//cJSON_AddItemToObject(root, "runs", runs);
    /* add 1st car to cars array */
    /*cJSON_AddItemToArray(runs, run = cJSON_CreateObject());
    cJSON_AddItemToObject(run, "Date", cJSON_CreateString(c_time_string));
    cJSON_AddItemToObject(run, "n", cJSON_CreateString(n));
    cJSON_AddItemToObject(run, "x", cJSON_CreateString(x));
    cJSON_AddItemToObject(run, "count", cJSON_CreateString(count));
    cJSON_AddItemToObject(run, "shell_sort", cJSON_CreateString((((float)avg_time1)/CLOCKS_PER_SEC)/count));
    cJSON_AddItemToObject(run, "insertion_sort", cJSON_CreateString((((float)avg_time1)/CLOCKS_PER_SEC)/count));
    
    out = cJSON_Print(root);
    printf("%s\n",out);
	*/
}
void create(int **arr1, int **arr2, int n, int x){
	*arr1 = allocate_arr(*arr1,n);
	*arr2 = allocate_arr(*arr2,n);
	fill_arr(*arr1,*arr2,n,x);
}
void print(int *arr1, int *arr2, int n){
	//TODO: vypise sa pole
	printf("ARR1:\n");
	vypis_arr(arr1,n);
	printf("\n\nARR2:\n");
	vypis_arr(arr2,n);
	printf("\n");
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
void test(int **arr1, int **arr2, int n){
	//TODO: test
	//TODO: print index, print into file? - mozno staci iba pri automatickom spusteni
	int test_result;

	test_result = check_arr(*arr1,n);
	if (test_result == -1){
		printf("Pole[1] je zoradene (0->9)\n");
	}
	else if(test_result >= 0){
		printf("Pole[1] NIE JE zoradene\nPrvy chybny prvok na indexe:  %d\n", test_result);   
	}

	test_result = check_arr(*arr2,n);
	if (test_result == -1){
		printf("Pole[2] je zoradene (0->9)\n");
	}
	else if(test_result >= 0){
		printf("Pole[2] NIE JE zoradene\nPrvy chybny prvok na indexe:  %d\n", test_result);   
	}
}

int main()
{
	//clock_t time;

	int *p_arr1, *p_arr2;
	int n = 0,count;
	int x = 50; // rand( 0-50)
	
	char menu_option;

	show_menu();
	while (1){
		menu_option = getchar();
		
		if(menu_option == 'r'){
			printf("Pocet prvkov v poli:\n");
			scanf("%d", &n);
			printf("Zadajte hornu hranicu generovanych cisel:\n");
			scanf("%d", &x);
			printf("Zadajte pocet opakovani:\n");
			scanf("%d", &count);
			run(&p_arr1, &p_arr2, n, x, count);
			printf("R - DONE\n");
			//return 1;
		}else if (menu_option == 'c'){
			printf("Pocet prvkov v poli:\n");
			scanf("%d", &n);
			printf("Zadajte hornu hranicu generovanych cisel:\n");
			scanf("%d", &x);
			create(&p_arr1, &p_arr2, n, x);
			printf("C - DONE\n");
		}else if (menu_option == 'p'){
			if (!n){
					printf("Najskor vytvorte pole.\n");
					continue;
			}
			print(p_arr1, p_arr2, n);
			printf("P - DONE\n");
		}else if (menu_option == 's'){
			if (!n){
					printf("Najskor vytvorte pole.\n");
					continue;
			}
			sort(&p_arr1, &p_arr2, n);
			printf("D - DONE\n");
		}else if (menu_option == 't'){
			if (!n){
					printf("Najskor vytvorte pole.\n");
					continue;
			}
			test(&p_arr1, &p_arr2, n);
			printf("T - DONE\n");
		}else if (menu_option == 'm'){
			show_menu();
		}else if (menu_option == 'e'){
			break;
		}
	}
			
	//fly you fool
	free(p_arr1);
	free(p_arr2);
	return 1;
}