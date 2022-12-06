#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
   List *list = (List*) malloc (sizeof(List));
   list->root = malloc(sizeof(Item));
   return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
   int counter = 1;
   Item  *node = list->root;
   if(list->root==NULL){
      list->root = (Item*)malloc(sizeof(Item));
      list->root->id = counter++;
      short i =0;
      while(str[i] != '\0'){
   i++;
   }
   list->root->str = copy_str(str,i);
   list->root->next = NULL;
   } else { 
      while(node->next!=NULL){
      node=node->next;
      counter++;
   }
   node->next = (Item*)malloc(sizeof(Item));
   node->next->id = counter++;
   short j =0;
   while(str[j] != '\0'){j++;}
   node->next->str = copy_str(str,j);
   node->next->next = NULL;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
   if(list->root == NULL){
      return "Empty";
   }
   Item *temp = list->root;
   while(temp != NULL){
      if(temp ->id == id){
	      return temp->str;
      }
      temp = temp -> next;
   }
   return "Value not found";
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
   Item *temp = list->root;
   while(temp != NULL){
      printf("Item[%d]) %s\n", temp->id,temp->str);
      temp = temp->next;
   }
   printf("\n");
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
   Item *temp;
   while((*list).root != NULL){
      temp = list->root;
      list->root = temp->next;
      free(temp->str);
      free(temp);
   }
   free(list);
}