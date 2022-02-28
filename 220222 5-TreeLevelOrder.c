void levelOrder( struct node *root) {
typedef struct level{
    struct node*point;
    struct level*next;
}ls;
ls*h=NULL;
h=(ls*)malloc(sizeof(ls));
h->point=root;
h->next=NULL;
ls*t=h;
while(h)
{
    printf("%d ",h->point->data);
    if(h->point->left)
    {
        t->next=(ls*)malloc(sizeof(ls));
        t->next->point=h->point->left;
        t=t->next;
        t->next=NULL;
    }
    if(h->point->right)
    {
        t->next=(ls*)malloc(sizeof(ls));
        t->next->point=h->point->right;
        t=t->next;
        t->next=NULL;
    }
    h=h->next;
}
printf("\n");
}
