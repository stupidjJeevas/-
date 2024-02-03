#include <iostream>

void FillArray(int** arr, int rows, int cols) {
	srand(time(NULL));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			arr[i][j] = rand() % 91 + 1;
		}
	}
}

void PrintArray(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << arr[i][j] << " ";
		}
	}
}

int MainCount(int** arr, int rows, int cols, int Final) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (i == j) {
				arr[i][j] += Final;
			}
		}
	}
	std::cout << Final;
	return Final;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int rows, cols;
	int Itog = 0;
	std::cout << "Введите количество строк: ";
	std::cin >> rows;

	std::cout << "Введите количество столбцов: ";
	std::cin >> cols;
	int** dynamicArray = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		dynamicArray[i] = new int[cols];
	}
	FillArray(dynamicArray, rows, cols);
    std::cout << "Двумерный массив случайных чисел от 1 до 100: " << std::endl;
	PrintArray(dynamicArray, rows, cols);
	std::cout << "Сумма по главной диагонали: " << std::endl;
	MainCount(dynamicArray, rows, cols, Itog);
    
	for (int i = 0; i < rows; ++i) {
		delete[] dynamicArray[i];
	}
	delete[] dynamicArray;
	return 0;
}

