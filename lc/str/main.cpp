Write a function that reverses a string. The input string is given as an array of characters char[].

***
Given a 32-bit signed integer, reverse digits of an integer.

***
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

***
Given two strings s and t , write a function to determine if t is an anagram of s.


***
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

***
Implement atoi which converts a string to an integer.
***
Implement strStr().


int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int j = 0;
        // mississippi
        //     issip
        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack[i] != needle[j]) {
                if (j) i = i - j;
                j = 0;
                continue;
            }

            if (++j >= needle.size())
                return i - j + 1;
        }
        return -1;
    }

***
The count-and-say sequence is the sequence of integers with the first five terms as following:

string countAndSay(int n, string s="1") {
        if (n==1)return s;
        int c = 1;
        string r;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size()-1 && s[i] == s[i+1]) {
                ++c;
                continue;
            }
            r += to_string(c);
            r += s[i];
            c = 1;
        }
        return countAndSay(n-1,r);

    }

***
Write a function to find the longest common prefix string amongst an array of strings.

