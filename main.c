#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
#include <string.h>
int main (int argc, char *argv[]) {
    printf("\e[1;1H\e[2J");
    printf("\nWelcome!");
    struct Bank bank;
    for(int i = 0; i<30; i++){
        strcpy(bank.account[i].name,"");
        strcpy(bank.account[i].password,"");
        bank.account[i].id=0;
        bank.account[i].balance=0;
    }
    
    struct Account loggedacc;
    strcpy(loggedacc.name,"");
    //bank.account[0]=create_account("Warsay Maharena", "SPONYSTREET");
    while(1){
 

        char str1[20];
        
        printf("\n\nprint a number fr a certain action, your options are...\n\n");
        printf("1. Set a deposit\n");
        printf("2. Draw money\n");
        printf("3. Give money to another accountt\n");
        printf("4. Register an account\n");
        printf("5. log into an account\n");
        printf("5. log out of an account\n");
        printf("7. quit the application\n\n");
        printf("logged: %s\n",loggedacc.name);
        printf("Enter Argument: ");

        scanf("%19s", str1);
        printf("\e[1;1H\e[2J");
        printf("%d %d %d",strcmp("4",str1),strcmp("5",str1),strcmp(loggedacc.name,""));
        if(strcmp("4",str1) && strcmp("5",str1) && !strcmp(loggedacc.name,"")){
            printf("\nyou aren't logged in!");

        }

        else if(!strcmp("1",str1)){
            printf("\nyou have decided to set a deposit");
            deposit(&bank,&loggedacc);
            
        }

        else if(!strcmp("2",str1)){
            printf("\nyou have decided to draw money");
            draw(&bank,&loggedacc);
            
        }

        else if(!strcmp("3",str1)){
            printf("\nyou have decided to give money to another account");
            give_money(&bank,&loggedacc);
            
        }

        else if(!strcmp("4",str1)){
            printf("\nyou have decided to register an account");
            create_account(&bank);
            
        }

        else if(!strcmp("5",str1)){
            printf("\nyou have decided to log into an account");
            log_into_account(&bank, &loggedacc);
        }

        else if(!strcmp("6",str1)){
            printf("\nyou have decided to log out");
            strcpy(loggedacc.name,"");
        }

        else if(!strcmp("7",str1)){
            break;
        }

        else{
            printf("\nGive a valid command");
            
        }
    }


    return 0;
}