#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        long long n;cin>>n;
        priority_queue<int, vector<int>, greater<int>> heap;
        for(long long j=0;j<n;j++){
            int op;cin>>op;
            if(op==2){
                cout<< heap.top() <<endl;
                heap.pop();
            }else{
                int num;cin>>num;
                heap.push(num);
            }
        }
    }
}