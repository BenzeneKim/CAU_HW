#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define BOARDX 21
#define BOARDY 9



///--------------static--------------------//
CONSOLE_SCREEN_BUFFER_INFO csbi;
const int boardColor[BOARDY][BOARDX] = {
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1
};

char title[] = "### Tic-Tac-Toe ###";
char des[] = "Player 1 : O | Player 2 : X";
char levelText[][100] = { "Dumber(random)", "Dumb(rule based)", "Smart(Heuristics)", "Smarter(Heuristics 2)" };
///----------------parameter-------------//

int terminalColumns, terminalRows;
int board[3][3]; //0:empty 1:'O' 2:'X'

int getKey;
int isPressed = 0;

int turn = 0;
int debugCode = 0;
int human = 2;
int computer = 3;

int aiLevel = 1;
int selectingTurn = 0;
///--------------function---------------//

//for console
void DisplayInit();
void GotoXY(int x, int y);
void HideCursor();

//for game
void BoardInit();
void SelectLevel();

//for main
void Init();
void ChooseTurn();
void HumanTurn();
void ComputerTurn(int ind);
void Dumber();
void Dumb();
void Smart();
void Smarter();
void Update(int t);
void Display();



void DisplayInit() {
    system("cls");

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    terminalColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    terminalRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    //Title
    GotoXY(terminalColumns / 2 - strlen(title) / 2, 5);
    printf(title);
    HideCursor();

    //description
    GotoXY(terminalColumns / 2 - strlen(des) / 2, 7);
    printf(des);
    HideCursor();

    //Show AI level
    GotoXY(terminalColumns / 2 - (strlen("AI Level : ") + strlen(levelText[aiLevel] ))/ 2, 9);
    printf("AI Level : %s", levelText[aiLevel]);
    HideCursor();

    for (int i = 0; i < BOARDY; i++) {
        for (int j = 0; j < BOARDX; j++) {
            GotoXY(terminalColumns / 2 - BOARDX / 2 + j, 12 + i);
            if (boardColor[i][j] == 0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            else if (boardColor[i][j] == 1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            printf(" ");
            HideCursor();
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info; info.dwSize = 20;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void GotoXY(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void BoardInit() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 1;
        }
    }
}
void ChooseTurn() {
    char inputS[2];
    isPressed = 0;
    while (isPressed == 0) {

        if (kbhit()) {
            char input = getch();
            inputS[0] = input;
            inputS[1] = '\0';
            getKey = atoi(inputS);
            isPressed = 1;
        }
        Display();

        GotoXY(terminalColumns / 2 - strlen("1 : Play first(O)") / 2 - 1, 23);
        printf("1 : Play first(O)");
        GotoXY(terminalColumns / 2 - strlen("2 : Play second(X)") / 2, 24);
        printf("2 : Play second(X)");
        GotoXY(terminalColumns / 2 - strlen("3 : Select AI") / 2 - 3, 25);
        printf("3 : Select AI");
        GotoXY(terminalColumns / 2 - strlen("4 : Exit") / 2 - 5, 26);
        printf("4 : Exit");
        HideCursor();

        if (isPressed == 1) {
            switch (getKey)
            {
            case 1:
                turn = 0;
                human = 2;
                computer = 3;
                break;
            case 2:
                turn = 1;
                human = 3;
                computer = 2;
                break;
            case 3:
                SelectLevel();
                break;
            case 4:
                exit(0);
                break;
            default:
                isPressed = 0;
                break;
            }
        }
    }
}

void SelectLevel() {
    selectingTurn = 1;

    char inputS[2];
    isPressed = 0;
    while (isPressed == 0) {

        if (kbhit()) {
            char input = getch();
            inputS[0] = input;
            inputS[1] = '\0';
            getKey = atoi(inputS);
            isPressed = 1;
        }
        Display();

        GotoXY(terminalColumns / 2 - strlen("1 : Dumber(random)") / 2 - 1, 23);
        printf("1 : Dumber(random)");
        GotoXY(terminalColumns / 2 - strlen("2 : Dumb(rule based)") / 2, 24);
        printf("2 : Dumb(rule based)");
        GotoXY(terminalColumns / 2 - strlen("3 : Smart(Heuristics)") / 2, 25);
        printf("3 : Smart(Heuristics)");
        GotoXY(terminalColumns / 2 - strlen("4 : Smarter(Heuristics 2)") / 2, 26);
        printf("4 : Smarter(Heuristics 2)");
        HideCursor();

        if (isPressed == 1) {
            switch (getKey)
            {
            case 1:
                aiLevel = 0;
                break;
            case 2:
                aiLevel = 1;
                break;
            case 3:
                aiLevel = 2;
                break;
            case 4:
                aiLevel = 3;
                break;
            default:
                isPressed = 0;
                break;
            }
        }
    }
}

void Init() {
    BoardInit();
    HideCursor();
    system("cls");
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    terminalColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    terminalRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    DisplayInit();
}

void HumanTurn() {
    char inputS[2];
    isPressed = 0;
    while (isPressed == 0) {
        if (kbhit()) {
            char input = getch();
            inputS[0] = input;
            inputS[1] = '\0';
            getKey = atoi(inputS);
            isPressed = 1;
            if (board[((getKey - 1) % 3)][2 - (((getKey - 1) / 3) % 3)] != 1) {
                isPressed = 0;
            }
        }
    }
}


void ComputerTurn(int ind) {
    switch (ind) {
    case 0:
        Dumber();
        break;
    case 1:
        Dumb();
        break;
    case 2:
        Smart();
        break;
    case 3:
        Smarter();
        break;
    default:
        Smarter();
        break;
    }
}
//Random
void Dumber() {
    srand(time(NULL));
    int i = 0;
    int isEmpty = 0;
    while (isEmpty == 0) {
        i = rand() % 9 + 1;
        if (board[((i - 1) % 3)][2 - (((i - 1) / 3) % 3)] == 1) {
            isEmpty = 1;
            getKey = i;
        }
    }

}
//Rule based
void Dumb() {
    int mul = 1;

    for (int p = 0; p < 2; p++) {
        //column and row
        for (int i = 0; i < 3; i++) {
            //column
            mul = 1;
            for (int j = 0; j < 3; j++) {
                mul *= board[i][j];
            }
            if (p == 0 && mul == computer * computer) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 1) {
                        getKey = i + (2 - j) * 3 + 1;
                        //debugCode = 1;
                        return;
                    }
                }
            }
            if (p == 1 && mul == human * human) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 1) {
                        getKey = i + (2 - j) * 3 + 1;
                        //debugCode = 2;
                        return;
                    }
                }
            }
            //row
            mul = 1;
            for (int j = 0; j < 3; j++) {
                mul *= board[j][i];
            }
            if (p == 0 && mul == computer * computer) {
                for (int j = 0; j < 3; j++) {
                    if (board[j][i] == 1) {
                        getKey = j + (2 - i) * 3 + 1;
                        //debugCode = 3;
                        return;
                    }
                }
            }
            if (p == 1 && mul == human * human) {
                for (int j = 0; j < 3; j++) {
                    if (board[j][i] == 1) {
                        getKey = j + (2 - i) * 3 + 1;
                        //debugCode = 4;
                        return;
                    }
                }
            }
        }


        //diagonal
        mul = 1;
        for (int i = 0; i < 3; i++) {
            mul *= board[i][i];
        }

        if (p == 0 && mul == computer * computer) {
            for (int i = 0; i < 3; i++) {
                if (board[i][i] == 1) {
                    getKey = i + (2 - i) * 3 + 1;
                    //debugCode = 5;
                    return;
                }
            }
        }
        if (p == 1 && mul == human * human) {
            for (int i = 0; i < 3; i++) {
                if (board[i][i] == 1) {
                    getKey = i + (2 - i) * 3 + 1;
                    //debugCode = 6;
                    return;
                }
            }
        }
        mul = 1;
        for (int i = 0; i < 3; i++) {
            mul *= board[i][2 - i];
        }

        if (p == 0 && mul == computer * computer) {
            for (int i = 0; i < 3; i++) {
                if (board[i][2 - i] == 1) {
                    getKey = i * 4 + 1;
                    //debugCode = 7;
                    return;
                }
            }
        }
        if (p == 1 && mul == human * human) {
            for (int i = 0; i < 3; i++) {
                if (board[i][2 - i] == 1) {
                    getKey = i * 4 + 1;
                    //debugCode = 8;
                    return;
                }
            }
        }

    }
    //debugCode = 0;

    if (board[1][1] == 1) {
        getKey = 5;
        return;
    }
    for (int i = 1; i < 5; i++) {
        if (board[((2 * i - 1) % 3)][2 - (((2 * i - 1) / 3) % 3)] == 1) {
            getKey = 2 * i;
            return;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (board[((2 * i) % 3)][2 - (((2 * i) / 3) % 3)] == 1) {
            getKey = 2 * i + 1;
            return;
        }
    }
}
//Heuristics
void Smart() {
    int heu[9] = { 0,0,0,0,0,0,0,0,0 };
    int mul = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mul *= board[i][j];
        }
    }
    if (mul == 1) {
        getKey = 5;
        return NULL;
    }
    //scoring
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //column
            if (board[i][j] == computer) {
                for (int k = 0; k < 3; k++) {
                    heu[i + (2 - k) * 3] += 1;
                }
            }
            else if (board[i][j] == human) {
                for (int k = 0; k < 3; k++) {
                    heu[i + (2 - k) * 3] -= 1;
                }
            }
            //
            //row
            if (board[j][i] == computer) {
                for (int k = 0; k < 3; k++) {
                    heu[(2 - i) * 3 + k] += 1;
                }
            }
            else if (board[j][i] == human) {
                for (int k = 0; k < 3; k++) {
                    heu[(2 - i) * 3 + k] -= 1;
                }
            }
            //
        }
        //diagonal
        if (board[i][i] == computer) {
            for (int j = 0; j < 3; j++) {
                heu[j + (2 - j) * 3] += 1;
            }
        }
        if (board[i][i] == human) {
            for (int j = 0; j < 3; j++) {
                heu[j + (2 - j) * 3] -= 1;
            }
        }
        if (board[i][2 - i] == computer) {
            for (int j = 0; j < 3; j++) {
                heu[j * 4] += 1;
            }
        }
        if (board[i][2 - i] == human) {
            for (int j = 0; j < 3; j++) {
                heu[j * 4] -= 1;
            }
        }
        //
    }
    //remove filled blocks
    for (int i = 0; i < 9; i++) {
        if (board[(i % 3)][2 - ((i / 3) % 3)] != 1) {
            heu[i] = -10000;
        }
    }

    ////show score(for debug)
    //for (int i = 0; i < 9; i++) {
    //    GotoXY(30, i);
    //    printf("%d", heu[i]);
    //}
    //Sleep(2000);

    //select
    int result = 0;
    for (int i = 1; i < 9; i++) {
        if (heu[i] > heu[result]) result = i;
    }
    getKey = result + 1;
}

//Heuristics2
void Smarter() {
    int heu[9] = { 0,0,0,0,0,0,0,0,0 };
    //scoring
    int mul = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mul *= board[i][j];
        }
    }
    if (mul == 1) {
        getKey = 5;
        return NULL;
    }
    //column
    for (int i = 0; i < 3; i++) {
        mul = 1;
        for (int j = 0; j < 3; j++) {
            mul *= board[i][j];
        }
        if (mul == computer * computer) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    heu[i + (2 - j) * 3] += 1000;
                }
            }
        }
        else if (mul == human * human) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    heu[i + (2 - j) * 3] += 100;
                }
            }
        }
        else {
            if (mul % computer == 0) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 1) {
                        heu[i + (2 - j) * 3] += 15;
                    }
                }
            }
            if (mul % human == 0) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 1) {
                        heu[i + (2 - j) * 3] += 10;
                    }
                }
            }
        }
    }
    //row
    for (int i = 0; i < 3; i++) {
        mul = 1;
        for (int j = 0; j < 3; j++) {
            mul *= board[j][i];
        }
        if (mul == computer * computer) {
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == 1) {
                    heu[(2 - i) * 3 + j] += 1000;
                }
            }
        }
        else if (mul == human * human) {
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == 1) {
                    heu[(2 - i) * 3 + j] += 100;
                }
            }
        }
        else {
            if (mul % computer == 0) {
                for (int j = 0; j < 3; j++) {
                    if (board[j][i] == 1) {
                        heu[(2 - i) * 3 + j] += 15;
                    }
                }
            }
            if (mul % human == 0) {
                for (int j = 0; j < 3; j++) {
                    if (board[j][i] == 1) {
                        heu[(2 - i) * 3 + j] += 10;
                    }
                }
            }
        }
    }
    //diagonal
    mul = 1;
    for (int i = 0; i < 3; i++) {
        mul *= board[i][i];
    }
    if (mul == computer * computer) {
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == 1) {
                heu[6 - 2 * i] += 1000;
            }
        }
    }
    else if (mul == human * human) {
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == 1) {
                heu[6 - 2 * i] += 100;
            }
        }
    }
    else {
        if (mul % computer == 0) {
            for (int i = 0; i < 3; i++) {
                if (board[i][i] == 1) {
                    heu[6 - 2 * i] += 15;
                }
            }
        }
        if (mul % human == 0) {
            for (int i = 0; i < 3; i++) {
                if (board[i][i] == 1) {
                    heu[6 - 2 * i] += 10;
                }
            }
        }
    }
    mul = 1;
    for (int i = 0; i < 3; i++) {
        mul *= board[i][2-i];
    }

    if (mul == computer * computer) {
        for (int i = 0; i < 3; i++) {
            if (board[i][2 - i] == 1) {
                heu[i * 4] += 1000;
            }
        }
    }
    else if (mul == human * human) {
        for (int i = 0; i < 3; i++) {
            if (board[i][2 - i] == 1) {
                heu[i * 4] += 100;
            }
        }
    }
    else {
        if (mul % computer == 0) {
            for (int i = 0; i < 3; i++) {
                if (board[i][2 - i] == 1) {
                    heu[i * 4] += 15;
                }
            }
        }
        if (mul % human == 0) {
            for (int i = 0; i < 3; i++) {
                if (board[i][2 - i] == 1) {
                    heu[i * 4] += 10;
                }
            }
        }
    }
    //remove filled blocks
    for (int i = 0; i < 9; i++) {
        if (board[(i % 3)][2 - ((i / 3) % 3)] != 1) {
            heu[i] *= 0;
        }
    }


    //select
    int result = 0;
    for (int i = 1; i < 9; i++) {
        if (heu[i] > heu[result]) result = i;
    }
    getKey = result + 1;
}

void Update(int t) {
    if (t == 0) board[((getKey - 1) % 3)][2 - (((getKey - 1) / 3) % 3)] = human;
    else board[((getKey - 1) % 3)][2 - (((getKey - 1) / 3) % 3)] = computer;
}

int checkWinner() {//on playing:0 | O win:1 | X win:2 | Draw:3
    int mul = 1;
    //column
    for (int i = 0; i < 3; i++) {
        mul = 1;
        for (int j = 0; j < 3; j++) {
            mul *= board[i][j];
        }
        if (mul == pow(human,3))       return 1;       //win Human
        else if (mul == pow(computer, 3))  return 2;       //win Computer
    }

    //row
    for (int i = 0; i < 3; i++) {
        mul = 1;
        for (int j = 0; j < 3; j++) {
            mul *= board[j][i];
        }
        if (mul == pow(human, 3))       return 1;       //win Human
        else if (mul == pow(computer, 3))  return 2;       //win Computer
    }

    //diagonal
    mul = 1;
    for (int i = 0; i < 3; i++) {
        mul *= board[i][i];
    }
    if (mul == pow(human, 3))       return 1;       //win Human
    else if (mul == pow(computer, 3))  return 2;       //win Computer

    mul = 1;
    for (int i = 0; i < 3; i++) {
        mul *= board[i][2 - i];
    }
    if (mul == pow(human, 3))       return 1;       //win Human
    else if (mul == pow(computer, 3))  return 2;       //win Computer

    mul = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mul *= board[i][j];
        }
    }
    if (mul == 2592 || mul == 3888)           return 3;
    return 0;
}

void Display() {
    if (isPressed == 1) {
        // for test

        /*system("cls");
        GotoXY(1, 1);
        printf("Input Check");
        GotoXY(1, 2);
        printf("something pressed");
        GotoXY(1, 3);
        printf("%d", getKey);
        GotoXY(1, 4);
        printf("debug Code : %d", debugCode);*/


        //Title
        GotoXY(terminalColumns / 2 - strlen(title) / 2, 5);
        printf(title);
        HideCursor();

        //description
        GotoXY(terminalColumns / 2 - strlen(des) / 2, 7);
        printf(des);
        HideCursor();

        //Show AI level
        GotoXY(terminalColumns / 2 - (strlen("AI Level : ") + strlen(levelText[aiLevel])) / 2, 9);
        printf("AI Level : %s", levelText[aiLevel]);
        HideCursor();

        for (int i = 0; i < BOARDY; i++) {
            for (int j = 0; j < BOARDX; j++) {
                GotoXY(terminalColumns / 2 - BOARDX / 2 + j, 12 + i);
                if (boardColor[i][j] == 0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                else if (boardColor[i][j] == 1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                if (i % 3 == 1 && j % 7 == 3) {
                    int x, y;
                    x = j / 7;
                    y = i / 3;
                    if (board[x][y] == 2) {
                        printf("O");
                    }
                    else if (board[x][y] == 3) {
                        printf("X");
                    }
                    else {
                        printf(" ");
                    }
                }
                else {
                    printf(" ");
                }
                HideCursor();
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    }
}

void SwitchTurn() {
    if (turn == 1) turn = 0;
    else if (turn == 0) turn = 1;
}

void ShowWinner() {
    switch (checkWinner()) {
    case 1:
        GotoXY(terminalColumns / 2 - strlen("You Win") / 2, 23);
        printf("You Win");
        GotoXY(terminalColumns / 2 - strlen("Press any key to restart") / 2, 25);
        printf("Press any key to restart");
        HideCursor();
        break;
    case 2:
        GotoXY(terminalColumns / 2 - strlen("You lose") / 2, 23);
        printf("You lose");
        GotoXY(terminalColumns / 2 - strlen("Press any key to restart") / 2, 25);
        printf("Press any key to restart");
        HideCursor();
        break;
    case 3:
        GotoXY(terminalColumns / 2 - strlen("Draw") / 2, 23);
        printf("Draw");
        GotoXY(terminalColumns / 2 - strlen("Press any key to restart") / 2, 25);
        printf("Press any key to restart");
        HideCursor();
        break;
    default:
        break;
    }
    while (1) {
        if (kbhit()) {
            char clear = getch();
            break;
        }
    }
}

int main() {
    while (1) {
        Init();
        ChooseTurn();
        DisplayInit();

        while (checkWinner() == 0 && selectingTurn == 0) {
            switch (turn) {
            case 0:
                HumanTurn();            //Human Play
                Update(0);
                break;
            case 1:
                ComputerTurn(aiLevel);
                Update(1);
                break;
            default:
                break;
            }
            Display();
            SwitchTurn();
        }
        if (selectingTurn == 1) selectingTurn = 0;
        else ShowWinner();
    }
}
