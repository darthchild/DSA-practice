#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// BEST SOLUTION (TORTOISE & HARE APPROACH / SLOW & FAST POINTERS)
bool hasCycle(ListNode *head) {

    ListNode* s = head;
    ListNode* f = head;

    while(f && f->next){
        s = s->next;
        f = f->next->next;
        if(s == f)
            return true;
    }
    return false;
    
}


// TC: O(n) SC: O(n)
// Doesn't work if all node values are not unique
bool hasCycle(ListNode *head) {

    ListNode* it = head;
    unordered_set<int> set; // to store visited nodes

    while(it != NULL){
        if(set.find(it->val) != set.end())
            return true;
        else {
            set.insert(it->val);
            it = it->next;
        }
    }
    return false;
}