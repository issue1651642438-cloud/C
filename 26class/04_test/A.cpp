#include<iostream>
#include<stdio.h>
#include<string.h>
#include<deque>
#include<regex>
using namespace std;
regex Push(R"(push (\d{1,10}))");

int main()
{
    int m=0;
    cin >> m;
    for(int i=0;i<m;i++){
        int iswronga = 0,iswrongb = 0;

        int n=0;
        cin >> n;
        cin.get();

        deque<int> a;   // 模拟栈
        deque<int> b;   // 模拟队列
        for(int j=0;j<n;j++){
            string str;
            getline(cin,str);
            smatch matches;

            if(regex_match(str,matches,Push)){
                int num = stoi(matches[1].str());
                a.push_back(num);
                b.push_back(num);
            }else{
                if(a.size()==0||b.size()==0){
                    if(a.size()==0)iswronga = 1;
                    if(b.size()==0)iswrongb = 1;
                }else{
                    a.pop_back();b.pop_front();
                }                
            }
        }
        if(iswrongb){
            printf("error\n");
        }else{
            int N = b.size();
            for(int i=0;i<N;i++){
                int num = b.front();b.pop_front();
                if(i!=0) printf(" ");
                printf("%d",num);
            }
            printf("\n");
        }
        if(iswronga){
            printf("error\n");
        }else{
            int N = a.size();
            for(int i=0;i<N;i++){
                int num = a.front();a.pop_front();
                if(i!=0) printf(" ");
                printf("%d",num);
            }
            printf("\n");
        }
    }
}