// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Stack implementation in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>

// predefines the name of the type for the stack
struct stack_elem_t;
typedef struct stack_elem_s stack_elem_t;
// defines a name for a pointer to an element of type the stack
typedef struct stack_elem_t *stack_elem_p;

/*
 * defines the structure of the stack
 * first field is the value
 * the second field is the pointer to the element under this element
 */
struct stack_elem_t
{
    int value;
    struct stack_elem_t *next;
};

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
    stack_elem_p new_elem = (stack_elem_p) malloc(sizeof(struct stack_elem_t));
    new_elem->value = i_value; 
    new_elem->next = *stack_p;
    *stack_p = new_elem;
}

/*
 * Pops the top element of the given stack and returns its value.
 * Frees up the memory of the popped element.
 */
int pop(stack_elem_p *stack_p)
{
    int result = 0;
    if(stack_p != NULL && *stack_p != NULL)
    {
        result = (*stack_p)->value;
        stack_elem_p tmp = *stack_p;
        *stack_p = (*stack_p)->next;
        free(tmp);    
    }

    return result;
}

/*
 * Prety print of the given stack
 */
void print_stack(stack_elem_p stack_p)
{
    printf("\n - - - = = = STACK = = = - - -\n");
    stack_elem_p tmp = stack_p;
    while (tmp!=NULL)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    printf(" - - - = = = ^ ^^ ^ = = = - - -\n");
}

/*
 * Frees the memory of the given stack
 */
void free_stack(stack_elem_p *stack_p)
{
    if(stack_p != NULL && *stack_p != NULL)
    {
        while (*stack_p != NULL)
        {
            stack_elem_p tmp = *stack_p;
            *stack_p = (*stack_p)->next;
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
