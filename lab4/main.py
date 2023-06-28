
from dimacs import loadCNF
from solver1 import solver1

import os

tests_path = "./sat"
tests = ["./sat/30.yes.sat", "./sat/30.no.sat"]

# for path in os.listdir(tests_path):
#     full_path = os.path.join(tests_path, path)
#     if os.path.isfile(full_path):
#         tests.append(full_path)

for test in tests:
    n, cnf = loadCNF(test)
    res = solver1(cnf, n)
    print(n)
    print(cnf)
    print(res)
