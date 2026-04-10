#include <bits/stdc++.h>
using namespace std;

void receiver()
{
	string s = "";
	cout << "Insert the received data stream : ";
	cin >> s;
	int total = s.length();
	int r = 0;
	while (pow(2, r) < total)
	{
		r++;
	}

	vector<int> arr(total + 1, 0);
	int k = 1;
	for (int i = total - 1; i >= 0; i--)
	{
		arr[k++] = s[i] - '0';
	}
	int errorBit = 0;
	k = 0;
	for (int i = 1; i <= total; i *= 2)
	{
		int ans = 0;
		// right shift i bits to get the last ith bit's parity
		for (int j = i; j <= total; j++)
		{
			int bitShift = log(i) / log(2);
			int tar = (j >> (bitShift));
			if (tar & 1)
				ans ^= arr[j];
		}
		errorBit += (ans * (int)pow(2, (k++)));
	}

	if (errorBit == 0)
		cout << "No Error !!";
	else
	{
		cout << "Error Found in bit : " << errorBit << endl;
		arr[errorBit] = !arr[errorBit];
		cout << "Corrected Data : ";
		for (int i = total; i >= 1; i--)
			cout << arr[i] << " ";
	}

	cout << endl;
}

void sender()
{
	string s = "";
	cout << "Enter Input Bit Stream : ";
	cin >> s;
	// s = "1011010";

	int d = s.length();
	int r = 0;

	while (pow(2, r) < (d + r + 1))
	{
		r++;
	}

	int total = r + d;
	vector<int> arr(total + 1, 0);

	int j = 1, k = d - 1;
	for (int i = 1; i <= total; i++)
	{
		if (i == j)
		{
			j *= 2;
		}
		else
		{
			arr[i] = s[k] - '0';
			k--;
		}
	}

	// filling the parity bits
	for (int i = 1; i <= total; i *= 2)
	{
		int ans = 0;
		// right shift i bits to get the last ith bit's parity
		for (j = i; j <= total; j++)
		{
			int bitShift = log(i) / log(2);
			int tar = (j >> (bitShift));
			if (tar & 1)
				ans ^= arr[j];
		}
		arr[i] = ans;
	}

	cout << "Entered Data is : ";
	cout << s << endl;

	cout << "Data to be sent : ";
	for (int i = total; i >= 1; i--)
		cout << arr[i] << " ";

	cout << endl;
	receiver();
}

int main()
{
	sender();
}
