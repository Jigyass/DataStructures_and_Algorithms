struct NumTable
{
	int val;
	UT_hash_handle hh;
};
bool containsDuplicate(int* nums, int numsSize)
{
	struct NumTable myTable = NULL, *tmp;
	for(int i=0; i<numsSize; i++)
	{
		int num = nums[i];
		HASH_FIND_INT(myTable, &num, tmp);
		if(tmp)
		{
			return 1;
		}
		tmp = malloc(sizeof(struct NumTable));
		tmp->val = num;
		HASH_ADD_INT(myTable, val, tmp);

	}
	return false;
}
