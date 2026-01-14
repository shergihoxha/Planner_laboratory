#include <iostream>
#include "Planner.h"

using namespace std;

int main() {
    Planner planner;
    int choice;

    do {
        cout << "\n========== PLANNER SETTIMANALE ==========\n";
        cout << "1. Aggiungi attivita'\n";
        cout << "2. Mostra attivita' della settimana\n";
        cout << "3. Segna attivita' come completata\n";
        cout << "4. Modifica attivita'\n";
        cout << "5. Rimuovi attivita'\n";
        cout << "0. Esci\n";
        cout << "Scegli: ";
        cin >> choice;

        switch (choice) {
            case 1: planner.addActivity(); break;
            case 2: planner.showWeek(); break;
            case 3: planner.markAsDone(); break;
            case 4: planner.editActivity(); break;
            case 5: planner.removeActivity(); break;
            case 0: cout << "Uscita...\n"; break;
            default: cout << "Scelta non valida.\n";
        }
    } while (choice != 0);

    return 0;
}
