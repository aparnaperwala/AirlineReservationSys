#pragma once
#include <string>


namespace AirlineReservationSys {
	
	class Passenger {
	public:
		Passenger() = default;
		Passenger(const std::string& firstName,
			const std::string& lastName, const int& Age);

		Passenger(const std::string& firstName,
			const std::string& lastName, const int& Age, 
			const std::string& FromCity, 
			const std::string& ToCity,
			const std::string& Airlines);

		const std::string& getFirstName() const;
		void setFirstName(const std::string& firstName);

		const std::string& getLastName() const;
		void setLastName(const std::string& LastName);
		
		const std::string& getFromCity() const;
		void setFromCity(const std::string& FromCity);

		const std::string& getToCity() const;
		void setToCity(const std::string& ToCity);

		const int& getAge() const;
		void setAge(const int& Age);

		const std::string& getAirlines() const;
		void setAirlines(const std::string& Airlines);
		
		void displayPassengerInfo() const;
		void displayBookingReq() const;

		void book();
		void cancel();
		bool isBooked() const;
		
		//const std::string& getDoT() const;
		//void setDoT(const std::string& DoT);
		//bool setweekDay() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		int mAge;
		std::string mFromCity;
		std::string mToCity;
		std::string mDoT;
		bool mBooked = false;
		std::string mAirlines;


	};
}
