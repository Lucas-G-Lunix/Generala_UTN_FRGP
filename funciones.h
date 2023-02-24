#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<iostream>
#include<time.h>
#include"rlutil.h"

using namespace std;
using namespace rlutil;
/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void cargarVector(int v[], int tam);///asigna valores a cada una de las posiciones del vector

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

void ponerCero(int v[], int tam);/// pone en 0 todas las posiciones del vector

int posicionNumeroEnVector(int v[],int tam, int numero);/// devuelve la posici�n que ocupa un n�mero que se //env�a como par�metro. Devuelve la primera posici�n que encuentra el n�mero. Si no lo encuentra devuelve -1

int contarNumerosRepetidos(int v[], int numero, int tam); ///cuenta la cantidad de veces que se repite un //n�mero en el vector

int maximoVector(int v[], int tam);///devuelve  la posici�n (primera) que ocupa el m�ximo en el vector

int minimoVector(int v[], int tam);///devuelve  la posici�n (primera) que ocupa el m�nimo en el vector

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector. EL par�metro limite establece el valor maximo posible

void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

void copiarVector(int v[], int v2[],int tam ); ///copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam );// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

// PROPIAS

void generalaDeAUno(int puntos[], int &tiradasTotales, char jugador[]);

void generalaDeADos(int puntos1[], int puntos2[], int &tiradas1, int &tiradas2, char nombre1[], char nombre2[], bool &generalaServida);

void entreTurnos(char nombreSig[], char nombreAnt[], int puntosSig[], int puntosAnt[], int tiradasSig, int rondas); // Cartel entre turnos

void puntuacionMasAlta(int puntos[], char nombre[], int tiradas, char nombreMax[], int &tiradasMax, int &maxPuntuacion); // carga puntuacion mas alta

void mostrarDados(int dados[]);

void finJuego(int puntos[], int tiradas, char nombre[]);

int sumarPuntos(int v[], int tam ); /// suma los valores contenidos en el vector

void cargarNombreJugador(char nombre[], int tam);///carga el nombre del jugador en el vector

void cargaDados(int v[]);///carga los dados en el vector

void cambioDados(int dados[]);///cambia los dados en el vector

void cargarPuntos(int puntos[], int dados[]);///carga los puntos en el vector

void combinacionesGanadoras(int puntos[], int dados[]);///comprueba las combinaciones ganadoras

void anularCombinacion(int puntos[], int dados[]);///anula las combinaciones ganadoras

// Funciones de las combinaciones ganadoras

int juegoDeNumero(int dados[], int num);///suma juegos de 1, 2, 3, 4, 5, 6

bool escalera(int dados[]);///comprueba escalera

bool full(int dados[]);///comprueba full

bool poker(int dados[]);///comprueba poker

bool generala(int dados[]);///comprueba generala

/// Desarrollo de funciones / Definiciones

int posicionNumeroEnVector(int v[],int tam, int numero)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero) return i;
    }
    return -1;
}
int minimoVector(int v[], int tam)
{
    int i, posMin=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]<v[posMin])
        {
            posMin=i;
        }
    }
    return posMin;
}
void ordenarVector(int v[], int tam )
{
    int i,j, posmin, aux;
    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
        {
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int maximoVector(int v[], int tam)
{
    int i, posMax=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]>v[posMax])
        {
            posMax=i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite)
{
    int i;
    srand(time(NULL));
    for( i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
}

void mostrarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
}


int contarNumerosRepetidos(int v[], int numero, int tam)
{
    int i, cant=0;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero) cant++;
    }
    return cant;
}

void copiarVector(int v[], int v2[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

void cargarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<"INGRESE NUMERO: ";
        cin>>v[i];
    }
}


// Propias

// Reinicia el vector dado poniendolo en -1
void reiniciarPuntos(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        v[i]=-1;
    }
}

// Carga el nombre del jugador en el char dado
void cargarNombreJugador(char nombre[])
{
    cout<<"INGRESE NOMBRE DEL JUGADOR: ";
    cin>>nombre;
}

// Deja seleccionar la forma en la que cargar los dados manual o random
void cargaDados(int v[])
{
    char opcion;
    cout << "DESEA CARGAR LOS DADOS ALEATORIAMENTE? (S/N): ";
    cin >> opcion;
    switch (opcion)
    {
    case 'S':
    case 's':
        cargarAleatorio(v, 5, 6);
        break;
    case 'N':
    case 'n':
        cargarVector(v, 5);
        break;
    default:
        cout << "OPCION INVALIDA" << endl;
        break;
    }
}
/*
// Carga los dados de forma aleatoria
void cargaDados(int v[])
{
    cargarAleatorio(v, 5, 6);
}
*/

// Vuelve a lanzar los dados ingresados
void cambioDados(int dados[])
{
    int cantidad, numeroDeDado, i;
    cout << "CUANTOS DADOS DESEA CAMBIAR? (1-5): ";
    cin >> cantidad;
    for (i = 0; i < cantidad; i++)
    {
        cout << "INGRESE EL NUMERO DEL DADO A CAMBIAR: ";
        cin >> numeroDeDado;
        dados[numeroDeDado - 1] = (rand() % 6) + 1;
    }
}


// Muestra la carga de puntos y las diferentes opciones
void cargaPuntos(int puntos[], int dados[])
{
    int opcion;
    cout << "1. COMBINACIONES GANADORAS: " << endl;
    cout << "2. ANULAR ALGUNA COMBINACION: " << endl;
    cout << "INGRESE UNA OPCION: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        combinacionesGanadoras(puntos, dados);
        break;
    case 2:
        anularCombinacion(puntos, dados);
        break;
    default:
        cout << "OPCION INVALIDA" << endl;
        break;
    }
}

// Sumna los puntos exceptuando los -1
int sumarPuntos(int v[], int tam )
{
    int i, suma = 0;
    for(i=0; i<tam; i++)
    {
        if (v[i] != -1)
        {
            suma+=v[i];
        }
    }
    return suma;
}


// Muestra las combinaciones ganadoras disponibles y carga el puntaje en la seleccionada
void combinacionesGanadoras(int puntos[], int dados[])
{
    int opcion, i;
    bool hayJugadas = false;
    cout << "----------------------------------------------------" << endl;
    for (i = 0; i <= 5; i++)
    {
        if (juegoDeNumero(dados, (i+1)) != 0 && puntos[i] == -1)
        {
            cout << i+1 << ". JUEGO DE " << i+1 << " - PUNTOS: " << juegoDeNumero(dados, (i+1)) << endl;
            hayJugadas = true;
        }
    }
    if (escalera(dados) && puntos[6] == -1)
    {
        cout << "7. ESCALERA" << " - PUNTOS: 25" <<endl;
        hayJugadas = true;
    }
    if (full(dados) && puntos[7] == -1)
    {
        cout << "8. FULL" << " - PUNTOS: 30" <<endl;
        hayJugadas = true;
    }
    if (poker(dados) && puntos[8] == -1)
    {
        cout << "9. POKER" << " - PUNTOS: 40" << endl;
        hayJugadas = true;
    }
    if (generala(dados) && puntos[9] == -1)
    {
        cout << "10. GENERALA" << " - PUNTOS: 50" << endl;
        hayJugadas = true;
    }
    if (!hayJugadas)
    {
        cout << "NO HAY JUGADAS" << endl;
        anularCombinacion(puntos, dados);
        opcion = -1;
    }
    else
    {
        cout << "0. SALIR" << endl;
        cout << "ELIGA UNA COMBINACION: ";
        cin >> opcion;
    }

    switch (opcion)
    {
    case 1:
        if (puntos[0] == -1)
        {
            puntos[0] = juegoDeNumero(dados, 1);
        }
        break;
    case 2:
        if (puntos[1] == -1)
        {
            puntos[1] = juegoDeNumero(dados, 2);
        }
        break;
    case 3:
        if (puntos[2] == -1)
        {
            puntos[2] = juegoDeNumero(dados, 3);
        }
        break;
    case 4:
        if (puntos[3] == -1)
        {
            puntos[3] = juegoDeNumero(dados, 4);
        }
        break;
    case 5:
        if (puntos[4] == -1)
        {
            puntos[4] = juegoDeNumero(dados, 5);
        }
        break;
    case 6:
        if(puntos[5] == -1)
        {
            puntos[5] = juegoDeNumero(dados, 6);
        }
        break;
    case 7:
        if (puntos[6] == -1)
        {
            puntos[6] = 25;
        }
        break;
    case 8:
        if (puntos[7] == -1)
        {
            puntos[7] = 30;
        }
        break;
    case 9:
        if (puntos[8] == -1)
        {
            puntos[8] = 40;
        }
        break;
    case 10:
        if (puntos[9] == -1)
        {
            puntos[9] = 50;
        }
        break;
    case 0:
        cargaPuntos(puntos, dados);
        break;
    default:
        break;
    }
}


// Muestra las opciones a anular
void anularCombinacion(int puntos[], int dados[])
{
    int i, opcion;
    cout << "----------------------------------------------------" << endl;
    cout<<"LAS SIGUIENTES COMBINACIONES SE PUEDEN ANULAR: "<<endl;
    for (i = 0; i < 6; i++)
    {
        if (puntos[i] == -1)
        {
            cout<< i+1 <<". JUEGO DE "<< i+1 <<endl;
        }
    }
    if (puntos[6] == -1)
    {
        cout<<"7. ESCALERA"<< endl;
    }
    if (puntos[7] == -1)
    {
        cout<<"8. FULL"<< endl;
    }
    if (puntos[8] == -1)
    {
        cout<<"9. POKER"<< endl;
    }
    if (puntos[9] == -1)
    {
        cout<<"10. GENERALA"<< endl;
    }
    cout<<"0. SALIR"<< endl;
    cout<<"INGRESE EL NUMERO DE LA COMBINACION A ANULAR: ";
    cin>>opcion;

    switch (opcion)
    {
    case 1:
        puntos[0] = 0;
        break;
    case 2:
        puntos[1] = 0;
        break;
    case 3:
        puntos[2] = 0;
        break;
    case 4:
        puntos[3] = 0;
        break;
    case 5:
        puntos[4] = 0;
        break;
    case 6:
        puntos[5] = 0;
        break;
    case 7:
        puntos[6] = 0;
        break;
    case 8:
        puntos[7] = 0;
        break;
    case 9:
        puntos[8] = 0;
        break;
    case 10:
        puntos[9] = 0;
        break;
    case 0:
        cargaPuntos(puntos, dados);
        break;
    default:
        break;
    }
}


// Calcula Juego de 1, 2, 3, 4, 5, 6
int juegoDeNumero(int dados[], int num)
{
    int cantidad;
    cantidad = contarNumerosRepetidos(dados, num, 5);
    int puntos = cantidad*num;
    return puntos;
}


// Comprueba las diferentes formas de escalera
bool escalera(int dados[])
{
    int i, cont=0;
    for(i = 0; i < 5; i++)
    {
        if(dados[i] == i+1)
        {
            cont++;
        }
    }
    if(cont == 5)
    {
        return true;
    }
    else
    {
        cont = 0;
        for(i = 0; i < 5; i++)
        {
            if(dados[i] == i+2)
            {
                cont++;
            }
        }
        if(cont == 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Comprueba si hubo full y las diferentes dormas en las que puede ocurrir
bool full(int dados[])
{
    if ((contarNumerosRepetidos(dados, dados[0], 5) == 3) && (contarNumerosRepetidos(dados, dados[3], 5) == 2))
    {
        return true;
    }
    else
    {
        if ((contarNumerosRepetidos(dados, dados[2], 5) == 3) && (contarNumerosRepetidos(dados, dados[0], 5) == 2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Comprueba si hubo poker y las diferentes formas en las que puede ocurrir
bool poker(int dados[])
{
    if ((contarNumerosRepetidos(dados, dados[0], 5) == 4) || (contarNumerosRepetidos(dados, dados[1], 5) == 4))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Comprueba si hubo generala
bool generala(int dados[])
{
    if ((contarNumerosRepetidos(dados, dados[0], 5) == 5))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Se encarga de mostrar los dados de forma grafica
void mostrarDados(int dados[])
{
    int index = 0;
    int line = 1;

    while (line <= 5)
    {
        // Primera linea
        switch (line)
        {
        case 1:
            while(index<5)
            {
                switch(dados[index])
                {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    cout << char(201);
                    for (int i = 0; i < 7; i++)
                    {
                        cout << char(205);
                    }
                    cout << char(187);
                    cout << "	";
                    break;

                }
                index++;
            }
            cout << endl;
            line++;
            index = 0;
            break;
        // Segunda linea
        case 2:
            while(index<5)
            {
                switch(dados[index])
                {
                case 1:
                    cout<<char(186)<<"       "<<char(186)<<"	";
                    break;
                case 2:
                    cout<<char(186)<<" "<<char(254)<<"     "<<char(186)<<"	";
                    break;
                case 3:
                    cout<<char(186)<<" "<<char(254)<<"     "<<char(186)<<"	";
                    break;
                case 4:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;
                case 5:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;
                case 6:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;

                }
                index++;
            }
            cout << endl;
            line++;
            index = 0;
            break;
        //Tercera Linea
        case 3:
            while(index<5)
            {
                switch(dados[index])
                {
                case 1:
                    cout<<char(186)<<"   "<<char(254)<<"   "<<char(186)<<"	";
                    break;
                case 2:
                    cout<<char(186)<<"       "<<char(186)<<"	";
                    break;
                case 3:
                    cout<<char(186)<<"   "<<char(254)<<"   "<<char(186)<<"	";
                    break;
                case 4:
                    cout<<char(186)<<"       "<<char(186)<<"	";
                    break;
                case 5:
                    cout<<char(186)<<"   "<<char(254)<<"   "<<char(186)<<"	";
                    break;
                case 6:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;

                }
                index++;
            }
            cout << endl;
            line++;
            index = 0;
            break;
        //Cuarta Linea
        case 4:
            while(index<5)
            {
                switch(dados[index])
                {
                case 1:
                    cout<<char(186)<<"       "<<char(186)<<"	";
                    break;
                case 2:
                    cout<<char(186)<<"     "<<char(254)<<" "<<char(186)<<"	";
                    break;
                case 3:
                    cout<<char(186)<<"     "<<char(254)<<" "<<char(186)<<"	";
                    break;
                case 4:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;
                case 5:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;
                case 6:
                    cout<<char(186)<<" "<<char(254)<<"   "<<char(254)<<" "<<char(186)<<"	";
                    break;

                }
                index++;
            }
            cout << endl;
            line++;
            index = 0;
            break;
        // Quinta Linea
        case 5:
            while(index<5)
            {
                switch(dados[index])
                {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    cout << char(200);
                    for (int i = 0; i < 7; i++)
                    {
                        cout << char(205);
                    }
                    cout << char(188);
                    cout << "	";
                    break;

                }
                index++;
            }
            cout << endl;
            line++;
            break;
        }
    }
}

// Juego de generala de a uno
void generalaDeAUno(int puntos[], int &tiradasTotales, char jugador[])
{
    int dados[5], tirada, rondas = 0, cantRondas;
    char opcion;
    bool generalaServida = false;
    tiradasTotales = 0;
    reiniciarPuntos(puntos, 10);
    cargarNombreJugador(jugador);
    cout << "INGRESE LA CANTIDAD DE RONDAS: ";
    cin >> cantRondas;
    cls();
    while (rondas < cantRondas && generalaServida == false)
    {
        tirada = 0;
        opcion = ' ';
        rondas++;
        cls();
        cout << "TURNO DE " << jugador << " | ";
        cout << "RONDA N" << char(248) << rondas << " | ";
        cout << "PUNTAJE TOTAL: "<< sumarPuntos(puntos, 10) << " | " << endl;
        cout << "----------------------------------------------------" << endl;
        while (tirada<3 && (opcion != 'N' && opcion != 'n'))
        {
            tirada++;
            tiradasTotales++;

            cout << "TIRADA N"<< char(248) << tirada << " - ";
            cout << "TIRADAS TOTALES: " << tiradasTotales << endl;
            cout << "----------------------------------------------------" << endl;
            if (tirada == 1)
            {
                cargaDados(dados);
            }
            else
            {
                cambioDados(dados);
            }
            mostrarDados(dados);
            cout << endl;

            if (tirada == 1 && generala(dados) && puntos[9] == -1)
            {
                cls();
                cout << "---------------------" << endl;
                cout << "HAZ GANADO LA PARTIDA" << endl;
                cout << "GENERALA SERVIDA" << endl;
                cout << "---------------------";
                cout << endl;
                puntos[9] = 50;
                generalaServida = true;
                system("pause");
                break;
            }
            else
            {
                if (tirada != 3)
                {
                    cout << "CONTINUAR LANZANDO? (S/N): ";
                    cin >> opcion;
                    cout << endl;
                }
            }

        }
        cout << "----------------------------------------------------" << endl;
        if (generalaServida == false)
        {
            ordenarVector(dados, 5);
            mostrarDados(dados);
            cargaPuntos(puntos, dados);
        }
    }
}

// Muestra el cartel de fin de juego
void finJuego(int puntos[], int tiradas, char nombre[])
{
    cls();
    cout << "---------FIN DEL JUEGO---------" << endl;
    cout << nombre << endl;
    cout << "PUNTUACION TOTAL: " << sumarPuntos(puntos, 10) << endl;
    cout << "EL TOTAL DE TIRADAS ES: " << tiradas << endl;
    cout << "-------------------------------" << endl;
    system("pause");
}

// Muestra el cartel entre ronda y ronda con la informacion del puntaje, lanzaminetos y el siguiente turno
void entreTurnos(char nombreSig[], char nombreAnt[], int puntosSig[], int puntosAnt[], int tiradasSig, int rondas)
{
    cls();
    cout << "-------------------------------"<< endl;
    cout << "RONDA N" << char(248) << rondas << endl;
    cout << "PROXIMO TURNO: " << nombreSig << endl;
    cout << "LANZAMIENTOS: " << tiradasSig << endl;
    cout << "PUNTAJE " << nombreSig << ": " << sumarPuntos(puntosSig, 10) << endl;
    cout << "PUNTAJE " << nombreAnt << ": " << sumarPuntos(puntosAnt, 10) << endl;
    cout << "-------------------------------" << endl;
    system("pause");
}

// Juego de generala de a dos personas
void generalaDeADos(int puntos1[], int puntos2[], int &tiradas1, int &tiradas2, char nombre1[], char nombre2[], bool &generalaServida)
{
    // Definicion de variables
    int dados[5], tirada, rondas = 0, cantRondas;
    char opcion;
    bool generalaServida1 = false, generalaServida2 = false;
    generalaServida = false;
    tiradas1 = 0;
    tiradas2 = 0;
    reiniciarPuntos(puntos1, 10);
    reiniciarPuntos(puntos2, 10);
    cout << "JUGADOR 1" << endl;
    cargarNombreJugador(nombre1);
    cout << "JUGADOR 2" << endl;
    cargarNombreJugador(nombre2);
    cout << "INGRESE LA CANTIDAD DE RONDAS: ";
    cin >> cantRondas;
    cls();
    while (rondas < cantRondas && (!generalaServida1 || !generalaServida2))
    {
        cls();
        rondas++;
        // ENTRE TURNOS
        entreTurnos(nombre1, nombre2, puntos1, puntos2, tiradas1, rondas);
        //JUGADOR 1
        cls();
        tirada = 0;
        opcion = ' ';
        cout << "TURNO DE " << nombre1 << " | ";
        cout << "RONDA N" << char(248) << rondas << " | ";
        cout << "PUNTAJE TOTAL: "<< sumarPuntos(puntos1, 10) << " | " << endl;
        cout << "----------------------------------------------------" << endl;
        while (tirada<3 && (opcion != 'N' && opcion != 'n'))
        {
            tirada++;
            tiradas1++;
            cout << "TIRADA N"<< char(248) << tirada << " - ";
            cout << "TIRADAS TOTALES: " << tiradas1 << endl;
            cout << "----------------------------------------------------" << endl;
            if (tirada == 1)
            {
                cargaDados(dados);
            }
            else
            {
                cambioDados(dados);
            }
            mostrarDados(dados);
            cout << endl;
            if (tirada == 1 && generala(dados) && puntos1[9] == -1)
            {
                cls();
                cout << "---------------------" << endl;
                cout << "  GENERALA SERVIDA   " << endl;
                cout << "---------------------" << endl;
                cout << endl;
                puntos1[9] = 50;
                generalaServida1 = true;
                system("pause");
                break;
            }
            else if(generalaServida2 && !generala(dados))
            {
                generalaServida1 = true;
                break;
            }
            else
            {
                if (tirada != 3)
                {
                    cout << "CONTINUAR LANZANDO? (S/N): ";
                    cin >> opcion;
                    cout << endl;
                }
            }

        }
        cout << "----------------------------------------------------" << endl;
        if (!generalaServida1)
        {
            ordenarVector(dados, 5);
            mostrarDados(dados);
            cargaPuntos(puntos1, dados);
        }
        // ENTRE TURNOS
        if(generalaServida1 && generalaServida2)
        {
            break;
        }
        entreTurnos(nombre2, nombre1, puntos2, puntos1, tiradas2, rondas);
        // JUGADOR 2
        cls();
        tirada = 0;
        opcion = ' ';
        cout << "TURNO DE " << nombre2 << " | ";
        cout << "RONDA N" << char(248) << rondas << " | ";
        cout << "PUNTAJE TOTAL: " << sumarPuntos(puntos2, 10) << " | " << endl;
        cout << "----------------------------------------------------" << endl;
        while (tirada < 3 && (opcion != 'N' && opcion != 'n'))
        {
            tirada++;
            tiradas2++;
            cout << "TIRADA N" << char(248) << tirada << " - ";
            cout << "TIRADAS TOTALES: " << tiradas2 << endl;
            cout << "----------------------------------------------------" << endl;
            if (tirada == 1)
            {
                cargaDados(dados);
            }
            else
            {
                cambioDados(dados);
            }
            mostrarDados(dados);
            cout << endl;
            if (tirada == 1 && generala(dados) && puntos2[9] == -1)
            {
                cls();
                cout << "---------------------" << endl;
                cout << "  GENERALA SERVIDA   " << endl;
                cout << "---------------------" << endl;
                cout << endl;
                puntos2[9] = 50;
                generalaServida2 = true;
                system("pause");
                break;
            }
            else if(generalaServida1 && !generala(dados))
            {
                generalaServida2 = true;
                break;
            }
            else
            {
                if (tirada != 3)
                {
                    cout << "CONTINUAR LANZANDO? (S/N): ";
                    cin >> opcion;
                    cout << endl;
                }
            }
        }
        cout << "----------------------------------------------------" << endl;
        // Comprueba si hubo generala entonces no ejecuta las funciones
        if (!generalaServida2)
        {
            ordenarVector(dados, 5);
            mostrarDados(dados);
            cargaPuntos(puntos2, dados);
        }
    }
    if(generalaServida1 && generalaServida2)
    {
        generalaServida = true;
    }
}

// Se encarga de fijarse si la nueva puntuacion que se pasa es mayor que alguna puntuacion anterior
void puntuacionMasAlta(int puntos[], char nombre[], int tiradas, char nombreMax[], int &tiradasMax, int &maxPuntuacion)
{
    if(sumarPuntos(puntos, 10) > maxPuntuacion)
    {
        maxPuntuacion = sumarPuntos(puntos, 10);
        strcpy(nombreMax, nombre);
        tiradasMax = tiradas;
    }
}
#endif // FUNCIONES_H_INCLUDED
