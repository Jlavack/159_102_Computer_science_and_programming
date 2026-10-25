// Implement iterative Binary Search

#include <iostream>
using namespace std;

// A iterative binary search function. It returns
// location of key in given array arr[low...high] if present,
// otherwise -1
int binarySearch(int arr[], int low, int high, int key){
	while (low <= high) {
		int mid = low + (high - low) / 2;

		// Check if key is present at mid
		if (arr[mid] == key)
			return mid;

		// If key greater, ignore left half
		if (arr[mid] < key)
			low = mid + 1;

		// If key is smaller, ignore right half
		else
			high = mid - 1;
	}

	// if we reach here, then element was not present
	return -1;
}

int main(void)
{
	int arr[] = {10,14,19,26,27,31,33,35,42,44};
	int key = 44;
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, size - 1, key);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element " << key << " is found at index " << result << endl;
	return 0;
}
