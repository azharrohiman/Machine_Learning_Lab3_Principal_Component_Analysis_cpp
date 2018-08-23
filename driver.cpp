#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <array>
#include "Eigen/Dense"

using namespace std;

int main(int argc, char* argv[]) {

	vector<double> january;
	vector<double> july;

	ifstream file("input.txt");
	//ofstream output_file;
	//output_file.open("output.txt");
	double jan;
	double jul;

	while (file >> jan >> jul) {
		january.push_back(jan);
		july.push_back(jul);
	}

	/*
	cout << "January is: " << endl;

	for (int i = 0; i < january.size(); i++) {
		cout << january.at(i) << endl;
	}

	cout << "July is: " << endl;

	for (int i = 0; i < july.size(); i++) {
		cout << july.at(i) << endl;
	}
	*/

	double x_mean = 0.0;
	double y_mean = 0.0;

	return 0;
}
