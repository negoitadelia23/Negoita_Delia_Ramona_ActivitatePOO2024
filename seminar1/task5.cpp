#include <iostream>
using namespace std;
class Telefon {
	char* nume;
	const string brand;
	int nivelbaterie;
	static int anlansare;
public:
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
	Telefon(const Telefon& t) : brand(t.brand)
	{
		this->nume = new char[strlen(t.nume) + 1];
		strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
		this->nivelbaterie = t.nivelbaterie;
	}
	Telefon& operator=(const Telefon& t) {
		if (&t != this)
		{
			if (this->nume != nullptr)
			{
				delete[]this->nume;
			}
			this->nume = new char[strlen(t.nume) + 1];
			strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
			this->nivelbaterie = t.nivelbaterie;
		}
		return *this;
	}
	~Telefon()
	{
		if (this->nume != nullptr)
		{
			delete[]this->nume;
		}
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
	friend istream& operator>>(istream& in, Telefon& t)
	{
		cout << "Nume model= ";
		char buffer[100];
		in >> buffer;
		t.nume = new char[strlen(buffer) + 1];
		strcpy_s(t.nume, strlen(buffer) + 1, buffer);
		cout << "Nivel baterie= ";
		in >> t.nivelbaterie;
		cout << "An lansare= ";
		in >> Telefon::anlansare;
		return in;
	}
	static void afisare(Telefon* t)
	{
		cout << "Brand=" << t->brand << endl;
		cout << "Nume model= " << t->nume << endl;
		cout << "Nivel baterie= " << t->nivelbaterie << endl;
		cout << "An lansare= " << Telefon::anlansare << endl;
	}
	friend ostream& operator<<(ostream& out, Telefon& t)
	{
		out << "Brand=" << t.brand << endl;
		out << "Nume model= " << t.nume << endl;
		out << "Nivel baterie= " << t.nivelbaterie << endl;
		out << "An lansare= " << Telefon::anlansare << endl;
		return out;
	}
	operator int()
	{
		return this->nivelbaterie;
	}
	char* getnume()
	{
		return this->nume;
	}
	void setnume(char buffer[100])
	{
		if (strlen(buffer) > 1)
		{
			this->nume = new char[strlen(buffer) + 1];
			strcpy_s(this->nume, strlen(buffer) + 1, buffer);
		}
	}
	int getnivelbaterie()
	{
		return this->nivelbaterie;
	}
	void setnivelbaterie(int nivel)
	{
		if (this->nivelbaterie > 0 && this->nivelbaterie < 100)
			this->nivelbaterie = nivel;
	}
	static int getanlansare()
	{
		return Telefon::anlansare;
	}
	static void setanlansare(int an)
	{
		if (an > 2000)
			Telefon::anlansare = an;
	}

};
class PC {
	string model;
	char* producator;
	int nivelbaterie;
	const int memorieRAM;
	static string producator_procesor;
	bool aretouchscreen;
public:
	PC() :memorieRAM(16)
	{
		this->producator = new char[strlen("DELLXPS") + 1];
		strcpy_s(this->producator, strlen("DELLXPS") + 1, "DELLXPS");
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
		this->producator = new char[strlen(pc.producator) + 1];
		strcpy_s(this->producator, strlen(pc.producator) + 1, pc.producator);
		this->nivelbaterie = pc.nivelbaterie;
		this->aretouchscreen = pc.aretouchscreen;
	}
	PC& operator=(const PC& pc)
	{
		if (&pc != this)
		{
			if (this->producator != nullptr) {
				delete[] this->producator;
				this->producator = nullptr;
			}
			this->producator = new char[strlen(pc.producator) + 1];
			strcpy_s(this->producator, strlen(pc.producator) + 1, pc.producator);
			this->nivelbaterie = pc.nivelbaterie;
			this->aretouchscreen = pc.aretouchscreen;
		}
		return *this;
	}
	~PC()
	{
		if (this->producator != nullptr) {
			delete[] this->producator;
			this->producator = nullptr;
		}
	}
	void cresterenivelbat()
	{
		if (this->nivelbaterie > 0 && this->nivelbaterie < 100)
			this->nivelbaterie = this->nivelbaterie++;
	}
	PC operator++()
	{
		if (this->nivelbaterie > 0 && this->nivelbaterie < 100)
			this->nivelbaterie++;
		return *this;
	}
	PC operator++(int)
	{
		PC pc = *this;
		this->nivelbaterie++;
		return pc;
	}
	PC operator+(int baterie)
	{
		PC temp = *this;
		if (baterie <= 100 - temp.nivelbaterie)
			temp.nivelbaterie = temp.nivelbaterie + baterie;
		return temp;
	}
	friend istream& operator>>(istream& in, PC& pc)
	{
		cout << "Model= ";
		in >> pc.model;
		cout << "Producator= ";
		char buffer[100];
		in >> buffer;
		pc.producator = new char[strlen(buffer) + 1];
		strcpy_s(pc.producator, strlen(buffer) + 1, buffer);
		cout << "Nivel baterie= ";
		in >> pc.nivelbaterie;
		cout<< "Producatorul procesorului= ";
		in >> PC::producator_procesor;
		cout << "Are touch screen ? (0 NU, 1 DA) - ";
		in >> pc.aretouchscreen;
		return in;
	}
	friend ostream& operator<<(ostream& out, PC& pc)
	{
		out << "Model=" << pc.model << endl;
		out << "Producator= " << pc.producator << endl;
		out << "Nivel baterie= " << pc.nivelbaterie << endl;
		out << "Producator procesor= " << PC::producator_procesor << endl;
		out << "Are touch screen= " << (pc.aretouchscreen ? "DA" : "NU");
		return out;
	}
	static void Verif_Are_Touch_Screen(PC pc)
	{
		cout << "Are touch screen: " << (pc.aretouchscreen ? "DA" : "NU") << endl;
	}
	int getnivelbaterie()
	{
		return this->nivelbaterie;
	}
	void setnivelbaterie(int nivel)
	{
		if (nivel >= 0 && nivel < 100)
			this->nivelbaterie = nivel;
	}
	string getmodel()
	{
		return this->model;
	}
	void setmodel(string model)
	{
		if (model.length() > 1)
			this->model = model;
	}
	bool getaretouchscreen()
	{
		return this->aretouchscreen;
	}
	void setaretouchscreen(bool boolean)
	{
		this->aretouchscreen = boolean;
	}
	static string getproducator_procesor()
	{
		return PC::producator_procesor;
	}
	static void setproducator_procesor(string prod)
	{
		if (prod.length() > 2)
			PC::producator_procesor = prod;
	}

};
class Televizor
{
	const string marca;
	static string rezolutie;
	float diagonala;
	bool smart;
	char* model;
	float pret;
public:
	Televizor() :marca("LG")
	{
		this->diagonala = 3.5;
		this->smart = 0;
		this->model = new char[strlen("YZX") + 1];
		strcpy_s(this->model, strlen("YZX") + 1, "YZX");
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
	Televizor& operator=(const Televizor& tv)
	{
		if (&tv != this)
		{
			if (this->model != nullptr) {
				delete[] this->model;
				this->model = nullptr;
			}
			this->diagonala = tv.diagonala;
			this->smart = tv.smart;
			this->model = new char[strlen(tv.model) + 1];
			strcpy_s(this->model, strlen(tv.model) + 1, tv.model);
			this->pret = tv.pret;
		}
		return *this;
	}
	bool operator>=(Televizor& tv)
	{
		return this->diagonala >= tv.diagonala;
	}
	Televizor operator!()
	{
		Televizor temp = *this;
		temp.smart = !this->smart;
		return temp;
	}
	float operator()()//calculeaza pret total tv
	{
		return 1.19 * this->pret;
	}
	friend istream& operator>>(istream& in, Televizor& tv)
	{
		cout << "Rezolutie= ";
		in >> Televizor::rezolutie;
		cout << "Diagonala= ";
		in >> tv.diagonala;
		cout << "Este smart? (0 NU, 1 DA) ";
		in >> tv.smart;
		cout << "Model= ";
		char buffer[100];
		in >> buffer;
		tv.model = new char[strlen(buffer) + 1];
		strcpy_s(tv.model, strlen(buffer) + 1, buffer);
		cout << "Pret= ";
		in >> tv.pret;
		return in;
	}
	friend ostream& operator<<(ostream& out, Televizor& tv)
	{
		out << "Marca= " << tv.marca << endl;
		out << "Rezolutie= " << Televizor::rezolutie << endl;
		out << "Diagonala= " << tv.diagonala << endl;
		out << "Este smart= " << (tv.smart ? "DA" : "NU") << endl;
		out << "Model= " << tv.model << endl;
		out << "Pret= " << tv.pret << endl;
	}
	~Televizor()
	{
		if (this->model != nullptr) {
			delete[] this->model;
			this->model = nullptr;
		}
	}
	static float inch_to_cm(Televizor tv)
	{
		return tv.diagonala * 2.54;
	}

	void Verificare_Smart()
	{
		cout << "Este televizor smart: " << (this->smart ? "DA" : "NU") << endl;
	}
	static string getrezolutie()
	{
		return Televizor::rezolutie;
	}
	static void setrezolutie(string rez)
	{
		if (rez.length() > 2)
			Televizor::rezolutie = rez;
	}
	float getdiagonala()
	{
		return this->diagonala;
	}
	void setdiagonala(float diag)
	{
		if (diag > 10.0f)
			this->diagonala = diag;
	}
	bool getsmart()
	{
		return this->smart;
	}
	void setsmart(bool smarttv)
	{
		this->smart = smarttv;
	}
	char* getmodel()
	{
		return this->model;
	}
	void setmodel(char buffer[100])
	{
		if (strlen(buffer) > 4)
		{
			this->model = new char[strlen(buffer) + 1];
			strcpy_s(this->model, strlen(buffer) + 1, buffer);
		}
	}
	float getpret()
	{
		return this->pret;
	}
	void setpret(float pretnou)
	{
		if (pretnou >= 0.00f)
			this->pret = pretnou;
	}
	friend float pretcrescut(float pret, Televizor tv);
	friend float diagonalanoua(float diag, Televizor tv);

};
int Telefon::anlansare = 2021;
string PC::producator_procesor = "Intel";
string Televizor::rezolutie = "LED";

float pretcrescut(float pret, Televizor tv)
{
	if (pret > 0.0f)
	{
		tv.pret += pret;
		return tv.pret;
	}
}
float diagonalanoua(float diag, Televizor tv)
{
	if (diag > 0.0f)
	{
		tv.diagonala = diag;
		return tv.diagonala;
	}
}
int main()
{
	int numar=2;
	Telefon* telefoane;
	telefoane = new Telefon[numar];
	for (int i = 0; i < numar; i++)
		cin >> telefoane[i];
	for (int i = 0; i < numar; i++)
		cout << telefoane[i] << endl;
	PC** pc;
	pc = new PC * [numar];
	for (int i = 0; i < numar; i++)
		pc[i] = new PC();
	for (int i = 0; i < numar; i++)
		cin >> *pc[i];
	for (int i = 0; i < numar; i++)
		cout << *pc[i] << endl;
	Televizor* tv;
	tv = new Televizor[numar];
	for (int i = 0; i < numar; i++)
		cin >> tv[i];
	for (int i = 0; i < numar; i++)
		cout << tv[i] << endl;
	delete[] tv;
	for (int i = 0; i < numar; i++)
		delete pc[i];
	delete[] pc;
	delete[] telefoane;
	return 0;
}