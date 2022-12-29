/**
 * Name: Fahmid Abdullah
 * Student Number: 251244838
 * Assignment: worldCupDB
 * Description: User continously chooses between help, managing the team, managing the player, and quitting
 * Date Created: November 25, 2022
*/

#include <stdio.h>
#include "worldcup_team.h"
#include "worldcup_player.h"

int isValid(char charCode[]) { // Checks if the char parameter is valid and returns 1 if it is
    char choices[6] = {'i','s','u','p','q'};
        while (1) {
            printf("Enter operation code: ");
            scanf(" %s", &charCode);
            for (int i = 0; i < 6; i++) {
                if (charCode[0] == choices[i]) 
                    return 1; } 
        }
    return 0;
}

int teams(void) { // Prompts the user continously about team commands
    char opcode[2];
    printf("\nTEAMS: Enter operation code: ");
    scanf(" %s", &opcode);
    switch (opcode[0]) {
        case ('i'): {
            newTeam();
            break; }
        case ('s'): {
            searchTeam(); 
            break; }
        case ('u'): {
            updateTeam(); 
            break; }
        case ('p'): {
            printTeam();
            return 0; }
        case ('d'): {
            deleteTeam();
            return 0; }
    }
}


int players(void) { // Prompts the user continously about player commands
    char opcode[2];
    printf("\nPLAYERS: Enter operation code: ");
    scanf(" %s", &opcode);
    switch (opcode[0]) {
        case ('i'): {
            newPlayer();
            break; }
        case ('s'): {
            searchPlayer(); 
            break; }
        case ('u'): {
            updatePlayer(); 
            break; }
        case ('p'): {
            printPlayer();
            return 0; }
        case ('d'): {
            deletePlayer();
            return 0; }
    }
}

int main() { // Prompts the user continously about main menu commands including a help section, managing teams, managing players, and quitting
    char opcode[2];
    char mainMenu[6] = {'h','q','t','p'};


    while (opcode[0] != 'q') {
        int valid = 0;

        while (valid == 0) {
            printf("\nMAIN MENU: Enter operation code: ");
            scanf(" %s", &opcode);
            for (int i = 0; i < 5; i++) {
                if (opcode[0] == mainMenu[i]) 
                    valid = 1; } 
        }
    
        switch (opcode[0]) {
            case ('h'): {
                printf("\nThis program is used to manage teams and players.\n");
                printf("Commands:\n");
                printf("h: help\nt: manage teams\np: manage players\nq: quit");
                break; }
            case ('t'): {
                teams(); 
                break; }
            case ('p'): {
                players(); 
                break; }
            case ('q'): {
                return 0; }
        }
    

    }
}