from dimacs import *
from alg_2_apro import vertex_cover
# from alg_logn import vertex_cover
from os import listdir

import matplotlib.pyplot as plt
import networkx as nx

# GRAPH_NAMES = [f"graph/{f}" for f in listdir("./graph/") if not f.endswith('.sol')]
GRAPH_NAMES = ["graph/e40"]

print(GRAPH_NAMES)


for name in GRAPH_NAMES:
    G = loadGraph(name)
    H = nx.from_dict_of_lists({u: list(adjacent) for u, adjacent in enumerate(G)})
    pos = nx.spring_layout(H)
    nx.draw_networkx_nodes(H, pos=pos, node_size=20, node_color="red")
    nx.draw_networkx_edges(H, pos=pos, width=2)
    plt.show()

    C = vertex_cover(G)
    print(C)
    saveSolution(name + ".sol", C)

