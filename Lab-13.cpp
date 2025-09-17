// COMSC-210 | Lab 13 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
const int Size=30;

// I decided to use a reference to the grocery list in order to not make a new array and also make it const so that nothing can be changed 
//and then print out whatever was inside the array.
// printList() takes a reference to a string array.
void printList(vector<string> &list){
    cout<<"Printing List:"<<endl;
    for(int i=0;i<Size;i++){
        cout<<i+1<<"#: "<<list[i]<<", ";
    }
    cout<<endl;
}

//In my main code I made a grocery list program which has several functions for manual input, clearing, reading from a file, and exiting the program.
int main(){
    vector<string> GroceryList;
    string filepath;
    
    
    string response;
    while(true){
        cout<<"Welcome to the Grocery List, Enter F to enter a file path or for Manual Input Enter M"<<endl;
        cout<<"Other functions enter L to list the Grocery List,enter E to empty the list, Enter X to exit"<<endl;
        getline(cin,response);
        if(response=="F"){
            cout<<"Please enter file path"<<endl;
            getline(cin,filepath);
            ifstream file(filepath);
            if(!file){
                cout<<"error opening file, please try again"<<endl;
            }
            else{
                cout<<"file opened"<<endl;
                cout<<"Entering data now...."<<endl;
                string line;
                while(getline(file,line)){
                GroceryList.push_back(line);
                }
            }
        }
        if(response=="M"){
            string hold;
            for(int i=0;i<Size;i++){
                cout<<"Enter Item for #"<<i+1<<endl;
                getline(cin,hold);
                GroceryList.push_back(hold);
            }   
        }
        if(response=="L"){
         printList(GroceryList);
        }
        if(response=="E"){
            GroceryList.clear();
            cout<<"GroceryList set to blank"<<endl;
        }
        if(response=="X"){
            break;
        }
    }
    return 1;
}
