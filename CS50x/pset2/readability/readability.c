#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void get_grade(float letters, float words, float sentences);

int main(void)
{

    string text = get_string("Text: ");
    int letters = count_letters(text);
    //printf("%i letters\n",letters);
    int words = count_words(text);
    //printf("%i words\n",words);
    int sentences = count_sentences(text);
    //printf("%i sentences\n",sentences);
    get_grade(letters, words, sentences);
}

//count letters, words,sentences in the text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) == false && isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            count++;
        }
    }
    return count;
}

//get_grade : (before 1) or 1-16 or 16+

void get_grade(float letters, float words, float sentences)
{
    float L = (letters / words) * 100.0;
    float S = (sentences / words) * 100.0;
    float index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
