# Planner Settimanale

Progetto di laboratorio sviluppato in C++ che implementa un **planner settimanale da terminale** con salvataggio su file e test automatici.
---

## Funzionalità

* ➕ Aggiunta di attività (giorno, ora, descrizione)
* 📋 Visualizzazione attività settimanali
* ✅ Segnare attività come completate
* ✏️ Modifica attività esistenti
* ❌ Rimozione attività
* 💾 Salvataggio persistente su file
* 📊 Resoconto mensile automatico con percentuali
* **Test automatici con GoogleTest**

---

## Struttura del progetto

```
Planner_laboratory/
├── CMakeLists.txt
├── main.cpp
├── Activity.h / Activity.cpp
├── Planner.h / Planner.cpp
├── tests/
│ ├── main_test.cpp
│ ├── test_activity.cpp
│ └── test_planner.cpp
└── README.md
```

---

## Compilazione ed esecuzione

### Clonare il repository
```bash
git clone https://github.com/<username>/Planner_laboratory.git
cd Planner_laboratory
```
### Build con CMake

cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug

### Avviare il programma

./Planner_app
---

### Esecuzione dei test

I test sono realizzati con GoogleTest.

./Planner_tests
---

Oppure direttamente da CLion selezionando il target *Planner_tests*

## Tecnologie utilizzate

- **Linguaggio:** C++20  
- **Build system:** CMake  
- **Testing:** GoogleTest  
- **IDE:** CLion
---

## Possibili estensioni future

* Interfaccia grafica (Qt / SFML)
* Identificatore univoco per attività
* Ordinamento per giorno e ora
* Esportazione CSV / PDF
* Versione multi-utente

---

## Autore

**Shergi**

Studente di Ingegneria Informatica
