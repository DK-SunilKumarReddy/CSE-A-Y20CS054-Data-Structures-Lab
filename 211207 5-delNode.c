SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    int i;
SinglyLinkedListNode*t=llist;
if(position==0)
{
    llist=t->next;
    free(t);
    return llist;
}
for(i=1;i<position;i++)
t=t->next;
SinglyLinkedListNode* t2=(t->next)->next;
free(t->next);
t->next=t2;
return llist;
}
