#include <stdio.h>
#include <math.h>
#include <locale.h>

int in_system(int ten_number, int power)// from 10 in other system without sixteen
{
    setlocale(LC_ALL, "Rus");
    int remain;//remain is remainder of the division
    int res = 0;
    int count = 1;
    while (ten_number > 0)
    {
        if (ten_number % power != 0)
        {
            remain = ten_number % power;
            remain = remain * count;// multiply count on 10
            count *= 10;
            res += remain;//New variable for sum
            ten_number /= power;//continue to divide and again to return up
            /* In this act cycle to devise number in "ten system" but numbers
            turns around. For example, you enter num =  52, after first iteration value of iteration becomes equal to 4, in next iteration value return us 60.
            But true answer is 64 and i fixed in this in 17, 18, 30 and 31 lines
             */
        }
        else
            {
                ten_number /= power;
                remain = 0;
                count *= 10;
                res = res + remain * count * 10;
            }
    }
    printf("Your number: %d\n", res);

}
int of_system(int n, int a)// for any in 10 without 16
{
    int count = 0;
    int b, base;
    int s = 0;
    while (a != 0)
        {
            if (a / 10 != 0 || a / 10 == 0)
            {
                b = a % 10;
                a = (a - b) / 10;
                base = b * (pow(n,count));//Is regular algorithm to transfer, same how manually
                count ++;
                s += base;
            }
            else
                break;
        }
        return s;
}
int main()
{
    int n1,sys,number,res,res2;
    setlocale(LC_ALL, "Rus");
    printf("From which number system do you want to transfer ? ");
    scanf("%d", &n1);
    printf("What kind of system do you want? ? ");
    scanf("%d", &sys);
    printf("Enter a number: ");
    scanf("%d", &number);
    if ( n1 == 10)
    {
        res = in_system(number,sys);
        printf("Your number in %d system calculus: %d\n ",sys, res);
    }
    else
    {
        res = of_system(n1, number);
        res2 = in_system(res, sys);
    }
}
