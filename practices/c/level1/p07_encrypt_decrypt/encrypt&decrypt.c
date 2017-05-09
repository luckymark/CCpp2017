//
// Created by plusls on 17-3-4.
//

#include "encrypt&decrypt.h"
char **pointer_data = NULL;
int pointer_num = 0, pointer_max;
char *encrypt(const unsigned char *data, int l)
{
    char *ret = (char *)malloc(sizeof(char) * (l * 2 + 1));
    ret[l * 2] = '\0';
    for (int i = 0; i < l; ++i)
    {
        if (data[i] != 0)
            sprintf(ret + i * 2, "%02x", (unsigned char)(data[i] + i));
        else
        {
            ret[i*2] = 'g';
            ret[i*2] = 'g';
        }
    }
    add_pointer(ret);
    return ret;
}
unsigned char *decrypt(char *str)
{
    int l = strlen((char *)str);
    l /= 2;
    char *ret = (char *)malloc(sizeof(char) * l);
    ret[l] = '\0';
    for (int i = 0; i < l; ++i)
    {
        ret[i] = to_num(str[i * 2]) * 16 + to_num(str[i * 2 + 1]) - i;
    }
    add_pointer(ret);
    return ret;
}
void add_pointer(char *p)
{
    if (pointer_data == NULL)
    {
        pointer_data = (char**)malloc(sizeof(char*) * 32);
        pointer_max = 32;
    }
    else if (pointer_num + 1 > pointer_max)
    {
        pointer_max += 32;
        pointer_data = (char**)realloc(p, sizeof(char*) * pointer_max);
    }
    pointer_data[pointer_num] = p;
    ++pointer_num;
}
void free_memory()
{
    for (int i = pointer_num -1; i >= 0; --i)
    {
        free(pointer_data[i]);
    }
    pointer_num = 0;
    free(pointer_data);
    pointer_data = NULL;
}
int to_num(char c)
{
    int ret = 0;
    c = (char)tolower((int)c);
    if(isdigit(c))
        ret += c - '0';
    else
        ret += c - 'a' + 10;
    return ret;
}