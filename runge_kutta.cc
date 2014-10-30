/* Ejercicio 1
#Tarea 6 metodos computacionales*/
/* Manuel Ariza Fuentes y Billy Revelo */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float func_prime_1(float t, float x, float y);
float func_prime_2(float t, float x, float y);


int main(int argc, char **argv){
FILE *filename;

/* Constantes de derivacion */
float h=0.01;
float min_x = 0.0; 
float max_x = 1.0;
float n_points = ((max_x-min_x)/h);
int i=0;



/*Revisa que el numero de argumentos sea correcto*/
if(argc!=3){
printf("No se ingresaron los 2 argumentos requeridos \n");
exit(1);
}
/* Punteros de las 3 variables */
float* t;
float* x;
float* y;

/* Espacio para los 3 punteros */
 t = malloc(n_points*sizeof(float));
 x = malloc(n_points*sizeof(float));
 y = malloc(n_points*sizeof(float));



/*Las condiciones iniciales */

t[0] = min_x;
x[0] = atof(argv[1]);
y[0] = atof(argv[2]);


/*Funciones para el Runge_Kutta */
float k_1_prime1;
float k_1_prime2;
float x1;
float y1_1;
float y2_1;
float k_2_prime1;
float k_2_prime2;
float x2;
float y1_2;
float y2_2;
float k_3_prime1;
float k_3_prime2;
float x3;
float y1_3;
float y2_3;
float k_4_prime1;
float k_4_prime2;
float average_k_1;
float average_k_2;
float x_new;
float y_1_new;
float y_2_new;


/* Runge Kutta Fourth Order Step */

for(i=1;i<n_points;i++){
t[i]=0.0;
x[i] = 0.0;
y[i] = 0.0;

    
    k_1_prime1 = func_prime_1(t[i-1],x[i-1], y[i-1]);
    k_1_prime2 = func_prime_2(t[i-1],x[i-1], y[i-1]);
    
    /*#first step */
    x1 = t[i-1]+ (h/2.0);
    y1_1 = x[i-1] + (h/2.0) * k_1_prime1;
    y2_1 = y[i-1] + (h/2.0) * k_1_prime2;
    k_2_prime1 = func_prime_1(x1, y1_1, y2_1);
    k_2_prime2 = func_prime_2(x1, y1_1, y2_1);
    
    /* #second step*/
    x2 = t[i-1] + (h/2.0);
    y1_2 = x[i-1] + (h/2.0) * k_2_prime1;
    y2_2 = y[i-1] + (h/2.0) * k_2_prime2;
    k_3_prime1 = func_prime_1(x2, y1_2, y2_2);
    k_3_prime2 = func_prime_2(x2, y1_2, y2_2);
    
    
    /* #third*/
    x3 = t[i-1] + h;
    y1_3 = x[i-1] + h * k_3_prime1;
    y2_3 = y[i-1] + h * k_3_prime2;
    k_4_prime1 = func_prime_1(x3, y1_3, y2_3);
    k_4_prime2 = func_prime_2(x3, y1_3, y2_3);
    
			      /*fourth step*/
    average_k_1 = (1.0/6.0)*(k_1_prime1 + 2.0*k_2_prime1 + 2.0*k_3_prime1 + k_4_prime1);
    average_k_2 = (1.0/6.0)*(k_1_prime2 + 2.0*k_2_prime2 + 2.0*k_3_prime2 + k_4_prime2);
    
    x_new = t[i-1] + h;
    y_1_new = x[i-1] + h * average_k_1;
    y_2_new= y[i-1] + h * average_k_2;
    t[i]=x_new;
    x[i]=y_1_new;
    y[i]=y_2_new;
			      

}
    
/*Crea el archivo y escribe en el*/
char archivo[100]="poblaciones_x0_y0.dat";
sprintf(archivo, "poblaciones_%f_%f.dat", x[0],y[0]);
filename = fopen(archivo,"w");
printf("El archivo fue creado con exito");

if(!filename){
printf("problemas con el archivo %s\n", archivo);
exit(1);
}

/* Las 3 columnas de las variables, incluyendo las condiciones iniciales */
for(i=0;i<n_points;i++){
fprintf(filename, "%f %f %f \n", t[i], x[i],y[i]);
 
}
 fclose(filename);
 return 0;

}


/* Primera  ecuacion*/

float func_prime_1 (float t, float x, float y){
float dx;
float A=20.0;
float B=1.0;
 
  dx=A*x-B*x*y;
  return dx;
}


/* Segunda Ecuacion */
float func_prime_2 (float t, float x, float y){
float dy;
float C=30.0;
float D=1.0;
 
 dy=-C*y+D*x*y;

  return dy;
}
