#define TEAM_NAME 25 // Constant definition for max team name length
#define SEEDING_LEN 3 // Constant definition for max seeding length
#define COLOUR_LEN 7 // Constant definition for max colour length

struct team *findTeamCode(int code); // Looks up team code in team array. Returns the team index if the team code is found
struct team *findTeamName(char name[]); // Looks up team name in team array. Returns the team index if the team name is found
struct team *findTeamSeeding(char seeding[]); // Looks up team seeding in team array. Returns the team index if the team name is found
int validSeed(char seed[]); // Checks if the seeding entered follows the required format
int validKit(char *colour); // Checks if the colour kit format entered follows the required format 
int newTeam(); // Prompts the user for information about a new team, and then inserts the team in the database
void searchTeam(void); // Prompts the user to enter a team code, then looks up the team in the database. If the team exists, prints the code, name, seeding, and colour
int updateTeam(); // Prompts the user to enter a team code, then looks up the team in the database. If the team exists, lets the user enter a replacement name, seeding, and colour
int printTeam(); // Prints a listing of all teams in the database
void *deleteTeam(void); // Deletes a team from the database