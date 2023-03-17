from dimacs import *
from backtracking_2_to_k import vertex_cover

GRAPH_NAMES = ["graph/e40"]

for name in GRAPH_NAMES:
    G = loadGraph(name)

    print(G)
    print(edgeList(G))
    for k in range(1, len(G)):
        C = vertex_cover(G, k)
        if C:
            print(C)
            saveSolution(name + ".sol", C)
            break

