bool isAnagram(char* s, char* t)
{
	if(strlen(s) != strlen(t))
	{
		return false;
	}
	int string1[26]={0}, string2[26]={0};
	for(int i=0; s[i]='\0'; i++)
	{
		string1[s[i]-'a']++;
		string2[t[i]-'a']++;
	}
	for(int i=0; i<26;i++)
	{
		if(string1[i]!=string2[i])
		{
			return false;
		}
	}
	return true;
}
