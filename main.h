#include <vector>

// ����200*200�ĵ�ͼ����
const int map_rows = 200;
const int map_cols = 200;
std::vector<std::vector<int>> map_area(map_rows, std::vector<int>(map_cols));

// ����2*4���ִ�
const int ship_rows = 200;
const int ship_cols = 200;
std::vector<std::vector<int>> ship_area(ship_rows, std::vector<int>(ship_cols));

// �����ִ�ͣ��ʱ��ms
const int ship_wait_time = 5;

// ����4*4�Ĳ�λ����Ϊ������½��
const int berth_rows = 4;
const int berth_cols = 4;
// ������λ-�����ִ�
std::vector<std::vector<int>> berth_area(berth_rows, std::vector<int>(berth_cols));
// ½�ز�λ-���û���
std::vector<std::vector<int>> berth_area(berth_rows, std::vector<int>(berth_cols));
// ÿ����λ�����ͻ��ﵽ���ϵ�Ч��
float efficiency;
// ÿ����λ�ִ����߻�����������ʱ��
int revenue_time;

// ����1*1�Ļ�����
const int robot_rows = 1;
const int robot_cols = 1;
std::vector<std::vector<int>> robot_area(robot_rows, std::vector<int>(robot_cols));

// �������亯��
void transport()
