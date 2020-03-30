#include<stdio.h>
#include<stdlib.h>
struct Node{
	char data;
	struct Node *next;
};
void push(struct Node **head_ref, char new_data){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void pop(struct Node **head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
}
int validstr(char str[], struct Node **head_ref){
	int i, result;
	for(i = 0; str[i] != '\0'; i++)
		if(str[i] == '(')
			push(head_ref, i);
		else if(str[i] == ')'){
			if((*head_ref)->next != NULL)
				pop(head_ref);
			if(i - (*head_ref)->data > result)
				result = i - (*head_ref)->data;
			if((*head_ref)->next == NULL)
				push(head_ref, i);
		} else{
			printf("Not a valid string!\n");
			exit(0);
		}
	push(head_ref, i);
	return result;
}
int main(){
	struct Node *head = NULL;
	char str[100];
	printf("Enter string : ");
	scanf("%s", str);
	push(&head, -1);
	printf("Longest valid substring is of lenght %d!\n", validstr(str, &head));    
	return 0;
}
/*1) Create an empty stack and push -1 to it. The first element
   of stack is used to provide base for next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index 
   'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from stack (Most of the time an opening bracket)
   b) If stack is not empty, then find length of current valid
      substring by taking difference between current index and
      top of the stack. If current length is more than result,
      then update the result.
   c) If stack is empty, push current index as base for next
      valid substring.

3) Return result.*/
