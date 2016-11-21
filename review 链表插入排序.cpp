//以为很简单，写了好久~~~
//切记：新建一个头结点可以省很多事
//我的答案
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if(head==NULL) return NULL;
        ListNode *dummy=new ListNode(0);  
        dummy->next=head;
        ListNode *temp=NULL;
        ListNode *cur=head;
        ListNode *pre=NULL;
        ListNode *back=cur->next;
        while(back!=NULL)
        {
            if(back->val>=cur->val)
            {
                cur=cur->next;
                back=cur->next;
            }
            else
            {
                pre=dummy;
                head=dummy->next;
                while(head!=NULL&&head->val<back->val)
                {
                    pre=head;
                    head=head->next;
                }
                cur->next=back->next;
                back->next=pre->next;
                pre->next=back;
                
                back=cur->next;
                
            }
                
        }
        temp=dummy;  
        dummy=dummy->next;  
        free(temp); 
        return dummy;
    }
};

// Time:  O(n^2)
// Space: O(1)

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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy{numeric_limits<int>::min()};

        auto curr = head;
        ListNode *position = nullptr;

        while (curr) {
            position = findInsertPosition(&dummy, curr->val);
            ListNode *tmp = curr->next;
            curr->next = position->next;
            position->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ListNode* findInsertPosition(ListNode *head, int x) {
        ListNode *prev = nullptr;
        for (auto curr = head; curr && curr->val <= x;
             prev = curr, curr = curr->next);
        return prev;
    }
};
