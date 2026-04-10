#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "";
	cout << "Enter Bit Stream : ";
	cin >> s;
	int n = s.length();
	int cnt = 0;
	string ans = "";
	for (int i = 0; i < n - 1; i++)
	{
		if (cnt == 5)
		{
			ans = ans + '0';
			cnt = 0;
		}
		if (s[i] == '1' && s[i + 1] == '1')
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		ans = ans + s[i];
	}
	ans = ans + s[n - 1];
	cout << "\nBit Stuffed : " << ans << endl;
}
