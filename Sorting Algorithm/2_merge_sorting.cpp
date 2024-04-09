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
void merge_sort(int arr[], int left, int right){
	if(left >= right)
		return;
	int mid = left + right >> 1;
	merge_sort(arr, left, mid);			//采用递归将数组进行一分为二
	merge_sort(arr, mid + 1, right);
	
	int k = 0;
	int temp[right - left + 1] = { 0 };	//创建一个新数组来保存排序后的元素
	int i = left, j = mid + 1;
	while((i <= mid) && (j <= right)){	//若两个指针都没有到数组末尾，则取较小的元素赋给数组temp
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		} else{
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid) 				//若一个指针已经到末尾了，则将另一个指针后的元素直接依次复制给temp
		temp[k++] = arr[i++];
	while(j <= right) 
		temp[k++] = arr[j++];

	for(int p = 0; p < right - left + 1; p++){	//将排好序的temp赋给初始数组arr
		arr[left + p] = temp[p];
	}
}
