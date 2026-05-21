#include<iostream>
#include<vector>
using namespace std;

int parent[50005];
int ans;

int find(int i){
    if(parent[i]==i) return i;
    return parent[i] = find(parent[i]);
}

void unite(int i,int j){
    int root_i = find(i);
    int root_j = find(j);
    if(root_i!=root_j){
        parent[root_i] = root_j;
        ans--;
    }
}

int main(){
    int n,m,caseNum = 0;
    while(cin >> n >> m && (n != 0 || m != 0)){
        caseNum++;
        ans = n;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(int i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        cout << "Case " << caseNum << ": " << ans << endl;
    }
}