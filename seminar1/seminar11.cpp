#include <iostream>
using namespace std;

class Angajat {
protected:
	int marca;
	string nume;
	float salariu;
public:
	Angajat()
	{
		this->marca = 1234;
		this->nume = "No name";
		this->salariu = 4934.45;
	}
	Angajat(int marca, string nume, float salariu)
	{
		this->marca = marca;
		this->nume = nume;
		this->salariu = salariu;
	}
	float getSalariu() {
		return this->salariu;
	}
	virtual float getVenitIncasat() = 0;//aceasta metoda nu exista
};
class Cercetator :public Angajat {
public:
	Cercetator(int marca, string nume, float salariu) :Angajat(marca, nume, salariu)
	{

	}
	float getVenitIncasat()
	{
		return this->salariu;
	}
};
class Manager:public Angajat {
private:
	int nrSubordonati;
	float sporPerSubordonat;
public:
	Manager() :Angajat() {
		this->nrSubordonati = 0;
		this->sporPerSubordonat = 0;
	}
	Manager(int numar, float spor) :Angajat() {
		this->nrSubordonati = numar;
		this->sporPerSubordonat = spor;
	}
	float getSporConducere() {
		return this->nrSubordonati * this->sporPerSubordonat;
	}
};
class ManagerDepartament :public Manager {
	string numeDepartament;
	bool deCercetatare;
public:
	ManagerDepartament() :Manager() {
		this->numeDepartament = "Departament";
		this->deCercetatare = false;
	}
	ManagerDepartament(string nume, bool cercetare, int numar, float spor):Manager(numar, spor)
	{
		this->numeDepartament = nume;
		this->deCercetatare = cercetare;
	}
	float getVenitIncasat()
	{
		float venit = this->salariu;
		venit += this->getSporConducere();
		if (this->deCercetatare)
			venit += 0.1 * this->salariu;
		return venit;
	}
};

class ManagerDeProiect :public Manager {
	string numeProiect;
	int nrZile;
	float sporPerZi;
public:
	ManagerDeProiect() :Manager() {
		this->numeProiect = "Proiect";
		this->nrZile = 0;
		this->sporPerZi = 0;
	}
	ManagerDeProiect(string nume, int nrZile, float sporPerZi, int numar, float spor) :Manager(numar, spor) {
		this->numeProiect = nume;
		this->nrZile = nrZile;
		this->sporPerZi = sporPerZi;
	}
	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		venit += (this->nrZile * this->sporPerZi);
		return venit;
	}
};
int main() {
	//Angajat a;//nu pot crea obiect de tip unei cls abstracte
	// Manager m;//nu pot crea obiect de tip unei cls abstracte
	//etc
	ManagerDepartament md;//yay, pointerul din tabelul de pointeri la fctii virtuale NU mai e null
	Angajat* pointer;
	//pointer = new Angajat();//nu merge
	//pointer = nullptr;//merge
	pointer = new ManagerDepartament();//yay
	pointer->getVenitIncasat();//legatura tarzie / late binding - la momentul executiei
	//early bidingul este la compilare
	int nrAng = 5;
	Angajat** vector = new Angajat * [nrAng];
	vector[0] = new ManagerDepartament();
	vector[1] = new ManagerDeProiect();
	vector[2] = new ManagerDeProiect("TODO LIST", 10, 30, 4, 15);
	vector[3] = new ManagerDepartament("AI", true, 10, 15);
	vector[4] = new Cercetator(9876, "Pop", 7000);
	for (int i = 0; i < nrAng; i++)
		cout <<(i+1)<<". "<< vector[i]->getVenitIncasat() << endl;
	return 69;
}