#include <stdio.h>

int main(void)
{
    int jugador = 1;
    int ganador = 0;
    int opcion = 0;
    unsigned int fila = 0;
    unsigned int columna = 0;
    int turnos = 0;   // Contador de turnos para detectar empate 
    char tablero[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    // Bucle principal del juego
    while (ganador == 0 && turnos < 9)
    {
        // Mostrar tablero
        printf("\n");
        printf("%c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
        printf("---------\n");
        printf("%c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
        printf("---------\n");
        printf("%c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);

        // Pedir jugada
        do
        {
            printf("Jugador %d, ingrese un numero valido "
                "donde desea colocar su ficha %c: ", jugador, jugador == 1 ? 'X' : 'O');
            scanf("%d", &opcion);

            if (opcion < 1 || opcion > 9)
            {
                printf("Numero invalido. Debe ser entre 1 y 9.\n");
                continue;
            }

            fila = (opcion - 1) / 3;
            columna = (opcion - 1) % 3;

            if (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O')
            {
                printf("Esa posicion ya esta ocupada. Elija otra.\n");
            }
        } while (opcion < 1 || opcion > 9 || tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O');

        // Colocar ficha
        tablero[fila][columna] = (jugador == 1) ? 'X' : 'O';
        turnos++;

        // Verificar ganador - diagonales
        if ((tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) ||
            (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]))
        {
            ganador = jugador;
        }
        else
        {
            // Verificar ganador - filas y columnas
            for (unsigned int linea = 0; linea <= 2; ++linea)
            {
                if ((tablero[linea][0] == tablero[linea][1] && tablero[linea][0] == tablero[linea][2]) ||
                   (tablero[0][linea] == tablero[1][linea] && tablero[0][linea] == tablero[2][linea]))
                {
                    ganador = jugador;
                    break;
                }
            }
        }

        // Cambiar de jugador solo si no hay ganador
        if (ganador == 0)
        {
            jugador = (jugador == 1) ? 2 : 1;
        }
    }

    // Mostrar tablero final
    printf("\n");
    printf("%c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf("---------\n");
    printf("%c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf("---------\n");
    printf("%c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);

    // Mostrar resultado
    if (ganador != 0)
    {
        printf("\nEl jugador %d ha ganado!\n", ganador);
    }
    else
    {
        printf("\nHa sido un empate!\n");
    }

    return 0;
}
