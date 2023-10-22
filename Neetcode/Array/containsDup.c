struct NumHash{
    int val;
    UT_hash_handle hh;
};
bool containsDuplicate(int* nums, int numsSize){
    struct NumHash *myTable = NULL, *tmp;
    for(int i=0; i<numsSize; i++)
    {
        int num = nums[i];
        HASH_FIND_INT(myTable, &num, tmp);
        if(tmp)
        {
            return 1;
        }
        tmp = malloc(sizeof(struct NumHash));
        tmp->val = num;
        HASH_ADD_INT(myTable, val, tmp);
    }

    struct NumHash *currentEntry, *tmpEntry;
    HASH_ITER(hh, myTable, currentEntry, tmpEntry)
    {
        HASH_DEL(myTable, currentEntry);
        free(currentEntry);
    }

    return 0;


}
