#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// do NOT change this!
#define ARRAYSIZE 8

//specific spacing for outputs
#define NAME_SPACE 15
#define POP_SPACE 15
#define AREA_SPACE 20
#define DENSITY_SPACE 25

// prototypes
int readDatafile(string[], float[], float[], int);
void calcPopDensity(float[], float[], float[], int);
void outputRawData(string[], float[], float[], int);
void outputAllData(string[], float[], float[], float[], int);
void filterData(string[], float[], float[], float[], int);

int main() {
  string names[ARRAYSIZE];        // state names
  float population[ARRAYSIZE];    // state population
  float area[ARRAYSIZE];          // state area (square miles)

  float popDensity[ARRAYSIZE];    // state population density

  int lines;                      // number of lines filled with data

  //read the data and return amount of lines filled with data
  lines = readDatafile(names, population, area, ARRAYSIZE);
  //lines will always be equal to or less than ARRAYSIZE

  //no lines were taken from the file
  if(!lines) {cout << "-Data Format Unusable-" << endl; return 1;}

  calcPopDensity(population, area, popDensity, lines);

  //output the raw and all data
  outputRawData(names, population, area, lines);
  outputAllData(names, population, area, popDensity, lines);

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
  if(ifs.fail()) {cout << "-Error opening file-" << endl;}

  //data file exists, now extract the data from it
  int line=0;
  while(line < max && ifs >> n[line]) {
    ifs >> p[line];
    ifs >> a[line];

    //data did not have the required format for data extraction
    if(ifs.fail()) {cout << "-File Failed-" << endl; return 0;}

    line++;
  }
    return line;
}

void outputRawData(string n[], float p[], float a[], int max) {
  cout << "\n\n  -Raw Data-  \n\n";
  cout << left << setw(NAME_SPACE) << "Name" << right << setw(POP_SPACE) << "Population" << setw(AREA_SPACE) << "Area\n"; //title line

  cout << setw(NAME_SPACE) << " " << setw(POP_SPACE) << "(millions)" << setw(AREA_SPACE) << "(thou. sq. mi.)" << endl; //unit line
  
  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << n[i] << right << setw(POP_SPACE) << p[i] << setw(AREA_SPACE) << a[i] << endl;
  }
}

void outputAllData(string n[], float p[], float a[], float d[], int max) {
  cout << "\n\n  -All Data-  \n\n";
  cout << left << setw(NAME_SPACE) << "Name" << right << setw(POP_SPACE) << "Population" << setw(AREA_SPACE) << "Area" 
       << setw(DENSITY_SPACE) << "Pop. Density" << endl; //title line

  cout << setw(NAME_SPACE) << " " << setw(POP_SPACE) << "(millions)" << setw(AREA_SPACE) << "(thou. sq. mi.)"
       << setw(DENSITY_SPACE) << "(peop. per sq. mi.)" << endl; //unit line

  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE + DENSITY_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << n[i] << right << setw(POP_SPACE) << p[i] 
         << setw(AREA_SPACE) << a[i] << setw(DENSITY_SPACE) << d[i] << endl;
  }
}

void calcPopDensity(float p[], float a[], float d[], int max) {
  for(int i = 0; i < max; i++) {d[i] = p[i]/a[i] * 1000;}
}

void filterData() {

}