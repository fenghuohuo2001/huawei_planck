#include <iostream>
#include <vector>
#include <random>

// ��ͼ��С
const int MAP_SIZE = 200;

// ��Ʒ��
class Item {
public:
    int x, y; // ��Ʒ����

    Item(int _x, int _y) : x(_x), y(_y) {}
};

// �ִ���
class Ship {
public:
    int x, y; // �ִ�����
    int capacity; // �ִ�����

    Ship(int _x, int _y, int _capacity) : x(_x), y(_y), capacity(_capacity) {}
};

// ��λ��
class Berth {
public:
    int x, y; // ��λ���Ͻ�����
    int efficiency; // ��λЧ��
    int profit_time; // ������������ʱ��

    Berth(int _x, int _y, int _efficiency, int _profit_time) : x(_x), y(_y), efficiency(_efficiency), profit_time(_profit_time) {}
};

// ��������
class Robot {
public:
    int x, y; // ����������
    Item* item; // ������Я������Ʒ

    Robot(int _x, int _y) : x(_x), y(_y), item(nullptr) {}

    // �ƶ�����
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // ������Ʒ
    void carry(Item* _item) {
        item = _item;
    }

    // ������Ʒ
    void put() {
        item = nullptr;
    }
};

int main() {
    // �����ͼ
    std::vector<std::vector<int>> map(MAP_SIZE, std::vector<int>(MAP_SIZE));

    // ���������Ʒ
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, MAP_SIZE - 1);
    Item item(dis(gen), dis(gen));

    // �����ִ��Ͳ�λ
    Ship ship(0, 0, 10); // �ִ�λ�ڵ�ͼ���Ͻ�
    Berth berth(10, 10, 3, 5); // ��λλ�ڵ�ͼ����(10,10)��Ч��Ϊ3�������������ʱ��Ϊ5

    // ����������
    Robot robot(5, 5); // ������λ�ڵ�ͼ����(5,5)

    // �����ͼ��Ϣ
    std::cout << "Map Size: " << MAP_SIZE << "x" << MAP_SIZE << std::endl;
    std::cout << "Item Location: (" << item.x << "," << item.y << ")" << std::endl;
    std::cout << "Ship Location: (" << ship.x << "," << ship.y << "), Capacity: " << ship.capacity << std::endl;
    std::cout << "Berth Location: (" << berth.x << "," << berth.y << "), Efficiency: " << berth.efficiency << ", Profit Time: " << berth.profit_time << std::endl;
    std::cout << "Robot Location: (" << robot.x << "," << robot.y << ")" << std::endl;

    return 0;
}
