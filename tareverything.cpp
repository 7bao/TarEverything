#include "tareverything.h"

int main(int argc ,char **argv){
    string arg_1 = argv[1];
    Tareverything tar;
    tar.write_para(arg_1); 
    cout << tar.command << endl;
    tar.tar_command(tar.command);
}

