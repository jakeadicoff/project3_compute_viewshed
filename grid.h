#ifndef __grid_h
#define	__grid_h

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

using namespace std;

struct GridPoint{
  double start_event, end_event, elevation, slope;
};

class Grid{
 public:
  Grid(string file_name, int vp_row_, int vp_col_);
  vector <int> get_viewshed() {return viewshed;}

 private:
  vector <double> row_major;
  vector <int> viewshed;
  int num_rows, num_cols, vp_row, vp_col;

  void read_file(string file_name);
  void init_viewshed();
};

#endif
