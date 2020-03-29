#include <stdio.h>

void main(int argc, char* argv[]){

    printf("sizeof(int) = %ld\n",sizeof(int));
    printf("sizeof(long) = %ld\n",sizeof(long));


    return ;
}

/*
    apt install gcc-multilib
    gcc -m32 xxx.c
*/