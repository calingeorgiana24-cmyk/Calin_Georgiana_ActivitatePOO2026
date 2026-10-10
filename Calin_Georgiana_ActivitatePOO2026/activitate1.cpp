#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Librarie {
private:
	const int id;
	string numeLibrarie;
	int nrCarti;
	float* preturi;


public:
	static int nrLibrarii;
	Librarie() :id() {
		this->numeLibrarie = "Librarie generala";
		this->nrCarti = 0;
		this->preturi = nullptr;
	}

	Librarie(int id, string numeLibrarie, int nrCarti, float* preturi) :id(id) {
		this->numeLibrarie = numeLibrarie;
		this->nrCarti = nrCarti;
		this->preturi = new float[nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;

	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Nume Librarie: " << this->numeLibrarie;
		cout << endl << "Numar carti: " << this->nrCarti;
		if (this->nrCarti > 0) {
			cout << " are urmatoarele preturi: ";
			for (int i = 0; i < this->nrCarti - 1; i++)
			{
				cout << this->preturi[i] << " lei, ";
			}
			cout << this->preturi[this->nrCarti - 1] << " lei.";

		}
	}

};

int Librarie::nrLibrarii = 0;

void main() {
	Librarie librarie1;
	librarie1.afisare();

	cout << endl;

	float* preturi = new float[] {25, 55, 80.5};
	Librarie* Libris = new Librarie(3, "Libris", 3, preturi);
	Libris->afisare();

	delete Libris;

	cout << endl << "Numar librarii: " << Librarie::nrLibrarii;

}