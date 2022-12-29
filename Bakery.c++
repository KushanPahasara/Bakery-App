#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
   
    void login();
    

    login();
    
}

void login()
{
    string username, usernam;
	int password, passcode;
	cout<<"\t\t\t\t\t..WEL COME TO PANADERIA BAKERY..";
    cout << "\n\n\t\t\t\t\t\tEnter user name \n\t\t\t\t\t\t   ";
    cin >> username;
    cout << "\n\n\t\t\t\t\t\tEnter password  \n\t\t\t\t\t\t   ";
    cin >> password;
    ifstream  login;
    login.open("datafile.txt");
    login >> usernam >> passcode;
    if ((usernam == username) && (passcode == password))
    {
        cout << "\n\n\t\t\t\t\t\tlogin succesfully\n" << endl;
        void menu();
        menu();

    }
    else {
        cout << "\n\n\t\t\t\t\tInvalid User... Please try again\n\n";
        void login();
        login();

    }
    
}

void menu()
{
    system("cls");
    int input;
    
    cout << "\t\t\t\t\t\t1. Our Item list" << endl;
    cout << "\n\t\t\t\t\t\t2. Our Package List" << endl;
    cout << "\n\t\t\t\t\t\t3. Add new item" << endl;
    cout << "\n\t\t\t\t\t\t4. Add new package" << endl;
    cout << "\n\t\t\t\t\t\t5. Search Item" << endl;
    cout << "\n\t\t\t\t\t\t6. Search Package" << endl;
    cout << "\n\t\t\t\t\t\t7. Help" << endl;
    cout << "\n\t\t\t\t\t\t8. Exit" << endl;

    cout << "\n\t\t\t\t\t\t   select \n\t\t\t\t\t\t     ";
    cin >> input;
    switch (input)
    {
    
    case 1:void itemlist(); itemlist(); break; 
    case 2:void packList(); packList(); break;
    case 3:void addItem(); addItem(); break;
    case 4:void package(); package(); break;
    case 5:void searchItem(); searchItem(); break; 
    case 6:void searchPack(); searchPack(); break;
    case 7:void help(); help(); break; 
    case 8:void exit(); exit(); break; 
    default:cout << "invalid number given...." << endl;
    }
}



void itemlist()
{
	system("cls");
    string item;
    int itemCode;
    float price;
    ifstream listofItem;
    listofItem.open("list.txt");
    listofItem >> itemCode >> item >> price;
    cout <<"\t\t\t\t\t\t"<<"Id "    << "  " <<"Item "<< " " << "Price\n"<<endl;
    while (!listofItem.eof())
    {
        
        cout <<"\t\t\t\t\t\t"<<left <<setw(10)<< itemCode << setw(10) << item << " " << price  <<endl;
        listofItem >> itemCode >> item >> price;
    }
    listofItem.close();
    system("pause");
    void menu();
    menu();
    
}

  void packList()
{
    system("cls");
    ifstream packFile;
    packFile.open("packfile.txt");
    int pCode;
    string pName;
    float pPrice;
    packFile >> pCode >> pName >> pPrice;
    cout <<"\t\t\t\t\t\t"<<"Id "    << "  " <<" packages "<< " " << "Price\n"<<endl;
    while (!packFile.eof())
    {

        cout <<"\t\t\t\t\t\t"<<left <<setw(10)<< pCode <<  setw(10) << pName << "      " << pPrice << endl;
        packFile >> pCode >> pName >> pPrice;
    }
    packFile.close();
    system("pause");
    void menu();
    menu();
}
void addItem()
{
	int iCode;
    string iName;
    float iprice;
    system("cls");
    ofstream addfile;
    cout << "Please add new item" << endl;
    cout << "enter item code : ";
    cin >> iCode;
    cout << "enter item name : ";
    cin >> iName;
    cout << "enter item price : ";
    cin >> iprice;
    addfile.open("list.txt", ios::app);
    addfile << iCode << "\t" << iName << "\t" << iprice << endl;
    addfile.close();
    system("pause");
    void menu();
    menu();
}
  void package()
{
    system("cls");
    cout << "\t\tPackages" << endl;
    ofstream outFile;
    outFile.open("packfile.txt",ios::app);
    int packageCode;
    string packageName;
    float packagePrice;
    cout << "Enter package code : "; cin >> packageCode;
    cout << "Enter package name : "; cin >> packageName;
    cout << "Enter package price : "; cin >> packagePrice;
    outFile << packageCode << "\t" << packageName << "\t" << packagePrice << "\t" << endl;

    system("pause");
    void menu();
    menu();
}
  
void searchItem()
{
    system("cls");
    cout << "Search items" << endl;
    ifstream listfile;
    listfile.open("list.txt");
   
    int code,Input;
    string itemName;
    float price;
    listfile >> code >> itemName >> price;
    
    cout << "Enter Item code : ";
    cin >> Input;
    
    if (listfile)
        while (listfile) {
            if (code == Input)
            {
                cout << "Item Code : " << code << endl;
                cout << "Item Name :" << itemName << endl;
                cout << "Price     :" << price << endl;
            }
            listfile >> code >> itemName >> price;
        }
       
    listfile.close();
   
    system("pause");
    void menu();
    menu();
}
void searchPack()
{
    system("cls");
    cout << "Search packages" << endl;
    ifstream pacInfile;
    pacInfile.open("packfile.txt");
    int  pacCode, pacCode1;
    string  pacItem;
    float  pacPrice;
    pacInfile >> pacCode >> pacItem >> pacPrice;
    cout << "Enter package code : ";
    cin >> pacCode1;
    if (pacInfile)
        while (pacInfile) {
            if (pacCode1 == pacCode)
            {
                cout << "Package Code : " << pacCode << endl;
                cout << "Package Name :" << pacItem << endl;
                cout << "Price     :" << pacPrice << endl;
            }
            pacInfile >> pacCode >> pacItem >> pacPrice;
        } 
		
    pacInfile.close();
    system("pause");
    void menu();
    menu();

}
void help()
{
    system("cls");
    cout << "\t\t\t\t\t\tHelp" << endl;
    cout<< "To access the main menu, first provide the proper name and password."<<endl;
	cout<<"The services we have given will thereafter be visible on the main menu.\n "<<endl;
    cout<<"No. 1 contains a list of all of our item.\n "<<endl;
    cout<<"No. 2 has a list of all of our packages.\n" <<endl;
    cout<<"No. 3 considers ease of insertion of new items.\n "<<endl;
    cout<<"No. 4 makes it easy of insertion in new packages as well.\n"<<endl;
    cout<<"No. 5 and 6 make it simple to locate all of the goods and packages you want.\n "<<endl;
    cout<<"You may return to the login page by clicking Exite.\n"<<endl;

    system("pause");
    void menu();
    menu();


}

void exit()
{
    system("cls");
    void login();

    login();

}


