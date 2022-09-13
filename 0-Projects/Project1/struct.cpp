#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define ARRAYSIZE 8

// struct definition for a state object
struct state {
  string name;         // state name
  float population;    // state population
  float area;          // state area (square miles)
  float popDensity;    // state population density
};

// prototypes
int readDatafile(state[], int);
void calcPopDensity( ... );
void outputRawData( ... );
void outputAllData( ... );

// additional prototypes for sorting

int main() {
  state slist[ARRAYSIZE];

  return 0;
}

// open and read the datafile
int readDatafile(state list[], int max) {
  string fname;
  ifstream ifs;
  int num=0;
}
