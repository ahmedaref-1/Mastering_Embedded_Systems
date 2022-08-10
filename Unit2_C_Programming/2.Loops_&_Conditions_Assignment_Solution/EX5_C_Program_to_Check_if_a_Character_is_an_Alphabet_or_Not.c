#include <stdio.h>

int main()
{
    char c;
    printf("Please enter the character you want to check:");
    fflush(stdout);fflush(stdin);
    scanf("%c",&c);
    
    if(c>='A'&&c<='Z'||c>='a'&&c<='z')
        printf("%c is an alphabet.",c);
    else
        printf("%c is not an alphabet.",c);

    return 0;
}


