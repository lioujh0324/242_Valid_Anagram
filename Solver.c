
void Swap(char *start, int a,int b);
void QuickSort(char *start,int left,int right,int numsSize);
bool isAnagram(char * s, char * t)
{
    int nums=0,numt=0,i=0;
    char *temp;
    temp=s;
    while (*temp!='\0')
    {
        nums++;
        temp++;
    }
    temp=t;
    while (*temp!='\0')
    {
        numt++;
        temp++;
    }
    if(nums!=numt)
        return false;
    QuickSort(s,1,nums,nums);
    QuickSort(t,1,numt,numt);
    while(i<nums)
    {
        if(*(s+i)!=*(t+i))
            return false;
        i++;
    }
    return true;
}
void Swap(char *start, int a,int b)
{
    char temp;
    temp=*(start+a-1);
    *(start+a-1)=*(start+b-1);
    *(start+b-1)=temp;
}
void QuickSort(char *start,int left,int right,int numsSize)
{
    int pivot=left;
    int i=left+1, j=right+1;
    
    while(i<j)
    {
        while(*(start+i-1)<=*(start+pivot-1) && i<=numsSize-1)
            i++;
        j--;
        while(*(start+j-1)>*(start+pivot-1))
            j--;
        if(i<j)
        {
            Swap(start,i,j);
        }
        else
        {
            Swap(start,pivot,j);
            QuickSort(start,left,j-1,numsSize);
            QuickSort(start,j+1,right,numsSize);
        }
    }

}
