
def vertex_cover(G):
    C = set()

    while True:
        found_not_empty = False
        for u, adjacent in enumerate(G):
            for v in adjacent:
                C.add(u)
                C.add(v)
                for w in G[u]:
                    G[w].remove(u)
                for w in G[v]:
                    G[w].remove(v)
                G[u] = set()
                G[v] = set()
                found_not_empty = True
                break
            if found_not_empty:
                break
        if not found_not_empty:
            break

    return C
