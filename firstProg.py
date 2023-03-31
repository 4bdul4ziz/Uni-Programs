# plotting a curve import matplotlib.pyplot as pltimport numpy as np
import matplotlib as plt
import numpy as np

x = np.linspace(0, 20, 200)
y = 2 * np.sin(x)
fig, ax = plt.subplots()
ax.plot(x, y, linewidth=2.0, color="r")
ax.set(xlim=(0, 20), ylim=(-3, 3))
plt.show()
