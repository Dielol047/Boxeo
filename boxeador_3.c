#include <stdio.h>

int main(int argc, char *argv[]) {
    int score[6];
    int indices[6];

    for (int i = 0; i < 6; i++) {
        int valido = 0;
        while (!valido) {
            printf("Ingrese puntaje del Boxeador %d: ", i + 1);
            if (scanf("%d", &score[i]) != 1 || score[i] < 0) {
                printf("Entrada invalida. Ingrese un numero entero no negativo.\n");
                while (getchar() != '\n'); // Limpia el buffer
            } else {
                valido = 1;
            }
        }
        indices[i] = i;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (score[indices[i]] < score[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    if (score[indices[0]] == score[indices[1]] || score[indices[1]] == score[indices[2]]) {
        printf("No se permiten empates en los tres primeros puestos.\n");
        return 1;
    }

    printf("\n--- RESULTADOS FINALES ---\n");
    printf("1er lugar (Campeon): Boxeador %d\n", indices[0] + 1);
    printf("2do lugar (Subcampeon): Boxeador %d\n", indices[1] + 1);
    printf("3er lugar: Boxeador %d\n", indices[2] + 1);

    return 0;
}
