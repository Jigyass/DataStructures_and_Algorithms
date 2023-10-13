int maxDepth(char * s){
    int maxDepth = 0;
    int currentDepth = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            currentDepth++;
            if (currentDepth > maxDepth) {
                maxDepth = currentDepth;
            }
        } else if (s[i] == ')') {
            currentDepth--;
            if (currentDepth < 0) {
                return -1; // This means the string is not a VPS
            }
        }
    }

    if (currentDepth != 0) {
        return -1; // This means the string is not a VPS
    }

    return maxDepth;
}
