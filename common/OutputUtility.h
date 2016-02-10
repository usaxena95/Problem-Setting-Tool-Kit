#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class OutputUtility {
    int testCase;
    string fileName, OutputDir, SourceFile, OutputFile, InputDir, InputFile;
public:
    OutputUtility() {
    }
    OutputUtility(string SourceFile,string InputDir, string InputFile,string OutputDir, string OutputFile) {
        this->SourceFile = SourceFile;
        this->OutputFile = OutputFile;
        this->OutputDir = OutputDir;
        this->InputDir = InputDir;
        this->InputFile = InputFile;

        testCase = 0;
        system(("mkdir "+OutputDir).c_str());
        system(("g++ "+ SourceFile+".cpp -o "+SourceFile+".exe").c_str());
    }
    void GenerateOutput() {
        ++testCase;
        cerr<<"Generating\t"<<(OutputDir+"\\"+OutputFile+"-"+toString(testCase)+".txt")<<endl;

        double initial = clock();
        system((SourceFile+".exe < "+InputDir+"\\"+InputFile+"-"+toString(testCase)+".txt > "+OutputDir+"\\"+OutputFile+"-"+toString(testCase)+".txt").c_str());
        cerr<<"Time taken =\t"<<(clock()-initial)/CLOCKS_PER_SEC<<"  second\n";
    }
};

