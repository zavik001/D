import numpy as np
import matplotlib.pyplot as plt

# Заданные уравнения
t = np.linspace(0, 1, 1000)
x = 4 * np.cos(4 * np.pi * t)
y = 4 * np.cos(4 * np.pi * t - np.pi / 2)

# Построение графика
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='Траектория движения')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Траектория движения частицы')
plt.grid(True)
plt.legend()
plt.show()
