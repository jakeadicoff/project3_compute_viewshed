#include "grid.h"

using namespace std;

Grid::Grid(string file_name, int vp_row_, int vp_col_) {
  this->num_cols = 0;
  this->num_rows = 0;
  this->vp_row = vp_row_;
  this->vp_col = vp_col_;
  vector <double> dummy1;
  vector <int> dummy2;
  this->row_major = dummy1;
  this->viewshed = dummy2;
  read_file(file_name);
  init_viewshed();
}

void Grid::init_viewshed() {
  viewshed.clear();
  for(int i = 0; i < num_rows; i++) {
    for(int j = 0; j < num_cols; j++) {
      viewshed.push_back(0);
    }
  }
}

//read in test file, populate row_major grid
void Grid::read_file(string file_name) {
  //open file
  ifstream file_stream;
  file_stream.open(file_name.c_str(), ios::in);

  if(!file_stream.good())
    cout << "Error: not able to open file" << endl;

  string line;

  //parse file for nrows, ncols, and data
  int i = 0;
  while(getline(file_stream,line)) {
    if(i > 5) {
      //https://stackoverflow.com/questions/236129/most-elegant-way-to-split-a-string
      istringstream iss(line);
      vector<string> tokens{istream_iterator<string>{iss},
	  istream_iterator<string>{}};

      //https://stackoverflow.com/questions/20257582/convert-vectorstdstring-to-vectordouble
      vector<double> doubleVector(tokens.size());
      transform(tokens.begin(), tokens.end(), doubleVector.begin(),
		[](const std::string& val) { return std::stod(val); });

      //Append new line that was just read into file
      for (uint i = 0; i<doubleVector.size(); ++i)
	row_major.insert(row_major.end(), doubleVector.begin(), doubleVector.end());
    }

    else if(i == 0) sscanf(line.c_str(), "%*s %d", &num_cols); //first line is num_cols
    else if(i == 1) sscanf(line.c_str(), "%*s %d", &num_rows); //second is num_rows

    i++;
  }

  cout << "rows: " << num_rows << "; cols: " << num_cols << endl;
  cout << "ROW MAJOR FORMAT:" << endl;
}

