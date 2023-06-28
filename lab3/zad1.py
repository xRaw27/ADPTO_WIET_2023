import random
import numpy as np
import pycosat
import matplotlib.pyplot as plt

n = 10
k = 4
T = 100

a_arr = np.linspace(1, 10, 91)
print(a_arr)

S = [1, -1]
V = range(1, n + 1)

x = [int(a * n) for a in a_arr]
y = []
for a_n in x:
    satisfied = 0
    for _ in range(T):
        cnf = [[random.choice(V)*random.choice(S) for _ in range(k)] for _ in range(a_n)]
        sol = pycosat.solve(cnf)
        if sol != 'UNSAT':
            satisfied += 1
    y.append(satisfied / T)

plt.plot(x, y, 'ro')
plt.show()

# S = [1,-1]            # lista +/-
# V = range(1,n+1)      # lista zmiennych 1...n
# x = random.choice(V)*random.choice(S)  # losowo wybrana zmienna z losowym negowaniem
# print( x )
