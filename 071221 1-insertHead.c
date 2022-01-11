// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

SinglyLinkedListNode*n=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
n->data=data;
n->next=llist;
llist=n;
return llist;
}
