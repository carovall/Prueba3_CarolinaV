#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dm.h"
#define NPASOS 1000
#define NFREQ_DUMP 20
#define NFREQ_INFO 100

void equilibrar(void);

int main(int argc, char *argv[]) {

  equilibrar();
     
  FILE *archivo = fopen("equilibrio.dat", "r");

   // El archivo será leído linea a linea
   char string[1024]; // variable para alojar cada linea del archivo
   char *token = NULL; // Definimos para separar columnas de la linea
   int num_lineas= 800; // total de lineas
   // Definir arrays para guardar informacion de las velocidades
   float x_velocidad[800]={0};
   float y_velocidad[800]={0};
   float z_velocidad[800]={0};
   float magnitud[800]={0};

   // leer primeras 2 lineas
   for (int i=0; i<2; ++i) {
      fgets(string, 1024, archivo); //lee hasta que termine la linea y se lo asigna a string
   }
   for (int i=0; i<num_lineas; ++i) {
      fgets(string,1024, archivo);
      token = strtok(string, " ");
      for (int j = 0; j<11; j++){
        token = strtok(NULL, " ");
        if (j==3){
           x_velocidad[i] = atof(token);
       }
        if (j==4){
           y_velocidad[i] = atof(token);
       }
        if (j==5){
           z_velocidad[i] = atof(token);
       }
     }
   }
   fclose(archivo);
   
   FILE *archivo2 = fopen("magnitud.dat", "w");
   for (int i=0; i<800; ++i){
     magnitud[i]=sqrt((x_velocidad[i])*(x_velocidad[i])+(y_velocidad[i])*(y_velocidad[i])+(z_velocidad[i])*(z_velocidad[i]));
     fprintf(archivo2, "%f\n", magnitud[i]);
    }
   fclose(archivo2);
   
   return 0;
}

void equilibrar(void){
  double densidad = 0.8;
  double temp_inicio = 2.0;
  double temp = 1.0;
  double semilla = 1234;
  int numero_particulas = 800;
  double dt = 0.005;
  int numero_pasos = 1000;
  int nfreq_dump = 1000;

  sys *sistema = system_alloc(numero_particulas, dt,
                              nfreq_dump, NFREQ_INFO);
  crear_red_sc(sistema, densidad);
  crear_velocidades_gaussiana(sistema, temp_inicio, semilla);

  set_outputs(sistema, "equilibrio.dat");
  agregar_termostato(sistema, temp, 500, 1000, 20);
  simular(sistema, numero_pasos);
  system_free(sistema);
}
