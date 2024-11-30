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
	  static void afisare(Telefon* t)
	  {
		  cout << "Brand=" << t->brand << endl;
		  cout << "Nume model= " << t->nume << endl;
		  cout << "Nivel baterie= " << t->nivelbaterie << endl;
		  cout << "An lansare= " << Telefon::anlansare << endl;
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
		  if(this->nivelbaterie > 0 && this->nivelbaterie < 100)
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

float pretcrescut(float pret,Televizor tv)
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
	Telefon* t1;
	t1 = new Telefon();
	//t1->Citire();
	Telefon t2("Iphone", 93, "Apple");
	Telefon::afisare(t1);
	Telefon::afisare(&t2);
	Telefon t3 = t2;
	Telefon::afisare(&t3);
	PC pc1;
	pc1.cresterenivelbat();
	cout << pc1.getnivelbaterie() << endl;
	PC pc2("Lenovo", 99, 16, 1);
	pc2.cresterenivelbat();
	cout << pc2.getnivelbaterie() << endl;
	PC::Verif_Are_Touch_Screen(pc2);
	PC pc3 = pc2;
	Televizor tv1;
	Televizor tv2("LG", 23.4, 1, "XPS", 3000);
	Televizor tv3 = tv2;
	cout << Televizor::inch_to_cm(tv2) << endl;
	cout << pretcrescut(300, tv2);
	return 0;
}