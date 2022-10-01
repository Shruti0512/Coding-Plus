

int removeDuplicates(int* nums, int numsSize){
    int count=1;
    int j=0;
    for(int i=0;i<numsSize-1;i++)
    {
        if(nums[i]!=nums[i+1])
        {
            count++;
            nums[i+1-j]=nums[i+1];
        }
        else
            j++;
    }
    return count;
}
