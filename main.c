#include "include/raylib.h"
#include <stdbool.h>

#define NODES 25
#define GRID 5
#define CELL 120
#define BOARD_W (GRID * CELL)
#define BOARD_H (GRID * CELL)
#define UI_W 300
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

static const int graph[NODES][8] = {
 /* TODO */ };

typedef struct {
  Piece board[NODES];

  int goatsLeft;
  int goatsDead;
  int turn;
  int selected;
  bool gameOver;
  int winner;
} Game;

static void init_game(Game *g) {}

static void draw_game(Game *g) {
  ClearBackground(RAYWHITE);

  int tx = BOARD_W + 20;
  DrawText(TextFormat("Goats left: %d", g->goatsLeft), tx, 20, 20, BLACK);
  DrawText(TextFormat("Dead goats: %d", g->goatsDead), tx, 50, 20, BLACK);

  DrawText(g->turn == 0 ? "Turn: goat" : "Turn: tiger", tx, 80, 20, BLACK);
}

int main(void){
  InitWindow(SCREEN_W, SCREEN_H, "Bghchaal");
  SetTargetFPS(60);

  Game game;
  init_game(&game);

  while (!WindowShouldClose()) {
    BeginDrawing();
    // .......
    draw_game(&game);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
