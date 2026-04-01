#include<iostream>
#include<stack>
using namespace std;
#define MAX 1000005

int main()
{
    long long n=0;
    cin >> n;
    stack<int> a,max;
    for(long long i=0;i<n;i++){
        int op = 0;
        cin >> op;
        if(op==1){
            int num=0;
            cin >> num;
            a.push(num);
            if(max.empty()){
                max.push(num);
            }else if(max.top()<=num){
                max.push(num);
            }
        }else if(op==2){
            if(!a.empty()){
                if(a.top()==max.top())
                {
                    max.pop();
                }
                a.pop();
            }
        }else{
            if(a.empty()){
                cout << 0 <<endl;
            }else{
                cout<<max.top()<<endl;
            }
        }
    }
}