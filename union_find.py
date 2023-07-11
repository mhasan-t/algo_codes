def find_set(par, item):
    if par[item]==-1:
        par[item] = item
        return item
    if par[item] == item:
        return item
    par[item] = find_set(par[item])
    return par[item]

def union(par, item1, item2):
    if find_set(item1) != find_set(item2):
        par[find_set(item2)] = find_set(item1)
