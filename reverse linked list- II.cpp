// problem link:https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *res= new ListNode(0);
        ListNode *pre= res, *cur;
        res->next=head;
        
        for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return res->next;
    }
};
