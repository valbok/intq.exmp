Write a function that reverses a string. The input string is given as an array of characters char[].

    void reverseString(vector<char>& s) {
        // 1234
        for (int i = 0; i < s.size()/2; ++i) {
            char tmp = s[i];
            s[i] = s[s.size() - 1  - i];
            s[s.size() - 1  - i] = tmp;
        }
    }
***
Given a 32-bit signed integer, reverse digits of an integer.

int reverse(int x) {
        bool n = x <0;
        string str= to_string(labs(x));
        std::reverse(str.begin(),str.end());
        int r=0;
        try {
        r= stoi(str);
            return n?0-r:r;
        } catch (...) {}
        return 0;
    }

***
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

    int firstUniqChar(string s) {
        int t[256]={0};
        for (int i=0;i<s.size();++i) {
            ++t[s[i]];
        }
        for (int i=0;i<s.size();++i) {
            if (t[s[i]] == 1)return i;
        }
        return -1;
    }

***
Given two strings s and t , write a function to determine if t is an anagram of s.
 bool isAnagram(string s, string t) {
        int s1[256] ={0};
        for (char a:s)
            ++s1[a];
        int s2[256] ={0};
        for (char a:t)
            ++s2[a];
        for (int i=0;i<256;++i) {
            if (s1[i]==0&&s2[i]==0)continue;
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }

***
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

bool isPalindrome(string s) {
        int i = 0, j=s.size()-1;
        while (i <j) {
            if (!isalnum(s[i])) {++i;continue;}
            if (!isalnum(s[j])) {--j;continue;}
            if (tolower(s[i]) !=tolower(s[j]))return false;
            ++i;
            --j;
        }
        return true;
    }
***
Implement atoi which converts a string to an integer.

int myAtoi(string str) {
        int r=0;
        bool n = false;
        bool s = false;
        for (int i =0;i<str.size();++i) {
            if (!s&&str[i]==' ')continue;
            if (!s&&str[i]=='-'){n=true;s=true;continue;}
            if (!s&&str[i]=='+'){s=true;continue;}
            if (!isdigit(str[i]))break;
            int t = str[i]-'0';
            if (r&&INT_MAX/r <10)return n?INT_MIN:INT_MAX;
            r*=10;
            if (r&&INT_MAX-r <t)return n?INT_MIN:INT_MAX;
            r+=t;
            s=true;
        }
        return n?0-r:r;
    }
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

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()<1) return "";
        if (strs.size()<2) return strs[0];
        sort(strs.begin(),strs.end());
        string f = strs[0];
        string s = strs[strs.size()-1];
        string r;
        for (int i = 0; i < f.size(); ++i) {
            if (f[i] != s[i])
                return r;
            r += s[i];
        }
        return r;
    }