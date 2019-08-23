#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream ifEntrada;
	ofstream ofSalida;

	ifEntrada.open("Cantidades.txt");
	ofSalida.open("Ventas.txt");

	int iID;
	double dPrecio;
	int iCantidad;

	while (!ifEntrada.eof()) {

		ifEntrada >> iID >> dPrecio >> iCantidad;
		ofSalida << iID*iCantidad << " ";
		ofSalida << dPrecio*iCantidad << " ";
		ofSalida << 1.16*(dPrecio*iCantidad);
		ofSalida << endl;
	}

	ifEntrada.close();
	ofSalida.close();

	return 0;
}