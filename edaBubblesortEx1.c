#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubblesort(int v[], int n) {
	int i, j, k = 0, l = 0;
	
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				
				k++;
			}
			
			l++;
		}
	}
	
	printf("Vetor ordenado: \n");
	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}
	printf("\n");
	
	printf("Numero total de operacoes: %d \n", l);
	printf("Numero total de trocas: %d \n", k);
}

int main() {
	int n, i;
	
	printf("Por favor, informe o tamanho do vetor: ");
	scanf("%d", &n);
	
	int* v = (int*) malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++) {
		v[i] = rand() % 100;
	}
	
	bubblesort(v, n);
}
