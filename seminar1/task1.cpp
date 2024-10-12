#include <iostream>
using namespace std;
struct blocuri {
	int nrscari;
	int nrapartamente;
	string strada;
	char* cartier;
	bool are_interfon;
};
blocuri* citirepointer()
{
	blocuri* p= new blocuri();
	cout << "Strada blocului: " << endl;
	cin >> p->strada;
	char buffer[100];
	cout << "Cartier: " << endl;
	cin >> buffer;
	p->cartier = new char[strlen(buffer) + 1];
	strcpy_s(p->cartier, strlen(buffer) + 1, buffer);
	cout << "Nr de scari: " << endl;
	cin >> p->nrscari;
	cout << "Nr de apartamente: " << endl;
	cin >> p->nrapartamente;
	cout << "Are interfon ? (0-NU, 1-DA)" << endl;
	cin >> p->are_interfon;
	return p;
}
void citirevector(blocuri** vector)
{
	for (int i = 0; i < 10; i++)
		vector[i] = citirepointer();
}
void afisareblocuri(blocuri* ptr)
{
	cout << "Blocul se afla in cartierul " << ptr->cartier << ", pe strada " << ptr->strada << ", avand " << ptr->nrscari << " scari si " << ptr->nrapartamente << " apartamente. Are interfon:" << (ptr->are_interfon ? "DA" : "NU")<<endl;
}
int main()
{
	blocuri** vectorptr;
	vectorptr = new blocuri*[10];
	citirevector(vectorptr);
	for (int i = 0; i < 10; i++)
		afisareblocuri(vectorptr[i]);
	for (int i = 0; i < 10; i++)
	{
		delete vectorptr[i]->cartier;
		delete[] vectorptr[i];
	}
	delete[] vectorptr;
}