// the function call from the driver program is CalculateLengthRecursive(head)

int CalculateLengthRecursive(struct node *head)
{
    int len=0;
    if(head->ptr!=0)
    {
        len+=CalculateLengthRecursive(head->ptr);
    }
    return (len+1);
}
