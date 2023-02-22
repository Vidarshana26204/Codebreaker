#include <stdio.h>

#define Max_Attempts 12
char *Sectret_CODE = NULL;

int main(int argc,char **argv)
{
    printf("Available Colors: (B)lue (G)reen (O)range (P)urple (R)ed (Y)ellow\n\n");

    //Make sure there are only 2 cmd-l arguments
    if(argc != 2)
    {
        printf("ICheck usage: ./codebreaker GUESS \n");
        return 1;
    }
    
    Sectret_CODE = argv[1]; 

    //Prompting user for guesses untill hits the max attempt conunt
    int i = Max_Attempts;
    int Won = 0;
    while (i > 0 && !Won)
    {
        int b = 0, w = 0, t=0;
        char guess[5]; 
        char Sectret_CODE2[5];
        char guess2[5];
        printf("No. guesses left: %i\n",i);
        printf("Enter Your Guess: ");
        scanf("%s",guess);

        //Checking for no.of correct colors in correct positions(b).
        for(int j = 0; j < 4; j++)
        {
            if(Sectret_CODE[j] == guess[j])
            {
               b++; 
            }
            else
            {   //Storing unmatched colors in another array
                Sectret_CODE2[t] = Sectret_CODE[j];
                guess2[t] = guess[j];
                t++;
            }

        } 
        //Null terminating the arrays.
        Sectret_CODE2[t] = '\0' ;
        guess2[t] = '\0' ;
        
        if(b == 4)
        {
            printf("YOU WIN!\n");
            Won = 1;
            return 0;
        }  
        else
        {   
            //Checking for no.of mismatched positions of correct colors(w).
            for(int j = 0; j < t; j++)
            {
                for(int k = 0; k < t;k++)
                if(Sectret_CODE2[j] == guess2[k])
                {
                    w++;
                    break;
                }
            }
        }
        printf("Feedback: %i,%i\n\n",b,w);
        i--;
    }

    if(!Won)
    {
        printf("You Lose!\n");
        return 0;
    }
}

