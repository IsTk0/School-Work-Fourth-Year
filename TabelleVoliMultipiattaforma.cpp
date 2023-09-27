//Developed by Antonio Carbone 4Fi 25/09/2023 2023-2024

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

const int MAXFLIGHTS = 10;
const int LENGTHFLIGHTCODE = 5;
int indexAvaliableOnFlightTable[MAXFLIGHTS];
const int MAXSEATAVALIABLE = 184;

struct localTime{
    int hours, minutes;
};

struct flightTableList{
    string flightCode, destinationIATA;
    localTime flightDepartureTime;
    int seatAvailable;
}flightTable[MAXFLIGHTS];

void clearView(){
    try {
        system("cls");
    } catch (...) {
        system("clear");
    }
}

int checkTime(int hoursToCheck, int minutesToCheck){
    if (hoursToCheck > 24 || hoursToCheck < 0 || minutesToCheck > 60 || minutesToCheck < 0){
        cout << "\aI'm sorry but the time you entered cannot exist, we ask you to re-enter it." << endl; 
        return 0;
    }
    else{
        return 1;
    }
}

int checkFlightCodeLenght(string flightCodeToAnalyze){
    if (flightCodeToAnalyze.length() > 5){
        cout << "\aI'm sorry but the code you entered is longer than the expected 5 digits." << endl; 
        return 0;
    }
    else if (flightCodeToAnalyze.length() < 5){
        cout << "\aI'm sorry but the code you entered is shorter than the expected 5 digits." << endl; 
        return 0;
    }
    else{
        return 1;
    }
}

int checkSeatAvaliable(int seatAvaliableToCheck){
    if (seatAvaliableToCheck > MAXSEATAVALIABLE || seatAvaliableToCheck < 0){
        cout << "\aYou have entered a greater number of available places than the number of places that actually exist, please try again." << endl; 
        return 0;
    }
    else{
        return 1;
    }
}

string randomAlphanumberGnerator(int stringLength){
    const string ALPHANUM = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string randomString;
    srand(time(nullptr));
    for (int i = 0; i < stringLength; ++i) {
        randomString += ALPHANUM[rand() % ALPHANUM.size()];
    }
    return randomString;
}

int randomDigitsClock(char typeOfGeneration){
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr));
        initialized = true;
    }
    int randomTwoDigitsClock;
    if (typeOfGeneration == 'H')
        randomTwoDigitsClock = rand() % 12 + 1;
    else if (typeOfGeneration == 'M')
        randomTwoDigitsClock = rand() % 60 + 1;
    else if (typeOfGeneration == 'S')
        randomTwoDigitsClock = rand() % MAXSEATAVALIABLE + 1;
    return randomTwoDigitsClock;
}

string generateRandomIATA(){
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr));
        initialized = true;
    }
    string IATACode;
    string listOfIATACode[10] = {"JFK", "LAX", "LHR", "CDG", "DXB", "HND", "SIN", "PEK", "FRA", "AMS"};
    int randomIndex = rand() % 10;
    return IATACode = listOfIATACode[randomIndex];
}

void setupFlightTableFill(){
    clearView();
    cout << "! This function is perfectly placed for debugging and demonstration to the teacher\n! Enter n if you want to manually enter all the various parameters, otherwise for any other input entered they will be automatically filled in randomly" << endl;
    char choice; 
    cin >> choice;
    if (choice == 'n' || choice == 'N'){
        for (int i = 0; i < MAXFLIGHTS; i++){
            cout << "You are compiling the table with index in the database number: " << i << endl << endl;
            do{
                cout << "Insert flight code (5 alphanumeric digits): ";
                cin >> flightTable[i].flightCode;
            }while(checkFlightCodeLenght(flightTable[i].flightCode) != 1);
            cout << "Enter the destination of this flight (name or IATA code): ";
            cin >> flightTable[i].destinationIATA;
            do{
                cout << "Insert the local departure time (hours): ";
                cin >> flightTable[i].flightDepartureTime.hours;
                cout << "Insert the local departure time (minutes): ";
                cin >> flightTable[i].flightDepartureTime.minutes;
            }while(checkTime(flightTable[i].flightDepartureTime.hours, flightTable[i].flightDepartureTime.minutes) != 1);
            do{
                cout << "Enter the number of seats available on the flight: ";
                cin >> flightTable[i].seatAvailable;
            }while(checkSeatAvaliable(flightTable[i].seatAvailable) != 1);
            cout << "Flight schedule:" << flightTable[i].flightCode << "was completed successfully" << endl << endl;
        }
    }
    else{
        for (int i = 0; i < MAXFLIGHTS; i++){
            flightTable[i].flightCode = randomAlphanumberGnerator(LENGTHFLIGHTCODE);
            flightTable[i].destinationIATA = generateRandomIATA();
            flightTable[i].flightDepartureTime.hours = randomDigitsClock('H');
            flightTable[i].flightDepartureTime.minutes = randomDigitsClock('M');
            flightTable[i].seatAvailable = randomDigitsClock('S');
        }
    }
}

//stampa tutte le informazioni di tutti i voli
void printAllFlightTable(){ 
    clearView();
    cout << "All scheduled flight: " << endl << endl;
    cout << "Flight Code\tDestination\tDeparture Time\tSeat Avaliable" << endl << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
    for(int i = 0; i < MAXFLIGHTS; i++){
        if (flightTable[i].flightCode != "NULL"){
            cout << flightTable[i].flightCode << "\t\t|" << flightTable[i].destinationIATA << "\t\t|" << flightTable[i].flightDepartureTime.hours << ":" << flightTable[i].flightDepartureTime.minutes << "\t\t|" << flightTable[i].seatAvailable << endl;
            cout << "- - - - - - - - + - - - - - - - + - - - - - - - + - - - - - - " << endl;
        }
        else { cout << "\aWe were unable to find this specific information, please check the syntax and try again" << endl; }
    }
}

//stampa le informazioni di un volo in base all'codice di volo
void printFlightTableByCode(string flightCodeToFind){
    clearView();
    bool printSomethingCheck = false;
    cout << "Here are the results obtained from the research of this flight code : " << flightCodeToFind << endl << endl;
    cout << "Flight Code\tDestination\tDeparture Time\tSeat Avaliable" << endl << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
    for(int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightCode == flightCodeToFind){
            printSomethingCheck = true;
            cout << flightTable[i].flightCode << "\t\t|" << flightTable[i].destinationIATA << "\t\t|" << flightTable[i].flightDepartureTime.hours << ":" << flightTable[i].flightDepartureTime.minutes << "\t\t|" << flightTable[i].seatAvailable << endl;
            cout << "- - - - - - - - + - - - - - - - + - - - - - - - + - - - - - - " << endl;
        }
        //else { cout << "We were unable to find this specific flight table, please check the syntax and try again" << endl; }
    }
    if(printSomethingCheck == false){
        cout << "\aNo flight found with this code: " << flightCodeToFind << endl;
    }
}

//vettore contente tutti gli indici dei risoltati delle ricerche 
int indexFindByParameters[MAXFLIGHTS], obtainedResulCounter = 0; //variabile locale alla funzione "searchIndexFlightTableByParameter" designata globalmente per semplicità d'accesso e di lettura da parte di altre funzioni

//cerca tutti i voli con un determinato codice volo
void searchFlightCodeForIndex(string whatHaveToSearchString){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightCode == whatHaveToSearchString){
            indexFindByParameters[j] = i;
            j++;
            obtainedResulCounter++;
        }
        //else { cout << "\aWe were unable to find this specific information, please check the syntax and try again" << endl; }
    }
}

//cerca tutti i voli con una determinata destianzione
void searchDestinationFlightForIndex(string whatHaveToSearchString){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].destinationIATA == whatHaveToSearchString){
            indexFindByParameters[j] = i;
            j++;
            obtainedResulCounter++;
        }
        //else { cout << "\aWe were unable to find this specific information, please check the syntax and try again" << endl; }
    }
}

//cerca tutti i voli con un determinato orario di partenza
void searchTimeHoursDepartureForIndex(int whatHaveToSearchInt){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightDepartureTime.hours == whatHaveToSearchInt){
            indexFindByParameters[j] = i;
            j++;
            obtainedResulCounter++;
        }
        //else { cout << "\aWe were unable to find this specific information, please check the syntax and try again" << endl; }
    }
}

//ricerca tutti i voli con > n numeri disponibili di posti a sedere
void searchSeatAvaliableOnFlight(int whatHaveToSearchInt){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].seatAvailable >= whatHaveToSearchInt){
            indexFindByParameters[j] = i;
            j++;
            obtainedResulCounter++;
        }
        //else { cout << "\aWe were unable to find this specific information, please check the syntax and try again" << endl; }
    }
}

//questa funzione stampa la tabelle voli contenuti nel vettore indexFindByParameters
void printSearchResults(){
    clearView();
    cout << "Here are the results obtained from the research: " << endl << endl;
    cout << "Flight Code\tDestination\tDeparture Time\tSeat Avaliable" << endl << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
    for(int i = 0; i < obtainedResulCounter; i++){
        cout << flightTable[i].flightCode << "\t\t|" << flightTable[i].destinationIATA << "\t\t|" << flightTable[i].flightDepartureTime.hours << ":" << flightTable[i].flightDepartureTime.minutes << "\t\t|" << flightTable[i].seatAvailable << endl;
        cout << "- - - - - - - - + - - - - - - - + - - - - - - - + - - - - - - " << endl; 
    }
}

//questa funzione permette sia di creare un elenco contenenti tutti gli indici delle tabelle di volo che si vogliono manipolare e permette anche dopo la ricerca di stamparle 
void searchIndexFlightTableByParameter(){ //char inteso come C per riceerca per codice volo T per l'orario etc...
    clearView();
    bool running = true;
    string whatHaveToSearchString;
    char parameter;
    int whatHaveToSearchInt;
    while(running){
        cout << "What parameter do you want to search for? (C, D, T, S) - digit H for help > ";
        cin >> parameter;
        clearView();
        char choice;
        switch (parameter){
            case 'H':
                cout << "Here is the list of commands!" << endl << endl;
                cout << "C > search by flight code,\n    you will be asked to enter the flight code to find,\n    and it will return the indices relevant to the search" << endl << endl;
                cout << "D > search by destination airport,\n    you will be asked to enter the IATA code of airport or the name of the city of destination to find,\n    and it will return the indices relevant to the search" << endl << endl;
                cout << "T > search by departure time, you will be asked to enter the first two digits of the departure time to find, the relevant indices for the search will be returned" << endl << endl;
                cout << "X > for exit from this function" << endl << endl;
                break;
                
            case 'C':
                cout << "Enter the flight code to search > ";
                cin >> whatHaveToSearchString;
                searchFlightCodeForIndex(whatHaveToSearchString);
                do{
                    cout << "Resolutions obtained from research " << obtainedResulCounter << " .Do you want to print the search results? (y or n) > ";
                    cin >> choice;
                    if (choice == 'y' or choice == 'Y'){
                        printSearchResults(); // questa funzuine stampa semoplicemenrte il vettore contenehte gli indici dei risultati della ricerca
                    }
                }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
                break;

            case 'D':
                cout << "Enter the flight destination airport to search > ";
                cin >> whatHaveToSearchString;
                searchDestinationFlightForIndex(whatHaveToSearchString);
                do{
                    cout << "Resolutions obtained from research " << obtainedResulCounter << " .Do you want to print the search results? (y or n) > ";
                    cin >> choice;
                    if (choice == 'y' or choice == 'Y'){
                        printSearchResults(); // questa funzuine stampa semoplicemenrte il vettore contenehte gli indici dei risultati della ricerca
                    }
                }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
                break;

            case 'T':
                cout << "Enter the time (hours) of your departing flights to search > ";
                cin >> whatHaveToSearchString;
                searchTimeHoursDepartureForIndex(whatHaveToSearchInt);
                do{
                    cout << "Resolutions obtained from research " << obtainedResulCounter << " .Do you want to print the search results? (y or n) > ";
                    cin >> choice;
                    if (choice == 'y' or choice == 'Y'){
                        printSearchResults(); // questa funzuine stampa semoplicemenrte il vettore contenehte gli indici dei risultati della ricerca
                    }
                }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
                break;
                
            case 'S':
                cout << "enter the minimum number of free places to carry out the search > ";
                cin >> whatHaveToSearchInt;
                searchSeatAvaliableOnFlight(whatHaveToSearchInt);
                do{
                    cout << "Resolutions obtained from research " << obtainedResulCounter << " .Do you want to print the search results? (y or n) > ";
                    cin >> choice;
                    if (choice == 'y' or choice == 'Y'){
                        printSearchResults(); // questa funzuine stampa semoplicemenrte il vettore contenehte gli indici dei risultati della ricerca
                    }
                }while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
                break;

            case 'X':
                running = false;
                break;

            default:
                cout << "\aWe're sorry but there was an error in the search,\nyou probably entered a character incorrectly,\ntype 'H' to get the list of commands" << endl << endl;
                break;

        }
    }
}

//inserisce dati a determinate tabelle di volo secondo secondo alcuni criteri | per entrare in questa fuzione su oggetti multipli bisogna prima chiamare la funzione di ricercasearchIndexFlightTableByParameter
void editFlightTableByIndexOrParameters(){
    clearView();
    bool running = true;
    char choice, multiplyDataEdit;
    string flightCodeToEdit;
    while (running){
        switch(choice){
            case 'H': 
                cout << "Here is the list of commands!" << endl << endl;
                cout << "C > modify flight code,\n    you will be asked to enter the flight code to edit." << endl << endl;
                cout << "D > modify the destination airport name,\n    you will be asked to enter the new IATA code of airport or the name of the city of destination." << endl << endl;
                cout << "T > modify the departure time, you will be asked to enter the H (hours) or M (minutes) to edit." << endl << endl;
                cout << "X > for exit from this function" << endl << endl;
                break;
            case 'C':
                cout << "If you use this function, make sure you have searched by criteria first. A (for all data by search) or or any other characters to continue individually." << endl << endl;
                cin >> multiplyDataEdit;
                if (multiplyDataEdit == 'A'){ // tutti i dati
                    for (int i = 0; i < obtainedResulCounter; i++){
                        cout << "Enter the new flight code of " << flightTable[i].flightCode << "> ";
                        cin >> flightTable[indexFindByParameters[i]].flightCode;
                        clearView();
                    }
                    cout << "Flight code changed successfully" << endl;
                }
                else{
                    cout << "Enter the flight code you want to change > ";
                    cin >> flightCodeToEdit;
                    for (int i = 0; i < MAXFLIGHTS; i++){
                        if(flightTable[i].flightCode == flightCodeToEdit){
                            cout << "Enter the new flight code of " << flightTable[i].flightCode << "> ";
                            cin >> flightTable[i].flightCode;
                            clearView();
                            cout << "Flight code changed successfully. Now the code is > " << flightTable[i].flightCode << endl;
                        }
                        //else { cout << "\aWe were unable to find this specific flight table, please check the syntax and try again" << endl; }
                    }
                }
                break;

            case 'D':
                cout << "If you use this function, make sure you have searched by criteria first. A (for all data by search) or or any other characters to continue individually." << endl << endl;
                cin >> multiplyDataEdit;
                if (multiplyDataEdit == 'A'){ // tutti i dati
                    for (int i = 0; i < obtainedResulCounter; i++){
                        cout << "Enter the new destination name or the new IATA code of " << flightTable[indexFindByParameters[i]].flightCode << " > ";
                        cin >> flightTable[indexFindByParameters[i]].destinationIATA;
                        clearView();
                    }
                cout << "Flight departure name or IATA code changed successfully" << endl;
                }
                else{
                    cout << "Enter the flight code you want to change > ";
                    cin >> flightCodeToEdit;
                    for (int i = 0; i < MAXFLIGHTS; i++){
                        if(flightTable[i].destinationIATA == flightCodeToEdit){
                            cout << "Enter the new flight code of " << flightTable[i].flightCode << "> ";
                            cin >> flightTable[i].destinationIATA;
                            clearView();
                            cout << "Flight departure name or IATA code changed successfully. Now the name is > " << flightTable[i].destinationIATA << endl;
                        }
                        //else { cout << "\aWe were unable to find this specific flight table, please check the syntax and try again" << endl; }
                    }
                }
                break;

            case 'T':
                char choice; 
                cout << "If you use this function, make sure you have searched by criteria first." << endl << endl;
                cout << "Enter the H (hours) or M (minutes) to edit > ";
                cin >> choice;
                if(choice == 'H' || choice == 'h'){
                    cout << "If you use this function, make sure you have searched by criteria first. A (for all data by search) or or any other characters to continue individually." << endl << endl;
                    cin >> multiplyDataEdit;
                    if (multiplyDataEdit == 'A'){ // tutti i dati
                        for (int i = 0; i < obtainedResulCounter; i++){
                            cout << "Enter the 2-digit number of the new departure time of > " <<  flightTable[indexFindByParameters[i]].flightCode << " > ";
                            cin >> flightTable[indexFindByParameters[i]].flightDepartureTime.hours;
                            clearView();
                        }
                        cout << "The flight departure time changed successfully." << endl;
                    }
                    else{
                        cout << "Enter the flight code you want to change > ";
                        cin >> flightCodeToEdit;
                        for (int i = 0; i < MAXFLIGHTS; i++){
                            if(flightTable[i].flightCode == flightCodeToEdit){
                                cout << "Enter the 2-digit number of the new departure time of > " <<  flightTable[i].flightDepartureTime.hours << " > ";
                                cin >> flightTable[i].flightDepartureTime.hours;
                                clearView();
                                cout << "The flight departure time changed successfully. Now the time is > " << flightTable[i].flightDepartureTime.hours << endl;
                            }
                            //else { cout << "\aWe were unable to find this specific flight table, please check the syntax and try again" << endl; }
                        }
                    }
                }

                else if (choice == 'M' || choice == 'm'){
                    cout << "If you use this function, make sure you have searched by criteria first. A (for all data by search) or or any other characters to continue individually." << endl << endl;
                    cin >> multiplyDataEdit;
                    if (multiplyDataEdit == 'A'){ // tutti i dati
                        for (int i = 0; i < obtainedResulCounter; i++){
                            cout << "Enter the 2-digit number of the new departure time of > " <<  flightTable[indexFindByParameters[i]].flightCode << " > ";
                            cin >> flightTable[indexFindByParameters[i]].flightDepartureTime.minutes;
                            clearView();
                        }
                        cout << "The flight departure time changed successfully." << endl;
                    }
                    else{
                        cout << "Enter the flight code you want to change > ";
                        cin >> flightCodeToEdit;
                        for (int i = 0; i < MAXFLIGHTS; i++){
                            if(flightTable[i].flightCode == flightCodeToEdit){
                                cout << "Enter the 2-digit number of the new departure time of > " <<  flightTable[i].flightDepartureTime.hours << "> ";
                                cin >> flightTable[i].flightDepartureTime.minutes;
                                clearView();
                                cout << "The flight departure time changed successfully. Now the time is > " << flightTable[i].flightDepartureTime.minutes << endl;
                            }
                            //else { cout << "\aWe were unable to find this specific flight table, please check the syntax and try again" << endl; }
                        }
                    }
                }
                    
                else{ cout << "\aThe input you entered was not recognized by the system, please try again" << endl; }
                break;

            case 'X':
                running = false;
                break;

            default:
                cout << "\aThe input you entered was not recognized by the system, please try again" << endl;
                break;
        }
    }
}

//permette di prenotare un volo
void bookSeats(){
    string flightCodeToBook;
    int numberOfSeatsToBook;
    cout << "Enter the flight code > ";
    cin >> flightCodeToBook;
    cout << "Enter the number of seats to book > ";
    cin >> numberOfSeatsToBook;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightCode == flightCodeToBook){
            if(flightTable[i].seatAvailable >= numberOfSeatsToBook || numberOfSeatsToBook <= MAXSEATAVALIABLE){
                flightTable[i].seatAvailable -= numberOfSeatsToBook;
                cout << "The seats have been booked successfully" << endl;
            }else{
                cout << "\aWe're sorry but there are not enough seats available. There are only " << flightTable[i].seatAvailable << " places available." << endl;
            }
        }
        else { cout << "\aWe were unable to find this specific flight code, please check the syntax and try again" << endl; }
    }

}

void addFlightTable(){ 
    clearView();
    for (int i = 0; i < obtainedResulCounter; i++){
        if (flightTable[i].flightCode == "NULL"){
            cout << "The new flight was included in the index:" << i << endl << endl;
            cout << "Insert flight code (5 alphanumeric digits): ";
            cin >> flightTable[i].flightCode;
            cout << "Enter the destination of this flight (name or IATA code): ";
            cin >> flightTable[i].destinationIATA;
            cout << "Insert the local departure time (hours): ";
            cin >> flightTable[i].flightDepartureTime.hours;
            cout << "Insert the local departure time (minutes): ";
            cin >> flightTable[i].flightDepartureTime.minutes;
            cout << "Enter the number of seats available on the flight: ";
            cin >> flightTable[i].seatAvailable;
            cout << "Flight schedule:" << flightTable[i].flightCode << "was completed successfully" << endl << endl;
            cout << "The data has been successfully loaded" << endl;
        }
        else{
            clearView();
            cout << "\aIt was not possible to find an area not previously allocated in the system. There is not enough space to allocate a new flight" << endl << endl;
        }
    }
}

void deleteFlightTable(){ 
    clearView();
    char multiplyDataEdit;
    cout << "If you use this function, make sure you have searched by criteria first. A (for all data by search) or or any other characters to continue individually." << endl << endl;
    cin >> multiplyDataEdit;
    int indexTemp;
    if (multiplyDataEdit == 'A'){ // tutti i dati
        for (int i = 0; i < obtainedResulCounter; i++){
            clearView();
            indexAvaliableOnFlightTable[i] = i;
            flightTable[i].flightCode = "NULL";
            flightTable[i].destinationIATA = "NULL";
            flightTable[i].flightDepartureTime.hours = 0;
            flightTable[i].flightDepartureTime.minutes = 0;
            flightTable[i].seatAvailable = 0;
        }
        cout << "\aThe data has been successfully deleted" << endl;
    }
    else{
        string flightCodeToEdit; // dichiarazione della variabile flightCodeToEdit
        cout << "Enter the flight code you want to delete > ";
        cin >> flightCodeToEdit;
        for (int i = 0; i < MAXFLIGHTS; i++){
            if(flightTable[i].flightCode == flightCodeToEdit){
                indexAvaliableOnFlightTable[i] = i;
                flightTable[i].flightCode = "NULL";
                flightTable[i].destinationIATA = "NULL";
                flightTable[i].flightDepartureTime.hours = 0;
                flightTable[i].flightDepartureTime.minutes = 0;
                flightTable[i].seatAvailable = 0;
                clearView();
                cout << "\aThe data has been successfully deleted." << endl;
            }
            cout << "\aIt was not possible to find an area not previously allocated in the system. There is not enough space to allocate a new flight" << endl << endl;
        }
    }
}

void showLogo(){
    cout <<"\n\n\n      _________       __    __     _____      __             __      __          " << endl;
    cout <<"     / ____/ (_)___ _/ /_  / /_   / ___/_____/ /_  ___  ____/ /_  __/ /__  _____ " << endl;
    cout <<"    / /_  / / / __ `/ __ \\/ __/   \\__ \\/ ___/ __ \\/ _ \\/ __  / / / / / _ \\/ ___/ " << endl;
    cout <<"   / __/ / / / /_/ / / / / /_    ___/ / /__/ / / /  __/ /_/ / /_/ / /  __/ /     " << endl;
    cout <<"  /_/   /_/_/\\__, /_/ /_/\\__/   /____/\\___/_/ /_/\\___/\\__,_/\\__,_/_/\\___/_/      " << endl;
    cout <<"           /____/                                                               " << endl;
    cout <<"    Developed by Antonio Carbone 4Fi 25/09/2023 2023-2024" << endl;
}

void showMenu(){ //mosta tutte le possibili funzioni del programma tramite un albero (like: il comando tree su linux)
    clearView();
    bool running = true;
    string command;
    while (running){
        clearView();
        showLogo();
        cout << "\n\n\nWelcome to Flight Scheduler, Below are all the functions of the program." << endl << endl;
        cout << "   Here" << endl;
        cout << "       |______ PrintAll" << endl;
        cout << "       |______ PrintByCode (PBC)" << endl;
        cout << "       |______ PrintSearchedTable (PST)" << endl;
        cout << "       |______ SearchInDataBase (SDB)" << endl;
        cout << "       |               |_________________ SearchFlightCode" << endl;
        cout << "       |               |                             |_________ Print" << endl;
        cout << "       |               |                                             |___ All or Specific" << endl;
        cout << "       |               |_________________ SearchDestinationFlight" << endl;
        cout << "       |               |                             |_________ Print" << endl;
        cout << "       |               |                                             |___ All or Specific" << endl;
        cout << "       |               |_________________ SearchTimeHoursDeparture" << endl;
        cout << "       |                                             |_________ Print" << endl;
        cout << "       |                                                             |___ All or Specific" << endl;
        cout << "       |______ EditFlightInformation (EFI)" << endl;
        cout << "       |               |_________________ EditFlightCode" << endl;
        cout << "       |               |_________________ EditDestinationFlight" << endl;
        cout << "       |               |_________________ EditTimeDeparture" << endl;
        cout << "       |                                             |_________ EditHours" << endl;
        cout << "       |                                             |_________ EditMinutes" << endl;
        cout << "       |______ BookSeats" << endl;
        //cout << "       X                   " << endl;
        cout << "       |______ DeleteFlightTable (DFT)" << endl;
        cout << "       |               |___ All or Specific" << endl;
        cout << "       |______ AddFlightTable (AFT)" << endl;
        cout << "\n\nFunctions that have the '!' symbol prefixed to them they have been written but not tested or compiled.\nType X or Exit and press enter to permanently exit Flight Scheduler! Exit" << endl << endl << endl;
        cout << "User $ > ";
        cin >> command;
        if (command == "PrintAll" || command == "printall"){printAllFlightTable();}
        else if (command == "PrintByCode" || command == "printbycode" || command == "PBC"){
            string flightCode;
            cout << "Enter the flight code of the flight you want to print > ";
            cin >> flightCode;
            printFlightTableByCode(flightCode);
        }
        else if (command == "PrintSearchedTable" || command == "printsearchedtable" || command == "PST"){printSearchResults();}
        else if (command == "SearchInDataBase" || command == "searchindatabase" || command == "SDB"){searchIndexFlightTableByParameter();}
        else if (command == "EditFlightInformation" || command == "editflightinformation" || command == "EFI"){editFlightTableByIndexOrParameters();}
        else if (command == "BookSeats" || command == "bookseats"){bookSeats();}
        else if (command == "DeleteFlightTable" || command == "deleteflighttable" || command == "DFT"){deleteFlightTable();}
        else if (command == "AddFlightTable" || command == "addflighttable" || command == "AFT"){addFlightTable();}
        else if (command == "X" || command == "Exit" || command == "x" || command == "exit") {running = false;}
        else {cout << "\aThe command: " << command << "it is not a command recognized by the system. Try checking the command syntax. Try again" << endl; }

    }
}

int main(){
    setupFlightTableFill();
    showMenu();
    cout << "\a\a\aThank you for using this flight management software, See you next time we launch. Until we meet again              ^-^" << endl;
}