# include"stdio.h"
# include"string.h"
# include"ctype.h"
# include"stdlib.h"
int cal(char ch,int x,int y)
{
    if(ch=='+')
        return x+y;
    if(ch=='-')
        return x-y;
    if(ch=='*')
        return x*y;
    if(ch=='/')
       return x/y;
    return -1;

}
int main()
{
    int i=0;
    while(i<10)
    {
        if(i%3==0)
         {i++;
        continue;}
        printf("%d",i);
       i++;
    }
    while (1)
    {
        /* code */
    }
    
    return 0;
}
