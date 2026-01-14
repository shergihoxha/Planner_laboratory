#include "Planner.h"
#include <iostream>
#include <fstream>
#include <ctime>

#include "Planner.h"
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

int Planner::getActivitiesCount() const {
    return activities.size();
}

bool Planner::isActivityCompleted(const string& description) const {
    for (const auto& a : activities)
        if (a.description == description)
            return a.completed;
    return false;
}

void Planner::addActivityTest(const Activity& a) {
    activities.push_back(a);
    saveToFile();
}

bool Planner::markAsDoneByDescription(const string& description) {
    for (auto& a : activities) {
        if (a.description == description) {
            a.completed = true;
            saveToFile();
            return true;
        }
    }
    return false;
}

// (Qui va tutto il resto del Planner.cpp che avevo già, le funzioni addActivity, removeActivity, etc.)

using namespace std;

Planner::Planner() {
    loadFromFile();
    checkMonthlyReport();
}

void Planner::addActivity() {
    Activity a;
    cout << "Inserisci giorno (es. Lunedi'): ";
    cin >> ws;
    getline(cin, a.day);
    cout << "Descrizione attivita': ";
    getline(cin, a.description);
    cout << "Ora (es. 14:00): ";
    getline(cin, a.time);
    a.completed = false;

    activities.push_back(a);
    saveToFile();
    cout << "Attivita' aggiunta.\n";
}

void Planner::showWeek() {
    if (activities.empty()) {
        cout << "Nessuna attivita' presente.\n";
        return;
    }

    cout << "\nAttivita' settimanali:\n";
    for (const auto& a : activities) {
        cout << "- " << a.day << " | " << a.time << " | " << a.description
             << " | " << (a.completed ? "Completata" : "In corso") << "\n";
    }
}

void Planner::markAsDone() {
    showWeek();
    cout << "\nInserisci la descrizione dell'attivita' da segnare come completata: ";
    string desc;
    cin >> ws;
    getline(cin, desc);

    for (auto& a : activities) {
        if (a.description == desc) {
            a.completed = true;
            saveToFile();
            cout << "Attivita' completata.\n";
            return;
        }
    }
    cout << "Attivita' non trovata.\n";
}

void Planner::editActivity() {
    showWeek();
    cout << "\nInserisci la descrizione dell'attivita' da modificare: ";
    string desc;
    cin >> ws;
    getline(cin, desc);

    for (auto& a : activities) {
        if (a.description == desc) {
            cout << "Lascia vuoto un campo se non vuoi modificarlo.\n";
            string newDay, newDesc, newTime;

            cout << "Nuovo giorno (" << a.day << "): ";
            getline(cin, newDay);
            if (!newDay.empty()) a.day = newDay;

            cout << "Nuova descrizione (" << a.description << "): ";
            getline(cin, newDesc);
            if (!newDesc.empty()) a.description = newDesc;

            cout << "Nuova ora (" << a.time << "): ";
            getline(cin, newTime);
            if (!newTime.empty()) a.time = newTime;

            saveToFile();
            cout << "Attivita' modificata.\n";
            return;
        }
    }
    cout << "Attivita' non trovata.\n";
}

void Planner::removeActivity() {
    showWeek();
    cout << "\nInserisci la descrizione dell'attivita' da rimuovere: ";
    string desc;
    cin >> ws;
    getline(cin, desc);

    for (auto it = activities.begin(); it != activities.end(); ++it) {
        if (it->description == desc) {
            activities.erase(it);
            saveToFile();
            cout << "Attivita' rimossa.\n";
            return;
        }
    }
    cout << "Attivita' non trovata.\n";
}

void Planner::checkMonthlyReport() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    int currentMonth = localTime->tm_mon + 1;

    if (lastSavedMonth != -1 && currentMonth != lastSavedMonth) {
        generateMonthlyReport(lastSavedMonth);
    }
    lastSavedMonth = currentMonth;
}

void Planner::generateMonthlyReport(int month) {
    int total = activities.size();
    int done = 0;

    for (const auto& a : activities) {
        if (a.completed) done++;
    }

    ofstream out(reportFile, ios::app);
    out << "Resoconto mese " << month << ":\n";
    out << "Totale attivita': " << total << "\n";
    out << "Completate: " << done << "\n";
    out << "Percentuale: " << (total ? (done * 100 / total) : 0) << "%\n";
    out << "-------------------------\n";
    out.close();

    activities.clear();
    saveToFile();
    cout << "\nResoconto mensile generato automaticamente.\n";
}

void Planner::saveToFile() {
    ofstream out(dataFile);
    for (const auto& a : activities) {
        out << a.toString() << endl;
    }
    out.close();
}

void Planner::loadFromFile() {
    ifstream in(dataFile);
    if (!in) return;

    string line;
    while (getline(in, line)) {
        if (!line.empty())
            activities.push_back(Activity::fromString(line));
    }
    in.close();
}
