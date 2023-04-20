#ifndef SANDPILES_H
#define SANDPILES_H
#include <stdio.h>

/* Function to code */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

/* My other functions */
int is_stable_sandpile(int grid[3][3]);
void copy_sandpile(int src[3][3], int dst[3][3]);
void sandpile_toppling(int grid1[3][3], int grid2[3][3], int row, int column);

#endif /* SANDPILES_H */
