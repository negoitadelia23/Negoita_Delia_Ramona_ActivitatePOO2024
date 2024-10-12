#include <iostream>
using namespace std;
struct Tara {
	char* denumire;
	string capitala;
	int nrlocuitori;
	bool areiesirelamare;
};
void afisarepointerlatara(Tara* pt)
{
	cout << "Nume: " << pt->denumire << endl;
	cout << "Nr loc: " << pt->nrlocuitori << endl;
	cout << "Capitala " << pt->capitala << endl;
	cout << "Are iesire la mare: " << (pt->areiesirelamare ? /*Are iesire la mare ?*/ "DA" : "NU") << endl;
	//op ternar
}
Tara* citirePointer()//citirea NU are nevoie de param
{
	Tara* p = new Tara();
	cout << "Capitala:";
	cin >> p->capitala;
	cout << "Denumire: ";
	//NU poti face cin la asta, e un pointer denumire
	char buffer[100];//e pe stiva ca e static
	cin >> buffer;
	p->denumire = new char[strlen(buffer + 1)];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);
	cout << "Nr locuitori:";
	cin >> p->nrlocuitori;
	cout << "Are iesire la mare?(0-NU, 1-DA)";
	cin >> p->areiesirelamare;
	return p;//orice ar fi chiar daca se sterge din stack pointerul RAMANE in heap
}
int main()
{
	Tara tara;
	Tara* ptara;
	ptara = new Tara();//avem in heap o zona ptr ptr
	tara.areiesirelamare = false;
	ptara->capitala = "Bucuresti";
	ptara->denumire = new char[strlen("Romania" + 1)];
	//shallow copy e un tip de copiere care copiaza adresa
	strcpy_s(ptara->denumire, strlen("Romania") + 1, "Romania"); //STRCPY ia lua sirul Romania, alocand zona de mem fixa, dar daca avem m.m, el copiaza pana la final orice ar fi
	delete[] ptara->denumire;
	ptara->nrlocuitori = 200;
	ptara->areiesirelamare = true;
	afisarepointerlatara(ptara);
	delete ptara;
	/*Tara* p2tara = citirePointer();
	afisarepointerlatara(p2tara);*/
	Tara* vector;
	vector = new Tara[2];//vector
	delete[] vector;
	int nrptr = 2;
	//vector de pointeri
	Tara** pointeri;
	pointeri = new Tara * [nrptr];
	for (int i = 0; i < nrptr; i++)
		pointeri[i] = citirePointer();//
	for (int i = 0; i < nrptr; i++)
		afisarepointerlatara(pointeri[i]);
	//Memory Leak reprezinta o zona de mem alocata, dar care nu a fost dezalocata si nu mai avem adresa acelei zone de memorie
	for (int i = 0; i < nrptr; i++)
	{
		delete[] pointeri[i]->denumire;
		delete pointeri[i];
	}
	delete[] pointeri;
	return 0;
}