#include <unistd.h>
#include <stdlib.h>

#define N 4

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str)
        write(1, str++, 1);
}

void ft_putnbr(int n) {
    char c;
    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void print_grid(int grid[N][N]) {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < N) {
            ft_putnbr(grid[i][j]);
            if (j != N-1)
                ft_putchar(' ');
            j++;
        }
        //ft_putchar('$');
        ft_putchar('\n');
        i++;
    }
}

int is_unique(int grid[N][N], int row, int col, int val) {
    int i = 0;
    while (i < N) {
        if (grid[row][i] == val)
            return 0;
        if (grid[i][col] == val)
            return 0;
        i++;
    }
    return 1;
}

int visible_from_left(int row[N]) {
    int count = 0, max = 0, i = 0;
    while (i < N) {
        if (row[i] > max) {
            max = row[i];
            count++;
        }
        i++;
    }
    return count;
}

int visible_from_right(int row[N]) {
    int count = 0, max = 0, i = N-1;
    while (i >= 0) {
        if (row[i] > max) {
            max = row[i];
            count++;
        }
        i--;
    }
    return count;
}

int visible_from_top(int grid[N][N], int col) {
    int count = 0, max = 0, i = 0;
    while (i < N) {
        if (grid[i][col] > max) {
            max = grid[i][col];
            count++;
        }
        i++;
    }
    return count;
}

int visible_from_bottom(int grid[N][N], int col) {
    int count = 0, max = 0, i = N-1;
    while (i >= 0) {
        if (grid[i][col] > max) {
            max = grid[i][col];
            count++;
        }
        i--;
    }
    return count;
}

int check_constraints(int grid[N][N], int clues[16], int row, int col) {
    if (col == N) {
        int r = row;
        int left = clues[8 + r];
        int right = clues[12 + r];
        int row_vals[N];
        int i = 0;
        while (i < N) {
            row_vals[i] = grid[r][i];
            i++;
        }
        if (visible_from_left(row_vals) != left)
            return 0;
        if (visible_from_right(row_vals) != right)
            return 0;
    }
    if (row == N) {
        int c = col;
        int top = clues[c];
        int bottom = clues[4 + c];
        if (visible_from_top(grid, c) != top)
            return 0;
        if (visible_from_bottom(grid, c) != bottom)
            return 0;
    }
    return 1;
}

int solve(int grid[N][N], int clues[16], int row, int col) {
    if (row == N) {
        print_grid(grid);
        return 1;
    }
    if (col == N)
        return solve(grid, clues, row + 1, 0);

    int val = 1;
    while (val <= N) {
        if (is_unique(grid, row, col, val)) {
            grid[row][col] = val;
            if ((col < N - 1 || check_constraints(grid, clues, row, col + 1)) &&
                (row < N - 1 || check_constraints(grid, clues, row + 1, col))) {
                if (solve(grid, clues, row, col + 1))
                    return 1;
            }
            grid[row][col] = 0;
        }
        val++;
    }
    return 0;
}

int parse_input(char *str, int *clues) {
    int idx = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ')
            i++;
        if (str[i] == '\0')
            break;
        if (str[i] >= '1' && str[i] <= '4') {
            if (idx >= 16)
                return 0;
            clues[idx++] = str[i] - '0';
            i++;
        } else {
            return 0;
        }
    }
    if (idx != 16)
        return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ft_putstr("Error\n");
        return 1;
    }

    int *clues = (int *)malloc(sizeof(int) * 16);
    if (!clues) {
        ft_putstr("Error\n");
        return 1;
    }

    if (!parse_input(argv[1], clues)) {
        free(clues);
        ft_putstr("Error\n");
        return 1;
    }

    int (*grid)[N] = (int (*)[N])malloc(sizeof(int) * N * N);
    if (!grid) {
        free(clues);
        ft_putstr("Error\n");
        return 1;
    }

    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < N) {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }

    if (!solve(grid, clues, 0, 0)) {
        ft_putstr("Error\n");
        free(clues);
        free(grid);
        return 1;
    }

    free(clues);
    free(grid);
    return 0;
}
