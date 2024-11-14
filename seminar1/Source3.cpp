#include <iostream>
using namespace std;
class Sejur {
	const unsigned int id;
	char* destinatie;
	float pretBaza;
	int nrExcursiiOptionale;
	float* pretExcursie;
	string locDePlecare;
	string numeCalator;
public:
	Sejur() :id(0)
	{
		this->destinatie = new char[strlen("Bucuresti") + 1];
		strcpy_s(this->destinatie, strlen("Bucuresti") + 1, "Bucuresti");
		this->pretBaza = 50.42f;
		this->nrExcursiiOptionale = 2;
		this->pretExcursie = new float[this->nrExcursiiOptionale];
		for (int i = 0; i < this->nrExcursiiOptionale; i++)
			this->pretExcursie[i] = 32.5f + i;
		this->locDePlecare = "Prahova";
		this->numeCalator = "Ramona";
	}
	Sejur(const unsigned id, const char* destinatie, float pretBaza, int nr, float* pret, string locDePlecare, string nume) :id(id) {
		this->destinatie = new char[strlen(destinatie) + 1];
		strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
		this->pretBaza = pretBaza;
		this->nrExcursiiOptionale = nr;
		this->pretExcursie = new float[nr];
		for (int i = 0; i < nr; i++)
			this->pretExcursie[i] = pret[i];
		this->locDePlecare = locDePlecare;
		this->numeCalator = nume;
	}
	Sejur(const Sejur& sejur) :id(sejur.id)
	{
		this->destinatie = new char[strlen(sejur.destinatie) + 1];
		strcpy_s(this->destinatie, strlen(sejur.destinatie) + 1, sejur.destinatie);
		this->pretBaza = sejur.pretBaza;
		this->nrExcursiiOptionale = sejur.nrExcursiiOptionale;
		this->pretExcursie = new float[sejur.nrExcursiiOptionale];
		for (int i = 0; i < sejur.nrExcursiiOptionale; i++)
			this->pretExcursie[i] = sejur.pretExcursie[i];
		this->locDePlecare = sejur.locDePlecare;
		this->numeCalator = sejur.numeCalator;
	}
	Sejur& operator=(const Sejur& sejur)
	{
		if (&sejur != this)
		{
			if (this->destinatie != NULL)
				delete[] this->destinatie;
			this->destinatie = new char[strlen(sejur.destinatie) + 1];
			strcpy_s(this->destinatie, strlen(sejur.destinatie) + 1, sejur.destinatie);
			this->pretBaza = sejur.pretBaza;
			this->nrExcursiiOptionale = sejur.nrExcursiiOptionale;
			if (this->pretExcursie != NULL)
				delete[] this->pretExcursie;
			this->pretExcursie = new float[sejur.nrExcursiiOptionale];
			for (int i = 0; i < sejur.nrExcursiiOptionale; i++)
				this->pretExcursie[i] = sejur.pretExcursie[i];
			this->locDePlecare = sejur.locDePlecare;
			this->numeCalator = sejur.numeCalator;
		}
		return *this;
	}

	explicit operator float()
	{
		float sum = 0;
		for (int i = 0; i < this->nrExcursiiOptionale; i++)
			sum += this->pretExcursie[i];
		sum += this->pretBaza;
		return sum;
	}
	friend ostream& operator<<(ostream& out, Sejur sejur)
	{
		out << "ID destinatie: " << sejur.id << endl;
		out << "Destinatie: " << sejur.destinatie << endl;
		out << "Pret de baza: " << sejur.pretBaza << endl;
		out << "Nr excursii optionale: " << sejur.nrExcursiiOptionale << endl;
		for (int i = 0; i < sejur.nrExcursiiOptionale; i++)
			out << "Excursia " << (i + 1) << " are pretul de: " << sejur.pretExcursie[i] << endl;
		out << "Loc de plecare: " << sejur.locDePlecare << endl;
		out << "Nume calator: " << sejur.numeCalator << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Sejur& sejur)
	{
		cout << "Destinatie:";
		char buffer[100];
		in >> buffer;
		if (sejur.destinatie != NULL)
			delete[] sejur.destinatie;
		sejur.destinatie = new char[strlen(buffer) + 1];
		strcpy_s(sejur.destinatie, strlen(buffer) + 1, buffer);
		cout << "Pret de baza:";
		in >> sejur.pretBaza;
		cout << "Nr excursii optionale:";
		in >> sejur.nrExcursiiOptionale;
		if (sejur.nrExcursiiOptionale > 0)
		{
			if (sejur.pretExcursie != NULL)
				delete[] sejur.pretExcursie;
			sejur.pretExcursie = new float[sejur.nrExcursiiOptionale];
			for (int i = 0; i < sejur.nrExcursiiOptionale; i++)
			{
				cout << "Excursia " << (i + 1) << " are pretul de:";
				in >> sejur.pretExcursie[i];
			}
		}
		cout << "Loc de plecare:";
		in >> sejur.locDePlecare;
		cout << "Nume calator:";
		in >> sejur.numeCalator;
		return in;

	}
	~Sejur()
	{
		if (this->destinatie != NULL)
			delete[] this->destinatie;
		if (this->pretExcursie != NULL)
			delete[] this->pretExcursie;
	}
	string getLoc()
	{
		return this->locDePlecare;
	}
	string getNume()
	{
		return this->numeCalator;
	}
	void setLoc(string locNou)
	{
		if (locNou.length() > 3)//M-am gandit la Iasi,Cluj etc
			this->locDePlecare = locNou;
	}
	void setNume(string numeNou)
	{
		if (numeNou.length() > 2)//M-am gandit la Ana,Ion etc
			this->numeCalator = numeNou;
	}
	Sejur operator--(int)//postdecrementare
	{
		Sejur temp = *this;
		float min = temp.pretExcursie[0];
		for (int i = 1; i < temp.nrExcursiiOptionale; i++)
		{
			if (temp.pretExcursie[i] < min)
			{
				min = temp.pretExcursie[i];
				temp.nrExcursiiOptionale--;
			}
		}
		return *this;
	}
	friend bool operator<=(float pret, const Sejur& sejur)
	{
		if (sejur.nrExcursiiOptionale == 0)
			return false; 
		float max = sejur.pretExcursie[0];
		for (int i = 1; i < sejur.nrExcursiiOptionale; i++)
		{
			if (sejur.pretExcursie[i] > max)
				max = sejur.pretExcursie[i];
		}
		return pret <= max;
	}

	bool operator<(float pret)
	{
		int max = this->pretExcursie[0];
		for (int i = 1; i < this->nrExcursiiOptionale; i++)
		{
			if (this->pretExcursie[i] > max)
				max = this->pretExcursie[i];
		}
		return max < pret;
	}

};
void main()
{
	Sejur s;
	cout << s << endl;
	bool a = s < 2.4;
	cout << a;
	bool b = 2.4f <= s; 
	cout << b;
	Sejur s2= s--;
	cout << s2 << endl;
	return;
}