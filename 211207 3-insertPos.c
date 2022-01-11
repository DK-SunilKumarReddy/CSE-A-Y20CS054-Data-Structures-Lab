SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    int i;
SinglyLinkedListNode* n,*t=llist;
n=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
n->data=data;
n->next=NULL;
if(position==0)
{
    n->next=llist;
    llist=n;
    return llist;
}
for(i=1;i<position;i++)
    t=t->next;
n->next=t->next;
t->next=n;
return llist;
}
