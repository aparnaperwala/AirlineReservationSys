#pragma once
#include <iostream>
#include <vector>
#include "Passenger.h"

namespace AirlineReservationSys {
	
	//const int kNumofTkts = 1;

	class FlightDB {
	public:
		/*
		Passenger& addPassenger(const std::string& firstName,
			const std::string& lastName);
		Passenger& getPassenger(const std::string& firstName,
			const std::string& lastName);

		void displayAllPassengers() const;
		*/
		FlightDB() = default;
		/*FlightDB(const std::string& Airlines,
			const std::string& FromCity,
			const std::string& ToCity,
			bool weekDay);*/
		
		FlightDB(const std::string& Airlines,
			const std::string& FromCity,
			const std::string& ToCity);

		const std::string& getAirlines() const;
		void setAirlines(const std::string& Airlines);

		const std::string& getFromCity() const;
		void setFromCity(const std::string& FromCity);

		const std::string& getToCity() const;
		void setToCity(const std::string& ToCity);


		void displayFlightInfo() const;
		bool IsWeekDayFlight() const;
		void weekDayFlights();
		void weekendFlights();
		

	private:
		/*
		std::vector<Passenger> mPassengers;
		int mNumTkts = kNumofTkts;
		*/
		std::string mAirlines;
		std::string mFromCity;
		std::string mToCity;
		bool mweekDay= true;



	};

}