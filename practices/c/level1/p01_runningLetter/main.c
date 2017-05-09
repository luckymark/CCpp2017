#include <stdio.h>
#include <string.h>
#include <windows.h>

const int delay_time = 50;

int main()
{
    char word[] = "this is the text";
    int word_length = strlen(word);
    for (int i = 0; i < 50; ++i)
    {
        Sleep(delay_time);
        for (int j = 0; j < word_length; ++j)
            putchar('\b');
        printf(" %s", word);
    }
    for (int i = 0; i < 50; ++i)
    {
        Sleep(delay_time);
        printf("\b ");
        for (int j = 0; j < word_length; ++j)
            putchar('\b');
        printf("\b%s", word);
    }
    return 0;
}
