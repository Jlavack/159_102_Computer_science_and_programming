#include <iostream>
#include <cstdlib> // to use exit
using namespace std;
float strtofloat(string str);
string temp;
float a, b , result;
int main(int argc, char* argv[]) {
 if (argc != 3) {
 cout << "ERROR 12: you must supply two numbers \n";
 exit(12);
}
// ignore argv[0] - this is the name of the program
temp = argv[1];
a = strtofloat(temp);
temp = argv[2];
b = strtofloat(temp);
result = a + b;
cout << "a + b = " << result << endl;
}
float strtofloat(string str) {
float value, fraction;
int len, i;
i = 0; // very important to set i to zero
value = 0.0;
len = str.length();
while (str[i] != '.') {
value = value * 10 + str[i] - 48;
i++;
if (i == len) { return value; } // if there is no dot
}
i++; // skip over the dot
fraction = 0.1;
while (i < len) {
value = value + (str[i] - 48) * fraction;
fraction = fraction / 10.0;
i++;
}
return value;
}
