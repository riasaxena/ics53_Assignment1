#include <stdio.h>
#include <string.h>
int max_frequency(int freq[26]){
    int max = 0;
    int i;
    for (i = 0; i < 26; i++){
        if (max < freq[i]){
            max = freq[i];
        }
    }
    return max;
}
void print_freq(int freq[26], char *input){
    char ascending_order [strlen(input)-1];
    int index = 0;
    int max = max_frequency(freq);
    int print_v = 1;
    while (max > print_v - 1){
        int i;
        for (i= 0; i < 26; i++) {
            if (freq[i] == print_v) {
                printf("%c - %d\n", i + 'a', freq[i]);
            }
            if ((print_v == 1) && (freq[i] != 0)){
                int count = 0;
                while (count < freq[i]){
                    ascending_order[index] = i + 'a';
                    count = count + 1;
                    index = index + 1; 
                }
                
            }
        }
        print_v = print_v + 1;
    }
    ascending_order[index] = '\0';
    printf("%s\n", ascending_order);

}
void count_lines(char *input)
{
    int freq[26] = { 0 };
    int i; 
    for (i = 0; i <strlen(input); i++) {
        freq[input[i] - 'a']++;
    }

    
    print_freq(freq, input);
}


int main (){
    char input[256];
    printf("> ");
    fgets(input, 256, stdin);
    int len = strlen(input);
    int i; 
    for(i = 0; i < len; i++){  
        if(input[i] == ' '){  
            int j;
            for(j=i;j<len;j++)  
            {  
                input[j]=input[j+1];  
            }  
            len = len - 1;  
        }  
    }
    input[strlen(input)] = '\0';
    count_lines(input);
    return 0;
}