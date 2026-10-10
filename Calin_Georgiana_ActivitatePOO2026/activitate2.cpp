#include <iostream>
#include <string>

using namespace std;

class Magazin {
private:
	const int id;
	string numeMagazin;
	int nrProduse;
	float* preturi;

public:
	static int nrMagazine;
	Magazin() :id(++nrMagazine) {
		this->numeMagazin = "Magazin";
		this->nrProduse = 0;
		this->preturi = nullptr;
	}

	Magazin(int id, string numeMagazin, int nrProduse, float* preturi) :id(id){
		this->numeMagazin = numeMagazin;
		this->nrProduse = nrProduse;

		this->preturi = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) 
		{
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Nume magazin: " << this->numeMagazin;
		cout << endl << "Numar produse: " << this->nrProduse;
		if (this->nrProduse > 0) {
			cout << " are urmatoarele preturi: ";
			for (int i = 0; i < this->nrProduse - 1; i++)
			{
				cout << this->preturi[i] << " lei, ";
			}
			cout << this->preturi[this->nrProduse - 1] << " lei.";
		}
	}
};

int Magazin::nrMagazine = 0;

int main() {

	Magazin magazin1;
	magazin1.afisare();

	cout << endl;

	float* preturi = new float[] {44, 24, 55};
	Magazin* magazinTabac = new Magazin(5, "Magazin Tabac", 3, preturi);
	magazinTabac->afisare();
	cout << endl;

	delete magazinTabac;

	cout << endl << "Numar magazine: " << Magazin::nrMagazine;
	return 0;
}

