// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// List with integer numbers in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/*

Да се напише функцията remove_by_value().
Функцията премахва елемента с дадена стойност от даден списък и го връща като резултат. Дефиницията на функцията да е следната

element_t * remove_by_value(element_t ** plist, int value);

където :
plist - двоен указател към началото (върха) на списъка,
value - стойността на елемента, който да се махне от списъка.

Функцията трябва да намери елемента, който има стойност равна на стойността на value, да махне този елемент от списъка, като при това списъкът да остане свързан, и да върна указателя към елемента като резултат.

Например, ако списъкът съдържа следните елементи - 1,2,3,4,5,6, тогава ако извикаме remove_by_value  с параметри указател към списъка (т.е. към първия му елемент) и value = 4 функцията връща елемент със стойност 4, а списъкът остава 1,2,3,5,6.
Ако няма елемент със зададената стойност, тогава функцията връща NULL.
Ако списъкът има само един елемент, тогава функцията връща този елемент, ако той има стойност равна на value, а самият списък се изпразва, т.е. *plist = NULL.

Подсещане.
1) Провери дали plist == NULL и *plist == NULL - това означава празен списък.
2) Използвай временна променлива за да обходиш списъка.
3) Запомни във временна променлива предния елемент, за да можеш когато махаш текущия елемент да пренасочиш предния към следващия, т.е. в примера по-горе 3 е предния елемент, който, като се махне 4 (текущия елемент), трябва да се пренасочи към (свърже за) следвашия елемент 5.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element_value_t;

// pre-definition of the list's element
struct element_s;

// definition of pointer to an element
typedef struct element_s * element_p;

// definition of double pointer to an element
typedef element_p *element_pp;

// definition of the list's element structure
typedef 
struct element_s {
    element_value_t value;
    element_p next;
}
element_t;

/*

plist е променлива от туп двоен указател към елемент от списъка

I) Празен списък (при едно от двете условия): 
1) plist == NULL
2) *plist == NULL

II) Списък с 1 елемент:
            +=========================+
(*plist) -> | value = 1 | next = NULL |
            +=========================+

III) Списък с 3 елемента
            +=========================+  +=========================+  +=========================+
(*plist) -> | value = 1 | next -------+->| value = 2 | next -------+->| value = 3 | next = NULL |
            +=========================+  +=========================+  +=========================+

IV) Премахване на елемент от списък
1) prev_elem->next = curr_elem

            +=========================+  +=========================+  +=========================+
(*plist) -> | value = 1 | next -------+->| value = 2 | next -------+->| value = 3 | next = NULL |
            +=========================+  +=========================+  +=========================+
             ^                             ^
prev_elem ---+                             |
curr_elem ---------------------------------+

2) prev_elem->next = curr_elem->next    
                                        +--------------------------------\/
            +=========================+ |  +=========================+  +=========================+
(*plist) -> | value = 1 | next -------+-+  | value = 2 | next -------+->| value = 3 | next = NULL |
            +=========================+    +=========================+  +=========================+
             ^                              ^
prev_elem ---+                              |
curr_elem ----------------------------------+

3) curr_elem->next = NULL

            +=========================+                                +=========================+
(*plist) -> | value = 1 | next -------+------------------------------->| value = 3 | next = NULL |
            +=========================+   +=========================+  +=========================+
             ^                            | value = 2 | next = NULL |
             |                            +=========================+ 
prev_elem ---+                             ^
curr_elem ---------------------------------+


*/
// same as 'element_t * remove_by_value(element_t ** plist, int value)'
element_p remove_by_value(element_pp plist, element_value_t value) {
    // result variable
    element_p result = NULL;

    if (plist != NULL && *plist != NULL)
    {
        result = *plist;
        // walk through the list, 
        // while result does not point to an element with value == given value 
        while (result != NULL && result->value != value) 
        {
            result = result->next;
        }

        // here if result != NULL then we have found an element with value == given value
        if (result != NULL)
        {
            // find the element whose position is just before the element that will be removed from the list 
            element_p prev_elem = *plist;
            while (prev_elem->next != result) {
                prev_elem = prev_elem->next;
            }
            // ...
            
        }
    }

    return result;
}

int* sum (int a, int b)
{
    int* tmp = malloc(sizeof(int));
    *tmp = a + b);
    return tmp;
}


// MAIN ENTRY POINT
int main(int argc, char const *argv[])
{
    int* p = sum(3,4);
    printf(" sum of 3 + 4 is %d\n", *p);
    free(p);

    return 0;
}
