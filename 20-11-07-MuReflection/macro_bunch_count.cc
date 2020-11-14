#include <cstdio>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
const double T = 1./324e6*1e9; //RF 1 cycle nsec
const double toffset = 463;    
#define NBUN 10 

int main (int argc, char* argv[]){
  double p = T/100*atof(argv[1]);
  int np[NBUN]={0}; //number of muons in a certin bunch
  
  ifstream f("tall.dat");
  double t;
  int nall = 0;
  while(f>>t){
    int a = (int) ((t-toffset-p)/T);
    np[a]++;
    nall++;
  }
  cout << "--- # of muons and fraction in each bunch ---" << endl;
  for(int i=0; i<NBUN; i++){
    cout << i << " th bunch: " << np[i] << "\t" << "( " << fixed << setprecision(1) << 100.0*np[i]/nall << " %)"  << endl;
  }
  
  
}
