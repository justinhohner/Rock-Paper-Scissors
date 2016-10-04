/*
 * Copyright 2016 Dave Storey
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;
/* RockPaperScissors.c:
 * my first i/o C++ program, with do/while
 * loop and switches; saving results to file.
 */

enum Throw { rock, paper, scissors, unknown };
enum Winner { user, computer, tie  };

struct Game {
    Throw user;
    Throw computer;
    Winner winner;
};

// Using random number to simulate a "throw," or play
Throw randthrow() {
    unsigned int seed = time(0);
    Throw n = static_cast<Throw>(rand_r(&seed) % scissors);
    return n;
}

string lower(string str) {
    locale loc;
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i], loc);
    }
    return str;
}

Throw strtothrow(string str) {
    Throw ret;
    str = lower(str);
    if (str == "rock") {
        ret = rock;
    } else if (str == "paper") {
        ret = paper;
    } else if (str == "scissors") {
        ret = scissors;
    } else {
        ret = unknown;
    }

    return ret;
}

string throwtostr(Throw t) {
    string ret;
    switch (t) {
        case rock:
            ret = "Rock";
            break;
        case paper:
            ret = "Paper";
            break;
        case scissors:
            ret = "Scissors";
            break;
        default:
            ret = "unknown";
    }

    return ret;
}

// rock < paper
// scissors < rock
// paper < scissors
bool lt(Throw a, Throw b) {
    bool ret = false;
    switch (a) {
        case rock:
            if (b == paper)
                ret = true;
            break;
        case paper:
            if (b == scissors)
                ret = true;
            break;
        case scissors:
            if (b == rock)
                ret = true;
            break;
        default:
            ret = false;
    }
    return ret;
}

// paper > rock
// rock > scissors
// scissors > paper
bool gt(Throw a, Throw b) {
    bool ret = false;
    switch (a) {
        case rock:
            if (b == scissors)
                ret = true;
            break;
        case paper:
            if (b == rock)
                ret = true;
            break;
        case scissors:
            if (b == paper)
                ret = true;
            break;
        default:
            ret = false;
    }
    return ret;
}

bool eq(Throw a, Throw b) {
    return a == b;
}

string winnertostr(Winner w) {
    string ret;
    switch (w) {
        case user:
            ret = "User";
            break;
        case computer:
            ret = "Computer";
            break;
        case tie:
            ret = "Tie";
            break;
        default:
            ret = "unknown";
    }

    return ret;
}

void pretty_print(vector<Game> games) {
    vector<Game>::iterator it;
    for (int i = 0; i < games.size(); i++) {
        cout << throwtostr(games[i].user) << " " << throwtostr(games[i].computer) << " " << games[i].winner << '\n';
    }
}

// Initiates game and plays first round and
// any round where a prediction is not available.
int main() {
    locale loc;
    vector<Game> games;
    Throw compthrow, userthrow;
    int roundcnt = 0;
    string userinput = "";

    // convert the first letter to lowercase
    // q or quit to leave the game
    while (tolower(userinput[0], loc) != 'q') {
        Game game;
        cout << "Would you like to play Rock, Paper, Scissors? y/n ";
        getline(cin, userinput);
        userthrow = strtothrow(userinput);
        if (userthrow == unknown) {
            break;
        }
        compthrow = randthrow();

        game.user = userthrow;
        cout << "user played ";
        cout << throwtostr(userthrow);
        cout << "\n";

        game.computer = compthrow;
        cout << "computer played ";
        cout << throwtostr(compthrow);
        cout << "\n";

        if (gt(compthrow, userthrow)) {
            cout << "computer wins!!!";
            cout << "\n";
            game.winner = computer;
        } else if (lt(compthrow, userthrow)) {
            cout << "user wins!!!";
            cout << "\n";
            game.winner = user;
        } else {
            cout << "it was a tie :(";
            cout << "\n";
            game.winner = tie;
        }
        games.push_back(game);

        roundcnt++;
    }
    pretty_print(games);
    return 0;
}
