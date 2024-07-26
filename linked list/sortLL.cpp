
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* merge(ListNode* a, ListNode* b){

    // Merging Base Case
    if(!a) return b;
    if(!b) return a;

    // Merging
    ListNode* res;
    if(a->val > b->val){
        res = b;
        res->next = merge(a,b->next);
    } else {
        res = a;
        res->next = merge(a->next, b);
    }
    return res;
}

ListNode* sortList(ListNode* head) {
    
    // Splitting Base Case
    if(!head || !head->next)
        return head;

    // Splitting
        // Finds the middle Node 
    ListNode* left = head, *prev = head, *right = head, *it = head;
    while(it && it->next){
        prev = right;
        right = right->next;
        it = it->next->next;
    }
        // Effectively Splits LL into 2 sublists 
        // (as "prev" is mid-1 element, and we have to split from the middle)
    prev->next = NULL;

    // now "left" is head of Left Sublist
    // and "right" is head of Right Sublist 

    // Keep Splitting till Base Case is reached
    left = sortList(left);
    right = sortList(right);

    return merge(left,right);
}