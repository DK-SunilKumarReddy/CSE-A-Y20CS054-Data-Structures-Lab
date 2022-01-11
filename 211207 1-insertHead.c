SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

SinglyLinkedListNode*n=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
n->data=data;
n->next=llist;
llist=n;
return llist;
}
