#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h> 
using namespace std;

bool catUsed[13] = { false };
int diceArray[5];

class Die {
public:
	int roll();
};

int Die::roll() {
	int result = rand() % 6 + 1;
	return result;
}



class Dice : public Die {
public:
	void rollAll();
};

void Dice::rollAll() {
	cout << "You rolled: ";
	for (int i = 0; i <= 4; i++)
	{
		diceArray[i] = roll();
		if (i < 4) {
			cout << diceArray[i] << ", ";
		}
		else
			cout << diceArray[i] << "\n";
	}
	cout << "\n";
}



class ScoreCard : public Dice {
public:
	int getScore(int);
	void display();
};

void ScoreCard::display() {
	cout << "Category 1: Aces: " << catUsed[0] << endl;
	cout << "Category 2: Twos: " << catUsed[1] << endl;
	cout << "Category 3: Threes: " << catUsed[2] << endl;
	cout << "Category 4: Fours: " << catUsed[3] << endl;
	cout << "Category 5: Fives: " << catUsed[4] << endl;
	cout << "Category 6: Sixes: " << catUsed[5] << endl;
	cout << "Category 7: Three-Of-A-Kind: " << catUsed[6] << endl;
	cout << "Category 8: Four-Of-A-Kind: " << catUsed[7] << endl;
	cout << "Category 9: Full House: " << catUsed[8] << endl;
	cout << "Category 10: Small Straight: " << catUsed[9] << endl;
	cout << "Category 11: Large Straight: " << catUsed[10] << endl;
	cout << "Category 12: Yahtzee: " << catUsed[11] << endl;
	cout << "Category 13: Chances: " << catUsed[12] << endl << endl;
}

int ScoreCard::getScore(int category) {
	int score = 0;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;

	if (category == 1) {
		catUsed[0] = true;

		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 1) {
				score += 1;
			}
		}
	}

	if (category == 2) {
		catUsed[1] = true;

		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 2) {
				score += 2;
			}
		}
	}

	if (category == 3) {
		catUsed[2] = true;

		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 3) {
				score += 3;
			}
		}
	}

	if (category == 4) {
		catUsed[3] = true;

		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 4) {
				score += 4;
			}
		}
	}

	if (category == 5) {
		catUsed[4] = true;

		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 5) {
				score += 5;
			}
		}
	}

	if (category == 6) {
		catUsed[5] = true;

		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 6) {
				score += 6;
			}
		}
	}

	else {
		for (int i = 0; i < 5; i++) {
			if (diceArray[i] == 1) { count1++; }
			else if (diceArray[i] == 2) { count2++; }
			else if (diceArray[i] == 3) { count3++; }
			else if (diceArray[i] == 4) { count4++; }
			else if (diceArray[i] == 5) { count5++; }
			else { count6++; }
		}
	}

	if (category == 7)
	{
		catUsed[6] = true;
		for (int j = 0; j < 5; j++)
		{
			if (count1 >= 3) { score += diceArray[j]; }
			else if (count2 >= 3) { score += diceArray[j]; }
			else if (count3 >= 3) { score += diceArray[j]; }
			else if (count4 >= 3) { score += diceArray[j]; }
			else if (count5 >= 3) { score += diceArray[j]; }
			else if (count6 >= 3) { score += diceArray[j]; }
		}
	}

	if (category == 8)
	{
		catUsed[7] = true;
		for (int j = 0; j < 5; j++)
		{
			if (count1 >= 4) { score += diceArray[j]; }
			else if (count2 >= 4) { score += diceArray[j]; }
			else if (count3 >= 4) { score += diceArray[j]; }
			else if (count4 >= 4) { score += diceArray[j]; }
			else if (count5 >= 4) { score += diceArray[j]; }
			else if (count6 >= 4) { score += diceArray[j]; }
		}
	}

	if (category == 9) {
		catUsed[8] = true;

		if ((count1 == 3 && count2 == 2) || (count1 == 3 && count3 == 2) || (count1 == 3 && count4 == 2) || (count1 == 3 && count5 == 2) || (count1 == 3 && count5 == 2) ||
			(count1 == 2 && count2 == 3) || (count1 == 2 && count3 == 3) || (count1 == 2 && count4 == 3) || (count1 == 2 && count5 == 3) || (count1 == 2 && count5 == 3) ||

			(count2 == 3 && count3 == 2) || (count2 == 3 && count4 == 2) || (count2 == 3 && count5 == 2) || (count2 == 3 && count6 == 2) ||
			(count2 == 2 && count3 == 3) || (count2 == 2 && count4 == 3) || (count2 == 2 && count5 == 3) || (count2 == 2 && count6 == 3) ||

			(count3 == 3 && count4 == 2) || (count3 == 3 && count5 == 2) || (count3 == 3 && count6 == 2) ||
			(count3 == 2 && count4 == 3) || (count3 == 2 && count5 == 3) || (count3 == 2 && count6 == 3) ||

			(count4 == 3 && count5 == 2) || (count4 == 3 && count6 == 2) ||
			(count4 == 2 && count5 == 3) || (count4 == 2 && count6 == 3) ||

			(count5 == 3 && count6 == 2) ||
			(count5 == 2 && count6 == 3)) {
			score += 25;
		}
	}


	if (category == 10) {
		catUsed[9] = true;

		int i, key, j;
		for (i = 1; i < 5; i++) {
			key = diceArray[i];
			j = i - 1;

			while (j >= 0 && diceArray[j] > key) {
				diceArray[j + 1] = diceArray[j];
				j = j - 1;
			}
			diceArray[j + 1] = key;
		}

		int curSeqLen = 1;
		int lastDie = diceArray[0];

		if (diceArray[0] >= 4 || diceArray[4] <= 3) score = 0;

		for (int i = 1; i < 5; i++) {

			if (diceArray[i] == lastDie + 1) {
				curSeqLen++;
			}

			else if (diceArray[i] == lastDie) {}

			else {
				curSeqLen = 1;
			}
			if (curSeqLen >= 4) score = 30;
			lastDie = diceArray[i];
		}
	}

	if (category == 11) {
		catUsed[10] = true;

		int i, key, j;
		for (i = 1; i < 5; i++) {
			key = diceArray[i];
			j = i - 1;

			while (j >= 0 && diceArray[j] > key) {
				diceArray[j + 1] = diceArray[j];
				j = j - 1;
			}
			diceArray[j + 1] = key;
		}

		int curSeqLen = 1;
		int lastDie = diceArray[0];

		if (diceArray[0] >= 3 || diceArray[4] <= 2) score = 0;

		for (int i = 1; i < 5; i++) {

			if (diceArray[i] == lastDie + 1) {
				curSeqLen++;
			}

			else if (diceArray[i] == lastDie) {}

			else {
				curSeqLen = 1;
			}
			if (curSeqLen >= 5) score = 40;
			lastDie = diceArray[i];
		}
	}

	if (category == 12)
	{
		catUsed[11] = true;
		if (count1 == 5 || count2 == 5 || count3 == 5 || count4 == 5 || count5 == 5 || count6 == 5) { score = 50; }
	}

	if (category == 13) {
		catUsed[12] = true;

		for (int i = 0; i < 5; i++) {
			score += diceArray[i];
		}
	}

	return score;
}



class Game : public ScoreCard {
public:
	void play();
	bool gameOver();
};

void Game::play() {
	//Die die1, die2, die3, die4, die5;
	ScoreCard gamecard;
	Dice allDice;
	int userCategory = 30;
	int totalScore = 0;
	int pointsGained = 0;
	int round = 1;

	while (gameOver() != true)
	{
		cout << "____________________________\n";
		cout << "          Round " << round << endl;
		cout << "____________________________\n\n";
		allDice.rollAll();
		display();

		bool isValid = false;

		while (isValid == false)
		{
			cout << "Choose a category (1-13): ";
			cin >> userCategory;
			cout << "\n";

			if (userCategory >= 1 && userCategory <= 13 && catUsed[userCategory - 1] != true) {
				isValid = true;
			}
			else {
				cout << "Invalid input, please try again!\n";
			}
		}

		// Get score
		int pointsGained = gamecard.getScore(userCategory);
		cout << "Points gained: " << pointsGained << "\n\n\n";
		totalScore += pointsGained;

		round++;
	}

	cout << "Game Over!\n";
	cout << "Total Score: " << totalScore;
}

bool Game::gameOver() {
	bool allUsed = true;
	int i = 0;

	while (allUsed == true && i < 13)
	{
		if (catUsed[i] == false)
			allUsed = false;
		i++;
	}

	return allUsed;
}

int main()
{
	srand(time(0));

	Game newGame;
	newGame.play();

	return 0;
}
