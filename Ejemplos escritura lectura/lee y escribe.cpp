
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  // writing on a text file
  ofstream escribe ("clase proga.txt");
  if (escribe.is_open()){
    escribe << "This is a line.\n";
    escribe << "This is another line.\n";
    escribe.close();
  }
  else
    cout << "Unable to open file";


  // reading from on a text file
  string line;
  ifstream lee ("lee y eshjfjfgjgfjfjgjffcribe.cpp");
  if (lee.is_open()){
    while ( getline (lee,line) ){
      cout << line << '\n';
    }
    lee.close();
  }
  else
    cout << "Unable to open file";

  return 0;
}
