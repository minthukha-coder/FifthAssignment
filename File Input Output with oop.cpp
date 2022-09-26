#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class MyClass{
private:
    int passcode;
    double amount;

public:
    int id;
    char name[20];
    int age;
    string location;
    int pPasscode;
    double aAmount;
    void addData();
    void display();
    void findData();
    void update();
    void setPasscode(int p);
    void setAmount(double a);
};
    void MyClass::setPasscode(int p){
        passcode = p;
    }

    void MyClass::setAmount(double a){
        amount = a;
    }


    void MyClass::addData(){

    cout << "Please enter your id: ";
    cin >> id;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your age: ";
    cin >> age;

    cout << "Please enter your passcode: ";
    cin >> passcode;

    cout << "Please enter your amount: ";
    cin >> amount;

    cout << "Please enter your location: ";
    cin >> location;

    fstream fout;
    fout.open("006testw.txt",ios::app);


    fout << id << " " << name << " " << age << " " << passcode << " " << amount << " " << location << endl;
    fout.close();
    }

    void MyClass::display(){
    ifstream read;
    read.open("006testw.txt",ios::in);
    if (!read){
        cout << "File can't reading";
    }else{
        while(1){
        string s;
        if (!getline(read,s)){
            break;
        }else{
        cout << s << endl;
        }
    }

    }
     read.close();
    }

    void MyClass::findData(){
        MyClass obj2[10];
        char newName[10];
        int found = 0;
        int i = 0;
        cout << "Please enter name to find: ";
        cin >> newName;
    ifstream read;
    read.open("006testw.txt",ios::in);
    for (i = 0; i < 10;i++){
    read >> obj2[i].id >> obj2[i].name >> obj2[i].age >> obj2[i].passcode >> obj2[i].amount >> obj2[i].location;
    if (read.is_open()){
        if(strcmp(obj2[i].name,newName) == 0){
            found = 1;
        cout << obj2[i].id << " " << obj2[i].name << " " << obj2[i].age << " " << obj2[i].passcode << " " << obj2[i].amount << " " << obj2[i].location << endl;
        }
    }
    }

    if (found == 0){
        cout << "Data not found";
    }
    read.close();
    }

    void MyClass::update(){
        MyClass obj3[10];
        int i = 0;
        int ch = 0;
        int found = 0;
    char uName[20];
    cout << "Please enter name to update: ";
    cin >> uName;

    ifstream read;
    read.open("006testw.txt",ios::in);
    for (i = 0;i < 10;i++){
     read >> obj3[i].id >> obj3[i].name >> obj3[i].age >> obj3[i].passcode >> obj3[i].amount >> obj3[i].location;
    if (strcmp(obj3[i].name,uName) == 0){
        found = 1;

        cout << endl << "What do you want to change?"<< endl;
        cout << "If you want to change name / Press 1:" << endl;
        cout << "If you want to change age / Press 2:" << endl;
        cout <<"If you want to change password / Press 3:" << endl;
        cout << "If you want to change amount / Press 4:" << endl;
        cout << "If you want to change location / Press 5:" << endl;
        cin >> ch;

    if (ch == 1){
        cout << "Please enter new name: ";
        cin >> obj3[i].name;
        cout << obj3[i].id << " " << obj3[i].name << " " << obj3[i].age << " " << obj3[i].passcode << " " << obj3[i].amount << " " << obj3[i].location << endl;
    }

    if (ch == 2){
        cout << "Please enter new age: ";
        cin >> obj3[i].age;
        cout << obj3[i].id << " " << obj3[i].name << " " << obj3[i].age << " " << obj3[i].passcode << " " << obj3[i].amount << " " << obj3[i].location << endl;
    }

    if (ch == 3){
        cout << "Please enter new password: ";
        cin >> obj3[i].passcode;
        cout << obj3[i].id << " " << obj3[i].name << " " << obj3[i].age << " " << obj3[i].passcode << " " << obj3[i].amount << " " << obj3[i].location << endl;
    }

    if (ch == 4){
        cout << "Please enter new amount: ";
        cin >> obj3[i].amount;
        cout << obj3[i].id << " " << obj3[i].name << " " << obj3[i].age << " " << obj3[i].passcode << " " << obj3[i].amount << " " << obj3[i].location << endl;
    }
    if (ch == 5){
        cout << "Please enter new location: ";
        cin >> obj3[i].location;
        cout << obj3[i].id << " " << obj3[i].name << " " << obj3[i].age << " " << obj3[i].passcode << " " << obj3[i].amount << " " << obj3[i].location << endl;

    }

    }

    }

    if (found == 0){
        cout << "Data not found" << endl;
    }
    read.close();
}








int main(){

    MyClass obj[10];
    int pPasscode;
    double aAmount;
    int i = 0;
    int uPress = 0;

    obj[i].setPasscode(pPasscode);
    obj[i].setAmount(aAmount);
    cout << "Firstly you have to create file " << endl;
    while(1){
    cout << "\nIf you want to insert data / Press 1\nAfter inserting you have to reload" << endl;
    cout << "If you want to display data / Press 2"<< endl;
    cout << "If you want to find data / Press 3" << endl;
    cout << "If you want to update / Press 4 " << endl;
    cout << "If you want to reload or exit / Press 5 " << endl;
    cin >> uPress;
    if (uPress == 1){
        for (i = 0;i < 10;i++){
    obj[i].addData();
    break;
    }
    }

    if (uPress == 2){
    ifstream read;
    read.open("006testw.txt",ios::in);
    read >> obj[i].id >> obj[i].name >> obj[i].age >> obj[i].pPasscode >> obj[i].aAmount >> obj[i].location;
    if (read.is_open()){
        if (read.eof()){
            cout << "Database is empty" << endl;
        }else{
            obj[i].display();
        }
        }
        read.close();
        }


    if (uPress == 3){
        ifstream read;
    read.open("006testw.txt",ios::in);
    read >> obj[i].id >> obj[i].name >> obj[i].age >> obj[i].pPasscode >> obj[i].aAmount >> obj[i].location;
    if (read.is_open()){
        if (read.eof()){
            cout << "Database is empty" << endl;
        }else{
            obj[i].findData();
        }
        }
        read.close();
        }



    if (uPress == 4){
    ifstream read;
    read.open("006testw.txt",ios::in);
    read >> obj[i].id >> obj[i].name >> obj[i].age >> obj[i].pPasscode >> obj[i].aAmount >> obj[i].location;
    if (read.is_open()){
        if (read.eof()){
            cout << "Database is empty" << endl;
        }else{
            obj[i].update();
        }
    }
    read.close();
    }

    if (uPress == 5){
        exit(0);
    }

    }

return 0;
}











