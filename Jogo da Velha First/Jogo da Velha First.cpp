#include <iostream>
#include <string>

class Game
{
private:
	std::string nboard = R"(
 1 | 2 | 3 
___|___|___
 4 | 5 | 6 
___|___|___
 7 | 8 | 9 
   |   |   )";


	std::string xturn = "It's X's turn:";
	std::string yturn = "It's O's turn:";
	unsigned int turncount = 1;
	char turn = 'X';
	bool WinCond = false;



	char board[3][3] = { { '_','_','_' },
							  { '_','_','_' },
							  {'_','_','_' } };

	char preview[3][3] = { { '_','_','_' },
							 { '_','_','_' },
							 {'_','_','_' } };


public:
	int input = -1;


	void PrintT()
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				std::cout << "|" << board[x][y] << "|";
			}
			std::cout << std::endl;
		}

	}

	void PrintPreview()
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				std::cout << "|" << preview[x][y] << "|";
			}
			std::cout << std::endl;
		}

	}

	void Next()
	{
		turncount++;
		if (turncount % 2 != 0)
		{
			turn = 'X';
			std::cout << xturn << std::endl;
		}
		else
		{
			turn = 'O';
			std::cout << yturn << std::endl;
		}
	}

	void Assign()
	{
		std::cin >> input;
		--input;
		for (int x = 10; x >= (input / 3); x--)
		{
			if (x == input / 3)
			{
				for (int y = 10; y >= (input % 3); y--)
				{
					if (y == input % 3) { board[x][y] = turn; }
				}
			}
		}
	}

	void CheckWin()
	{
		while (turncount > 4)
		{
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					if (board[x][y] == board[x][y - 1])
					{
						if (board[x][y] == board[x][y - 1])
						{
							WinCond = true;
						}
					}
					if (board[x][y] == board[x - 1][y])
					{
						if (board[x][y] == board[x - 2][y])
						{
							WinCond = true;
						}
					}
					if (board[x][y] == board[x + 1][y + 1])
					{
						if (board[x][y] == board[x + 2][y + 2])
						{
							WinCond = true;
						}
					}
				}
			}
		}

		std::cout << "The " << symbol << " is the winner!" << std::endl;
	}


	void Play()
	{
		while (WindCond == false)
		{
			Assign();
			PrintT();
			CheckWin();
			Next(); // Verificar se isso será printado mesmo após o jogo acabar
		}
	}

};




int main()
{

	std::cout << "Press Enter to start the game" << std::endl;
	std::cin.get();
	bool InitGame = true;
	while (Initgame == true)
	{
		Game g;
		std::cout << "This is the board:\n" << std::endl;
		g.PrintPreview();
		std::cout << "\nYou can choose where to assign your symbol by pressing the respective number on your keyboard." << std::endl;
		std::cout << "Now, X goes first. Type in the respective number for your intended play:" << std::endl;
		g.Play();
		char choice;
		std::cout << "\nDo you want to play one more? Y/N" << std::endl;
		std::cin >> choice;
		if (choice == 'N') { Initgame = false; }
		else { std::cout << "Okay, let's play one more!" << std::endl; }
	}
	std::cout << "Thank you for playing! " << (char)0x03;
	std::cin.get();


}