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
bool State::operator>(const State &) const {
  return this->getPopulationDensity() > getPopulationDensity();
}

bool State::operator<(const State &) const {
  return this->getName() < getName();
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

// read the data file, store in class
int readDatafile(State[], int);
// output the formatted "raw data"
void outputData( ... );
// output the sorted data, including population density
void outputSorted( ... );

// sorting routines - use a bubble sort
void sortAscend( ... );  // set this up to sort by name
void sortDescend( ... ); // set this up to sort by population density
void swap( ... );        // used by the bubble sort

int main() {
  State slist[ARRAYSIZE];

  return 0;
}
/////////////////////////* states.cpp DRIVER FILE */////////////////////////