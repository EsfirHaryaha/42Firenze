#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c) {
    // Scrive un singolo carattere su stdout
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    // Scrive una stringa terminata da '\0' su stdout
    while (*str)
        write(1, str++, 1);
}

void ft_putnbr(int n) {
    // Scrive un numero intero positivo su stdout (ricorsivo)
    char c;
    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void print_grid(int grid[4][4]) {
    // Stampa la griglia 4x4 con i valori e aggiunge '$' visibile con cat -e alla fine di ogni riga
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            ft_putnbr(grid[i][j]);
            if (j != 3)
                ft_putchar(' ');
            j++;
        }
        //ft_putchar('$');
        ft_putchar('\n');
        i++;
    }
}

int is_unique(int grid[4][4], int row, int col, int val) {
    // Controlla se val non è presente già nella riga e colonna specificata
    int i = 0;
    while (i < 4) {
        if (grid[row][i] == val)
            return 0;
        if (grid[i][col] == val)
            return 0;
        i++;
    }
    return 1;
}

int visible_from_left(int row[4]) {
    // Conta quante "scatole" sono visibili da sinistra in una riga data
    int count = 0, max = 0, i = 0;
    while (i < 4) {
        if (row[i] > max) {
            max = row[i];
            count++;
        }
        i++;
    }
    return count;
}

int visible_from_right(int row[4]) {
    // Conta quante "scatole" sono visibili da destra in una riga data
    int count = 0, max = 0, i = 3;
    while (i >= 0) {
        if (row[i] > max) {
            max = row[i];
            count++;
        }
        i--;
    }
    return count;
}

int visible_from_top(int grid[4][4], int col) {
    // Conta quante "scatole" sono visibili dall'alto nella colonna col
    int count = 0, max = 0, i = 0;
    while (i < 4) {
        if (grid[i][col] > max) {
            max = grid[i][col];
            count++;
        }
        i++;
    }
    return count;
}

int visible_from_bottom(int grid[4][4], int col) {
    // Conta quante "scatole" sono visibili dal basso nella colonna col
    int count = 0, max = 0, i = 3;
    while (i >= 0) {
        if (grid[i][col] > max) {
            max = grid[i][col];
            count++;
        }
        i--;
    }
    return count;
}

int check_constraints(int grid[4][4], int clues[16], int row, int col) {
    // Controlla se i vincoli di visibilità sono rispettati per righe e colonne completate
    if (col == 4) {
        int r = row;
        int left = clues[8 + r];
        int right = clues[12 + r];
        int row_vals[4];
        int i = 0;
        while (i < 4) {
            row_vals[i] = grid[r][i];
            i++;
        }
        if (visible_from_left(row_vals) != left)
            return 0;
        if (visible_from_right(row_vals) != right)
            return 0;
    }
    if (row == 4) {
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

int solve(int grid[4][4], int clues[16], int row, int col) {
    // Risolve ricorsivamente la griglia usando backtracking
    if (row == 4) {
        print_grid(grid);
        return 1;
    }
    if (col == 4)
        return solve(grid, clues, row + 1, 0);

    int val = 1;
    while (val <= 4) {
        if (is_unique(grid, row, col, val)) {
            grid[row][col] = val;
            if ((col < 3 || check_constraints(grid, clues, row, col + 1)) &&
                (row < 3 || check_constraints(grid, clues, row + 1, col))) {
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
    // Parsing manuale dell'input stringa argv[1], estraendo 16 valori numerici separati da spazi (1..4)
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
    // Funzione principale - gestisce input, allocazione, risoluzione e output o errore
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

    int (*grid)[4] = (int (*)[4])malloc(sizeof(int) * 16);
    if (!grid) {
        free(clues);
        ft_putstr("Error\n");
        return 1;
    }

    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
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
