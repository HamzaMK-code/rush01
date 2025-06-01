/***************************************************************
 *                  GRID VALIDATION FUNCTIONS                  *
 * ------------------------------------------------------------ *
 * These functions are used to check if a proposed 4x4 grid     *
 * follows the game's rules:                                   *
 *                                                             *
 * 1. It respects the 16 clues provided (around the grid).     *
 *    → Clues tell how many buildings are visible from each    *
 *      side (top, bottom, left, right).                       *
 * 2. Each column must have different values (no duplicates).  *
 *                                                             *
 * The grid contains numbers from 1 to 4 (representing heights).
 * Each row and column must contain the digits 1, 2, 3, 4 once. *
 ***************************************************************/

int count_visible(int *line)
{
    int max;
    int count;
    int i;

    i = 0;
    max = 0;      // start with no tallest building
    count = 0;    // how many we can see
    while (i < 4)
    {
        if (line[i] > max) // if current is taller than all before
        {
            max = line[i]; // update tallest
            count++;       // and we see it
        }
        i++;
    }
    return (count); // return number of visible buildings
}

// Count visible buildings from right to left
// Just reverse the row and call count_visible()
int reverse_count(int *line)
{
    int rev[4];
    int i;

    i = 0;
    while (i < 4)
    {
        rev[i] = line[3 - i]; // copy elements in reverse order
        i++;
    }
    return (count_visible(rev)); // count visible from reversed line
}

// Check if the current 4x4 grid respects all the 16 clues
int check_clues(int grid[4][4], int *clues)
{
    int col[4];
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        // check left-to-right clue for row i
        if (count_visible(grid[i]) != clues[8 + i])
            return (0);
        // check right-to-left clue for row i
        if (reverse_count(grid[i]) != clues[12 + i])
            return (0);

        // build column i manually
        j = 0;
        while (j < 4)
        {
            col[j] = grid[j][i]; // column j = row[j][i]
            j++;
        }

        // check top-to-bottom clue for column i
        if (count_visible(col) != clues[i])
            return (0);
        // check bottom-to-top clue for column i
        if (reverse_count(col) != clues[4 + i])
            return (0);

        i++;
    }
    return (1); // if all clues are OK
}

// Check if all columns have different numbers (no duplicates)
int check_all_cols(int grid[4][4])
{
    int c;   // column index
    int r1;  // first row to compare
    int r2;  // second row to compare

    c = 0;
    while (c < 4)
    {
        r1 = 0;
        while (r1 < 4)
        {
            r2 = r1 + 1;
            while (r2 < 4)
            {
                if (grid[r1][c] == grid[r2][c]) // same value in same column?
                    return (0); // not allowed
                r2++;
            }
            r1++;
        }
        c++;
    }
    return (1); // all columns are valid
}
