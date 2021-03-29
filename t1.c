#include<stdio.h>
#include<string.h>

char car[20], week[5];
int month, date;
unsigned int length;
int isNum(int x);
int isIo();
int lastDigit();
int threeSame();
int ck(int x, int y);
void checkAllow();
void newEnergy(int begin, int end);

int main()
{
    for(int i = 1; i <= 3; i++)
    {
        scanf("%s %d/%d %s", car, &month, &date, week);
        length = strlen(car);
        if(length == 6)//new energy
        {
            if(car[0] == 'D' || car[0] == 'F')
            {
                newEnergy(1, 5);
            }
            else if(car[5] == 'D' || car[5] == 'F')
            {
                newEnergy(0, 4);
            }
            else
            {
                printf("This number is invalid.\n");
            }
        }
        else if(length == 5)
        {
            if(isIo())
            {
                printf("This number is invalid.\n");
            }
            else if((car[0] == 'T' || car[0] == 'X') && ck(0, 0))//taxi
            {
               printf("This car is allowed to drive.\n");
            }
            //auto-generated
            else if(ck(0, 0) || ck(4, 4) || ck(-1, -1))
            {
                checkAllow();
            }
            //auto-generated
            //self-designed
            else if(threeSame())
            {
                printf("This number is invalid.\n");
            }
            else if(ck(0, 1) || ck(1, 2) || ck(2, 3) || ck(3, 4) || ck(4, 0) || ck(1, 1) || ck(2, 2))
            {
                checkAllow();
            }
            //self-designed
            else
            {
                printf("This number is invalid.\n");
            }
        }
        else
        {
            printf("This number is invalid.\n");
        }
	printf("haha\n");
    }
    return 0;
}

int isNum(int x)
{
    return (car[x] <= '9' && car[x] >= '0');
}

int isIo()
{
    for(int i = 0; i <= 4; i++)
    {
        if(car[i] == 'I' || car[i] == 'O')
        {
            return 1;
        }
    }
    return 0;
}

int lastDigit()
{
    for(int i = 4; i >= 0; i--)
    {
        if(isNum(i))
        {
            return car[i]-'0';
        }
    }
}

int threeSame()
{
    for(int i = 0; i <= 2; i++)
    {
        if(car[i] == car[i+1] && car[i] == car[i+2])
        {
            return 1;
        }
    }
    return 0;
}
//car[x] and car[y] are letters,others are numbers
int ck(int x, int y)
{
    for(int i = 0; i <= 4; i++)
    {
        if((i == x || i == y) == isNum(i))
        {
            return 0;
        }
    }
    return 1;
}

void checkAllow()
{
    if(week[0] != 'S' && lastDigit()%2 != date%2)
    {
        printf("This car is not allowed to drive.\n");
    }
    else
    {
        printf("This car is allowed to drive.\n");
    }
    return;
}

void newEnergy(int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        if(!isNum(i))
        {
            printf("This number is invalid.\n");
            return;
        }
    }
    printf("This car is allowed to drive.\n");
    return;
}
/*3U306 03/27 Sat
T0378 10/21 Thu
N05M8 05/03 Mon
*/
//问题：第一位是T或X，但却是Self-designed类，导致被误判为invalid
