#include "Activity.h"

string Activity::toString() const {
    return day + ";" + description + ";" + time + ";" + (completed ? "1" : "0");
}

Activity Activity::fromString(const string& line) {
    Activity a;
    size_t p1 = line.find(';');
    size_t p2 = line.find(';', p1 + 1);
    size_t p3 = line.find(';', p2 + 1);

    a.day = line.substr(0, p1);
    a.description = line.substr(p1 + 1, p2 - p1 - 1);
    a.time = line.substr(p2 + 1, p3 - p2 - 1);
    a.completed = line.substr(p3 + 1) == "1";

    return a;
}
