#include <gtest/gtest.h>
#include "../Planner.h"

TEST(PlannerTest, MarkActivityCompleted) {
    Planner p;

    Activity a{"Martedi", "Algoritmi", "16:00", false};
    p.addActivityTest(a);

    bool result = p.markAsDoneByDescription("Algoritmi");

    EXPECT_TRUE(result);
    EXPECT_TRUE(p.isActivityCompleted("Algoritmi"));
}
