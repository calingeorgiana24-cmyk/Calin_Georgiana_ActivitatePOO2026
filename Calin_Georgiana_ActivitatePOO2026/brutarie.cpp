#include <iostream>
#include <string>

using namespace std;

//enum
enum Zona { CENTRALA = 1, PERIFERICA = 2 };

class Brutarie {
private: //atribute private
	const int id;
	Zona zona;
	string numeBrutarie;
	float vanzariTotale;
	int nrProduse;
	float* preturi;


public:
	static int nrBrutarii;
	Brutarie() :id(++nrBrutarii) { //constructor default
		this->numeBrutarie = "Brutaria Amzei";
		this->zona = PERIFERICA;
		this->vanzariTotale = 0;
		this->nrProduse = 0;
		this->preturi = nullptr;
	}

	//constructor cu toti parametri
	Brutarie(int id, string numeBrutarie, float vanzariTotale, int nrProduse, float* preturi, Zona zona) :id(id) {
		nrBrutarii++;
		this->numeBrutarie = numeBrutarie;
		this->vanzariTotale = vanzariTotale;
		this->nrProduse = nrProduse;
		this->zona = zona;

		this->preturi = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->preturi[i] = preturi[i];
		}
	}

	//constructor de copiere
	Brutarie(const Brutarie& constrCopie) :id(++nrBrutarii) {
		this->numeBrutarie = constrCopie.numeBrutarie;
		this->zona = constrCopie.zona;
		this->vanzariTotale = constrCopie.vanzariTotale;
		this->nrProduse = constrCopie.nrProduse;

		if (constrCopie.preturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = constrCopie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}

	//operator egal
	Brutarie& operator=(const Brutarie& opEgal) {
		this->numeBrutarie = opEgal.numeBrutarie;
		this->vanzariTotale = opEgal.vanzariTotale;
		this->nrProduse = opEgal.nrProduse;
		this->zona = opEgal.zona;

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}

		if (opEgal.preturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = opEgal.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}

		return *this;
	}

	//get si set
	string getNumeBrutarie() {
		return this->numeBrutarie;
	}
	void setNumeBrutarie(string numeBrutarie) {
		if (numeBrutarie.length() > 0) {
			this->numeBrutarie = numeBrutarie;

		}
	}

	float getVanzariTotale() {
		return this->vanzariTotale;
	}
	void setVanzariToate(float vanzariTotale) {
		this->vanzariTotale = vanzariTotale;
	}

	int getNrProduse() {
		return this->nrProduse;
	}
	void setNrProduse(int nrProduse) {
		this->nrProduse = nrProduse;
	}

	float* getPreturi() {
		float* vPreturi = new float[this->nrProduse];
		for (int i = 0; i < nrProduse; i++) {
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
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = vPreturi[i];
			}
		}
	}

	//operator <<
	friend void operator<<(ostream& out, Brutarie b) {
		out << endl << "Welcome to Brutarie: ";
		out << endl << "Id: " << b.id;
		out << endl << "Nume brutarie: " << b.numeBrutarie;
		out << endl << "Vanzari totale: " << b.vanzariTotale;
		out << endl << "Nr produse: " << b.nrProduse;

		if (b.preturi != nullptr) {
			out << endl << "Preturi: ";
			for (int i = 0; i < b.nrProduse; i++) {
				out << b.preturi[i] << " lei ";
			}
		}

	}

	//destructorul
	~Brutarie() {
		cout << endl << "S-a apelat destructorul!";
		if (this->preturi != nullptr) {
			delete[] this->preturi;
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
};

int Brutarie::nrBrutarii = 0;

int main() {
	Brutarie brutarieGenerala;
	cout << brutarieGenerala;

	brutarieGenerala.setNumeBrutarie("Brutaria Maria");

	cout << brutarieGenerala;
	cout << endl;

	float* preturi = new float[3] {2.5, 6.7, 8.6};
	Brutarie* brutarieMita = new Brutarie(1, "Mita Biciclista", 95000, 3, preturi, CENTRALA);
	cout << (*brutarieMita);

	(*brutarieMita)[0] = 5;
	cout << endl << (*brutarieMita)[0];
	cout << *brutarieMita;

	delete brutarieMita;
	delete[] preturi;

	return 0;
}