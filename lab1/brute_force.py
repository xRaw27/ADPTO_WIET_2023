from itertools import combinations
from dimacs import edgeList, isVC


def vertex_cover(G, k):
    E = edgeList(G)
    for C in combinations(range(len(G)), k):
        if isVC(E, C):
            return C
    return None
