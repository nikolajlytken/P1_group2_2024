#include <stdio.h>

// Load all matches in an array of structs (90 matches in the tournament) ("Match-array") that contains:
// Day of week of the match
// Date (without year)
// Time of day (klokkeslæt)
// The two teams playing the match
// Result of match
// Number of visiters (tilskuere)

// Run through all matches and make 12 "team-arrays"
// Must be an associative array = associates a string (team name) with a certain struct
// Each team is a struct, that contains:
// Team-name
// Points
// Number of goals scored
// Number of goals conceded

// "If you want, you can place the teams on "predetermined" positions in the team-array"

// Output:
// Team-name    Points      Goals for       Goals against       Goal diff
// Preferably output the team with the most points at the top - if equal points, decide from goal differnce


// To-do:

// Read from file
// 