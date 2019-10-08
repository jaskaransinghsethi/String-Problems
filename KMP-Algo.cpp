vector<int> computeLPSArray(string pattern)
{
	vector<int> LPS(pattern.size(), 0);
	int len = 0;
	LPS[0] = 0;
	int i = 1;
	while (i < pattern.size())
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			LPS[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = LPS[len - 1];
			}
			else
			{
				LPS[i] = 0;
				i++;
			}
		}
	}

	return LPS;
}

int KMPSearch(string text, string pattern)
{
	if (text == "" && pattern == "")
		return 0;

	if (text == "")
		return -1;

	if (pattern == "")
		return 0;

	vector<int> LPS = computeLPSArray(pattern);

	int i = 0, j = 0;
	while (i < text.size())
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}

		if (j == pattern.size())
		{
			return i - j;
		}

		if (i < text.size() && text[i] != pattern[j])
		{
			if (j != 0)
				j = LPS[j - 1];
			else
				i++;
		}
	}

	return -1;
}
