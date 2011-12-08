
#include <string.h>

#include "pstringx.h"


USING_PTYPES


string trim(string s)
{
    int old_len = length(s);
    int new_len = old_len;
    if (new_len == 0)
        return nullstring;

    int ltrim = 0, rtrim = 0;
    const char* b = s;

    const char* p;
    for (p = b + old_len - 1; p >= b; p--)
        if (uchar(*p) <= uchar(' '))
            rtrim++;
        else
            break;
    new_len -= rtrim;

    for (p = b; p < b + new_len; p++)
        if (uchar(*p) <= uchar(' '))
            ltrim++;
        else
            break;
    new_len -= ltrim;

    if (new_len == 0)
        return nullstring;

    if (new_len == old_len)
        return s;

    if (ltrim > 0)
    {
        char* p = unique(s);
        memmove(p, p + ltrim, new_len);
    }

    setlength(s, new_len);

    return s;
}


string implode(const string& separator, const variant& array)
{
    if (alength(array) == 0)
        return nullstring;
    bool first = true;
    variant item;
    string result;
    for (int i = 0; anext(array, i, item); )
    {
        if (!first)
            result += separator;
        else
            first = false;
        result += string(item);
    }
    return result;
}


variant explode(char separator, const string& s)
{
    if (isempty(s))
        return nullvar;

    variant result;
    const char* p = s;
    const char* e = p;
    do
    {
        e = strchr(p, separator);
        if (e == 0)
            e = pconst(s) + length(s);
        aadd(result, string(p, int(e - p)));
        if (*e != 0)
            e ++;
        p = e;
    }
    while (*p != 0);
    return result;
}


variant explode(const string& separator, const string& s)
{
    if (isempty(s))
        return nullvar;

    variant result;
    const char* p = s;
    const char* e = p;
    do
    {
        e = strstr(p, separator);
        if (e == 0)
            e = pconst(s) + length(s);
        aadd(result, string(p, int(e - p)));
        if (*e != 0)
            e += length(separator);
        p = e;
    }
    while (*p != 0);
    return result;
}


string uppercase(const string& s)
{
    string r = s;
    char* p = pchar(pconst(r));
    bool u = false;
    int i = 0;
    while (*p != 0)
    {
        char c = upcase(*p);
        if (c != *p)
        {
            if (!u)
            {
                p = unique(r) + i;
                u = true;
            }
            *p = c;
        }
        p++;
        i++;
    }
    return r;
}
