#include<iostream>
#include<vector>
#define MAX 50005
using namespace std;
long parent[3*MAX];

long find(long i){
    if(parent[i]==i) return i;
    return parent[i] = find(parent[i]);
}

void unite(long i,long j){
    long root_i = find(i);
    long root_j = find(j);
    if(root_i!=root_j){
        parent[root_i] = root_j;
    }
}

int main(){
    long n,k;cin>>n>>k;
    long faultNum=0;

    for (long i = 1; i <= 3 * n; i++) {
        parent[i] = i;
    }

    for(long i=0;i<k;i++){
        long op,x,y;
        cin>>op>>x>>y;
        if(x>n||y>n){
            faultNum ++;
            continue;
        }
        if(op==1){
            if(find(x)==find(y+n)||find(x)==find(y+2*n)){
                faultNum ++;
                continue;
            }else{
                unite(x,y);unite(x+n,y+n);unite(x+2*n,y+2*n);
            }
        }else{
            if(find(x)==find(y)||find(x)==find(y+2*n)||x==y){
                faultNum ++;
                continue;
            }else{
                unite(x,y+n);unite(x+n,y+2*n);unite(x+2*n,y);
            }
        }
    }

    cout<<faultNum<<endl;
}