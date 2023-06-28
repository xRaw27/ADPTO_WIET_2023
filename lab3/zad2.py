import random
import numpy as np
import pycosat
import matplotlib.pyplot as plt
from dimacs import loadX3C

n, S = loadX3C("x3c/10.yes.x3c")

print(n)
print(S)
