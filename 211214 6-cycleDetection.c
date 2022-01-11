bool has_cycle(SinglyLinkedListNode* head) {
SinglyLinkedListNode* t1=head,*t2=head;
while(t2 && t2->next)
{
    t1=t1->next;
    t2=t2->next->next;
    if(t1==t2)
    return 1;
}
return 0;
}
