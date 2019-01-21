/**
 * @file main.cpp
 * @author Manuel Fernando Galindo Semanate (mfdogalindo@outlook.com)
 * @brief Sort numbers separated by spaces in a text file
 * @version 1.0
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "sort.hpp"
#include <fstream>

using namespace std;

string outfile_name;
vector<string> lines_vector;    //temporal string lines vector
string line;                    //temporal string line 
algorithm alg_selected;         //enumerated element to select sort algorithm
int line_counter = 0;           //valid and invalid lines counter


/**
 * @brief main function
 * 
 * @param argc arguments counter
 * @param argv arguments -> [0]: ignored, [1]: input file path, [2]: output file path, [3]: algorithm selector
 * @return int exit code
 */
int main(int argc, char** argv) 
{ 

    switch (argc){
        case 2:
            outfile_name = "out.txt";
            alg_selected = _QUICK;
            break;
        case 3:
            outfile_name = argv[2];
            alg_selected = _QUICK;
            break;
        case 4:
            outfile_name = argv[2];
            //Sort selector valition
            if(strcmp(argv[3], "--quick") == 0 || strcmp(argv[3], "-q")==0){
                alg_selected = _QUICK;
            } 
            else if(strcmp(argv[3],"--gnome") == 0 || strcmp(argv[3], "-g")==0){
                alg_selected = _GNOME;
            }
            else{
                alg_selected = _QUICK;
            }
            break;
        default:
            cout << "Parameters error!" << endl;
            return 1;
    }
    ifstream inputfile (argv[1]);
    ofstream (outfile_name);

    cout << "Sort method: ";
    if(alg_selected == _GNOME){
        cout << "gnome" << endl;
    }
    else{
        cout << "quick" << endl;
    }

    //files/filesystem validation
    if (inputfile.is_open() && outputfile.is_open())
    {
        //Parsing lines of file
        while ( getline (inputfile,line) ){
            line_counter++;

            //line characters and size validation
            if(lineValidator(line) > 0 && line.size() <= 100){
                lines_vector.push_back(line); //adding line to vector
            }
            else{
                cout << "WARNING! Line " << line_counter << " invalid" << endl;
            }

             //number of file lines validation
            if(lines_vector.size() > 10000){
                cout << "WARNING! File has more than 10000 lines, ignoring rest of file" << endl;
                break;
            }
        }

        //empty file validation
        if(lines_vector.size()==0){
            cout << "Error! empty file" << endl;
            return 1;
        }

        //Computing sort algorithm...
        sortWorker(lines_vector, alg_selected);

        //writing output file
        for(int lin=0;lin<lines_vector.size();lin++){
            outputfile << lines_vector[lin] << endl;
        }

        inputfile.close();
        outputfile.close();

        cout << "Success!" << endl;
        return 0;
    }

    else {
        cout << "Unable to open/create file" << endl;
        return 1;
    }
} 
