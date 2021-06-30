//problem link:https://leetcode.com/problems/linked-list-cycle-ii/


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head == NULL || head -> next == NULL)    
            return NULL;
 
        ListNode *fast = head;
        ListNode *slow = head;
         bool flag = false;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                    flag = true;
                    break;
                }
        }
            if(!flag)
                return NULL;
                                  
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
                
        }
 
        return slow;
    }
};
