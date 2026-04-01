#include<iostream>
#include<deque>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        deque<int> a;
        cin>>m;
        for(int j=0;j<m;j++){
            int op;
            cin>>op;
            if(op==1){
                int num;
                cin>>num;
                a.push_back(num);
            }else if(op==2){
                if(a.empty()) continue;

                int choose;
                cin>>choose;
                if(choose==0)   a.pop_front();
                else            a.pop_back();
            }
        }
        if(a.size()==0) cout<< "NULL" <<endl;
        else{
            int len = a.size();
            for(int k=0;k<len;k++){
                if(k!=0) cout << " ";
                int num = a.front();a.pop_front();
                cout << num;
            }
            cout<<endl;
        }
    }
}
