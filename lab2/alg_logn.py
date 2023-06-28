

def vertex_cover(G):
    C = set()
    while True:
        u = max(range(len(G)), key=lambda x: len(G[x]))
        if len(G[u]) == 0:
            break
        C.add(u)
        for v in G[u]:
            G[v].remove(u)
        G[u] = set()

    return C

