#include <stdio.h>
#include <string.h>

char* reversePrefix(char* word, char ch)
{
    int i, j;
    char temp;

    for (i = 0; i < strlen(word); i++)
    {
        if (word[i] == ch)
            break;
    }

    if (i == strlen(word))
        return word;

    for (j = 0; j < i; j++, i--)
    {
        temp = word[j];
        word[j] = word[i];
        word[i] = temp;
    }

    return word;
}

int main()
{
    char word[] = "abcdefd";
    char ch = 'd';

    printf("%s", reversePrefix(word, ch));

    return 0;
}