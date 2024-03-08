#include <math.h>
#include "A_star.h"


void Astar::InitAstar(std::vector<std::vector<int>> &_maze){
    maze = _maze;
}

int Astar::calcG(Point *temp_start, Point *point){
    // 计算马氏距离是否等于1，若等于1，则代表走直线，使用const1；否则走斜线const2
    int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kConst1:kConst2;
    int parentG = point->parent == nullptr ? 0 : point->parent->G;  // 累计G
    return parentG + extraG;
}

int Astar::calcH(Point *point, Point *end){
    return sqrt((double)(end->x - point->x) * (double)(end->x - point->x) + (double)(end->y - point->y) * (double)(end->y - point->y)) * kConst1;
}

int Astar::calcF(Point *point){
	return point->G + point->H;
}

Point *Astar::getLeastFpoint(){
    if(!openList.empty()){
        auto resPoint = openList.front();
        for(auto &point : openList)
        if(point->F < resPoint->F){
            resPoint = point;
        }
        return resPoint;
    }
    return nullptr;
}

Point *Astar::findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner){
    openList.push_back(new Point(startPoint.x, startPoint.y));
    while(!openList.empty()){
        auto curPoint = getLeastFpoint();       // 找到F值最小的点
        openList.remove(curPoint);          // 从开启列表中删除
        closeList.push_back(curPoint);      // 放入关闭列表

        // 1. 找到当前周围八邻域中可通过的格子
        auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
        for(auto &target : surroundPoints){
            // 2. 对某一个格子，若不在开启列表中，则加入，设置当前格为其父节点，计算FGH
            if(!isInList(openList, target)){
                target->parent = curPoint;

                target->G = calcG(curPoint, target);
                target->H = calcH(target, &endPoint);
                target->F = calcF(target);

                openList.push_back(target);
            }
            // 3. 对某一个格子，它在开启列表中，计算G值，若比原来大，则跳过，否则设置它的父节点为当前点，更新G和F
            else{
                int tempG = calcG(curPoint, target);
                if (tempG < target->G){
                    target->parent = curPoint;
                    target->G = tempG;
                    target->F = calcF(target);
                }
            }
            Point *resPoint = isInList(openList, &endPoint);
            if(resPoint){
                return resPoint;
            }
        }
    }
    return nullptr;
}

std::list<Point *> Astar::Getpath(Point &startPoint, Point &endPoint, bool isIgnoreCorner){
    Point *result = findPath(startPoint, endPoint, isIgnoreCorner);
    std::list<Point *> path;
    // 返回路径，若没找到路径，返回空链表
    while(result){
        path.push_front(result);
        result = result->parent;
    }

    // 清空临时开闭列表，防止重复执行getpath导致结果异常
    openList.clear();
    closeList.clear();
    return path;
}

Point *Astar::isInList(const std::list<Point *> &list, const Point *point) const{
    for(auto p : list){
        if(p->x == point->x && p->y == point->y){
            return p;
        }
    }
    return nullptr;
}


bool Astar::isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const{
	if (target->x<0 || target->x>maze.size() - 1
		|| target->y<0 || target->y>maze[0].size() - 1
		|| maze[target->x][target->y] == 1
		|| target->x == point->x&&target->y == point->y
		|| isInList(closeList, target)) //如果点与当前节点重合、超出地图、是障碍物、或者在关闭列表中，返回false
		return false;
	else
	{
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1) //非斜角可以
			return true;
		else
		{
			//斜对角要判断是否绊住
			if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0)
				return true;
			else
				return isIgnoreCorner;
		}
	}
}

std::vector<Point *> Astar::getSurroundPoints(const Point *point, bool isIgnoreCorner) const{
	std::vector<Point *> surroundPoints;
 
	for (int x = point->x - 1; x <= point->x + 1; x++)
	for (int y = point->y - 1; y <= point->y + 1; y++)
	if (isCanreach(point, new Point(x, y), isIgnoreCorner))
		surroundPoints.push_back(new Point(x, y));
 
	return surroundPoints;
}
