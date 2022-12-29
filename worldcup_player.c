/**
 * Name: Fahmid Abdullah
 * Student Number: 251244838
 * Assignment: worldcup_player
 * Description: User continously chooses between adding a player, editing a player, searching for a player, printing a player, deleting a player, and quitting.
 * Date Created: November 25, 2022
*/


// Maintains a player database
#include "worldcup_player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// player struct
struct player
{   /* data stores in the player */
    int code;
    char name[PLAYER_NAME];
    int age;
    char club[CLUB_LEN];
    struct player *next; // pointer to the next player
};

struct player *num_players = NULL; // pointer to first player

struct player *findPlayerCode(int code) { // Looks up player code in player array. Returns the player index if the player code is found
    struct player *p;
    for (p = num_players; p != NULL && code > p->code; p = p->next); 
        if (p != NULL && code == p->code) 
            return p;
        
    
    return NULL;
}


int newPlayer() { // Prompts the user for information about a new player, and then inserts the player in the database
    char lastName[PLAYER_NAME/2];
    char pName[PLAYER_NAME];
    int pAge;
    char lastClub[CLUB_LEN/2];
    char pClub[CLUB_LEN];

    /* cur points to current player, prev points to previous player, new_player points to player being added */
    struct player *cur, *prev, *new_player;
    new_player = malloc(sizeof(struct player));

    if (new_player == NULL) { // Returns if database is full
        printf("Database is full; Can't add more players.\n");
        return 0;
    }

    printf("\tEnter Player Code: ");
    scanf(" %d", &new_player->code);

    if (new_player->code < 0) { // Returns if code is not valid
        printf("\tInvalid Player Code.\n");
        return 0;
    }

    // Searches the database for the current player and clears the space and returns if found 
    for (cur = num_players, prev = NULL; cur != NULL && new_player->code > cur->code; prev = cur, cur = cur->next);
        if (cur != NULL && new_player->code == cur->code) {
            printf("Player already exists.\n");
            free(new_player);
            return 0;
        }

    printf("\tEnter Player Name: "); // Asks user for player name
    scanf("%s %s", &pName, &lastName);
    strcat(pName, " ");
    strcat(pName, lastName);
    pName[50] = '\0';
    strcpy(new_player->name, pName);

    printf("\tEnter Player Age: "); // Asks user for player age
    scanf(" %d", &pAge);
    
    if ((pAge < 17) || (pAge > 99)) {
        printf("\tInvalid Player Age.\n");
        return 0;
    } else {
        new_player->age = pAge;
    }

    printf("\tEnter Player Club Affiliation: "); // Asks user for player club affiliation
    scanf("%s %s", &pClub, &lastClub);
    strcat(pClub, " ");
    strcat(pClub, lastClub);
    pName[50] = '\0';
    strcpy(new_player->club, pClub);
    
    /* Adds the new_player node to the database*/
    new_player->next = cur;
    if (prev == NULL)
        num_players = new_player;
    else
        prev->next = new_player;
}

void searchPlayer(void) { // Prompts the user to enter a player code, then looks up the player in the database. If the player exists, prints the code, name, age, and club
    int code;
    struct player *p;

    printf("Enter Player Code: ");
    scanf(" %d", &code);
    p = findPlayerCode(code);
    if (p != NULL) {
        printf("Player Code\t\tPlayer Name\t\t\t\tAge\t\tClub\n");
        printf("%d\t\t\t%s\t\t\t\t%d\t\t%s\n", p->code, p->name, p->age, p->club);
    } else {
        printf("Player not found\n");
    }
}

int updatePlayer() { // Prompts the user to enter a player code, then looks up the player in the database. If the player exists, lets the user enter a replacement name, age, and colour
    struct player *p;
    int code;
    char lastName[PLAYER_NAME/2];
    char pName[PLAYER_NAME];
    int pAge;
    char lastClub[CLUB_LEN/2];
    char pClub[CLUB_LEN];

    printf("Enter Player Code: ");
    scanf(" %d", &code);
    p = findPlayerCode(code);
    if (p != NULL) {
    printf("\tEnter Player Name: ");
    scanf("%s %s", &pName, &lastName);
    strcat(pName, " ");
    strcat(pName, lastName);
    pName[50] = '\0';
    strcpy(p->name, pName);

    printf("\tEnter Player Age: ");
    scanf(" %d", &pAge);
    
    if ((pAge < 17) || (pAge > 99)) {
        printf("\tInvalid Player Age.\n");
        return 0;
    } else {
        p->age = pAge;
    }

    printf("\tEnter Player Club Affiliation: ");
    scanf("%s %s", &pClub, &lastClub);
    strcat(pClub, " ");
    strcat(pClub, lastClub);
    pName[50] = '\0';
    strcpy(p->club, pClub);

    }
}

void printPlayer(void) { // Prints a listing of all players in the database
    struct player *p;
    printf("Player Code\t\tPlayer Name\t\t\t\tAge\t\tClub\n");
    for (p = num_players; p != NULL; p = p->next) {
        printf("%d\t\t\t%s\t\t\t\t%d\t\t%s\n", p->code, p->name, p->age, p->club);
    }
}

void *deletePlayer(void) { // Deletes a player from the database
    int code;
    struct player *cur, *prev;


    printf("Enter Player Code: ");
    scanf(" %d", &code);

    for (cur = num_players, prev = NULL; cur != NULL && cur->code != code; prev = cur, cur = cur->next);
        if (cur == NULL)
            return num_players;
        if (prev == NULL)
            num_players = num_players->next;
        else
            prev->next = cur->next;
        free(cur);
        return num_players; 
    
}
