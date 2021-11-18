#include <iostream>
#include <vector>

#define WIDTH 4
#define HEIGHT 4
#define AREA 16
#define BLOCKED AREA

typedef enum { WAL, CU, CD, CL, CR, SVR, FLT, RCK} NodeType;

struct Node{
    int x;
    int y;
    int id;
    NodeType type;

    Node(){}
    Node(int _x, int _y, NodeType _type){
        x = _x;
        y = _y;
        id = x + y * WIDTH;
        type = _type;
    }
    bool isFlat() const{
        bool ret = type == FLT || type == SVR || type == RCK;
        return ret;
    }
    std::string toString() const {
        return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(isFlat()) + "\n";
    }
};

struct Path{
    Node start;
    Node end;
    Node next;
    int len;
    std::string toString() const{
        return next.toString() + " " + std::to_string(len) + "\n";
    }
};
std::vector<Node> getNeighbor(Node n){
    std::vector<Node> ret;

};


static Path pathMtx[AREA][AREA];
static Node nodeMtx[HEIGHT][WIDTH];

void initPath(){
    for (auto & row : pathMtx){
        for (auto & path : row){
            path.len = BLOCKED;
        }
    }
}

static int adj_mtx[AREA][AREA] = {
        //                   4           8           12
        {9, 9, 9, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 9, 9, 9, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 1, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 1, 9, 9, 1, 9, 9, 9, 9, 1, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1, 9, 9, 1, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 9, 9, 1, 9}
};

std::vector<Path> onePaths(){
    std::vector<Path> nowPaths;
    for (int i=0; i<AREA;i++){
        for (int j=0; j<AREA;j++){
            if (adj_mtx[i][j] == 1){
                pathMtx[i][j].len = 1;
                nowPaths.push_back(pathMtx[i][j]);
            }
        }
    }
    return nowPaths;
}

void countAllPath(){
    std::vector<Path> lastPaths = onePaths();
    while (!lastPaths.empty()){
        for (auto & lp : lastPaths){
            std::vector<Path> nowPaths;
            for (Node nb : getNeighbor(lp.end)){
                Path p = pathMtx[lp.next.id][nb.id];
                if (lp.len + 1 < p.len){
                    p.len = lp.len + 1;
                    nowPaths.push_back(p);
                }
            }
            lastPaths = nowPaths;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    countAllPath();
    return 0;
}
