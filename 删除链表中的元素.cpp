/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        if(head==NULL)
            return NULL;
        while(head->val==val)
            {
                head=head->next;
                if(head==NULL)
                    return NULL;
            }
        
        ListNode* pre=head;
        ListNode* p=head->next;
        while(p)
        {
            if(p->val==val)
                {   
                    pre->next=p->next;
                    p=p->next;
                }
                else{
            pre=p;
            p=p->next;}
        }
  
        return head;
    }
};
