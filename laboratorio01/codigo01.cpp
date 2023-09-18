#include<iostream>           // Inclusión de bibliotecas estándar de C++
#include<fstream>            // Para trabajar con archivos
#include <string>            // Para manipular cadenas de texto
#include <vector>            // Para trabajar con vectores
#include <random>            // Para generación de números aleatorios
#include <cmath>             // Para operaciones matemáticas

using namespace std;         // Uso del espacio de nombres estándar de C++

// Función que calcula la distancia euclidiana entre dos puntos en cualquier dimensión.
double distanciaEuclidiana(const std::vector<double>& punto1, const std::vector<double>& punto2) {
    double distancia = 0.0;
    for (size_t i = 0; i < punto1.size(); ++i) {
        double diferencia = punto1[i] - punto2[i];
        distancia += diferencia * diferencia;
    }
    return std::sqrt(distancia);
}

int main(){
    int cont = 1;
    ofstream archivo("Distancias.csv", ios::app);  // Abre un archivo llamado "Distancias.csv" en modo de apendizaje.

    // Declaración de varios vectores para almacenar distancias en diferentes dimensiones.
    std::vector<double> distancias10;
    distancias10.reserve(4950);
    std::vector<double> distancias50;
    distancias50.reserve(4950);
    std::vector<double> distancias100;
    distancias100.reserve(4950);
    std::vector<double> distancias500;
    distancias500.reserve(4950);
    std::vector<double> distancias1000;
    distancias1000.reserve(4950);
    std::vector<double> distancias2000;
    distancias2000.reserve(4950);
    std::vector<double> distancias5000;
    distancias5000.reserve(4950);   

    std::random_device rd;  // Inicializa un generador de números aleatorios.
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);  // Distribución uniforme entre 0 y 1.

    // Vector que almacena las dimensiones que se utilizarán.
    std::vector<int> dimensiones = {10, 50, 100, 500, 1000, 2000, 5000};

    // Loop a través de las dimensiones.
    for (int d : dimensiones) {
        std::vector<std::vector<double>> puntos;
        puntos.reserve(100);

        // Generación de 100 puntos aleatorios en la dimensión actual.
        for (int i = 0; i < 100; ++i) {
            std::vector<double> punto;
            punto.reserve(d);
            for (int j = 0; j < d; ++j) {
                punto.push_back(dis(gen));  // Genera un valor aleatorio entre 0 y 1 y lo agrega al punto.
            }
            puntos.push_back(punto);
        }

        // Cálculo de las distancias entre todos los pares de puntos en esta dimensión.
        for (size_t i = 0; i < puntos.size(); ++i) {
            for (size_t j = i + 1; j < puntos.size(); ++j) {
                double distancia = distanciaEuclidiana(puntos[i], puntos[j]);
                // Almacena la distancia en el vector correspondiente según la dimensión.
                if(d==10){
                    distancias10.push_back(distancia);
                }
                if(d==50){
                    distancias50.push_back(distancia);
                }
                if(d==100){
                    distancias100.push_back(distancia);
                }
                if(d==500){
                    distancias500.push_back(distancia);
                }
                if(d==1000){
                    distancias1000.push_back(distancia);
                }
                if(d==2000){
                    distancias2000.push_back(distancia);
                }
                if(d==5000){
                    distancias5000.push_back(distancia);
                }
            }
        }
        puntos.clear();  // Limpia el vector de puntos para la próxima dimensión.

    }

    // Definición de nombres de columnas en el archivo CSV.
    string d10, d50, d100, d500, d1000, d2000, d5000;
    d10= "Distancia_10";
    d50= "Distancia_50";
    d100= "Distancia_100";
    d500= "Distancia_500";
    d1000= "Distancia_1000";
    d2000= "Distancia_2000";
    d5000= "Distancia_5000";
    
    // Escribir los nombres de las columnas en el archivo CSV.
    archivo << d10 << ";" << d50 << ";" << d100
    << ";" << d500 << ";" << d1000 << ";" << d2000
    << ";" << d5000 << endl;

    int tamano = distancias10.size();

    // Escribir las distancias en el archivo CSV.
    for (int i = 0; i < tamano; i++) {
        archivo << distancias10[i] << ";" << distancias50[i] << ";" << distancias100[i]
        << ";" << distancias500[i] << ";" << distancias1000[i] << ";" << distancias2000[i]
        << ";" << distancias5000[i] << endl;
    }

    archivo.close();  // Cerrar el archivo CSV.

    return 0;
}
