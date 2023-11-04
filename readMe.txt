Task: Design and implement a database of all teams (nations) for the World Cup.

Design
-Each team will be stored as a structure with the following attributes:
 +Team code (unique integer from 0 to 31)
 +Team name (up to 25 characters)
 +Group seeding (letter representing group and number representing seeding)
 +Primary kit (uniform) colours (R, 0, Y, G, B, I, V)

Implementation
-Program should continuously prompt the user for one of five possible commands:
 +Insert a new team (using command i)
 +Search for a team in the database and print it out (using command s)
 +Update a team in the database (using command u)
 +Print the entire list of teams (using command p)
 +Quit the program (using command a)

Other implementation notes
-Helper functions and C libraries can be used.
 +No delete function.
 +Wording for prompts can be customized.

Page 2: Sample output
Operation code: p (Print the entire list of teams)
Operation code: i (Insert a new team)
Operation code: p (Print the entire list of teams)
Operation code: i (Insert a new team)
Operation code: i (Insert a new team)
Operation code: i (Insert a new team)
Operation code: s (Search for a team in the database and print it out)
Operation code: u (Update a team in the database)
Operation code: p (Print the entire list of teams)
Operation code: q (Quit the program)