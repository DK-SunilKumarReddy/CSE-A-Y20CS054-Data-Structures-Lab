SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

SinglyLinkedListNode*n=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
SinglyLinkedListNode*t=head;
n->data=data;
n->next=NULL;
if(head==NULL)
{
    head=n;
    return head;
}
   while(t->next!=NULL)
       t=t->next;
   t->next=n;
return head;
}
