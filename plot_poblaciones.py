import numpy as np
import sys
import matplotlib.pyplot as plt


#Importa el archivo
filename = sys.argv[1]
#cargar datos del archivo
matriz = np.loadtxt(filename)
#definir arreglos para graficar
t= matriz[:,0]
x = matriz[:,1]
y = matriz[:,2]


#Graficar
plt.plot(x,y)
plt.xlabel('Numero de Presas')
plt.ylabel('Numero de cazadores')
plt.title('Dinamica de cazador-presa')

#Guarda en un pdf
plt.savefig(str(filename)+'.pdf',format='pdf')
