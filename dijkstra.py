def dijkstra(self, g, start, goals):
    d = { start : 0 }
    q = [ start ]

    while q:
        u = min(q, key=lambda x:d[x])
        q.remove(u)
        adj = g[u]
        for v in adj:
            if v==u:
                continue
            if d.get(v) is None:
                d[v] = d[u]+1
                q.append(v)
            elif d[v]>d[u]+1:
                d[v] = d[u]+1
                q.append(v)
        # print(u, adj, d, q)
    # print(d)
    dists = [d[x] for x in goals if d.get(x) is not None]
    if dists:
        return min(dists)
    return -1
