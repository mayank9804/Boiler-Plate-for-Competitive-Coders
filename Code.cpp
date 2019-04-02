#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

string fixString(string t){
    size_t start_pos = 0;
    while((start_pos=t.find("\\n",start_pos))!=string::npos){
        t.replace(start_pos,2,"\n");
    }
    return t;
}
int main(int argc, char const *argv[]){
    
    if(argc!=2){
        cout<<"Too few arguments\n";
        cout<<"Usage: ./filecreate [FILENAME]\n";
        return 0;
    }else{
        
        string temp="";
        string t="";
        fstream content;
        content.open("getContent.txt",ios::in);
        while(getline(content,t)){
            t=fixString(t);
            temp+=t;
        }
        content.close();
        string fileName = argv[1];
        fileName+=".cpp";
        fstream o(fileName,ios::out);
        o<<temp;
        o.close();
        string tempFileName="";
        for(int i=0;i<fileName.size();i++){
            if(fileName[i]!=32){
                tempFileName+=fileName[i];
            }else{
                tempFileName+="\\ ";
            }
        }
        
        string cmd = "code "+tempFileName;

        system(cmd.c_str());
    }
    return 0;
}

