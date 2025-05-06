#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "Game.h"
#include "Engine.h"
#include "main.h"
void drawWinScreen(Game& game, Engine& engine)
{
    int gameStatus = game.GameStatus();
    std::string msg;
    SDL_Color bgColor;
    SDL_Color textColor;
    if (gameStatus == Game::P1Wins)
    {
        msg = "Player 1, WON";
        bgColor = { 0,0,0,200 };
        textColor = { 255,255,255,255 };
    }

    else if (gameStatus == Game::P2Wins)
    {
        msg = "Player 2, WINS!!!";
        bgColor = { 255,255,255,200 };
        textColor = { 0,0,0,255 };
    }
    engine.drawRectangle(500, 500, 1000, 1000, bgColor);
    engine.drawText(msg, 500, 500, textColor);
    engine.drawText("Press space to play again.", 500, 800, textColor);
}

int main() {

    Engine engine;

    Game game;
    bool running = true;
    SDL_Event event;
    int row = 0;
    int col = 0;
    bool pieceSelected = false;
    int selectedRow = -1, selectedCol = -1;
    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    if (game.GameStatus() != Game::ongoing) game = Game();
                }
            }

            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int clickedCol = event.button.x / 100;
                int clickedRow = event.button.y / 100;

                if (game.GameStatus() == Game::ongoing) {
                    if (!pieceSelected) {
                        // First click: select a piece
                        
                        if (game.GetPieceType(clickedCol, clickedRow) == game.GetCurrentPiece()) {
                            pieceSelected = true;
                            selectedRow = clickedRow;
                            selectedCol = clickedCol;
                        }
                    }
                    else {
                        // Second click: attempt move or attack
                        std::vector<int> moveSet = { clickedCol, clickedRow };
                        std::vector<int> selectedMove = { selectedCol, selectedRow };
                        bool attack = game.ValidAttack(moveSet, selectedMove);
                        bool move = game.ValidMove(moveSet, selectedMove);
                        if (attack) {
                            game.Play(moveSet, selectedMove, true);
                            selectedRow = -1;
                            selectedCol = -1;
                            pieceSelected = false;
                        }
                        else if (move) {
                            game.Play(moveSet, selectedMove, false);
                            selectedRow = -1;
                            selectedCol = -1;
                            pieceSelected = false;
                        }
                    }
                }
            }
        }

        engine.clear();
        game.Draw(&engine, selectedRow, selectedCol);
        if (game.GameStatus() != Game::ongoing) {
            drawWinScreen(game, engine);
        }

        engine.flip();
    }
    return 0;
}