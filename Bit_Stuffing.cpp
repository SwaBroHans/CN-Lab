#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "";
	cout << "Enter Bit Stream : ";
	cin >> s;

	int cnt = 0;
	string ans = "";

	for (int i = 0; i < s.length(); i++)
	{
		ans += s[i];

		if (s[i] == '1')
		{
			cnt++;
			if (cnt == 5)
			{
				ans += '0'; // stuff 0 after five 1s
				cnt = 0;
			}
		}
		else
		{
			cnt = 0; // reset on 0
		}
	}

	cout << "\nBit Stuffed : " << ans << endl;
}
