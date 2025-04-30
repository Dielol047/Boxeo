#include <stdio.h> 

int main(int argc, char *argv[]) {
    int score[6];
    int finalistas[3];
    int puntajes[3];

    for (int i = 0; i < 6; i++) {
        int valido = 0;
        while (!valido) {
            printf("Ingrese puntaje del Boxeador %d: ", i + 1);
            if (scanf("%d", &score[i]) != 1 || score[i] < 0) {
                printf("Entrada invalida. Ingrese un numero entero no negativo.\n");
                while (getchar() != '\n');
            } else {
                valido = 1;
            }
        }
    }

    if (score[0] > score[1]) {
        finalistas[0] = 0;
    } else {
        finalistas[0] = 1;
    }

    if (score[2] > score[3]) {
        finalistas[1] = 2;
    } else {
        finalistas[1] = 3;
    }

    if (score[4] > score[5]) {
        finalistas[2] = 4;
    } else {
        finalistas[2] = 5;
    }

    for (int i = 0; i < 3; i++) {
        puntajes[i] = score[finalistas[i]];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (puntajes[i] < puntajes[j]) {
                int tempPuntaje = puntajes[i];
                puntajes[i] = puntajes[j];
                puntajes[j] = tempPuntaje;

                int tempFinalista = finalistas[i];
                finalistas[i] = finalistas[j];
                finalistas[j] = tempFinalista;
            }
        }
    }

    if (puntajes[0] == puntajes[1] || puntajes[1] == puntajes[2]) {
        printf("No se permiten empates en los tres primeros puestos.\n");
        return 1;
    }

    printf("\n--- RESULTADOS FINALES ---\n");
    printf("1er lugar (Campeon): Boxeador %d\n", finalistas[0] + 1);
    printf("2do lugar (Subcampeon): Boxeador %d\n", finalistas[1] + 1);
    printf("3er lugar: Boxeador %d\n", finalistas[2] + 1);

    return 0;
}
