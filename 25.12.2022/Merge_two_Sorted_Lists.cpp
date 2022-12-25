/*
ou are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
    ListNode *newHead = NULL;
    ListNode *newTail = NULL;

    void insertNode(ListNode *node)
    {
        ListNode *newNode = new ListNode(node->val);
        if (newHead == NULL)
        {
            newHead = newNode;
            newTail = newTail;
        }
        else
        {
            newTail->next = newNode;
            newTail = newNode;
        }
    }

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }

        if (list2 == NULL)
        {
            return list1;
        }

        while (list1 != NULL and list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                insertNode(list1);
            }
            else
            {
                insertNode(list2);
            }
        }

        if (list1 == NULL)
        {
            newTail->next = list2;
        }

        if (list2 == NULL)
        {
            newTail->next = list2;
        }
        return newHead;
    }
};