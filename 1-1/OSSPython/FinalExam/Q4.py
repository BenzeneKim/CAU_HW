import matplotlib.pyplot as plt
import numpy as np

X=np.arange(-3,3,0.001)
Y1=[x**2 for x in X]
Y2=[2*x-3 for x in X]

ax=plt.axes()

ax.plot(X,Y1,label="x**2")
ax.plot(X,Y2,label="2*x-3")

ax.set_title("My graph-1")
ax.spines.left.set_position('center')
ax.spines.right.set_color('none')
ax.spines.bottom.set_position('center')
ax.spines.top.set_color('none')


plt.legend()
plt.grid()
ax.set_xlabel('x')
ax.set_ylabel('y')

plt.show()
