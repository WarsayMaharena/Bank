#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account{
    int balance;
    char name[20];
    int id;
    char password[20];
};

struct Bank{
   struct Account account[30];
};

void create_account(struct Bank *bank){
    printf("\e[1;1H\e[2J");
    printf("Welcome to the banks register page!\n\n Register an account by typing \"name password\", or just type \"quit 0\"\n\nEnter Argument: ");

    char name[20], password[20];
    scanf("%19s %19s", name, password);

    
    if(!strcmp(name,"quit")||!strcmp(name,"Quit")){ //see if user wants to quit
        printf("\e[1;1H\e[2J");
        printf("Quit!");
        return;
    }

    for(int i=0; i<30; i++){

        if(!strcmp(bank->account[i].name, name)){      //check if name exists
            printf("\e[1;1H\e[2J");
            printf("User already Exists!");
            break;
        }

        else if(bank->account[i].id==0){    //check if index is not taken
            bank->account[i].id=i+1;
            bank->account[i].balance=0;
            strcpy(bank->account[i].name,name);
            strcpy(bank->account[i].password,password);
             
            printf("\e[1;1H\e[2J");
            printf("Welcome: %s!", name);
            break;
        }

        else if(i==29){                     //check if slot empty in bank
            printf("\e[1;1H\e[2J");
            printf("The bank is full!");
        }
    }
    
    
}

void log_into_account(struct Bank *bank, struct Account *logged){
    printf("\e[1;1H\e[2J");
    printf("Welcome to the banks login page!\n\n log into an account by typing \"name password\", or just type \"quit 0\"\n\nEnter Argument: ");
    char name[20], password[20];
    scanf("%19s %19s", name, password);
    if(!strcmp(name,"quit")||!strcmp(name,"Quit")){ //see if user wants to quit
        printf("\e[1;1H\e[2J");
        printf("Quit!");
        return;
    }

    printf("%s\n",bank->account[0].name);
    for(int i = 0; i<30; i++){
        if(strcmp(bank->account[i].name, name) == 0 && strcmp(bank->account[i].password, password) == 0){
            printf("\e[1;1H\e[2J");
            printf("You have logged in!");
            strcpy(logged->name,name);
            logged->id=i+1;
            logged->balance=bank->account[i].balance;
            return;

        }
    }
    printf("\e[1;1H\e[2J");
    printf("wrong name or password");

}

void give_money(struct Bank *bank, struct Account *logged){
    printf("\e[1;1H\e[2J");
    printf("Who do you want to give your money to?\n\n give monet by typing the amount and name \"amount name\", or just type \"quit 0\"\n\nEnter Argument: ");
    char name[20];
    int amount;

    scanf("%19s %d",name, &amount);
    if(!strcmp(name,"quit")||!strcmp(name,"Quit")){ //see if user wants to quit
        printf("\e[1;1H\e[2J");
        printf("Quit!");
        return;
    }

    for(int i = 0; i<30; i++){
        if(logged->balance<amount){
            printf("\e[1;1H\e[2J");
            printf("you don't have enough money!");
            return;
        }
        else if(!strcmp(bank->account[i].name, name)){
            printf("\e[1;1H\e[2J");
            logged->balance=logged->balance-amount;
            bank->account[logged->id-1].balance=bank->account[logged->id-1].balance-amount;
            bank->account[i].balance=bank->account[i].balance+amount;
            printf("you gave %s %d of money",bank->account[i].name,amount);
            return;
        }

    }
    printf("\e[1;1H\e[2J");
    printf("\n your friend doesn't exist!");
    
}

void deposit(struct Bank *bank, struct Account *logged) {
    printf("\e[1;1H\e[2J");
    printf("How much money do you want to deposit?\n\n set an amount by typing the amount \"deposit {amount}\", or just type \"quit 0\"\n\nEnter Argument: ");
    char name[20];
    int amount;

    scanf("%19s %d",name, &amount);
    if(!strcmp(name,"quit")||!strcmp(name,"Quit")){ //see if user wants to quit
        printf("\e[1;1H\e[2J");
        printf("Quit!");
        return;
    }

    for(int i = 0; i<30; i++){
        if(!strcmp(bank->account[i].name, logged->name)){
            printf("\e[1;1H\e[2J");
            logged->balance=logged->balance+amount;
            bank->account[logged->id-1].balance=bank->account[logged->id-1].balance+amount;
            printf("you deposited %d of money, %s",amount, logged->name);
            return;
        }

    }
    printf("\e[1;1H\e[2J");
    printf("\n your friend doesn't exist!");
    

}

void draw(struct Bank *bank, struct Account *logged) {
    printf("\e[1;1H\e[2J");
    printf("How much money do you want to draw?\n\n set an amount by typing the amount \"draw {amount}\", or just type \"quit 0\"\n\nEnter Argument: ");
    char name[20];
    int amount;

    scanf("%19s %d",name, &amount);
    
    if(!strcmp(name,"quit")||!strcmp(name,"Quit")){ //see if user wants to quit
        printf("\e[1;1H\e[2J");
        printf("Quit!");
        return;
    }

    for(int i = 0; i<30; i++){
        if(logged->balance<amount){
            printf("\e[1;1H\e[2J");
            printf("you don't have enough money!");
            return;
        }
        else if(!strcmp(bank->account[i].name, logged->name)){
            printf("\e[1;1H\e[2J");
            logged->balance=logged->balance-amount;
            bank->account[logged->id-1].balance=bank->account[logged->id-1].balance-amount;
            printf("you have drawn %d of money, %s",amount, logged->name);
            return;
        }

    }
    printf("\e[1;1H\e[2J");
    printf("\n your friend doesn't exist!");
    

}