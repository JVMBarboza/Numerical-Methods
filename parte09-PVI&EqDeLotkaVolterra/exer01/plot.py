import matplotlib.pyplot as plt
import numpy as np

fig_name = "image.png"

data1 = np.genfromtxt("saida-0.5.dat",delimiter=' ')
data2 = np.genfromtxt("saida-0.7.dat",delimiter=' ')
data3 = np.genfromtxt("saida-0.9.dat",delimiter=' ')
data4 = np.genfromtxt("saida-1.1.dat",delimiter=' ')
data5 = np.genfromtxt("saida-1.3.dat",delimiter=' ')
data6 = np.genfromtxt("saida-1.5.dat",delimiter=' ')

x1 = data1[:,1]
y1 = data1[:,2]

x2 = data2[:,1]
y2 = data2[:,2]

x3 = data3[:,1]
y3 = data3[:,2]

x4 = data4[:,1]
y4 = data4[:,2]

x5 = data5[:,1]
y5 = data5[:,2]

x6 = data6[:,1]
y6 = data6[:,2]


main_fig = plt.figure()
mainPlot = main_fig.add_axes([0.1, 0.1, 0.8, 0.8])

mainPlot.plot(x1,y1,color='#07b404', lw=1.5, label="0.5")
mainPlot.plot(x2,y2,color='#f56b0f', lw=1.5, label="0.7")
mainPlot.plot(x3,y3,color='#f3c42b', lw=1.5, label="0.9")
mainPlot.plot(x4,y4,color='#95f32b', lw=1.5, label="1.1")
mainPlot.plot(x5,y5,color='#19f578', lw=1.5, label="1.3")
mainPlot.plot(x6,y6,color='#15efeb', lw=1.5, label="1.5")

mainPlot.set_xlabel('population 1', fontsize=15)
mainPlot.set_ylabel('population 2', fontsize=15)
mainPlot.legend()

mainPlot.grid(True,axis='both',alpha=0.24)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)
#OUTPUT
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)