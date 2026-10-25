// Workshop 6 solutions
#include <iostream>
using namespace std;

//// Q1
float f;
float *fp;
int main() {
  f = 3.1415;
  fp = &f;
  cout << "The hexadecimal address of f is " << fp << endl;
  // (long long) can cast a 64-bit address to an integer
  // (intptr_t) can safely cast an address to an integer regardless the platform capacity
  cout << "The decimal address of f is " << (intptr_t) fp << endl;
}

//// Q2
// int val;
// int *ptr;
// int main() {
//   ptr=&val;
//   cout<<"Enter an integer value: ";
//   cin >> *ptr;
//   *ptr=*ptr+3;
//   cout<<"value at address in ptr: "<<*ptr<<endl;
//   cout<<"val value: "<<val<<endl;
// }

//// Q3
// int *p;
// int main() {
//   //p=NULL;
//   int v=33;
//   p=&v;
//   if(p==NULL){
//     cout<<"It is a NULL pointer"<<endl;
//   }
//   if(!p){
//     cout<<"It is a NULL pointer"<<endl;
//   }
//   if(p){
//     cout<<"Address in p: "<<p<<endl;
//     cout<<"value at address in p: "<<*p<<endl;
//   }
//
// }

//// Q5
// void convert(float NZD, float &ST, float &PGK);
//
// int main() {
//   float nzvalue, tala, kina;
//   nzvalue=500;
//   convert(nzvalue,tala,kina);
//   cout << "NZ $" << nzvalue << " = " << tala << " Samoan tala\n";
//   cout << "NZ $" << nzvalue << " = " << kina << " Papua New Guinea kina\n";
// }
//
// void convert(float NZD, float &ST, float &PGK){
//   ST = NZD / 0.5;
//   PGK = NZD / 0.4;
// }
