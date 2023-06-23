#pragma once

#include <cstdint>
#include <cstdlib>

/** % needed to let Person has a special event. */
const int d_event_chance = 10;

    /**

    Enumerated names for the Person specifier's special event (male, female, kid).
    */
enum special_event_specifier
{
    male = 1,
    female = 2,
    kid = 3
};

/**

Person is class which is transferred between floors.
It has random events which has impact on Lift and whole Simulation as well as on data collected.
*/
class Person
{
    /** Person's weight. */
    uint16_t weight;
    /** Person's desired floor number. */
    uint32_t floor_number;
    /**  Contains if person has random events. */
    bool random_event;

    /** Sets weight that depend on the person's specifier. */
    void set_weight();

    /**

    Sets a random event for the person.
    The person will have a random event if the generated random number is >= to the event chance.
    The random number is generated using the rand() function in the range of <0;100>.
    */
    void set_random_event();

protected:
    /** Contains person's specifier (Male, Female or Kid). */
    special_event_specifier specifier;
    /** Turns off person's random event (sets to false). */
    void turn_off_random_event() { random_event = false; }

public:
    /** Constructor sets weight and if object will have random event. */
    Person();
    ~Person() = default;
    /** Sets object desired floor that is not current floor. */
    void set_floor(uint32_t, uint32_t);

    /**

    Returns person's weight.
    @return person's weight.
     */
    uint16_t get_person_weight() const { return weight; };

    /**

    Returns persons desired floor number.
    @return persons desired floor number.
     */
    uint32_t get_person_floor() const { return floor_number; };

    /**

    Returns person's random event.
    @return True if has random event, false otherwise.
    */
    bool get_person_random_event_chance() const { return random_event; };

    /**

    Returns enum with person's specifier.
    @return specifier (male, female or kid).
    */
    special_event_specifier get_person_specifier() const { return specifier; };

    virtual uint32_t event(uint32_t) = 0;
    virtual uint32_t event() = 0;

};
