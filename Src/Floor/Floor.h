#pragma once

#include <cstdint>
#include <queue>
#include <cstdlib>

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

const int d_person_percent = 70;

class Floor
{
    inline static uint32_t floors_number = 0;
    uint32_t this_floor_number;

    std::queue<std::shared_ptr<Person> > person_queue;

    void add_person();

public:
    Floor();
    void iteration();
    std::shared_ptr<Person> get_first_person_in_queue();

    bool is_person();

    void delete_person_from_floor();

};