// 67. Add Binary
#include <string>
#include <math>
using namespace std;

class SolutionV1 
{
public:
    string addBinary(string a, string b) 
    {
        string addString;
        addString.reserve(max(a.size(), b.size()) + 1);

        int carry = 0;
        int aBackIndex = a.length() - 1;
        int bBackIndex = b.length() - 1;
        for (int i = 0; i < max(a.size(), b.size()); i++) 
        {
            int isAOne = (aBackIndex - i) > -1 ? (a[aBackIndex - i] == '1' ? 1 : 0) : 0;
            int isBOne = (bBackIndex - i) > -1 ? (b[bBackIndex - i] == '1' ? 1 : 0) : 0;

            int val = (isAOne + isBOne + carry) % 2;
            carry = (isAOne + isBOne + carry) / 2;
            if (val == 1) 
            {
                addString.push_back('1');
            }
            else 
            {
                addString.push_back('0');
            }
        }

        if (carry == 1) 
        {
            addString.push_back('1');
        }

        int stringLength = addString.length();
        int left = 0;

        while (left < stringLength - left - 1) 
        {
            swap(addString[left], addString[stringLength - left - 1]);
            left++;
        }

        return addString;
    }
};

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string addString;
        addString.reserve(max(a.size(), b.size()) + 1);

        int carry = 0;
        int aBackIndex = a.length() - 1;
        int bBackIndex = b.length() - 1;
        for (int i = 0; i < max(a.size(), b.size()); i++)
        {
            if (aBackIndex - i > -1) 
            {
                carry += a[aBackIndex - i] - '0';
            }

            if (bBackIndex - i > -1) 
            {
                carry += b[bBackIndex - i] - '0';
            }

            addString.push_back((carry % 2) + '0');
            carry /= 2;
        }

        if (carry == 1)
        {
            addString.push_back('1');
        }

        /*int stringLength = addString.length();
        int left = 0;

        while (left < stringLength - left - 1)
        {
            swap(addString[left], addString[stringLength - left - 1]);
            left++;
        }*/

        reverse(begin(addString), end(addString));

        return addString;
    }
};