#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
// 优先级
int priority(char a)
{
    if(a=='|'||a=='&')  return 1;
    if(a=='!')          return 2;
    return 0; 
}

// 处理字符串
void stringToOutput(string& s)
{
    stack<char> op;
    stack<bool> val;
    for(auto c : s){
        if(c==' '){
            continue;
        }else if(c=='V'||c=='F'){
            val.push(c=='V');
        }else if(c=='('){
            op.push('(');
        }else if(c==')'){
            while(!op.empty()&&op.top()!='('){
                char o = op.top();op.pop();
                if(o=='!'){
                    bool a = val.top();val.pop();
                    val.push(!a);
                }else{
                    bool a =val.top();val.pop();
                    bool b =val.top();val.pop();
                    if(o=='|')  val.push(b||a);
                    else        val.push(b&&a);
                }
            }
            op.pop();
        }else{
            while(!op.empty() && 
      ((c!='!' && priority(op.top()) >= priority(c)) ||
       (c=='!' && priority(op.top()) > priority(c)))){
                char o =op.top();op.pop();
                if(o=='!'){
                    bool a = val.top();val.pop();
                    val.push(!a);
                }else{
                    bool a =val.top();val.pop();
                    bool b =val.top();val.pop();
                    if(o=='|')  val.push(b||a);
                    else        val.push(b&&a);
                }
            }
            op.push(c);
        }
    }
    while(!op.empty())
    {
        char o =op.top();op.pop();
        if(o=='!'){
            bool a = val.top();val.pop();
            val.push(!a);
        }else{
            bool a =val.top();val.pop();
            bool b =val.top();val.pop();
            if(o=='|')  val.push(b||a);
            else        val.push(b&&a);
        }
    }

    cout<< (val.top()?"V":"F")<<endl;
}

int main()
{
    string s;
    while(getline(cin, s)){
        if(s.empty()) break;
        stringToOutput(s);
    }
}