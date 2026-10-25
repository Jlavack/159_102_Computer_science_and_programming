#include <iostream>
using namespace std;

class rectangle {
private:
  int length, width;
public:
  rectangle(int l, int w) { //constructor
    length = l;
    width = w;
  }
  int get_area() {
    return length*width;
  }
};

int main() {
  // rectangle var1(5, 2);//parameterised constructor
  // //rectangle *ptr = &var1; //intialise the pointer
  // rectangle *ptr = new rectangle(5,2); //dynamic memory allocation
  // int area = ptr->get_area();//use the pointer
  // cout << "the area of rectanlge is: " << area << endl;
  // delete ptr; //dealllocate memory allocated to pointer to avoid memory leak
   //
   // int *ptr;
   // int arr[5] = {0,1,2,3,4};
   // ptr = arr; //&arr[0] //both ways are the same
   // for (int i=0; i<5; i++) {
   //   cout << "*ptr + " << i << " = " << ptr + i << endl; //equivalent to &arr[i] showing the address
   //   cout << "*(ptr + " << i << ") : " << (*ptr + i) << endl; //equivalent to arr[i] showing vlaue
   // }

   //create object array of rectangles
   rectangle var[2] = {rectangle(5,2), rectangle(3,2)};
   //create pointer of rectanlge type and giving addresses of var[] to the pointer
   rectangle *ptr;
   ptr = var;
   //calc the area using pointer to call object get_area() function
   for (int i=0; i<2; i++) {
     cout << "Area of rectangle " << (i+1) << " : " << (ptr+i) ->get_area() << endl;
   }
   return 0;
}
