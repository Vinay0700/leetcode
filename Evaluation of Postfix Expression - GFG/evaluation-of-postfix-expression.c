// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*)
           malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity *
                                   sizeof(int));
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
int peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
int pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, int op)
{
    stack->array[++stack->top] = op;
}



 // } Driver Code Ends
//User function Template for C

// create a stack of size capacity
// struct Stack* createStack( unsigned capacity );

// check if stack is empty
// int isEmpty(struct Stack* stack)

// return top element of stack
// int peek(struct Stack* stack)

// deletes top element of stack if stack is not empty
// int pop(struct Stack* stack)

// pushes element op in the stack
// void push(struct Stack* stack, int op)

//Function to evaluate a postfix expression.
int evaluatePostfix(char* exp) 
{ 
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp)); 
    int i; 
  
    // See if stack was created successfully 
    if (!stack) return -1; 
  
    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0'); 
  
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            } 
        } 
    } 
    return pop(stack);}
// { Driver Code Starts.

int main() {
	
	int t;
	scanf("%d",&t);
    while(t--)
    {
        char *exp;
        scanf("%s",exp);
        printf("%d\n",evaluatePostfix(exp));
    }
	return 0;
}  // } Driver Code Ends