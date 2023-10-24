#include <stdio.h>

unsigned long long fib(int n, unsigned long long memoria[]) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (memoria[n] != 0) {
        return memoria[n];
    } else {
        memoria[n] = fib(n - 1, memoria) + fib(n - 2, memoria);
        return memoria[n];
    }
}
void initCerebro(unsigned long long memoria[], int n) {
    if (n >= 2) {  
        memoria[n] = 0;
        initCerebro(memoria, n - 1);
    }
}

void printFib(int n, unsigned long long memoria[]) {
    if (n >= 0) {
        printFib(n - 1, memoria);
        printf("%llu ", fib(n, memoria));
    }
}
int main() {
    int n;
    printf("Introduce el numero de terminos de la serie de Fibonacci que quieras: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, introduce un numero entero positivo \n");
    } else {
        unsigned long long memoria[n + 1];
        initCerebro(memoria, n);
        memoria[0] = 0; 
        memoria[1] = 1;
        printf("Los primeros %d numeros de la serie Fibonacci son: \n", n);
        printFib(n - 1, memoria);
        printf("\n");
    }
    return 0;
}

