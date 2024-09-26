#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>
#include<set>

#define alloc 1
#define nonalloc 0

using namespace std;

void parse();

int main(int argc, char* argv[]){
    string s = argv[1];
    cout<<"reading from file: "<<s<<endl;
    vector<string> lines;
    ifstream filein(s);
    if(!filein.is_open()){
        cerr<<"file not found,check and specify again"<<endl;
        return 1;
    }
    string line;
    while (getline(filein, line)) { 
        if(!(line == "") && line[0] != '#'){
            int i=0;
            while(line[i]== ' ' || line[i] == '\t'){
                i++;
            }
            int j = 0;
            int len = line.length()-1;
            while(j <= len){
                if(line[j] == '#'){
                    break;
                }j++;
            }
            lines.push_back(line.substr(i,j-i));
        }
    }
    filein.close();
    vector<string> data;
    vector<string> text;
    if(lines[0]== ".data"){
        u_int32_t i=1;
        while(lines[i] != ".text"){
            data.push_back(lines[i]);
            i++;
        }i++;
        while(i < lines.size()){
            text.push_back(lines[i]);
            i++;
        }
    }else{
        u_int32_t i=1;
        while(i < lines.size()){
            text.push_back(lines[i]);
            i++;
        }
    }
    // data contains the data lines, text contains the text segment.
    map<string,vector<pair<string,int>>*> functions;
    set<pair<string,int>> labels_text;
    // functions should contain the lines of the code and line numbers wrt to label in that order
    //the labels_text should contain the lines of the labels with line number in that order.
    //in essense, the functions shud contain the offsets wrt labels, and labels_text contain the global offsets in the file.
    vector<pair<string,int>>* curr = nullptr;
    string currfunc = "";
    int offs = 0;
    for(int i = 0;i < text.size();i++){
        if(text[i].back() == ':'){
            vector<pair<string,int>>* temp = new vector<pair<string,int>>;
            functions[text[i]] = temp;
            curr = temp;
            currfunc = text[i];
            offs = i*4;
        }else{
            curr->push_back(make_pair(currfunc,i*4 - offs));
        }
    }


}