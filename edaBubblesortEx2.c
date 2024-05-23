#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubblesort(int v[], int n) {
	int troca, i, k = 0, l = 0;
	
	do {
		troca = 0;
		
		for (i = 0; i < n - 1; i++) {
 			if (v[i] > v[i + 1]) {
 				int aux = v[i];
 				v[i] = v[i + 1];
 				v[i + 1] = aux;
 				troca = 1; 
 				
 				k++;
 			}
 		}
 		
 		l++;
	} while (troca);
	
	printf("Vetor ordenado: \n");
	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}
	printf("\n");
	
	printf("Numero total de operacoes: %d \n", l);
	printf("Numero total de trocas: %d \n", k);
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
	
	bubblesort(v, n);
	
	return 0;
}
