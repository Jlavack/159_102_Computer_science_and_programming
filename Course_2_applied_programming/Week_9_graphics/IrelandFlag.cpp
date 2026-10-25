#include <iostream>
#include <fstream>
using namespace std;

class pixel_class {
private:
  int red, green, blue;
public:
  void loaddata(int v1, int v2, int v3);
  void datatofile(fstream & ppmfile);
  int getR() { return red; }
  int getG() { return green; }
  int getB() { return blue; }
};

void IrelandFlag();
string filename;
pixel_class picture[500][250]; // x:y = 2:1
int main() {
  int x, y;
  fstream myfile;
  IrelandFlag();
  filename = "Flag.ppm";
  myfile.open(filename.c_str(), fstream::out);
  myfile << "P3\n";
  myfile << "# " << filename << endl;
  myfile << 500 << " " << 250 << endl;
  myfile << 256 << endl;
  for (y = 0; y < 250; y++) {
    for (x = 0; x < 500; x++) {
      picture[x][y].datatofile(myfile);
    }
    myfile << endl;
  }
  myfile.close();
}

void IrelandFlag() {
  int x, y;
  // green block up to one third of 500
  for (y = 0; y < 250; y++) {
    for (x = 0; x < 167; x++) {
      picture[x][y].loaddata(22, 155, 98);
    }
  }
  // white block from one third to two thirds of 500
  for (y = 0; y < 250; y++) {
    for (x = 167; x < 333; x++) {
      picture[x][y].loaddata(255, 255, 255);
    }
  }
  // orange block from two thirds of 500 to the end
  for (y = 0; y < 250; y++) {
    for (x = 333; x < 500; x++) {
      picture[x][y].loaddata(255, 136, 62);
    }
  }
}

//--------------- methods for the pixel_class ------------
void pixel_class::loaddata(int v1, int v2, int v3) {
  red = v1;
  green = v2;
  blue = v3;
}

void pixel_class::datatofile(fstream & ppmfile) {
// write the data for one pixel to the ppm file
  ppmfile << red << " " << green;
  ppmfile << " " << blue << "  ";
}
