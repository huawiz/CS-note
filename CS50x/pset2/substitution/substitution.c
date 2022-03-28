#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_repeat(string s);
bool check_alpha(string s);
void cipher(string key);
char rotate(char letter, string key);

int main(int argc, string argv[])
{
    //check program with one command-line arguments
    if (argc == 2)
    {
        //check program contain 26 letter.
        if (strlen(argv[1]) == 26)
        {
            //check the key doesn't contain repeat and non-alpha letter.
            if (check_repeat(argv[1]) && check_alpha(argv[1]))
            {
                cipher(argv[1]);
                return 0;
            }
            else if (check_repeat(argv[1]) == false)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//check repeat
bool check_repeat(string s)
{
    for (int i = 0 ; i < strlen(s); i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                return 0;
                break;
            }
        }
    }
    return 1;
}

bool check_alpha(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == false)
        {
            return 0;
        }
    }
    return 1;
}

void caesar(string key)
{
    string text = get_string("plaintext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = rotate(text[i], key);
    }
    printf("ciphertext: %s\n", text);
}

char rotate(char letter, string key)
{
    if (isupper(letter))
    {
        return toupper(key[((int)letter) - 65]);
    }
    else if (islower(letter))
    {
        return tolower(key[((int)letter) - 97]);
    }
    else
    {
        return letter;
    }
}