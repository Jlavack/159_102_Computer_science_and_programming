//
// Everything you need to know is here:
// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
//

#include <iostream>
#include <cstdlib>  // for system
using namespace std;

class grid_class {
private:
  int max = 20;
  int cells[20][20];
public:
  int getcell(int x, int y) { return cells[x][y]; }
  void setcell(int x, int y, int v) { cells[x][y] = v; }
  void loadall(int value);
  void setup();
  void display();
  void copy(grid_class & other);
  void calculate();
};

grid_class oldgrid, newgrid;

int main() {
  oldgrid.loadall(0);
  oldgrid.setup();
  while (true) {
    system("cls");  // clear the screen on Windows - "clear" on Mac
    oldgrid.display();
    newgrid.loadall(0);
    oldgrid.calculate();
    oldgrid.copy(newgrid);
  }
}

//--------------- methods for the grid_class ------------

void grid_class::loadall(int value) {
  int x, y;
  for (y = 0; y < max; y++) {
    for (x = 0; x < max; x++) {
      cells[x][y] = value;
    }
  }
}

void grid_class::setup() {
// set up the grid
  cells[4][10] = 1;
  cells[5][10] = 1;
  cells[6][10] = 1;
  cells[6][9] = 1;
  cells[5][8] = 1;
}

void grid_class::display() {
  int x, y;
  for (y = 0; y < max; y++) {
    for (x = 0; x < max; x++) {
      if (cells[x][y] == 1) {
        cout << "O";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void grid_class::copy(grid_class & other) {
// copy all values from the other grid
  int x, y, value;
  for (y = 0; y < max; y++) {
    for (x = 0; x < max; x++) {
      value = other.getcell(x, y);
      cells[x][y] = value;
    }
  }
}

void grid_class::calculate() {
// calculate new grid based on pattern in the old grid
  int total, upper, middle, lower;
  int x, y, xplus1, xminus1, yplus1, yminus1;
  for (y = 0; y < max; y++) {
    for (x = 0; x < max; x++) {
      // check 8 adjacent cells
      xplus1 = x + 1;
      if (xplus1 >= max) { xplus1 = 0; }
      xminus1 = x - 1;
      if (xminus1 < 0) { xminus1 = max - 1; }
      yplus1 = y + 1;
      if (yplus1 >= max) { yplus1 = 0; }
      yminus1 = y - 1;
      if (yminus1 < 0) { yminus1 = max - 1; }
      upper = cells[xminus1][yminus1] + cells[x][yminus1] + cells[xplus1][yminus1];
      middle = cells[xminus1][y] + cells[xplus1][y];
      lower = cells[xminus1][yplus1] + cells[x][yplus1] + cells[xplus1][yplus1];
      total = upper + middle + lower;
      if (cells[x][y] == 1) {  // a live cell
        if ((total == 2) || (total == 3)) {
          newgrid.setcell(x, y, 1);
        }
      }
      if (cells[x][y] == 0) {  // a dead cell
        if (total == 3) {
          newgrid.setcell(x, y, 1);
        }
      }
    }
  }
}
