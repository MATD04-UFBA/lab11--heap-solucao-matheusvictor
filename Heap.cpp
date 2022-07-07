#include <iostream>

#include "cMaxHeap.h"

#define MAX 10
  
// ***********************************************
// ***********************************************
// ***********************************************

int main(int argv, char** argc) {

int maxElem; 

  if ( (argv < 2) || (atoi(argc[1]) < 1) )
    maxElem = MAX;
  else
    maxElem = atoi(argc[1]);

cMaxHeap maxH(maxElem);

  srand ( time(NULL) );

  for (unsigned int i = 0 ; i < MAX ; i++ ) {

    int n = rand() % 100;

    if (!maxH.insertHeap(n)) {
      std::cout << "ERROR : insert Heap " << n << std::endl;
      break;
      }
    }

  std::cout << maxH << std::endl;    

  int n;
  while ( maxH.removeHeap(n) ) 
    std::cout << maxH << std::endl;    

  return 0;
}

