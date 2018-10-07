void shell_sort(int *arr, int n){

	int i, j, k, tmp;
    for (i = n / 2; i > 0; i = i / 2)
    {
        for (j = i; j < n; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k]){
                    break;
                }   
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }

}

void insertion_sort(int *arr, int n){

   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}