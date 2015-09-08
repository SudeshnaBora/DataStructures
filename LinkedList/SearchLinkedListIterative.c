
void SearchlinkedListIterative(int element)
{
    temp=head;
    while(temp!=0)
    {
        if(temp->num==element)
        {
            printf("The element is in the linked list\n");
            return;
        }
        temp=temp->ptr;
    }
    printf("The element is not in the linked list\n");
    return;
}
