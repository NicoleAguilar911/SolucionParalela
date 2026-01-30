// SolucionParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 10

int main() {

    int tid;
    int A[N], B[N], R[N];

    //Medición de tiempo
    double start = omp_get_wtime();

    cout << "Inicializando arreglos con valores aleatorios...\n";

    srand((unsigned)time(nullptr));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    //Pedir número de hilos
    int nHilos;
    cout << "Cuantos hilos quieres trabajar: ";
    cin >> nHilos;

#ifdef _OPENMP
    omp_set_num_threads(nHilos);
#endif

    cout << "\nIniciando suma paralela...\n";

    //Región paralela 
#pragma omp parallel for private(tid)
    for (int i = 0; i < N; i++) {

        tid = omp_get_thread_num();

        R[i] = A[i] + B[i];

        cout << "Thread " << tid
            << " suma indice " << i
            << " -> " << A[i] << " + " << B[i]
            << " = " << R[i] << endl;
    }

    //Fin del tiempo
    double end = omp_get_wtime();

    // Resultados finales
    cout << "\nResultados finales:\n";
    for (int i = 0; i < N; i++) {
        cout << "R[" << i << "] = " << R[i] << endl;
    }

    cout << "\nTiempo transcurrido: " << end - start << " segundos\n";

    return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
