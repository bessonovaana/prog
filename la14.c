#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    FILE *file;
    char f[]="textf.txt";
    char line[100];
    int count=0;
    int n;
    printf("enter number of lines: ");
    scanf("%d", &n);
    file=fopen(f,"w");
    if (file==NULL){
        printf("ERROR\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        int line_length = rand() % 50 + 1;
        char line[line_length + 1];
        for (int j = 0; j < line_length; j++) {
            int random_char = rand() % 62;  // 0-25: буквы в нижнем регистре, 26-51: буквы в верхнем регистре, 52-61: цифры
            if (random_char < 26) {
                line[j] = 'a' + random_char;
            } else if (random_char < 52) {
                line[j] = 'A' + random_char - 26;
            } else {
                line[j] = '0' + random_char - 52;
            }
        }
        line[line_length] = 'n';
        fprintf(file, "%s", line);
    }
    fclose(file);
     file=fopen(f,"r");
    if (file==NULL){
        printf("ERROR\n");
        return 1;
    }
    while (fgets(line, sizeof(line),file)){
        for (int i=0;line[i]!='\0';i++){
            if(isdigit(line[i])){
                count++;
            }
        }
    }
    fclose(file);
    file=fopen(f,"a");
    if (file==NULL){
        printf("ERROR\n");
        return 1;
    }
    fprintf(file,"\nnumber of number in file is %d",count);
    fclose(file);
    printf("look in file\n");

}