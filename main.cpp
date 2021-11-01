#include <iostream>
#include <string>

using namespace std;

void playGame(string first, string second);

char userPlay[9] = {0};

const string winningPlaces[9] = {
    "012",
    "345",
    "678",
    "048",
    "048",
    "246",
    "036",
    "147",
    "258"};

void displayRule(string first, string second)
{
    cout << "========================================================" << endl;
    cout << "\t     Tic \t Tac \t Toe" << endl;
    cout << "====================Rules===============================" << endl;
    cout << "Tic-tac-toe is a game for two players, X and O," << endl;
    cout << "who take turns marking the spaces in a 3x3 grid." << endl;
    cout << "The player who succeeds in placing three of their marks " << endl;
    cout << "in a horizontal, diagonal or vertical row wins the game." << endl;
    cout << "Write a numer where will be displayed your mark" << endl;
    cout << "========================================================" << endl;
    cout << endl;
    cout << "First player will be (X) : " << first << endl;
    cout << "Second player will be (O) : " << second << endl;
    cout << endl;
    cout << "========================================================" << endl;
    cout << endl;
}

void displayDesk()
{
    cout << char(201) << char(205) << char(203) << char(205) << char(203) << char(205) << char(187) << endl;
    cout << char(186) << userPlay[0] << char(186) << userPlay[1] << char(186) << userPlay[2] << char(186) << endl;
    cout << char(204) << char(205) << char(206) << char(205) << char(206) << char(205) << char(185) << endl;
    cout << char(186) << userPlay[3] << char(186) << userPlay[4] << char(186) << userPlay[5] << char(186) << endl;
    cout << char(204) << char(205) << char(206) << char(205) << char(206) << char(205) << char(185) << endl;
    cout << char(186) << userPlay[6] << char(186) << userPlay[7] << char(186) << userPlay[8] << char(186) << endl;
    cout << char(200) << char(205) << char(202) << char(205) << char(202) << char(205) << char(188) << endl;
}

bool checkWinner(string first, string second, int runCounter)
{
    string winner = "";
    bool tempWinner = false;
    int firstPlayerMap[5] = {0};
    int secondPlayerMap[4] = {0};
    int counter = 0;
    int secondCounter = 0;
    int length = 0;
    string temp = "";
    string firstPlayerStringValue = "";
    string secondPlayerStringValue = "";
    for (int i = 0, j = 0, k = 0; i < 9; i++)
    {
        if (userPlay[i] == 'X')
        {
            firstPlayerMap[j] = i;
            j++;
        }
        else if (userPlay[i] == 'O')
        {
            secondPlayerMap[k] = i;
            k++;
        }
        else
            continue;
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        firstPlayerStringValue += to_string(firstPlayerMap[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        secondPlayerStringValue += to_string(secondPlayerMap[i]);
    }
    if (runCounter == 1)
    {
        length = 1;
        firstPlayerStringValue.erase(1);
        secondPlayerStringValue = "0";
    }
    else if (runCounter == 2)
    {
        length = 1;
        firstPlayerStringValue.erase(1);
        secondPlayerStringValue.erase(1);
    }
    else if (runCounter == 3)
    {
        length = 2;
        firstPlayerStringValue.erase(2);
        secondPlayerStringValue.erase(1);
    }
    else if (runCounter == 4)
    {
        length = 2;
        firstPlayerStringValue.erase(2);
        secondPlayerStringValue.erase(2);
    }
    else if (runCounter == 5)
    {
        length = 3;
        firstPlayerStringValue.erase(3);
        secondPlayerStringValue.erase(2);
    }
    else if (runCounter == 6)
    {
        length = 3;
        firstPlayerStringValue.erase(3);
        secondPlayerStringValue.erase(3);
    }
    else if (runCounter == 7)
    {
        length = 4;
        firstPlayerStringValue.erase(4);
        secondPlayerStringValue.erase(3);
    }
    else if (runCounter == 8)
    {
        length = 4;
        firstPlayerStringValue.erase(4);
        secondPlayerStringValue.erase(4);
    }
    else if (runCounter == 9)
    {
        length = 5;
        firstPlayerStringValue.erase(5);
        secondPlayerStringValue.erase(4);
    }
    else
    {
        cout << "System bug , unexpected error !" << endl;
    }
    if (runCounter >= 5)
    {
        for (int i = 0; i < 9; i++)
        {
            counter = 0;
            secondCounter = 0;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < length; k++)
                {
                    if (winningPlaces[i][j] == firstPlayerStringValue[k])
                    {
                        counter++;
                        if (counter == 3)
                        {
                            tempWinner = true;
                            winner = first;
                            break;
                        }
                    }
                    if (winningPlaces[i][j] == secondPlayerStringValue[k])
                    {
                        secondCounter++;
                        if (secondCounter == 3)
                        {
                            tempWinner = true;
                            winner = second;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (tempWinner)
    {
        char answer = 'n';
        cout << "Winner is : " << winner << endl;
        cout << endl
             << "Wanna rematch (Y/N) ? : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            playGame(first, second);
        }
        else if (answer == 'n' || answer == 'N')
        {
            cout << "Okey so final winner is " << winner << endl;
            exit(0);
        }
        else
        {
            cout << "Can't understand that is yes or no \nso i will close myself , try run again" << endl;
            exit(0);
        }
    }
    return tempWinner;
}

void fillArray()
{
    char temp[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 9; i++)
    {
        userPlay[i] = temp[i];
    }
}

void playGame(string first, string second)
{
    fillArray();
    bool firstRun = true;
    int counter = 0;
    int number = 0;
    int runCounter = 1;
    cout << endl;
    while (true)
    {
        if (firstRun)
        {
            displayDesk();
        }
        else
        {
            system("CLS");
            displayDesk();
            if (checkWinner(first, second, runCounter))
                break;
            runCounter++;
            if (runCounter == 10)
            {
                char answer = 'n';
                cout << "Draw !" << endl;
                cout << endl
                     << "Wanna rematch (Y/N) ? : ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
                {
                    playGame(first, second);
                }
                else if (answer == 'n' || answer == 'N')
                {
                    cout << "Okey so winner is friendship" << endl;
                    exit(0);
                }
                else
                {
                    cout << "Can't understand that is yes or no \nso i will close myself , try run again" << endl;
                    exit(0);
                }
            }
            if (runCounter >= 11)
            {
                cout << "Unexpected error !" << endl;
                exit(0);
            }
        }
        if (counter == 0)
        {
            cout << "Now it's " << first << " turn ." << endl;
            cout << "Make move between 1-9" << endl;
            cout << "Your move : ";
            cin >> number;
            if (number <= 0 || number > 9)
            {
                cout << "Told you to input number between 1-9" << endl;
                cout << "Let's try again , input number : ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                    cout << "Okey if u wanna crash proggram \nI will close myself!" << endl;
                    exit(0);
                }
            }
            if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
            {
                cout << endl;
                cout << endl;
                cout << "You can't place your mark twice on one place !" << endl;
                cout << "Make move between 1-9" << endl;
                cout << "Your move : ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                    cout << "Told you to input number between 1-9" << endl;
                    cout << "Let's try again , input number : ";
                    cin >> number;
                    if (number <= 0 || number > 9)
                    {
                        cout << "Okey if u wanna crash proggram \nI will close myself!" << endl;
                        exit(0);
                    }
                }
                if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
                {
                    cout << endl;
                    cout << "Use program wisely :)" << endl;
                    cout << "Program is closing ..." << endl;
                    system("PAUSE");
                    exit(0);
                }
                else
                {
                    userPlay[number - 1] = 'X';
                    displayDesk();
                    counter++;
                    firstRun = false;
                }
            }
            else
            {
                userPlay[number - 1] = 'X';
                displayDesk();
                counter++;
                firstRun = false;
            }
        }
        else
        {
            cout << "Now it's " << second << " turn ." << endl;
            cout << "Make move between 1-9" << endl;
            cout << "Your move : ";
            cin >> number;
            if (number <= 0 || number > 9)
            {
                cout << "Told you to input number between 1-9" << endl;
                cout << "Let's try again , input number : ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                    cout << "Okey if u wanna crash proggram \nI will close myself!" << endl;
                    exit(0);
                }
            }
            if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
            {
                cout << endl;
                cout << endl;
                cout << "You can't place your mark twice on one place !" << endl;
                cout << "Make move between 1-9" << endl;
                cout << "Your move : ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                    cout << "Told you to input number between 1-9" << endl;
                    cout << "Let's try again , input number : ";
                    cin >> number;
                    if (number <= 0 || number > 9)
                    {
                        cout << "Okey if u wanna crash proggram \nI will close myself!" << endl;
                        exit(0);
                    }
                }
                if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
                {
                    cout << "Use program wisely :)" << endl;
                    cout << "Program is closing ..." << endl;
                    system("PAUSE");
                    exit(0);
                }
                else
                {
                    userPlay[number - 1] = 'O';
                    displayDesk();
                    counter--;
                    firstRun = false;
                }
            }
            else
            {
                userPlay[number - 1] = 'O';
                displayDesk();
                counter--;
                firstRun = false;
            }
        }
    }
}

void startGame(string first, string second)
{
    displayRule(first, second);
    string start;
    cout << "Start game (Y/N) ? : ";
    cin >> start;
    if (start == "y" || start == "Y")
    {
        playGame(first, second);
    }
    else if (start == "n" || start == "N")
    {
        cout << "Maybe give a try (Y/N) ? : ";
        cin >> start;
        if (start == "y" || start == "Y")
        {
            playGame(first, second);
        }
        else
        {
            cout << "Closing program" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Wrong answer , Answer must be Y or N let's start again" << endl;
        system("PAUSE");
        system("CLS");
        startGame(first, second);
    }
}

int main(int argc, char const *argv[])
{
    string firstPlayerName = "Kosta";
    cout << "Input first player name : ";
    cin >> firstPlayerName;
    string secondPLayerName = "Doe";
    cout << "Input second player name : ";
    cin >> secondPLayerName;
    startGame(firstPlayerName, secondPLayerName);
    return 0;
}