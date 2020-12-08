// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Stack implementation in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>

// predefines the name of the type for the stack
struct stack_elem_s;

// defines a name for a pointer to an element of type the stack
typedef struct stack_elem_s* stack_elem_p;

/*
 * defines the structure of the stack
 * first field is the value
 * the second field is the pointer to the element under this element
 */
typedef
struct stack_elem_s
{
    int value;
    stack_elem_p next;
}
// define a short name for 'struct stack_elem_s'
stack_elem_t;

/*
 * define the stack to use.
 */
stack_elem_p stack_p;

/*
 * Pushes a value on the given stack.
 * Allocates memory for the new element on the stack.
 * The new element becomes the top of the given stack.
 */
void push(int i_value, stack_elem_p *stack_p)
{
    // allocate a new element
    stack_elem_p new_elem = (stack_elem_p) malloc(sizeof(stack_elem_t));
    // set the value of the new element
    new_elem->value = i_value; 
    // point the new element to the top of the given stack
    new_elem->next = *stack_p;
    // make the new element the top of the given stack
    *stack_p = new_elem;
}

/*
 * Pops the top element of the given stack and returns its value.
 * Frees up the memory of the popped element.
 * Returns 0 if the stack is empty.
 */
int pop(stack_elem_p *stack_p)
{
    // predefine the result for an empty stack
    int result = 0;
    // if there are elements on the stack ...
    if(stack_p != NULL && *stack_p != NULL)
    {
        // ... get the value from the top element
        result = (*stack_p)->value;
        // get a pointer to the top element
        stack_elem_p tmp = *stack_p;
        // move the stack 1 element down
        *stack_p = (*stack_p)->next;
        // free the temporary (now not on the stack) top element
        free(tmp);    
    }

    // return the value or 0
    return result;
}

/*
 * Prety print of the given stack
 */
void print_stack(stack_elem_p stack_p)
{
    printf("\n - - - = = = STACK = = = - - -\n");
    // get e temporary pointer to the top of the given stack
    stack_elem_p tmp = stack_p;
    // while the temp pointer points to a valid element ...
    while (tmp!=NULL)
    {
        // ... print the value
        printf("%d\n", tmp->value);
        // move the temp pointer to the next element
        tmp = tmp->next;
    }
    printf(" - - - = = = ^ ^^ ^ = = = - - -\n");
}

/*
 * Frees the memory of the given stack
 */
void free_stack(stack_elem_p *stack_p)
{
    // if the given stack is empty
    if(stack_p != NULL && *stack_p != NULL)
    {
        // while the given stack is valid
        while (*stack_p != NULL)
        {
            // get a temporary pointer to the top of the stack
            stack_elem_p tmp = *stack_p;
            // move the stack 1 element down
            *stack_p = (*stack_p)->next;
            // free the temporary (now not on the stack) top element
            free(tmp);
        }
    }
}

/*
 * Entry point
 */
int main()
{
    // initialise the stack
    stack_p = NULL;

    // push 1,2,3 on the stack
    push(1,&stack_p);
    push(2,&stack_p);
    push(3,&stack_p);

    // print the current stack
    print_stack(stack_p);

    // pop the stack
    printf("\npop: %d\n", pop(&stack_p));

    // push 4,5 on the stack
    push(4,&stack_p);
    push(5,&stack_p);

    // print the current stack
    print_stack(stack_p);

    // pop the stack
    printf("\npop: %d\n", pop(&stack_p));

    // print the current stack
    print_stack(stack_p); 

    // free up the memory allocated for the stack
    free_stack(&stack_p);

    return 0;
}
