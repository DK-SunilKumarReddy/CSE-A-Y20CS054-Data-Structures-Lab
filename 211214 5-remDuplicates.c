SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
SinglyLinkedListNode *t1=llist,*t2;
while(t1->next!=NULL)
{
    t2=t1->next;
    if(t1->data==t2->data)
    {
        t1->next=t2->next;
        free(t2);
    }
    else
    t1=t1->next;
}
return llist;
}
