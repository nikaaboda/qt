// Bucket sort implementation
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	float data;
	Node* next;
};

void print(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void insertionSort(vector<float> bucket, int n)
{
    int i, j;
    float key;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        key = bucket[i];

        while(j >= 0 && key < bucket[j])
        {
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}


void bucketSort(float arr[], int size) {
	vector<float> B[size];

	for(int i = 0; i < size; i++) {
		B[int(size*arr[i])].push_back(arr[i]);
	}

	for(int i = 0; i < size; i++) {

	}

	int index = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < (int)B[i].size(); j++) {
			arr[index] = B[i][j];
			index++; 
		}
	}
}

int main() {
	float arr[7] = { 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1 };
	print(arr, 7);
	bucketSort(arr, 7);
	print(arr, 7);
	return 0;
}