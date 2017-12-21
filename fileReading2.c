#include <stdio.h>
char *readTheFile(){

    FILE *fp;
    char *buffer=0;
    long long int length;
    char fileName[] = "test.html";
     fp = fopen(fileName,"rb");

    if(fp){

        fseek(fp,0,SEEK_END);
        length = ftell(fp);
        printf("%lld",length);
        fseek(fp,0,SEEK_SET);
        buffer = (char *)malloc(sizeof(char)*(length+1));
        if (buffer)
            fread(buffer,1,length,fp);
        fclose(fp);
        buffer[length]='\0';

    }

    return buffer;

}
int main(){

    char *ch;
    ch = readTheFile();
    puts(ch);
}
