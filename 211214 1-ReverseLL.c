SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
SinglyLinkedListNode *t,*p,*c;
t=llist;
c=NULL;
while(t!=NULL)
{
p=c;
c=t;
t=t->next;
c->next=p;
}
llist=c;
return llist;
}
