#include<iostream>
#include<vector>
using namespace std;

vector<long> parent(200005);

long find(long i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unite(long i, long j){
    long root_i = find(i);
    long root_j = find(j);
    if(root_i != root_j){
        parent[root_i] = root_j;
    }
}

int main()
{
    int t=0;cin>>t;
    for(int i=0;i<t;i++){
        long n,m;
        cin>>n>>m;
        for(long j=1;j<=2*n;j++){
            parent[j] = j;
        }
        for(long j=0;j<m;j++){
            char op;
            int a,b;
            cin>>op>>a>>b;
            if(op=='D'){
                unite(a,b+n);unite(a+n,b);
            }else{
                if(find(a)==find(b+n)||find(a+n)==find(b)){
                    cout<<"In different gangs."<<endl;
                }else if(find(a)==find(b)||find(a+n)==find(b+n)){
                    cout<<"In the same gang."<<endl;
                }else{
                    cout<<"Not sure yet."<<endl;
                }
            }
        }
    }
}
