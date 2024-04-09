/*
	input:
		arr[]:	array
		left:	The first sequence number of the array
		right:	The last sequence number of the array

	output:	null
	example:
		int n = 12;
    	int arr[n] = {3, 3, 1, 6, 2, 18, 5, 9, 2, 5, 4, 7};
		quickSort(arr, 0, n-1);
*/
/************************do-while****************************/
void quickSort(int arr[], int left, int right){
	if(left >= right)
		return;
	int i = left - 1, j = right + 1, x =arr[left + right >> 1];
	while(i < j){
		do i++; while(arr[i] < x);
		do j--; while(arr[j] > x);
		if(i < j)
			swap(arr[i], arr[j]);
	}
	quickSort(arr, left, j), quickSort(arr, j + 1, right);
}

/************************while-do****************************/
void quickSort(int arr[], int left, int right){
	if(left >= right)
		return;
	int i = left, j = right, x =arr[left + right >> 1];
	while(i < j){
		while(arr[i] < x)
			i++;
		while(arr[j] > x)
			j--;
		if(i < j){
			swap(arr[i], arr[j]);
			i++;j--;
		}
	}
	quickSort(arr, left, j), quickSort(arr, j + 1, right);
}
