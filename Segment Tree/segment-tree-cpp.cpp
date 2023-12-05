#include <bits/stdc++.h>

class SegmentTree {
    std::vector<long long> tree;
    std::vector<long long> max;
    std::vector<long long> min;
public:
    explicit SegmentTree(std::vector<long long> &v) {
        tree.assign(4 * v.size(), 0);
        max.assign(4 * v.size(), LLONG_MIN);
        min.assign(4 * v.size(), LLONG_MAX);
        build(v, 1, 0, v.size() - 1);
    }

    void build(std::vector<long long> vec, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = vec[tl];
            max[v] = vec[tl];
            min[v] = vec[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(vec, 2 * v, tl, tm);
            build(vec, 2 * v + 1, tm + 1, tr);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
            max[v] = std::max(max[2 * v], max[2 * v + 1]);
            min[v] = std::min(min[2 * v], min[2 * v + 1]);
        }
    }

    void update(int v, int tl, int tr, int x, long long value) {
        if (tl == tr) {
            tree[v] = value;
            max[v] = value;
            min[v] = value;
        } else {
            int tm = (tl + tr) / 2;
            if (x <= tm)
                update(v * 2, tl, tm, x, value);
            else
                update(v * 2 + 1, tm + 1, tr, x, value);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
            max[v] = std::max(max[2 * v], max[2 * v + 1]);
            min[v] = std::min(min[2 * v], min[2 * v + 1]);
        }
    }

    void addValue(int v, int tl, int tr, int l, int r, long long value) {
        if (tr < l || l > r || r < tl) return;

        if (tl == tr){
            tree[v] += value;
            max[v] += value;
            min[v] += value;
            return;
        }

        int tm = (tl + tr) / 2;
        addValue(v * 2, tl, tm, l, r, value);
        addValue(v * 2 + 1, tm + 1, tr, l, r, value);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
        max[v] = std::max(max[2 * v], max[2 * v + 1]);
        min[v] = std::min(min[2 * v], min[2 * v + 1]);
    }


    long long findMax(int v, int tl, int tr, int l, int r){
        if (l > r)
            return LLONG_MIN;
        if (l == tl && r == tr) {
            return max[v];
        }

        int tm = (tl + tr) / 2;
        return std::max(findMax(v * 2, tl, tm, l, std::min(r, tm)), findMax(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    long long findMin(int v, int tl, int tr, int l, int r){
        if (l > r)
            return LLONG_MAX;
        if (l == tl && r == tr) {
            return min[v];
        }

        int tm = (tl + tr) / 2;
        return std::min(findMin(v * 2, tl, tm, l, std::min(r, tm)), findMin(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    long long sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }

        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, std::min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }

    SegmentTree tr(v);
    while (true) {
        int op;
        std::cin >> op;
        switch (op){
            case 0:{
                fclose(stdin);
                return 0;
            }
            case 1: {
                int a, b;
                std::cin >> a >> b;
                tr.update(1, 0, v.size() - 1, a, b);
                break;
            }
            case 2: {
                int a, b, c;
                std::cin >> a >> b >> c;
                tr.addValue(1, 0, v.size() - 1, a, b, c);
                break;
            }
            case 3: {
                int a, b;
                std::cin >> a >> b;
                std::cout << tr.sum(1, 0, v.size() - 1, a, b) << "\n";
                break;
            }
            case 4: {
                int a, b;
                std::cin >> a >> b;
                std::cout << tr.findMin(1, 0, v.size() - 1, a, b) << "\n";
                break;
            }
            case 5: {
                int a, b;
                std::cin >> a >> b;
                std::cout << tr.findMax(1, 0, v.size() - 1, a, b) << "\n";
                break;
            }
        }
    }

}