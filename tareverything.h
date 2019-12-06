#include <cstdlib>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>
#include <map>
#include <sys/stat.h>

using namespace std;
using namespace boost;
using std::vector;

class Tareverything {
    public :
//        Tareverything():doub_suff(1),sing_suff(2){};

        static const int doub_suff;
        static const int sing_suff;
        string command;

        void tar_command(string& command);
        void write_para(string& path_and_filename);
        void write_para(string& path_and_filename, string& dest_path);
    private:
        enum suff { tar = 1, tar_gz, gz,tar_bz2,tar_Z,rar,zip,tar_xz};
};
        const int Tareverything::sing_suff = 2;
        const int Tareverything::doub_suff = 3;

void Tareverything::tar_command(string& command){
    system(command.data());
}

void Tareverything::write_para(string& path_and_filename) {
    vector<string> fields;
    int suffpoint;
    const int SINGLE = 2;
    const int DOUBLE = 3;
    fstream _file;
    map<string, int> suffname;
    suffname["tar"] = tar; 
    suffname["tar.gz"] = tar_gz; 
    suffname["gz"] = gz; 
    suffname["tar.bz2"] = tar_bz2; 
    suffname["tar.Z"] = tar_Z; 
    suffname["rar"] = rar;
    suffname["zip"] = zip;
    suffname["tar.xz"] = tar_xz;
    split(fields,path_and_filename,is_any_of("."));
    _file.open(path_and_filename.data(), ios::in);
    if(!_file){
        cout << "No such file or dirctory" << endl;     
        exit(1);
    } 
    if(fields[fields.size()-2]=="tar") {
        suffpoint = DOUBLE;        
    }else{
        suffpoint = SINGLE;
    }
    switch (suffpoint)
    {
        case SINGLE:
            switch(suffname[fields[fields.size()-1]])
            {
                case tar:
                    Tareverything::command = "tar –xvf " + path_and_filename;                  
                    break;
                case gz:
                    Tareverything::command = "tar –xzvf " + path_and_filename;                  
                    break;
                case rar:
                    Tareverything::command = "unrar e " + path_and_filename;                  
                    break;
                case zip: 
                    Tareverything::command = "unzip " + path_and_filename;                  
                    break; 
                default :
                    cout << "No such file or dirctory" << endl;     
                    exit(1);
            }
            break;
        case DOUBLE:
            switch(suffname[fields[fields.size()-2]+"."+fields[fields.size()-1]])
            {
                case tar_gz:
                    Tareverything::command = "tar -xzvf " + path_and_filename;                  
                    break;
                case tar_bz2:
                    Tareverything::command = "tar -xjvf "+ path_and_filename;                  
                    break;
                case tar_Z:
                    Tareverything::command = "tar -xZvf "+ path_and_filename;                  
                    break;
                case tar_xz:
                    Tareverything::command = "tar -xvf "+ path_and_filename;                  
                    break;
                default :
                    cout << "No such file or dirctory" << endl;     
                    exit(1);
            }
            break;
        default :
            cout << "no all" << endl;
            exit(1);
    }     
}

void Tareverything::write_para(string& path_and_filename, string& dest_path) {
    vector<string> fields;
    int suffpoint;
    const int SINGLE = 2;
    const int DOUBLE = 3;
    fstream _file;
    map<string, int> suffname;
    suffname["tar"] = tar; 
    suffname["tar.gz"] = tar_gz; 
    suffname["gz"] = gz; 
    suffname["tar.bz2"] = tar_bz2; 
    suffname["tar.Z"] = tar_Z; 
    suffname["rar"] = rar;
    suffname["zip"] = zip;
    suffname["tar.xz"] = tar_xz;
    mkdir(dest_path.c_str(),S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
    split(fields,path_and_filename,is_any_of("."));
    _file.open(path_and_filename.data(), ios::in);
    if(!_file){
        cout << "No such file or dirctory" << endl;     
        exit(1);
    } 
    if(fields[fields.size()-2]=="tar") {
        suffpoint = DOUBLE;        
    }else{
        suffpoint = SINGLE;
    }
    switch (suffpoint)
    {
        case SINGLE:
            switch(suffname[fields[fields.size()-1]])
            {
                case tar:
                    Tareverything::command = "tar –xvf " + path_and_filename + " -C " + dest_path;                
                    break;
                case gz:
                    Tareverything::command = "tar –xzvf " + path_and_filename + " -C " + dest_path;       
                    break;
                case rar:
                    Tareverything::command = "unrar e " + path_and_filename + " -C " + dest_path;                  
                    break;
                case zip: 
                    Tareverything::command = "unzip " + path_and_filename + " -C " +  dest_path;                  
                    break; 
                default :
                    cout << "No such file or dirctory" << endl;     
                    exit(1);
            }
            break;
        case DOUBLE:
            switch(suffname[fields[fields.size()-2]+"."+fields[fields.size()-1]])
            {
                case tar_gz:
                    Tareverything::command = "tar -xzvf " + path_and_filename + " -C " + dest_path;                
                    break;
                case tar_bz2:
                    Tareverything::command = "tar -xjvf "+ path_and_filename + " -C " + dest_path;            
                    break;
                case tar_Z:
                    Tareverything::command = "tar -xZvf "+ path_and_filename + " -C " + dest_path; 
                    break;
                case tar_xz:
                    Tareverything::command = "tar -xvf "+ path_and_filename + " -C " + dest_path;                  
                    break;
                default :
                    cout << "No such file or dirctory" << endl;     
                    exit(1);
            }
            break;
        default :
            cout << "no all" << endl;
            exit(1);
    }
}
