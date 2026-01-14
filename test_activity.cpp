#include <gtest/gtest.h>
#include "../Activity.h"

TEST(ActivityTest, ToStringWorks) {
    Activity a{"Lunedi", "Studio", "14:00", true};
    EXPECT_EQ(a.toString(), "Lunedi;Studio;14:00;1");
}

TEST(ActivityTest, FromStringWorks) {
    std::string line = "Martedi;Palestra;18:00;0";
    Activity a = Activity::fromString(line);

    EXPECT_EQ(a.day, "Martedi");
    EXPECT_EQ(a.description, "Palestra");
    EXPECT_EQ(a.time, "18:00");
    EXPECT_FALSE(a.completed);
}
