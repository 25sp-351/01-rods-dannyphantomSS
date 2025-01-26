#include <stdio.h>
#include <stdlib.h>

#define MAX_PIECES 100
#define MAX_ROD_LENGTH 10000 

typedef struct {
    int length;
    int value;
} Piece;

// Function prototypes
void read_piece_prices(Piece pieces[], int max_pieces, int *num_pieces);
void solve_rod_cutting(int rod_length, Piece pieces[], int num_pieces);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rod_length>\n", argv[0]);
        return 1;
    }

    int rod_length = atoi(argv[1]);
    if (rod_length <= 0 || rod_length > MAX_ROD_LENGTH) {
        fprintf(stderr, "Error: Rod length must be between 1 and %d.\n", MAX_ROD_LENGTH);
        return 1;
    }

    Piece pieces[MAX_PIECES];
    int num_pieces = 0;

    read_piece_prices(pieces, MAX_PIECES, &num_pieces);
    solve_rod_cutting(rod_length, pieces, num_pieces);

    return 0;
}

void read_piece_prices(Piece pieces[], int max_pieces, int *num_pieces) {
    printf("Enter piece prices in the format '<length>, <value>' (e.g., '9, 12').\n");
    printf("Press Ctrl+D when you are done:\n");

    int count = 0;
    char input_line[256];

    while (count < max_pieces && fgets(input_line, sizeof(input_line), stdin) != NULL) {
        int length, value;

        // Parse the input line
        if (sscanf(input_line, "%d, %d", &length, &value) == 2) {
            pieces[count].length = length;
            pieces[count].value = value;
            count++;
        } else {
            fprintf(stderr, "Invalid input format. Skipping: %s", input_line);
        }
    }

    *num_pieces = count; // Update the number of pieces read
}

void solve_rod_cutting(int rod_length, Piece pieces[], int num_pieces) {
    int total_value = 0;
    int remainder = rod_length;

    while (remainder > 0) {
        float best_ratio = 0.0;
        int best_piece_index = -1;
        int best_piece_count = 0;

        for (int i = 0; i < num_pieces; i++) {
            if (pieces[i].length <= remainder) {
                float value_per_length = (float)pieces[i].value / pieces[i].length;
                if (value_per_length > best_ratio) {
                    best_ratio = value_per_length;
                    best_piece_index = i;
                    best_piece_count = remainder / pieces[i].length;
                }
            }
        }

        if (best_piece_index == -1) {
            break;
        }

        printf("%d @ %d = %d\n", best_piece_count, pieces[best_piece_index].length,
               best_piece_count * pieces[best_piece_index].value);

        total_value += best_piece_count * pieces[best_piece_index].value;
        remainder -= best_piece_count * pieces[best_piece_index].length;
    }

    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", total_value);
}

