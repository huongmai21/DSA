#include<bits/stdc++.h>

using namespace std;

bool isOperator(char x){ //Neu x la phep toan ( + - * /)
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    else return false;
}

string preToPost(string s){
    stack<string> st;
    int len = s.size();
    for(int i = len-1; i>=0;--i){
        char x = s[i];
        if(isOperator(x)){
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string tmp = '(' + op1 + x + op2 + ')';
            st.push(tmp);
        }
        else{
            st.push(string(1,x)); // dua x vao duoi dang string
        }
    }
    return st.top();
}

int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<preToPost(s)<<endl;
    }
    return 0;
}