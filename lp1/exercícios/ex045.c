#include <stdlib.h>

typedef struct {
    int cor;
    char nomeDoDono[50];
    float area;
} Casa;

int maxDistance(Casa* casas, int numCasas) {
    int maior = 0;

    for (int i = 0; i < numCasas; i++) {
        for (int j = 0; j < numCasas; j++) {
            if (casas[i].cor != casas[j].cor) {
                int dist = i - j;
                if (dist < 0)
                    dist = -dist;
                if (dist > maior)
                    maior = dist;
            }
        }
    }

    return maior;
}

int main() {
    Casa casas[6] = {
        {1, "Alice", 80.0},  // cor 1
        {1, "Bruno", 75.0},  // cor 1
        {2, "Carla", 60.0},  // cor 2
        {1, "Diego", 90.0},  // cor 1
        {3, "Eva",   70.0},  // cor 3
        {1, "Fábio", 85.0}   // cor 1
    };

    int distancia = maxDistance(casas, 6);
    printf("Maior distância entre casas de cores diferentes: %d\n", distancia);

    return 0;
}