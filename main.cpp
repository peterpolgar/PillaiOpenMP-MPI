/* 
 * File:   main.cpp
 * Author: addy
 *
 * Created on August 22, 2013, 7:12 PM
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "pillai_op.h"
#include "pillai.h"
#include "set"
#include "pillai_bt.h"
#include <time.h>
#include <ctime>
#include <boost/progress.hpp>
#include <omp.h>
#include <dirent.h>
#include <string.h>

using namespace std;

/**
 * Extern Function declarations.
 */
extern int* pillaif(int n);
bool isExist(const char*) ;

/**
 * Pillai project Controller Main Function
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv) {

    // 17 - 1; 25 - 2; 49 - 3 ; 63 - 4; 91 - 5; 103 - 6; 13? - 7; ? - 8
    //Common declerations:
    unsigned short int n = BITSET_SIZE, d = 4, gDepth = d;
    pillai* sol;
    vector<unsigned short int>* primesV = new vector<unsigned short int> ();
    boost::progress_timer pT;

    switch (argc) {

            // Generating: "/home/addy/NetBeansProjects/Pillai6s2/" for grid solving: 
        case 4:
            // 1 1 "/home/addy/NetBeansProjects/Pillai6s2/"
            // 2 2 "/home/addy/NetBeansProjects/Pillai6s2/"
            // 3 3 "/home/addy/NetBeansProjects/Pillai6s2/"
            // 4 4 "/home/addy/NetBeansProjects/Pillai6s2/"
            d = atoi(argv[1]);
            if (argv[1] > argv[2])
                gDepth = atoi(argv[1]);
            else
                gDepth = atoi(argv[2]);

            cout << "Generation for grid solving" << endl;
            pT.restart();
            //pillai_bt::pillai_generate(n, d, gDepth, "/home/addy/NetBeansProjects/Pillai6s/");
            pillai_bt::pillai_generate(n, d, gDepth, argv[3]);
            //pillai_bt::pillai_generate_p(n, d, gDepth, argv[3]);
            break;

            // Grid solving: 
        case 2:
        {
            // /home/addy/NetBeansProjects/Pillai6s2/17_1/in/17_1_1.txt
            // /home/addy/NetBeansProjects/Pillai6s2/25_2/in/25_2_6.txt
            // /home/addy/NetBeansProjects/Pillai6s2/49_3/in/49_3_12.txt
            // /home/addy/NetBeansProjects/Pillai6s2/63_4/in/63_4_79.txt
            cout << "Grid solving" << endl;
            cout << argv[1] << endl;

            // Output checking:
            string outFile(string(argv[1]).replace( string(argv[1]).find("in"), std::string("in").length(), "out" ));     

            ifstream myfile;
            myfile.open(outFile.c_str());
            if(myfile.good()) {              
                std::cout<<"The result already exists."<<std::endl;
				myfile.close();
            }
            else 
            {
                std::cout<<"Unable to open file, so the result does not exists."<<std::endl;
                std::cout << "Running..." << std::endl;
                pT.restart();
                pillai_bt::pillai_solver_f(argv[1]);
                std::cout << "Finish." << std::endl;
            }
            break;
        }
            

        case 5: // /home/addy/NetBeansProjects/Pillai6s2/25_2/in/ gebulkp 0 run
               //  /home/addy/NetBeansProjects/Pillai6s2/49_3/in gebulkp 1 run
        {
            cout << "Parallel Grid solving" << endl;
            std::string str_outputFile;
            cout << argv[1] << endl;

            DIR *Dir;
            struct dirent *DirEntry;
            Dir = opendir(argv[1]);
            std::vector<string> fileVector;

            // Read input file list
            int noFiles = 0;
            while (DirEntry = readdir(Dir)) {
                if (DirEntry->d_name[0] != '.') {
                    str_outputFile.assign(argv[1]);
                    str_outputFile.append("/");
                    str_outputFile.append(DirEntry->d_name);
                    fileVector.push_back(str_outputFile);
                    noFiles++;
                }
            }
            closedir(Dir);

            // Run in parallel way:
            int nthreads, tid;
            omp_set_dynamic(0);
            
            //#pragma omp parallel for num_threads(atoi(argv[3]))
            //#pragma omp parallel for num_threads(atoi(argv[3])==0?omp_get_num_threads():atoi(argv[3]))
            for (int n = 0; n < fileVector.size(); n++) {
                //if (n == 0) {
                //    nthreads = omp_get_num_threads();
                //    printf("%d threads are used to running.\n", nthreads);
                //}
                //std::cout << fileVector.at(n) << std::endl;
                //std::cout << "Running..." << std::endl;
                pT.restart();
                
                // Output checking:
                if (isExist((fileVector.at(n)).c_str()) && strcmp(argv[4],"rerun") != 0) {
                    std::cout<<"The result already exists."<<std::endl;
                }
                else 
                {
                    std::cout<<"The result does not exists yet or rerun function is activated."<<std::endl;
                    std::cout << "Running..." << std::endl;
                    pillai_bt::pillai_solver_f((fileVector.at(n)).c_str());
                    std::cout << "Finish." << std::endl;
                }
            }
            break;
        }

        default:
            cout << "Not adequate input parameters are given for:" << endl;
            cout << "   - Generating grid solving," << endl;
            cout << "   - Grid solving." << endl;
            cout << "" << endl;

            cout << "START one thread pc solving:" << endl;
            pT.restart();

            sol = pillai_bt::pillai_solver(n, primesV,argc==3? atoi(argv[2]):d);
            cout <<pT.elapsed()<< endl;
            delete sol;

            break;
    }

    //TEST:
    gDepth = 1;
    //pillai_bt::pillai_writer(pillai_bt::pillai_solver(n, primesV, d, gDepth),n, d, "/home/addy/NetBeansProjects/Pillai6s/");
    //pillai_bt::pillai_generate(n, d, gDepth, "/home/addy/NetBeansProjects/Pillai6s/");
    //pillai_bt::pillai_reader(std::string("/home/addy/NetBeansProjects/Pillai6s/17_1/in/17_1_2.txt").c_str(), " ");
    //pillai_bt::pillai_solver_f(std::string("/home/addy/NetBeansProjects/Pillai6s/17_1/in/17_1_1.txt").c_str());

    primesV->clear();
    delete primesV;
    return 0;
}

/**
 * Exist file or not
 * @param input - const char*
 * @return bool - true if the file already exist. 
 */
bool isExist(const char* input) {

    size_t pos;
    std::string str_outputFile, str_tail;
    std::ofstream outputFile;

    str_outputFile.assign(input);
    str_tail.assign(str_outputFile.substr(pos = (str_outputFile.find("in") + 2), str_outputFile.length()));
    str_outputFile.replace(pos - 2, str_outputFile.length(), std::string("out" + str_tail));
    outputFile.open(str_outputFile.c_str(), std::ios::in);

    if (outputFile.is_open()) {
        outputFile.close();
        return true;
    } else {
        return false;
    }
}
