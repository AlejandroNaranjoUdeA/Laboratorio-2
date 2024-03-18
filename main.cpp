#include"funciones.h"
#include<stdlib.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<cctype> //se usa en el problema 5 para pasar de minusculas a mayusculas
using namespace std;

/*EJERCICIO 1. Codifica el programa que se muestra a continuación:

Con ayuda del debugger, examina la representación en memoria del arreglo array y responde las siguientes
preguntas.
● ¿Cuál es su dirección en memoria? ¿Cuántos bytes se dedican para almacenar cada elemento de array?
● ¿Cuál es la dirección y el contenido en memoria del elemento array [3]?
● Describe el efecto que tiene la función fun_b, sobre el arreglo array
*/

//este programa lo que hace es que mueve de posiciones los elementos del arreglo, es decir, en este arreglo en concreto, estan en orden ascendente.
//y lo que hace es como rotarlos de forma inversa, dejandolos en orden descendente
/*

//funcion principal:
int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //arreglo de 10
    fun_b(array, 10);
    for(int i=0; i<10; i++){ //for para imprimir como quedo el arreglo en pantalla
        cout<<array[i]<<", ";
    }

    return 0;
}
*/

/*
EJERCICIO 2:
La función que se ilustra a continuación calcula el promedio de los elementos de un arreglo de tamaño n.
Promedio y suma apuntan a variables que la función modifica por referencia. Desafortunadamente, la función
contiene errores; encuéntralos y corrígelos, de tal manera que su operación sea correcta.

void fun_c(double *a, int n, double *promedio, double*suma){
    int i;
    suma = 0.0;
    for (i = 0; i < n; i++)
        suma += (a + i);
    promedio = suma / n;
}

En principio, vemos que en la implementacion de la funcion vemos varios errores, empezando por que en
- suma=0.0; aca hay un error ya que en principio, la variable suma es un puntero que apunta a una direccion de memoria, por lo que no puede ser igualada a 0.
- Tambien, aunque no sea un error, es innceserio declarar la variable int i al inicio cuando se puede poner facilmente en el for.
- El segundo error que le vi es que el for no tiene llaves, se podria poner (suma += (a+i)) pero inmediatamente despues de cerrar el parentesis en la declaracion
del for
- El tercer error es que, de igual forma que con suma, promedio tambien ha sido ingresado en los parametros como un puntero, por lo que no se puede igualar una
direccion de memoria con un numero. Y tambien se hace lo mismo con suma.


Implementa un caso de prueba para la función anterior, que te permita verificar su correcto funcionamiento.

*/
/*
int main(){

    double A=3, prom, sum;

    fun_c(&A, 10, &prom, &sum);

    cout<<"\n"<<prom<<endl; //imprimiendo promedio

    return 0;
}
*/

/*EJERCICIO 3:
Se tiene la siguiente declaración e inicialización para el arreglo b:

unsigned short b[4][2]= {{77,50},{5,2},{28,39},{99,3}}; matriz b de 4x2 compuesta por numeros enteros sin signo cortos

Completa la numeración de las direcciones de memoria,
en notación hexadecimal, para cada elemento del arreglo b.

*/

//PROBLEMA 1:
/*
Se necesita un programa que permita determinar la mínima combinación de billetes y monedas para una
cantidad de dinero determinada. Los billetes en circulación son de $50.000, $20.000, $10.000, $5.000, $2.000 y
$1.000, y las monedas son de $500, $200, $100 y $50. Haz un programa que entregue el número de billetes y
monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas
disponibles no se puede lograr la cantidad deseada, el sistema deberá decir lo que resta para lograrla. Usa arreglos
y ciclos para realizar el programa.
Ejemplo: si se ingresa 47810, el programa debe imprimir:
50000: 0
20000: 2
10000: 0
5000: 1
2000: 1
1000: 0
500: 1
200: 1
100: 1
50: 0
Faltante: 10
Realiza una versión en Arduino de este programa (en un Arduino físico o Tinkercad), la cantidad de dinero debe
ser ingresada con la ayuda del serial. Usa el monitor serial de Arduino o Tinkercad para ingresar los valores
necesarios e imprimir.
*/
/*
int main(){

    int cantidad;
    cout<<"Ingrese una cantidad de dinero: "; cin>>cantidad;
    contarBilletesYMonedas(cantidad); //llamado a la funcion

    return 0;
}
*/

//PROBLEMA 2:
/*
Elabora un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprime este arreglo y luego
imprime cuantas veces se repita cada letra en el mismo.
Ejemplo: supón que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir:
ABARSECAAB
A: 4
B: 2
C: 1
Y así sucesivamente
*/
/*
int main(){

    const int tamano = 200; //variable constante
    char letras[tamano];
    int frecuencia[26] = {0}; // 26 letras del alfabeto

    srand(time(0)); // Inicializa la semilla para obtener diferentes resultados en cada ejecución

    generarArregloLetras(letras, tamano);
    contarFrecuenciaLetras(letras, tamano, frecuencia);
    imprimirArregloLetras(letras, tamano);
    imprimirFrecuenciaLetras(frecuencia);

    return 0;
}
*/

//PROBLEMA 3:
/*
Haz una función que compare 2 cadenas de caracteres y retorne un valor lógico verdadero si son iguales, y
falso en caso contrario, no olvides también tener en cuenta la longitud de las cadenas. Escribe un programa de
prueba.
*/
/*
int main(){

    const char* cadena1 = "Hola";
    const char* cadena2 = "Hola";

    if (compararCadenas(cadena1, cadena2)) {
        cout << "Las cadenas son iguales." <<endl<<endl;
    } else {
        cout << "Las cadenas son diferentes." <<endl<<endl;
    }

    return 0;
}
*/

//PROBLEMA 4:
/*
Haz una función que reciba una cadena de caracteres numéricos, la convierta a un número entero y retorne
dicho número. Escribe un programa de prueba.
Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123
*/
/*
int main(){

    char cadena[20];  // Puedes ingresar una cadena de hasta 19 caracteres
    cout << "Ingresa una cadena de caracteres numericos: ";
    cin >> cadena;

    int resultado = convertirCadenaANumero(cadena);

    cout << "El numero entero convertido es: " << resultado << endl;


    return 0;
}
*/

//PROBLEMA 5:
/*
Haz una función que reciba un número entero (int) y lo convierta a cadena de caracteres. Usa parámetros por
referencia para retornar la cadena. Escribe un programa de prueba.
Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.
*/
/*
int main(){

    int numero;
    cout<<"Ingresa un numero: "; cin>>numero;
    std::string resultado;

    convertirAcadena(numero, &resultado);// se pasa a traves de referencia hacia un puntero

    cout<<"El resultado de la conversion es: "<<resultado<<endl;


    return 0;
}
*/

//PROBLEMA 6:
/*
Escribe un programa que reciba una cadena de caracteres y cambie las letras minúsculas por mayúsculas, los demás caracteres no deben ser alterados.

Ejemplo: si recibe Man-zana debe mostrar MAN-ZANA.

Nota: la salida del programa debe ser: Original: Man-zana. En mayúscula: MAN-ZANA.
*/

/*
int main() {
    // Leer la cadena de caracteres
    cout << "Ingrese una cadena de caracteres: ";
    string cadena;
    getline(cin, cadena); //guardar un string

    // Mostrar la cadena original
    cout << "\nOriginal: " << cadena << endl;

    // Convertir letras minúsculas a mayúsculas utilizando la tabla ASCII
    char* punteroCadena = &cadena[0];
    convertirAMayusculas(punteroCadena);

    // Mostrar la cadena con letras en mayúsculas
    cout << "\nEn mayuscula: " << cadena << endl<< endl;



        return 0;
}
*/

//PROBLEMA 7:
/*
Escribe un programa que reciba una cadena de caracteres y elimina los caracteres repetidos.
Ejemplo: se recibe bananas debe mostrar bans.
Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.
*/

/*
int main() {
    // Leer la cadena de caracteres
    cout << "Ingrese una cadena de caracteres: ";

    // Utilizar memoria dinámica para almacenar la cadena
    char* cadena = new char[100];
    cin.getline(cadena, 100);

    // Mostrar la cadena original
    cout << "Original: " << cadena << endl;

    // Eliminar caracteres repetidos
    eliminarRepetidos(cadena);

    // Mostrar la cadena sin caracteres repetidos
    cout << "Sin repetidos: " << cadena << endl;

    // Liberar la memoria asignada dinámicamente
    delete[] cadena;

    return 0;
}
*/

//PROBLEMA 8:
/*
Escribe un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
generando una cadena que no tiene números y otra con los números que había en la cadena original.
Ejemplo: Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
Nota: la salida del programa debe ser:
Original: abc54rst.
Texto: abcrst. Numero: 54.
*/
/*
int main() {
    // Leer la cadena de caracteres
    cout << "Ingrese una cadena de caracteres: ";
    char cadena[100];
    cin.getline(cadena, sizeof(cadena));

    // Crear cadenas para texto y números
    char texto[100];
    char numeros[100];

    // Separar números del resto de caracteres
    separarNumeros(cadena, texto, numeros);

    // Mostrar la cadena original, la cadena de texto y la cadena de números
    cout << "Original: " << cadena << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numero: " << numeros << endl;

        return 0;
}
*/

//PROBLEMA 9:
/*
Escribe un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa debe
separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma sería 087+512+395=994.
Nota: la salida del programa debe ser:
Original: 87512395.
Suma: 994
*/
/*
int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Validar n positivo
    while(n <= 0) {
        cout << "Ingrese un valor positivo para n: " ;
        cin>>n;
    }

    char cadena[100];
    cout << "Ingrese la cadena de caracteres numericos: ";
            cin >> cadena;

    // Calcular la suma utilizando la función
    int resultado = sumaBloques(n, cadena);

    // Imprimir resultados
    cout << "Original: " << cadena << "." << endl;
    cout << "Suma: " << resultado << endl;

    return 0;
}
*/

//PROBLEMA 10:
/*
Escribe un programa que permita convertir un número en el sistema romano al sistema arábigo usado
actualmente. A continuación, se encuentran los caracteres usados en el sistema romano y su equivalente arábigo:
M: 1000
D: 500
C: 100
L: 50
X: 10
V: 5
I: 1
Los números romanos se forman usando estos caracteres en base a dos reglas:
● Si un carácter está seguido por uno de igual o menor valor, su valor se suma al total.
● Si un carácter está seguido por uno de mayor valor, su valor se resta del total.
Ejemplo: CC=200, CD=400, DC=600, DCLXVI=666, CLXXIV=174.
Nota: la salida del programa debe ser
El número ingresado fue: DCLXVI
Que corresponde a: 666.
*/
/*
int main() {
    char numeroRomano[50];

    // Solicitar al usuario que ingrese un número romano
    cout << "Ingrese un numero romano: ";
    cin >> numeroRomano;

    // Llamar a la función de conversión e imprimir el resultado
    int resultado = convertirRomanoAArabigo(numeroRomano);

    cout << "El numero ingresado fue: " << numeroRomano << endl;
    cout << "Que corresponde a: " << resultado << endl;

    return 0;
}
*/

//PROBLEMA 11:
/*
Escribe un programa que permita manejar las reservas de asientos en una sala de cine, estos están organizados
en 15 filas con 20 (asientos) cada una. El programa debe mostrar una representación de la sala, que indique qué
asientos están disponibles y cuales se encuentran reservados. Además, debe permitir realizar reservas o
cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).
Nota: un ejemplo de visualización de una sección de la sala es el siguiente:
+ + + +
- - + +
- - - -
Donde + representa los asientos reservados y - representa los asientos disponibles
*/
/*
const int FILAS = 15;
const int ASIENTOS_POR_FILA = 20;

int main() {
    // Crear la sala utilizando un array de punteros
    char** sala = new char*[FILAS];
    for (int i = 0; i < FILAS; i++) {
        sala[i] = new char[ASIENTOS_POR_FILA];
    }

    // Inicializar la sala con asientos disponibles
    inicializarSala(sala);

    // Menú principal
    char opcion;
    do {
        mostrarSala(sala);
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Reservar asiento" << endl;
        cout << "2. Cancelar reserva" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1': {
            char fila;
            int asiento;
            cout << "Ingrese la fila (letras A-O): ";
            cin >> fila;
            cout << "Ingrese el numero del asiento (1-20): ";
            cin >> asiento;
            reservarAsiento(sala, fila, asiento);
            break;
        }
        case '2': {
            char fila;
            int asiento;
            cout << "Ingrese la fila (letras A-O): ";
            cin >> fila;
            cout << "Ingrese el numero del asiento (1-20): ";
            cin >> asiento;
            cancelarReserva(sala, fila, asiento);
            break;
        }
        case '3':
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != '3');

    // Liberar la memoria al finalizar el programa
    for (int i = 0; i < FILAS; i++) {
        delete[] sala[i];
    }
    delete[] sala;

    return 0;
}
*/

//PROBLEMA 12:
/*
Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa
que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado
mágico.
Nota: un ejemplo de cuadrado mágico es el siguiente:
4 9 2
3 5 7
8 1 6
*/
/*
int main(){

    pedirDatosDeMatriz();

    if(esCuadradoMagico()==true){
        cout<<"\n\nLa matriz ingresada es un cuadrado magico."<<endl<<endl;
    }
    else{
        cout<<"\n\nLa matriz ingresada no es un cuadrado magico"<<endl<<endl;
    }

    //liberar la memoria dinamica utilizada:
    for(int i=0; i<numero_filas; i++){
        delete[] puntero_matriz[i]; //liberando espacio de las columnas
    }
    delete[] puntero_matriz; //liberando espacio de las filas

    return 0;
}
*/

//PROBLEMA 13:
/*
Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a 61.000.000 de
años luz del planeta Tierra. La representación digital de la imagen está constituida por una matriz de números
enteros; en la cual, cada uno representa la cantidad de luz en ese punto de la imagen, así:

0 3 4 0 0 0 6 8
5 13 6 0 0 0 2 3
2 6 2 7 3 0 10 0
0 0 4 15 4 1 6 0
0 0 7 12 6 9 10 4
5 0 6 10 6 4 8 0

Se puede determinar si el elemento ai,,j de la matriz representa una estrella si se cumple que:
(𝑎𝑎𝑖𝑖,𝑗𝑗 + 𝑎𝑎𝑖𝑖,𝑗𝑗−1 + 𝑎𝑎𝑖𝑖,𝑗𝑗+1 + 𝑎𝑎𝑖𝑖−1,𝑗𝑗 + 𝑎𝑎𝑖𝑖+1,𝑗𝑗)/5 >  6

Elabora y prueba una función que reciba un puntero a la matriz de enteros como argumento y que retorne el
número de estrellas encontradas en la imagen. Ignora las posibles estrellas que puedan existir en los bordes de la
matriz.
*/
/*
int main(){

    int filas, columnas, **p_matriz;

    cout<<"Ingrese el numero de filas de la imagen: "; cin>>filas;
    cout<<"Ingrese el numero de columnas de la imagen: "; cin>>columnas;

    p_matriz= new int *[filas]; //reservando memoria dinamica para las filas
    for(int i=0; i<filas; i++){
        p_matriz[i] = new int[columnas]; //reservando memoria dinamica para las columnas
    }
    pedirDatosImagen(filas, columnas, p_matriz);

    int resultado= contarEstrellas(p_matriz, filas, columnas);
    cout<<"\n\nEl numero de estrellas contadas en la imagen es de: "<<resultado<<endl<<endl;

    for(int i=0; i<filas; i++){
        delete[] p_matriz[i]; //eliminando espacio de memoria dinamica para las columnas
    }
    delete[] p_matriz; //eliminando espacio de memoria dinamica para las filas
}
*/

//PROBLEMA 14:
/*

*/
