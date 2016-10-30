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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int value = 0;
		ListNode *p= l1;
		ListNode *q = l2;
		ListNode *root = NULL, *iter = NULL;
		int c = 0;
		while (p != NULL&&q != NULL)
		{
			value=p->val + q->val+c;
			c = value / 10;
			value %= 10;
			ListNode *ls = new ListNode(value);
			if (root == NULL)
				root = ls;
			if (iter != NULL)
				iter->next= ls;
			iter = ls;
			p = p->next;
			q = q->next;
		}
		while (p != NULL)
		{
			value = p->val + c;
			c = value / 10;
			value %= 10;
			ListNode *ls = new ListNode(value);
			if (root == NULL)
				root = ls;
			if (iter != NULL)
				iter->next= ls;
			iter = ls;
			p = p->next;
		}
		while (q != NULL)
		{
			value = q->val + c;
			c = value / 10;
			value %= 10;
			ListNode *ls = new ListNode(value);
			if (root == NULL)
				root = ls;
			if (iter != NULL)
				iter->next= ls;
			iter = ls;
			q = q->next;
		}
		if (c == 1)
		{
			ListNode *ls = new ListNode(1);
			iter->next = ls;
			ls->next = NULL;
		}
        return root;
        
    }
};
