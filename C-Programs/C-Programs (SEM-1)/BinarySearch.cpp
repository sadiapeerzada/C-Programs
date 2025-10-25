#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
	while(low<=high) {
		int mid=low+(high-low)/2;
		
		if(arr[mid]==key){
			return mid;
		} else if(arr[mid]<key) {
			low= mid+1;
		} else{
			high=mid-1;
		}
	}
	return-1;
}
int main(){
	int arr[]={2,3,4,10,40};
	int key=10;
	int n=sizeof(arr)/sizeof(arr[0]);
	int result=binarySearch(arr,0,n-1,key);
	(result==-1)? printf("Element is not present in array\n")
	:printf("Element is present at index %d\n",result);
	   return 0;	
}

