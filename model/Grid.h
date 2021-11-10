//
// Created by t30002884 on 2021/11/10.
//

#ifndef TRY_GRID_H
#define TRY_GRID_H

#include <string>
#include <vector>
#include "constant.h"
#include "location.h"

static const Location DIRS[4] = {
        /* East, West, North, South */
        Location{1, 0}, Location{-1, 0},
        Location{0, -1}, Location{0, 1}
};

class Grid {
    int h = 5;
    int w = 6;
    int locs[5][6];
public:
    Grid(const std::string &fileName);

    void show();

    int **calAdjMtx(int, int, int[][WIDTH]);

    const bool inBounds(const Location loc) const {
        return 0 <= loc.x && loc.x < WIDTH && 0 <= loc.y && loc.y < HEIGHT;
    }

    int hash(Location loc) {
        return loc.x * WIDTH + loc.y;
    }

    std::vector<Location> GetNeighbors(Location loc) {
        std::vector<Location> neighbors;

        for (Location dir : DIRS) {
            Location next{loc.x + dir.x, loc.y + dir.y};
            if (inBounds(next)) {
                neighbors.push_back(next);
            }
        }
        return neighbors;
    }

    void gen_node(Location loc) {
        for (Location next : GetNeighbors(loc)) {
            gen_adj(loc, next);
        }
    }

    void gen_adj(Location cur, Location next) {
        switch (loc2val(cur)) {
            case 5:
                break;
            case 0:
                if (loc2val(next) == 0){

                }
        }
    }

    int loc2val(Location loc){
        return locs[loc.x][loc.y];
    }
};


#endif //TRY_GRID_H
