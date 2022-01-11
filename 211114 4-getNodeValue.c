int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
SinglyLinkedListNode* t=llist;
int c=0,i;
while(t!=NULL)
{
    c++;
    t=t->next;
}
t=llist;
for(i=1;i<c-positionFromTail;i++)
t=t->next;
return t->data;
}
