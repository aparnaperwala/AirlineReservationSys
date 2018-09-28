#include "pch.h"
#include <iostream>
#include "Passenger.h"

using namespace std;

namespace AirlineReservationSys {

	Passenger::Passenger(const std::string& firstName,
		const std::string& lastName, const int& Age) : mFirstName(firstName), mLastName(lastName), mAge(Age) {

	}
	
	Passenger::Passenger(const std::string& firstName,
		const std::string& lastName, const int& Age,
		const std::string& FromCity,
		const std::string& ToCity, 
		const std::string& Airlines) : mFirstName(firstName),
		mLastName(lastName), mAge(Age), mFromCity(FromCity), mToCity(ToCity), mAirlines(Airlines) {

	}
	
	const std::string& Passenger::getFirstName() const {
		return mFirstName;
	}

	void Passenger::setFirstName(const string& firstName) {
		mFirstName = firstName;
	}


	const std::string& Passenger::getLastName() const {
		return mLastName;
	}
	void Passenger::setLastName(const string& LastName) {
		mLastName = LastName;
	}


	const int& Passenger::getAge() const {
		return mAge;
	}

	void Passenger::setAge(const int& Age) {
		mAge = Age;
	}

	const std::string& Passenger::getFromCity() const {
		return mFromCity;
	}
	void Passenger::setFromCity(const string& FromCity) {
		mFromCity = FromCity;
	}

	const std::string& Passenger::getToCity() const {
		return mToCity;
	}
	void Passenger::setToCity(const string& ToCity) {
		mToCity = ToCity;
	}

	const std::string& Passenger::getAirlines() const {
		return mAirlines;
	}

	void Passenger::setAirlines(const std::string& Airlines) {
		mAirlines = Airlines;
	}

	void Passenger::book()
	{
		mBooked = true;
	}

	void Passenger::cancel()
	{
		mBooked = false;
	}

	bool Passenger::isBooked() const {
		return mBooked;
	}

	void Passenger::displayPassengerInfo() const {

		cout << "Passenger " << getLastName() << "," << getFirstName() << "," << getAge() << endl;
		cout << "----------------------------------------------------------" << endl;
	}

	void Passenger::displayBookingReq() const {
		cout << "Booking from City " << getFromCity() << "," << "Booking to City" << getToCity() << "." << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		//cout << "Travel day of the week is  " <<  << endl;
	}


	/*const std::string& Passenger::getDoT() const{
		return mDoT;
	}

		void Passenger::setDoT(const string& DoT) {
		mDoT = DoT;
	}

*/

	
}
