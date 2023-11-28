struct NumHash {
    int key;
    int val;
    UT_hash_handle hh;
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct NumHash *myHash = NULL, *tmp;
    int *result = malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];

        HASH_FIND_INT(myHash, &num, tmp);
        if (tmp) {
            result[0] = tmp->val;
            result[1] = i;
            *returnSize = 2;
            return result;
        }

        int complement = target - num;
        tmp = malloc(sizeof(struct NumHash));
        tmp->key = complement;
        tmp->val = i;
        HASH_ADD_INT(myHash, key, tmp);
    }

    struct NumHash *currentEntry, *tmpEntry;
    HASH_ITER(hh, myHash, currentEntry, tmpEntry) {
        HASH_DEL(myHash, currentEntry);
        free(currentEntry);
    }

    return NULL;
}
