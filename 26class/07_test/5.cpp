#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX int(pow(2,28))

int main(){
    long long n,total=0;
    cin>>n;
    vector<long long>as,bs,cs,ds;
    for(long long i=0;i<n;i++){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        as.push_back(a);
        bs.push_back(b);
        cs.push_back(c);
        ds.push_back(d);
    }
    
    vector<long long>cds;
    vector<long long> hash(2*MAX+5,0);
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            if(as[i]+bs[j]>=0){
                hash[as[i]+bs[j]]++;
            }else{
                hash[MAX+as[i]+bs[j]]++;
            }
            
        }
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            if(-cs[i]-ds[j]>=0&&hash[-cs[i]-ds[j]]!=0){
                total+=hash[-cs[i]-ds[j]];
            }else if(-cs[i]-ds[j]<0&&hash[-cs[i]-ds[j]+MAX]!=0){
                total+=hash[-cs[i]-ds[j]+MAX];
            }
        }
    }

    cout<<total;
}