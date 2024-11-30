#include<iostream>

using namespace std;

class Masina {
private:
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2024), nrRoti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}
	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++) {
			this->producatori[i] = "Michelin";
		}
	}
	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrRoti];
		for (int i = 0; i < m.nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}
	Masina operator=(const Masina& m) {
		if (this != &m) {
			this->nrRoti = m.nrRoti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[m.nrRoti];
			for (int i = 0; i < m.nrRoti; i++) {
				this->producatori[i] = m.producatori[i];
			}
		}
		return *this;
	}


	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}

	Masina operator+(const Masina& m) const {
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	Masina operator+=(Masina m) {
		this->pret = this->pret + m.pret;
		return *this;
	}

	Masina operator+=(float adaosPret) {
		this->pret += adaosPret;
		return *this;
	}

	Masina operator+(float adaosPret)const {
		Masina temp = *this;
		temp.pret += adaosPret;
		return temp;
	}

	friend Masina operator+(float adaosPret, Masina m) {
		Masina temp = m;
		temp.pret += adaosPret;
		return temp;
	}
	explicit operator float()
	{
		return calculeazaPretTotal();
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			throw "Indexul este in afara limitelor.";
		}
	}
	explicit operator int()
	{
		return this->nrRoti;
	}
	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}
	float getPret() {
		return this->pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	string* getProducatori() {
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			return "NU a fost gasit.";
		}
	}
	int getNrRoti()
	{
		return this->nrRoti;
	}
	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << ": ";
		if (this->producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + (this->pret * (Masina::TVA / 100.0f));
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}

	bool operator<(Masina m) {
		return this->pret < m.pret;
	}
	friend istream& operator>>(istream& input, Masina& m) {
		cout << "Introduceti marca:";
		input >> m.marca;
		cout << "Nr roti:";
		input >> m.nrRoti;
		if (m.producatori != NULL) {
			delete[]m.producatori;
		}
		if (m.nrRoti > 0) {
			m.producatori = new string[m.nrRoti];
			cout << "Producatori:";
			for (int i = 0; i < m.nrRoti; i++) {
				input >> m.producatori[i];
			}
		}
		else {
			m.producatori = NULL;
		}
		cout << "Pret:";
		input >> m.pret;
		return input;
	}
	friend ostream& operator<<(ostream& output, Masina m);
};

int Masina::TVA = 19;

ostream& operator<<(ostream& output, Masina m) {
	output << "Marca:" << m.marca << endl;
	output << "Nr roti:" << m.nrRoti << ": ";
	if (m.producatori != NULL) {
		for (int i = 0; i < m.nrRoti; i++) {
			output << m.producatori[i] << ", ";
		}
	}
	output << endl;
	output << "Pret:" << m.pret << endl;
	output << "TVA:" << m.TVA << endl;
	output << "An fabricatie:" << m.anFabricatie << endl;
	return output;
}
class Tir : public Masina {
	float tonaj;
	char* tara;
public:
	Tir() :Masina(10,"Volvo",10000,2020)
	{
		this->tonaj = 20;
		this->tara = nullptr;
	}
	Tir(float tonaj, const char* tara) :Masina(10, "Volvo", 10000, 2020)
	{
		this->tonaj = tonaj;
		this->tara = new char[strlen(tara) + 1];
		strcpy_s(this->tara, strlen(tara) + 1, tara);
	}
	Tir(const Tir& tir) :Masina(tir)
	{
		this->tonaj = tir.tonaj;
		this->tara = new char[strlen(tir.tara) + 1];
		strcpy_s(this->tara, strlen(tir.tara) + 1, tir.tara);
	}
	Tir(float tonaj, const char* tara, int _nrRoti, string marca, float pret, int an, string* producatori) :Masina(_nrRoti, marca, pret, an)
	{
		this->tonaj = tonaj;
		this->tara = new char[strlen(tara) + 1];
		strcpy_s(this->tara, strlen(tara) + 1, tara);
		setNrRoti(_nrRoti, producatori);
	}
	Tir& operator=(const Tir& tir)
	{
		if (&tir != this)
		{	
			Masina::operator=(tir);
			this->tonaj = tir.tonaj;
			this->tara = new char[strlen(tir.tara) + 1];
			strcpy_s(this->tara, strlen(tir.tara) + 1, tir.tara);
		}
		return *this;
	}
	~Tir()
	{
		if (this->tara)
			delete[] this->tara;
	}
	explicit operator float()
	{
		return this->tonaj;
	}
	friend ostream& operator<<(ostream& out, const Tir& tir)
	{
		out << (Masina)tir;
		if (tir.tara)
		{
			out <<"Tara: "<< tir.tara;
			out <<"Tonaj: "<< tir.tonaj;
		}
		return out;
	}
	float calculeazaMedieTonaj()
	{
		return this->tonaj / getNrRoti();
	}
	friend istream& operator>>(istream& input, Tir& tir)
	{
		//operator>>(input, (Masina&)tir);
		input >> (Masina&)tir;
		cout << "Tara: ";
		char buffer[50];
		input >> buffer;
		if (tir.tara)
			delete[] tir.tara;
		tir.tara = new char[strlen(buffer) + 1];
		strcpy_s(tir.tara, strlen(buffer) + 1, buffer);
		cout << "Tonaj: ";
		input >> tir.tonaj;
		return input;

	}

};
int main() {
	Tir t(15.2, "Romania");
	Tir t2;
	t2 = t;
	Tir t3 = t;
	t2 = t;
	int numarRoti = 4;
	string* prod = new string[numarRoti];
	for (int i = 0; i < numarRoti; i++)
		prod[i] = "Michellin";
	Tir t4(15.0f, "Romania", numarRoti, "DAC", 50000.0f, 2020, prod);
	cout << t << endl;
	cout << t2<<endl;
	cout << "media de tone per roate" << t2.calculeazaMedieTonaj() << endl;
	float tonaj = (float)t2;
	cout << tonaj << endl;
	delete[] prod;
}