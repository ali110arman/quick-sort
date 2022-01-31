#include <iostream>
using namespace std;
class Sort {
public:
	Sort();
	int Max();
	void Quick_Sort(int Low, int High);
	void Print();
private:
	int n;
	int arr[20];
	int Partition(int Low, int High);
	void Swap(int* xp, int* yp);
};
int Sort::Max() {
	return n;
}
void Sort::Print() {
	for (int i = 0; i < n; i++)
		cout << arr[i]<<" ";
}
void Sort::Swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
Sort::Sort() {
	cout << "inter count: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}
int Sort::Partition(int Low, int High) {
	int pivot = arr[High];
	int i = (Low - 1);
	for (int j = Low; j <= High - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[High]);
	return (i + 1);
}

void Sort::Quick_Sort(int Low, int High) {
	if (Low < High) {
		int pi = Partition(Low, High);
		Quick_Sort(Low, pi - 1);
		Quick_Sort(pi + 1, High);
	}
}
void main() {
	Sort s;
	s.Quick_Sort(0, s.Max() - 1);
	s.Print();
}