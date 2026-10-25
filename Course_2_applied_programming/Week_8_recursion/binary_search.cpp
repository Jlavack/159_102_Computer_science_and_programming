#include <iostream>
using namespace std;
int binarysearch(int first, int last, int search);
int loadsorteddata();
int id[500];
int total; // number of ID numbers in the array
int search; // the ID number that we are looking for
int index; // index of the ID number we are looking for
int main() {
 total = loadsorteddata();
 cout << "Enter an id to search for ";
 cin >> search;
 index = binarysearch(0, total - 1, search);
 if (index == -1) {
 cout << "The id " << search << " is not in the array.\n";
 } else {
 cout << "The id " << search << " is at index " << index << endl;
 }
}
int binarysearch(int first, int last, int search) {
//recursive search
// first = first index, last = last index
 int middle, result;
 if (first > last) {
 return -1; // the base case
 }
 result = -1;
 middle = (first + last) / 2;
 if (search == id[middle]) {
 result = middle;
 } else if (search > id[middle]) {
 result = binarysearch(middle + 1, last, search);
} else if (search < id[middle]) {
result = binarysearch(first, middle - 1, search);
}
return result;
}

int loadsorteddata() {
int num;
// load data in SORTED order - or load randomly and sort it
num = 6;
id[0] = 109;
id[1] = 220;
id[2] = 391;
id[3] = 528;
id[4] = 761;
id[5] = 846;
return num;
}
