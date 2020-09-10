#include "ObarivResort.h"

int ObarivResort::OneHourPleasure(const initializer_list<Visitor>& list)const {
	int res = 0, price = 0, numberOfVisitor = 1;
	cout << "\nOne hour pleasure for " << list.size() << " visitors" << endl;
	for (auto visitor : list) {
		price = visitPool.VisitPool(visitor.age);
		cout << endl << numberOfVisitor << ".Visiting pool:\nPrice: " << price << endl;
		res += price;
		price = visitMassage.VisitMassage(visitor.sex, visitor.age);
		cout << "\nVisiting massage:\nPrice: " << price << endl;
		res += price;
		numberOfVisitor++;
	}
	cout << "\t\t\t\tTotal: " << res << " uah.\n";
	return res;
}

int ObarivResort::OneEveningPleasure(const initializer_list<Visitor> &list)const {
	int res = 0, price = 0, numberOfVisitor = 1;
	cout << "\nOne evening pleasure for " << list.size() << " visitors" << endl;
	for (auto visitor : list) {
		price = visitMassage.VisitMassage(visitor.sex, visitor.age);
		cout << endl << numberOfVisitor << ".Visiting massage:\nPrice: " << price << endl;
		res += price;
		price = visitBilliard.VisitBilliard();
		cout << "\nVisiting billiard:\nPrice: " << price << endl;
		res += price;
		if (visitor.needForAlcohol && visitor.age >= 18) {
			price = visitBar.VisitBar(visitor.sex, visitor.age);
			cout << "\nVisiting bar:\nPrice: " << price << endl;
			res += price;
		}
		price = visitRestaurant.Dinner(visitor.age);
		cout << "\nDinner in restaurant:\nPrice: " << price << endl;
		res += price;
		numberOfVisitor++;
	}
	cout << "\t\t\t\tTotal: " << res << " uah.\n";
	return res;
}

int ObarivResort::OneNightPleasure(const initializer_list<Visitor>&list)const {
	int res = 0, price = 0, numberOfVisitor = 1, countRooms = 0;
	cout << "One night pleasure for " << list.size() << " visitors" << endl;

	if (list.size() <= 4)
		price = bookRoom.BookRoom(list.size(), 1);
	else {
		price = bookRoom.BookRoom(4, 1);
		price *= list.size() / 4;
		price += bookRoom.BookRoom(list.size() % 4, 1);
	}
	cout << "\nBooking room for " << list.size() << " visitors for 1 day:\nPrice: " << price << endl;
	res += price;

	for (auto visitor : list) {
		price = visitRestaurant.Dinner(visitor.age);
		cout << endl << numberOfVisitor << ".Dinner in restaurant:\nPrice: " << price << endl;
		res += price;
		price = visitBilliard.VisitBilliard();
		cout << "\nVisiting billiard:\nPrice: " << price << endl;
		res += price;
		if (visitor.needForAlcohol && visitor.age >= 18) {
			price = visitBar.VisitBar(visitor.sex, visitor.age);
			cout << "\nVisiting bar:\nPrice: " << price << endl;
			res += price;
		}
		price = visitRestaurant.Breakfast(visitor.age);
		cout << "\nBreakfast in restaurant:\nPrice: " << price << endl;
		res += price;
		numberOfVisitor++;
	}
	cout << "\t\t\t\tTotal: " << res << " uah.\n";
	return res;
}

int ObarivResort::HolidaysPleasure(const initializer_list<HolidayVisitor> &list, int days)const {
	int res = 0, price = 0, numberOfVisitor = 1;

	if (days <= 7)
		days = 7;
	else if (days <= 10)
		days = 10;
	else if (days <= 14)
		days = 14;
	else if (days <= 20)
		days = 20;
	else if (days <= 30)
		days = 30;
	else
		throw exception("Invalid booking days");

	cout << "Holidays pleasure for " << list.size() << " visitors.For " << days << " days.\n";

	if (list.size() <= 4)
		price = bookRoom.BookRoom(list.size(), days);
	else {
		price = bookRoom.BookRoom(4, 1);
		price *= list.size() / 4;
		price += bookRoom.BookRoom(list.size() % 4, days);
	}

	cout << "Room for " << list.size() << " visitors for " << days << " days:\nPrice " << price << endl;
	res += price;

	for (auto &visitor : list) {

		price = visitRestaurant.Lunch(visitor.age);
		cout << endl << numberOfVisitor << ".Lunch in restaurant:\nPrice: " << price << endl;
		price *= days;
		cout << "For " << days << " days: " << price << endl;
		res += price;

		if (visitor.breakfast) {
			price = visitRestaurant.Breakfast(visitor.age);
			cout << "\nBreakfast in restaurant:\nPrice: " << price << endl;
			price *= days;
			cout << "For " << days << " days: " << price << endl;
			res += price;
		}

		if (visitor.dinner) {
			price = visitRestaurant.Dinner(visitor.age);
			cout << "\nDinner in restaurant:\nPrice: " << price << endl;
			price *= days;
			cout << "For " << days << " days: " << price << endl;
			res += price;
		}

		if (visitor.visitingBilliard) {
			price = visitBilliard.VisitBilliard();
			cout << "\nVisiting billiard:\nPrice: " << price << endl;
			price *= days;
			cout << "For " << days << " days: " << price << endl;
			res += price;
		}

		if (visitor.needForAlcohol && visitor.age >= 18) {
			price = visitBar.VisitBar(visitor.sex, visitor.age);
			cout << "\nVisiting bar:\nPrice: " << price << endl;
			price *= days;
			cout << "For " << days << " days: " << price << endl;
			res += price;
		}

		if (visitor.visitingPool) {
			price = visitPool.VisitPool(visitor.age);
			cout << "\nVisiting pool:\nPrice: " << price << endl;
			price *= days;
			cout << "For " << days << " days: " << price << endl;
			res += price;
		}

		if (visitor.visitingMassage) {
			price = visitMassage.VisitMassage(visitor.sex, visitor.age);
			cout << "\nVisiting massage:\nPrice: " << price << endl;
			price *= days;
			cout << "For " << days << " days: " << price << endl;
			res += price;
		}

		numberOfVisitor++;
	}
	cout << "\t\t\t\tTotal: " << res << " uah.\n";
	return res;
}