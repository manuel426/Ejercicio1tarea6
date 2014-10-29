/*#ejercicio 1
#Tarea 6 metodos computacionales*/
/* Manuel Ariza Fuentes y Billy Revelo */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double func_prime_1(double t, double x, double y, double a, double b);
double func_prime_2(double t, double x, double y, double c, double d);


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
 double a=0.0;
 double b=0.0;
 double c=0.0;
 double d=0.0;

double t;
double x;
double y;
 double dx=0.0;
 double dy=0.0;

/*Revisa que el numero de argumentos sea correcto*/
if(argc!=3){
printf("No se ingresaron los 2 argumentos requeridos \n");
exit(1);
}


double x[n_points];
double y[n_points];
double t[n_points];

for(i=0;i<n_points;i=i+i/n_points){
t[i]=i/n_points;
 }



/*Las condiciones iniciales */

 double t[0] = min_x;
double x[0] = atoi(argv[1]);
double y[0] = atoi(argv[2]);


}

double func_prime_1(double t, double x, double y, double a, double b){
  A=a;
  B=b;
  dx=A*x-B*x*y;
  return dx;
}

double func_prime_2(double t, double x, double y, double c, double d){
  C=c;
  D=d;
  dy=-C*y+D*x*y;

  return dy;
}

for(i=1;i<n_puntos;i++){
    
    k_1_prime1 = func_prime_1(t[i-1],x[i-1], y[i-1]);
    k_1_prime2 = func_prime_2(t[i-1],x[i-1], y[i-1]);
    
    #first step
    x1 = t[i-1]+ (h/2.0);
    y1_1 = x[i-1] + (h/2.0) * k_1_prime1;
    y2_1 = y[i-1] + (h/2.0) * k_1_prime2;
    k_2_prime1 = func_prime_1(x1, y1_1, y2_1);
    k_2_prime2 = func_prime_2(x1, y1_1, y2_1);
    
    #second step
    x2 = t[i-1] + (h/2.0);
    y1_2 = x[i-1] + (h/2.0) * k_2_prime1;
    y2_2 = y[i-1] + (h/2.0) * k_2_prime2;
    k_3_prime1 = func_prime_1(x2, y1_2, y2_2);
    k_3_prime2 = func_prime_2(x2, y1_2, y2_2);
    
    
    #third
    x3 = t[i-1] + h;
    y1_3 = x[i-1] + h * k_3_prime1;
    y2_3 = y[i-1] + h * k_3_prime2;
    k_4_prime1 = func_prime_1(x3, y1_3, y2_3;
    k_4_prime2 = func_prime_2(x3, y1_3, y2_3);
    
    #fourth step
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
char archivo[50]="poblaciones_x0_y0.dat";
    sprintf(archivo, "poblaciones_%d_%d.dat", atoi(argv[1]),atoi(argv[2]));
in = fopen(archivo,"w");
printf("El archivo fue creado con exito");
if(!in){
printf("problemas con el archivo %s\n", archivo);
exit(1);
}
for(i=0;i<n_points;i++){
fprintf(in, "%d %f\n", t[i], x[i],y[i]);
}
fclose(in);
return 0;
}
