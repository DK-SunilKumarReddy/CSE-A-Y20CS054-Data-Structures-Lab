SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
SinglyLinkedListNode *t1=head1,*t2=head1,*t3;
if(head1==NULL)
return head2;
while(head2)
{
    if(head2->data<=t1->data)
    {
        t3=head2->next;
        head2->next=t1;
        if(t1==head1)head1=head2;
        else t2->next=head2;
        t2=head2;
        head2=t3;
    }
    else if(t1->next!=NULL)
    {
        t2=t1;
        t1=t1->next;
    }
    else
    {
    t1->next=head2;
    return head1;
    }
}
return head1;
}
