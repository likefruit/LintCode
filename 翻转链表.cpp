/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head==NULL||head->next==NULL)  return head;
        
        ListNode *temp=NULL;
        ListNode *cur=head;
        ListNode *back=head->next;
        ListNode *dummy=new ListNode(0);
        dummy->next=NULL;
        //头插法
        while(cur!=NULL)
        {
            back=cur->next;
            cur->next=dummy->next;
            dummy->next=cur;
            cur=back;
        }
        
        temp=dummy;
        dummy=dummy->next;
        free(temp);
        temp=NULL;
        return dummy;
    }
};
