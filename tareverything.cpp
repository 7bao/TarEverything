#include "tareverything.h"

int main(int argc ,char **argv){
    string arg_1;
    string arg_2;
    Tareverything tar;
    switch(argc){
        case tar.sing_suff:
            arg_1 = argv[1];
            tar.write_para(arg_1); 
            cout << tar.command << endl;
            tar.tar_command(tar.command);
            break;
        case tar.doub_suff:
            arg_1 = argv[1];
            arg_2 = argv[2];
            tar.write_para(arg_1,arg_2); 
            cout << tar.command << endl;
            tar.tar_command(tar.command);
            break;
        default:
            cout << "No such file or dirctory" << endl;     
            exit(1);
    }
}

