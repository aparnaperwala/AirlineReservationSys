// AirlineReservationSys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Database.h"
using namespace std;
using namespace AirlineReservationSys;

int displayMenu();
void doPassengerInfo(Database& db);
void doFlightSearch(Database& db);
void doBook(Database& db);
void doDisplayTkt(Database& db);

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
	Database DB;
	FlightDB& flight1 = DB.addFlight("Alaska","SEA","SJC");
	FlightDB& flight2 = DB.addFlight("Delta","SEA","SJC");
	FlightDB& flight3 = DB.addFlight("SouthWest","SEA","SJC");
	FlightDB& flight4 = DB.addFlight("Alaska","SEA","NYC");
	FlightDB& flight5 = DB.addFlight("Delta","SEA","NYC");
	FlightDB& flight6 = DB.addFlight("SouthWest","SEA","NYC");

	DB.displayAllFlights();
	//Database flightDB;
	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			doPassengerInfo(DB);
			break;
		case 2:
			doFlightSearch(DB);
			break;
		case 3:
			doBook(DB);
			break;
		case 4:
			doDisplayTkt(DB);
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
	cout << "2. Search and display matching flights " << endl;
	cout << "3. Choose and Book your flight "<< endl;
	cout << "4. Display Ticketing Info:  " << endl;
	cout << "0. Quit " << endl;
	cout << "======================================================" << endl;

	cin >> selection;
	return selection;
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

void doFlightSearch(Database& db) {
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
	
	db.inputBookingReq(FromCity, ToCity);

	switch (search) {

	case 1:
		
		try {
			FlightDB& flight = db.getMatchingFlight(Airlines);
			
		}
		catch (const std::logic_error& exception) {
			cerr << "No matching flights found, search again! " << exception.what() << endl;
		}
		break;

	case 2:
	{
		try {
			FlightDB& flight = db.getMatchingFlight(FromCity, ToCity);
		}
		catch (const std::logic_error& exception) {
			cerr << "No matching flights found, search again! " << exception.what() << endl;
		}
		break;
	}


	}

	
}

void doBook(Database& db) {
	int FlightNum;

	cout << "Input the flight number of your choice for booking: " << endl;
	cin >> FlightNum;
	//db.getMatchingFlight(FlightNum);

	try {
		FlightDB& flight = db.getMatchingFlight(FlightNum);
		//flight.displayFlightInfo();
		flight.book();
		cout << "Flight number: " << FlightNum << "has been Booked. " << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "No matching flights found, search again! " << exception.what() << endl;
	}

}

void doDisplayTkt(Database& db){
/*
	cout << "                           AIRLINE TICKET                                 " << endl;
	cout << "|_________________________________________________________________________" << endl;
	cout << "|Passenger Information :                                                  " << endl;
	db.displayAllPassengers();
	cout << "|_________________________________________________________________________" << endl;
	cout << "|flight Information :                                                     " << endl;
	db.displayBookedFlight();
	cout << "|BOING 747                                                                " << endl;
	cout << "|_________________________________________________________________________" << endl;
	cout << "|*BAGGAGE allowed 40 Kilos                                                " << endl;
	cout << "|*contact Airline to Confirm baggage allowance                            " << endl;
	cout << "|_________________________________________________________________________" << endl;
*/
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
	