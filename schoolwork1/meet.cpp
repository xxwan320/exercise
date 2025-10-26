#include <iostream>
#include <vector>
using namespace std;

 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA){
            lenA++;
            tempA = tempA -> next;
        }
         while(tempB){
            lenB++;
            tempB = tempB -> next;
        }
        int gap = abs(lenA - lenB);
        ListNode* longer = lenA > lenB ? headA : headB;
        ListNode* shorter = lenA > lenB ? headB : headA;
        for(int i = 0; i < gap; i++){
            longer = longer -> next;
        }
        while(longer && shorter){
            if(longer == shorter){
                return longer;
            }
            longer = longer -> next;
            shorter = shorter -> next;
        }
        return nullptr;        
    }
};