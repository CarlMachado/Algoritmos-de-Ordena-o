#include <stdlib.h>

#pragma once

void bubblesort(int vetor[], int n)
{
	int i, j, aux;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (vetor[j] > vetor[j + 1]) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}

void selectionsort(int vetor[], int n)
{
	int i, j, min, aux;

	for (i = 0; i < (n - 1); i++) {
		min = i;
		for (j = (i + 1); j < n; j++) {
			if (vetor[j] < vetor[min])
				min = j;
		}
		if (vetor[i] != vetor[min]) {
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
	}
}

void insertionsort(int vetor[], int n)
{
	int i, j, atual;

	for (i = 1; i < n; i++) {
		atual = vetor[i];
		for (j = i - 1; (j >= 0) && (atual < vetor[j]); j--) {
			vetor[j + 1] = vetor[j];
		}
		vetor[j + 1] = atual;
	}
}

void quicksort(int vetor[], int inicio, int fim)
{
	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (int)((i + j) / 2);
	pivo = vetor[meio];

	do {
		while (vetor[i] < pivo) i++;
		while (vetor[j] > pivo) j--;

		if (i <= j) {
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	} while (j > i);

	if (inicio < j) quicksort(vetor, inicio, j);
	if (i < fim) quicksort(vetor, i, fim);
}

void shellSort(int vetor[], int n)
{
	int i, j, value;
	int gap = 1;

	while (gap < n) {
		gap = 3 * gap + 1;
	}
	while (gap > 1) {
		gap /= 3;
		for (i = gap; i < n; i++) {
			value = vetor[i];
			j = i;
			while (j >= gap && value < vetor[j - gap]) {
				vetor[j] = vetor[j - gap];
				j = j - gap;
			}
			vetor[j] = value;
		}
	}
}

void merge(int vetor[], int comeco, int meio, int fim)
{
	int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
	int *vetAux;
	vetAux = (int*)malloc(tam * sizeof(int));

	while (com1 <= meio && com2 <= fim) {
		if (vetor[com1] < vetor[com2]) {
			vetAux[comAux] = vetor[com1];
			com1++;
		}
		else {
			vetAux[comAux] = vetor[com2];
			com2++;
		}
		comAux++;
	}

	while (com1 <= meio) {
		vetAux[comAux] = vetor[com1];
		comAux++;
		com1++;
	}

	while (com2 <= fim) {
		vetAux[comAux] = vetor[com2];
		comAux++;
		com2++;
	}

	for (comAux = comeco; comAux <= fim; comAux++) {
		vetor[comAux] = vetAux[comAux - comeco];
	}

	free(vetAux);
}

void mergesort(int vetor[], int comeco, int fim)
{
	if (comeco < fim) {
		int meio = (fim + comeco) / 2;

		mergesort(vetor, comeco, meio);
		mergesort(vetor, meio + 1, fim);
		merge(vetor, comeco, meio, fim);
	}
}