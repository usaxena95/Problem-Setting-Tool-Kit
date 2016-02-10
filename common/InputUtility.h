class InputUtility {
    string InputDir, InputFile;
    OutputUtility output;
    int testCase;
public:
    InputUtility(string InputDir,string InputFile,OutputUtility output) {
        testCase = 0;
        this->InputDir = InputDir;
        this->InputFile = InputFile;
        this->output = output;

        system(("mkdir "+InputDir).c_str());
    }
    void open() {
        string fileName = InputDir+"\\"+InputFile+"-" + toString(++testCase) +".txt";
        cerr<<"Generating\t"<<fileName<<"....\n";
        freopen(fileName.c_str(),"w",stdout);
    }
    void close() {
        fclose(stdout);
        output.GenerateOutput();
    }
};
