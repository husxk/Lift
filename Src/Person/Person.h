#pragma once

#include <cstdint>
#include <cstdlib>
#include <iostream>

const int d_event_chance = 90; // % needed to be decided and not have special event

enum special_event_specifier
{
    male = 1,
    female = 2,
    kid = 3
};

class Person
{
    uint16_t weight;
    uint32_t floor_number = 0;
    bool random_event;

    void set_weight();
    void set_random_event();

protected:
    special_event_specifier specifier;

public:
    Person();
    void set_floor(uint32_t, uint32_t); // TODO Change this to sth better

    uint16_t get_person_weight() const { return weight; };
    uint32_t get_person_floor() const { return floor_number; };
    bool get_person_random_event_chance() const { return random_event; };
    special_event_specifier get_person_specifier() const { return specifier; };

    void turn_off_random_event() { random_event = false; }

    virtual uint32_t event(uint32_t) = 0;
    virtual void event() = 0;

    ~Person() = default;
};
