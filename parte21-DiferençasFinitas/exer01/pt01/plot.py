import matplotlib.pyplot as plt
import numpy as np

fig_name = "image.png"

data20   = np.genfromtxt("saida-20.dat",delimiter=' ')
data50   = np.genfromtxt("saida-50.dat",delimiter=' ')
data100  = np.genfromtxt("saida-100.dat",delimiter=' ')
data1000 = np.genfromtxt("saida-1000.dat",delimiter=' ')

x20 = data20[:,0]
y20 = data20[:,1]
x50 = data50[:,0]
y50 = data50[:,1]
x100 = data100[:,0]
y100 = data100[:,1]
x1000 = data1000[:,0]
y1000 = data1000[:,1]

main_fig = plt.figure()
mainPlot = main_fig.add_axes([0.1, 0.1, 0.8, 0.8])

mainPlot.plot(x20   ,y20   ,color='#f46506' ,lw=1.25 , ls='solid', label="N = 20")
mainPlot.plot(x50   ,y50   ,color='#f6c604' ,lw=1.90 , ls='dotted', label="  = 50")
mainPlot.plot(x100  ,y100  ,color='#7fff00' ,lw=1.5 , ls='dashed', label="  = 100")
mainPlot.plot(x1000 ,y1000 ,color='#05fafa' ,lw=1.5 , ls='dotted', label="  = 1000")
#mainPlot.plot(x,z,color='#f41a1a', lw=1.5, label="pop 2")

mainPlot.set_xlabel('x', fontsize=15)
mainPlot.set_ylabel('Temperature (K)', fontsize=15)
mainPlot.legend()

mainPlot.grid(True,axis='both',alpha=0.24)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)
#OUTPUT
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)