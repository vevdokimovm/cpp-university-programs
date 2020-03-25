#include <iostream>
#define EMPTY 0
#define N 9


struct Sudoku
{
Sudoku() {
	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N; ++j)
			std::cin >> field[i][j];
}


bool empty_spots(int & row, int & col) {
	for (row = 0; row < N; ++row)
		for (col = 0; col < N; ++col)
			if (this->field[row][col] == EMPTY)
				return true;
	return false;
}

bool is_member_uniq(int rowIndex = 0, int colIndex = 0, int value = 0) {
	for (int j = 0; j < N; ++j)
		if (field[rowIndex][j] == value && j != colIndex)
			return false;
	for (int i = 0; i < N; ++i)
		if (field[i][colIndex] == value && i != rowIndex)
			return false;
	for (int i = (rowIndex / 3) * 3; i < (rowIndex / 3) * 3 + 3; ++i)
		for (int j = (colIndex / 3) * 3; j < (colIndex / 3) * 3 + 3; ++j)
			if (field[i][j] == value && i != rowIndex && j != colIndex)
				return false;
	return true;
}

bool sudoku_solver()
{
	int row, col;
	if (!empty_spots(row, col))
		return true;
	for (int num = 1; num <= N; ++num)
		if (is_member_uniq(row, col, num)){
			field[row][col] = num;
			if (sudoku_solver())
				return true;
			field[row][col] = EMPTY;
		}
	return false;
}


void output() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			std::cout << field[i][j] << " ";
		std::cout << std::endl;
	}
}


int field[9][9] = {};
};


int main()
{
	int number = 0;
	std::cout << "Print Sudoku field : \n" << std::endl;

	for (size_t i = 0; i < 3; ++i)
		for (size_t j = 0; j < N * N; ++j)
			std::cin >> number;
	Sudoku sudoku;


	for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (sudoku.field[i][j] != EMPTY)
                if (!sudoku.is_member_uniq(i, j, sudoku.field[i][j])){
                    std::cout << "NO";
                    return 0;
                }


	int a = 0;
	int b = 0;
	if (!sudoku.empty_spots(a, b)){
		sudoku.output();
		return 0;
	}
	else if (!sudoku.sudoku_solver()) {
		std::cout << "NO";
		return 0;
	}
	sudoku.output();
	system("pause");
	return 0;
}
