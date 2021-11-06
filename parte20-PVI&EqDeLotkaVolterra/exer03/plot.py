import matplotlib.pyplot as plt
import numpy as np

fig_name = "image.png"

data = np.genfromtxt("saida.dat",delimiter=' ')

t = data[:,0]
s = data[:,1]
i = data[:,2]
r = data[:,3]

main_fig = plt.figure()
mainPlot = main_fig.add_axes([0.1, 0.1, 0.8, 0.8])

mainPlot.plot(t,s,color='#14f51b', lw=1.5, label="S")
mainPlot.plot(t,i,color='#e40c0c', lw=1.5, label="I")
mainPlot.plot(t,r,color='#06f9c4', lw=1.5, label="R")

mainPlot.set_xlabel('Time', fontsize=15)
mainPlot.set_ylabel('Population Density', fontsize=15)
#mainPlot.set_yticks(np.arange(0,10,step=0.5))
mainPlot.legend()

mainPlot.grid(True,axis='both',alpha=0.24)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)
#OUTPUT
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)