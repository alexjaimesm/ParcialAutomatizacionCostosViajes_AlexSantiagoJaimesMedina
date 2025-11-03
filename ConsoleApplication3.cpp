#include <iostream>
#include <string>

using namespace std;

double validarDato(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor < 0)
            cout << "  El valor no puede ser negativo. Intente de nuevo.\n";
    } while (valor < 0);
    return valor;
}

void IngresarConductores(int& NumConductores) {
    cout << "Ingrese la cantidad de conductores: " << endl;
    cin >> NumConductores;

    while (NumConductores <= 0 || NumConductores > 10) {
        cout << "Debe ingresar unicamente un numero entre el 1 y el 10" << endl;
        cin >> NumConductores;
    }
}

void IngresarDatosConductores(int NumConductores, string NombresConductores[], int NumViajes[], double TotalGanado[], double PromedioDistancia[]) {
    double SumaDistancia = 0, Distancia, CostoKm;

    for (int i = 0; i < NumConductores; i++) {
        cout << "===CONDUCTOR #" << i + 1 << " ===" << endl;
        cout << "Nombre: ";
        cin >> NombresConductores[i];

        cout << "Ingrese el numero de viajes realizados: " << endl;
        cin >> NumViajes[i];

        while (NumViajes[i] <= 0 || NumViajes[i] > 10) {
            cout << "Debe ingresar unicamente un numero entre el 1 y el 10 " << endl;
            cin >> NumViajes[i];
        }
        
        TotalGanado[i] = 0;

        for (int j = 0; j < NumViajes[i]; j++) {
            cout << "Viaje #" << j + 1 << ":" << endl;

            double Distancia = validarDato("  Distancia (km): ");
            double CostoKm = validarDato("  Costo por km ($): ");

            TotalGanado[i] += Distancia * CostoKm;
            SumaDistancia += Distancia;
        }

        PromedioDistancia[i] = SumaDistancia / NumViajes[i];
    }
}

int EncontrarConductorMayorIngreso(int NumConductores, double TotalGanado[]) {
    int MayorIndice = 0;
    for (int i = 1; i < NumConductores; i++) {
        if (TotalGanado[i] > TotalGanado[MayorIndice]) {
            MayorIndice = i;
        }
    }
    return MayorIndice;
}

void MostrarResultados(int NumConductores, string NombresConductores[], double TotalGanado[], double PromedioDistancia[], int MayorIndice) {
    cout << "================= RESUMEN DE VIAJES =================" << endl;
    cout << "Conductor\tTotal Ganado ($)\tPromedio Distancia (Km)" << endl;
    cout << "------------------------------------------------------" << endl;

    for (int i = 0; i < NumConductores; i++) {
        cout << NombresConductores[i] << "\t\t"
            << TotalGanado[i] << "\t\t"
            << PromedioDistancia[i] << endl;
    }

    cout << "------------------------------------------------------" << endl;
    cout << "El conductor con mayor ingreso fue: "
        << NombresConductores[MayorIndice]
        << " con $" << TotalGanado[MayorIndice] << endl;
    cout << "======================================================" << endl;
}

int main() {
    int NumConductores, MayorIndice = 0;
    int NumViajes[10];
    double PromedioDistancia[10], TotalGanado[10];
    string NombresConductores[10];

    IngresarConductores(NumConductores);
    IngresarDatosConductores(NumConductores, NombresConductores, NumViajes, TotalGanado, PromedioDistancia);
    MayorIndice = EncontrarConductorMayorIngreso(NumConductores, TotalGanado);
    MostrarResultados(NumConductores, NombresConductores, TotalGanado, PromedioDistancia, MayorIndice);
}
