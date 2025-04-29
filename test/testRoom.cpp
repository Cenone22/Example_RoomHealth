#include <assert.h>
#include <stdio.h>

// Include the C header with extern "C"
extern "C" {
    #include "room.h"
    #include "temperature.h"
    #include "humidity.h"
}

// Stub the globals and functions used in room.c
int temperature_metricUnits = 1; // used in temperature.c if necessary

// Mock implementations of dependencies (if they’re not already implemented)
float temperature_getTemperature() {
    return 22.0f; // example temperature
}

uint8_t humidity_getHumidity() {
    return 40; // example humidity
}

void temperature_meassure() {
    // No-op or fake implementation
}

void humidity_meassure() {
    // No-op or fake implementation
}

void test_room_getRoomHealth() {
    room_create("Test Room", 25); // setup

    room_roomHealth_t health = room_getRoomHealth();
    assert(health >= PERFECT && health <= DISASTER); // basic sanity check
    printf("Health enum: %d -> %s\n", health, room_getRoomHealthText(health));
    printf("test_room_getRoomHealth passed.\n");
}

int main() {
    test_room_getRoomHealth();
    return 0;
}
