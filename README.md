# Planner Settimanale in C++

Un semplice **planner settimanale da riga di comando**, sviluppato in C++, che consente di gestire attività quotidiane con **salvataggio su file** e **resoconto mensile automatico**.

---

## Funzionalità

* ➕ Aggiunta di attività (giorno, ora, descrizione)
* 📋 Visualizzazione attività settimanali
* ✅ Segnare attività come completate
* ✏️ Modifica attività esistenti
* ❌ Rimozione attività
* 💾 Salvataggio persistente su file
* 📊 Resoconto mensile automatico con percentuali

---

## Struttura del progetto

```
PlannerSettimanale/
│
├── Activity.h
├── Activity.cpp
│
├── Planner.h
├── Planner.cpp
│
├── main.cpp
│
├── planner_data.txt        // generato automaticamente
├── monthly_report.txt      // generato automaticamente
└── README.md
```

---

## Compilazione ed esecuzione

### Compilazione (GCC)

```bash
g++ main.cpp Planner.cpp Activity.cpp -o planner
```

### Esecuzione

```bash
./planner
```

---

## Requisiti

* Compilatore C++ (GCC / Clang)
* Standard consigliato: **C++11 o superiore**

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
