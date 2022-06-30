#include <stdio.h>

int main(void)
{
    char v3[30];
    char v4[26] = "MMMwjau`S]]S}ybS?4:;5:<4<q";
    // printf("Please input flag:");
    // scanf("%s", v3);
    for(int i=0; i<26; i++){
        v3[i] = v4[i]^0xC;
        printf("%c", v3[i]);
        // if((v3[i] ^ 0xC) != v4[i])
    }
    printf("\n");
    // printf("%s", v3);
}