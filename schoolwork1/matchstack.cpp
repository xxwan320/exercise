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
    bool isValid(string s) {
    stack<stackNode*> st;
   
    for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(new stackNode(ch));
        } else {
            if(st.empty()) return false;
            stackNode* topNode = st.top();
            if((ch == ')' && topNode->data != '(') ||
               (ch == '}' && topNode->data != '{') ||
               (ch == ']' && topNode->data != '[')){       
                return false;  
        
    }
            st.pop();
        }
    }
    return st.empty();
 }
};