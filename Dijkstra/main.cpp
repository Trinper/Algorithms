#include <bits/stdc++.h>

std::vector< std::vector <std::pair <long long, long long> > > g(200001);
std::vector<long long> d(200001, LLONG_MAX);
std::set<std::pair<long long, long long> > minn;

void dijkstra(long long start){
    minn.erase({LLONG_MAX, start});
    minn.insert({0, start});
    d[start] = 0;

    while (!minn.empty()) {
        auto cur = minn.begin()->second;
        minn.erase(minn.begin());
        for (int j = 0; j < g[cur].size(); j++) {
            auto vcur = g[cur][j].first;
            auto rcur = g[cur][j].second;
            if (d[cur] + rcur < d[vcur]) {
                minn.erase({d[vcur], vcur});
                d[vcur] = d[cur] + rcur;
                minn.insert({d[vcur], vcur});
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long n, m, s;

    std::cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        long long u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (long long i = 0; i < n; i++){
        minn.insert({LLONG_MAX, i});
    }

    dijkstra(s);

    for (int i = 0 ; i < n; i++)
        std::cout << d[i] << " ";

    std::fclose(stdin);
}

