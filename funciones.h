#ifndef FUNCIONES_H
#define FUNCIONES_H

#endif // FUNCIONES_H

#include<string>
//EJERCICIO 1:
//prototipo de las funciones (no se hace uso de ninguna variable global):
void fun_a(int *pointer_x, int *pointer_y);
void fun_b(int a[], int tam);


//EJERCICIO 2:
void fun_c(double *, int , double *, double *);


//EJERCICIO 3:



//PROBLEMA 1:
void contarBilletesYMonedas(int );


//PROBLEMA 2:
void generarArregloLetras(char [], int );
void contarFrecuenciaLetras(char [], int , int []);
void imprimirArregloLetras(char [], int );
void imprimirFrecuenciaLetras(int []);

//PROBLEMA 3:
bool compararCadenas(const char* , const char* );

//PROBLEMA 4:
int convertirCadenaANumero(const char* );

//PROBLEMA 5:
void convertirAcadena(int , std::string *);

//PROBLEMA6:
void convertirAMayusculas(char* );

//PROBLEMA 7:
void eliminarRepetidos(char*);

//PROBLEMA 8:
void separarNumeros(char*, char* , char* );

//PROBLEMA 9:
int sumaBloques(int , const char*);

//PROBLEMA 10:
int romanoAArabigo(char );
int convertirRomanoAArabigo(const char*);

//PROBLEMA 11:
extern const int FILAS;
extern const int ASIENTOS_POR_FILA;
void mostrarSala(char** );
void inicializarSala(char** );
void reservarAsiento(char** , char , int );
void cancelarReserva(char** , char , int );













