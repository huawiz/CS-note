#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*輸入h*/
    int h = 0;
    do
    {
        int height = get_int("Height:");
        h = height;
    }
    while (h < 1 || h > 8);
    /*定義b函數，用來製造空格*/
    int b = h;
    for (int i = 0; i < h ; i++)
    {
        for (int j = 0; j < b - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
        b--;
    }
}
