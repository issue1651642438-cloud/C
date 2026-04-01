#include<iostream>
#include<deque>
#include<vector>
#define MAX 100005
using namespace std;
int main(){
    long long m,k;
    deque<int> maxIndex,minIndex;
    vector<int> a,maxNum,minNum;
    cin >> m >> k;
    for(int i=0;i<m;i++){
        int num = 0;
        cin >> num;
        a.push_back(num);
    }

    for(int i=0;i<m;i++){
        if(!maxIndex.empty()&&maxIndex.front()<i-k+1){
            maxIndex.pop_front();
        }
        while(!maxIndex.empty()&&a[i]>=a[maxIndex.back()]){
            maxIndex.pop_back();
        }
        maxIndex.push_back(i);
        if(i>=k-1) maxNum.push_back(a[maxIndex.front()]);

        if(!minIndex.empty()&&minIndex.front()<i-k+1){
            minIndex.pop_front();
        }
        while(!minIndex.empty()&&a[i]<=a[minIndex.back()]){
            minIndex.pop_back();
        }
        minIndex.push_back(i);
        if(i>=k-1) minNum.push_back(a[minIndex.front()]);
    }

    for(int i=0;i<m-k+1;i++){
        if(i!=0) cout<<" ";
        cout<<minNum[i];
    }
    cout<<endl;

    for(int i=0;i<m-k+1;i++){
        if(i!=0) cout<<" ";
        cout<<maxNum[i];
    }
    cout<<endl;
    

}