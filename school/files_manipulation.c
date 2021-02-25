// https://www.programiz.com/c-programming/c-file-input-output

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
   // int num;
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("data.txt","r");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   // printf("Enter num: ");
   // scanf("%d",&num);

   // fprintf(fptr,"%d",num);

   int c;
   char line[1024] = {0};

   c = fscanf(fptr, "%s", line);
   printf("c = %d\n", c);

   if (c > 0)
   {
      printf("line: %s\n", line);
   }


   fclose(fptr);

   return 0;
}
