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

    float obshta_konsumacia = 0;

    if (apartament != NULL)
    {
        for (int i = 0; i < apartament->razmer; i++) 
        {
            if (apartament->elektrouredi[i].raboti) 
            {
                obshta_konsumacia = obshta_konsumacia + apartament->elektrouredi[i].consumacia;
            }
        }
    }

    return obshta_konsumacia;
}

int main()
{
    struct apartament_t apartament;
    apartament.razmer = 5;
    apartament.elektrouredi[0].raboti = true;
    apartament.elektrouredi[0].consumacia = 0.5;
    apartament.elektrouredi[1].raboti = true;
    apartament.elektrouredi[1].consumacia = 0.7;
    apartament.elektrouredi[2].raboti = false;
    apartament.elektrouredi[2].consumacia = 1.2;
    apartament.elektrouredi[3].raboti = true;
    apartament.elektrouredi[3].consumacia = 0.5;
    apartament.elektrouredi[4].raboti = true;
    apartament.elektrouredi[4].consumacia = 0.1;

    float cons = calc_current_consumption(&apartament);

    printf("\nobshta consumacia: %.2f\n", cons);

    return 0;
}
