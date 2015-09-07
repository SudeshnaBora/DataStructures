int CalculateLengthIterative()
{
    int length=0;
    temp=head;
    while(temp!=0)
    {
        temp=temp->ptr;
        length++;
    }
    return length;
}
