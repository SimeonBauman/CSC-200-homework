#include <iostream>
#include <time.h>

using namespace std;

void Sort(int* ar, int leng);
int* genArray(int leng);
void printArray(int* ar, int leng);

int main()
{
	srand(time(NULL));
	int* nums = genArray(100);
	printArray(nums, 100);
	Sort(nums, 100);
	printArray(nums, 100);
}


int* genArray(int leng) {


	int* nums = (int*)malloc(leng * sizeof(int));
	for (int i = 0; i < leng; i++) {

		nums[i] = rand();
		
	}
	
	return nums;
}


void Sort(int* ar, int leng) {
	int temp = 0;
	for (int i = 0; i < leng - 1; i++) {
		for (int j = 0; j < leng - i - 1; j++) {
			if (ar[j] > ar[j + 1]) {
				temp = ar[j + 1];
				ar[j + 1] = ar[j];
				ar[j] = temp;
			}
		}
	}
}
void printArray(int* ar, int leng) {
	for (int i = 0; i < leng; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}