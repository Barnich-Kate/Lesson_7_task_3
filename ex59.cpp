#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void fill_file(const char * const filename, const vector <double> &numbers);
vector <double> get_numbers(ifstream &input_file, vector <double> &numbers);
int main()
{
    setlocale(LC_ALL, "Russian");
    const char file_name[] = "Textt.txt";
    ifstream input_file(file_name);
    vector <double> numbers;
    get_numbers(input_file, numbers);
    input_file.close();
    fill_file(file_name, numbers);
    cout<<"Все чила возведены в квадрат";
    cout<<endl<<endl;
}
 
vector <double> get_numbers(ifstream &input_file, vector <double> &numbers)
{
    while (!input_file.eof())
    {
        double temporary;
        input_file >> temporary;
        numbers.push_back(temporary *= temporary);
    }
    return numbers;
}
 
void fill_file(const char * const filename, const vector <double> &numbers)
{
    ofstream output(filename);
    const size_t vector_capacity = numbers.size();
    for (size_t counter{0}; counter < vector_capacity ; counter++)
    {
        output << numbers.at(counter);
        if (counter != vector_capacity - 1)
        {
            output << '\t';
        }
    }
    output.close();
}
0
