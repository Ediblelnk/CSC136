#include <iostream>
using namespace std;

int main() {
  float x = 0.5;
  float y[] = {2, 4, 5};
  float *p = &x; //creates pointer p and assigns it the memory address of x
  float *q = &y[0];
  cout << "x = *p; *p: " << *p << endl; // *p is the value at the stored memory address
  cout << "         p: " << p << endl;  // p  is the value of the stored memory address
  cout << "    *(p+1): " << *(p+1) << endl;
  cout << "    *(q+1): " << *(q+1) << endl;
  cout << "      q[0]: " << q[0] << endl;

  /* MEMORY ALLOCATION: new and delete */
  float *fp = new float; //one floating point number
  int *it = new int[10]; //an array of 10 integers

  *fp = 10;
  cout << "*fp: " << *fp << endl;
  cout << " fp: " << fp << endl;

  delete fp;
  delete[] it; //important to use '[]' for an array of memory allocated 

  /* POINTER ARITHMETIC EXAMPLES */
  int iarr[] = {1, 1, 2, 3, 5, 8};
  int *ip;
  ip = iarr;

  cout << "*ip:     " << *ip << endl; // is equivalent to ip[0] and iarr[0];
  cout << "*(ip+2): " << *(ip+2) << endl;
  cout << "*(ip+5): " << *(ip+5) << " this is the end of the array" << endl;
  *ip++;
  cout << "*(ip++): " << *(ip+5) << " this is the next memory place, it is not part of the program" << endl;

}