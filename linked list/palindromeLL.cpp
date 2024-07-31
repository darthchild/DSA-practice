#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

ListNode* reverse(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* prev = NULL;
    ListNode* it = head;

    while (it != NULL) {
        ListNode* aft = it->next;
        it->next = prev;
        prev = it;
        it = aft;
    }
    return prev;
}

    /*
              s
    1 -> 2 -> 2 -> 1 -> X

    s
    1 -> 2 -> X

    */

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // Find the midpoint using s and f pointers
    ListNode* s = head, *f = head;

    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }

    // Reverse the second half of the list
    ListNode* p2 = reverse(s), *p1 = head;

    // Compare the first and second halves
    // (p1 - iterator for List's 1st half, p2 - iterator for 2nd half)
    while (p2 != NULL) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}










// MINEEE
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

    ListNode* reverse(ListNode* head){
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode* prev = NULL, *it = head;

        while(it != NULL){
            ListNode* aft = it->next;
            it->next = prev;
            prev = it;
            it = aft;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(!head->next) return true;
    
        ListNode* newHead = reverse(head);
        ListNode* a = head, *b = newHead;
        int len = 0, cnt = 0;

        while(a){
            len++;
            a = a->next;
        }
        a = head;

        while(a && b){
            cout << a->val << " " << b->val;
            if(a->val == b->val)
                cnt++;
            a = a->next;
            b = b->next;
        }

        cout << endl << len << " " << cnt ;

        if(len == cnt)
            return true;
        return false;
    }
};