#include <algorithm>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
vector <int> mid,pre,after;
void getPre(int midBegin,int midOver,int afterBegin,int afterOver){
    if (midBegin > midOver) return;

    int root = after[afterOver];
    pre.push_back(root);
    int leftMidB = midBegin;
    int leftMidO = find(mid.begin() + midBegin, mid.begin() + midOver + 1, root) - mid.begin();
    int leftSize = leftMidO - midBegin;
    getPre(midBegin, leftMidO - 1, afterBegin, afterBegin + leftSize - 1);
    getPre(leftMidO+1,midOver,afterBegin+leftSize,afterOver-1);
}

int main(){
    string line;
    int num = 0;
    getline(cin,line);    
    istringstream iss1(line);
    while(iss1>>num){
        mid.push_back(num);
    }
    getline(cin,line);
    istringstream iss2(line);
    while(iss2>>num){
        after.push_back(num);
    }

    getPre(0,mid.size()-1,0,after.size()-1);

    for(int i=0;i<pre.size();i++){
        if(i!=0) cout<<' ';
        cout<< pre[i];
    }
}