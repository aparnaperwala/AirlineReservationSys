// AirlineReservationSys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Database.h"
using namespace std;
using namespace AirlineReservationSys;

int displayMenu();
void doPassengerInfo(Database& db);
void doSearchNDisplay(Database& db);
void doReserve(Database& db);

int main()
{
	
	/*Testing FlightDB class
	FlightDB flight;
	flight.setAirlines("Alaska");
	flight.setFromCity("SEA");
	flight.setToCity("SJC");
	flight.displayFlightInfo();
	*/
	
	/*Testing Database.cpp*/
	Database myDB;
	FlightDB& flight1 = myDB.addFlight("Alaska","SEA","SJC");
	FlightDB& flight2 = myDB.addFlight("Delta","SEA","SJC");
	FlightDB& flight3 = myDB.addFlight("SouthWest","SEA","SJC");
	FlightDB& flight4 = myDB.addFlight("Alaska","SEA","NYC");
	FlightDB& flight5 = myDB.addFlight("Delta","SEA","NYC");
	FlightDB& flight6 = myDB.addFlight("SouthWest","SEA","NYC");

	myDB.displayAllFlights();
	//Database flightDB;
	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			doPassengerInfo(myDB);
			break;
		case 2:
			doSearchNDisplay(myDB);
			break;
		case 3:
			
			break;
		case 4:
			doReserve(myDB);
			break;
		default:
			cerr << "unknown command. Try again. " << endl;
			break;

		}
	}
}

int displayMenu() {

	int selection;
	cout << endl;
	cout << "Welcome to the Airline Reservation System" << endl;
	cout << "======================================================" << endl;
	cout << "1. Add Passenger Info: " << endl;
	cout << "2. Provide flight booking requirements " << endl;
	cout << "3. Search and display matching flights " << endl;
	cout << "4. choose and book a flight " << endl;
	cout << "0. Quit " << endl;
	cout << "======================================================" << endl;

	cin >> selection;
	return selection;
}

void doReserve(Database& db) {
	
	
	
	//db.getMatchingFlight(FromCity, ToCity);

	
}
void doPassengerInfo(Database& db) {

	string firstName;
	string lastName;
	int Age;
	
	cout << "FirstName ?";
	cin >> firstName;

	cout << "LastName ?";
	cin >> lastName;

	cout << "Age ? ";
	cin >> Age;
	db.addPassenger(firstName, lastName, Age);
	db.displayAllPassengers();

}

void doSearchNDisplay(Database& db) {
	string FromCity;
	string ToCity;
	string Airlines;
	int search;

	cout << "From City: ?";
	cin >> FromCity;

	cout << "To City: ?";
	cin >> ToCity;

	cout << "Airlines? ";
	cin >> Airlines;

	cout << "Flight starting from:  " << FromCity << "Flight Destination:  " << ToCity << "with Airlines" << Airlines << endl;
	cout << "Press (1) to search by Airlines or (2) for search by City" << endl;
	cin >> search;

	switch (search) {

	case 1:
		db.inputBookingReq(FromCity, ToCity);
		try {
			FlightDB& flight = db.getMatchingFlight(Airlines);
			flight.displayFlightInfo();
		}
		catch (const std::logic_error& exception) {
			cerr << "No matching flights found, search again! " << exception.what() << endl;
		}
		break;

	case 2:
	{
		try {
			FlightDB& flight = db.getMatchingFlight(FromCity, ToCity);
			flight.displayFlightInfo();
		}
		catch (const std::logic_error& exception) {
			cerr << "No matching flights found, search again! " << exception.what() << endl;
		}
		db.getMatchingFlight(FromCity, ToCity);
		break;
	}


	}
}

	


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
	