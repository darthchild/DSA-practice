#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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