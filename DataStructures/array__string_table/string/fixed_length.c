#include "stdio.h"
#include "stdlib.h"
#include"string.h"
#define MAX_STRLEN 256

typedef struct 
{
    char str[MAX_STRLEN];
    int length;
} StringType;

typedef enum {
    OVERFLOW,
    OK,
    ERROR,
    INVALID_STACK_NUM
} Status;

// �����Ӳ���
Status StrContact(StringType*s, StringType t)
{
    if (s->length + t.length > MAX_STRLEN)
        return ERROR;
    for (int i = 0; i < t.length; i++)
    {
        s->str[s->length + i] = t.str[i];
    }
    s->length = s->length + t.length;
    return OK;
}

// ���Ӵ�����
Status SubString(StringType s, int pos, int len, StringType* sub)
{
    if (pos < 1 || pos > s.length || len < 0 || len > s.length - pos + 1)
        return ERROR;
    for (int i = 0, k = pos; i < len; k++, i++)
    {
        sub->str[i] = s.str[k - 1];
    }
    sub->length = len;
    return OK;
}

int main()
{
    StringType s1, s2, sub;
    s1.length = 0;
    s2.length = 0;
    sub.length = 0;

    // �����ַ��� s1 �� s2
    printf("Enter string s1: ");
    scanf("%s", s1.str);
    s1.length=strlen(s1.str);
 
    printf("Enter string s2: ");
    scanf("%s", s2.str);
       s2.length=strlen(s2.str);
    // // ���Դ����Ӳ���
    Status contactStatus = StrContact(&s1, s2);
    if (contactStatus == OK)
    {
        printf("Concatenated string: %s\n", s1.str);
    }
    else
    {
        printf("Error: String concatenation failed.\n");
    }

    // �������Ӵ�����
    int pos, len;
    printf("Enter starting position for substring: ");
    scanf("%d", &pos);
    printf("Enter length of substring: ");
    scanf("%d", &len);

    Status substringStatus = SubString(s1, pos, len, &sub);
    if (substringStatus == OK)
    {
        printf("Substring: %s\n", sub.str);
    }
    else
    {
        printf("Error: Substring extraction failed.\n");
    }
    system("pause");
    return 0;
}

