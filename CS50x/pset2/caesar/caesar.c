#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_digits(string s);
void caesar(string key);
char rotate(char letter, int key);
int main(int argc, string argv[])
{

    //check program with one command-line arguments and it's digit
    if (argc == 2 && check_digits(argv[1]))
    {
        caesar(argv[1]);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool check_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == false)
        {
            return 0;
            break;
        }
    }
    return 1;
}
/*
原始符號+KEY-Z符號+(A符號-1)=加密後的符號
例如O--+13-->B: 79+13-90+64 = 66
C_i = ((p_i-64)+k)%26+64 is upper
C_i = ((p_i-97)+k)%26+97 is lower
*/


void caesar(string key)
{
    string text = get_string("plaintext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = rotate(text[i], atoi(key));
    }
    printf("ciphertext: %s\n", text);
}

char rotate(char letter, int key)
{
    if (isupper(letter))
    {
        return (((int)letter - 64) + key) % 26 + 64;
    }
    else if (islower(letter))
    {
        return (((int)letter - 97) + key) % 26 + 97;
    }
    else
    {
        return letter;
    }
}