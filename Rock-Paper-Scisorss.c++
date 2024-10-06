#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum ensort { Paper = 1, Scissor = 2, Rock = 3 };
short CounterEqual = 0;
short CounterComputerWins = 0;
short CounterPlayerWins = 0;
void PlayerWinScreen() {
system("color A0");
}
void ComputerWinScreen() {
system("color C0");
}
void EqualScreen() {
system("color E0");
}
short READSORT() {
short Number;
do {
 cin >> Number;
} while (Number < 1 || Number > 3);
return Number;
}
short READ(string msg) {
short Number;
do {
cout << msg << endl;
cin >> Number;
Untitled 2
} while (Number < 1 || Number > 10);
return Number;
}
ensort PlayerChoce() {
cout << "[1] Paper, [2] Scissor, [3] Rock" << endl;
short PChoce = READSORT();
return static_cast<ensort> (PChoce);
}
ensort ComputerChoce() {
short CChoce = rand() % 3 + 1;
return static_cast<ensort> (CChoce);
}
void PrintChoses(ensort PlayerChose, ensort ComputerChose) {
string PlayerChoseStr;
switch (PlayerChose)
{
case Paper: PlayerChoseStr = "Paper"; break;
case Scissor: PlayerChoseStr = "Scissor"; break;
case Rock: PlayerChoseStr = "Rock"; break;
}
string ComputerChoseStr;
switch (ComputerChose)
{
case Paper: ComputerChoseStr = "Paper"; break;
case Scissor: ComputerChoseStr = "Scissor"; break;
case Rock: ComputerChoseStr = "Rock"; break;
}
cout << "Your Choice: " << PlayerChoseStr << endl;
cout << "Computer Choice: " << ComputerChoseStr<< endl;
}
void EqualWins(ensort PlayerChoce, ensort ComputerChoce) {
EqualScreen();
Untitled 3
cout << "Its Tie" << endl;
PrintChoses(PlayerChoce, ComputerChoce);
}
void ComputerWins(ensort PlayerChoce, ensort ComputerChoce) {
ComputerWinScreen();
PrintChoses(PlayerChoce, ComputerChoce);
cout << "Computer Wins" << endl;
}
void PlayerWins(ensort PlayerChoce, ensort ComputerChoce) {
PlayerWinScreen();
PrintChoses(PlayerChoce, ComputerChoce);
cout << "You Won" << endl;
}
void Compare(ensort PlayerChoce, ensort ComputerChoce) {
// 2 Mean that Player won
if (PlayerChoce == ComputerChoce) {
 EqualWins( PlayerChoce, ComputerChoce);
 CounterEqual++;
}
else if ((PlayerChoce == ensort::Rock && ComputerChoce == ens
ort::Paper) || (PlayerChoce == ensort::Scissor && ComputerCho
ce == ensort::Rock) ||
 (PlayerChoce == ensort::Paper && ComputerChoce == ensor
t::Scissor)) {
 ComputerWins(PlayerChoce, ComputerChoce);
 CounterComputerWins++;
}
else if ((PlayerChoce == ensort::Rock && ComputerChoce == ens
ort::Scissor) || (PlayerChoce == ensort::Scissor && ComputerC
hoce == ensort::Paper) ||
 (PlayerChoce == ensort::Paper && ComputerChoce == ensor
t::Rock))
Untitled 4
{
 PlayerWins(PlayerChoce, ComputerChoce);
 CounterPlayerWins++;
}
}
void Game() {
short Round = READ("Enter How Many Rounds You Will Play!!");
for (int i = 1; i <= Round; i++) {
cout << "Round [" << i << "] is Begging Please Choose One Of Them ==> ";
ensort PlayerChoice = PlayerChoce();
ensort ComputerChoice = ComputerChoce();
Compare(PlayerChoice, ComputerChoice);
}
}
void CompareLastResult() {
short CounterEquall = CounterEqual;
short CounterPlayerWinss = CounterPlayerWins;
short CounterComputerWinss = CounterComputerWins;
if ((CounterEquall > CounterComputerWinss) && (CounterEquall >
CounterPlayerWinss )) {
PlayerWinScreen();
cout << endl << endl << endl << "The Game Result is: Tie " << endl;
}
else if ((CounterComputerWinss > CounterEquall) && (CounterComputerWinss >
CounterPlayerWinss)) {
ComputerWinScreen();
cout << endl << endl << endl << "The Game Result is: Computer Won " << endl;
}
else if ((CounterPlayerWinss > CounterEquall) && (CounterPlay
erWinss > CounterComputerWinss)) {
 PlayerWinScreen();
Untitled 5
 cout << endl << endl << endl << "The Game Result is: You
Won" << endl;
}
}
void PrintResult() {
short PlayerWinsTimes = CounterPlayerWins;
short ComputerWinsTimes = CounterComputerWins;
short EqualTimes = CounterEqual;
cout << "
GAME OVER" << endl;
cout << "Equals is: "<<EqualTimes << endl;
cout << "Your Wons is: " << PlayerWinsTimes << endl;
cout << "My Wons is: " << ComputerWinsTimes << endl;
CompareLastResult();
}
void RePlay() {
int Number;
cout << "Do You Want To play Again [1] => Yes [0] => No " << endl;
cin >> Number;
if (Number == 1) {
Game();
PrintResult();
RePlay();
}
else if (Number == 0) {
cout << "Thank You For The Game, See You!!" << endl;
}
else {
cout << "Please Enter Valid Number" << endl;
}
}
void AllGame() {
Game();
PrintResult();
Untitled 6
RePlay();
}
int main() {
srand((unsigned)time(NULL));
AllGame();
return 0;
