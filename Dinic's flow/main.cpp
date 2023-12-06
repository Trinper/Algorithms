#include <bits/stdc++.h>

struct edge {
    int v;
    int u;
    long long cap;
    long long flow;
};

class Dinic {
    int n;
    int m = 0;
    int s;
    int t;
    std::vector<int> level;
    std::vector<int> ptr;
    std::queue<int> q;
    std::vector<edge> edges;
    std::vector<std::vector<int>> g;

public:
    Dinic(int n_, int s_, int t_) : level(n_), ptr(n_), g(n_) {
        n = n_;
        s = s_;
        t = t_;
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back((edge) {v, u, cap, 0});
        edges.emplace_back((edge) {u, v, 0, 0});
        g[v].push_back(m++);
        g[u].push_back(m++);
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id: g[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < (int) g[v].size(); cid++) {
            int id = g[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, std::min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, LLONG_MAX)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    Dinic dinic(n, 0, n - 1); // flow of maximum value from the source (vertex 1) to the sink (vertex n)
    while (m--) {
        int v, u;
        long long w;
        std::cin >> v >> u >> w;
        dinic.add_edge(--v, --u, w);
    }

    std::cout << dinic.flow();
}
