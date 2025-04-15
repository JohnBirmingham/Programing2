Keeps track of what games are in stock and what games are out of stock. 
I would use a std::list to organize the games and make it easy to remove games. 
This allows the user to keep track of where things are easily be able to remove items.
Nouns:
Game
GameTracker
gameName
personName
gameList
checkedIn
Verbs:
AddGame
RemoveGame
CheckGameIn
CheckGameOut
ListGames
// Game.h
class Game {
public:
    std::string gameName;
    bool checkedIn;
    std::string personName;
    Game(std::string gameName, bool checkedIn, std::string personName);
};
 
// GameTracker.h
class GameTracker {
private:
    std::list<Game> gameList;
public:
    void AddGame(const Game& game);
    void RemoveGame(int gameNum);
    void ListGame() const;
    void CheckGameIn(int gameNum);
    void CheckGameOut(int gameNum);
};
```mermaid
    class Game {
        +gameName : string
        +checkedIn : bool
        +personName : string
        +Game() : string
    }

    class GameTracker {
        -gameList : list~Game~ 
        +AddGame(game : Game&)
        +RemoveGame(gameNum : int)
        +ListGame()
        +CheckGameIn(gameNum : int)
        +CheckGameOut(gameNum : int)
    }
 
    GameTracker --> Game : uses
```