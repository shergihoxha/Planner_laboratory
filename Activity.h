#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
using namespace std;

struct Activity {
    string day;
    string description;
    string time;
    bool completed;

    string toString() const;
    static Activity fromString(const string& line);
};

#endif
