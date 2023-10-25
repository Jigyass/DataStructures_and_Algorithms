bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t))
        return false;
    
    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < strlen(s); i++) {
        count1[(int)s[i] - 97] += 1;
        count2[(int)t[i] - 97] += 1;
    }

    int result = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            result = false;
            break;
        }
    }

    return result;
}
