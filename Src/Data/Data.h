#include <memory>

/* Data is responsible for collecting data throughout simulation */
class Data
{
    /* total number of people transferred between floors */
    uint64_t people_served;
    /* total number of male random events that occurred */
    uint64_t random_event_male;
    /* total number of female random events that occurred */
    uint64_t random_event_female;
    /* total number of kid random events that occurred */
    uint64_t random_event_kid;
    /* if there is no-one at lift -> simulation is successful, otherwise no */
    bool is_successful;

public:
    /* increments number of people_served */
    void add_person() { people_served++; }
    /* increments number of random_event_male */
    void add_random_male_event() { random_event_male++; }
    /* increments number of random_event_female */
    void add_random_female_event() { random_event_female++; }
    /* increments number of random_event_kid */
    void add_random_kid_event() { random_event_kid++; }
    /* sets how simulation ended, with success or not */
    void set_is_successful(bool is) { is_successful = is; }

    /* returns number of people_served */
    uint64_t get_people_served() const { return people_served; }
    /* returns number of random_event_male */
    uint64_t get_random_event_male() const { return random_event_male; }
    /* returns number of random_event_female */
    uint64_t get_random_event_female() const { return random_event_female; }
    /* returns number of random_event_kid */
    uint64_t get_random_event_kid() const { return random_event_kid; }
    /* returns how simulation ended, successful or not */
    bool get_is_successful() const { return is_successful; }

    /* default Data constructor */
    Data() = default;
    ~Data() = default;
};