#include<bits/stdc++.h>

using namespace std;

bool isOperator(char x){ //Neu x la phep toan ( + - * /)
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    else return false;
}

void postToPre(string s){
    stack<string> st;
    int len = s.size();
    for(int i = 0; i<len;++i){
        char x = s[i];
        if(isOperator(x)){
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string tmp = '('+ op2 + x + op1 + ')';
            st.push(tmp);
        }
        else{
            st.push(string(1,x)); // dua x vao duoi dang string
        }
    }
    cout<<st.top()<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        postToPre(s);
    }
    return 0;
}