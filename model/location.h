//
// Created by t30002884 on 2021/11/10.
//

#ifndef TRY_LOCATION_H
#define TRY_LOCATION_H

#include <iostream>
#include "constant.h"

struct Location {
    int x, y;
};

bool operator==(Location a, Location b);

bool operator!=(Location a, Location b);

bool operator<(Location a, Location b);

std::basic_iostream<char>::basic_ostream &
operator<<(std::basic_iostream<char>::basic_ostream &out, const Location &loc);

namespace std {
    /* implement hash function so we can put Location into an unordered_set */
    template<>
    struct hash<Location> {
        typedef Location argument_type;
        typedef std::size_t result_type;

        std::size_t operator()(const Location &id) const noexcept {
            return std::hash<int>()(id.x ^ (id.y << 4));
        }
    };
}


#endif //TRY_LOCATION_H
