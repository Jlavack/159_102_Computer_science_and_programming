// Iteration and Recursive Code For Linear Search

#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int key){

//// Iteration approach
	// for(int i=0; i<size; i++){
	// 	if(arr[i] == key){
	// 		return i;
	// 	}
	// }
	// return -1;

//// Recursion approach
	size = size-1;
	if (size < 0){  // Base case - not found
		return -1;
	}
	if (arr[size] == key){  // Base case - found
		return size;
	}
	else{
		int ans = linearsearch(arr, size, key);
		return ans;
	}
}

int main() {
	int arr[10]={10,14,19,26,27,31,33,35,42,44};
	int key = 10;
	int ans = linearsearch(arr, 10, key);
	if(ans == -1 ){
		cout << "The element "<<key <<" is not found."<< endl;
	}else{
		cout << "The element "<<key <<" is found at "<<ans <<" index of the given array."<< endl;
	}
	return 0;
}
