/*
Assume that the text is an array T[1…n] of length n and the pattern is an array P[1…m] of length m.
We say that pattern P occurs with shift s in text T if T[s+1,…, s+m]= P[1…m] where 0≤s≤n-m. If P occurs with shift s in T, then we call s a valid shift, otherwise, we call s is an invalid shift.
The text T is said to be an arithmetic text if each valid shift increases by adding some constant k.
For example, T= abxabxab and P=ab , the valid shifts are 0, 3, 6, and each valid shift increases by adding the constant k=3. Therefore T is the arithmetic text.
Otherwise, T is not an arithmetic text.  Print -1 if all shifts are invalid.
Design an algorithm and implement your algorithm to check whether the given text T is the arithmetic text or not.

Input format

Enter the text T

Enter the pattern P

Output format

Print valid shifts or Print -1 for all shifts are invalid.

Print yes for arithmetic text

Print no for not arithmetic text.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void validShift(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int k = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int flag = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                count++;
                j = 0;
            }
        }
        else
        {
            i++;
            j = 0;
        }
    }
    if (count == 0)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << i * k << " ";
        }
    }
}

void arithmeticText(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int k = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int flag = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                count++;
                j = 0;
            }
        }
        else
        {
            i++;
            j = 0;
        }
    }
    if (count == 0)
    {
        cout << "no";
    }
    else
    {
        cout << "yes";
    }
}

int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    validShift(text, pattern);
    cout << endl;
    arithmeticText(text, pattern);
    return 0;
}