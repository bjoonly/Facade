#pragma once

struct Visitor {
	int age;
	char sex;
	bool needForAlcohol;

	Visitor(int age, char sex, bool needForAlcohol) {
		if (age < 0)
			age = 1;
		if (sex != 'm' && sex != 'f')
			sex = 'm';
		this->age = age;
		this->needForAlcohol = needForAlcohol;
		this->sex = sex;
	}
};
struct HolidayVisitor :public Visitor {
	bool visitingPool;
	bool visitingBilliard;
	bool dinner;
	bool breakfast;
	bool visitingMassage;

	HolidayVisitor(int age, char sex, bool needForAlcohol, bool visitingPool, bool visitingBilliard, bool breakfast, bool dinner, bool visitingMassage)
		:Visitor(age, sex, needForAlcohol), visitingBilliard(visitingBilliard), visitingMassage(visitingMassage), visitingPool(visitingPool), breakfast(breakfast), dinner(dinner) {}
};