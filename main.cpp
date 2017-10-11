#include "main.h"

using namespace std;

int main(int argc, char** argv) {

  if(argc < 5) {
    cout << "Not enough arguments:\n" <<
      "arg 1: input file name\n" <<
      "arg 2: output file name\n" <<
      "arg 3: row of viewpoint\n" <<
      "col of viewpoint" << endl;
    exit(0);
  }

  string input_file_name = argv[1];
  string output_file_name = argv[2];
  int vp_row = atoi(argv[3]);
  int vp_col = atoi(argv[4]);

  
  
  return 0;
}
