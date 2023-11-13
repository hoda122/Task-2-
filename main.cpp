#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<stdbool.h>
#include <ctype.h>

typedef struct {
    char username[50];
    char password[50];

    union userStatus{
        int active;
        bool isActive;
    }status;

} User;



User users[100];
int numUsers = 2;

bool parseBooleanInput(const char* input) {
    if (strcmp(input, "true") == 0 || strcmp(input, "1") == 0) {
        return true;
    } else if (strcmp(input, "false") == 0 || strcmp(input, "0") == 0) {
        return false;
    } else {
        return false;
    }
}



void registers() {
    User regUser;

    printf("Enter userName : ");
    scanf("%s", regUser.username);

    printf("Enter password : ");
    scanf("%s", regUser.password);

    char input[10];
    printf("Enter status ( 1 for active,0 for inactive): ");
    scanf("%s", input);

    regUser.status.isActive = parseBooleanInput(input);
    users[numUsers] = regUser;
    numUsers++;

    printf("Thank You For Registration \n");

}

int login() {
    char username[50];
    char password[50];

    strcpy(users[0].username,"Hoda");
    strcpy(users[0].password,"123");
    users[0].status.active = 1;

    strcpy(users[1].username,"Salama");
    strcpy(users[1].password,"456");
    users[1].status.isActive = false;

    printf("Enter userName : ");
    scanf("%s", username);

    printf("Enter password : ");
    scanf("%s", password);


    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
                if(users[i].status.active == 1 || users[i].status.isActive == true ){
                    printf("Thank You For Login \n");
                    return 1;
                }else{
                    printf("Sorry You Are Not Active \n");
                    return 0;
                }
        }
    }

    printf("Invalid userName or password \n");
    return 0;
}

int main() {
    char answer;

    while ("y") {
        printf("Do you have an email? (y/n)\n");
        printf("To exit (e)\n");
        printf("Enter your answer : ");
        scanf("%s", &answer);

        switch (answer) {
            case 'n':
                registers();
                printf("\t \t \t \t \t \n \n");
                break;
            case 'y':
                login();
                printf("\t \t \t \t \t \n \n");
                break;
            case 'e':
                printf("Exit successful\n");
                return 0;
            default:
                printf("Invalid answer.\n");
        }
    }

    return 0;
}
