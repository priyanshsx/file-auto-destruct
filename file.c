// importing libraries

#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>

int main() {

    // step 1: create the target file 
        // create the storage array for the input 
        char input[250];

        // ask the user for an input 
        printf("What string would you like to test?: ");

        // using fgets to get the string from the user 
        fgets(input, sizeof(input), stdin);

        // open file 
        FILE *file_ptr = fopen("textdetonator.txt", "a");

        // checking we actually got the memory for the file
        if (file_ptr == NULL) {
            printf("Fatal error. File could not be created. Please close the program and try again.\n");
            return 1;
        }

        // use fprintf to put some text inside it, then close it
        fprintf(file_ptr, "Input text: %s", input); 
        fclose(file_ptr);

    // step 2: arm the bomb 
        time_t start_time = time(NULL);
        printf("File created. Detonator in 15 seconds...\n");

    // step 3: countdown loop 
    // capture the current time using time_t
    // calculate the difference between the current time and the file creation time 
    // print a countdown message to the terminal 
        while (1) {
            // grabbing the current time as a unix timestamp 
            time_t current_time = time(NULL);

            // used double here to store the unix timestamp 
            double elapsed_seconds = difftime(current_time, start_time);
            // to convert into actual seconds
            int seconds_left = 15 - (int)elapsed_seconds;

            if (seconds_left <= 0) {
                printf("\nTime's up.\n");
                break;
            }

            // printing the timer on terminal 
            printf("\rDetonating in: %i", seconds_left);
            fflush(stdout);

            // to prevent the loop from running continuously 
            sleep(1);
        }
    
    // step 4: detonation (delete the file)
    // uses remove()
    // print success 
            if (remove("textdetonator.txt") == 0){
                printf("Successfully removed the file.\n");
            } else { 
                printf("Failed to remove the file.\n");
            }

    return 0;

}