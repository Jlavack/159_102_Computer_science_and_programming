#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Without srand(), the program will create same sequence of
    // random numbers on every program run
    //srand(1);

    // Use current time as seed for random generator
    // then create different sequence of
    // random numbers on every program run
    srand(time(0));

//// generate random numbers from 0 to RAND_MAX: [0-32767]
    for(int i = 0; i<5; i++){
        cout << rand() << " ";
    }

//// generate random numbers from 1 to 10: [1,10]
//// [a,b]: rand() % (b-a+1) + a
    // cout<<"Random numbers generated between [1,10]:"<<endl;
    // for(int i=0;i<10;i++){
    //     cout << (rand() % 10) + 1 << " ";
    // }

//// generate random numbers from 1 to 10: [1,10)
//// [a,b): rand() % (b-a) + a
    // cout<<"Random numbers generated between [1,10):"<<endl;
    // for(int i=0;i<10;i++){
    //     cout << (rand() % 9) + 1 << " ";
    // }

//// generate random numbers from 1 to 10: (1,10]
//// (a,b]: rand() % (b-a) + (a+1)
    // cout<<"Random numbers generated between (1,10]:"<<endl;
    // for(int i=0;i<10;i++){
    //     cout << (rand() % 9) + 2 << " ";
    // }

//// generate random numbers from 1 to 10: (1,10)
//// (a,b): rand() % (b-a-1) + (a+1)
    // cout<<"Random numbers generated between (1,10):"<<endl;
    // for(int i=0;i<10;i++){
    //     cout << (rand() % 8) + 2 << " ";
    // }


//// generate float random numbers from 0 to 1: [0,1]
    // cout<<"Random numbers generated between 0 and 1:"<<endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << (float) rand()/RAND_MAX << endl;
    // }

//// generate float random numbers from 15 to 20: [15,20]
//// Float [a,b]: ((b - a) * ((float)rand() / RAND_MAX)) + a
    // cout<<"Random numbers generated between 0 and 1:"<<endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << ((5 * (float) rand()/RAND_MAX) + 15) << endl;
    // }

    cout << endl;
    return 0;
}
