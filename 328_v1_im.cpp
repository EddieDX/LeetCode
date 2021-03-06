/*
  328_v1_im.cpp
  Odd Even Linked List
*/

/**
*Definition for singly-linked list.
*struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
*};
*/
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) return head;
    ListNode *odd = head, *even = head->next, *evenhead = even;
    while (even && even->next) {
      odd->next = odd->next->next;
      even->next = even->next->next;
      odd = odd->next;
      even = even->next;
    }
    odd->next = evenhead;
    return head;
  }
};