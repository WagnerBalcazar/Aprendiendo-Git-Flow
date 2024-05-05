/**
 * @file Acreditacion.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Acreditacion{
    float trabajos;
    float lecciones;
    float aprendizajeAutonomo;
    float notaFinal;
};

int main(int argc, char const *argv[]){
    system("@cls||clear");
    
    struct Acreditacion acreditacion;    
    char estado[20];

    printf("Ingrese la nota promedio del trabajo en clase y extra-clase (/2.0): ");
    scanf("%f", &acreditacion.trabajos);
    getchar();
    printf("Ingrese la nota promedio de lecciones y participación en clase (/2.0): ");
    scanf("%f", &acreditacion.lecciones);
    getchar();
    printf("Ingrese la nota promedio del aprendizaje autónomo (/2.0): ");
    scanf("%f", &acreditacion.aprendizajeAutonomo);
    getchar();
    printf("Ingrese la nota promedio de evaluaciones (/4.0): ");
    scanf("%f", &acreditacion.notaFinal);
    getchar();

    acreditacion.notaFinal = acreditacion.trabajos + acreditacion.lecciones + acreditacion.aprendizajeAutonomo + acreditacion.notaFinal;

    if (acreditacion.notaFinal > 10 || acreditacion.notaFinal < 0){
        printf ("Los valores no corresponden a la escala de calificación\n");
        strcpy(estado, "NO EXISTE");
    } else{
        if (acreditacion.notaFinal >= 7.0){
            strcpy(estado, "APROBADO");
        } else{
            if (acreditacion.notaFinal >= 2.40){
                strcpy(estado, "EN SUSPENSO");
            } else{
                strcpy(estado, "REPROBADO");
            }
        }
    }
    printf("Nota final: %.2f ---> %s\n", acreditacion.notaFinal, estado);

    printf("Presione cualquier tecla para salir...");
    getchar();
    return 0;
}
