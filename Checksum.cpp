#include <bits/stdc++.h>
using namespace std;

string checkSum(string s)
{
	string ans(8, '0');
	string temp(8, '0');

	int carry = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			int sum = (s[i * 8 + j] - '0') + (temp[j] - '0') + carry;
			if (sum == 3)
			{
				sum = 1;
				carry = 1;
			}
			else if (sum == 2)
			{
				sum = 0;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			temp[j] = sum + '0';
		}
		if (carry)
		{
			for (int j = 7; j >= 0; j--)
			{
				int sum = (temp[j] - '0') + carry;
				if (sum == 2)
				{
					sum = 0;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				temp[j] = sum + '0';
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		ans[i] = (temp[i] == '0') ? '1' : '0';
	}

	return ans;
}

int main()
{

	cout << "\n-----------------------------------------------\n";

	// Sender Side
	cout << "Sender's Side : " << endl;
	string s;
	cout << "Enter 32-bit string : ";
	cin >> s;
	int n = s.length();
	while (n < 32)
	{
		s = '0' + s;
		n = s.length();
	}

	cout << endl
		 << "Entered String is : ";

	for (int i = 0; i < 32; i++)
	{
		if (i % 8 == 7 && i != n - 1)
			cout << s[i] << "|";
		else
			cout << s[i];
	}

	string senderStr = checkSum(s);
	cout << "\nCheckSum is : " << senderStr;

	cout << "\n-----------------------------------------------\n";

	// Receiver Side
	cout << "Receiver's Side : " << endl;
	string r;
	cout << "Enter 32-bit string : ";
	cin >> r;
	n = r.length();

	while (n < 32)
	{
		r = '0' + r;
		n = r.length();
	}

	cout << endl
		 << "Entered String is : ";

	for (int i = 0; i < 32; i++)
	{
		if (i % 8 == 7 && i != n - 1)
			cout << r[i] << "|";
		else
			cout << r[i];
	}

	cout << "\nEnter 8-bit received CheckSum : ";
	string checkRec;
	cin >> checkRec;
	n = checkRec.length();
	while (n < 8)
	{
		checkRec = '0' + checkRec;
		n = checkRec.length();
	}

	cout << endl;
	cout << "New Str : " << r << endl;
	string receiverStr = checkSum(r);
	n = receiverStr.length();

	for (int i = 0; i < 8; i++)
	{
		receiverStr[i] = (receiverStr[i] == '0') ? '1' : '0';
	}

	cout << "Received : " << receiverStr << endl;

	int carry = 0;
	for (int j = 7; j >= 0; j--)
	{
		int sum = (checkRec[j] - '0') + (receiverStr[j] - '0') + carry;
		if (sum == 3)
		{
			sum = 1;
			carry = 1;
		}
		else if (sum == 2)
		{
			sum = 0;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		receiverStr[j] = sum + '0';
	}

	for (int i = 0; i < n; i++)
	{
		if (receiverStr[i] == '0')
		{
			cout << "\nDiscarded! Received Data is wrong.\n";
			return 0;
		}
	}
	cout << "\nAccepted! Received Data is right.\n";
	return 0;
}
