#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <cstring>

using namespace std;

/** 
 * Simplify the implementation below as much as you can. 
 * Even better if you can also improve performance as part of the simplification!
 * FYI: This code is over 35 lines and over 300 tokens, but it can be written in
 * 5 lines and in less than 60 tokens.
*/

char *func(char *s, char a, char b) 
{
    char *res = NULL;
    int i = 0;
    do
    {
        if (s[i] == a || s[i] == b) 
        {
            res = &s[i];
        }
    } while (s[i++] != '\0' && res == NULL);
 
    return res;
}

int main() 
{
    {
        char *s = "test string";
        char *r = func(s, 'e', 's');
        assert(strcmp(r, "est string") == 0);
    }
    
    {
        char *s = "test string";
        char *r = func(s, 'r', 's');
        assert(strcmp(r, "st string") == 0);
    }

    {
        char *s = "test string";
        char *r = func(s, 'e', 's');
        assert(strcmp(r, "est string") == 0);
    }
    
    {
        char s[1] = {'\0'};
        char *r = func(s, 'r', 's');
        assert(r == NULL);
    }

    {
        char s[1] = {'\0'};
        char *r = func(s, 'r', '\0');
        assert(strcmp(r, "\0") == 0);
        assert(*r == '\0');
    }

    {
        char s[1] = {'\0'};
        char *r = func(s, '\0', 't');
        assert(strcmp(r, "\0") == 0);
        assert(*r == '\0');
    }
}