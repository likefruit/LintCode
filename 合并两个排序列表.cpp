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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode head(0);
        ListNode* temp=NULL;
        ListNode* rear=&head;
        ListNode* temp1=&head;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                rear->next=l1;
                l1=l1->next;
            }
            else
            {
                rear->next=l2;
                l2=l2->next;
            }
            rear=rear->next;
        }
        if(l1!=NULL)
            rear->next=l1;
        if(l2!=NULL)
            rear->next=l2;
        return head.next;
    }
};

// Time:  O(n)
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
