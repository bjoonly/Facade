#pragma once
#include<iostream>
#include<string>
using namespace std;
class Hotel {
public:
	int BookRoom(int numberOfGusts, int timeRent)const{
		int res = 0;
		switch (numberOfGusts) {
		case 1:
			res += 230;
			break;
		case 2:
			res += 330;
			break;
		case 3:
			res += 430;
			break;
		case 4:
			res += 530;
			break;
		default:
			throw exception("No rooms for the selected number of people.\n");
		}
		switch (timeRent) {
		case 1:
			res += 20;
			break;
		case 7:
			res = res * 7 + 20 * 7;
			break;
		case 10:
			res = res * 9 + 20 * 9;
			break;
		case 14:
			res = res * 12 + 15 * 12;
			break;
		case 20:
			res = res * 17 + 15 * 17;
			break;
		case 30:
			res = res * 27 + 10 * 27;
			break;
		default:
			throw exception("Unable to rent a room for the selected number of days.\n");
		}
		return res;
	}
};
class Restaurant {
public:
	int Breakfast(int age)const {
		if (age < 12)
			return 80;

		return 100;
	}
	int Lunch(int age)const {
		if (age < 12)
			return 210;
		return 250;
	}
	int Dinner(int age)const {
		if (age < 12)
			return 160;
		return 200;
	}

};
class Bar {
public:
	int VisitBar(char sex, int fullYears)const {
		if (fullYears < 18)
			throw exception("Incorrect age.\n");
		if (sex != 'm' && sex != 'f')
			throw exception("Incorrect sex.\n");
		if (sex == 'f')
			return 150;
		return 200;
	}
};
class Pool {
public:
	int VisitPool(int age) const {

		if (age < 0)
			throw exception("Incorrect age.\n");
		else if (age < 6)
			return 40;
		else if (age < 12)
			return 80;

		return 120;
	}
};
class Massage {
public:
	int VisitMassage(char sex, int age)const {
		if (age < 0)
			throw exception("Incorrect age.\n");
		else if (sex != 'm' && sex != 'f')
			throw exception("Incorrect sex.\n");
		else if (age < 6)
			return 50;
		else if (age < 16)
			return 90;
		else if (sex == 'f')
			return 250;
		return 230;
	}
};
class Billiard {
public:
	int VisitBilliard()const {
		return 150;
	}
};