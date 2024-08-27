#include<iostream>
#include<string>
#include<iomanip>
#include"Guest.cpp"
#include"Guest.h"
#include"Member.cpp"
#include"Member.h"
#include"Admin.cpp"
#include"Admin.h"
#include"Menu.h"
#include"Menu.cpp"
using namespace std;

void SearchT(Collection* , string );
Member* MLogin(vector<Member*>);
Admin* ALogin(vector<Admin*>);

enum ActionType
{   
    SEARCH_TITLE, SEARCH_SERIAL, LOGOUT, EXIT_PROGRAM,
    SAMPLE_BOOK, READ_FREE, REGISTED, ADMIN_LOGIN, MEMBER_LOGIN,
    BOOK_DISPLAY, COLLECION_DISPLAY, SUBLIST, SUBSCRIBED, UNSUBLIST, BORROW, RETURN, BORROW_LIST,
    NEW_ADMIN, CREATE_BOOK, HIDE_BOOK, SHOW_BOOK, EDIT_BOOK, DELETE_BOOK,
    CREATE_COLLECTION, ADD_BOOK, REMOVE_BOOK, DELETE_COLLECTION,
};

int main()
{
//User Data======================================================================================
    Admin* TempA;
    Member* TempM;
    Guest* UGuest = new Guest();

    Member* Mem1 = new Member("aladin", "12345678", "392728393", "jOHN", 2011, 2020);
    Member* Mem2 = new Member("genor", "genor1", "8633545", "than", 2011, 2020);
    Member* Mem3 = new Member("123456", "12121212", "726265673", "anna", 2011, 2020);
    vector<Member*> MemList;
    MemList.push_back(Mem1);
    MemList.push_back(Mem2);
    MemList.push_back(Mem3);

    Admin* RootAdmin = new Admin("root", "root", "83724847", "linda");
    vector<Admin*> AdminList;
    AdminList.push_back(RootAdmin);

//Book Data=====================================================================================
    Collection* TempC;
    Book* TempB;
    Book* book1 = new Book("Math_12", "000001", "Homer", 217, 20, "Education", true, true);
    Book* book2 = new Book("Geography", "000002", "Lewis", 485, 20, "Education", true, true);
    Book* book3 = new Book("Ravent", "000003", "James", 1982, 50, "Fiction", true, true);
    Book* book4 = new Book("Runete", "000004", "Amanda", 2042, 50, "Adventure", true, true);
    Book* book5 = new Book("Two_Trees", "000005", "Henry", 3044, 50, "Psychological", true, true);

    Collection* AllBook = new Collection(100001, "Library's Book");
    AllBook->AddBook(book1);
    AllBook->AddBook(book2);
    AllBook->AddBook(book3);
    AllBook->AddBook(book4);
    AllBook->AddBook(book5);
    AllBook->AddSub(Mem1);
    AllBook->AddSub(Mem2);
    AllBook->AddSub(Mem3);

    Collection* Samples = new Collection(100002, "Samples Books");
    Samples->AddBook(book1);
    Samples->AddBook(book2);
    Samples->AddBook(book3);
    Samples->AddSub(Mem1);
    Samples->AddSub(Mem2);
    Samples->AddSub(Mem3);
    //Samples->RemoveSub(Mem1);

    vector<Collection*> ListCollection;
    ListCollection.push_back(AllBook);
    ListCollection.push_back(Samples);

//Menu Data======================================================================================
    Menu* SearchTitle = new Menu("Title search", "Searching for title book", SEARCH_TITLE);
    Menu* SearchSerial = new Menu("Serial search", "Searching for serial book", SEARCH_SERIAL);
    Menu* Logout = new Menu("Log Out", "", LOGOUT);

//Guest Menu=======
    Menu* GuestMenu = new Menu("Guest Menu", "You are logging in as Guest");
    Menu* FreeSample = new Menu("Free Sample", "Free Sample book");
    Menu* MemberLogin = new Menu("Member Login", "Logging in for Member", MEMBER_LOGIN);
    Menu* AdminLogin = new Menu("Admin Login", "Logging in for Admin", ADMIN_LOGIN);
    Menu* Register = new Menu("Register", "Regist new member account", REGISTED);
    Menu* Exitmenu = new Menu("Exit", "See you next time", EXIT_PROGRAM);
    GuestMenu->AddSubMenu(FreeSample);
    GuestMenu->AddSubMenu(SearchTitle);
    GuestMenu->AddSubMenu(SearchSerial);
    GuestMenu->AddSubMenu(MemberLogin);
    GuestMenu->AddSubMenu(AdminLogin);
    GuestMenu->AddSubMenu(Register);
    GuestMenu->AddSubMenu(Exitmenu);

    Menu* FreeDisp = new Menu("Display Free Sample", "",SAMPLE_BOOK);
    Menu* ReadFS = new Menu("Read Free Samples", "", READ_FREE);
    FreeSample->AddSubMenu(FreeDisp);
    FreeSample->AddSubMenu(ReadFS);
    FreeSample->AddSubMenu(GuestMenu);

//Mmeber Menu=======
    Menu* MemberMenu = new Menu("Member Menu", "You are logging in as Member");
    Menu* BookDisplay = new Menu("All Books Available", "", BOOK_DISPLAY);
    Menu* AllList = new Menu("All Collection", "All collection in the List", COLLECION_DISPLAY);
    Menu* DisplayList = new Menu("Subcribed List", "You Subcribed Collections", SUBLIST);
    Menu* Subscribe = new Menu("Subscribe", "Subscribing to Collections", SUBSCRIBED);
    Menu* UnSubList = new Menu("Unsubcribe", "Unsubscribing to Collections", UNSUBLIST);
    Menu* BorrowB = new Menu("Borrowing Books", "", BORROW);
    Menu* ReturnB = new Menu("Returning Books", "", RETURN);
    Menu* BorrowList = new Menu("Borrow List", "", BORROW_LIST);
    MemberMenu->AddSubMenu(BookDisplay);
    MemberMenu->AddSubMenu(SearchTitle);
    MemberMenu->AddSubMenu(SearchSerial);
    MemberMenu->AddSubMenu(AllList);
    MemberMenu->AddSubMenu(DisplayList);
    MemberMenu->AddSubMenu(Subscribe);
    MemberMenu->AddSubMenu(UnSubList);
    MemberMenu->AddSubMenu(BorrowList);
    MemberMenu->AddSubMenu(BorrowB);
    MemberMenu->AddSubMenu(ReturnB);
    MemberMenu->AddSubMenu(Logout);

//Admin Menu=======
    Menu* AdminMenu = new Menu("Admin Menu", "You are logging in as Admin");
    Menu* EditBook = new Menu("Edit Book", "Editting books");
    Menu* EditCollection = new Menu("Edit Collection", "Editting Collection");
    Menu* CreateA = new Menu("Create Admin", "Creating new Admin Account", NEW_ADMIN);
    AdminMenu->AddSubMenu(CreateA);
    AdminMenu->AddSubMenu(BookDisplay);
    AdminMenu->AddSubMenu(SearchTitle);
    AdminMenu->AddSubMenu(SearchSerial);
    AdminMenu->AddSubMenu(EditBook);
    AdminMenu->AddSubMenu(EditCollection);
    AdminMenu->AddSubMenu(Logout);

    Menu* CreatB = new Menu("Add New Book","", CREATE_BOOK);
    Menu* HideBook = new Menu("Hide Book", "", HIDE_BOOK);
    Menu* ShowBook = new Menu("Show Book", "", SHOW_BOOK);
    Menu* DeleteB = new Menu("Deleting Book", "", DELETE_BOOK);
    Menu* EditB = new Menu("Change Book Information", "", EDIT_BOOK);
    EditBook->AddSubMenu(CreatB);
    EditBook->AddSubMenu(HideBook);
    EditBook->AddSubMenu(ShowBook);
    EditBook->AddSubMenu(DeleteB);
    EditBook->AddSubMenu(EditB);
    EditBook->AddSubMenu(AdminMenu);

    Menu* CreateC = new Menu("Create Collection","", CREATE_COLLECTION);
    Menu* AddB = new Menu("Add Book","", ADD_BOOK);
    Menu* RemoveB = new Menu("Remove Book","", REMOVE_BOOK);
    Menu* DeleteC = new Menu("Delete Collection","", DELETE_COLLECTION);
    EditCollection->AddSubMenu(CreateC);
    EditCollection->AddSubMenu(AddB);
    EditCollection->AddSubMenu(RemoveB);
    EditCollection->AddSubMenu(DeleteC);
    EditCollection->AddSubMenu(AdminMenu);

//Display=========================================================================================
    Menu* currentMenu = GuestMenu;
    Guest* currentGuest = UGuest;
    Member* currentMember = MemList[0];
    Admin* currentAdmin = AdminList[0];
    User* currentUser = currentGuest;
    string searchT, searchS;
    string N, C;
    string choice;
    int sr;
    while(true){
        bool check = false;
        currentMenu->displayMenu();
        int opt = currentMenu->PromtOption();
        currentMenu = currentMenu->getSubMenu(opt);
        switch(currentMenu->getAction()){
            case -1:
                break;
            case SAMPLE_BOOK:
                cout<<"====="<<currentMenu->getName()<<"===== \n";
                Samples->ListBookDisplay(currentUser);
                currentMenu = FreeSample;
                break;
            case READ_FREE:
                cout<<"====="<<currentMenu->getName()<<"===== \n";
                currentUser->read();
                currentMenu = FreeSample;
                break;
            case MEMBER_LOGIN:
                currentMember = MLogin(MemList);
                currentUser = currentMember;
                if(currentUser->getAccessLevel() == member)
                currentMenu = MemberMenu;
                else currentMenu = GuestMenu;
                break;
            case SUBLIST:
                cout<<"=====Subcribed Collection====="<<endl;
                cout<<"------------------------------"<<endl;
                for(int i =0; i<ListCollection.size(); i++){
                    if(ListCollection[i]->checkSub(currentMember)){
                        cout<<setw(10)<<ListCollection[i]->getCollectionName()<<setw(10)<<ListCollection[i]->getCID()<<endl;
                    }
                }
                currentMenu = MemberMenu;
                break;
            case SUBSCRIBED:
                cout<<"Choose a Collection to Subscribe: Serial:"; cin>>sr;
                for(int i = 0; i<ListCollection.size(); i++){
                    if(ListCollection[i]->getCID()== sr){
                        ListCollection[i]->AddSub(currentMember);
                        check = true;
                    }
                }
                if (check==false) cout<<"No Collection found"<<endl;
                currentMenu = MemberMenu;
                break;
            case UNSUBLIST:
                cout<<"Choose a Collection to Unsubscribe: Serial:"; cin>>sr;
                for(int i = 0; i<ListCollection.size(); i++){
                    if(ListCollection[i]->getCID()== sr){
                        if(ListCollection[i]->checkSub(currentMember)){
                            ListCollection[i]->RemoveSub(currentMember);
                        }
                        else cout<<"Your are not subcribe to this collection"<<endl;
                    }
                }
                currentMenu = MemberMenu;
                break;
            case ADMIN_LOGIN:
                currentAdmin = ALogin(AdminList);
                currentUser = currentAdmin;
                if(currentUser->getAccessLevel() == admin)
                    currentMenu = AdminMenu;
                else { 
                    currentMenu = GuestMenu;
                    }
                currentMenu->displayMenu();
                break;
            case REGISTED:
                TempM = currentGuest->Register();
                MemList.push_back(TempM);
                currentMenu = GuestMenu;
                break;
            case BOOK_DISPLAY:
                switch(currentUser->getAccessLevel()){
                    case member:
                        for(int i = 0; i<ListCollection.size(); i++){
                            if(ListCollection[i]->checkSub(currentMember)){
                                cout<<"========"<<ListCollection[i]->getCollectionName()<<"========"<<endl;
                                ListCollection[i]->ListBookDisplay(currentUser);
                            }
                        }
                        currentMenu = MemberMenu;
                        break;
                    case admin:
                        for(int i = 0; i<ListCollection.size(); i++){
                            cout<<"========"<<ListCollection[i]->getCollectionName()<<"========"<<endl;
                            ListCollection[i]->ListBookDisplay(currentUser);
                        }
                        currentMenu = AdminMenu;
                        break;
                    default:
                        break;
                }
                break;
            case COLLECION_DISPLAY:
                cout<<"=======All Library Collection======="<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<setw(20)<<"Collection"<<setw(10)<<"Serial"<<endl;
                for(int i=0; i<ListCollection.size(); i++){
                    cout<<setw(20)<<ListCollection[i]->getCollectionName()<<setw(10)<<ListCollection[i]->getCID()<<endl;
                }
                currentMenu = MemberMenu;
                break;
            case SEARCH_TITLE:
                cout<<"Enter the book title you want to search: ";
                cin>>searchT;
                switch(currentUser->getAccessLevel()){
                    case admin:
                        for(int i = 0; i<ListCollection.size(); i++){
                            cout<<"========"<<ListCollection[i]->getCollectionName()<<"========"<<endl;
                            TempB = ListCollection[i]->getBookT(searchT);
                        }
                        currentMenu = AdminMenu;
                        break;
                    case member:
                        for(int i = 0; i<ListCollection.size(); i++){
                            if(ListCollection[i]->checkSub(currentMember)){
                                cout<<"========"<<ListCollection[i]->getCollectionName()<<"========"<<endl;
                                TempB = ListCollection[i]->getBookT(searchT);
                            }
                        }
                        currentMenu = MemberMenu;
                        break;
                    case guest:
                        cout<<"========"<<Samples->getCollectionName()<<"========"<<endl;
                        Samples->getBookT(searchT);
                        currentMenu = GuestMenu;
                        break;
                    default:
                        break;   
                }
                break;
            case SEARCH_SERIAL:
                cout<<"Enter the book serial you want to search: ";
                cin>>searchS;
                switch(currentUser->getAccessLevel()){
                    case admin:
                        for(int i = 0; i<ListCollection.size(); i++){
                            cout<<"========"<<ListCollection[i]->getCollectionName()<<"========"<<endl;
                            TempB = ListCollection[i]->getBookS(searchS);
                            }
                        currentMenu = AdminMenu;
                        break;
                    case member:
                        for(int i = 0; i<ListCollection.size(); i++){
                            if(ListCollection[i]->checkSub(currentMember)){
                                cout<<"========"<<ListCollection[i]->getCollectionName()<<"========"<<endl;
                                TempB = ListCollection[i]->getBookS(searchS);
                            }
                        }
                        currentMenu = MemberMenu;
                        break;
                    case guest:
                        cout<<"========"<<Samples->getCollectionName()<<"========"<<endl;
                        Samples->getBookS(searchS);
                        currentMenu = GuestMenu;
                        break;
                    default:
                        break;   
                }
                break;
            case BORROW:
                cout<<"Enter the book title you want to Borrow: ";
                cin>>searchT;
                for(int i=0; i<ListCollection.size(); i++){
                    if(ListCollection[i]->checkSub(currentMember)){
                        TempB = ListCollection[i]->getBookT(searchT);
                        currentMember->Borrow(TempB);
                        break;
                    }
                }
                currentMenu = MemberMenu;
                break;
            case RETURN:
                cout<<"Enter the book title you want to return: ";
                cin>>searchT;
                for(int i=0; i<ListCollection.size(); i++){
                    if(ListCollection[i]->checkSub(currentMember)){
                        TempB = ListCollection[i]->getBookT(searchT);
                        currentMember->Return(TempB);
                        break;
                    }
                }
                currentMenu = MemberMenu;
                break;
            case BORROW_LIST:
                currentMember->DisplayBorrowList();
                currentMenu = MemberMenu;
                break;
            case NEW_ADMIN:
                TempA = currentAdmin->CreateAdmin();
                AdminList.push_back(TempA);
                currentMenu = AdminMenu;
                break;
            case CREATE_BOOK:
                TempB = currentAdmin->CreateBook();
                AllBook->AddBook(TempB);
                currentMenu = EditBook;
                break;
            case HIDE_BOOK:
                cout<<"Enter the book title you want to Hide: ";
                cin>>searchT;
                for(int i=0; i<ListCollection.size(); i++){
                    TempB = ListCollection[i]->FindBook(searchT);
                    currentAdmin->hideBook(TempB);
                    break;
                }
                currentMenu = EditBook;
                break;
                break;
            case SHOW_BOOK:
                cout<<"Enter the book title you want to Show: ";
                cin>>searchT;
                for(int i=0; i<ListCollection.size(); i++){
                    TempB = ListCollection[i]->FindBook(searchT);
                    currentAdmin->showBook(TempB);
                    break;
                }
                currentMenu = EditBook;
                break;
            case EDIT_BOOK:
                cout<<"Enter the book title you want to Edit: ";
                cin>>searchT;
                for(int i=0; i<ListCollection.size(); i++){
                    TempB = ListCollection[i]->FindBook(searchT);
                    currentAdmin->editBook(TempB);
                    break;
                }
                currentMenu = EditBook;
                break;
            case DELETE_BOOK:
                cout<<"Enter the book title you want to Delete: ";
                cin>>searchT;
                for(int i=0; i<ListCollection.size(); i++){
                    TempB = ListCollection[i]->FindBook(searchT);
                    currentAdmin->deleteBook(TempB);
                    break;
                }
                currentMenu = EditBook;
                break;
            case CREATE_COLLECTION:
                cout<<"Enter new collection name: ";
                cin>>N;
                cout<<"Enter new collection id: ";
                cin>>sr;
                TempC = currentAdmin->CreateCollection(sr, N);
                ListCollection.push_back(TempC);
                cout<<"New Collection created"<<endl;
                currentMenu = EditCollection;
                break;
            case ADD_BOOK:
                currentMenu = EditCollection;
                break;
            case REMOVE_BOOK:
                currentMenu = EditCollection;
                break;
            case DELETE_COLLECTION:
                currentMenu = EditCollection;
                break;
            case LOGOUT:
                currentUser = currentGuest;
                currentMenu = GuestMenu;
                break;
            case EXIT_PROGRAM:
                cout<<"Exiting Program"<<endl;
                exit(0);
            default:
                cout<<"Default action"<<endl;
        }
        
  
    }
    for(int i=0; i<MemList.size(); i++){
        delete MemList[i];
    }
    for (int i = 0; i<AdminList.size(); i++){
        delete AdminList[i];
    }
    return 0;
}


Member* MLogin(vector<Member*> MList){
    bool check=false;
    string un, pw, choice;
    do{
        cout<<"Enter User Name: "; cin>>un;
        cout<<"Enter Password: "; cin>>pw;
        for(int i =0; i<MList.size(); i++){
            if(MList[i]->getUsername()== un){
                if(MList[i]->getPassword() == pw){
                    cout<<"Logging in success"<<endl;
                    check = true;
                    return MList[i];
                    break;
                }
            }
        }
        if(check == false){
            cout<<"Wrong password or user name"<<endl;
            cout<<"Do you want to try a again?(Y/N)";
            cin>>choice;
        }
    }
    while(choice == "y" || choice == "Y");

    Member* tempM;
    tempM->setAccessLevel(guest);
    return tempM;
}

Admin* ALogin(vector<Admin*> AList){
    bool check=false;
    string un, pw, choice;
    do{
        cout<<"Enter User Name: "; cin>>un;
        cout<<"Enter Password: "; cin>>pw;
        for(int i =0; i<AList.size(); i++){
            if(AList[i]->getUsername()== un){
                if(AList[i]->getPassword() == pw){
                    cout<<"Logging in success"<<endl;
                    check = true;
                    return AList[i];
                    break;
                }
            }
        }
        if(check == false){
            cout<<"Wrong password or user name"<<endl;
            cout<<"Do you want to try a again?(Y/N)";
            cin>>choice;
        }
    }
    while(choice == "y" || choice == "Y");

    Admin* tempA;
    tempA->setAccessLevel(guest);
    return tempA;
}

