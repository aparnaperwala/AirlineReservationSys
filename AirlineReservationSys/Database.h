#pragma once
#include <iostream>
#include <vector>
#include "FlightDB.h"
#include "Passenger.h"
#include "pch.h"

namespace AirlineReservationSys {

	class Database {
	public:

		const int kFirstFlight = 1;

		Passenger& addPassenger(const std::string& firstName,
			const std::string& lastName, const int& Age);

		FlightDB& addFlight(const std::string& Airlines, 
			const std::string& FromCity,
			const std::string& ToCity);
			/*bool weekDay*/
		
		Passenger& getPassenger(const std::string& firstName,
			const std::string& lastName);
		
		FlightDB& getMatchingFlight(const std::string& Airlines);
		
		
		FlightDB& getMatchingFlight(const std::string& FromCity,
			const std::string& ToCity);

		FlightDB& getMatchingFlight(int FlightNum);


		/*FlightDB& getMatchingFlight(const std::string& Airlines, 
			const std::string& FromCity,
			const std::string& ToCity,
			bool weekDay);*/
		

		void inputBookingReq(const std::string& FromCity,
			const std::string& ToCity);
			/*bool weekDay*/;
		
		/*Passenger& inputBookingReq(const std::string& FromCity,
									const std::string& ToCity);*/

		//void displayAllPassengers() const;
		//void displayWeekdayFlights() const;
		//void displayWeekendFlights() const;
		void displayAllFlights() const;
		void displayAllPassengers() const;
		//void displayBookedFlight() const;
		
	private:
		std::vector<FlightDB> mFlights;
		std::vector<Passenger> mPassengers;
		int mFlightNum = kFirstFlight;
		

	};

}
