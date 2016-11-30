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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *p=head;
        ListNode *q=head;
        int count=0;
        while(count!=n&&p!=NULL)
        {
            p=p->next;
            count++;
        }
        while(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        return q;
    }
};


