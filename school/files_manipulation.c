// https://www.programiz.com/c-programming/c-file-input-output

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
   int num;
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("C:\\program.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);

   return 0;
}
