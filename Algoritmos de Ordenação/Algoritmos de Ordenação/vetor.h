#include <time.h>
#include <iostream>

#pragma once

using namespace std;

void escrever_vetor(int vetor[], int n)
{
	int i, contador = 0;

	for (i = 0; i < n; i++) {

		if (vetor[i] < 10) {
			cout << "00" << vetor[i] << " ";
		}
		else if (vetor[i] < 100) {
			cout << "0" << vetor[i] << " ";
		}
		else {
			cout << vetor[i] << " ";
		}
		
		contador++;
		if (contador == 25) {
			cout << endl;
			contador = 0;
		}
	}
	cout << endl << endl;
}

void preencher_vetor(int vetor[], int n)
{
	int i;

	srand(time(NULL));

	for (i = 0; i < n; i++)
		vetor[i] = rand() % 999;
}