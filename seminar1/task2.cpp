#include <iostream>
using namespace std;
class Telefon {
public:	char* nume;
		const string brand;
		int nivelbaterie;
		static int anlansare;
		Telefon() :brand("Samsung")
		{
			this->nume = new char[strlen("Galaxy") + 1];
			strcpy_s(this->nume, strlen("Galaxy") + 1, "Galaxy");
			this->nivelbaterie = 50;
}
		Telefon(const char* nume, int nivelbaterie, const string brand1) :brand(brand1)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
			this->nivelbaterie = nivelbaterie;
		}
		Telefon(const Telefon& t): brand(t.brand)
		{
			this->nume = new char[strlen(t.nume) + 1];
			strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
			this->nivelbaterie = t.nivelbaterie;
	}
		Telefon* Citire()
		{
			Telefon* t;
			t = new Telefon();
			cout << "Nume model= ";
			char buffer[100];
			cin >> buffer;
			this->nume = new char[strlen(buffer) + 1];
			strcpy_s(this->nume, strlen(buffer) + 1, buffer);
			cout << "Nivel baterie= ";
			cin >> this->nivelbaterie;
			return t;
		}
		static void afisare(Telefon* t)
		{
			cout << "Brand=" << t->brand << endl;
			cout << "Nume model= " << t->nume << endl;
			cout << "Nivel baterie= " << t->nivelbaterie << endl;
			cout << "An lansare= " << Telefon::anlansare << endl;
		}
		void setnume(char buffer[100])
		{
			cin >> buffer;
			if (strlen(buffer) > 1)
			{
				this->nume = new char[strlen(buffer) + 1];
				strcpy_s(this->nume, strlen(buffer) + 1, buffer);
			}
		}
};	
class PC {
public:string model;
	  char* producator;
	  int nivelbaterie;
	  const int memorieRAM;
	  static string producator_procesor;
	  bool aretouchscreen;
	  PC() :memorieRAM(16)
	  {
		  this->producator = new char[strlen("DELL" + 1)];
		  strcpy_s(this->producator, strlen("DELL") + 1, "DELL");
		  this->nivelbaterie = 50;
		  this->aretouchscreen = aretouchscreen;
	  }
	  PC(const char* producator, int nivelbaterie, const int memorieRAM, bool aretouchscreen) : memorieRAM(memorieRAM) {
		  this->producator = new char[strlen(producator) + 1];
		  strcpy_s(this->producator, strlen(producator) + 1, producator);
		  this->nivelbaterie = nivelbaterie;
		  this->aretouchscreen = aretouchscreen;
	  }
	  PC(const PC& pc) :memorieRAM(pc.memorieRAM)
	  {
		  this->producator = new char[strlen(pc.producator + 1)];
		  strcpy_s(this->producator, strlen(pc.producator) + 1, pc.producator);
		  this->nivelbaterie = pc.nivelbaterie;
		  this->aretouchscreen = pc.aretouchscreen;
	  }
	  void cresterenivelbat()
	  {
		  if(this->nivelbaterie>0 && this->nivelbaterie<100)
		  this->nivelbaterie=this->nivelbaterie++;
	  }
	  static void Verif_Are_Touch_Screen(PC pc)
	  {
		  cout << "Are touch screen: " << (pc.aretouchscreen ? "DA" : "NU") << endl;
	  }
};
class Televizor
{public:
	const string marca;
	static string rezolutie;
	float diagonala;
	bool smart;
	char* model;
	float pret;
	Televizor() :marca("LG")
	{
		this->diagonala = 3.5;
		this->smart = 0;
		if (this->model != nullptr)
			delete[]this->model;
		this->model = new char[strlen("Y" + 1)];
		strcpy_s(this->model, strlen("Y") + 1, "Y");
		this->pret = 300;
	}
	Televizor(const string marca, float diagonala, bool smart, const char* model, float pret) :marca(marca)
	{
		this->diagonala = diagonala;
		this->smart = smart;
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
		this->pret = pret;
	}
	Televizor(const Televizor& tv) :marca(tv.marca)
	{
		this->diagonala = tv.diagonala;
		this->smart = tv.smart;
		this->model = new char[strlen(tv.model) + 1];
		strcpy_s(this->model, strlen(tv.model) + 1, tv.model);
		this->pret = tv.pret;
	}
	static float inch_to_cm(Televizor tv)
	{
		return tv.diagonala * 2.54;
	}

	void Verificare_Smart()
	{
		cout << "Este televizor smart: " << (this->smart ? "DA" : "NU") << endl;
	}
};
int Telefon::anlansare = 2021;
string PC::producator_procesor = "Intel";
string Televizor::rezolutie = "LED";
int main()
{	Telefon* t1;
	t1 = new Telefon();
	//t1->Citire();
	Telefon t2("Iphone", 93, "Apple");
	Telefon::afisare(t1);
	Telefon::afisare(&t2);
	Telefon t3 = t2;
	Telefon::afisare(&t3);
	PC pc1;
	pc1.cresterenivelbat();
	cout << pc1.nivelbaterie << endl;
	PC pc2("Lenovo", 99, 16, 1);
	pc2.cresterenivelbat();
	cout << pc2.nivelbaterie << endl;
	PC::Verif_Are_Touch_Screen(pc2);
	PC pc3 = pc2;
	Televizor tv1;
	Televizor tv2("LG", 23.4, 1, "XPS", 3000);
	Televizor tv3 = tv2;
	cout << Televizor::inch_to_cm(tv2)<<endl;
	return 0;
}