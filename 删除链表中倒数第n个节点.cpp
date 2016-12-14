/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(head==NULL) return NULL;
        
        int k=1;
        
        //如果删除的是头结点，那么设置一个空的头结点会比较方便。
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        
        
        ListNode *temp=NULL;ListNode *temp2=NULL;
        ListNode *back_cur=head;
        ListNode *pre_back_cur=dummy;
        
        ListNode *front_cur=head;
        while(k!=n)
        {
            front_cur=front_cur->next;
            k++;
        }
        while(front_cur->next!=NULL)
        {
            front_cur=front_cur->next;
            pre_back_cur=back_cur;
            back_cur=back_cur->next;
        }
        
        //删除结点操作
        temp=back_cur;
        pre_back_cur->next=back_cur->next;
        free(temp);
        
        
        temp=dummy;
        dummy=dummy->next;
        free(temp);

        return dummy;
        
        
    }
};


