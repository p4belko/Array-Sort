int * allocate_arr(int *arr, int n){
	arr = (int*)malloc(n*sizeof(int));
	return arr;
}

void fill_arr(int *arr1, int *arr2, int n, int scope){
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr1[i] = rand() % scope + 1; 
		arr2[i] = arr1[i];
	}
}

int check_arr(int *arr, int n){
	for (int i = 0; i < n-1; ++i)
	{
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
