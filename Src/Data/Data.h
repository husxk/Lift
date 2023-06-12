#include <memory>

// class is responsible for collecting data from simulation

class Data
{
    uint64_t people_served; // total number of people transferred between floors
    uint64_t random_event_male; // total number of male random events that occurred
    uint64_t random_event_female; // total number of female random events that occurred
    uint64_t random_event_kid;  // total number of kid random events that occurred
    bool is_successful; // if there is no-one at lift -> simulation is successful, otherwise no

public:

    void add_person() { people_served++; }
    void add_random_male_event() { random_event_male++; }
    void add_random_female_event() { random_event_female++; }
    void add_random_kid_event() { random_event_kid++; }
    void set_is_successful(bool is) { is_successful = is; }

    uint64_t get_people_served() const { return people_served; }
    uint64_t get_random_event_male() const { return random_event_male; }
    uint64_t get_random_event_female() const { return random_event_female; }
    uint64_t get_random_event_kid() const { return random_event_kid; }
    uint64_t get_is_successful() const { return is_successful; }

    Data() = default;
    ~Data() = default;
};