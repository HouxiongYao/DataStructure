#include"stdio.h"
#include"stdlib.h"
#include"string.h"
void get_next(char*s,int next[])
{
    int i=0;
    next[0]=-1;
    int j=-1;
    while(i<strlen(s)-1)
    {
        if(j==-1||s[i]==s[j])
        {
            j++;
            i++;
            if(s[i]!=s[j])
            next[i]=j;
            else
            next[i]=next[j];
        }
        else j=next[j];
    }
}
int KMP(char*S,char*T,int pos)
{
    int i=pos;
    int j=0;
    int next[strlen(T)];
    get_next(T,next);
    int T_len=strlen(T);
    int S_len=strlen(S);
     while(j<T_len&&i<S_len-pos)
    {
        if(j==-1||S[i]==T[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j==strlen(T))
    return i-strlen(T);
    else return -1;
}
int main() {
    char S[] = "abacadeij";
    char T[] = "ade";
    int pos = 2;
    int result = KMP(S, T, pos);
    if (result != -1) {
        printf("Pattern found at position %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    system("pause");
    return 0;
}