#include<stdio.h>
#define maxn 30

int n;
int reg[6] = {0};
int opt[maxn], a[maxn], b[maxn], c[maxn];
char tmp[10];
void work(int x);

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", tmp);
        if(tmp[0] == 'a')
        {
            opt[i] = 1;
            scanf(" x%d x%d x%d", &a[i], &b[i], &c[i]);
        }
        else if(tmp[0] == 's')
        {
            opt[i] = 2;
            scanf(" x%d x%d x%d", &a[i], &b[i], &c[i]);
        }
        else if(tmp[0] == 'm')
        {
            opt[i] = 3;
            scanf(" x%d x%d x%d", &a[i], &b[i], &c[i]);
        }
        else if(tmp[0] == 'd')
        {
            opt[i] = 4;
            scanf(" x%d x%d x%d", &a[i], &b[i], &c[i]);
        }
        else if(tmp[0] == 'l')
        {
            opt[i] = 5;
            scanf(" x%d %d", &a[i], &b[i]);
        }
        else if(tmp[0] == 'p')
        {
            opt[i] = 6;
            scanf(" x%d", &a[i]);
        }
        else
        {
            opt[i] = 7;
            scanf(" x%d x%d %d", &a[i], &b[i], &c[i]);
        }
    }
    work(1);
    return 0;
}

void work(int x)
{
    if(x > n)
    {
        return;
    }
    if(opt[x] == 1)
    {
        reg[a[x]] = reg[b[x]]+reg[c[x]];
    }
    else if(opt[x] == 2)
    {
        reg[a[x]] = reg[b[x]]-reg[c[x]];
    }
    else if(opt[x] == 3)
    {
        reg[a[x]] = reg[b[x]]*reg[c[x]];
    }
    else if(opt[x] == 4)
    {
        reg[a[x]] = reg[b[x]]/reg[c[x]];
    }
    else if(opt[x] == 5)
    {
        reg[a[x]] = b[x];
    }
    else if(opt[x] == 6)
    {
        printf("x%d = %d\n", a[x], reg[a[x]]);
    }
    else if(reg[a[x]] >= reg[b[x]])
    {
        work(c[x]);
        return;
    }
    work(x+1);
    return;
}