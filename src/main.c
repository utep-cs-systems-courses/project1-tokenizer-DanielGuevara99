#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h>
#include <ctype.h>

int main()
{   
    char user_in[100];
    List *history = init_history();
    
    printf("Please select one of the following options.\nType your words\nType ! followed by a number to select a token\nHistory = !h\n Quit = !q\n");

    while(1){
        printf("%s", "\n> ");
        fgets(user_in, 100, stdin);
        if(user_in[0] == '!' && user_in[1] == 'h'){
	        print_history(history);
        } else if (user_in[0] == '!' && isdigit(user_in[1])) {
	        printf("%s\n", get_history(history, user_in[1]-'0'));
        } else if(user_in[0] == '!' && user_in[1] == 'q') {
	        return 0;
        } else {
	        add_history(history, user_in);
	        char **tokens = tokenize(user_in);
	        print_tokens(tokens);
	        free_tokens(tokens);
        }
    }
}