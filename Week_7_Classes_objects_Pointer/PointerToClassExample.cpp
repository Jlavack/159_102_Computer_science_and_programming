// This example is from https://simplesnippets.tech/pointer-to-class-in-cpp/

#include <iostream>
using namespace std;

class Rectangle {
	private:
 		int length;
 		int breadth;
 	public:
 		Rectangle(int l, int b) {
 			length=l;
 			breadth=b;
		}
 		int getArea() {
 			return 2*length*breadth;
		}
};

int main() {
//// Pointer to Class
	// First approach: Create an object first, then assign to a pointer
	// creating an object of Rectangle
  Rectangle var1(5,2); // parameterized constrcutor

  /* creating a pointer of Rectangle type &
    assigning address of var1 to this pointer */
	Rectangle* ptr = &var1;

	// Second approach: directly use the new operator to assign a class/datatype to a pointer
	//Rectangle* ptr = new Rectangle(5,2);//&var1;

  /* calculating area of rectangle by using pointer
  ptr to call the objects getArea() function
  */
  int area = ptr->getArea();
  cout<<"Area of rectangle is: "<< area << endl;

	// Second approach: free the allocated memory when using the new operator
	//delete ptr;

//// Pointer to an array
	// int *ptr;
	// int arr[5]={0,1,2,3,4};
	// ptr = arr; //&arr[0]; // both ways are ok, both point to the first element
	// for(int i=0;i<5;i++){
	// 	// ptr+i is equivalent to &arr[i], display the address stored in ptr+i
	// 	cout << "ptr + " << i << " = "<< ptr + i << endl;
	// 	// *(ptr+i) is equivalent to arr[i], display the value at the address stored in ptr+i
	// 	cout << "*(ptr + " << i << ") : "<< *(ptr + i) << endl;
	// }


//// Pointer to Class Array
	// // creating an object array of Rectangle, setting values of array elements
  // Rectangle var[2] = {Rectangle(5,2), Rectangle(3,2)};
	//
  // /* creating a pointer of Rectangle type &
  //   assigning address of var to this pointer */
  // Rectangle* ptr;
  // ptr = var;
	//
  // /* calculating area of rectangles by using pointer
  // ptr to call the objects getArea() function
  // */
  // for(int i=0;i<2;i++){
 	// 	cout<<"Area of Rectangle"<<(i+1)<<" : "<<(ptr+i)->getArea()<<endl;
  // }

 	return 0;
}
