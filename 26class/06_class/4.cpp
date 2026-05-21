#include <iostream>
#include <vector>

using namespace std;

int parent[30005];
int sz[30005]; 

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        sz[root_j] += sz[root_i];
    }
}

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            if (k == 0) continue;

            int first;
            cin >> first;
            for (int j = 1; j < k; j++) {
                int next;
                cin >> next;
                unite(first, next);
            }
        }
        cout << sz[find(0)] << endl;
    }
    return 0;
}