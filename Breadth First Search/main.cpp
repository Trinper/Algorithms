#include <bits/stdc++.h>
using namespace std;

int mark = 0;


void bfs(vector < vector <int> > g, vector <bool>& visit, int start, vector <int>& marked){

    queue <int> q;
    q.push(start);
    visit[start] = true;
    while (!q.empty()){
        auto cur = q.front();
        marked[cur] = ++mark;
        q.pop();
        for (size_t i = 0; i < g[cur].size(); ++i){
            int to = g[cur][i];
            if (!visit[to]){
                visit[to] = true;
                q.push(to);
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector < vector <int> > g(n);
    vector <bool> visit(n);
    vector <int> marked(n);
    for (int i = 0; i < n; i++){
        marked[i] = -1;
    }

    for (int i = 0; i < n; i++){
        visit[i] = false;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            if (x == 1){
                g[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (!visit[i]){
            //cout << i << '\n';
            bfs(g, visit, i, marked);
        }
    }

    for (int i = 0; i < n; i++){
        cout << marked[i] << " ";
    }

    std::fclose(stdin);
}
