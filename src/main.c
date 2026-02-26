#include "../include/raylib.h"
#include <stdbool.h>


#define NODES 25
#define GRID 5
#define CELL 120
#define BOARD_W (GRID * CELL)
#define BOARD_H (GRID * CELL)
#define UI_W 120
#define SCREEN_W (BOARD_W + UI_W)
#define SCREEN_H (BOARD_H)


typedef enum {
    EMPTY,
    GOAT,
    TIGER
} Piece;

typedef enum {
    PLACE_PHASE,
    MOVE_PHASE
} GoatPhase;

typedef struct {
    Piece board[NODES];

    int goats_left;
    int goats_dead;
    int turn;
    int selected;
    bool game_over;
    int winner;
} Game;


static void
init_game(Game *g) {
    for (int i = 0; i < NODES; i++) {
        g->board[i] = EMPTY;
    }

    // tigers in corners
    g->board[0] = TIGER;
    g->board[4] = TIGER;
    g->board[20] = TIGER;
    g->board[24] = TIGER;

    g->goats_left = 20;
    g->goats_dead = 0;
    g->turn = 0; // 0 = goat, 1 = tiger
    g->selected = -1;
    g->game_over = false;
    g->winner = -1;
}


static void
draw_board(void) {
    for (int row = 0; row < GRID; row++) {
        for (int col = 0; col < GRID; col++) {
            int x = col * CELL;
            int y = row * CELL;

            DrawRectangleLines(x, y, CELL, CELL, DARKGRAY);
        }
    }
}


static void
draw_pieces(Game *g) {
    for (int i = 0; i < NODES; i++) {
        int row = i / GRID;
        int col = i % GRID;

        int x = col * CELL + CELL / 2;
        int y = row * CELL + CELL / 2;

        if (g->board[i] == GOAT) {
            DrawCircle(x, y, 30, GREEN);
        } else if (g->board[i] == TIGER) {
            DrawCircle(x, y, 30, RED);
        }
    }
}


static void
draw_game(Game *g) {
    ClearBackground(RAYWHITE);

    draw_board();
    draw_pieces(g);

    int tx = BOARD_W + 20;
    DrawText(TextFormat("Goats left: %d", g->goats_left), tx, 20, 20, BLACK);
    DrawText(TextFormat("Dead goats: %d", g->goats_dead), tx, 50, 20, BLACK);

    DrawText(g->turn == 0 ? "Turn: goat" : "Turn: tiger", tx, 80, 20, BLACK);
}


int
main(void){
    InitWindow(SCREEN_W, SCREEN_H, "Baghchaal");
    SetTargetFPS(60);

    Game game;
    init_game(&game);

    while (!WindowShouldClose()) {
        BeginDrawing();
        draw_game(&game);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
