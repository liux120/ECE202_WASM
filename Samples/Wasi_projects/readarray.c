#include <stdio.h>
#include <wasi/core.h>
int main()
{

    FILE *myFile;
    myFile = fopen("array.txt", "r");

    //read file into array
    int numberArray[16];
    int i;

    for (i = 0; i < 16; i++)
    {
        fscanf(myFile, "%d", &numberArray[i]);
    }

    for (i = 0; i < 16; i++)
    {
        printf("Number is: %d\n\n", numberArray[i]);
    }


}

//https://stackoverflow.com/questions/15091284/read-comma-separated-input-with-scanf
