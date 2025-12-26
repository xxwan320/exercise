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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                ListNode* ptr1 = head;
                ListNode* ptr2 = slow;
                while(ptr1 != ptr2){
                    ptr1 = ptr1 -> next;
                    ptr2 = ptr2 -> next;
                }
                return ptr1;
            }
        }
        return nullptr;
    }
};