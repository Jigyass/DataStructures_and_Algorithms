// Create a dummy node to serve as the head of the merged list
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If one of the lists is not empty, append its remaining nodes to the merged list
    if (list1 != NULL) {
        current->next = list1;
    }
    if (list2 != NULL) {
        current->next = list2;
    }

    // The merged list starts from the next of the dummy node
    struct ListNode* merged_head = dummy->next;

    // Free the dummy node (no longer needed)
    free(dummy);

    return merged_head;
