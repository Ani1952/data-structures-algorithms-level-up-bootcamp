
#include <bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key)
{

	// string tokeniser
	//  hello how are you

	char *s = strtok((char *)str.c_str(), " ");
	while (key > 1)
	{
		s = strtok(NULL, " ");
		key--;
	}
	return (string)s;
}

int convertToInt(string s)
{

	int ans = 0;
	int p = 1;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		ans += ((s[i] - '0') * p);
		p = p * 10;
	}
	return ans;
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1 < key2;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return convertToInt(key1) < convertToInt(key2);
}

int main()
{
	int n = 3;
	vector<string> v;

	v={"20,12","45,87","15,17"};

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	// 1. To extract keys for comparison & store them
	vector<pair<string, string>> vp;

	for (int i = 0; i < n; i++)
	{
		vp.push_back({v[i], extractStringAtKey(v[i], key)});
	}

	// 2. Sorting
	if (ordering == "numeric")
	{
		sort(vp.begin(), vp.end(), numericCompare);
	}
	else
	{
		sort(vp.begin(), vp.end(), lexicoCompare);
	}

	// 3. reversal
	if (reversal == "true")
	{
		reverse(vp.begin(), vp.end());
	}

	// 4. output
	for (int i = 0; i < n; i++)
	{
		cout << vp[i].first << endl;
	}

	return 0;
}
