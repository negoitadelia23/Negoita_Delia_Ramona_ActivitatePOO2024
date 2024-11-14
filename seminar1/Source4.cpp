#include <iostream>
using namespace std;
class Prajitura {
public:
	char* denumire;
	unsigned int nrCalorii;
	unsigned int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	string numeBucatar;
	static int nrClienti;

	Prajitura()
	{
		this->denumire = new char[strlen("Amandina")+1];
		strcpy_s(this->denumire, strlen("Amandina") + 1, "Amandina");
		this->nrCalorii = 540;
		this->nrIngrediente = 4;
		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++)
			this->gramajIngrediente[i] = 32.5f;
		this->esteVegana = 0;
		this->numeBucatar = "Ramona";
	}
	Prajitura(const char* denumire, unsigned int nrCalorii, unsigned int nrIngrediente, float* gramaj, bool esteVegana, string numeBucatar)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->nrCalorii = nrCalorii;
		this->nrIngrediente = nrIngrediente;
		this->gramajIngrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++)
			this->gramajIngrediente[i] = gramaj[i];
		this->esteVegana = esteVegana;
		this->numeBucatar = numeBucatar;
	}
	~Prajitura()
	{
		if (this->denumire != NULL)
			delete[]this->denumire;
		if (this->gramajIngrediente != NULL)
			delete[]this->gramajIngrediente;
	}
	Prajitura(const Prajitura& prajitura)
	{
		this->denumire = new char[strlen(prajitura.denumire) + 1];
		strcpy_s(this->denumire, strlen(prajitura.denumire) + 1, prajitura.denumire);
		this->nrCalorii = prajitura.nrCalorii;
		this->nrIngrediente = prajitura.nrIngrediente;
		if (this->gramajIngrediente != NULL)
			delete[]this->gramajIngrediente;
		this->gramajIngrediente = new float[prajitura.nrIngrediente];
		for (int i = 0; i < prajitura.nrIngrediente; i++)
			this->gramajIngrediente[i] = prajitura.gramajIngrediente[i];
		this->esteVegana = prajitura.esteVegana;
		this->numeBucatar = prajitura.numeBucatar;
	}
	Prajitura& operator=(const Prajitura& prajitura)
	{
		if (&prajitura != this)
		{
			if (this->denumire != NULL)
				delete[]this->denumire;
			this->denumire = new char[strlen(prajitura.denumire) + 1];
			strcpy_s(this->denumire, strlen(prajitura.denumire) + 1, prajitura.denumire);
			this->nrCalorii = prajitura.nrCalorii;
			this->nrIngrediente = prajitura.nrIngrediente;
			this->gramajIngrediente = new float[prajitura.nrIngrediente];
			for (int i = 0; i < prajitura.nrIngrediente; i++)
				this->gramajIngrediente[i] = prajitura.gramajIngrediente[i];
			this->esteVegana = prajitura.esteVegana;
			this->numeBucatar = prajitura.numeBucatar;
		}
		return *this;
	}
	Prajitura& operator*=(int a)
	{
		Prajitura temp = *this;
		for (int i = 0; i < this->nrIngrediente; i++)
			this->gramajIngrediente[i] *= a;
		return temp;
	}

	string getNumeBucatar()
	{
		return this->numeBucatar;
	}
	static int getNrClienti()
	{
		return Prajitura::nrClienti;
	}
	void setNumeBucatar(string numeNou)
	{
		if (numeNou.length() > 2)//Ana,Ion
			this->numeBucatar = numeNou;
		else throw "Inputul nu are sens";
	}
	static void setNrClienti(int clienti)
	{
		if (clienti >= 0)
			Prajitura::nrClienti = clienti;
		else throw "Nu exista un nr de clienti negativ.";
	}
	float getGramajTotal()
	{
		float sum = 0;
		for (int i = 0; i < this->nrIngrediente; i++)
			sum += this->gramajIngrediente[i];
		return sum;
	}

	bool operator!=(Prajitura p)
	{
		return this->esteVegana != p.esteVegana && this->denumire != p.denumire; this->nrCalorii != p.nrCalorii && this->nrClienti != p.nrClienti && this->nrIngrediente != p.nrIngrediente && this->gramajIngrediente != p.gramajIngrediente && this->numeBucatar != p.numeBucatar;
	}
	friend Prajitura& operator+(float gramajNou, Prajitura& prajitura);
};
Prajitura& operator+(float gramajNou, Prajitura& prajitura)
{
	float* temp = new float[prajitura.nrIngrediente + 1];
	for (int i = 0; i < prajitura.nrIngrediente; i++)
		temp[i] = prajitura.gramajIngrediente[i];
	temp[prajitura.nrIngrediente] = gramajNou;
	prajitura.nrIngrediente++;
	if (prajitura.gramajIngrediente != NULL)
		delete[]prajitura.gramajIngrediente;
	prajitura.gramajIngrediente = temp;
	return prajitura;
	}

int Prajitura::nrClienti = 4;
int main()
{
	Prajitura p;
	for (int i = 0; i < p.nrIngrediente; i++)
		cout << p.gramajIngrediente[i] << endl;
	try {
		p.setNumeBucatar("Ana");
		p.setNumeBucatar("R");
	}
	catch (int exceptie)
	{
		
	}
	catch (float exceptie)
	{

	}
	catch (const char* exceptie)
	{
		cout << exceptie<<endl;
	}
	catch (...)
	{

	}
	try{
		Prajitura::setNrClienti(4);
		Prajitura::setNrClienti(-1);
	}
	catch (int exceptie)
	{

	}
	catch (float exceptie)
	{

	}
	catch (const char* exceptie)
	{
		cout << exceptie << endl;
	}
	catch (...)
	{

	}
	p *= 2;
	Prajitura p2 = p;
	p = 12.5f + p2;
	for (int i = 0; i < p.nrIngrediente; i++)
		cout << p.gramajIngrediente[i] << endl;
	cout << (p != p2);
	return 0;
}