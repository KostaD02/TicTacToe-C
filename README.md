# Tic Tac Toe 
Tic Tac Toe game written in c++ <br>

<img style="width:400px;height:400px;" src="https://simo.sh/tic-tac-toe-draw.gif">

```cpp
#include <iostream>

startGame(firstPlayerName, secondPLayerName);

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

```
<p> Output: </p>
======================================================== <br>
             Tic         Tac     Toe        <br>
====================Rules===============================   <br>
Tic-tac-toe is a game for two players, X and O, <br>
who take turns marking the spaces in a 3x3 grid.   <br>    
The player who succeeds in placing three of their marks  <br>
in a horizontal, diagonal or vertical row wins the game. <br>
Write a numer where will be displayed your mark <br>
======================================================== <br>
<br> 
First player will be (X) : Kosta <br>
Second player will be (O) : Doe <br>
<br>
========================================================<br>
<br>
Start game (Y/N) ? : Y<br>
<br>
╔═╦═╦═╗ <br>
║1║2║3║ <br>
╠═╬═╬═╣ <br>
║4║5║6║ <br>
╠═╬═╬═╣ <br>
║7║8║9║ <br>
╚═╩═╩═╝ <br>
Now it's Kosta turn . <br>
Make move between 1-9 <br>
Your move : 1 <br>
╔═╦═╦═╗ <br>
║X║2║3║ <br>
╠═╬═╬═╣ <br>
║4║5║6║ <br>
╠═╬═╬═╣ <br>
║7║8║9║ <br>
╚═╩═╩═╝ <br>
<br>
Now it's Doe turn . <br>
Make move between 1-9 <br>
Your move : 2 <br>
... <br>
... <br>
... <br>
╔═╦═╦═╗ <br>
║X║O║3║ <br>
╠═╬═╬═╣ <br>
║X║O║6║ <br>
╠═╬═╬═╣ <br>
║X║8║9║ <br>
╚═╩═╩═╝ <br>
<br>
Winner is : Kosta <br>
<br>
Wanna rematch (Y/N) ? : n <br>
Okey so final winner is kosta <br>
