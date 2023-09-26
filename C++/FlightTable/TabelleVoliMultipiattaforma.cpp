//Developed by Antonio Carbone 4Fi 25/09/2023 2023-2024

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

const int MAXFLIGHTS = 10; //costante che pero per motivi di programmazione puo subbire delle variazioni
const int LENGTHFLIGHTCODE = 5;

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
        randomTwoDigitsClock = rand() % 168 + 1;
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
    for(int i = 0; i < MAXFLIGHTS; i++){
        cout << "Flight Code: " << flightTable[i].flightCode << endl;
        cout << "Destination: " << flightTable[i].destinationIATA << endl;
        cout << "Departure Time: " << flightTable[i].flightDepartureTime.hours << ":" << flightTable[i].flightDepartureTime.minutes << endl;
        cout << "Seat Available: " << flightTable[i].seatAvailable << endl << endl;
        cout << "---" << endl << endl;
    }
}

//stampa le informazioni di un volo in base all'codice di volo
void printFlightTableByCode(string flightCodeToFind){
    clearView();
    bool printSomethingCheck = false;
    cout << "Here are the results obtained from the research of this flight code : " << flightCodeToFind << endl << endl;
    for(int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightCode == flightCodeToFind){
            printSomethingCheck = true;
            cout << "Flight Code: " << flightTable[i].flightCode << endl;
            cout << "Destination: " << flightTable[i].destinationIATA << endl;
            cout << "Departure Time: " << flightTable[i].flightDepartureTime.hours << ":" << flightTable[i].flightDepartureTime.minutes << endl;
            cout << "Seat Available: " << flightTable[i].seatAvailable << endl << endl;
            cout << "---" << endl << endl;
        }
    }
    if(!printSomethingCheck){
        cout << "No flight found with this code: " << flightCodeToFind << endl;
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
    }
}

//questa funzione stampa la tabelle voli contenuti nel vettore indexFindByParameters
void printSearchResults(){
    clearView();
    cout << "Here are the results obtained from the research: " << endl << endl;
    for(int i = 0; i < obtainedResulCounter; i++){
        cout << "Flight Code: " << flightTable[indexFindByParameters[i]].flightCode << endl;
        cout << "Destination: " << flightTable[indexFindByParameters[i]].destinationIATA << endl;
        cout << "Departure Time: " << flightTable[indexFindByParameters[i]].flightDepartureTime.hours << ":" << flightTable[indexFindByParameters[i]].flightDepartureTime.minutes << endl;
        cout << "Seat Available: " << flightTable[indexFindByParameters[i]].seatAvailable << endl << endl;
        cout << "---" << endl << endl;
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
                cout << "We're sorry but there was an error in the search,\nyou probably entered a character incorrectly,\ntype 'H' to get the list of commands" << endl << endl;
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
                        }
                    }
                }

                if (choice == 'M' || choice == 'm'){
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
                        }
                    }
                }
                    
                else{ cout << "The input you entered was not recognized by the system, please try again" << endl; }
                break;

            case 'X':
                running = false;
                break;

            default:
                cout << "The input you entered was not recognized by the system, please try again" << endl;
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
            if(flightTable[i].seatAvailable >= numberOfSeatsToBook){
                flightTable[i].seatAvailable -= numberOfSeatsToBook;
                cout << "The seats have been booked successfully" << endl;
            }else{
                cout << "We're sorry but there are not enough seats available. There are only " << flightTable[i].seatAvailable << " places available." << endl;
            }
        }
    }

}

void addFlightTable(){ 
    //Funzione in sviluppo
}

/*
Questo codice definisce una struct `FlightTable` che contiene svariati parametri pertinenti ai voli. 
Successivamente, viene definita una funzione `deleteFlightTable` che utilizza un vettore di struct `FlightTable`, 
un indice e un puntatore a intero che rappresenta la DIMENSIONE LOGICA DEL VETTORE.
La funzione rimuove l'elemento del vettore con l'indice specificato, shiftando tutti gli elementi successivi a sinistra di una posizione
e riducendo la dimensione logica del vettore di uno.
Un vettore di struct `FlightTable`. Successivamente, viene chiamata la funzione `deleteFlightTable` per rimuovere l'elemento con indice n dal vettore.
Il principio dietro al funzionamento di questo codice è l'utilizzo di una struct per rappresentare un'entità complessa (in questo caso, una una tabella di voli)
e l'utilizzo di un vettore di struct per gestire un insieme di entità simili. La funzione `deleteFlightTable` dimostra come sia possibile manipolare un vettore 
di struct utilizzando un puntatore alla sua dimensione logica, consentendo di aggiungere o rimuovere elementi dal vettore in modo dinamico.
*/

/*
void deleteFlightTable(){ 
    clearView();
    char multiplyDataEdit;
    cout << "If you use this function, make sure you have searched by criteria first. A (for all data by search) or or any other characters to continue individually." << endl << endl;
    cin >> multiplyDataEdit;
    int indexTemp;
    if (multiplyDataEdit == 'A'){ // tutti i dati
        for (int i = 0; i < obtainedResulCounter; i++){
            clearView();
            indexTemp = indexFindByParameters[i];
            if (indexTemp < *MAXFLIGHTS) {
                for (int i = indexTemp; i < *MAXFLIGHTS - 1; i++) {
                    flightTable[i] = flightTable[i + 1];
                }
                (*MAXFLIGHTS)--;
            }
        }
        cout << "The data has been successfully deleted" << endl;
    }
    else{
        cout << "Enter the flight code you want to delete > ";
        cin >> flightCodeToEdit;
        for (int i = 0; i < MAXFLIGHTS; i++){
            if(flightTable[i].flightCode == flightCodeToEdit){
                if (indexTemp < *MAXFLIGHTS) {
                    for (int i = indexTemp; i < *MAXFLIGHTS - 1; i++) {
                        flightTable[i] = flightTable[i + 1];
                    }
                (*MAXFLIGHTS)--;
                }
                clearView();
                cout << "The data has been successfully deleted." << endl;
            }
        }
    }
}
*/
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
        cout << "       X                   " << endl;
        cout << "       |______ !DeleteFlightTable" << endl;
        cout << "       |               |___ All or Specific" << endl;
        cout << "       |______ AddFlightTable" << endl;
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
        /*else if (command == "DeleteFlightTable" || command == "deleteflighttable"){deleteFlightTable();}
        else if (command == "AddFlightTable" || command == "addflighttable"){addFlightTable();}*/
        else if (command == "X" || command == "Exit" || command == "x" || command == "exit") {running = false;}

    }
}

int main(){
    setupFlightTableFill();
    showMenu();
    cout << "Thank you for using this flight management software, See you next time we launch. Until we meet again              ^-^" << endl;
}
