#include "pch.h"
#include "Database.h"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace AirlineReservationSys {

	Passenger& Database::addPassenger(const std::string& firstName,
		const std::string& lastName, const int& Age) {
		Passenger thePassenger(firstName, lastName, Age);
		mPassengers.push_back(thePassenger);
		return mPassengers[mPassengers.size() - 1];

	}

	FlightDB& Database::addFlight(const std::string& Airlines, 
		const std::string& FromCity,
		const std::string& ToCity){
		FlightDB theFlight(Airlines,FromCity,ToCity);
		mFlights.push_back(theFlight);
		return mFlights[mFlights.size() - 1];
		
	}
	
	FlightDB& Database::getMatchingFlight(const std::string& Airlines) {
		for (auto& flight : mFlights) {
			if (flight.getAirlines() == Airlines) {
				flight.displayFlightInfo();
				return flight;
			}
		}
		throw logic_error("No matching flight found. ");
	}

	FlightDB& Database::getMatchingFlight(const std::string& FromCity,
		const std::string& ToCity) {
		for (auto& flight : mFlights) {

			if (flight.getFromCity() == FromCity && flight.getToCity() == ToCity) {

				flight.displayFlightInfo();
				return flight;
			}
			//flight.displayFlightInfo();
			throw logic_error("No matching flight found. ");
		}
	}



	Passenger& Database::getPassenger(const std::string& firstName,
		const std::string& lastName) {
		for (auto& passenger : mPassengers) {
			if (passenger.getFirstName() == firstName &&
				passenger.getLastName() == lastName) {
				return passenger;
			}
		}
		throw logic_error("No employee found. ");
	}

	void Database::inputBookingReq(const std::string& FromCity,
		const std::string& ToCity){ 
		for (auto& passenger : mPassengers) {
			passenger.setFromCity(FromCity);
			passenger.setToCity(ToCity);	
		}
		
	}

	/*Passenger& Database::inputBookingReq(const std::string& FromCity,
										const std::string& ToCity) {
		for (auto& passenger : mPassengers) {
			passenger.setFirstName(FromCity);
			passenger.setToCity(ToCity);

		}

	}*/

/*
	void Database::displayWeekdayFlights() const {
		for (const auto& flight:mFlights) {
			if (flight.IsWeekDayFlight())
				flight.displayFlightInfo();
		}
	}*/
	/*
	void Database::displayWeekendFlights() const {
		for (const auto& flight : mFlights) {
			if (!flight.IsWeekDayFlight())
				flight.displayFlightInfo();
		}
	}*/

	void Database::displayAllFlights() const {
		for (const auto& flight : mFlights) {
			flight.displayFlightInfo();
		}
	}
	void Database::displayAllPassengers() const {
		for (const auto& passenger : mPassengers) {
			passenger.displayPassengerInfo();
		}
	}
}
