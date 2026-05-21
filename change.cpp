#include<iostream>
#include<string>
#include<stack>
using namespace std;

string convert_ten_to_base(int N,int base){
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    stack<char> stk;
    if(N==0) return "0";
    while(N>0){
        stk.push(digits[N%base]);
        N/=base;
    }
    string result;
    while(stk.empty()!=0){
        result+= stk.top();
        stk.pop();
    }
    return result;
}