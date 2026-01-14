#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include <string>
#include "Activity.h"

using namespace std;

class Planner {
private:
    vector<Activity> activities;
    string dataFile = "planner_data.txt";
    string reportFile = "monthly_report.txt";
    int lastSavedMonth = -1;

    void saveToFile();
    void loadFromFile();
    void generateMonthlyReport(int month);

public:
    Planner();

    void addActivity();
    void showWeek();
    void markAsDone();
    void editActivity();
    void removeActivity();
    void checkMonthlyReport();

    // SOLO PER TEST
    int getActivitiesCount() const;
    bool isActivityCompleted(const std::string& description) const;
    void addActivityTest(const Activity& a);
    bool markAsDoneByDescription(const std::string& description);

};

#endif
