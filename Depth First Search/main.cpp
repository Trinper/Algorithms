#include <bits/stdc++.h>

int mark = 0;

void dfs(int v, std::vector <bool>& visit, std::vector < std::vector <int> > g, std::vector <int>& marked){
    visit[v] = true;
    marked[v] = ++mark;
    for (std::vector<int> :: iterator i = g[v].begin(); i != g[v].end(); ++i){
        if (!visit[*i]){
            dfs(*i, visit, g, marked);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    std::cin >> n;
    std::vector < std::vector <int> > g(n);
    std::vector <bool> visit(n);
    std::vector <int> marked(n);
    for (int i = 0; i < n; i++){
        marked[i] = -1;
    }

    for (int i = 0; i < n; i++){
        visit[i] = false;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            std::cin >> x;
            if (x == 1){
                g[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (!visit[i]){
            //cout << i << '\n';
            dfs(i, visit, g, marked);
        }
    }

    for (int i = 0; i < n; i++){
        std::cout << marked[i] << " ";
    }


}
