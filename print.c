/*****************************************************************
 *                PRINT THE 4x4 GRID TO THE TERMINAL             *
 * ------------------------------------------------------------- *
 * This function prints the 4x4 grid using spaces between        *
 * numbers and new lines after each row.                         *
 *****************************************************************/

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    print_grid(int grid[4][4])
{
    int i; // row index
    int j; // column index

    i = 0;
    while (i < 4) // Loop through each row
    {
        j = 0;
        while (j < 4) // Loop through each column
        {
            // Print the number + '0' to convert it into a character
            ft_putchar(grid[i][j] + '0');

            // Print a space after each number except the last one in the row
            if (j < 3)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n'); // After each row, go to the next line
        i++;
    }
}
