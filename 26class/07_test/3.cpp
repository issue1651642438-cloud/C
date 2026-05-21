#include<iostream>
#include<string>
#include<vector>
using namespace std;
// 0表示相同，1表示相似，-1表示不同
int isSimilar(string a, string b){
    if(a==b) return 0; // 0表示相同
    if(a.size()-b.size()==0){
        int diff = 0;
        for(int i = 0;i<a.size();i++){
            if(a[i]!=b[i]){
                diff++;
            }
            if(diff==2){
                return -1;
            }
        }
        return 1;
    }else if(a.size()-b.size()==1){
        int i=0,j=0,diff=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;j++;
            }else{
                i++;diff++;
                if(diff==2) return -1;
            }
        }
        return 1;
    }else if(a.size() - b.size()==-1){
        int i=0,j=0,diff=0;
        while(j<b.size()){
            if(a[i]==b[j]){
                i++;j++;
            }else{
                j++;diff++;
                if(diff==2) return -1;
            }
        }
        return 1;
    }else{
        return -1;
    }
}

int main(){
    vector<string> dictionary;
    int dicNum;
    string curstr;
    while(cin>>curstr && curstr!="#"){
        dictionary.push_back(curstr);
    }

    dicNum = dictionary.size();

    while(cin>>curstr){
        if(curstr=="#") return 0;

        vector<string> similar;
        int iscorrect = 0;
        for(int i=0;i<dicNum;i++){
            int index = isSimilar(curstr,dictionary[i]);
            if(index==0){
                cout<<curstr<<" is correct"<<endl;
                iscorrect = 1;
                break;
            }else if(index==1){
                similar.push_back(dictionary[i]);
            }
        }
        if(iscorrect) continue;

        cout<<curstr<<":";
        if(similar.size()!=0){
            for(int i=0;i<similar.size();i++){
                cout<<" "<<similar[i];
            }
        }
        cout<<endl;
    }
}