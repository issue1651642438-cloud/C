#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<cctype>
#define MAX 605
using namespace std;

// 优先级
int priority(char op)
{
    if(op=='+'||op=='-')return 1;
    if(op=='*'||op=='/')return 2;
    return 0;
}

// 中缀->后缀
vector<string> infixToPostfix(string& s)
{
    stack<char> op;
    vector<string> postfix;

    for(int i=0;i<s.size();)
    {
        if(isdigit(s[i])){
            string num;
            while(i<s.size()&&isdigit(s[i])){
                num+=s[i];
                i++;
            }
            postfix.push_back(num);
        }else if(s[i]==')'){
            while(!op.empty()&&op.top()!='('){
                postfix.push_back(string(1,op.top()));
                op.pop();
            }
            op.pop();
            i++;
        }else if(s[i]=='('){
            op.push(s[i]);
            i++;
        }else{
            while(!op.empty()&&priority(op.top())>=priority(s[i])){
                postfix.push_back(string(1,op.top()));
                op.pop();
            }
            op.push(s[i]);
            i++;
        }

    }
    while(!op.empty()){
        postfix.push_back(string(1,op.top()));
        op.pop();
    }
    return postfix;
}

// 计算后缀表达式
int calcPostfix(vector<string>& postfix)
{
    stack<int> st;
    for(auto& token : postfix){
        if(isdigit(token[0])){
            st.push(stoi(token));
        }else{
            int b = st.top();st.pop();
            int a = st.top();st.pop();

            if(token=="+")      st.push(a+b);
            else if(token=="-") st.push(a-b);
            else if(token=="*") st.push(a*b);
            else if(token=="/") st.push(a/b);
        }
    }
    return st.top();
}


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        vector<string> postfix = infixToPostfix(s);
        int result = calcPostfix(postfix);
        cout << result << endl;
    }
}
