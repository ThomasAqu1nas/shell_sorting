#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
using std::string;
using std::vector;

vector<vector <float> > getFromFile(string path);
void printMatrix(vector<vector<float> > matrix);
vector<float> line(vector<vector<float> > mat);
vector<vector<float> > square(vector <float> line);

int main()
{
	string path;
	std::cout << "Enter the path to the desired file:\n";
	std::cin >> path;
	int const SIZE = 100;
	vector<vector<float> > myMatrix = getFromFile(path);
	std::cout << "Current matrix:" << std::endl;
	std::cout << "\n";
	printMatrix(myMatrix);
	int d = SIZE / 2;
	vector<float> l = line(myMatrix);

	while (d>0)
	{
		for (uint32_t j = 0; j < SIZE - d; j++)
		{
			int k = j;

			while (k >= 0 && k%2 == 0 && l[k] > l[k + d] && l[k] > 0 && l[k + d] > 0)
			{
				float temp = l[k];
				l[k] = l[k + d];
				l[k + d] = temp;
				k--;

			}
		}
		d /= 2;
	}
	std::cout << "\n";
	std::cout << "Result:" << std::endl;
	std::cout << "\n";
	printMatrix(square(l));

}

vector<vector <float> > getFromFile(string path) {
	vector<vector<float> > mat(10, vector<float> (10));
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try
	{
		std::cout << "trying to open a file..." << std::endl;
		Sleep(1000);
		fin.open(path);
		std::cout << "file opened successfully!" << std::endl;
		Sleep(1000);
		string str;
		for (uint32_t i = 0; i < 10; i++)
		{
			for (uint32_t j = 0; j < 10; j++)
			{
				fin >> str;
				mat[i][j] = std::stof(str);
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << "File oppening error" << std::endl;
	}
	return mat;
}
vector<float> line(vector<vector<float> > mat) {
	vector<float> a;
	for (uint32_t i = 0; i < 10; i++)
	{
		for (uint32_t j = 0; j < 10; j++)
		{
			a.push_back(mat[i][j]);
		}
	}
	return a;
}
vector<vector<float> > square(vector <float> line) {
	vector<vector<float> > a(10, vector<float> (10));
	int k = 0;
	for (uint32_t i = 0; i < 10; i++)
	{
		for (uint32_t j = 0; j < 10; j++)
		{
			a[i][j] = line[k];
			k++;
		}
	}
	return a;
}
void printMatrix(vector<vector <float> > matrix) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

