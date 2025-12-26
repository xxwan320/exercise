#ifndef noheadDL_h
#define noheadDL_h
#include <iostream>
#include <vector>
using namespace std;
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


void creatList(ListNode*& head) {
    head = nullptr;
    ListNode* tail = nullptr;
    int val;
    std::cout << "Enter numbers to create linked list, end with -1:" << std::endl;
    while (true) {
        std::cin >> val;
        if (val == -1) break;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void coutList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}


#endif
