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

void SwedenFlag();
string filename;
pixel_class picture[480][300]; // x:y = 16:10
int main() {
  int x, y;
  fstream myfile;
  SwedenFlag();
  filename = "SwedenFlag.ppm";
  myfile.open(filename.c_str(), fstream::out);
  myfile << "P3\n";
  myfile << "# " << filename << endl;
  myfile << 480 << " " << 300 << endl;
  myfile << 256 << endl;
  for (y = 0; y < 300; y++) {
    for (x = 0; x < 480; x++) {
      picture[x][y].datatofile(myfile);
    }
    myfile << endl;
  }
  myfile.close();
}

void SwedenFlag() {
  int x, y;
  // Blue background
  for (y = 0; y < 300; y++) {
    for (x = 0; x < 480; x++) {
      picture[x][y].loaddata(0, 106, 167);
    }
  }
  // Yellow block from 150-210 (x)
  // x = 480 * (5/16)= 150  -> x = 480 * (7/16) = 210
  for (y = 0; y < 300; y++) {
    for (x = 150; x < 211; x++) {
      picture[x][y].loaddata(254, 204, 2);
    }
  }
  // Yellow block from 120-180 (y)
  // y = 300 * (4/10) = 120  -> y = 300 * (6/10) = 180
  for (y = 120; y < 181; y++) {
    for (x = 0; x < 480; x++) {
      picture[x][y].loaddata(254, 204, 2);
    }
  }
  for (y = 100; y < 101; y++) {
    for (x = 100; x <101; x++) {
      picture[x][y].loaddata(0, 255, 0);
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
