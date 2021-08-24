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
    if(n==0){
        return acum;
    }else if (n==1){
        acum=1;
        return acum;
    }else if (n==2){
        acum=1+2;
        return acum;
    }else if (n==3){
        acum=1+2+3;
        return acum;
    }else if (n==4){
        acum=1+2+3+4;
        return acum;
    }else if (n==5){
        acum=1+2+3+4+5;
        return acum;
    }else if (n==6){
        acum=1+2+3+4+5+6;
        return acum;
    }else if (n==7){
        acum=1+2+3+4+5+6+7;
        return acum;
    }else if (n==8){
        acum=1+2+3+4+5+6+7+8;
        return acum;
    }else if (n==9){
        acum=1+2+3+4+5+6+7+8+9;
        return acum;
    }else if (n==10){
        acum=1+2+3+4+5+6+7+8+9+10;
        return acum;
    }else if (n==11){
        acum=1+2+3+4+5+6+7+8+9+10+11;
        return acum;
    }else if (n==12){
        acum=1+2+3+4+5+6+7+8+9+10+11+12;
        return acum;
    }else{
        return 0;
    }
}

#endif // FUNCIONES_H
