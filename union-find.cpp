class UnionFind {
    Map<Integer, Integer> parents;
    int count;

    public UnionFind() {
        parents = new HashMap<>();
        count = 0;
    }

    public int getCount() {
        return count;
    }

    public int find(int x) {
        if (!parents.containsKey(x)) {
            parents.put(x, x);
            count++;
        }

        if (x != parents.get(x)) {
            parents.put(x, find(parents.get(x)));
        }

        return parents.get(x);
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }

        parents.put(rootX, rootY);
        count--;
    }
}
