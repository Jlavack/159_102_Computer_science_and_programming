#include <iostream>
#include <cstdio> // for getchar
#include <vector>

using namespace std;

class bank_account {
private:
  int accnumber;
  string name;
  float balance;
public:
   void loaddata();
   void display();
   int getnum() { return accnumber; }
};

void enteraccounts();

vector<bank_account> accounts;

int main() {
  int search, total, num, i;
  enteraccounts();
  cout << "Which account do you want to display? ";
  cin >> search;
  total = accounts.size();
  for (i = 0; i < total; i++) {
    num = accounts[i].getnum();
    if (num == search) {
      accounts[i].display();
    }
  }
}

void enteraccounts() {
 // enter 3 accounts - this could be changed
 int i;
 bank_account temp;
 for (i = 0; i < 3; i++) {
  temp.loaddata();
  accounts.push_back(temp);
  }
}
//--------------- methods for the bank_account ------------
void bank_account::loaddata() {
 cout << "Enter the bank account number ";
 cin >> accnumber;
 getchar();
 cout << "Enter the name of the account ";
 getline(cin, name);
 cout << "Enter the balance, e.g. 32.45 ";
 cin >> balance;
}

void bank_account::display() {
 cout << "Data for Account " << accnumber << endl;
 cout << "Name: " << name << endl;
 cout << "Balance: $" << balance << endl << endl;
}
