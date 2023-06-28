from dimacs import loadGraph
from pulp import *
import matplotlib.pyplot as plt
import networkx as nx

GRAPH_NAMES = ["graph/p200"]

print(GRAPH_NAMES)


def edges(G):
    E = []
    for u, adjacent in enumerate(G):
        for v in adjacent:
            if v > u:
                E.append((u, v))
    return E


def vertex_cover(G):
    model = LpProblem("vertex_cover", LpMinimize)
    n = len(G)
    x = [LpVariable(f"x_{i}", cat="Binary") for i in range(n)]

    model += sum(x)

    E = edges(G)
    for u, v in E:
        model += x[u] + x[v] >= 1

    print(model)

    model.solve()

    result = []
    for i, x_i in enumerate(x):
        if x_i.value() > 0:
            result.append(i)

    return result


for name in GRAPH_NAMES:
    G = loadGraph(name)

    res = vertex_cover(G)
    print(G)
    print(f"result: {res}")

    H = nx.from_dict_of_lists({u: list(adjacent) for u, adjacent in enumerate(G)})
    pos = nx.circular_layout(H)
    color_map = []
    for node in H:
        if node in res:
            color_map.append('blue')
        else:
            color_map.append('black')
    nx.draw(H, pos=pos, node_color=color_map, node_size=20)
    plt.show()
