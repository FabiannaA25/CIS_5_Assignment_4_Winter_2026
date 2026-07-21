#include <iostream>
#include <iomanip>

int calculateSum(const int* scores, int size);
double getAverage(const int& sum, const int& size);
void addBonus(int* scores, int size, int bonus = 10);
int minimumScore(const int* scores, int size);
int highPerformers(const int* scores, int size, int highScores = 80);
// Main function recalling the above functions
int main() {
	std::cout << "Original Scores: ";
	int scores[10] = { 75, 88, 62, 95, 50, 82, 70, 91, 45, 78 };
	for (int i = 0; i < 10; i++) {
		std::cout << scores[i] << " ";
	}
	std::cout << std::endl;
	int sum = calculateSum(scores, 10);
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	double average = getAverage(sum, 10);
	addBonus(scores, 10);
	std::cout << "New Scores after adding bonus (+10): ";
	for (int i = 0; i < 10; i++) {
		std::cout << scores[i] << " ";
	}
	std::cout << std::endl;
	int minimum = minimumScore(scores, 10);
	int highPerformersCount = highPerformers(scores, 10);
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;
	std::cout << "Minimum Score: " << minimum << std::endl;
	std::cout << "Number of High Performers: " << highPerformersCount << std::endl;
}
//Function Definitions
int calculateSum(const int* scores, int size) { // Pass by pointer with const which reads the array without changing it
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += scores[i];
	}
	return sum;
}
double getAverage(const int& sum, const int& size) { // Pass by value with const which reads the values without changing them
	double average = (double)sum / size;
	return average;
}
void addBonus(int* scores, int size, int bonus) { // Pass by pointer which allows the function to modify the original data
	for (int i = 0; i < size; i++) {
		scores[i] += bonus;
	}
}
int minimumScore(const int* scores, int size) { // Pass by pointer with const which reads the array without changing it and finds the minimum score
	int minimum = scores[0];
	for (int i = 1; i < size; i++) {
		if (scores[i] < minimum) {
			minimum = scores[i];
		}
	}
	return minimum;
}
int highPerformers(const int* scores, int size, int highScores) { // Pass by pointer with const which reads the array without changing it
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (scores[i] >= highScores) {
			count++;
		}
	}
	return count;
}
