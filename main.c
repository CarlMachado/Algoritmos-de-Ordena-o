#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

void escrever_vetor(int[], int);
void preencher_vetor(int[], int);

int main(void) {
	int arr[500], n = sizeof(arr) / sizeof((arr)[0]);
	int op = 0, p_exit = 0;

	while (!p_exit) {
		printf("Selecione o algoritmo de ordenacao:\n");
		printf("1 - Bubblesort\n");
		printf("2 - Selectionsort\n");
		printf("3 - Insertionsort\n");
		printf("4 - Quicksort\n");
		printf("5 - Shellsort\n");
		printf("6 - Mergesort\n");
		printf("7 - Sair\n\n");
		printf("Opcao: ");

		scanf("%i", &op);

		system("cls");

		fill_arr(arr, n);

		if (op != 7) {
			printf("Vetor sem ordenacao:\n\n");
			print_arr(arr, n);
		}

		switch (op)
		{
		case 1:
			bubblesort(arr, n);
			break;
		case 2:
			selectionsort(arr, n);
			break;
		case 3:
			insertionsort(arr, n);
			break;
		case 4:
			quicksort(arr, 0, n - 1);
			break;
		case 5:
			shellsort(arr, n);
			break;
		case 6:
			mergesort(arr, 0, n - 1);
			break;
		case 7:
			p_exit = 1;
			break;
		default:
			printf("Opcao invalida.\n\n");
		}

		if (!p_exit && op > 0 && op < 8) {
			printf("Vetor ordenado:\n\n");
			print_arr(arr, n);
			system("pause");
			system("cls");
		}
	}
	return 0;
}

void print_arr(int arr[], int n) {
	int i, c = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] < 10) {
			printf("00%i ", arr[i]);
		} else if (arr[i] < 100) {
			printf("0%i ", arr[i]);
		} else {
			printf("%i ", arr[i]);
		}
		c++;
		if (c == 25) {
			printf("\n");
			c = 0;
		}
	}
	printf("\n\n");
}

void fill_arr(int arr[], int n) {
	int i;
	srand(time(0));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 999;
}
