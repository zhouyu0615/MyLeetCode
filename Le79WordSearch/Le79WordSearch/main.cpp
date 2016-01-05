#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Solution {

public:
	bool exist(vector<vector<char>>& board, string word) {
		boardRow = board.size();
		boardCol = board[0].size();
		visited.assign(boardRow, vector<int>(boardCol, false));

		targetWord = word;

		if (word.length()>boardRow*boardCol)
		{
			return false;
		}



		for (int i = 0; i < boardRow;i++)
		{
			for (int j = 0; j < boardCol;j++)
			{
				if (board[i][j]!=targetWord[0])
				{
					continue;
				}
				DfsBackTrack(board, i, j, "");
				if (result==true)
				{
					return result;
				}
			}
		}

		return result;
	}
private:
	vector<vector<int>> visited;
	string targetWord;
	int boardRow;
	int boardCol;
	bool result = false;

	void DfsBackTrack(vector<vector<char>>& board, int row, int col, string word)
	{
		if (word == targetWord)
		{
			result = true;
			return;
		}

		if (word.length()>=targetWord.length())
		{
			return;
		}

		if (row<0||row>=boardRow||col<0||col>=boardCol)
		{
			return;
		}


		if (visited[row][col] == true) return;

		word = word + board[row][col];
		visited[row][col] = true;
		
		if (word == targetWord.substr(0, word.length()))
		{
			DfsBackTrack(board, row - 1, col, word);
			if (result==true)
			{
				return;
			}
			DfsBackTrack(board, row + 1, col, word);
			if (result == true)
			{
				return;
			}
			DfsBackTrack(board, row, col - 1, word);
			if (result == true)
			{
				return;
			}
			DfsBackTrack(board, row, col + 1, word);
			if (result == true)
			{
				return;
			}


		}
		word = word.substr(0, (word.length() - 1));
		visited[row][col] = false;
   }

 };







 int main()
 {
	 Solution testCase;

	 vector<vector<char>> board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };

	 string word = "SEE";

	 cout << testCase.exist(board, word)<<endl;

	 getchar();
	 return 0;
 }

