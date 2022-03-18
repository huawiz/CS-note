#include <cs50.h>
#include <stdio.h>

long get_cardID(void);
bool check_valid(long ID);
int check_type(long card_ID);

int main(void)
{

// 獲取CardID
    long cardID = get_cardID();

//判斷是否有效

    if (check_valid(cardID))
    {
        //如果有效，判斷卡片ID格式
        int ID_type = check_type(cardID);
        switch (ID_type)
        {
            case 1:
                printf("AMEX\n");
                break;
            case 2:
                printf("MASTERCARD\n");
                break;
            case 3:
                printf("VISA\n");
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


//get_cardID
long get_cardID(void)
{
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);
    return num;
}

/*
--判別卡有效
    1. 取偶數位的數字，乘上2後,把各個位數數字加總
    2. 再加上非偶數位的數字
    3. 如果是10的模數，就有效
*/

bool check_valid(long ID)
{
    long tmpID = ID;
    int digit = 0; //0=奇數;1=偶數;
    int sum_odd = 0;
    int sum_even = 0;
    do
    {
        int tmp = tmpID % 10;
        tmpID /= 10;

        //奇位數字
        if (digit == 0)
        {
            sum_odd += tmp;
            digit++;
        }
        //偶位數字
        else
        {
            tmp *= 2;
            if (tmp >= 10)
            {
                sum_even += 1 + (tmp % 10);
            }
            else
            {
                sum_even += tmp;
            }
            digit--;
        }
    }
    while (tmpID >= 1);

    //奇數和與偶數和加總，如果%10=0，就有效
    int sum = sum_odd + sum_even;
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int check_type(long num)
{
    //1 AMEX 長度15 開頭34,37
    if (num / (long) 1e13 == 34 || num / (long) 1e13 == 37)
    {
        return 1;
    }
    //2 Master 長度16 開頭51,52,53,54,55
    else if (num / (long) 1e14 == 51 || num / (long) 1e14 == 52 || num / (long) 1e14 == 53 || num / (long) 1e14 == 54
             || num / (long) 1e14 == 55)
    {
        return 2;
    }
    //3 VISA 長度13,16 開頭4
    else if (num / (long) 1e12 == 4 || num / (long)  1e15 == 4)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}