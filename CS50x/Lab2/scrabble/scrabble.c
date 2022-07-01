#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//判斷大寫還小寫，全部轉換為大寫後，取與A的差值來帶入point計算，直到所有字母被走完
int compute_score(string word)
{
    int sum = 0; //總分
    for (int i = 0; i < strlen(word); i++)
    {
        // 如果是小寫，就切換成大寫
        if (islower(word[i]))
        {
            word[i] = word[i] - 32;
        }
        // 轉換成大寫後，確認是否為大寫，排除掉符號的部分
        if (isupper(word[i]))
        {
            int tmp = ((int) word[i]) - 65;
            sum += POINTS[tmp];
        }
    }
    return sum;
}
