#include<iostream>
#include<vector>
using namespace std;
#define MAX 1005

int insert(int num, int M, vector<int>& hashPosed){
    int i = 0;
    while(1){
        if(hashPosed[(num+i*i)%M] ==0){
            hashPosed[(num+i*i)%M] = 1;
            return (num+i*i)%M;
        }else if(hashPosed[(num-i*i)%M] ==0){
            hashPosed[(num-i*i)%M] = 1;
            return (num-i*i)%M;
        }else{
            i++;
        }
    }
}

int main(){
    int N,M;cin>>N>>M;
    vector<int> numPosition(MAX,-1);
    vector<int> result;
    vector<int> hashPosed(M,0);
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(numPosition[num]!=-1){
            result.push_back(numPosition[num]);
        }else{
            int res = insert(num, M, hashPosed);
            numPosition[num] = res;
            result.push_back(res);
        }
    }

    for(int i=0;i<N;i++){
        if(i!=0) cout<<" ";
        cout<<result[i];
    }
}