// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Initialize variables
    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    // Check if numsSize is less than 3
    if (numsSize < 3) {
        return result;
    }

    for (int i = 0; i < numsSize - 2; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int left = i + 1;
            int right = numsSize - 1;
            int target = -nums[i];

            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    // Allocate memory for the new triplet
                    result = (int**)realloc(result, (*returnSize + 1) * sizeof(int*));
                    result[*returnSize] = (int*)malloc(3 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[left];
                    result[*returnSize][2] = nums[right];
                    (*returnSize)++;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (nums[left] + nums[right] < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
