#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int inDatabase(int id_number, int car_id[]){
    int index_v = -1;
    int i; 
    for(i = 0; i < 10; i++){
        if (car_id[i] == id_number){
            index_v = i; 
            break; 
        }
    }

    return index_v;
}
int main(){
    char input[20] = "";
    int car_number[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    float miles[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int avaiable_slot = 0;
    while (strncmp(input, "quit", 4) != 0){
        printf("> ");
        fgets(input, 20, stdin);
        if (strncmp(input, "AddCar", 6) == 0){
            
            char id_number[strlen(input) - 6];
            strncpy(id_number, &input[6], (strlen(input) - 6)); 
            if (inDatabase(atoi(id_number), car_number) == -1){
                car_number[avaiable_slot] = atoi(id_number);
                avaiable_slot = avaiable_slot + 1;
            }
            else{
                printf("Error! Car with ID %d already exists in the database.\n",atoi(id_number) );
            }

        }
        else if ((strncmp(input, "AddTrip", 7) == 0)){
            int second_space; 
            int i;
            for (i = 1; i < strlen(input) - 7; i++){
                if (input[i+7] == ' '){
                    second_space = i+7;
                    break;
                }
            }
            char id_number[second_space-7];
            strncpy(id_number, &input[7], (second_space-7)); 
            int valid = inDatabase(atoi(id_number), car_number);
            if(valid != -1){
                char miles_driven[strlen(input) - second_space];
                strncpy(miles_driven, &input[second_space], (strlen(input) - second_space)); 
                miles[valid] = miles[valid] + atof(miles_driven);
            }
            else{
                printf("Error! Car with ID %d doesn’t exist in the database.\n",atoi(id_number));
            }
        }
        else if ((strncmp(input, "Display", 7) == 0)){
            int i;
            for (i = 0; i < 10; i++){
                if(car_number[i] != -1){
                    printf("%d\t%0.1f\n", car_number[i], miles[i]);
                }     
            }
        }
        else if (strncmp(input, "Reset", 5) == 0){
            
            char id_number[strlen(input) - 5];
            strncpy(id_number, &input[6], (strlen(input) - 5)); 
            int car_id = inDatabase(atoi(id_number), car_number);
            if (car_id != -1){
                miles[car_id] = 0.0;
            }

        }
    }
    
    return 0; 
}