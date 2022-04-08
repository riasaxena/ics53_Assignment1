#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main (){
    int first_comma = -1; int second_comma = -1; int len = -1;
    char input[256];
    printf("> ");
    fgets(input, 256, stdin);
    int i = 0;
    while(len == -1){
        if (input[i] == ','){
            if (first_comma == -1 ){
                first_comma = i;
            }
            else {
                second_comma = i;
            }
        }
        if (input[i] =='\0'){
            len = i;
            break;
        }
        i = i + 1;
    }
    //printf("%d - %d - %d\n", first_comma, second_comma, len);
    char string_index[second_comma - first_comma]; char string_length[len-second_comma]; 
    strncpy(string_index, &input[first_comma + 1], second_comma-first_comma - 1);
    strncpy(string_length, &input[second_comma + 1], len-second_comma - 1);
    int index = atoi(string_index); 
    int length = atoi(string_length); 
    char string[first_comma];
    if ((index+length) <= first_comma){
        strncpy(string, &input[index],length);
    }
    else{
        strncpy(string, &input[index],first_comma-index);
    }
    string[first_comma-1] = '\0';
    printf("%s\n", string);
    //printf("%d - %d\n", index, length);
    
    return 0;
}