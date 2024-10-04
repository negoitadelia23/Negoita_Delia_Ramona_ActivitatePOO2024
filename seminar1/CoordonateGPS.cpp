#include <iostream>
using namespace std;
struct coord_GPS {
	int latitudine;
	int longitudine;
	int altitudine;
	string locatie;
};
void afisare_coordGPS(coord_GPS l)
{
	cout << "Latitudine: " << l.latitudine << endl;
	cout << "Longitudine: " << l.longitudine << endl;
	cout << "Altitudine: " << l.altitudine << endl;
	cout << "Locatie: " << l.locatie << endl;
}
void modificareAltitudine(coord_GPS *l, float nouaAltitudine) {
	l->altitudine = nouaAltitudine; // deferentiere + accesare = ->
}
void modificareAltitudineRef(coord_GPS &l, float nouaAltitudine) {
	l.altitudine = nouaAltitudine; // specific C++
}
coord_GPS initializareCoordGPS(int latitudine, int longitudine, int altitudine, string locatie) {
	coord_GPS l;
	l.latitudine = latitudine;
	l.longitudine = longitudine;
	l.altitudine = altitudine;
	l.locatie = locatie;
	return l;
}
int main() {
	coord_GPS l;
	l.latitudine = 46;
	l.longitudine = 92;
	l.altitudine = 1010;
	l.locatie = "Predeal";
	coord_GPS l1;
	cout<<"Introduceti latitudinea: ";
	cin >> l1.latitudine;
	cout << "Introduceti longitudinea: ";
	cin >> l1.longitudine;
	cout << "Introduceti altitudinea: ";
	cin >> l1.altitudine;
	cout << "Introduceti locatia: ";
	cin >> l1.locatie;
	afisare_coordGPS(l);
	afisare_coordGPS(l1);
	modificareAltitudine(&l, 2000);
	int a = 20;
	int *pa = &a;//ptr
	int *p = new int(50);//alocare dinamica
	modificareAltitudine(&l, 2000);
	return 0;
}