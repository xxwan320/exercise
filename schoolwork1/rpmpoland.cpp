#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    struct stackNode{
        long long data;
        stackNode* next;
        stackNode(int val){
            data = val;
            next = nullptr;
        }
    };

public:
        long long evalRPN(vector<string>& tokens){
        stack<stackNode*> st;
        for(string& token : tokens) {
            if(token == "+" || token == "-"|| token == "*" || token == "/"){
                if(st.size() < 2) return false;
                stackNode* num2 = st.top(); st.pop();
                stackNode* num1 = st.top(); st.pop();
                if(token == "+"){
                    st.push(new stackNode(num1->data + num2->data));
                } else if(token == "-"){
                    st.push(new stackNode(num1->data - num2->data));
                } else if(token == "*"){
                    st.push(new stackNode(num1->data * num2->data));
                } else if(token == "/"){
                    st.push(new stackNode(num1->data / num2->data));
                }
           
               }else{
                st.push(new stackNode(stoll(token))); 
               }

        }
        return st.top()->data;
    }   
};

int main(){
    Solution sol;
    
    // 正确的 RPN 表达式： (2 + 1) * 3 - 4 = 5
    vector<string> tokens = {"2", "1", "+", "3", "*", "4", "-"}; 
    
    cout << "RPN Expression: 2 1 + 3 * 4 -" << endl;
    cout << "Result: " << sol.evalRPN(tokens) << endl; // 预期输出: 5
    
    return 0;
}