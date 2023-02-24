#include <iostream>
#include <time.h>
#include "funciones.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;

int main()
{
    int puntosJugador[10], puntosJugador1[10], puntosJugador2[10], tiradas = 0, tiradas1 = 0, tiradas2 = 0;
    char nombreJugador[20], nombreJugador1[20], nombreJugador2[20];
    //
    char nombreJugadorMax[20];
    int maximaPuntuacion = 0, tiradasMax;
    bool generalaServida = false;
    while (1)
    {
        int opcion;
        cls();
        cout << "GENERALA" << endl;
        cout << "------------------" << endl;
        cout << "1) JUEGO DE A 1" << endl;
        cout << "2) JUEGO DE A 2" << endl;
        cout << "3) MOSTRAR PUNTUACION MAS ALTA" << endl;
        cout << "0) SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;
        cls();
        switch (opcion)
        {
        case 1:
            generalaDeAUno(puntosJugador, tiradas, nombreJugador);
            finJuego(puntosJugador, tiradas, nombreJugador);
            puntuacionMasAlta(puntosJugador, nombreJugador, tiradas, nombreJugadorMax, tiradasMax, maximaPuntuacion);
            break;
        case 2:
            generalaDeADos(puntosJugador1, puntosJugador2, tiradas1, tiradas2, nombreJugador1, nombreJugador2, generalaServida);
            puntuacionMasAlta(puntosJugador1, nombreJugador1, tiradas1, nombreJugadorMax, tiradasMax, maximaPuntuacion);
            puntuacionMasAlta(puntosJugador2, nombreJugador2, tiradas2, nombreJugadorMax, tiradasMax, maximaPuntuacion);
            if(generalaServida)
            {
                if(puntosJugador1[9] == 50)
                {
                    finJuego(puntosJugador1, tiradas1, nombreJugador1);
                }
                else
                {
                    finJuego(puntosJugador2, tiradas2, nombreJugador2);
                }
            }
            else
            {
                if(sumarPuntos(puntosJugador1, 10) > sumarPuntos(puntosJugador2, 10))
                {
                    finJuego(puntosJugador1, tiradas1, nombreJugador1);
                }
                else
                {
                    finJuego(puntosJugador2, tiradas2, nombreJugador2);
                }
            }
            break;
        case 3:
            cout << "----------------------------------------------" << endl;
            cout << "JUGADOR PUNTUACION MAXIMA: " << nombreJugadorMax << endl;
            cout << "PUNTUACION: " << maximaPuntuacion << endl;
            cout << "TIRADAS: " << tiradasMax << endl;
            cout << "----------------------------------------------" << endl;
            system("pause");
            break;
        case 0:
            exit(1);
            break;
        }
        system("pause");
    }
    return 0;
}
