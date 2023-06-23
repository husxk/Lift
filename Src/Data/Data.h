#include <memory>

/**

Data is responsible for collecting data throughout simulation.
*/
class Data
{
    /** Total number of people transferred between floors. */
    uint64_t people_served;
    /** Total number of male random events that occurred. */
    uint64_t random_event_male;
    /** Total number of female random events that occurred. */
    uint64_t random_event_female;
    /** Total number of kid random events that occurred. */
    uint64_t random_event_kid;
    /** If there is no one at lift -> simulation is successful, otherwise no. */
    bool is_successful;

public:
    /** Increments number of people_served. */
    void add_person() { people_served++; }
    /** Increments number of random_event_male. */
    void add_random_male_event() { random_event_male++; }
    /** Increments number of random_event_female. */
    void add_random_female_event() { random_event_female++; }
    /** Increments number of random_event_kid. */
    void add_random_kid_event() { random_event_kid++; }
    /**

    Sets how simulation ended, with success or not.
    @param is - True if simulation is successful, false otherwise.
    */
    void set_is_successful(bool is) { is_successful = is; }

    /**

    Returns number of people_served.
    @return number of people_served.
    */
    uint64_t get_people_served() const { return people_served; }

    /**

    Returns number of random_event_male.
    @return number of male random events that has occurred.
    */
    uint64_t get_random_event_male() const { return random_event_male; }

    /**

    Returns number of random_event_female.
    @return number female random events that has occurred.
    */
    uint64_t get_random_event_female() const { return random_event_female; }

    /**

    Returns number of random_event_kid.
    @return number of kid random events that has occurred.
    */
    uint64_t get_random_event_kid() const { return random_event_kid; }

    /**

    Returns whether simulation is successful.
    @return True if simulation is successful, false otherwise.
    */
    bool get_is_successful() const { return is_successful; }

    /** Default Data constructor. */
    Data() = default;
    ~Data() = default;
};