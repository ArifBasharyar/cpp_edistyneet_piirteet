#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream infile("random.txt", ios::in);
	int line{}, counter{}, sum{}, avg{};
	
	if (!infile) {
		cerr << "Failed to read file";
		return 1;
	} 
	
	while (infile >> line) {
		counter += 1;
		sum += line;
	}

	avg = sum / counter;
	cout << "counter: " << counter << ",\tsum: " << sum << ",\tavg: " << avg << ".\n";

	infile.close();
	return 0;
}