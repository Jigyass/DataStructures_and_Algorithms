#include <limits.h>

double max(double a, double b) {
    return a > b ? a : b;
}

double min(double a, double b) {
    return a < b ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array
    if (nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;

        int tmpSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tmpSize;
    }

    int low = 0, high = nums1Size;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

        int minX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((nums1Size + nums2Size) % 2 == 0) {
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            } else {
                return max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // This line should theoretically never be reached.
    return -1.0;
}

