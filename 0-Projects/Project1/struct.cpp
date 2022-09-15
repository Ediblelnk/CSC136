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

// struct definition for a state object
struct state {
  string name;         // state name
  float population;    // state population
  float area;          // state area (square miles)
  float popDensity;    // state population density
};

// prototypes
int readDatafile(state[], int);
int readDatafile(state[], int);
void calcPopDensity(state[], int);
void outputRawData(state[], int);
void outputAllData(state[], int, string);
void filterData(state[], int);

// additional prototypes for sorting

int main() {
  state slist[ARRAYSIZE];   //array of state structs

  int lines;                //number of lines filled with data

  //read the data and return the amount of lines filled with data
  lines = readDatafile(slist, ARRAYSIZE);
  //lines will always be equal to or less than ARRAYSIZE

  //no lines were taken from the file
  if(!lines) {cout << "-Data Format Unusable-" << endl; return 1;}

  //output the raw and all data
  outputRawData(slist, lines);

  return 0;
}

/*
 Function name:   readDatafile
 Description:     prompts the user for a filename and
                  attempts to read the contents. If possible,
                  it fits the data to state names, population,
                  and area.
 Parameters:      struct slist[]  -array of state structs
 Return Value:    int line    -the amount of lines read
*/
int readDatafile(state slist[], int max) {
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
  while(line < max && ifs >> slist[line].name) {
    ifs >> slist[line].population;
    ifs >> slist[line].area;

    //data did not have the required format for data extraction
    if(ifs.fail()) {cout << "-File Failed-" << endl; return 0;}

    line++;
  }
    return line;
}

/*
 Function name:   outputRawData
 Description:     prints out the states' information in a readable way
 Parameters:      struct slist[]  -array of state structs
                  int max         -
 Return Value:    N/A
*/
void outputRawData(state slist[], int max) {
  cout << "\n\n  -Raw Data-  \n\n";
  cout << fixed << setprecision(1) << left << setw(NAME_SPACE) << "Name" << right << setw(POP_SPACE)
       << "Population" << setw(AREA_SPACE) << "Area\n"; //title line

  cout << setw(NAME_SPACE) << " " << setw(POP_SPACE) << "(millions)" << setw(AREA_SPACE) << "(thou. sq. mi.)" << endl; //unit line
  
  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << slist[i].name << right << setw(POP_SPACE) << slist[i].population << setw(AREA_SPACE) << slist[i].area << endl;
  }
}