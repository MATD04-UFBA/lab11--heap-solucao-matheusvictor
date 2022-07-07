#include <iostream>

#include "cMaxHeap.h"


// ***********************************************
// ******                                   ******
// ***********************************************
cMaxHeap::cMaxHeap() {

	maxElem = 
	numElem = 0;
	vet 	= NULL;
}

// ***********************************************
// ******                                   ******
// ***********************************************
cMaxHeap::cMaxHeap(int n) {

	vet 	= new int[n];
	maxElem = n;
	numElem	= 0;
}

// ***********************************************
// ******                                   ******
// ***********************************************
void cMaxHeap::upHeap(int noCor) {

int pai	  = (noCor - 1) / 2,
	aux;

	if ( noCor ==  0 ) 
		return;

	if ( vet[pai] < vet[noCor] ) {

        aux 		= vet[noCor];
        vet[noCor] 	= vet[pai];
        vet[pai] 	= aux;

		upHeap(pai);
        }
}

// ***********************************************
// ******                                   ******
// ***********************************************
void cMaxHeap::downHeap(int noCor) {

	int fEsq  = noCor * 2 + 1,
		fDir  = fEsq+1,
		maior = noCor,
		aux;

    if ( (fEsq < numElem) && (vet[fEsq] > vet[noCor]) )
         maior = fEsq;

    if ( (fDir < numElem) && (vet[fDir] > vet[maior]) )
        maior = fDir;
 
    if (maior != noCor) {
        aux 		= vet[noCor];
        vet[noCor] 	= vet[maior];
        vet[maior] 	= aux;;
        downHeap(maior);
    	}
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cMaxHeap::insertHeap(int d) {

	if (numElem == maxElem)
		return false;

	vet[numElem] = d;

	upHeap(numElem);

	numElem++;

	return true;
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cMaxHeap::removeHeap(int& d) {

	if (numElem == 0)
		return false;

	d = vet[0];

	numElem--;

	int aux 			= vet[0];
		vet[0] 			= vet[numElem];
		vet[numElem] 	= aux;

	downHeap(0);

	return true;
}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cMaxHeap &ht ) { 

	output << "===================================" << std::endl;
	output << "\n------------ [ VETOR ] ------------" << std::endl;
	
	for (unsigned int i = 0 ; i < ht.maxElem ; i++)
		output << ht.vet[i] << " , ";
	
	output << "\n------------ [ HEAP ] ------------" << std::endl;
	
	for (unsigned int i = 0 ; i < ht.numElem ; i++)
		output << ht.vet[i] << " , ";
	
	output << "\n===================================" << std::endl;

	return output;            
}


