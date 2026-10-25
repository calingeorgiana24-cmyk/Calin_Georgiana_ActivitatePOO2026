#include<iostream>
#include<string>

using namespace std;

enum Functie { servant = 1, sefFormatie = 2, voluntar = 3, sofer = 4 };

class Pompier {
private:
	const int idPompier;
	Functie functie;
	string numePompier;
	int nrInterventii;
	float* durataInterventie;
	static int nrPompieri;

public:

	Pompier() :idPompier(++nrPompieri) {
		this->numePompier = "Pompier";
		this->functie = voluntar;
		this->nrInterventii = 0;
		this->durataInterventie = nullptr;
	}

	Pompier(int idPompier, Functie functie, string numePompier, int nrInterventii, float* durataInterventie) :idPompier(idPompier) {
		nrPompieri++;
		this->numePompier = numePompier;
		this->functie = functie;
		this->nrInterventii = nrInterventii;

		this->durataInterventie = new float[nrInterventii];
		for (int i = 0; i < this->nrInterventii; i++) {
			this->durataInterventie[i] = durataInterventie[i];
		}
	}


	//constructorul de copiere
	Pompier(const Pompier& copie) :idPompier(++nrPompieri) {
		this->functie = copie.functie;
		this->numePompier = copie.numePompier;
		this->nrInterventii = copie.nrInterventii;

		if (copie.durataInterventie != nullptr) {
			this->durataInterventie = new float[this->nrInterventii];
			for (int i = 0; i < this->nrInterventii; i++) {
				this->durataInterventie[i] = copie.durataInterventie[i];
			}
		}
		else {
			this->durataInterventie = nullptr;
		}
	}

	//operatorul =
	void operator=(const Pompier& copie) {
		this->functie = copie.functie;
		this->numePompier = copie.numePompier;
		this->nrInterventii = copie.nrInterventii;

		if (this->durataInterventie != nullptr) {
			delete[] this->durataInterventie;
			this->durataInterventie = nullptr;
		}

		if (copie.durataInterventie != nullptr) {
			this->durataInterventie = new float[this->nrInterventii];
			for (int i = 0; i < this->nrInterventii; i++) {
				this->durataInterventie[i] = copie.durataInterventie[i];
			}
		}
		else {
			this->durataInterventie = nullptr;
		}

	}

	//get si set
	string getNumePompier() {
		return this->numePompier;
	}

	void setNumePompier(string numePompier) {
		if (numePompier.length() > 0) {
			this->numePompier = numePompier;
		}
	}

	int getNrInterventii() {
		return this->nrInterventii;
	}

	void setNrInterventii(int nrInterventii) {
		if (nrInterventii >= 0) {
			this->nrInterventii = nrInterventii;
		}
		else {
			throw exception();
		}
	}

	float* getDurataInterventie() {
		float* vDurataInterventie = new float[this->nrInterventii];
		for (int i = 0; i < this->nrInterventii; i++) {
			vDurataInterventie[i] = this->durataInterventie[i];
		}
		return vDurataInterventie;
	}

	void setDurataInterventie(float* vDurataInterventie, int dim) {
		setNrInterventii(dim);

		if (this->durataInterventie != nullptr) {
			delete[] this->durataInterventie;
			this->durataInterventie = nullptr;
		}

		if (vDurataInterventie != nullptr) {
			this->durataInterventie = new float[this->nrInterventii];
			for (int i = 0; i < this->nrInterventii; i++) {
				this->durataInterventie[i] = vDurataInterventie[i];
			}
			delete[] vDurataInterventie;
		}
		else {
			this->durataInterventie = nullptr;
		}
	}


	void afisare() {
		cout << endl << "Id pompier: " << this->idPompier;
		cout << endl << "Functie: " << this->functie;
		if (this->functie == 1) {
			cout << "servant";
		}
		if (this->functie == 2) {
			cout << "sefFormatie";
		}
		if (this->functie == 3) {
			cout << "voluntar";
		}
		if (this->functie == 4) {
			cout << "sofer";
		}

		cout << endl << "Nume pompier: " << this->numePompier;

		cout << endl << "Numar interventii: " << this->nrInterventii;

		if (this->nrInterventii > 0) {
			cout << "Durata Interventie: " << this->durataInterventie;
			for (int i = 0; i < this->nrInterventii; i++) {
				cout << this->durataInterventie[i] << " minute.";
			}
		}
	}

	bool operator < (const Pompier& c) {
		return this->nrInterventii < c.nrInterventii;
	}

	~Pompier() {
		if (this->durataInterventie != nullptr) {
			delete[] this->durataInterventie;
		}
	}
};

int Pompier::nrPompieri = 0;



int main() {
	Pompier pompier;
	pompier.afisare();
	pompier.setNumePompier("Andrei Popescu");

	float* durate = new float[3] {35.5, 40.5, 50};
	Pompier* pompierBaneasa = new Pompier(7, sefFormatie, "Iustin Ionescu", 3, durate);

	return 0;
}