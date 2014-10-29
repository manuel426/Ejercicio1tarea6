/*#ejercicio 1
#Tarea 6 metodos computacionales*/
/* Manuel Ariza Fuentes y Billy Revelo */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int main(int argc, char **argv){
FILE *in;

h=0.01;
min_x = 0.0;
max_x = 6.0;
n_points = int((max_x-min_x)/h);
double A=20.0;
double B=1.0;
double C=30.0;
double D=1.0;

double x[n_points];
double y_1[n_points];
double y_2[n_points];
double t[n_points];
for(i=0;i<n_points;i=i+i/n_points){
t[i]=i/n_points;
}

/*Revisa que el numero de argumentos sea correcto*/
if(argc!=3){
printf("No se ingresaron los 2 argumentos requeridos \n");
exit(1);
}

/*we use our initial conditions */
double x[0] = min_x;
double y_1[0] = 0.0;
double y_2[0] = 0.0;

x[0] = min_x
y_1[0] = atoi(argv[1]);
y_2[0] = atoi(argv[2]);


}

double func_prime_1(x, y_1, y_2){
return y_2
}

double func_prime_2(x, y_1, y_2){
    return y_1
}



double RungeKuttaFourthOrderStep(x[0], y_1[0], y_2[0]){
    
    k_1_prime1 = func_prime_1(x_old,y1_old, y2_old);
    k_1_prime2 = func_prime_2(x_old,y1_old, y2_old);
    
    #first step
    x1 = x_old+ (h/2.0);
    y1_1 = y1_old + (h/2.0) * k_1_prime1;
    y2_1 = y2_old + (h/2.0) * k_1_prime2;
    k_2_prime1 = func_prime_1(x1, y1_1, y2_1);
    k_2_prime2 = func_prime_2(x1, y1_1, y2_1);
    
    #second step
    x2 = x_old + (h/2.0);
    y1_2 = y1_old + (h/2.0) * k_2_prime1;
    y2_2 = y2_old + (h/2.0) * k_2_prime2;
    k_3_prime1 = func_prime_1(x2, y1_2, y2_2);
    k_3_prime2 = func_prime_2(x2, y1_2, y2_2);
    
    
    #third
    x3 = x_old + h;
    y1_3 = y1_old + h * k_3_prime1;
    y2_3 = y2_old + h * k_3_prime2;
    k_4_prime1 = func_prime_1(x3, y1_3, y2_3;
    k_4_prime2 = func_prime_2(x3, y1_3, y2_3);
    
    #fourth step
    average_k_1 = (1.0/6.0)*(k_1_prime1 + 2.0*k_2_prime1 + 2.0*k_3_prime1 + k_4_prime1);
    average_k_2 = (1.0/6.0)*(k_1_prime2 + 2.0*k_2_prime2 + 2.0*k_3_prime2 + k_4_prime2);
    
    x_new = x_old + h;
    y_1_new = y1_old + h * average_k_1;
    y_2_new= y2_old + h * average_k_2;
    return x_new, y_1_new, y_2_new
}
    
    
    
/*Crea el archivo y escribe en el*/
char archivo[50]="poblaciones_x0_y0.dat";
    sprintf(archivo, "poblaciones_%d_%d.dat", atoi(argv[1]),atoi(argv[2]));
in = fopen(archivo,"w");
printf("El archivo fue creado con exito");
if(!in){
printf("problems opening the file %s\n", archivo);
exit(1);
}
for(i=0;i<n_points;i++){
fprintf(in, "%d %f\n", t[i], x[i],y[i]);
}
fclose(in);
return 0;
}
