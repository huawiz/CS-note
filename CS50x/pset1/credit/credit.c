#include <cs50.h>
#include <stdio.h>

long get_cardID(void);
bool check_valid(long ID);
void check_type(long card_ID);

int main(void)
{

// 獲取CardID
    long cardID = get_cardID();

//判斷是否有效
    if (check_valid(cardID))
    {
        //如果有效，判斷卡片ID格式
        check_type(cardID);
    }
    else
    {
        printf("INVALID\n");
    }
}


//輸入ID
long get_cardID(void)
{
    long ID;
    do
    {
        ID = get_long("Number: ");
    }
    while (ID < 0);
    return ID;
}

//判斷ID是否有效
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

        //奇位數字直接取和
        if (digit == 0)
        {
            sum_odd += tmp;
            digit++;
        }
        //偶位數字乘上二後加總，如果乘上二後大於十，就再分開加
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

    //奇數和與偶數和加總
    int sum = sum_odd + sum_even;

    //如果是10的模數->有效
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//判斷卡種
void check_type(long ID)
{
    //1 AMEX 長度15 開頭34,37
    if (ID / (long) 1e13 == 34 || ID / (long) 1e13 == 37)
    {
        printf("AMEX\n");
    }
    //2 Master 長度16 開頭51,52,53,54,55
    else if (ID / (long) 1e14 == 51 || ID / (long) 1e14 == 52 || ID / (long) 1e14 == 53 || ID / (long) 1e14 == 54
             || ID / (long) 1e14 == 55)
    {
        printf("MASTERCARD\n");
    }
    //3 VISA 長度13,16 開頭4
    else if (ID / (long) 1e12 == 4 || ID / (long)  1e15 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}