#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char fname[] = {"questions.dat"};

struct question_t
{
    char question[300];
    char a[50];
    char b[50];
    char c[50];
    char d[50];
    unsigned int answer;
    unsigned int difficulty;
};

struct jokeri_t
{
    unsigned int fifty_fifty;
    unsigned int telephone;
    unsigned int ask_public;
};


int size_of_file()
{
    FILE *fp;
    int size = 0;
    struct question_t q;

    fp = fopen(fname, "rb");
    while (1)
    {
        fread(&q, sizeof(q), 1, fp);
        size++;
        if (feof(fp))
            break;
    };
    fclose(fp);

    return size - 1;
}

struct question_t rquestion_f()
{
    FILE *fp;
    fp = fopen(fname, "rb");
    struct question_t q;
    int sizef = size_of_file();
    int rng = rand() % sizef;

    int j;
    for (j = 0; j <= rng; j++)
    {
        fread(&q, sizeof(q), 1, fp);
    };
    return q;
}

void add_to_arr(struct question_t **arr, struct question_t q, int *size)
{
    *size += 1;
    *arr = (struct question_t *)realloc(*arr, (*size) * sizeof(struct question_t));
    (*arr)[*size - 1] = q;
}

int exists(struct question_t *arr, struct question_t q, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(arr[i].question, q.question))
            return 1;
    }
    return 0;
}

//saving random 10 questions
struct question_t *sv_10q()
{
    FILE *fp;
    struct question_t *arr = (struct question_t *)malloc(sizeof(struct question_t));
    int size = 0;
    fp = fopen(fname, "rb");

    for (int i = 0; i < 10;)
    {
        struct question_t rq = rquestion_f();
        if (exists(arr, rq, size))
            continue;
        if (i < 3)
        {
            if (rq.difficulty == 0)
            {
                add_to_arr(&arr, rq, &size);
                i++;
            };
        };
        if (i >= 3 && i <= 5)
        {
            if (rq.difficulty == 1)
            {
                add_to_arr(&arr, rq, &size);
                i++;
            };
        };
        if (i >= 6 && i <= 9)
        {
            if (rq.difficulty == 2)
            {
                add_to_arr(&arr, rq, &size);
                i++;
            };
        };
    };
    fclose(fp);
    return arr;
}

void display_all()
{
    FILE *fp;
    struct question_t q;
    int i = 1;
    fp = fopen(fname, "rb");

    printf("\n========================================================\n\n");
    printf("\t\t All question details\n\n");
    printf("========================================================\n\n");

    while (1)
    {
        fread(&q, sizeof(q), 1, fp);

        if (feof(fp))
        {
            break;
        }
        printf("[---Question %d---]\n", i);
        printf("%s\n", q.question);
        printf("1. %s\n", q.a);
        printf("2. %s\n", q.b);
        printf("3. %s\n", q.c);
        printf("4. %s\n\n", q.d);
        i++;
    }
    printf("========================================================\n\n");
    fclose(fp);
}

void append_ui()
{
    FILE *fp;
    struct question_t q;

    fp = fopen(fname, "ab");

    printf("\nEnter question:");
    fgets(q.question, sizeof(q.question), stdin);
    q.question[strlen(q.question) - 1] = '\0';

    printf("\nEnter answer a:");
    fgets(q.a, sizeof(q.a), stdin);
    q.a[strlen(q.a) - 1] = '\0';

    printf("\nEnter answer b:");
    fgets(q.b, sizeof(q.b), stdin);
    q.b[strlen(q.b) - 1] = '\0';

    printf("\nEnter answer c:");
    fgets(q.c, sizeof(q.c), stdin);
    q.c[strlen(q.c) - 1] = '\0';

    printf("\nEnter answer d:");
    fgets(q.d, sizeof(q.d), stdin);
    q.d[strlen(q.d) - 1] = '\0';

    printf("\nEnter correct answer (1-4):");
    scanf("%u", &q.answer);
    // todo: if diff != (1-3)
    printf("\nEnter difficulty (0-2):");
    scanf("%u", &q.difficulty);

    fwrite(&q, sizeof(q), 1, fp);
    fclose(fp);
    printf("\n\n");
}

void append(struct question_t *questions, int size)
{
    FILE *fp;

    fp = fopen(fname, "wb");
    for (int i = 0; i < size; i++)
    {
        fwrite(&questions[i], sizeof(questions[i]), 1, fp);
    }

    fclose(fp);
}

//-------------------------------------------------------------
/*void edit_q(){ 
	Logika:
		1. printirame vsichki vuprosi vuv originalniq fail;
		2. otvarqme temp faila i pishem v nego vsichki vurposi do tozi, koito potrebitelqt
		e izbral da editne (kato v sushtoto vreme chetem ot originalniq fail). 
		NB!!! ako nqma takuv vpos printirame error;
		3. kogato stignem to tozi koito trqbva da se editne, pitame potrebitelq za nov vupros
	    i go zapametqvame vuv temp faila na mqstoto na nomera na vuprosa koit potrebitelq e izbral. 
		4. prehvurlqme vsichko ot temp faila v original faila 
		
		nakraq trqbva da zatvorim failovete
	
}*/

// namira nai-malkoto chislo koeto ne nadvishava argumenta
int find_ceil(int arr[], int r, int l, int h)
{
    int mid;
    while (l < h)
    {
        mid = l + ((h - l) >> 1); // Same as mid = (l+h)/2
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);
    }
    return (arr[l] >= r) ? l : -1;
}

//
//
int rand_prob(int arr[], int freq[], int n)
{
    // Create and fill prefix array
    int prefix[n], i;
    prefix[0] = freq[0];
    for (i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + freq[i];

    // prefix[n-1] is sum of all frequencies. Generate a random number
    // with value from 1 to this sum
    int r = (rand() % prefix[n - 1]) + 1;

    // Find index of ceiling of r in prefix arrat
    int indexc = find_ceil(prefix, r, 0, n - 1);
    return arr[indexc];
}

void start_game()
{
    struct question_t *questions = sv_10q(); //size=10
    int round = 1;
    int ans;
    struct jokeri_t jokeri = {0, 0, 0};
    int answers[5] = {0};
    for (int i = 0; i < 10; i++, round++)
    {
        while(1)
        {
            printf("[---Question for round %d---]\n", round);
            printf("%s\n", questions[i].question);

            if (answers[1]== 0)
            {
                printf("1. %s\n", questions[i].a);
            }
            if (answers[2] == 0)
            {
                printf("2. %s\n", questions[i].b);
            }
            if (answers[3] == 0)
            {
                printf("3. %s\n", questions[i].c);
            }
            if (answers[4] == 0)
            {
                printf("4. %s\n", questions[i].d);
            }

            printf("--- === jokers ===---\n");

            if (jokeri.fifty_fifty == 0)
            {
                printf("5. joker - 50/50\n");
            }
            if (jokeri.telephone == 0)
            {
                printf("6. joker - telefon\n");
            }
            if (jokeri.ask_public == 0)
            {
                printf("7. joker - pitai publica\n");
            }

            printf("\nEnter the correct answer: ");
            scanf("%d", &ans);
            if (ans == 5)
            {
                //izpolzvame 50/50 joker
                for(int k = 0; k < 2; k++)
                {
                    int h = rand()%4+1;
                    while(h == questions[i].answer || answers[h] == 1)
                    {
                        h = rand()%4+1;
                    }
                    answers[h] = 1;
                }    
                jokeri.fifty_fifty = 1;
            }
            if (ans == 6)
            {
                //izpolzvame telephone joker
                jokeri.telephone = 1;
                int answers[4] = {1,2,3,4};
                int freqs[4] = {1,1,1,1};
                switch (questions[i].difficulty)
                {
                    case 0:
                        freqs[0] = freqs[1] = freqs[2] = freqs[3] = 1;
                        freqs[questions[i].answer-1] = 8;
                        break;
                    case 1:
                        freqs[0] = freqs[1] = freqs[2] = freqs[3] = 2;
                        freqs[questions[i].answer-1] = 6;
                        break;
                    case 2:
                        freqs[0] = freqs[1] = freqs[2] = freqs[3] = 3;
                        freqs[questions[i].answer-1] = 3;
                        break;
                }
                int hint = rand_prob(answers, freqs, 4);
                printf("\nTelephone hint is %d\n\n", hint);
            }
            if (ans == 7)
            {
                //izpolzvame pitai publikata joker
                jokeri.ask_public = 1;
            }

            if(ans > 0 && ans < 5)
            {
                if (ans != questions[i].answer)
                {
                    printf("\nYou lost the game.\nYou played for [%d] rounds\n", round);
                    printf("\n\n");
                    return;
                }
                break;
            }
        }
    }
    printf("Congratulations! You won!\n\n");
}

int main()
{
    srand(time(0));
    struct question_t questions[] = {
        {"A person with well-developed abdominal muscles is said to have a what?", "One-pack", "Six pack", "12-pack", "Family-pack", 2, 0},
        {"What sort of animal is Walt Disney's Dumbo?", "Elephant", "Deer", "Donkey", "Lion", 1, 1},
        {"Compiled by Benjamin Franklin in 1737, The Drinker's Dictionary  included all but which of these synonyms for drunkenness?", "Nimptopsical", "Buzzey", "Staggerish", "Pifflicated", 4, 2},
        {" What do egals usually eat?", "Fruit", "Meat", "Worms", "Leaves", 3, 1},
        {"In the children’s book series, where is Paddington Bear originally from?", " Iceland", "Peru", "India", "Canada", 2, 2},
        {"What animal is the tallest?", "Giraff", "Lion", " Horse", "Cat", 1, 0},
        {"What letter must appear on the beginning of the registration number of all non-military aircraft in the US?", "A", "U", "L", "N", 4, 2},
        {"What first lady was a ninth-generation descendant of Pocahontas?", "Edith Wilson", "Helen Taft", "Bess Truman", "Mamie Eisenhower", 1, 1},
        {"The US icon Uncle Sam was based on Samuel Wilson who worked during the War of 1812 as a what?", "Mail deliverer", "Meat inspector", "Historian", "Weapons mechani", 2, 2},
        {"Khrushchev's famous 1960 shoe-banging outburst at the UN was in response to a delegate from what nation?", "Austria", "The Philippines", "Turkey", "Spain", 3, 2},
        {"Where did Scotch whisky originate?", "Belgium", "Spain", "Ireland", "Wales", 3, 0},
        {"When was Henry VIII born?", " 28th June 1491", "4th July 1478", "6th January 1490", "12th February 1468", 2, 1},
        {"The song God Bless America was originally written for what 1918 musical?", "Oh Lady! Lady!!", "Watch Your Step", "Blossom Time", "Yip, Yip, Yaphank", 4, 2},
        {"Nadia Comaneci was the first gymnast to ever do what at the Olympics?", "Get a perfect 10", "Win an Olympic gold medal", "Win an Olympic gold medal", "Forfeit her position", 2, 1},
        {"Which of these birds has the biggest brain relative to its size?", "Hummingbird", "EagleSparrow", "Ostrich", "Eagle", 1, 1},
        {"A person who is not a banker and lends money at an extremely high interest rate is known as what?", "Brother-in-law", "Paper tiger", "Green snake", "Loan Shark", 4, 0},
        {"What name is traditionally given to the party held for a woman who is expecting a baby?", "Baby downpour", "Baby deluge", "Baby shower", "Baby drizzle", 3, 0},
        {"Now used to refer to a cat, the word tabby is derived from the name of a district of what world capital?", "Cairo", "New Delhi", "Baghdad", "Moscow", 3, 2},
        {" The national flag of which of these countries does not feature three horizontal stripes?", "Russia", "Meat", "Romania", " Bulgaria", 3, 1},
        {" The popular children's song It's Raining, It's Pouring mentions an old man  doing what?", "Yelling at squirrels", "Laughing", "Snoring", "Cooking", 1, 0},

    };
    append(questions, sizeof(questions) / sizeof(questions[0]));
    //display_all();

    while (1)
    {
        int o;
        printf("1. Start game\n");
        printf("2. Add a question\n");
        printf("3. Display all available questions\n");
        //printf("4. Edit an existing question\n");
        printf("0. Exit\n\n");
        printf("Select option: ");
        scanf("%d", &o);
        getchar();
        printf("\n");
        switch (o)
        {
        case 1:
            start_game();
            break;

        case 2:
            append_ui();
            break;

        case 3:
            display_all();
            break;

            // case 4: edit_q();
            // break;

        case 0:
            exit(0);
            break;
        }
    }
}
