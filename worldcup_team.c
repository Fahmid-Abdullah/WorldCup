/**
 * Name: Fahmid Abdullah
 * Student Number: 251244838
 * Assignment: worldcup_team
 * Description: User continously chooses between adding a team, editing a team, searching for a team, printing a team, deleting a team, and quitting.
 * Date Created: November 25, 2022
*/


// Maintains a teams database
#include "worldcup_team.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// team struct
struct team
{   /* data stores in the team */
    int code;
    char name[TEAM_NAME];
    char seeding[SEEDING_LEN];
    char colour[COLOUR_LEN];
    struct team *next; // pointer to the next team
};

struct team *num_teams = NULL; // pointer to first team

struct team *findTeamCode(int code) { // Looks up team code in team array. Returns the team index if the team code is found
    struct team *t;
    for (t = num_teams; t != NULL && code > t->code; t = t->next);
        if (t != NULL && code == t->code) 
            return t;


    return NULL;
}

struct team *findTeamName(char name[]) { // Looks up team name in team array. Returns the team index if the team name is found
    struct team *t;
    for (t = num_teams; t != NULL; t = t->next);
        if (t != NULL && strcmp(t->name, name) == 0)
            return t;
        

    return NULL;
}

struct team *findTeamSeeding(char seeding[]) { // Looks up team seeding in team array. Returns the team index if the team name is found
    struct team *t;
    for (t = num_teams; t != NULL; t = t->next);
        if (t != NULL && strcmp(t->seeding, seeding) == 0) 
            return t;

    return NULL;
}

int validSeed(char seed[]) { // Checks if the seeding entered follows the required format
    char vLetters[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    char vNum[5] = {'1', '2', '3', '4'};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            if (seed[0] == vLetters[i]) {
                if (seed[1] == vNum[j]) {
                    return 1;
                }
            }
        }
    
    } return 0;
}

int validKit(char *colour) { // Checks if the colour kit format entered follows the required format 
    char vColours[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    
    for (int i = 0; i < 8; i++) {
        if (colour[0] == vColours[i]) {
            return 1;
        }
    } return 0;
}

int newTeam() { // Prompts the user for information about a new team, and then inserts the team in the database
    char lastName[TEAM_NAME/2];
    char tName[TEAM_NAME];
    char tSeeding[SEEDING_LEN];
    char tColour[2];
    char fullC[COLOUR_LEN];

    /* cur points to current team, prev points to previous team, new_team points to team being added */
    struct team *cur, *prev, *new_team;
    new_team = malloc(sizeof(struct team));

    if (new_team == NULL) { // Returns if database is full
        printf("\tDatabase is full; Can't add more teams.\n");
        return 0;
    }
    printf("\tEnter team code: ");
    scanf(" %d", &new_team->code);

    if (new_team->code < 0) { // Returns if code is not valid
        printf("\tInvalid Team Code.\n");
        return 0;
    }

    // Searches the database for the current team and clears the space and returns if found 
    for (cur = num_teams, prev = NULL; cur != NULL && new_team->code > cur->code; prev = cur, cur = cur->next);
        if (cur != NULL && new_team->code == cur->code) {
            printf("Team already exists.\n");
            free(new_team);
            return 0;
        }

    printf("\tEnter Team Name: "); // Asks user for team name
    scanf(" %s", &tName);
    tName[25] = '\0';
    if (findTeamName(tName) == NULL) 
        strcpy(new_team->name, tName);
    else {
        printf("Team Name exists.\n");
        return 0;
    }

    printf("\tEnter group seeding: "); // Asks user for group seeding
    scanf(" %s", &tSeeding);
    while (1) {
        tSeeding[3] = '\0';
        if (validSeed(tSeeding) == 1) {
            if (findTeamSeeding(tSeeding) != NULL) {
                printf("\tTeam Seeding already exists.\n");
                return 0;
            }
            strcpy(new_team->seeding, tSeeding);
            break;
        }
        printf("\tInvalid Group Seeding\n");
        printf("\tEnter Group Seeding: ");
        scanf(" %s", &tSeeding);
    }

    printf("\tEnter the kit colour: "); // Asks user for kit colour
    scanf(" %s", &tColour);
    tColour[2] = '\0';
    while (1) {
        if (validKit(tColour) == 1) {
            switch (tColour[0]) {
                case ('R'):
                    strcpy(new_team->colour, "Red");
                    break;
                case ('O'):
                    strcpy(new_team->colour, "Orange");
                    break;
                case ('Y'):
                    strcpy(new_team->colour, "Yellow");
                    break;
                case ('G'):
                    strcpy(new_team->colour, "Green");
                    break;
                case ('B'):
                    strcpy(new_team->colour, "Blue");
                    break;
                case ('I'):
                    strcpy(new_team->colour, "Indigo");
                    break;
                case ('V'):
                    strcpy(new_team->colour, "Violet");
                    break;
            } 
            break;
        }
        printf("\tInvalid Kit Colour\n");
        printf("\tEnter the kit colour: ");
        scanf(" %s", &tColour);
    }

    /* Adds the new_team node to the database*/
    new_team->next = cur;
    if (prev == NULL)
        num_teams = new_team;
    else
        prev->next = new_team;
}

void searchTeam(void) { // Prompts the user to enter a team code, then looks up the team in the database. If the team exists, prints the code, name, seeding, and colour
    int code;
    struct team *t;

    printf("\tEnter Team Code: ");
    scanf(" %d", &code);
    t = findTeamCode(code);
    if (t != NULL) {
        printf("Team Code\t\tTeam Name\t\t\t\tGroup Seeding\t\tPrimary Kit Colour\n");
        printf("%d\t\t\t%s\t\t\t\t\t%s\t\t\t%s\n", t->code, t->name, t->seeding, t->colour);
    } else {
        printf("Team not found\n");
    }
}

int updateTeam() { // Prompts the user to enter a team code, then looks up the team in the database. If the team exists, lets the user enter a replacement name, seeding, and colour
    struct team *t;
    int code;
    char tName[TEAM_NAME];
    char tSeeding[SEEDING_LEN];
    char tColour[2];
    char fullC[COLOUR_LEN];


    printf("\tEnter team code: ");
    scanf(" %d", &code);
    t = findTeamCode(code);
    if (t != NULL) {
        printf("\tEnter Team Name: ");
        scanf(" %s", &tName);
        tName[25] = '\0';
        if (findTeamName(tName) == NULL) 
            strcpy(t->name, tName);
        else {
            printf("Team Name exists.\n");
            return 0;
        }

        printf("\tEnter group seeding: ");
        scanf(" %s", &tSeeding);
        while (1) {
            if (validSeed(tSeeding) == 1) {
                if (findTeamSeeding(tSeeding) != NULL) {
                    printf("\tTeam Seeding already exists.\n");
                    return 0;
                }
                strcpy(t->seeding, tSeeding);
                break;
            }
            printf("\tInvalid Group Seeding\n");
            printf("\tEnter Group Seeding: ");
            scanf(" %s", &tSeeding);
        }

        printf("\tEnter the kit colour: ");
        scanf(" %s", &tColour);
        tColour[2] = '\0';
        while (1) {
            if (validKit(tColour) == 1) {
                switch (tColour[0]) {
                    case ('R'):
                        strcpy(t->colour, "Red");
                        break;
                    case ('O'):
                        strcpy(t->colour, "Orange");
                        break;
                    case ('Y'):
                        strcpy(t->colour, "Yellow");
                        break;
                    case ('G'):
                        strcpy(t->colour, "Green");
                        break;
                    case ('B'):
                        strcpy(t->colour, "Blue");
                        break;
                    case ('I'):
                        strcpy(t->colour, "Indigo");
                        break;
                    case ('V'):
                        strcpy(t->colour, "Violet");
                        break;
                } 
                break;
            }
            printf("\tInvalid Kit Colour\n");
            printf("\tEnter the kit colour: ");
            scanf(" %s", &tColour);
        }

    }
}

int printTeam() { // Prints a listing of all teams in the database
    struct team *t;
    printf("Team Code\t\tTeam Name\t\t\t\tGroup Seeding\t\tPrimary Kit Colour\n");
    for (t = num_teams; t != NULL; t = t->next) {
        printf("%d\t\t\t%s\t\t\t\t\t%s\t\t\t%s\n", t->code, t->name, t->seeding, t->colour);
    }
}

void *deleteTeam(void) { // Deletes a team from the database
    int code;
    struct team *cur, *prev;


    printf("Enter Team Code: ");
    scanf(" %d", &code);

    /* Searches for the user code entered in the database, if found clears the space and thus removes the node from the database*/
    for (cur = num_teams, prev = NULL; cur != NULL && cur->code != code; prev = cur, cur = cur->next);
        if (cur == NULL)
            return num_teams;
        if (prev == NULL)
            num_teams = num_teams->next;
        else
            prev->next = cur->next;
        free(cur);
        return num_teams; 
    
}