#include <iostream>

using namespace std;

class Bicicleta {
private:
	char* nume;
	string culoare;
	int anFabricatie;
	float greutate;

public:
	//constructorul default sau implicit
	Bicicleta() {
		this->nume = nullptr;
		this->culoare = "";
		this->anFabricatie = 0;
		this->greutate = 0.0;
	}

	//constructorul cu parametri
	Bicicleta(const char* nume, string culoare, int anFabricatie, float greutate) {
		this->culoare = culoare;
		this->anFabricatie = anFabricatie;
		this->greutate = greutate;

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	//constructorul de copiere
	Bicicleta(const Bicicleta& copie) {
		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else {
			this->nume = nullptr;
		}
		this->culoare = copie.culoare;
		this->anFabricatie = copie.anFabricatie;
		this->greutate = copie.greutate;
	}

	//destructorul
	~Bicicleta() {
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
	}

	//operatorul=
	Bicicleta& operator=(const Bicicleta& copie) {

		if (this->nume != nullptr) {
			delete[] this->nume;
		}

		this->culoare = copie.culoare;
		this->anFabricatie = copie.anFabricatie;
		this->greutate = copie.greutate;
		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else {
			this->nume = nullptr;
		}

		return *this;
	}

	//getter si setteri
	void setNume(char* nume) {
		if (strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	char* getNume() {
		return this->nume;
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	string getCuloare() {
		return this->culoare;
	}

	void setAnFabricatie(int anFabricatie) {
		if (anFabricatie > 1980) {
			this->anFabricatie = anFabricatie;
		}
	}

	int getAnFabricatie() {
		return this->anFabricatie;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	//ostream sau operatorul de afisare sau sa se supraincarce operatorul de afisare cu friend
	friend void operator<<(ostream& out, Bicicleta b) {
		out << endl << (b.nume != nullptr ? "Nume: " + string(b.nume) : "Nume nespecificat");
		out << endl << "Culoare: " << b.culoare;
		out << endl << "An fabricatie: " << b.anFabricatie;
		out << endl << "Greutate: " << b.greutate;
	}

};

void main() {

	Bicicleta b1("Pegas", "rosie", 1997, 10.5);
	cout << "Nume: " << b1.getNume() << endl;
	cout << "Culoare: " << b1.getCuloare() << endl;
	cout << "An fabricatie: " << b1.getAnFabricatie() << endl;
	cout << "Greutate: " << b1.getGreutate() << endl;
	cout << endl;

	Bicicleta b2("Btwin", "neagra", 2000, 11.5);
	cout << "Nume: " << b2.getNume() << endl;
	cout << "Culoare: " << b2.getCuloare() << endl;
	cout << "An fabricatie: " << b2.getAnFabricatie() << endl;
	cout << "Greutate: " << b2.getGreutate() << endl;

}