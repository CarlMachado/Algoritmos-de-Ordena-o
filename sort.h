#ifndef SORT_H
#define SORT_H

void bubblesort(int arr[], int n) {
	int i, j, aux;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}

void selectionsort(int arr[], int n) {
	int i, j, min, aux;

	for (i = 0; i < (n - 1); i++) {
		min = i;
		for (j = (i + 1); j < n; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		if (arr[i] != arr[min]) {
			aux = arr[i];
			arr[i] = arr[min];
			arr[min] = aux;
		}
	}
}

void insertionsort(int arr[], int n) {
	int i, j, cur;

	for (i = 1; i < n; i++) {
		cur = arr[i];
		for (j = i - 1; (j >= 0) && (cur < arr[j]); j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = cur;
	}
}

void quicksort(int arr[], int begin, int end) {
	int pivot, aux, i, j, mid;

	i = begin;
	j = end;

	mid = (int)((i + j) / 2);
	pivot = arr[mid];

	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j) {
			aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
			i++;
			j--;
		}
	} while (j > i);

	if (begin < j) quicksort(arr, begin, j);
	if (i < end) quicksort(arr, i, end);
}

void shellsort(int arr[], int n) {
	int i, j, value;
	int gap = 1;

	while (gap < n) {
		gap = 3 * gap + 1;
	}
	while (gap > 1) {
		gap /= 3;
		for (i = gap; i < n; i++) {
			value = arr[i];
			j = i;
			while (j >= gap && value < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = value;
		}
	}
}

void merge(int arr[], int begin, int mid, int end) {
	int begin1 = begin, begin2 = mid + 1, begin_aux = 0, size = end - begin + 1;
	int *arr_aux;
	arr_aux = (int*)malloc(size * sizeof(int));

	while (begin1 <= mid && begin2 <= end) {
		if (arr[begin1] < arr[begin2]) {
			arr_aux[begin_aux] = arr[begin1];
			begin1++;
		} else {
			arr_aux[begin_aux] = arr[begin2];
			begin2++;
		}
		begin_aux++;
	}

	while (begin1 <= mid) {
		arr_aux[begin_aux] = arr[begin1];
		begin_aux++;
		begin1++;
	}

	while (begin2 <= end) {
		arr_aux[begin_aux] = arr[begin2];
		begin_aux++;
		begin2++;
	}

	for (begin_aux = begin; begin_aux <= end; begin_aux++) {
		arr[begin_aux] = arr_aux[begin_aux - begin];
	}

	free(arr_aux);
}

void mergesort(int arr[], int begin, int end) {
	if (begin < end) {
		int mid = (end + begin) / 2;

		mergesort(arr, begin, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, begin, mid, end);
	}
}

#endif //SORT_H
