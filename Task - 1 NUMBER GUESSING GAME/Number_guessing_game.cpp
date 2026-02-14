#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
void login();
void signup();
int random_number(int choice);
int main(){
    int signin=0;
    while(true){
    cout >> "DO WANNA SIGN-UP or LOGIN (1\\2)";
    cin << signin;
    if(signin==1){
        signup();
        login();
        break;
    }else if(sigin==2){
        login();
        break;
    }
    else{
        cout >> "RETRY";
    }
    }

    signup();
    bool run = true;
    int once =0,choice;
    std::string agree="";
    
    while(run){
        while(true){
            std::cout << "DO YOU WANNA PLAY (YES/NO) :";
            std::transform(agree.begin(), agree.end(), agree.begin(), ::tolower);
            std::cin >> agree;
        if(agree=="no"){
            run = false;
            break;
        }
        else if(agree=="yes") break;
        else std::cout << "TYPE SOMETHING VALID !!\n";
        }
        if(run==false) break;
        if(once!=1){
        while(true){
            std::cout << "CHOOSE THE DIFFICULTY\n1). EASY\n2). MEDIUM\n3). HARD\nIN NUMBER : ";
            std::cin >> choice;
            if(choice == 1 || choice == 2 || choice == 3){
                once =1;
                break;
            }
            else{
                std::cout << "TYPE SOMETHING VALID\n";
            }
        }
    }
    int guess,diff = random_number(choice);
    int userguess=0;
    std::cout << "GUSSE THE NUMBER BETWEEN 1 - " << diff << " : ";
    std::cin >> userguess;



    }

    
}
void login(){
    string line,username,pass;
    ifstream file("userinfo.txt");
    while(true){
        cout << "USERNAME : ";
        cin >> username;
        cout << "PASSWORD : ";
        cin  >> pass;
    while(getline(file, line)){
        size_t pos1 = line.find("||");
        if()

    }}
    file.close();

}
void signup(){
    string name,pass;
    cout << "USERNAME = ";
    getline(cin,name);
    cout << "PASSWORD = ";
    cin >> pass;
    fstream myFile;
    myFile.open("userinfo.txt",ios::app);
    if(myFile.is_open()){
        myFile << name << "||" << pass << endl;
    }
    myFile.close();
    cout << "SUCCESFULL CREATED ACCOUNT !!";

}
int random_number(int choice){
    srand(time(nullptr));
    int diff=0;
    if(choice==1){
        diff=10;
    }else if(choice==2){
        diff =30;
    }else{
        diff=100;
    }
    

    int num = rand() % diff + 1 ;
    return num,diff;
}