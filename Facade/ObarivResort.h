#pragma once
#include "Subsystems.h"
#include"Visitors.h"
class ObarivResort {
	class Pool visitPool;
	class Bar visitBar;
	class Billiard visitBilliard;
	class Massage visitMassage;
	class Hotel bookRoom;
	class Restaurant visitRestaurant;
public:
	int OneHourPleasure(const initializer_list<Visitor>&list)const;

	int OneEveningPleasure(const initializer_list<Visitor>& list)const;

	int OneNightPleasure(const initializer_list<Visitor> &list)const;

	int HolidaysPleasure(const initializer_list<HolidayVisitor>& list, int days)const;

};
