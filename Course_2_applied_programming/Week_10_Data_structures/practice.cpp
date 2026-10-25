/*make a class
put things in the class
load a vector with class
display the vector*/

#include <iostream>
#include <vector>

using namespace std;

class thing_class{
private:
  int number1;
  char letter;
  string word;
public:
  void loaddata();
  void display();
  int get_number1() { return number1; }
  char get_letter() { return letter; }
  string get_word() { return word; }
};

vector<thing_class> data;
thing_class *thing;

void display();
void delete_element();
void swaping(int x, int y);
void sort();

int main() {
  int i, total;

  cout << "Enter a number of things: ";
  cin >> total;

  for (i=0; i<total; i++) {
    thing = new thing_class; //do not need to declare thing as pointer here.
    thing->loaddata();
    data.push_back(*thing);
    cout << endl;
  }

  display();

  // int size = data.size();
  // cout << "There are " << size << " elements in the vector." << endl;
  //
  // delete_element();
  //
  // cout << "Here is the new list: " << endl;
  // display();

//calling get functions on elements in the array
  // cout << "the number in position 2 is: ";
  // cout << data[1].get_number1() << endl;
  //
  // cout << "we will now swap two positions, enter the two positions: ";
  // int x, y;
  // cin >> x >> y;
  // swaping(x, y);
  //display();

  cout << "Now let's sort the array by size ascending: " << endl;
  sort();
  display();
}
//-------------------------functions------------------------------------------//
void display() {
  int i=1;
  vector<thing_class>::iterator it;
  cout << "displaying the things" << endl;
  cout << "------------------------------------------------------------------" << endl;
    for (it = data.begin(); it != data.end(); it++) {
      cout << "thing " << i << ": " << endl;
      it->display();
      cout << endl;
      i++;
    }
  }

void delete_element() {
  char ans;
  cout << "delete an element? Y/N" << endl;
  cin >> ans;
  if (ans == 'y' || ans == 'Y') {
    cout << "Which position should be deleted? ";
    int del;
    cin >> del;
    data.erase(data.begin() + (del-1));
  }
}

void swaping(int x, int y) {
  if (data[y].get_number1() > data[x].get_number1()) {
    thing_class temp = data[x];
    data[x] = data[y];
    data[y] = temp;
  }
}

void sort() {
  int i, total = data.size();
  thing_class temp;
  for (i = 0; i < total; i++) {
    if (data[i].get_number1() > data[i+1].get_number1()) {
      temp = data[i];
      data[i] = data[i+1];
      data[i+1] = temp;
    }
  }
}

//----------methods-----------
void thing_class::loaddata() {
  cout << "Enter a number: ";
  cin >> number1;
  cout << "Enter a letter: ";
  cin >> letter;
    getchar();
  cout << "Enter a word: ";
  getline(cin, word);

}

void thing_class::display() {
  cout << number1 << " " << letter << " " << word << endl;
}
