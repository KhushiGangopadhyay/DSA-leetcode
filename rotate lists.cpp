//problem link:https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL|| k==0)
        {
            return head;
        }
        ListNode *p=head;
        int cnt=1;
        while(p->next)
        {
            cnt++;
            p=p->next;
        }
        
        p->next=head;
        k=k%cnt;
        int n=cnt-k;
    
        while(n--)
        {
            p=p->next;
        }
        
        head=p->next;
        p->next=NULL;
    return head;
    }
};
