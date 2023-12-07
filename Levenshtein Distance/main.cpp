#include <bits/stdc++.h>

int L_distance(std::string s1, std::string s2, int deleteCost, int insertCost, int replaceCost){
    int n = s1.size();
    int m = s2.size();

    int d[n + 1][m + 1];
    d[0][0] = 0;

    for (int i = 1; i <= n; i++){
        d[i][0] = d[i - 1][0] + deleteCost;
    }

    for (int j = 1; j <= m; j++){
        d[0][j] = d[0][j - 1] + insertCost;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1]){
                d[i][j] = d[i - 1][j - 1];
            } else
                d[i][j] =  std::min({d[i - 1][j - 1] + replaceCost, d[i - 1][j] + deleteCost, d[i][j - 1] + insertCost});
        }
    }

    return d[n][m];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int deleteCost, insertCost, replaceCost;
    std::cin >> deleteCost >> insertCost >> replaceCost;
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    std::cout << L_distance(s1, s2, deleteCost, insertCost, replaceCost);
    fclose(stdin);
}