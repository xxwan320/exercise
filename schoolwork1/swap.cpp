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
    ListNode* swapPairs(ListNode* head) {
        ListNode* Dhead = new ListNode(0);
        Dhead->next = head;
        ListNode* current = Dhead;
        while(head != nullptr && head -> next != nullptr){
            ListNode* first = head;
            ListNode* second = head -> next;
            current -> next = second;
            first  -> next = second -> next;
            second -> next = first;
            current = first;
            head = first -> next;
        }
        ListNode* result = Dhead->next;
        delete Dhead;
        return result;   
    }
};