// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Za Energoto
// Avtor: 
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef
enum boolean_e
{
    false = 0, true
} boolean;

// elektroured
typedef
struct electroured_t
{
    float consumacia;
    boolean raboti;
} *electroured_p;

// apartament
typedef
struct apartament_t
{
    struct electroured_t elektrouredi[10];
    int razmer;
} *apartament_p;

// izchislqva konsumaciqta
float calc_current_consumption(apartament_p apartament)
{
    if (apartament != NULL)
    {
        for (apartament->razmer) 
        {
            if (raboti) 
            {
                obshta_konsumaciq = obshta_konsumaciq + konsumaciq;
            }
        }
    }
}

int main()
{
    
    return 0;
}
