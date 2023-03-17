from dimacs import edgeList, isVC


def vertex_cover(G, k):
    E = edgeList(G)
    return VC(E, k, set())


def VC(E, k, S):
    # G to graf wejściowy, k liczba wierzchołków, które możemy użyć
    # S to zbiór wierzchołków, który budujemy

    # wybierz dowolną krawędź e = {u, v}, która nie jest jeszcze pokryta(czyli ani u ani v nie jest wybrany)

    if not E:
        return S

    if k == 0:
        return None

    u, v = E[0]

    S.add(u)
    S1 = VC([e for e in E if e[0] != u and e[1] != u], k - 1, S)
    if S1:
        return S1
    S.remove(u)
    S.add(v)
    S2 = VC([e for e in E if e[0] != v and e[1] != v], k - 1, S)
    return S2
