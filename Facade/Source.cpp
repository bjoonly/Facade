

#include "ObarivResort.h"

int main() {
	ObarivResort resort;
	try {
		resort.OneEveningPleasure({ Visitor(20,'f',1),Visitor(17,'f',0),Visitor(10,'m',0),Visitor(25,'m',1) });
		resort.OneHourPleasure({ Visitor(25,'m',0),Visitor(5,'f',0) });
		resort.OneNightPleasure({ Visitor(21, 'm', 1), Visitor(25, 'm', 1), Visitor(16, 'm', 0), Visitor(19, 'm', 1) });
		resort.HolidaysPleasure({ HolidayVisitor(17,'f',1,1,0,1,0,1), HolidayVisitor(19,'m',1,1,1,1,1,0) }, 10);
	}
	catch (exception ex) {
		cout << ex.what()<<endl;
	}
	return 0;
}