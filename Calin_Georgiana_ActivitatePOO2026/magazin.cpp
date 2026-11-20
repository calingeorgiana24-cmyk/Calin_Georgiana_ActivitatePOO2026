#include <iostream>
#include <string>

using namespace std;

enum Tip { ALIMENTAR, NEALIMENTAR };

class Magazin {
private:
	const int id;
	string denumire;
	int nrProduse;
	Tip tip;
	float incasariTotale;
	float* preturi;

public:
	//constr default
	Magazin() :id(0) {
		this->denumire = "Magazin general";
		this->nrProduse = 0;
		this->tip = ALIMENTAR;
		this->incasariTotale = 0;
		this->preturi = nullptr;
	}

	//constr cu toti param
	Magazin(int id, string denumire, int nrProduse, Tip tip, float incasariTotale, float* preturi) :id(id) {
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->tip = tip;
		this->incasariTotale = incasariTotale;

		this->preturi = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->preturi[i] = preturi[i];
		}
	}

	//constr de copiere
	Magazin(const Magazin& copie) :id(copie.id) {
		this->denumire = copie.denumire;
		this->nrProduse = copie.nrProduse;
		this->tip = copie.tip;
		this->incasariTotale = copie.incasariTotale;

		if (copie.preturi != nullptr) {
			this->preturi = new float[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}

	//op egal
	void operator=(const Magazin& copie) {
		this->denumire = copie.denumire;
		this->nrProduse = copie.nrProduse;
		this->tip = copie.tip;
		this->incasariTotale = copie.incasariTotale;

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}
		if (copie.preturi != nullptr) {
			this->preturi = new float[nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}

	~Magazin() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	//get si set
	string getDenumire() {
		return denumire;
	}
	void setDenumire(string denumire) {
		this->denumire = denumire;
	}

	int getNrProduse() {
		return nrProduse;
	}
	void setNrProduse(int nrProduse) {
		this->nrProduse = nrProduse;
	}

	float getIncasariTotale() {
		return incasariTotale;
	}
	void setIncasartTotale(float incasariTotale) {
		this->incasariTotale = incasariTotale;
	}

	//get si set pt vector
	float* getPreturi() {
		float* vPreturi = new float[nrProduse];
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

			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = vPreturi[i];
			}

			delete[] vPreturi;
		}
		else {
			this->preturi = nullptr;
		}

	}

	//operator de afisare sau <<
	friend void operator<<(ostream& out, Magazin m) {
		out << endl << "Operatorul de afisare: ";
		out << endl << "Id: " << m.id;
		out << endl << "Denumire: " << m.denumire;
		out << endl << "Nr produse: " << m.nrProduse;
		out << endl << "Incasari Totale: " << m.incasariTotale;
		out << endl << "Tip: ";
		if (m.tip == ALIMENTAR) out << "ALIMENTAR";
		if (m.tip == NEALIMENTAR) out << "NEALIMENTAR";

		if (m.preturi != nullptr) {
			out << endl << "Preturi";
			for (int i = 0; i < m.nrProduse; i++) {
				out << m.preturi[i] << " lei ";
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
};

int main() {

	Magazin m1; //apelare constr default
	float* v = new float[3] {10, 20, 30}; //creare vector
	Magazin* m2 = new Magazin(1, "Magazin", 3, ALIMENTAR, 97000, v); //apelare constr cu toti param
	cout << *m2;
	Magazin m3 = *m2; //apelare constr de coiere
	m1 = m3; //apelare op egal
	cout << m3.getDenumire() << endl;

	Magazin magazin57;

	float* vector = new float[5] { 10, 20, 30, 40, 50 };
	Magazin magazin1(2, "MagMag", 5, ALIMENTAR, 10000, vector);

	cout << endl << "Primul pret: " << magazin1[0];
	cout << endl << "Al treilea pret: " << magazin1[2];
	magazin1[1] = 99;
	cout << endl << "Pretul modificat: " << magazin1[1] << endl;



	cout << "Numele magazinului este: " << magazin1.getDenumire() << endl;
	cout << "Numarul produselor este: " << magazin1.getNrProduse() << endl;
	cout << "Totalul incasarilor este: " << magazin1.getIncasariTotale() << endl;


	return 0;
}