//20001249 John Lavack. Assignment 3 159.102

#include <iostream>
#include <fstream>
#include <cstdlib>
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

class button_class {
private:
  unsigned int button_total, xleft, xright, ytop, ybottom;
  bool defect;
public:
  detect_defect();
  unsigned int setxleft(unsigned int xmin) { xleft = xmin; return xleft; }
  unsigned int setxright(unsigned int xmax) { xright = xmax; return xright; }
  unsigned int setytop(unsigned int ymin) { ytop = ymin; return ytop; }
  unsigned int setybottom(unsigned int ymax) { ybottom = ymax; return ybottom; }
  unsigned int getxleft() { return xleft; }
  unsigned int getxright() { return xright; }
  unsigned int getytop() { return ytop; }
  unsigned int getybottom() { return ybottom; }
};

//-----functions------//
void loadButtons();
void pixel_check(unsigned int x, unsigned int y);
void minmax(unsigned int x, unsigned int y);
void detect_damage();
//-----global variables------//
unsigned int total, xmin, xmax, ymin, ymax, temp, average, sum = 0;  // MUST be global if used
unsigned int screenx, screeny, maxcolours;
int k = 0, r = 0, b;
int buttons[100][100], damage[100];

pixel_class picture[600][600];
button_class object;

int main() {
  string filename;
  unsigned int x=0, y=0;
  fstream Buttons_output;

  // Step 1 : read in the image from Buttons.ppm drawing boxes will be turning the pixel green or red.
  loadButtons();
  cout << "successful load \n";

  // Step 2 : identify buttons
     for (y=0; y <= screeny; y++) {
       for (x=0; x <= screenx; x++) {
        // initialise total number of pixels in button and minimums / maximums.
        // do this for each pixel. It is not known if any given pixel is part of a button
        // or not
         total = 0;
         xmin = x;
         xmax = x;
         ymin = y;
         ymax = y;
         pixel_check(x, y);
         b++;
         //recursion. Check all neighbouring pixels. And reset
         //minimums and maximums
         detect_damage(); //check if pixel is broken by comparing the total against a running average
  // Step 2a : draw the appropriate box
          if (total <= average) { //draw a red box
         //   if (total >0) { r++; }
         //   if ((picture[x][y].getR() > 128) && (picture[x][y].getexclude() == true)) {
         //      for (x = xmin; x <= xmax; x++) { //horizontals
         //        picture[x][ymin].loaddata(255, 0, 0);
         //        picture[x][ymin].setexclude(true);
         //        picture[x][ymax].loaddata(255, 0, 0);
         //        picture[x][ymax].setexclude(true);
         //      }
         //      for (y = ymin; y <= ymax; y++) { //verticals
         //        picture[xmin][y].loaddata(255, 0, 0);
         //        picture[xmin][y].setexclude(true);
         //        picture[xmax][y].loaddata(255, 0, 0);
         //        picture[xmax][y].setexclude(true);
         //      }
         //    }
         //  } else { // draw green box
         //    if ((picture[x][y].getR() > 128) && (picture[x][y].getexclude() == true)) {
         //      for (x = xmin; x <= xmax; x++) { //horizontals
         //        picture[x][ymin].loaddata(0, 255, 0);
         //        picture[x][ymin].setexclude(true);
         //        picture[x][ymax].loaddata(0, 255, 0);
         //        picture[x][ymax].setexclude(true);
         //      }
         //      for (y = ymin; y <= ymax; y++) { // verticals
         //        picture[xmin][y].loaddata(0, 255, 0);
         //        picture[xmin][y].setexclude(true);
         //        picture[xmax][y].loaddata(0, 255, 0);
         //        picture[xmax][y].setexclude(true);
         //      }
         //    }
         //  }

         for (int i = 0; i < k; i++) {
           for (x = buttons[b][0]; x < buttons[b][1]; x++) {
             picture[x][y].loaddata(0, 255, 0);
           }
         }
        }
      }
      }


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

  cout << "There are " << k << " buttons in the batch." << endl;
  cout << r << " of which are broken." << endl;

  // int i;
  // for (i=0; i < k; i++) {
  //   cout << buttons[i] << endl;
  // }
  // cout << b << endl;
  // for (int i = 0; i < b; i ++) {
  //   cout << buttons[i][0] << ",  ";
  //   cout << buttons[i][1] << ",  ";
  //   cout << buttons[i][2] << ",  ";
  //   cout << buttons[i][3] << endl;
  // }

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
//----------------object detection-------- -----------------------------------//
/* For pixel at coordinates [x, y], check if it is part of a button or not (R>128)
If it is do a recurion to check all the neighbouring pixels in caridnal directions.
Set any pixel in the button to be excluded from future recursions.
Repeat until all checked pixels are excluded or not part of a button. */
void pixel_check(unsigned int x, unsigned int y) {
  if (picture[x][y].getexclude() == true) {
    return; //if part of button stop and go to next pixel.
  }
  if (picture[x][y].getR() <= 128) {
    return; //if not part of button stop and go ot next pixel.
  }
  picture[x][y].setexclude(true);
  total++;
  minmax(x, y); //if part of button update minimums and maximums
  //do a recursion for all cardinally neighbouring pixels
  pixel_check(x, y-1);
  pixel_check(x, y+1);
  pixel_check(x-1, y);
  pixel_check(x+1, y);

}

//--------------------------minmaxing-----------------------------------------//
/* Track the values of the minimums and maximums. These will be the corners
of the boxes. */
void minmax(unsigned int x, unsigned int y) {
  if (x < xmin) { xmin = x; buttons[b][0] = object.setxleft(x);}
  if (x > xmax) { xmax = x; buttons[b][1] = object.setxright(x);}
  if (y < ymin) { ymin = y; buttons[b][2] = object.setytop(y);}
  if (y > ymax) { ymax = y; buttons[b][3] = object.setybottom(y);}
}
//---------------------------damage_check------------------------------------//
/* keep a running count of the buttons and total pixels on buttons in image.
Divide the total button pixels by the number of buttons. If total is less than
or equal to the running averaege the button is broken. Will always make the first
button broken, as the button must always be equal to the running average.*/
void detect_damage() {
  if (total > 0) { //without this the total is counted for all pixels. We only want when total is >0, when there is a button
  damage[k] = total;
    k++;
    temp = total; //track the ongoing sum of button pixles. Used to average
    sum = sum + temp;
    average = (sum)/k;
  }
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
