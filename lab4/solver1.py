def is_satisfied(CNF, V: dict):
    for C in CNF:
        val = [V.get(v, 0) for v in C]
        if 1 not in val:
            return False
    return True


def simplify_clause(C, V):
    # C - klauzula, czyli lista literałów
    # V - wartościowanie zmiennych

    simplified_C = []
    for v in C:
        val = V.get(v, 0)
        if val == 0:
            simplified_C.append(v)
        elif val == 1:
            return None
    return simplified_C


def simplify_CNF(CNF, V):
    # CNF - formuła do uproszczenia
    # V   - wartościowanie zmiennych

    simplified_CNF = []
    for C in CNF:
        simplified_C = simplify_clause(C, V)
        if simplified_C:
            simplified_CNF.append(simplified_C)
        elif simplified_C is not None:
            return None
    return simplified_CNF


def solve(CNF, V, n):
    # CNF to rozważana formuła
    # V to wartościowanie zmiennych

    if CNF is None:
        return None

    if is_satisfied(CNF, V):
        print(V)
        return V

    v = max(V.keys()) + 1 if len(V) > 0 else 1
    if v > n:
        return None

    V1 = V.copy()
    V2 = V.copy()

    V1[v] = 1
    V1[-v] = -1
    V2[v] = -1
    V2[-v] = 1
    CNF1 = simplify_CNF(CNF, V1)
    CNF2 = simplify_CNF(CNF, V2)

    return solve(CNF1, V1, n) or solve(CNF2, V2, n)


def solver1(CNF, n):
    V = {}
    res = solve(CNF, V, n)
    return res if res is not None else "UNSAT"
