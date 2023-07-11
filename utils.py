def getMaxInd(l):
    m, ind = float("-inf"), -1
    for i, val in enumerate(l):
        if val>m:
            ind=i
            m=val
    return ind
