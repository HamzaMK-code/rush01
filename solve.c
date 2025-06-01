
// These are function declarations (defined in other files)
int     check_all_cols(int grid[4][4]);
int     check_clues(int grid[4][4], int *clues);
void    print_grid(int grid[4][4]);

/*************************************************************
 * Copy one line (array of 4 ints) to another                *
 *************************************************************/
void    copy_line(int *src, int *dest)
{
    int i = 0;
    while (i < 4)
    {
        dest[i] = src[i];
        i++;
    }
}

/*************************************************************
 * Try one grid combination using 4 rows from the permutations
 * combo[0], combo[1], combo[2], combo[3] are the indexes of 
 * the rows taken from the 24 permutations
 * ----------------------------------------------------------
 * If the columns are valid and the clues are respected,
 * we print the grid and return 1 (success)
 *************************************************************/
int try_combo(int perms[24][4], int *clues, int combo[4])
{
    int grid[4][4];

    copy_line(perms[combo[0]], grid[0]); // Copy row 1
    copy_line(perms[combo[1]], grid[1]); // Copy row 2
    copy_line(perms[combo[2]], grid[2]); // Copy row 3
    copy_line(perms[combo[3]], grid[3]); // Copy row 4

    // Check if the grid is valid and satisfies all clues
    if (check_all_cols(grid) && check_clues(grid, clues))
    {
        print_grid(grid); // Print the valid grid
        return (1);       // Success
    }
    return (0); // Not a valid grid
}

/*************************************************************
 * Loop for third and fourth rows of the grid                *
 * Takes a and b as first two rows, then tests all c and d   *
 *************************************************************/
int solve_2(int a, int b, int perms[24][4], int *clues)
{
    int c;
    int d;
    int combo[4]; // Stores the 4 indexes of rows to test

    c = -1;
    while (++c < 24)
    {
        d = -1;
        while (++d < 24)
        {
            combo[0] = a;
            combo[1] = b;
            combo[2] = c;
            combo[3] = d;
            if (try_combo(perms, clues, combo))
                return (1); // Valid grid found
        }
    }
    return (0); // No valid grid found
}

/*************************************************************
 * This function tests every possible grid using 4 rows      *
 * from the 24 permutations                                  *
 * It starts with 2 rows (a and b), then calls solve_2       *
 *************************************************************/
void    solve(int perms[24][4], int *clues)
{
    int a;
    int b;

    a = -1;
    while (++a < 24)
    {
        b = -1;
        while (++b < 24)
        {
            if (solve_2(a, b, perms, clues))
                return; // Stop if a valid solution is found
        }
    }
    write(1, "Error\n", 6); // No solution found
}
