单链表的定义
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode* tmp = head;
            head = head -> next;
            delete tmp;
        }
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};
虚拟节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = dummyhead;

        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }else{
                cur = cur->next;
            }

        }
        ListNode* newHead = dummyhead->next;
        delete dummyhead;
        return newHead;      // 必须返回
    }
};