#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
   if (c == ' ' || c == '\t'){
      return 1;
   }
   return 0;
}

int non_space_char(char c)
{
   if(c != ' ' && c != '\t'){
      return 1;
   }
   return 0;
}

char *word_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  return str;/*return a pointer pointing to the start of a word*/
}

char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(word[i])){
    i = i+1;
  }
  
  return &word[i];
}

int count_words(char *str)
{
   int count = 0,i;
   int len = strlen(str);
   for(i = 0; i < len; i++) {
      if(space_char(str[i]) && non_space_char(str[i + 1]))
         count++;
   }
   return count;
}

char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc(sizeof(char) * (len+1));
  int i;
  for (i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[i] = '\0';
  
  return copy;
}

char **tokenize(char* str)
{
  int totalW = count_words(str);
  char **tokens = (char **) malloc ((totalW + 1) * sizeof(char *));
  char *start = word_start(str);
  char *end;
  int i;
  for (i = 0; i<totalW; i++){
    end = word_terminator(str=word_start(str));
    tokens[i] = copy_str(start,end-str);
    str = end;
  }
  tokens[i] = NULL;
  return tokens;
}


void print_tokens(char **tokens)
{
   for(int i = 0; tokens[i] != '\0'; i++){
     printf("%s\n",tokens[i]);
    }
}

void free_tokens(char **tokens)
{
  while (*tokens != 0){
    free(*tokens);
    tokens++;
  }
  free(tokens);
}