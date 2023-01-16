/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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

         // fast and slow pointer algo to find mid
         ListNode *giveMid(ListNode *head, int &a)
         {
                  ListNode *slow = head;
                  ListNode *fast = head;
                  while (!(fast == NULL || fast->next == NULL || fast->next == NULL))
                  {
                           slow = slow->next;
                           fast = fast->next->next;
                           a++;
                  }
                  return slow;
         }

         void reverseLl(stack<ListNode *> &s, ListNode *mid)
         {
                  // mid = mid->next;
                  while (mid != NULL)
                  {
                           s.push(mid);
                           mid = mid->next;
                  }
         }

public:
         void reorderList(ListNode *head)
         {
                  if (!head || !head->next || !head->next->next)
                  {
                           return;
                  }
                  stack<ListNode *> s;
                  int oddOrEve = 0;
                  ListNode *mid = giveMid(head, oddOrEve);

                  reverseLl(s, mid);

                  while (!(s.empty()))
                  {

                           ListNode *temp = head->next;
                           head->next = s.top();
                           head->next->next = temp;

                           head = temp;

                           s.pop();
                  }
                  cout << oddOrEve << endl;
                  //    (oddOrEve%2 == 0)? head->next->next= NULL : head->next = NULL;
                  head->next->next = NULL;
         }
};