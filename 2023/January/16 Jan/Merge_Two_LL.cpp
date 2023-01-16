/* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


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
                           newTail = newNode;
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
                                    list1 = list1->next;
                           }
                           else
                           {
                                    insertNode(list2);
                                    list2 = list2->next;
                           }
                  }

                  if (list1 == NULL and list2 != NULL)
                  {
                           newTail->next = list2;
                  }

                  if (list2 == NULL and list1 != NULL)
                  {
                           newTail->next = list1;
                  }
                  return newHead;
         }
};