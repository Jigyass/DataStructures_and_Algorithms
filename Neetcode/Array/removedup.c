int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int uniqueCount = 1; // Initialize unique count to 1 for the first element

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount] = nums[i]; // Move unique elements to the front
            uniqueCount++;
        }
    }

    return uniqueCount;
}

