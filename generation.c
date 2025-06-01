
 /* ------------------------------------------------------------ *
 * This part builds all possible row combinations for the grid. *
 * Each row must contain 4 different numbers: 1, 2, 3, 4        *
 * → So we generate all permutations of [1, 2, 3, 4]            *
 * There are 24 valid permutations (4!)                        *
 ****************************************************************/

// Save a valid combination (after checking it's unique)
void store_perm(int combo[4], int *p, int values[4], int perms[24][4])
{
    if (*p < 24) // limit to 24 permutations max
    {
        // Translate indexes into actual values from {1,2,3,4}
        perms[*p][0] = values[combo[0]];
        perms[*p][1] = values[combo[1]];
        perms[*p][2] = values[combo[2]];
        perms[*p][3] = values[combo[3]];
        (*p)++; // go to next slot
    }
}

// Check if combo has 4 different indexes, then store it
void check_and_store(int combo[4], int *p, int values[4], int perms[24][4])
{
    // Make sure all indexes are different (no duplicates)
    if (combo[0] != combo[1] && combo[0] != combo[2] && combo[0] != combo[3]
        && combo[1] != combo[2] && combo[1] != combo[3] && combo[2] != combo[3])
        store_perm(combo, p, values, perms); // if OK, store
}

// Loop through all values to generate every possible 4-number combo
void generate_perms_loops_2(int a, int *p, int values[4], int perms[24][4])
{
    int b;
    int c;
    int d;
    int combo[4]; // stores 4 positions (indexes 0 to 3)

    b = -1;
    while (++b < 4)
    {
        c = -1;
        while (++c < 4)
        {
            d = -1;
            while (++d < 4)
            {
                // Build one full combination of 4 numbers (by index)
                combo[0] = a;
                combo[1] = b;
                combo[2] = c;
                combo[3] = d;
                // Check if it's valid and store it
                check_and_store(combo, p, values, perms);
            }
        }
    }
}

// First loop for the first position, call sub-loop for the rest
void generate_perms_loops(int values[4], int perms[24][4])
{
    int a;
    int p;

    p = 0;   // counter for how many permutations saved
    a = -1;
    while (++a < 4)
        generate_perms_loops_2(a, &p, values, perms); // recursive loop
}

// Start permutation generation with values {1, 2, 3, 4}
void generate_perms(int perms[24][4])
{
    int values[4];

    values[0] = 1;
    values[1] = 2;
    values[2] = 3;
    values[3] = 4;
    generate_perms_loops(values, perms); // fill perms with all valid rows
}
