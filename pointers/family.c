// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Pointers cheat sheet in C programming language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_JOHN "JOHN"
#define MAME_MERRY "MERRY"
#define NAME_PAUL "PAUL"
#define NAME_SUSAN "SUSAN"
#define NAME_JIM "JIM"
#define NAME_SARAH "SARAH"

// defines the direct relations in a family
typedef enum relation_e {
    PARENT, CHILD, SPOUSE, SIBLING
} relation_t;

// defines the human genders
typedef enum gender_e {
    MALE, FEMALE
} gender_t;

// pre-defines person structure
typedef struct person_s person_t;
// defines pointer to person
typedef person_t* person_p;

// defines relational structure between persons
typedef struct relative_s {
    person_p relative;
    relation_t rel_type;
} relative_t;
// defines pointer to relative
typedef relative_t *relative_p;

// defines person structure
struct person_s {
    const char *name;
    gender_t gender;
    int age;
    relative_p *relatives;
    int rel_size;
};

// defines emtpy array with persons
person_p *family;
const unsigned int fam_size = 6;

// creates new person
person_p new(const char *name, int age, gender_t gender) 
{
    // the new person
    person_p person = (person_p) malloc(sizeof(person_t));

    person->name = name;
    (*person).age = age;
    person->gender = gender;
    (*person).rel_size = 0;
    person->relatives = NULL;

    return person;
}

// delete person
void delete(person_p person) 
{
    if (person != NULL)
    {
        if (person->relatives != NULL)
        {
            free((*person).relatives);
        }
        free(person);
    }
}

// adds pers2 as relation to pers1 of type rel_type
void add_relation(person_p pers1, person_p pers2, relation_t rel_type)
{
    if (pers1 != NULL && pers2 != NULL)
    {
        relative_p* tmp = (relative_p*) malloc((pers1->rel_size + 1) * sizeof(relative_p));
        tmp[pers1->rel_size] = (relative_p) malloc(sizeof(relative_t));
        tmp[pers1->rel_size]->rel_type = rel_type;
        (*tmp[pers1->rel_size]).relative = pers2;
        if (pers1->rel_size > 0)
        {
            memcpy(tmp, pers1->relatives, pers1->rel_size * sizeof(relative_p));
            free(pers1->relatives);
        }
        pers1->relatives = tmp;
        pers1->rel_size++;
    }
}

// checks if a person has a known mother.
person_p mother_of(person_p person) 
{
    person_p mother = NULL;

    if (person != NULL) 
    {
        printf("\nchecking mother of %s\n", person->name);

        if (person->rel_size > 0)
        {
            for (int i = 0; i < person->rel_size; i++)
            {
                if (person->relatives[i]->rel_type == PARENT
                    && person->relatives[i]->relative->gender == FEMALE)
                {
                    mother = person->relatives[i]->relative;
                    break;
                }
            }
        }

    }

    if (mother == NULL) 
    {
        printf("\nmother: n/a\n");
    }
    else
    {
        printf("   ... is %s\n", mother->name);
    }
    
    return mother;
}

// checks if a person has a known father.
person_p father_of(person_p person) 
{
    person_p father = NULL;

    if (person != NULL) 
    {
        printf("\nchecking father of %s\n", person->name);

        for (int i = 0; i < person->rel_size; i++)
        {
            if (person->relatives[i]->rel_type == PARENT
                && person->relatives[i]->relative->gender == MALE)
            {
                father = person->relatives[i]->relative;
                break;
            }
        }

    }

    if (father == NULL) 
    {
        printf("\nfather: n/a\n");
    }
    else
    {
        printf("   ... is %s\n", father->name);
    }
    
    return father;
}

// MAIN ENTRY POINT
int main()
{
    family = (person_p*) malloc(fam_size * sizeof(person_p));

    family[0] = new(NAME_JOHN, 40, MALE);
    family[1] = new(MAME_MERRY, 38, FEMALE);
    family[2] = new(NAME_PAUL, 74, MALE);
    family[3] = new(NAME_SARAH, 69, FEMALE);
    family[4] = new(NAME_JIM, 14, MALE);
    family[5] = new(NAME_SUSAN, 9, FEMALE);

    add_relation(family[0], family[1], SPOUSE);
    add_relation(family[1], family[0], SPOUSE);
    add_relation(family[2], family[3], SPOUSE);
    add_relation(family[3], family[2], SPOUSE);

    add_relation(family[0], family[4], CHILD);
    add_relation(family[0], family[5], CHILD);
    add_relation(family[1], family[4], CHILD);
    add_relation(family[1], family[5], CHILD);

    add_relation(family[2], family[0], CHILD);
    add_relation(family[3], family[0], CHILD);

    add_relation(family[0], family[2], PARENT);
    add_relation(family[0], family[3], PARENT);

    add_relation(family[4], family[0], PARENT);
    add_relation(family[4], family[1], PARENT);
    add_relation(family[5], family[0], PARENT);
    add_relation(family[5], family[1], PARENT);

    add_relation(family[4], family[5], SIBLING);
    add_relation(family[5], family[4], SIBLING);

    mother_of(family[4]);
    mother_of(family[5]);
    mother_of(family[0]);
    mother_of(family[1]);
    father_of(family[5]);
    father_of(family[0]);
 
    for (int i = 0; i < fam_size; i++)
    {
        delete(family[i]);
    }
    free(family);

    return 0;
}
