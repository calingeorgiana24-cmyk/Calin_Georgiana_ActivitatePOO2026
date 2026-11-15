#include <iostream>

using namespace std;

class Rochie {
private:
	const int idRochie;
	static int numarRochii;
	char* marca;
	string culoare;
	float greutate;
	int anLansare;

public:
	Rochie() :idRochie(++numarRochii) {
		this->marca = nullptr;
		this->culoare = "";
		this->greutate = 2.3;
		this->anLansare = 2005;
	}

	Rochie(const char* marca, string culoare, float greutate, int anLansare) :idRochie(++numarRochii) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->anLansare = anLansare;

		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);

	}

	Rochie(const Rochie& copie) :idRochie(++numarRochii) {
		if (copie.marca != nullptr) {
			this->marca = new char[strlen(copie.marca) + 1];
			strcpy_s(this->marca, strlen(copie.marca) + 1, marca);
		}
		else {
			this->marca = nullptr;
		}
	}

	~Rochie() {
		if (this->marca != nullptr) {
			delete[] this->marca;
		}
	}

	//operatorul=
	void operator=(const Rochie& copie) {
		if (this->marca != nullptr) {
			delete[] this->marca;
			this->marca = nullptr;
		}

		if (copie.marca != nullptr) {
			this->marca = new char[strlen(copie.marca) + 1];
			strcpy_s(this->marca, strlen(copie.marca) + 1, copie.marca);
		}
		else {
			this->marca = nullptr;
		}
	}

	void setMarca(char* marca) {
		if (strlen(marca) > 0) {
			if (this->marca != nullptr) {
				delete[]this->marca;
			}
			this->marca = new char[strlen(marca) + 1];
			strcpy_s(this->marca, strlen(marca) + 1, marca);
		}
	}

	char* getMarca() {
		return this->marca;
	}

	void setCuloare(string culoare) {
		this->marca = marca;
	}

	string getCuloare() {
		return this->culoare;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	void setAnLansare(int anLansare) {
		if (anLansare > 2000) {
			this->anLansare = anLansare;
		}
	}

	int getAnLansare() {
		return this->anLansare;
	}

	//ostream - citire de la tastatura sau operatorul de afisare sau supraincarcarea operatorului de afisare
	friend void operator<<(ostream& consola, Rochie r) {
		consola << endl << (r.marca != nullptr ? "Marca: " + string(r.marca) : "Marca nespecificata");
		consola << endl << "Culoare: " << r.culoare;
		consola << endl << "Greutate: " << r.greutate;
		consola << endl << "An lansare: " << r.anLansare;
	}

	//operator postincrementare
	Rochie operator++(int) {
		Rochie copie = *this;
		this->anLansare++;

		return copie;
	}

	//operator preincrementare
	Rochie operator++() {
		this->anLansare++;
		return *this;
	}

};

int Rochie::numarRochii = 0;

void main() {

	cout << "ROCHIE 1" << endl;
	Rochie rochie1("Valentino", "rosie", 3.5, 2005);
	cout << "Marca este: " << rochie1.getMarca() << endl;
	cout << "Culoarea este: " << rochie1.getCuloare() << endl;
	cout << "Greutatea este: " << rochie1.getGreutate() << endl;
	cout << "Anul lansarii este: " << rochie1.getAnLansare() << endl;
	cout << endl;

	cout << "Rochie 2" << endl;
	Rochie rochie2("Chanel", "neagra", 4.2, 2006);
	cout << "Marca este: " << rochie2.getMarca() << endl;
	cout << "Culoarea este: " << rochie2.getCuloare() << endl;
	cout << "Greutatea este: " << rochie2.getGreutate() << endl;
	cout << "Anul lansarii este: " << rochie2.getAnLansare() << endl;

}