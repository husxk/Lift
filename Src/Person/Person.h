#pragma once

#include <cstdint>
#include <cstdlib>

/* % needed to let Person has special event */
const int d_event_chance = 10;

/* enum of name for Person specifier's */
enum special_event_specifier
{
    male = 1,
    female = 2,
    kid = 3
};

/* Person is class which is transferred between floors, it has random events which has impact on Lift and whole Simulation
    as well as on data collected*/
class Person
{
    /* person's weight */
    uint16_t weight;
    /* person's desired floor number */
    uint32_t floor_number;
    /*  contains if person has random events */
    bool random_event;

    /* sets weight that depend on person's specifier */
    void set_weight();
    /* rand() in range <0;100> if is >= d_event_chance -> this person will have random event */
    void set_random_event();

protected:
    /* contains person's specifier (Male, Female or Kid)*/
    special_event_specifier specifier;
    /* sets random_event to false */
    void turn_off_random_event() { random_event = false; }

public:
    /* constructor sets weight and if object will have random event */
    Person();
    ~Person() = default;
    /* set object desired floor that is not current floor */
    void set_floor(uint32_t, uint32_t);

    /* returns persons weight */
    uint16_t get_person_weight() const { return weight; };
    /*  returns persons desired floor number */
    uint32_t get_person_floor() const { return floor_number; };
    /* returns true if person will have random event, false if no*/
    bool get_person_random_event_chance() const { return random_event; };
    /* returns persons specifier */
    special_event_specifier get_person_specifier() const { return specifier; };

    virtual uint32_t event(uint32_t) = 0;
};
