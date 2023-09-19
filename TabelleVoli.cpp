#include <iostream>

using namespace std;

const int MAXFLIGHTS = 10;

struct {
    int hours, minutes;
}localTime[MAXFLIGHTS];

struct flightTableList{
    string flightCode, destinationIATA;
    localTime flightDepartureTime;
    int seatAvailable;
}flightTable[MAXFLIGHTS];

/* sample flightTable
    flightCode: AZ115
    destination: Milano
    localTime.hours: 12 | localTime.minutes: 30
    seatAvailable: 57
*/

//TODO: fixare l'accesso ai singoli parametri della struct dell'orario
//TODO: fixare L'accesso al vettore contenente tutte gli indici di determinati elementi risultati da una ricerca

void clearView(){
    // TODO: per non usare librerie e quindi causare incompatibilità uso un semplice try e catch
}

void setupFlightTableFill(){
    clearView();
    for (int i = 0; i < MAXFLIGHTS; i++){
        cout << "You are compiling the table with index in the database number: " << i << endl << endl;
        cout << "Insert flight code (5 alphanumeric digits): ";
        cin >> flightTable[i].flightCode;
        cout << "Enter the destination of this flight (name or IATA code): ";
        cin >> flightTable[i].destinationIATA;
        cout << "Insert the local departure time (hours): ";
        cin >> flightTable[i].hours;
        cout << "Insert the local departure time (minutes): ";
        cin >> flightTable[i].minutes;
        cout << "Enter the number of seats available on the flight: ";
        cin >> flightTable[i].seatAvailable;
        cout << "Flight schedule:" << flightTable[i].flightCode << "was completed successfully" << endl << endl;
    }
}

void printAllFlightTable(){
    clearView();
    cout << "All scheduled flight: " << endl << endl;
    for(int i = 0; i < MAXFLIGHTS; i++){
        cout << "Flight Code: " << flightTable[i].flightCode << endl;
        cout << "Destination: " << flightTable[i].destinationIATA << endl;
        cout << "Departure Time: " << flightTable[i].hours << ":" << flightTable[i].minutes << endl;
        cout << "Seat Available: " << flightTable[i].seatAvailable << endl << endl;
        cout << "---" << endl << endl;
    }
}

void printFlightTableByCode(string flightCodeToFind){
    clearView();
    bool printSomethingCheck = false;
    cout << "Here are the results obtained from the research of this flight code : " << flightCodeToFind << endl << endl;
    for(int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightCode == flightCodeToFind){
            printSomethingCheck = true;
            cout << "Flight Code: " << flightTable[i].flightCode << endl;
            cout << "Destination: " << flightTable[i].destinationIATA << endl;
            cout << "Departure Time: " << flightTable[i].hours << ":" << flightTable[i].minutes << endl;
            cout << "Seat Available: " << flightTable[i].seatAvailable << endl << endl;
            cout << "---" << endl << endl;
        }
    }
    if(!printSomethingCheck){
        cout << "No flight found with this code: " << flightCodeToFind << endl;
    }
}

int indexFindByParameters[MAXFLIGHTS]; //variabile locale alla funzione "searchIndexFlightTableByParameter" designata globalmente per semplicità d'accesso e di lettura da parte di altre funzioni
void searchFlightCodeForIndex(string whatHaveToSearchString){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].flightCode == whatHaveToSearchString){
            indexFindByParameters[j] = i;
            j++;
        }
    }
}

void searchDestinationFlightForIndex(string whatHaveToSearchString){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].destinationIATA == whatHaveToSearchString){
            indexFindByParameters[j] = i;
            j++;
        }
    }
}

void searchTimeHoursDepartureForIndex(int whatHaveToSearchInt){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].hours == whatHaveToSearchInt){
            indexFindByParameters[j] = i;
            j++;
        }
    }
}
//TODO: se viene rischiesta questa funzione nell parametro interno viene passato il numero di posti minimo richiesti
//inserisci gli indici di tutti i voli disponibili con quel numero di posti a sedere
void searchSeatAvaliableOnFlight(int whatHaveToSearchInt){
    int j = 0;
    for (int i = 0; i < MAXFLIGHTS; i++){
        if(flightTable[i].seatAvailable == whatHaveToSearchInt){
            indexFindByParameters[j] = i;
            j++;
        }
    }
}

//TODO: ce un po di roba da aggiustare in quanto ho mixato la funzione di ricerca destinata all'utente e quella utilizato dal computer per ottenere gli indici dei risultati da stampare successivaemnte
//TODO: prima di chiamare questa funzione ci sarà un if che se il parametro che si vuole cercare è di tipo stringa si riempe il secondo parametro e si lascia il palametro di tipo interno vuoto, poi nel chiamare le funzioni delle singole casistiche si invia il dato che ci interessa
void searchIndexFlightTableByParameter(char parameter, string whatHaveToSearchString, int whatHaveToSearchInt){ //char inteso come C per riceerca per codice volo T per l'orario etc...
    clearView();
    //bool running = true;
    //while(running){
    switch (parameter){
        /* TODO: ho sbagliato nello scrivere lo switch qui, questo andra usato nella funzione dove si inserisce il parametro da cercare e restituice i risultati stessi e non dei numeri
        case 'H':
            cout << "Here is the list of commands!" << endl << endl;
            cout << "C > search by flight code,\n    you will be asked to enter the flight code to find,\n    and it will return the indices relevant to the search" << endl << endl;
            cout << "D > search by destination airport,\n    you will be asked to enter the IATA code of airport or the name of the city of destination to find,\n    and it will return the indices relevant to the search" << endl << endl;
            cout << "T > search by departure time, you will be asked to enter the first two digits of the departure time to find, the relevant indices for the search will be returned" << endl << endl;
            break;
        */
        case 'C':
            searchFlightCodeForIndex(whatHaveToSearchString);
            break;
        case 'D':
            searchDestinationFlightForIndex(whatHaveToSearchString);
            break;
        case 'T':
            searchTimeHoursDepartureForIndex(whatHaveToSearchInt);
            break;
        case 'S':
            searchSeatAvaliableOnFlight()
            break;
        default:
            cout << "We're sorry but there was an error in the search,\nyou probably entered a character incorrectly,\ntype 'H' to get the list of commands" << endl << end;
            break;
    }
    //}
}

void addFlightTable(){

}

void deleteFlightTable(int indexFlightTable){ //per adesso mentre cerco come cancellare completamente il record svuoto tutti i parametri della struct

}

void showMenu(){ //mosta tutte le possibili funzioni del programma tramite un albero (like: il comando tree su linux)
    
}


int main(){
    showMenu();
}