#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <cstring>

using namespace std;

char *find(char *s, char a, char b) 
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
        char *r = find(s, 'e', 's');
        assert(strcmp(r, "est string") == 0);
    }
    
    {
        char *s = "test string";
        char *r = find(s, 'r', 's');
        assert(strcmp(r, "st string") == 0);
    }

    {
        char *s = "test string";
        char *r = find(s, 'e', 's');
        assert(strcmp(r, "est string") == 0);
    }

    {
        char *s = "test string";
        char *r = find(s, 'p', 'q');
        assert(r == NULL);
    }
    
    {
        char s[1] = {'\0'};
        char *r = find(s, 'r', 's');
        assert(r == NULL);
    }

    {
        char s[1] = {'\0'};
        char *r = find(s, 'r', '\0');
        assert(strcmp(r, "\0") == 0);
        assert(*r == '\0');
    }

    {
        char s[1] = {'\0'};
        char *r = find(s, '\0', 't');
        assert(strcmp(r, "\0") == 0);
        assert(*r == '\0');
    }
}