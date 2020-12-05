import matplotlib.pyplot as plt
import numpy as np

fig_name = "image.png"

data99  = np.genfromtxt("saida-99.dat",delimiter=' ')
data999 = np.genfromtxt("saida-999.dat",delimiter=' ')

x99 = data99[:,0]
y99 = data99[:,1]
y999 = data999[:,1]

j=0
k=0
for i in data999[:,0]:
    if i == x99[j]:
        y99[j] = np.fabs((y99[j] - y999[k]))  
        j = j+1
    k = k+1

main_fig = plt.figure()
mainPlot = main_fig.add_axes([0.119, 0.119, 0.855, 0.855])

mainPlot.plot(x99,y99,color='#307bfd',lw=1.80,ls='solid' , label="")

mainPlot.set_xlabel('x', fontsize=15)
mainPlot.set_ylabel('Difference between Temperatures (K)', fontsize=15)
mainPlot.legend()

mainPlot.grid(True,axis='both',alpha=0.24)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)
#OUTPUT
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)