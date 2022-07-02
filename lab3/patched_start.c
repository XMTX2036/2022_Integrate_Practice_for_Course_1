#include <stdio.h>

int main(int argc, char *argv[])
{
    char c0[] = {'r', 'q', 'e', 'v', 'L', 'u', 'T', 'Z', 'd', 'C', 'V', 
                 'M', '`', 'X', 'T', 'R', 'G', '}', 'U', 'H', 'B', 'y',
                 'Q', 'V', '^', 'O', 'v', 'N', 'C', 'O', 'J', 0x13, 'n', 
                 0x1F};
    char res[100];
    int n = sizeof(c0)/sizeof(c0[0]);
    printf("%d\n", n);
    for(int i=0; i<n; i++){
        res[i] = c0[i]^(i^0x33);
        printf("%c\n", res[i]);
    }
    // ACTF{Can_you_find_the_true_flag?}
/**
ACTF{Can_you_find_the_true_flag?}
 */
}