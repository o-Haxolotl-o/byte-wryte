#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int value=0x00; //value to write
    unsigned int position=0x00; //position to write to
    unsigned short q=0; //whether to quit

    char path[128];
    printf("Enter the path to file:\n");
    scanf("%s", path);
    FILE *checker;
    if(checker = fopen(path, "r")) {
        fclose(checker);
    }
    else {
        printf("File not found\n");
        return 1;
    }

    FILE *file = fopen(path,"r+b");
    while(1) {
        printf("What position to write?\n");
        scanf("%x",&position);
        printf("What value to write?\n");
        scanf("%x",&value);

        fseek(file,position,SEEK_SET);
        fwrite(&value,1,1,file);

        printf("Again? Y/n\n");
        scanf(" %c",&q);
        if(q=='n'||q=='N'){
            break;
        }
    }
    fclose(file);
    return 0;
}
