#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double ini, fim;
} Camera;

int cmp(const void *a, const void *b) {
    Camera *c1 = (Camera *)a;
    Camera *c2 = (Camera *)b;
    if (c1->ini < c2->ini) return -1;
    if (c1->ini > c2->ini) return 1;
    return 0;
}

int main() {
    int N, L, A;

    while (scanf("%d %d %d", &N, &L, &A), N) {
        Camera cameras[10000];
        int qtd = 0;

        for (int i = 0; i < N; i++) {
            int x, r;
            scanf("%d %d", &x, &r);

            if (r * 2 < A) continue;  // Não cobre a altura do corredor

            double half_A = A / 2.0;
            double horizontal = sqrt((double)r * r - half_A * half_A);

            cameras[qtd].ini = x - horizontal;
            cameras[qtd].fim = x + horizontal;
            qtd++;
        }

        qsort(cameras, qtd, sizeof(Camera), cmp);

        double cobertura = 0.0;
        int i = 0, usados = 0;
        int possivel = 1;

        while (cobertura < L) {
            double melhor_fim = cobertura;
            while (i < qtd && cameras[i].ini <= cobertura) {
                if (cameras[i].fim > melhor_fim)
                    melhor_fim = cameras[i].fim;
                i++;
            }

            if (melhor_fim == cobertura) {
                possivel = 0;
                break;
            }

            cobertura = melhor_fim;
            usados++;
        }

        if (possivel)
            printf("%d\n", usados);
        else
            printf("Tera que comprar mais cameras.\n");
    }

    return 0;
}