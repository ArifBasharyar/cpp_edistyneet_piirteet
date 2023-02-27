#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ofstream outfile("teht3.html", ios::out);
	string name{}, desc{};
	const string 
		BEG = "<html>\n<head>\n</head>\n<body>\n</body>\n\t<center>\n\t\t<h1>",
		MID = "</h1>\n\t</center>\n\t<br />\n\t",
		END = "\n\t<br />\n</body>\n</html>";

	if (!outfile) {
		cerr << "Failed to write a file.";
		return 1;
	}

	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Describe yourself: ";
	getline(cin, desc);

	outfile << BEG << name << MID << desc << END;

	outfile.close();
	return 0;
}