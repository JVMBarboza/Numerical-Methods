import matplotlib.pyplot as plt
import numpy as np

fig_name = "image.png"

data = np.genfromtxt("saida.dat",delimiter=' ')

x = data[:,0]
y = data[:,1]
z = data[:,2]

main_fig = plt.figure()
mainPlot = main_fig.add_axes([0.1, 0.1, 0.8, 0.8])

mainPlot.plot(y,z,color='#07b404', lw=1.5, label="")
#mainPlot.plot(x,z,color='#f41a1a', lw=1.5, label="pop 2")

mainPlot.set_xlabel('population 1', fontsize=15)
mainPlot.set_ylabel('population 2', fontsize=15)

mainPlot.grid(True,axis='both',alpha=0.24)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)
#OUTPUT
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)