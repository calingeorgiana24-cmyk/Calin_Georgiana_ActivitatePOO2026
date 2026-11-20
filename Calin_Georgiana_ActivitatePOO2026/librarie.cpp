#include <iostream>
#include <string>

using namespace std;

enum Zona { CENTRALA, PERIFERICA };

class Librarie {
private:
	const int id;
	Zona zona;
	string nume;
	float vanzariTotale;
	int nrProduse;
	float* preturi;

public:
	//constructorul default
	Librarie() :id(0) {
		this->zona = CENTRALA;
		this->nume = "Librarie generala";
		this->vanzariTotale = 0;
		this->nrProduse = 0;
		this->preturi = nullptr;
	}

	//constructorul cu toti parametri
	Librarie(int id, Zona zona, string nume, float vanzariTotale, int nrProduse, float* preturi) :id(id) {
		this->zona = zona;
		this->nume = nume;
		this->vanzariTotale = vanzariTotale;
		this->nrProduse = nrProduse;

		this->preturi = new float[nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->preturi[i] = preturi[i];
		}
	}

	//constructorul de copiere este o functie speciala care creeaza un obiect nou folosind informatiile unui obiect deja existent
	Librarie(const Librarie& original) :id(original.id) {
		this->zona = original.zona;
		this->nume = original.nume;
		this->vanzariTotale = original.vanzariTotale;
		this->nrProduse = original.nrProduse;

		if (original.preturi != nullptr) {
			this->preturi = new float[nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = original.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}

	}

	//operator egal= este un operator de atribuie supraincarcat
	void operator=(const Librarie& copie) {
		this->zona = copie.zona;
		this->nume = copie.nume;
		this->vanzariTotale = copie.vanzariTotale;
		this->nrProduse = copie.nrProduse;

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}

		if (copie.preturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}

	//get si set
	string getNume() {
		return this->nume;
	}
	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}

	float getVanzariTotale() {
		return this->vanzariTotale;
	}
	void setVanzariTotale(float vanzariTotale) {
		if (vanzariTotale > 0) {
			this->vanzariTotale = vanzariTotale;
		}
	}

	int getNrProduse() {
		return this->nrProduse;
	}
	void setNrProduse(int nrProduse) {
		this->nrProduse = nrProduse;
	}

	//get si set pt vectorul preturi
	float* getPreturi() {
		float* vPreturi = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			vPreturi[i] = this->preturi[i];
		}
		return vPreturi;
	}

	void setPreturi(float* vPreturi, int dim) {
		setNrProduse(dim);

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}
		if (vPreturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->preturi[i] = vPreturi[i];
			}
			delete[] vPreturi;
		}
		else {
			this->preturi = nullptr;
		}
	}

	//operator de afisare
	friend void operator<<(ostream& out, Librarie l) {
		out << endl << "Operatorul de afisare: ";
		out << endl << "ID este: " << l.id;
		out << endl << "Numele este: " << l.nume;
		out << endl << "Vanzarile totale sunt: " << l.vanzariTotale;
		out << endl << "Nr produse: " << l.nrProduse;
		out << endl << "Zona este: ";
		if (l.zona == CENTRALA) out << "CENTRALA";
		if (l.zona == PERIFERICA) out << "PERIFERICA";

		if (l.preturi != nullptr) {
			out << endl << "Preturi: ";
			for (int i = 0; i < l.nrProduse; i++) {
				out << l.preturi[i] << "lei ";
			}
		}
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

	~Librarie() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}
};

int main() {

	Librarie librarieGenerala;
	Librarie librarie2 = librarieGenerala; //copiem din librarie generala in librarie2 adica apelam constr de copiere

	cout << librarieGenerala;


	Librarie l3;
	l3 = librarie2; //apelam op egal

	float* v1 = new float[2] {15, 26};
	librarie2.setPreturi(v1, 2);

	float* v2 = new float[2] {15, 26};
	Librarie* librarieAna = new Librarie(1, CENTRALA, "Ana", 97000, 2, v2);
	cout << (*librarieAna);

	(*librarieAna)[0] = 20;
	cout << endl << (*librarieAna)[0];
	cout << *librarieAna;

	librarie2.getPreturi();

	cout << "Numele librariei este: " << librarieAna->getNume() << endl;
	cout << "Totalitatea vanzarilor este: " << librarieAna->getVanzariTotale() << endl;

	delete librarieAna;

	return 0;
}