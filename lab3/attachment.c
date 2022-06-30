#include <stdio.h>

void decrypt(unsigned int *a0, unsigned int *a1, int *a2)
{
    unsigned int v3; // [rsp+1Ch] [rbp-24h]
    unsigned int v4; // [rsp+20h] [rbp-20h]
    long long v5; // [rsp+24h] [rbp-1Ch]
    unsigned int i; // [rsp+28h] [rbp-18h]

    v3 = *a0;
    v4 = *a1;
    v5 = 0x458BCD42 * 64;
    for ( i = 0; i <= 0x3F; ++i )
    {
        v4 -= (v3 + v5 + 20) ^ ((v3 << 6) + a2[2]) ^ ((v3 >> 9) + a2[3]) ^ 0x10;
        v3 -= (v4 + v5 + 11) ^ ((v4 << 6) + *a2) ^ ((v4 >> 9) + a2[1]) ^ 0x20;
        v5 -= 0x458BCD42;
    }
    // printf("\nhaha:%d\n", v5/0x458BCD42);
    *a0 = v3;
    *a1 = v4;
}

int main(int argc, char *argv[])
{
    int a2[] = {2, 2, 3, 4};
    int v8[] = {0xDF48EF7E, 0x20CAACF4, 0xE0F30FD5, 0x5C50D8D6, 0x9E1BDE2D, 0x84F30420,};
    // int v9[] = {0xDF48EF7E, 0x20CAACF4, 3774025685, 1548802262, 2652626477, 0x84F30420,};
    for(int i=0; i<6; i++) printf("%X\n", v8[i]);
    int v6[10], tmp1, tmp2;
    for(int i=0; i<=4; i+=2){
        tmp1 = v8[i];
        tmp2 = v8[i+1];
        decrypt(&tmp1, &tmp2, a2);
        v6[i] = tmp1;
        v6[i+1] = tmp2;
    }
    for(int i=0; i<6; i++) printf("%u\n", v6[i]);
    for(int i=0; i<6; i++) printf("%x", v6[i]);
    printf("\n");
    // char *s = (char *)v6;
    // for(int i=0; i<48; i++) printf("%c", s[i]);
    printf("%lu\n", sizeof(long long));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(unsigned int));
}