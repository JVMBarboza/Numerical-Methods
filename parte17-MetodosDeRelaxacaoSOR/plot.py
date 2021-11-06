import matplotlib.pyplot as plt
import numpy as np

fig_name = "image02.png"

data = np.genfromtxt("saida-itemb.csv",delimiter=',')

x = data[:,0]
y = data[:,1]

main_fig = plt.figure()
mainPlot = main_fig.add_axes([0.1, 0.1, 0.8, 0.8])

mainPlot.plot(x,y,color='#07b404', lw=1.5)

mainPlot.set_xlabel('Iterações', fontsize=15)
#mainPlot.set_xticks(np.arange(1, 12, step=1))
mainPlot.set_ylabel('Norma do Vetor Resíduo', fontsize=15)
#mainPlot.set_yticks(np.arange(10, 915, step=60))

mainPlot.grid(True,axis='both',alpha=0.24)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)
#OUTPUT
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)