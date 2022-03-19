// Radix sort implementation
#include <iostream>
#include <cmath>

using namespace std;

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int arrMax(int arr[], int n) {
	int max = arr[0];

	for(int i = 1; i < n; i++) {
		if(arr[i] > max)
			max = arr[i];
	}

	return max;
}

// 3595, 2
int get_digit(int number, int index) {
	while (index > 0) {
		number /= 10;
		index--;
	}

	return number % 10;
}

void counting(int arr[], int n, int d) {
	cout << "Okay" << endl;
	int buffer[10];
	int result[n];

	for(int i = 0; i < 10; i++) {
		buffer[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		result[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		int digit = get_digit(arr[i], d);
		buffer[digit]++;
	}

	for(int i = 1; i < 10; i++) {
		buffer[i] = buffer[i] + buffer[i-1];
	}

	for(int i = n-1; i >= 0; i--) {
		int number = arr[i];
		int digit = get_digit(number, d);
		int index = buffer[digit] - 1;
		result[index] = number;
		buffer[digit]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = result[i];
	}
}

int digit_count(int number) {
	int i = 1;

	while (number >= 10) {
		number /= 10;
		i++;
	}

	return i;
}

void radix(int arr[], int n) {
	int max = arrMax(arr, n);
	int digits = digit_count(max);

	cout << "Will require " << digits << " passes" << endl;
	for (int i = 0; i < digits; i++) {
		counting(arr, n, i);
	}
}

int main() {
	int arr[] = { 123, 46, 521, 124, 643, 5, 1345 };
	int size = sizeof(arr) / sizeof(int);
	radix(arr, size);

	print(arr, size);

	return 0;
}