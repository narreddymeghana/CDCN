#include <bits/stdc++.h>
using namespace std;

void crcDivision(string data, string generator, string &remainder)
{
    int dataLen = data.length();
    int genLen = generator.length();

    string temp = data;

    for (int i = 0; i <= dataLen - genLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    remainder = temp.substr(dataLen - genLen + 1);
}

string wordToBinary(string word)
{
    string binary = "";

    for (int i = 0; i < word.length(); i++)
    {
        unsigned char ch = word[i];

        for (int j = 7; j >= 0; j--)
        {
            if (ch & (1 << j))
                binary += '1';
            else
                binary += '0';
        }
    }

    return binary;
}

int main()
{
    string word;

    // CRC-4 generator
    // x^4 + x + 1
    string generator = "10011";

    string data;
    string paddedData;
    string remainder;
    string transmitted;

    cout << "Enter a word: ";
    cin >> word;

    // Convert word to binary
    data = wordToBinary(word);

    cout << "\nData in binary : " << data << endl;
    cout << "Generator      : " << generator << endl;

    // Append generator length - 1 zeros
    paddedData = data;

    for (int i = 0; i < generator.length() - 1; i++)
        paddedData += '0';

    // Find CRC remainder
    crcDivision(paddedData, generator, remainder);

    cout << "CRC Remainder  : " << remainder << endl;

    // Append CRC to original data
    transmitted = data + remainder;

    cout << "Transmitted Data: " << transmitted << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void crcDivision(string data, string generator, string &remainder)
{
    int dataLen = data.length();
    int genLen = generator.length();

    string temp = data;

    for (int i = 0; i <= dataLen - genLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    remainder = temp.substr(dataLen - genLen + 1);
}

string wordToBinary(string word)
{
    string binary = "";

    for (int i = 0; i < word.length(); i++)
    {
        unsigned char ch = word[i];

        for (int j = 7; j >= 0; j--)
        {
            if (ch & (1 << j))
                binary += '1';
            else
                binary += '0';
        }
    }

    return binary;
}

int main()
{
    string word;

    string generator = "10011";

    string data;
    string paddedData;
    string remainder;
    string transmitted;

    cout << "Enter a word: ";
    cin >> word;

    data = wordToBinary(word);

    cout << "\nData in binary : " << data << endl;
    cout << "Generator      : " << generator << endl;

    paddedData = data;

    for (int i = 0; i < generator.length() - 1; i++)
        paddedData += '0';

    crcDivision(paddedData, generator, remainder);

    cout << "CRC Remainder  : " << remainder << endl;

    transmitted = data + remainder;

    cout << "Transmitted Data: " << transmitted << endl;

    return 0;
}