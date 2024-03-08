#include <iostream>
#include <vector>
#include <random>

// 地图大小
const int MAP_SIZE = 200;

// 物品类
class Item {
public:
    int x, y; // 物品坐标

    Item(int _x, int _y) : x(_x), y(_y) {}
};

// 轮船类
class Ship {
public:
    int x, y; // 轮船坐标
    int capacity; // 轮船容量

    Ship(int _x, int _y, int _capacity) : x(_x), y(_y), capacity(_capacity) {}
};

// 泊位类
class Berth {
public:
    int x, y; // 泊位左上角坐标
    int efficiency; // 泊位效率
    int profit_time; // 运输产生收益的时间

    Berth(int _x, int _y, int _efficiency, int _profit_time) : x(_x), y(_y), efficiency(_efficiency), profit_time(_profit_time) {}
};

// 机器人类
class Robot {
public:
    int x, y; // 机器人坐标
    Item* item; // 机器人携带的物品

    Robot(int _x, int _y) : x(_x), y(_y), item(nullptr) {}

    // 移动操作
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // 搬运物品
    void carry(Item* _item) {
        item = _item;
    }

    // 放下物品
    void put() {
        item = nullptr;
    }
};

int main() {
    // 定义地图
    std::vector<std::vector<int>> map(MAP_SIZE, std::vector<int>(MAP_SIZE));

    // 随机生成物品
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, MAP_SIZE - 1);
    Item item(dis(gen), dis(gen));

    // 创建轮船和泊位
    Ship ship(0, 0, 10); // 轮船位于地图左上角
    Berth berth(10, 10, 3, 5); // 泊位位于地图坐标(10,10)，效率为3，运输产生收益时间为5

    // 创建机器人
    Robot robot(5, 5); // 机器人位于地图坐标(5,5)

    // 输出地图信息
    std::cout << "Map Size: " << MAP_SIZE << "x" << MAP_SIZE << std::endl;
    std::cout << "Item Location: (" << item.x << "," << item.y << ")" << std::endl;
    std::cout << "Ship Location: (" << ship.x << "," << ship.y << "), Capacity: " << ship.capacity << std::endl;
    std::cout << "Berth Location: (" << berth.x << "," << berth.y << "), Efficiency: " << berth.efficiency << ", Profit Time: " << berth.profit_time << std::endl;
    std::cout << "Robot Location: (" << robot.x << "," << robot.y << ")" << std::endl;

    return 0;
}
