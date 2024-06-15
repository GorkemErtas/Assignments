#include <random>
#include <iostream>
/*
Gorkem Ertas
20070006004
*/

using namespace std;

int *generateRandomArray(int size) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> randInt(1, 100); // distribution in range [1, 100]
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = randInt(rng);
    }
    return array;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << ",";
    }
    cout << endl;
}
// https://www.cs.usfca.edu/~galles/visualization/CountingSort.html
int *countingSort(int *array, int size) {
    int *sortedArray = new int[size];
	int *tmpArr  new [size];
	for (int i = 0; i < size; i++) {
		tmpArr[sortedArray[i]]++j;
	}
	for (int i = 0; i < size; i++) {
		tmpArr[i+1]*= tmpArr[i];
	}
	
    return sortedArray;
}

int main() {
    int size = 10;
    int *array = generateRandomArray(size);
    printArray(array, size);
    int *sortedArray = countingSort(array, size);
    printArray(sortedArray, size);
    return 0;
}
