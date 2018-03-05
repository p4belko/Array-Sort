int * allocate_arr(int *arr, int n){
	//TODO: code this
	//mozno calloc? (mal by zapisovat contiguous, mozno realnejsie casy bez pristupu na disk)
	arr = (int*)malloc(n*sizeof(int));
	return arr;
}

void fill_arr(int *arr1, int *arr2, int n, int scope){
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		//TODO: inak generovat random?
		//*(a+i) = i; 
		arr1[i] = rand() % scope + 1; 
		//printf("%d\n", arr1[i] );
		arr2[i] = arr1[i];
	}
}

int check_arr(int *arr, int n){
	//TODO: co keby sa tu vracal rovno idext
	// tj.. ak -1 == OK, inak >=0 tj, index zleho prvku
	for (int i = 0; i < n-1; ++i)
	{
		//printf("vs: %d %d\n", *(arr+i), *(arr+i+1) );
		if ( *(arr+i) > *(arr+i+1)) return i+1; //0->9
	}
	return -1;
}

void vypis_arr(int *arr, int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}

/*void allocate_arr(int **a, int **b, int n){
	//TODO: code this
	//mozno calloc? (mal by zapisovat contiguous, mozno realnejsie casy bez pristupu na disk)
	*a = (int*)malloc(n*sizeof(int));
	*b = (int*)malloc(n*sizeof(int));
}*/


/*
void check_arr(int *a, int n){
	//TODO: prepisat cele?
	int result;
	result = 1;

	for (int i = 0; i < n-1; ++i)
	{
		//printf("vs: %d %d\n", *(a+i), *(a+i+1) );
		if ( *(a+i) < *(a+i+1)) result = 0;
	}

	if (result) printf("je to ok\n");
	else printf("nope\n");
}
*/