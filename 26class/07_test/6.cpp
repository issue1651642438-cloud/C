#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Cow{
public:
    int index;
    long long Aex;
    long long Bex;

    Cow(int i, long long a, long long b){
        index = i;
        Aex = a;
        Bex = b;
    }
};

int cmp1(Cow* A, Cow* B){
    return A->Aex > B->Aex;
}

int cmp2(Cow* A, Cow* B){
    return A->Bex > B->Bex;
}

int main(){
    int N,K;
    cin>>N>>K;
    vector<Cow*> cows;
    for(int i=1;i<=N;i++){
        long long a, b;
        cin>>a>>b;
        Cow* cow = new Cow(i,a,b);
        cows.push_back(cow);
    }

    sort(cows.begin(),cows.end(),cmp1);
    sort(cows.begin(),cows.begin()+K,cmp2);

    cout<<cows[0]->index<<endl;
}