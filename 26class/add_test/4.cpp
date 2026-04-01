#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include <algorithm>
using namespace std;
#define MAX 15
char board[15][15];
bool used[15][15]={0};
vector<string> words;
int m,n,p;

bool find(int idx)
{
    if(idx==p) return true;

    string w = words[idx];
    int len = w.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j+len<=m){
                bool ok =true;
                for(int k=0;k<len;k++){
                    if(used[i][j+k]||board[i][j+k]!=w[k]){
                        ok = false;
                        break;
                    }
                    if(ok){
                        for(int k=0;k<len;k++){
                            used[i][j+k] = true;
                        }
                        if(find(idx+1)) return true;
                        for(int k=0;k<len;k++){
                            used[i][j+k] = false;
                        }
                    }
                }
            }

            if(i+len<=n){
                bool ok =true;
                for(int k=0;k<len;k++){
                    if(used[i+k][j]||board[i+k][j]!=w[k]){
                        ok = false;
                        break;
                    }
                    if(ok){
                        for(int k=0;k<len;k++){
                            used[i+k][j] = true;
                        }
                        if(find(idx+1)) return true;
                        for(int k=0;k<len;k++){
                            used[i+k][j] = false;
                        }
                    }
                }
            }
        }
        return false;
    }
}

int main()
{
    cin >>n >>m >>p;
    for(int i=0;i<n;i++)
    {
        cin >>board[i];
    }
    words.resize(p);
    for(int i=0;i<p;i++)
    {
        cin >>words[i];
    }
    memset(used,false,sizeof(used));
    find(0);

    vector <char> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[i][j]){
                res.push_back(board[i][j]);
            }
        }
    }
    sort(res.begin(),res.end());
    for(char c : res) cout<<c;
    cout<<endl;
    return 0;
}