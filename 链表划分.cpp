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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head==NULL) return NULL;
        
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *temp=head;
        //如果要插入第一个位置的话，那么dummy结点可以帮助我们
        //避免pretemp是空结点而导致无法插入的错误。
        ListNode *pretemp=dummy;
        
        ListNode *cur=NULL;
        ListNode *precur=NULL;
        
        //找到第一个大于等于x的值作为分界线，存在temp中。
        while(temp!=NULL&&temp->val<x)
        {
            pretemp=temp;
            temp=temp->next;
        }
        
        if(temp!=NULL&&temp->next!=NULL)
        {
            precur=temp;
            cur=temp->next;
        }
        //找到分界线右侧小于x的值的结点，将其存在cur中。
        while(cur!=NULL)
        {
            while(cur!=NULL&&cur->val>=x)
            {
                precur=cur;
                cur=cur->next;
            }
            //如果找到的话将其插入到分界线以前的第一个位置
            if(cur!=NULL)
            {
                precur->next=cur->next;
                cur->next=temp;
                pretemp->next=cur;
                pretemp=cur;
                cur=precur->next;
            }
        }
        
        temp=dummy;
        dummy=dummy->next;
        free(temp);
        return dummy;
        
    }
};


