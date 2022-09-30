/////////////////////////* State.h FILE */////////////////////////
#ifndef STATE_H
#define STATE_H

#include <string>
using namespace std;

// DO NOT CHANGE THIS FILE!!!

// struct definition for a State object
class State {
public:

  // constructor
  State(string n="", float p=0, float a=0);

  // modifiers
  void setName(string n);
  void setPopulation(float v);
  void setArea(float v);

  // inspectors
  string getName() const;
  float getPopulation() const;
  float getArea() const;

  float getPopulationDensity() const;

  // overloads
  // greater than - compares population densities
  bool operator>(const State &) const; // greater than
  // less than - compares state names
  bool operator<(const State &) const; // less than

private:
  string name;      // state name
  float population;   // state test score
  float area;         // state progam score
};

// overload of external stream operators
ostream &operator<<(ostream &, const State &);
istream &operator>>(istream &, State &);

#endif
/////////////////////////* State.h FILE */////////////////////////

/////////////////////////* State.cpp FILE *//////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//#include "State.h" MAKE SURE TO UNCOMMENT THIS WHEN PLACED INTO PUTTY

//CONSTRUCTORS
State::State(string n, float p, float a) {
  name = n; population = p; area = a;
}

//MODIFIERS
void State::setArea(float a) {
  area = a;
}

void State::setName(string n) {
  name = n;
}

void State::setPopulation(float p) {
  population = p;
}

//INSPECTORS
float State::getArea() const {
  return area;
}

string State::getName() const {
  return name;
}

float State::getPopulation() const {
  return population;
}

float State::getPopulationDensity() const {
  return population / area * 1000;
}

//OPERATOR OVERLOADS
bool State::operator>(const State &A) const {
  return getPopulationDensity() > A.getPopulationDensity();
}

bool State::operator<(const State &A) const {
  return getName() < A.getName();
}

istream &operator>>(istream &input, State &S) {
  float p; string n; float a;
  input >> n >> p >> a;
  S.setName(n);
  S.setPopulation(p);
  S.setArea(a);

  return input;
}

/////////////////////////* State.cpp FILE */////////////////////////

/////////////////////////* states.cpp DRIVER FILE */////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//#include "State.h" MAKE SURE TO UNCOMMENT THIS WHEN PLACED INTO PUTTY

// DO NOT CHANGE THIS VALUE!
#define ARRAYSIZE 8

//specific spacing for outputs
#define NAME_SPACE 15
#define POP_SPACE 15
#define AREA_SPACE 20
#define DENSITY_SPACE 25

// read the data file, store in class
int readDatafile(State[], int);
// output the formatted "raw data"
void outputData(State[], int);
// output the sorted data, including population density
void outputSorted(State[], int, string);

// sorting routines - use a bubble sort
void sortAscend(State[], int);  // set this up to sort by name
void sortDescend(State[], int); // set this up to sort by population density
void swap(State&, State&);  // used by the bubble sort

int main() {

  State slist[ARRAYSIZE];
  int lines = readDatafile(slist, ARRAYSIZE);

  outputData(slist, lines);
  sortAscend(slist, lines);
  outputSorted(slist, lines, "Alphabetical");
  sortDescend(slist, lines);
  outputSorted(slist, lines, "Population Density");

  return 0;
}

int readDatafile(State s[], int max) {
  string fname;
  ifstream ifs;
  int lines = 0;

  string name; float population; float area;

  cout << "Enter data file name: ";
  cin >> fname;
  ifs.open(fname);
  if(ifs.fail()) {cout << "-Error opening file-" << endl;}

  while(lines < max && ifs >> s[lines]) {
    if(ifs.fail()) {cout << "-File Failed" << endl; return 0;}
    lines++;
  }
  return lines;
}

void outputData(State s[], int max) {
  cout << "\n\n -Data- \n\n";
  cout << setprecision(1);
  cout << fixed << left << setw(NAME_SPACE) << "Name";
  cout << right << setw(POP_SPACE) << "Population";
  cout << setw(AREA_SPACE) << "Area" << endl;

  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << s[i].getName();
    cout << right << setw(POP_SPACE) << s[i].getPopulation();
    cout << setw(AREA_SPACE) << s[i].getArea() << endl;
  }
}

void outputSorted(State s[], int max, string style) {
  cout << "\n\n -" << style << " Sorted Data- \n\n"
   << setprecision(1)
   << fixed << left << setw(NAME_SPACE) << "Name"
   << right << setw(POP_SPACE) << "Population"
   << setw(AREA_SPACE) << "Area"
   << setw(DENSITY_SPACE) << "Density" << endl;

  cout << fixed << left << setw(NAME_SPACE) << " "
   << right << setw(POP_SPACE) << "(millions)"
   << setw(AREA_SPACE) << "(thou. sq. mi.)"
   << setw(DENSITY_SPACE) << "(peop. per sq. mi.)" << endl; 

  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE + DENSITY_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << s[i].getName()
     << right << setw(POP_SPACE) << s[i].getPopulation()
     << setw(AREA_SPACE) << s[i].getArea()
     << setw(DENSITY_SPACE) << s[i].getPopulationDensity() << endl;
  }
}

void swap(State &a, State &b) {
  State temp = a; a = b; b = temp;
}

void sortAscend(State s[], int max) {
  bool flag = true;
  while(flag) {
    flag = false;
    for(int i = 0; i < max-1; i++) {
      if(s[i+1] < s[i]) {swap(s[i], s[i+1]); flag = true;}
    }
  }
}

void sortDescend(State s[], int max) {
  bool flag = true;
  while(flag) {
    flag = false;
    for(int i = 0; i < max-1; i++) {
      if(s[i+1] > s[i]) {swap(s[i], s[i+1]); flag = true;}
    }
  }
}
/////////////////////////* states.cpp DRIVER FILE */////////////////////////