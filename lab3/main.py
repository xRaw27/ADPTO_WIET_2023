import pycosat

cnf = [[-1, 2, 3], [2, -3], [1, -2, -3]]
sol = pycosat.solve(cnf)
print(sol)
