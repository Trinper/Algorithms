#include <bits/stdc++.h>

class DSU{

    std::vector<int> parent;
    std::vector<int> rank;
    int connectivity;
public:

    DSU(int n_): parent(n_), rank(n_){
        this -> connectivity = n_;
        for (int i = 0; i < n_; i++){
            makeSet(i);
        }
    }

    void makeSet(int x){
        parent[x] = x;
        rank[x] = 1;
    }

    int findSet(int x){
        return ((x == parent[x]) ? x : parent[x] = findSet(parent[x]));
    }

    void unionSets(int a, int b){
        a = findSet(a);
        b = findSet(b);
        if (a != b){
            if (rank[a] < rank[b])
                std::swap(a,b);
            parent[b] = a;
            connectivity--;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }

    int getConnectivity() const{
        return connectivity;
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int x, y;
        std::cin >> x >> y;
        dsu.unionSets(--x, --y);
        std::cout << dsu.getConnectivity() << '\n';
    }
    fclose (stdin);
    return 0;
}
