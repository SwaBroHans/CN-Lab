#include <iostream>
#include <string>

using namespace std;

// XOR between two binary strings
string xorOperation(string a, string b)
{
    string result = "";
    for (int i = 1; i < b.length(); i++)
    {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

// Modulo-2 division
string mod2Division(string dividend, string divisor)
{
    int pick = divisor.length();
    string temp = dividend.substr(0, pick);
    int n = dividend.length();

    while (pick < n)
    {
        if (temp[0] == '1')
            temp = xorOperation(divisor, temp) + dividend[pick];
        else
            temp = xorOperation(string(divisor.length(), '0'), temp) + dividend[pick];

        pick++;
    }

    if (temp[0] == '1')
        temp = xorOperation(divisor, temp);
else
        temp = xorOperation(string(divisor.length(), '0'), temp);

    return temp;
}

// Sender side: encode data
string encodeData(string data, string divisor)
{
    string appended_data = data + string(divisor.length() - 1, '0');
    string remainder = mod2Division(appended_data, divisor);
    return data + remainder;
}

// Receiver side: check data
bool checkData(string received_data, string divisor)
{
    string remainder = mod2Division(received_data, divisor);
    for (char bit : remainder)
    {
        if (bit != '0')
            return false;
    }
    return true;
}

int main()
{
    string data = "100100";
    string divisor = "1101";

    cout << "--- Initial Information ---" << endl;
    cout << "Original Data: " << data << endl;
    cout << "Divisor: " << divisor << endl;

    string transmitted_data = encodeData(data, divisor);
    cout << "\n--- Sender Side ---" << endl;
    cout << "Transmitted Data: " << transmitted_data << endl;

    cout << "\n--- Receiver Side ---" << endl;

    cout << "Scenario 1: " << transmitted_data << endl;
    cout << (checkData(transmitted_data, divisor) ? "Data accepted!" : "Data rejected.") << endl;

    string corrupted_data = transmitted_data;
    corrupted_data[3] = (corrupted_data[3] == '0') ? '1' : '0';

    cout << "\nScenario 2: " << corrupted_data << endl;
    cout << (checkData(corrupted_data, divisor) ? "Data accepted!" : "Data corrupted!") << endl;

    return 0;
}