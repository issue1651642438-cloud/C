#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;

    priority_queue<long long, vector<long long>,greater<long long>> heap;
    for(int i=0;i<n;i++){
        long long length;
        cin >> length;
        heap.push(length);
    }

    long long total = 0;
    while(heap.size()>1){
        long long first = heap.top();
        heap.pop();
        long long second = heap.top();
        heap.pop();
        heap.push(first+second);
        total+= first+second;
    }

    cout<<total<<endl;
    return 0;
}