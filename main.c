/****************************************************************
 *                     MAIN PROGRAM (main.c)                   *
 * ------------------------------------------------------------ *
 * This is the entry point of the program.                     *
 * It reads the clues given as argument, checks if they're OK, *
 * generates all row permutations, and tries to solve the grid *
 ****************************************************************/

#include <unistd.h>

// Function prototypes (defined elsewhere)
void    generate_perms(int perms[24][4]);
void    solve(int perms[24][4], int *clues);

// Parse the input string to extract the 16 clues into the array `clues`
int parse_input(char *arg, int *clues)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (arg[i]) // Loop through each character of input
    {
        // Only allow digits from '1' to '4'
        if (arg[i] >= '1' && arg[i] <= '4')
        {
            if (j >= 16) // More than 16 clues = error
                return (0);
            clues[j++] = arg[i] - '0'; // Convert char to int and store
        }
        // Any other character than space is invalid
        else if (arg[i] != ' ')
            return (0);
        i++;
    }
    return (j == 16); // Return true if exactly 16 clues were collected
}

// Main function
int main(int argc, char **argv)
{
    int clues[16];      // Array to store the 16 clues
    int perms[24][4];   // Array to store the 24 valid row permutations

    // Check if there is exactly 1 argument, and parse it into clues[]
    if (argc != 2 || !parse_input(argv[1], clues))
    {
        write(1, "Error\n", 6); // If invalid input, print "Error"
        return (1);
    }

    // Generate all permutations of rows (each with 4 different values)
    generate_perms(perms);

    // Try all combinations of those permutations to solve the grid
    solve(perms, clues);

    return (0);
}
