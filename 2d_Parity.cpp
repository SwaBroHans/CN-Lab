#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cout << "Enter the binary string : ";
	cin >> s;
	int n = s.length();
	int ones = 0;
	if (n % 8 != 0) // can't break into 8 char set
	{
		for (int i = 0; i < (8 - (n % 8)); i++)
		{
			s = '0' + s;
		}
	}
	n = s.length();
	cout << endl
		 << "Entered String is : ";

	for (int i = 0; i < n; i++)
	{
		if (i % 8 == 7 && i != n - 1)
			cout << s[i] << "|";
		else
			cout << s[i];
	}

	cout << "\n-----------------------------------------------\n";

	vector<vector<char>> mat(n / 8 + 1, vector<char>(9));
	for (int i = 0; i < (n / 8); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			mat[i][j] = s[8 * i + j];
			if (mat[i][j] == '1')
				ones++;
		}
		if (ones % 2 == 1) // if odd number of ones then we add 1 to make even
			mat[i][8] = '1';
		else
			mat[i][8] = '0';
		ones = 0;
	}

	string ans = "";
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < (n / 8); i++)
		{
			if (mat[i][j] == '1')
				ones++;
		}
		if (ones % 2 == 1) // if odd number of ones then we add 1 to make even
		{
			mat[n / 8][j] = '1';
			ans += '1';
		}
		else
		{
			mat[n / 8][j] = '0';
			ans += '0';
		}
		ones = 0;
	}

	for (int i = 0; i <= (n / 8); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 7)
				cout << mat[i][j] << "   ";
			else
				cout << mat[i][j] << " ";
		}
		cout << endl;
		if (i == ((n / 8) - 1))
			cout << endl;
	}
	cout << "\n-----------------------------------------------\n";

	cout << "Code : ";
	for (int i = 0; i <= (n / 8); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << mat[i][j];
		}
		if (i != n / 8)
			cout << "|";
	}
	cout << endl;
}
