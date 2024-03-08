#include <iostream>
#include "A_star.h"
 
bool InPath(const int &row, const int &col, const std::list<Point *> &path) {
  for (const auto &p : path) {
    if (row == p->x && col == p->y) {
      return true;
    }
  }
  return false;
}
 
int main() {
  //��ʼ����ͼ���ö�ά��������ͼ��1��ʾ�ϰ��0��ʾ��ͨ
  std::vector<std::vector<int>> map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                                       {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                                       {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
                                       {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                                       {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
  Astar astar;
  astar.InitAstar(map);
 
  //������ʼ�ͽ�����
  Point start(1, 1);
  Point end(6, 10);
 
  // A*�㷨��Ѱ·��
  std::list<Point *> path = astar.Getpath(start, end, false);
 
  // ��ӡ���
  for (auto &p : path) {
    std::cout << "(" << p->x << "," << p->y << ") ";
  }
  std::cout << "\n";
 
  for (int row = 0; row < map.size(); ++row) {
    for (int col = 0; col < map[0].size(); ++col) {
      if (InPath(row, col, path)) {
        if (map[row][col] != 0) {
          std::cout << "e ";
        } else {
          std::cout << "* ";
        }
      } else {
        std::cout << map[row][col] << " ";
      }
    }
    std::cout << "\n";
  }
  return 0;
}