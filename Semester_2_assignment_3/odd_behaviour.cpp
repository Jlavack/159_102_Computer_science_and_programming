//20001249 John Lavack. Assignment 3 159.102

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

class pixel_class {
private:
  unsigned int red, green, blue, x, y;
  bool exclude;  // if true, do not check this pixel
public:
  void loaddata(unsigned int v1, unsigned int v2, unsigned int v3);
  void datatofile(fstream & ppmfile);
  unsigned int getR() { return red; }
  unsigned int getG() { return green; }
  unsigned int getB() { return blue; }
  void setexclude(bool ex) { exclude = ex; }
  bool getexclude() { return exclude; }
};
//-----functions------//
void loadButtons();
void pixel_check(unsigned int x, unsigned int y);
void minmax(unsigned int x, unsigned int y);
void load_arrays(unsigned int x, unsigned int y);
//-----global variables------//
unsigned int total, xmin, xmax, ymin, ymax, xtemp, ytemp;  // MUST be global if used
unsigned int screenx, screeny, maxcolours;
unsigned int  yarray[600], xarray[600], yindex = 0, xindex = 0, average, temp;

pixel_class picture[600][600];

int main() {
  string filename;
  unsigned int x=0, y=0;
  fstream Buttons_output;

  // Step 1 : read in the image from Buttons.ppm drawing boxes will be turning the pixel green or red.
  loadButtons();
  cout << "successful load \n";
       int k = 0;
       unsigned int sum = 0;
  // Step 2 : identify buttons and draw boxes
     for (y=0; y <= screeny; y++) {
       for (x=0; x <= screenx; x++) {
         load_arrays(x, y);
         total = 0;
         xmin = x;
         xmax = x;
         ymin = y;
         ymax = y;
         pixel_check(x, y);
//check if pixel is broken by comparing the total against a running average
         if (total > 0) {
           k++;
           cout << "DEBUG k = " << k << endl;
           cout << "DEBUG TOTAL = " << total << endl;
           temp = total;
           sum = sum + temp;
           average = (sum)/k;
           cout<< "DEBUG SUM: " << sum << "    av: " << average << endl;
         }
//draw the appropriate box
         if (total <= average) {
           if ((picture[x][y].getR() > 128) && (picture[x][y].getexclude() == true)) {
              for (x = xmin; x <= xmax; x++) { //top line
                picture[x][ymin].loaddata(255, 0, 0);
                picture[x][ymin].setexclude(true);
              }
              for (x = xmin; x <= xmax; x++) { //bottom line
                picture[x][ymax].loaddata(255, 0, 0);
                picture[x][ymax].setexclude(true);
              }
              for (y = ymin; y <= ymax; y++) { // left line
                picture[xmin][y].loaddata(255, 0, 0);
                picture[xmin][y].setexclude(true);
              }
              for (y = ymin; y <= ymax; y++) {
                picture[xmax][y].loaddata(255, 0, 0);
                picture[xmax][y].setexclude(true);
              }
            }
          } else {
            if ((picture[x][y].getR() > 128) && (picture[x][y].getexclude() == true)) {
              for (x = xmin; x <= xmax; x++) { //top line
                picture[x][ymin].loaddata(0, 255, 0);
                picture[x][ymin].setexclude(true);
              }
              for (x = xmin; x <= xmax; x++) { //bottom line
                picture[x][ymax].loaddata(0, 255, 0);
                picture[x][ymax].setexclude(true);
              }
              for (y = ymin; y <= ymax; y++) { // left line
                picture[xmin][y].loaddata(0, 255, 0);
                picture[xmin][y].setexclude(true);
              }
              for (y = ymin; y <= ymax; y++) {
                picture[xmax][y].loaddata(0, 255, 0);
                picture[xmax][y].setexclude(true);
              }
            }
          }
       }
     }

     //Draw box


  // Step 3 : output the final .ppm file
  filename = "Buttons_output.ppm";
  Buttons_output.open(filename.c_str(), fstream::out);
  Buttons_output << "P3\n";
  Buttons_output << "# " << filename << endl;
  Buttons_output << screenx << " " << screeny << endl;
  Buttons_output << maxcolours << endl;
  for (y = 0; y < screeny; y++) {
    for (x = 0; x < screenx; x++) {
      picture[x][y].datatofile(Buttons_output);
    }
    Buttons_output << endl;
  }
  Buttons_output.close();
  cout << "Successful write \n";
}

//----------------------------------functions---------------------------------//
void loadButtons() {
  // load the picture from Buttons.ppm
  unsigned int x, y, R, G, B;
  fstream infile;
  string infilename, line;
  infilename = "Buttons.ppm";
  infile.open(infilename.c_str(), fstream::in);
  if (infile.is_open() == false) {
    cout << "ERROR: not able to open " << infilename << endl;
    exit(2);
  }
  getline(infile, line);  // this line is "P3"
  getline(infile, line);  // this line is "# filename"
  infile >> screenx >> screeny;  // this line is the size
  infile >> maxcolours;  // this line is 256
  for (y = 0; y < screeny; y++) {
    for (x = 0; x < screenx; x++) {
      infile >> R >> G >> B;
      picture[x][y].loaddata(R, G, B);
      picture[x][y].setexclude(false);
    }
  }
  infile.close();
}
//----------------object detection--------------------//
void pixel_check(unsigned int x, unsigned int y) {
  if (picture[x][y].getexclude() == true) {
    return;
  }
  if (picture[x][y].getR() <= 128) {
    return;
  }
  picture[x][y].setexclude(true);
  total++;
  minmax(x, y);
//   /*DEBUG*/cout << y << ", " << x << " is button" << endl;
//  /*DEBUG*/ cout << "[y, x]: [" << y << ", " << x << "] " << endl;
  pixel_check(x, y-1);
  pixel_check(x, y+1);
  pixel_check(x-1, y);
  pixel_check(x+1, y);
}

//-----------------------load_arrays------------------------------------------//
void load_arrays(unsigned int x, unsigned int y) {
  yarray[yindex] = y;
// /*DEBUG*/cout << "y array at index " << yindex << " is " << yarray[yindex] << endl;
  yindex++;
  xarray[xindex] = x;
// /*DEBUG*/ cout << "x array at index " << xindex << " is " << xarray[xindex] << endl;
  xindex++;
}

//------------------------minmaxing-------------------------------------------//
void minmax(unsigned int x, unsigned int y) {
  if (x < xmin) { xmin = x; }
  if (x > xmax) { xmax = x; }
  if (y < ymin) { ymin = y; }
  if (y > ymax) { ymax = y; }
 }

//----------------------------------------------------------------------------//
//--------------- methods for the pixel_class --------------------------------//
void pixel_class::loaddata(unsigned int v1, unsigned int v2, unsigned int v3) {
  red = v1;
  green = v2;
  blue = v3;
}

void pixel_class::datatofile(fstream & ppmfile) {
  // write the data for one pixel to the ppm file
  ppmfile << red << " " << green;
  ppmfile << " " << blue << "  ";
}
