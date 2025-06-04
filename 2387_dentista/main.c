#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inicio;
    int fim;
} Consulta;

int comparar(const void *a, const void *b) {
    Consulta *c1 = (Consulta *)a;
    Consulta *c2 = (Consulta *)b;
    return c1->fim - c2->fim;
}

int main() {
    int n;
    scanf("%d", &n);
    Consulta consultas[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &consultas[i].inicio, &consultas[i].fim);
    }

    qsort(consultas, n, sizeof(Consulta), comparar);

    int count = 0;
    int fimUltima = 0;

    for (int i = 0; i < n; i++) {
        if (consultas[i].inicio >= fimUltima) {
            count++;
            fimUltima = consultas[i].fim;
        }
    }

    printf("%d\n", count);
    return 0;
}
