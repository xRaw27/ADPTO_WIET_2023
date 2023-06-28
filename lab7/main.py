from dimacs import loadGRGraph, loadDecomposition, Bag

name = "graphtw/b20"

G = loadGRGraph(f"{name}.gr")
B = loadDecomposition(f"{name}.tw")

print(G)


def checkVC(G, X: set[int], Y: set[int]):
    for u in X:
        for v in G[u] & X:
            if u not in Y and v not in Y:
                print(u, v)
                return False
    return True


# checkVC(G, {1, 2, 3}, {2})

def f()

root = B[1]




print(B)
