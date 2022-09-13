#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// do NOT change this!
#define ARRAYSIZE 8

// prototypes
int readDatafile(string[], float[], float[], int);
void calcPopDensity(float[], float[], float[], int);
void outputRawData( ... );
void outputAllData( ... );


int main() {
  string names[ARRAYSIZE];        // state names
  float population[ARRAYSIZE];    // state population
  float area[ARRAYSIZE];          // state area (square miles)

  float popDensity[ARRAYSIZE];    // state population density

  //will be true if data is read without error
  if(readDatafile(names, population, area, ARRAYSIZE)) {
    calcPopDensity(population, area, popDensity, ARRAYSIZE);
  } else {
    cout << "-An Unknown Error Occured with File Contents-" << endl;
    return 1;
  }

  return 0;
}

// open and read the datafile
int readDatafile(string n[], float p[], float a[], int max) {
  string fname;
  ifstream ifs;
  int num=0;

  //get data file and check validity
  cout << "Enter data file name: ";
  cin >> fname;
  ifs.open(fname);
  if(ifs.fail()) {cout << "-Error opening file-\n\n";}

  //data file exists, now extract the data from it
  int line=0;
  while(line < max && ifs >> n[line]) {
    ifs >> p[line];
    ifs >> a[line];
    if(ifs.fail()) {cout << "-The File Failed-" << endl; return 0;}

    //debug feature
    cout << "Read: " << n[line] << " " << p[line] << " " << a[line] << endl;

    line++; //increment line
  }
    return 1;
}

  //void outputRawData() {}

void calcPopDensity(float p[], float a[], float d[], int max) {
  for(int i = 0; i < max; i++) {
    d[i] = p[i]/a[i];

    //debug feature
    cout << "Density " << i << ":" << d[i] << endl;
  }
}

  //void outputAllData() {}