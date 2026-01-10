#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// the goal of this program is to grab all words of english dictionary and write
// a fixed set of words into a file, the words shall be random or determined by 
// character frequecies as the user desires in the future ... As for now for simplicity sake, i'll get the words
// randomly :)
// This program is aimed to be a quick way to practice on your favourite text editor


//#define LINES 370105 // it was an idea, get all words, yet inefficient and caused a segfault //
// stack can't hold too much storage

#define MAXWORD 40
#define WORDS 50



//  I assume : start < end 
int get_random(int start, int end){
    return start + ( rand() % (end - start + 1) ); 
}

int main(){

    
    srand(time(NULL)); // seed with current time //
                       
    FILE *filewords = fopen("words_alpha.txt", "r"); // file containing words //
    FILE *practice = fopen("practice.txt", "w"); // file to practice in //

    if(!filewords){
        perror("Failed to open words_alpha.txt");
        return 1;
    }
    if(!practice){
        perror("Failed to open practice.txt");
        return 1;
    }
    
    char words[WORDS][MAXWORD] = {0}; // we will only store practice words here //
    char *read = NULL;
    int len = 0;

    //  I don't want to load the entire 300K, I will need the heap to store additional //
    //  300K pointers, because i'll need to use the heap, otherwise the program will crash //
    //  with a segfault. //
    
    // first tell how many bytes are inside the file //
    fseek(filewords, 0, SEEK_END);
    long bytes = ftell(filewords);
    rewind(filewords);

    int c;
    int words_added = 0; 
    
    for(int i = 0; i < WORDS ; i++){

        fseek(filewords, get_random(0, bytes - MAXWORD), SEEK_SET); // go to a random byte //
        while((c = fgetc(filewords))!= '\n' && c != EOF){ } // go to next line //

        // we have reached a '\n' 
        if(c == '\n'){
            // our cursor is at '\n' // 
            read = fgets(words[i], MAXWORD, filewords); 
            if(read != NULL){
                len = strlen(words[i]);
                // remove '\n', and '\r' for windows //
                if(len > 0 && words[i][len - 1] == '\n') words[i][len - 1] = '\0';
                if(len > 1 && words[i][len - 2] == '\r') words[i][len - 2] = '\0';
                words_added++;
            }
        } else {
            fprintf(stderr, "c = %c\n", c);
            break;
        }
    }

    if(words_added == WORDS) {
        // print for the user //
        for(int i = 0; i < WORDS; i++){
            if(i && i % 8  == 0) fprintf(practice, "\n"); // after each 8 words, add a newline //
            fprintf(practice, "%s ", words[i]);
            fflush(practice); // ensure output // 
        }
        
        // print some newline characters //
        fprintf(practice, "%.10s", "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        fflush(practice);
    }
    // close the files //
    fclose(filewords);
    fclose(practice);

    // claim victory : this code was not touched by IA, made with love by Laaouina Anas in Neovim btw //
}
