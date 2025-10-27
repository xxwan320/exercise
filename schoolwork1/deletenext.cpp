#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    struct stackNode{
        int data;
        stackNode* next;
        stackNode(int val){
            data = val;
            next = nullptr;
        }
    };

public:
    void reservestring(string &s) {
    stack<stackNode*> st;   
    for(char ch : s){
            st.push(new stackNode(ch));
    }
    s.clear();
    while(!st.empty()){
        s += st.top() -> data;
        st.pop();
    }
}    
    string removeDuplicates(string s) {
    stack<stackNode*> st;   
    for(char ch : s){
            if(!st.empty() && st.top() -> data == ch){
                st.pop();
            }else{
                st.push(new stackNode(ch));
            }
            }
    string result;
    while(!st.empty()){
        result += st.top() -> data;
        st.pop();
    }
    reservestring(result);
    return result;
 }
};

//string类本身提供栈接口
/*
class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};
*/