graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0, 3],
    3: [4, 1, 2],
    4: [3, 5, 6],
    5: [4, 6],
    6: [4, 5]
}
back_edges = {}
W = [0] * 7
L = [0] * 7
H = [0] * 7
ND = [1] * 7
P = [-1] * 7
finished = [0] * 7
queue = [0]


def tarjan_bridge_finding(node, time=0):
    time += 1
    W[node] = L[node] = time

    for v in graph[node]:
        if v == P[node]:
            continue

        if W[v] == 0:
            P[v] = node
            time = tarjan_bridge_finding(v, time)
            ND[node] += ND[v]
        else:
            back_edges[node] = [v] if back_edges.get(
                node) is None else back_edges[node].append(v)

        L[node] = min(L[node], L[v])
        # H[node] = max(H[node], H[v])
        if W[node] < L[v]:
            print(f"Bridge at edge({node}->{v})")

    return time


tarjan_bridge_finding(0)
# print(W)
# print(back_edges)
# print(P)
# print(ND)
# print(L)
# print(H)
