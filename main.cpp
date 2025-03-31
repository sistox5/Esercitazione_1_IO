#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <numbers>

double mappa(double);

const int a = 1;
const int b = 5;
const int c = -1;
const int d = 2;
const int PRECISION = 16;
const std::string file_iniziale = "data.txt";
const std::string file_output = "result.txt";

int main() {
    std::ifstream inputFile(file_iniziale);
    std::cout << std::setprecision(PRECISION) << std::scientific;
    std::ofstream outputFile(file_output);
    outputFile << std::scientific << std::setprecision(PRECISION);
    
    if (inputFile && outputFile) {
        double temp = 0.0, sum = 0.0, mean = 0.0;
        int count = 0;
        
        outputFile << "# N Mean\n";
        
        while (inputFile >> temp) {
            double converted = mappa(temp);
            sum += converted;
            mean = sum / ++count;
            
            
            outputFile << count << " " << mean << "\n";
        }
    }
    return 0;
}

double mappa(double v) {
    return ((v - a) * (d - c) / (b - a)) + c;
}