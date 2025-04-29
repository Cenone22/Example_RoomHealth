#include <unity.h>
#include "room.h"

// Needed because production main.c is not compiled
int temperature_metricUnits = 0;

void setUp(void) {}
void tearDown(void) {}

void test_RoomInit(void) {
    Room room;
    Room_init(&room);
    TEST_ASSERT_EQUAL_INT(0, room.health);
}

void test_RoomHealthCalculations(void) {
    Room room;
    Room_init(&room);

    room.temperature = 25;
    room.humidity = 45;
    room.CO2 = 400;

    int health = Room_calculateHealth(&room);
    TEST_ASSERT_TRUE(health >= 0 && health <= 100);
}
