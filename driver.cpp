#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <array>
#include "Eigen/Dense"
#include "Eigen/Eigenvalues"

using namespace Eigen;
using Eigen::MatrixXd;
using namespace std;

int main(int argc, char* argv[]) {

	vector<double> january;
	vector<double> july;

	ifstream file("input.txt");
	//ifstream file("test.txt");
	//ofstream output_file;
	//output_file.open("output.txt");
	double jan;
	double jul;

	while (file >> jan >> jul) {
		january.push_back(jan);
		july.push_back(jul);
	}

	double x_total = 0.0;
	double y_total = 0.0;

	for (int i = 0; i < january.size(); i++) {
		x_total += january.at(i);
		y_total += july.at(i);
	}

	cout << "Total for January is: " << x_total << " and total for July is: " << y_total << endl;

	double x_mean = x_total/january.size();
	double y_mean = y_total/july.size();

	cout << "Mean for January is: " << x_mean << " and mean for July is: " << y_mean << endl;

	for (int i = 0; i < january.size(); i++) {
		january.at(i) -= x_mean;
		july.at(i) -= y_mean;
	}

	double january_variance = 0.0;
	double july_variance = 0.0;

	double january_july_variance = 0.0;

	for (int i = 0; i < january.size(); i++) {
		january_variance += january.at(i) * january.at(i);
		july_variance += july.at(i) * july.at(i);

		january_july_variance += january.at(i) * july.at(i);
	}

	//cout << january_variance/january.size() << endl;

	MatrixXd m(2, 2);
	m(0, 0) = january_variance/(january.size()-1);
	m(1, 0) = january_july_variance/(january.size()-1);
	m(0, 1) = january_july_variance/(january.size()-1);
	m(1, 1) = july_variance/(july.size()-1);

	//std::cout << m << std::endl;

	EigenSolver<MatrixXd> es(m);
	cout << "Eigen values: " << endl << es.eigenvalues() << endl << endl;
	cout << "Eigen vectors: " << endl << es.eigenvectors() << endl << endl;

	cout << "January variance: " << january_variance/(january.size()-1) << " is " << 100*(january_variance/(january_variance + july_variance)) << "%";
	cout << " of the total variance." << endl;

	cout << "July variance: " << july_variance/(january.size()-1) << " is " << 100*(july_variance/(january_variance + july_variance)) << "%";
	cout << " of the total variance." << endl;

	cout << "Total variance: " << (january_variance/(january.size()-1)) + (july_variance/(january.size()-1)) << endl;

	return 0;
}
