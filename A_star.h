#pragma once

#include <vector>
#include <list>

const int kConst1 = 10;     // 直线移动一格消耗
const int kConst2 = 14;     // 斜线移动一个消耗

struct Point{
    int x, y;
    int F, G, H;
    Point *parent;
    Point(int _x, int _y): x(_x), y(_y), F(0), G(0), H(0), parent(nullptr){}
};

class Astar{
public:
    void InitAstar(std::vector<std::vector<int>> &_maze);
    std::list<Point *> Getpath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);

private:
    Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
    std::vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
    bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const;
    Point *isInList(const std::list<Point *> &list, const Point *point) const;
    Point *getLeastFpoint();

    int calcG(Point *temp_start, Point *point);
    int calcH(Point *point, Point *end);
    int calcF(Point *Point);

private:
    std::vector<std::vector<int>> maze;
    std::list<Point *> openList;
    std::list<Point *> closeList;
};
