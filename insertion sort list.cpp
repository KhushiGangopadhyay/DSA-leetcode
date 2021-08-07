//problem link:https://leetcode.com/problems/insertion-sort-list/

class Solution {
public:

ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* curr = head->next, *prev, *tempcurr, *temp;
    head->next = NULL;
    while(curr){
        tempcurr = curr;
        temp = head;
        curr = curr->next;
        while(temp && temp->val < tempcurr->val){
            prev = temp;
            temp = temp->next;
        }
        if(temp == head){
            tempcurr->next = temp;
            head = tempcurr;
        }else{
            prev->next = tempcurr;
            tempcurr->next = temp;
        }
    }
    return head;
}
};
