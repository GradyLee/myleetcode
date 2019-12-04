#include <stdio.h>
#include <stdlib.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct{
    int val;
    struct ListNode *next;
}ListNode;

ListNode* createListFromArray(int *nums, int cnt) {
	int i;
	ListNode *node, *prev, *head;
	
	if (cnt <= 0) {
		return NULL;
	}
	
	prev = NULL;
	head = NULL;
	
	for (i = 0; i < cnt; i++) {
		node = malloc(sizeof(ListNode));
		node->val = nums[i];
		node->next = NULL;
		
		if (prev) {
			prev->next = node;
		}
		prev = node;
		if (!head) {
			head = node;
		}
	}
	
	return head;
}

ListNode* appendtoList(ListNode* head, int val) {
	if (!head) {
		head = malloc(sizeof(ListNode));
		head->next = NULL;
		head->val = val;
		return head;
	}
	
	ListNode *node, *tail;
	node = malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	
	tail = head;
	for (;;) {
		if (tail->next == NULL) {
			tail->next = node;
			break;
		}
		tail = tail->next;
	}
	
	return head;
}

void printList(ListNode* head) {
	ListNode *node;

	node = head;

	for (;;) {
		if (!node) {
			break;
		}
		printf("%d", node->val);
		node = node->next;
		if (node) {
			printf(" -> ");
		}
		else {
			printf("\n");
		}
	}
}



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	ListNode *a, *b ,*ret;
	a = l1;
	b = l2;

	ret = NULL;
	
	int l ,carry, t;
	carry = 0;
	
	for (;;) {
		t = (a ? a->val : 0) + (b ? b->val : 0) + carry;
		carry = t /10; //may be 0
		l = t % 10;
		
		ret = appendtoList(ret, l);
	
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
		
		if (!a && !b && carry == 0) {
			break;
		}
	}
	
	return ret;
}

int main(int argc, char* argv[]) {
	ListNode *l1, *l2, *ret;
	int a[] = {2, 4, 3};
	int b[] = {5, 6, 4};
	l1 = createListFromArray(a, 3);
	l2 = createListFromArray(b, 3);
	printList(l1);
	printList(l2);
	
	ret = addTwoNumbers(l1, l2);
	
	printList(ret);
	
}