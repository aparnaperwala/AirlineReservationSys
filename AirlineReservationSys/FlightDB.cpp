#include "pch.h"
#include <iostream>
#include "FlightDB.h"

using namespace std;
namespace AirlineReservationSys {

	/*
	FlightDB::FlightDB(const std::string& Airlines,
		const std::string& FromCity,
		const std::string& ToCity,
		bool weekDay) : mAirlines(Airlines), mFromCity(FromCity), mToCity(ToCity), mweekDay(weekDay) {
	}*/
	
	FlightDB::FlightDB(const std::string& Airlines,
		const std::string& FromCity,
		const std::string& ToCity) : mAirlines(Airlines), mFromCity(FromCity), mToCity(ToCity) {}

	const std::string& FlightDB::getAirlines() const {
		return mAirlines;

	}

	void FlightDB::setAirlines(const std::string& Airlines) {
		mAirlines = Airlines;
	}

	const std::string& FlightDB::getFromCity() const {
		return mFromCity;
	}
	void FlightDB::setFromCity(const string& FromCity) {
		mFromCity = FromCity;
	}

	const std::string& FlightDB::getToCity() const {
		return mToCity;
	}
	void FlightDB::setToCity(const string& ToCity) {
		mToCity = ToCity;
	}
	
	bool FlightDB::IsWeekDayFlight() const {
		return mweekDay;
	}

	void FlightDB::weekDayFlights() {
		mweekDay = true;
	}
	void FlightDB::weekendFlights() {
		mweekDay = false;
	}
	void FlightDB::displayFlightInfo() const {
		cout << "Airlines is " << getAirlines() << endl;
		cout << "Flight Origin City is " << getFromCity() << endl;
		cout << "Flight Destination City is " << getToCity() << endl;
		//cout << (IsWeekDayFlight() ? "This is a Weekday flight " : "This is a Weekend Flight ") << endl;
		cout << endl;

	}

}