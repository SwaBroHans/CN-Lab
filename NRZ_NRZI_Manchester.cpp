#include <bits/stdc++.h>
using namespace std;

string bits;
int n;
int cnt = 0;

void nrzl()
{
	cnt = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (bits[i] != bits[i + 1])
			cnt++;
	}
	cout << "NRZL : " << cnt << endl;
}

void nrzi()
{
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (bits[i] == '1')
			cnt++;
	}
	cout << "NRZI : " << cnt << endl;
}

void bipolarAMI()
{
	cnt = 0;

	for (int i = 1; i < n; i++)
	{
		// count only those which are adjacent 0s then eliminate from total possible
		if (bits[i] == '0' && bits[i - 1] == '0')
		{
			cnt++;
		}
	}
	cout << "Bipolar AMI : " << n - 1 - cnt << endl;
}

void pseudoTernary()
{
	cnt = 0;

	for (int i = 1; i < n; i++)
	{
		// count only those which are adjacent 0s then eliminate from total possible
		if (bits[i] == '1' && bits[i - 1] == '1')
		{
			cnt++;
		}
	}
	cout << "Pseudoternary : " << n - 1 - cnt << endl;
}

void manchester()
{
	cnt = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (bits[i] == bits[i + 1])
			cnt++;
	}

	cout << "Manchester : " << n + cnt << endl;
}

void diffManchester()
{
	cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (bits[i] == '0')
			cnt++;
	}

	cout << "Differential Manchester : " << n + cnt << endl;
}

int main()
{
	cout << "Enter the binary string : ";
	cin >> bits;
	n = bits.length();
	int ch;
	ch = -1;
	while (ch != 7)
	{
		cout << "\n1.NRZI\n2.NRZ-L\n3.Bipolar AMI\n4.Pseudoternary\n5.Manchester\n6.Differential Manchester\n7.Exit\nEnter your choice : ";
		cin >> ch;
		cout << endl;
		switch (ch)
		{
		case 1:
			nrzi();
			break;
		case 2:
			nrzl();
			break;
		case 3:
			bipolarAMI();
			break;
		case 4:
			pseudoTernary();
			break;
		case 5:
			manchester();
			break;
		case 6:
			diffManchester();
			break;
		default:
			break;
		}
	}

	return 0;
}
