#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int v[], int i, int raiz) {
	int aux = v[i];
	v[i] = v[raiz];
	v[raiz] = aux;
}

void heapify(int v[], int n, int i) {
	int raiz = i;
	int esquerda = 2 * i + 1;
	int direita  = 2 * i + 2;
	
	if (esquerda < n && v[esquerda] > v[raiz]) {
		raiz = esquerda;
	}

	if (direita < n && v[direita] > v[raiz]) {
		raiz = direita;
	}

	if (raiz != i) {
		swap(v, i, raiz);
		heapify(v, n, raiz);
	}
}

void heapsort(int v[], int n) {
	int i = n / 2 - 1;
	for (i; i >= 0; i--) {
		heapify(v, n, i);
	}
	
	int j = n - 1;
	for (j; j > 0; j--) {
 		swap(v, 0, j); 
 		heapify(v, j, 0);
 	}
}

int main() {
	int n, i, j;
	
	int seed = time(NULL);
	srand(seed);
	
	do {
		printf("Por favor, informe o tamanho do vetor: ");
		scanf("%d", &n);
		
		if (n <= 0) {
			printf("Erro: Informe um valor maior do que 0! \n");
		}
		
	} while(n <= 0);
	
	
	printf("Informe a base da randomizacao: ");
	scanf("%d", &j);
	
	if (j <= 0) {
		j = 1;
	}
	
	int* v = (int*) malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++) {
		v[i] = rand() % j;
	}
	
	printf("Vetor nao ordenado: \n");
	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}
	
	heapsort(v, n);
	
	printf("\nVetor ordenado: \n");
	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}

	return 0;
}
