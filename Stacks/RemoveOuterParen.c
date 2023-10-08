char * removeOuterParentheses(char * s){
    int len = strlen(s);
    char *result = (char *)malloc(len * sizeof(char));
    int stack = 0;
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            if (stack > 0) {
                result[j] = s[i];
                j++;
            }
            stack++;
        } else {
            stack--;
            if (stack > 0) {
                result[j] = s[i];
                j++;
            }
        }
    }

    result[j] = '\0';
    return result;
}
