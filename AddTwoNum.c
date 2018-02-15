/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode
 {
      int val;
      struct ListNode *next;
 };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  struct ListNode* re = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* ret = re;
  
  int carry = 0;
  int sum = 0;
  int l1v,l2v;
  ret->val = (l1->val + l2->val)%10;
  carry = (l1->val + l2->val)/10; 
  l1 = l1->next;
  l2 = l2->next;
  ret -> next = NULL;
  while(l1 != NULL || l2 != NULL )
  {
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1 == NULL) {l1v = 0;}else{l1v = l1->val;l1 = l1->next;}
        if(l2 == NULL) {l2v = 0;}else{l2v = l2->val;l2 = l2->next;}
        sum = l1v+l2v+carry;     
	carry = sum/10;
        sum = sum % 10;
        t->val = sum;  
        t->next = NULL;
        ret->next = t;
        ret = t;
  }
  if(carry == 1)
  {
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->val = 1; 
	p->next = NULL;
	ret->next = p;
  }
  return re;  
return re;
}
int main()
{
  struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* r1 = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* r2 = (struct ListNode*)malloc(sizeof(struct ListNode));


     struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
     struct ListNode* r3 = (struct ListNode*)malloc(sizeof(struct ListNode));
      struct ListNode* r4 = (struct ListNode*)malloc(sizeof(struct ListNode));

      l1->val = 2;
      r1->val = 4;
      r2->val = 3;
      l2->val = 5;
      r3->val = 6;
      r4->val = 4;
      l1->next = r1;
      r1->next = r2;
      r2->next = NULL;
      l2->next = r3;
      r3->next = r4;
      r4->next = NULL;
      struct ListNode* re =addTwoNumbers(l1, l2);
      while(re)
{
 printf("%d",re->val);
re = re->next;
}      
 
  return 0;
}
