#include<string.h>
#include<iostream>
using namespace std;

string getAfter(string pre,string mid){
    if(pre.empty()) return "";

    char root = pre[0];
    int k = mid.find(root);
    
    string preleft = pre.substr(1,k);
    string midleft = mid.substr(0,k);
    string preright = pre.substr(k+1);
    string midright = mid.substr(k+1);

    return getAfter(preleft,midleft)+getAfter(preright,midright)+root;    
}

int main(){
    string pre;
    string mid;
    while(cin>>pre&&cin>>mid){
        string after = getAfter(pre,mid);
        cout<<after<<endl;
    }
}