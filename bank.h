#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account{
    int balance;
    char *name;
    int id;
    char *password;
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
    struct Account account;                     //create account struct
    account.name = name;
    account.password = password;

    for(int i=0; i<30; i++){

        if(bank->account[i].name == name){      //check if name exists
            printf("\e[1;1H\e[2J");
            printf("User already Exists!");
            break;
        }

        else if(bank->account[i].id==0){    //check if index is not taken
            account.id = i;
            account.balance = 0;
            bank->account[i] = account;
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
            logged->name=name;
            logged->id=i;
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
    char *old_amount;
    
    scanf("%19s %19s", name, old_amount);
    int amount = atoi(old_amount);
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
            bank->account[logged->id].balance=bank->account[logged->id].balance-amount;
            bank->account[i].balance=bank->account[i].balance+amount;
            printf("you gave %s %d of money",bank->account[i].name,amount);
            return;
        }

    }
    printf("\e[1;1H\e[2J");
    printf("\n your friend doesn't exist!");
    
}

void deposit(struct Account account,int deposit){
    
}