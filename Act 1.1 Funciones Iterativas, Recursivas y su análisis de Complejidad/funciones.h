/*
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

/*#include <iostream>
using namespace std;*/


class Funciones
{
    public:
        Funciones(){};

        long sumaIterativa(int);
        long sumaRecursiva(int);
        long sumaDirecta(int);
};

long Funciones::sumaIterativa(int n){
    int acum=0;
    int i=1;
    if(n<0){
        return 0;
    }else{
        while(i<=n){
        acum=acum+i;
        i++;
    }
    return acum;
    }
}


long Funciones::sumaRecursiva(int n){
    if (n<=0){
        return 0;
    }else{
        if (n <= 1)
    {
        return 1;
    }else {
        return n + sumaRecursiva(n-1);
    }
    }
}

long Funciones::sumaDirecta(int n){
    int acum=0;
    if (n>=0){
        acum=(n*(n+1))/2;
        return acum;
    }else{
        return 0;
    }
}

#endif // FUNCIONES_H
