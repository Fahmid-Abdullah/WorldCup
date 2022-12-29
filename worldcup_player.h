#define PLAYER_NAME 50 // Constant definition for max player name length
#define CLUB_LEN 50 // Constant definition for max club length

struct player *findPlayerCode(int code); // Looks up player code in team array. Returns the player index if the player code is found
int newPlayer(); // Prompts the user for information about a new player, and then inserts the player in the database
void searchPlayer(void); // Prompts the user to enter a player code, then looks up the player in the database. If the player exists, prints the code, name, age, and club
int updatePlayer(); // Prompts the user to enter a player code, then looks up the player in the database. If the player exists, lets the user enter a replacement name, age, and colour
void printPlayer(void); // Prints a listing of all players in the database
void *deletePlayer(void); // Deletes a player from the database