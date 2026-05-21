#include<iostream>
using namespace std;

int main(){
    long long m,n;
    while(cin>>m>>n&&m!=0&&n!=0){
        long long total = 0;
        long long left = m;
        long long right = m;
        while(left<=n){
            total += min(right,n) - left+1;

            left*=2;
            right = right*2 +1;
        }
        cout<<total<<endl;
    }
}