#include <iostream>
#include <string>

using namespace std;

class Cafenea {
private:
	const int id;
	string nume;
	float vanzari;
	int nrProduse;
	float* preturi;


public:
	static int nrCafenele;
	Cafenea() :id(++nrCafenele) {
		this->nume = "nume default";
		this->vanzari = 0;
		this->nrProduse = 0;
		this->preturi = nullptr;

	}

	Cafenea(int id, string nume, float vanzari, int nrProduse, float* preturi) :id(id) {
		nrCafenele++;
		this->nume = nume;
		this->vanzari = vanzari;
		this->nrProduse = nrProduse;


		this->preturi = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;
	}

	Cafenea(const Cafenea& obNou) :id(++nrCafenele) {
		this->nume = obNou.nume;
		this->vanzari = obNou.vanzari;
		this->nrProduse = obNou.nrProduse;

		if (obNou.preturi != nullptr) {
			this->preturi = new float[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->preturi[i] = obNou.preturi[i];
			}
		}
		else this->preturi = nullptr;
	}

	void operator=(const Cafenea& copie) {
		this->nume = copie.nume;
		this->vanzari = copie.vanzari;
		this->nrProduse = copie.nrProduse;

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}
		if (copie.preturi != nullptr) {
			this->preturi = new float[nrProduse];
			for (int i = 0; i < nrProduse; i++)
			{
				this->preturi[i] = copie.preturi[i];
			}
		}
		else this->preturi = nullptr;
	}

	int getNrProduse() {
		return this->nrProduse;
	}

	void setNrProduse(int nrProduse) {
		if (nrProduse >= 0) {
			this->nrProduse = nrProduse;
		}
		else {
			throw exception();
		}
	}

	float* getPreturi() {
		float* vPreturi = new float[this->nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			vPreturi[i] = preturi[i];
		}
		return vPreturi;
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Nume: " << this->nume;
		cout << endl << "Vanzari: " << this->vanzari;
		cout << endl << "Nr produse: " << this->nrProduse;

		if (this->nrProduse > 0) {
			cout << "Preturi: ";
			for (int i = 0; i < nrProduse; i++) {
				cout << this->preturi[i];
			}
		}
	}

	bool operator<(const Cafenea& c) {
		return this->nrProduse < c.nrProduse;
	}

	~Cafenea() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	void operator+=(float vanzariTotaleDeAdunat) {
		this->vanzari += vanzariTotaleDeAdunat;
	}

	//operatorul negatie
	bool operator!() {
		return this->vanzari > 0;
	}

	//operatorul functie
	float operator()(float valoareDeAdaugat) {
		return this->vanzari + valoareDeAdaugat;
	}

	//operatorul index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrProduse) {
			return this->preturi[index];
		}
		else {
			throw exception();
		}
	}

	friend void operator<<(ostream& out, Cafenea c) {
		out << endl << "Operator de afisare: ";
		out << endl << "Id: " << c.id;
		out << endl << "Nume: " << c.nume;
		out << endl << "Vanzari: " << c.vanzari;
		if (c.preturi != nullptr) {
			out << endl << "Preturi: ";
			for (int i = 0; i < c.nrProduse; i++) {
				out << c.preturi[i] << "ml ";
			}
		}
	}

	Cafenea operator++(int) {
		Cafenea copie = *this;
		this->vanzari++;

		return copie;
	}

	Cafenea operator++() {
		this->vanzari++;
		return *this;
	}

	//cast explicit
	explicit operator int() {
		return this->nrProduse;
	}
};

int Cafenea::nrCafenele = 0;

int main() {

	Cafenea cafeneaGenerala;

	float* preturi = new float[3] { 15.5, 23, 20.5 };
	Cafenea* cafeneaUzina = new Cafenea(5, "Uzina", 10000, 3, preturi);
	(*cafeneaUzina) += 100;

	if (cafeneaGenerala < *cafeneaUzina) {
		cout << endl << "Cafeneaua generala are mai putine produse decat cafeneaua Uzina";
	}
	else {
		cout << endl << "Cafeneaua Uzina are mai putine produse decat cafeneaua generala";
	}
	(*cafeneaUzina)[0] = 15;

	cout << *cafeneaUzina;

	Cafenea cafenea1 = cafeneaGenerala++;

	cout << cafenea1;
	cout << cafeneaGenerala;

	Cafenea cafenea2 = ++cafeneaGenerala;

	cout << cafenea2;
	cout << cafeneaGenerala;

	cout << endl << "Cast cafenea -> int: " << int(*cafeneaUzina);

	delete cafeneaUzina;

	cout << endl << "Numar cafenele: " << Cafenea::nrCafenele;

	return 0;
}