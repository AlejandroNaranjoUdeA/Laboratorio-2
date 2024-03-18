#include<iostream>
#include<conio.h>
#include<stdlib.h> //libreria para new y delete
#include<cstring>
#include<string>
#include"funciones.h"
using namespace std;


//Implementacion de las funciones:


//EJERCICIO 1:
void fun_a(int *pointer_x,int *pointer_y){
    int tmp = *pointer_x; //uso de una variable auxiliar para cambiar los valores de variable.
    *pointer_x = *pointer_y;
    *pointer_y = tmp;
}
void fun_b(int a[], int tam){
    int f, l; //variables locales
    int *b = a; //puntero de un arreglo a llamado b
    for (f = 0, l = tam -1; f < l; f++, l--) { //for con f=0, l=tam_arreglo-1 (9); hasta que f sea menor que l; f++, l--
        fun_a(&b[f], &b[l]); //se llama a la funcion fun_a con los parametros (direccion de memoria de b en [f], y la direccion
            //de memoria de b en [l]) es decir, que estos parametros van a ir hacia unos punteros.
    }
}

//EJERCICIO 2:
void fun_c(double *a, int n, double *promedio, double*suma){
    *suma = 0.0;
    for (int i = 0; i < n; i++){
        *suma += (*a + i); //suma = suma + (a+i) - aca lo unico que cambia es la variable i
    }
    *promedio = *suma / n; //n es el numero de veces que se introduce algo
}


//EJERCICIO 3:



//PROBLEMA 1:

void contarBilletesYMonedas(int cantidad) {
    int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int resultado[10] = {0}; // Arreglo para almacenar la cantidad de cada billete y moneda

    // Determinar la cantidad de cada billete y moneda necesaria
    for (int i = 0; i < 10; i++) {
        int billetesMonedas = cantidad / denominaciones[i];
        if (billetesMonedas > 0) {
            resultado[i] = billetesMonedas;
            cantidad %= denominaciones[i];
        }
    }

    // Mostrar la cantidad de cada billete y moneda necesaria
    for (int i = 0; i < 10; i++) {
        if (resultado[i] > 0) {
            cout << denominaciones[i] << ": " << resultado[i] << endl;
        }
    }

    // Mostrar el valor restante si no se puede lograr la cantidad deseada
    if (cantidad > 0) {
        cout << "Faltante: " << cantidad << endl;
    }
}


//PROBLEMA 2:
// Función para generar un arreglo de letras aleatorias
void generarArregloLetras(char letras[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        letras[i] = 'A' + rand() % 26; // Genera letras aleatorias de la A a la Z
    }
}

// Función para contar la frecuencia de cada letra en el arreglo
void contarFrecuenciaLetras(char letras[], int tamano, int frecuencia[]) {
    for (int i = 0; i < tamano; i++) {
        frecuencia[letras[i] - 'A']++; // Incrementa la frecuencia de la letra correspondiente, ejem: 'D'-'A'= 68-65= 3, es decir, D= letras[3].
    }
}

// Función para imprimir el arreglo de letras
void imprimirArregloLetras(char letras[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << letras[i];
    }
    cout << endl;
}

// Función para imprimir la frecuencia de cada letra
void imprimirFrecuenciaLetras(int frecuencia[]) {
    for (int i = 0; i < 26; i++) {
        char letra = 'A' + i;
        if (frecuencia[i] > 0) {
            cout << letra << ": " << frecuencia[i] << endl;
        }
    }
}

//PROBLEMA 3:
bool compararCadenas(const char* cadena1, const char* cadena2) {
    if (strlen(cadena1) != strlen(cadena2)) {
        return false; // Si las longitudes son diferentes, las cadenas no son iguales
    }

    return strcmp(cadena1, cadena2) == 0; // Compara el contenido de las cadenas
}

//PROBLEMA 4:
int convertirCadenaANumero(const char* cadena) {
    return stoi(cadena); //la funcion stoi propia de la libreria
}

//PROBLEMA 5:
void convertirAcadena(int num, string *puntero_cadena){
    *puntero_cadena= std::to_string(num); //to_string, funcion propia de la libreria <string> pasa de entero a caracter
}

//PROBLEMA 6:
void convertirAMayusculas(char* cadena) {
    while (*cadena) {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - ('a' - 'A');
        }
        ++cadena;
    }
}

//PROBLEMA 7:
void eliminarRepetidos(char* cadena) {
    int longitud = strlen(cadena);

    for (int i = 0; i < longitud; ++i) {
        for (int j = i + 1; j < longitud;) {
            if (cadena[i] == cadena[j]) {
                // Carácter repetido encontrado, eliminarlo
                for (int k = j; k < longitud; ++k) {
                    cadena[k] = cadena[k + 1];
                }
                --longitud;
            } else {
                ++j;
            }
        }
    }
}

//PROBLEMA 8:
// Función para separar los números del resto de los caracteres
void separarNumeros(char* cadena, char* texto, char* numeros) {
    // Recorre la cadena original
    while (*cadena) {
        // Verifica si el carácter actual es un número
        if (isdigit(*cadena)) {
            // Si es un número, lo agrega a la cadena de números
            *numeros = *cadena;
            ++numeros;
        } else {
            // Si no es un número, lo agrega a la cadena de texto
            *texto = *cadena;
            ++texto;
        }
        // Mueve el puntero a la siguiente posición en la cadena original
        ++cadena;
    }
    // Agrega terminadores nulos al final de las cadenas de texto y números
    *texto = '\0';
    *numeros = '\0';
}

//PROBLEMA 9:
// Función para sumar los bloques de n cifras en la cadena
int sumaBloques(int n, const char* cadena) {
    int suma = 0;
    int currentNum = 0;

    // Iterar sobre la cadena de caracteres
    for (int i = 0; cadena[i] != '\0'; ++i) {
        // Convertir el carácter a número y agregar al número actual
        currentNum = currentNum * 10 + (cadena[i] - '0');

        // Si la posición actual es múltiplo de n o es el último dígito
        if ((i + 1) % n == 0 || cadena[i + 1] == '\0') {
            suma += currentNum; // Sumar el número actual a la suma total
            currentNum = 0; // Reiniciar el número actual para el próximo bloque de n cifras
        }
    }

    return suma;
}


//PROBLEMA 10:
int romanoAArabigo(char c) {
    switch (c) {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default:  return 0;
    }
}

// Función que convierte un número romano a su equivalente arábigo
int convertirRomanoAArabigo(const char* numeroRomano) {
    int total = 0;

    // Iterar sobre los caracteres del número romano
    for (int i = 0; numeroRomano[i] != '\0'; i++) {
        int valorActual = romanoAArabigo(numeroRomano[i]);
        int valorSiguiente = romanoAArabigo(numeroRomano[i + 1]);

        // Verificar si se debe sumar o restar según las reglas del sistema romano
        if (valorActual < valorSiguiente) {
            total -= valorActual;
        } else {
            total += valorActual;
        }
    }

    return total;
}

//PROBLEMA 11:
const int FILAS = 15;
const int ASIENTOS_POR_FILA = 20;

// Función para mostrar el estado actual de la sala
void mostrarSala(char** sala) {
    cout << "Estado actual de la sala:" << endl;

    // Iterar sobre las filas y asientos para imprimir el estado
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            // Mostrar el contenido utilizando punteros
            cout << *(*(sala + i) + j) << " ";
        }
        cout << endl;
    }
}

// Función para inicializar la sala con asientos disponibles
void inicializarSala(char** sala) {
    // Iterar sobre las filas y asientos para establecer todos los asientos como disponibles
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            // Inicializar el contenido utilizando punteros
            *(*(sala + i) + j) = '-';
        }
    }
}

// Función para realizar una reserva de asiento
void reservarAsiento(char** sala, char fila, int asiento) {
    int filaIndex = fila - 'A';
    int asientoIndex = asiento - 1;

    // Verificar límites y estado del asiento antes de reservar
    if (filaIndex >= 0 && filaIndex < FILAS && asientoIndex >= 0 && asientoIndex < ASIENTOS_POR_FILA) {
        if (*(*(sala + filaIndex) + asientoIndex) == '-') {
            // Realizar la reserva utilizando punteros
            *(*(sala + filaIndex) + asientoIndex) = '+';
            cout << "Asiento reservado con exito." << endl;
        } else {
            cout << "El asiento ya esta reservado." << endl;
        }
    } else {
        cout << "Fila o asiento no valido." << endl;
    }
}

// Función para cancelar una reserva de asiento
void cancelarReserva(char** sala, char fila, int asiento) {
    int filaIndex = fila - 'A';
    int asientoIndex = asiento - 1;

    // Verificar límites y estado del asiento antes de cancelar la reserva
    if (filaIndex >= 0 && filaIndex < FILAS && asientoIndex >= 0 && asientoIndex < ASIENTOS_POR_FILA) {
        if (*(*(sala + filaIndex) + asientoIndex) == '+') {
            // Cancelar la reserva utilizando punteros
            *(*(sala + filaIndex) + asientoIndex) = '-';
            cout << "Reserva cancelada con exito." << endl;
        } else {
            cout << "El asiento no esta reservado." << endl;
        }
    } else {
        cout << "Fila o asiento no valido." << endl;
    }
}

// PROBLEMA 12:

int **puntero_matriz, numero_filas;

void pedirDatosDeMatriz(){
    cout<<"Ingrese el numero de filas de la matriz: "; cin>>numero_filas;

    //reservando memoria dinamica:
    puntero_matriz= new int* [numero_filas]; //reservando memoria dinamica para las filas
    for(int i=0; i<numero_filas; i++){
        puntero_matriz[i]= new int[numero_filas]; //reservando memoria dinamica para las columnas
    }

    cout<<"\n\nPidiendo datos al usuario: "; cout<<endl;
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            cout<<"Ingrese el dato de la posicion ["<<i<<"]["<<j<<"]: ";
            cin>>*(*(puntero_matriz+i)+j);
        }
    }
}

bool esCuadradoMagico(){
    int suma_objetivo;
    for(int i=0; i<numero_filas; i++){
        suma_objetivo += *(*puntero_matriz+i); //suma de la primera fila.
    }

    //verificar suma de filas y columnas
    for(int i=0; i<numero_filas; i++){
        int suma_fila=0, suma_columna=0;
        int **puntero_filas = puntero_matriz+i, /* este +i permite el cambio de fila.*/ **puntero_columnas= puntero_matriz;
        for(int j=0; j<numero_filas; j++){
            suma_fila += *(*puntero_filas+j);
            suma_columna += *(*(puntero_columnas+j)+i); //al sumar el j solo cambiamos de fila, y como i permanece constante en este for, no cambia la columna.
        }
        if((suma_fila != suma_objetivo)||(suma_columna != suma_objetivo)){
            return false;
        }
    }

    //no es necesario verificar si las diagonales tambien suman lo mismo ya que es una de las propiedades de los cuadrados magicos.
    //Si todas sus filas y columnas suman lo mismo, automaticamente, sus diagonales tambien tienen que dar lo mismo.

}

//PROBLEMA 13:
void pedirDatosImagen(int filas, int columnas, int **p_matriz){
    cout << "\n\nIngrese los elementos de la matriz:" << endl<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Ingrese el elemento en la posicion [" << i << "][" << j << "]: ";
            cin >> *(*(p_matriz+i)+j);
        }
    }
}

int contarEstrellas(int **p_matriz, int filas, int columnas) {
    int estrellas = 0;
    for (int i = 1; i < filas - 1; i++) { //se empieza desde 1 hasta filas - 1 ya que se nos indique que ignoremos los bordes
        for (int j = 1; j < columnas - 1; j++) {
            if (((*( *(p_matriz + i) + j) + *( *(p_matriz + i) + (j - 1)) + *( *(p_matriz + i) + (j + 1)) + *( *(p_matriz + (i - 1)) + j) + *( *(p_matriz + (i + 1)) + j))/5) > 6){
                estrellas++;
            }
        }
    }
    return estrellas;
}


