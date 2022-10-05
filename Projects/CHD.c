#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void info();
void declaration();
void menu();

int main() {

    int num_response, num_response2;
    char response, response2, response3;

    printf("\n*************************************************\n");
    printf("Welcome to the CoVid-19 Health Declaration Form.\n");
    printf("*************************************************\n");
    printf("\nThis program is going to get your personal details\n");
    printf("and your health status relating to CoVid-19 protocols.\n");

    do {
    printf("\nPress '1' to start || Press '0' to exit\n");
    scanf("%d", &num_response);
        if (num_response != 1 && num_response != 0) {
            printf("\n!! Invalid action. Please try again. !!\n");
        }
    } while (num_response != 1 && num_response != 0);

    if (num_response == 0) {
        printf("\n============= You have now exited. ==============");
        exit(1);
    } 

    info();
 
    do {
    printf("\nWould you like to proceed? Press 'Y' for 'yes' and 'N' for 'no': ");
    scanf("%c");
    scanf("%c", &response);
    response = toupper(response);
        if (response == 'N') {
        printf("Do you want to go back to re-do the personal information form? ");
        scanf("%c");
        scanf("%c", &response2);
        response2 = toupper(response2);
        if (response2 == 'Y') {
            info();
        } else if (response2 == 'N') {
            printf("Do you want to go back to the main menu?\n\n");
            printf("Press '1' to main menu || Press '0' to exit\n");
            scanf("%d", &num_response2);
            if (num_response2 == 0) {
            printf("\n============= You have now exited. ==============");
            exit(1);
            } else if (num_response2 = 1) {
                main();
            }
          }
    }
    } while (response == 'N');

    printf("\nYou may now proceed answering the health declaration form.\n");

    declaration();

    do {
    printf("\nDo you want to submit your health declaration form now? (Y/N): ");
    scanf("%c");
    scanf("%c", &response3);
    response3 = toupper(response3);
    } while (response3 == 'N');

    printf("\n\n=================== Thank You! ===================\n\n");

    menu();

return 0;
}

void info() {

    char name[100];
    char address[100];
    char email[100];
    char temp;
    int age;
    int cell;

    printf("\n========== Input your personal details ==========\n\n");

    printf("Name: ");
    scanf("%c");
    fgets(name, 100, stdin);
    name[strlen(name)-1] = '\0';

    printf("Age: ");
    scanf("%d", &age);

    printf("Address: ");
    scanf("%c", &temp);
    fgets(address, 100, stdin);
    address[strlen(address)-1] = '\0';

    /*printf("Cellphone number: ");
    scanf("%d", &cell);*/

    printf("Email address: ");
    scanf("%s", &email);

    
    printf("\n========= Review your personal details =========\n\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Address: %s\n", address);
    //printf("Cellphone number: %011d\n", cell);
    printf("Email address: %s\n", email);

}

void declaration() {

    char questions[][500] = {"1. Do you have a sore throat?:",
                             "2. Do you have a fever?:",
                             "3. Do you have a cough?:",
                             "4. Do you have a runny nose?:",
                             "5. Do you have loss of sense in smell?:",
                             "6. Do you have loss of sense in taste?:",
                             "7. Do you have an abdominal pain?:",
                             "8. Do you have diarrhea?:",
                             "9. Do you have any travel history within 14 days?:",
                             "10. Have you had contact with a probable or confirmed case within 14 days?:"};

    char options[][100]   = {"Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No",
                             "Yes", "No"};
    
    char followUp[]      = {'Y'};

    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
    char responseForm;
    //char travelResponse[100];

    printf("\n\n***************************************************************************");
    printf("\nThis is a Covid-19 Health Declaration Form; answer the following truthfully.");
    printf("\n***************************************************************************\n");

    for (int i = 0; i < numberOfQuestions; i++) 
    {
        printf("\n%s\n", questions[i]);

        for (int j = (i * 2); j < (i * 2) + 2; j++) 
        {
            printf("%s\n", options[j]);
        }

        printf("Response (Y/N): ");
        scanf("%c", &responseForm);
        scanf("%c");

        responseForm = toupper(responseForm);

    }
        /*if(responseForm == followUp[i+11]) 
        {
            printf("Where did you travel?:");
            fgets(travelResponse, 100, stdin);
            travelResponse[strlen(travelResponse)-1] = '\0';
        }*/

}

void menu() {

    int responseMenu;

    do {
    printf("\nPress '1' to restart || Press '0' to exit\n");
    scanf("%d", &responseMenu);
        if (responseMenu != 1 && responseMenu != 0) {
            printf("\n!! Invalid action. Please try again. !!\n");
        }
    } while (responseMenu != 1 && responseMenu != 0);

    if (responseMenu == 0) {
        printf("\n============= You have now exited. ==============");
        exit(1);
    } else if (responseMenu == 1) {   
        main();
    }
    
}
