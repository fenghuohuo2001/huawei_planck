#include <vector>

// 定义200*200的地图区域
const int map_rows = 200;
const int map_cols = 200;
std::vector<std::vector<int>> map_area(map_rows, std::vector<int>(map_cols));

// 定义2*4的轮船
const int ship_rows = 200;
const int ship_cols = 200;
std::vector<std::vector<int>> ship_area(ship_rows, std::vector<int>(ship_cols));

// 定义轮船停留时间ms
const int ship_wait_time = 5;

// 定义4*4的泊位，分为海岸和陆地
const int berth_rows = 4;
const int berth_cols = 4;
// 海岸泊位-放置轮船
std::vector<std::vector<int>> berth_area(berth_rows, std::vector<int>(berth_cols));
// 陆地泊位-放置货物
std::vector<std::vector<int>> berth_area(berth_rows, std::vector<int>(berth_cols));
// 每个泊位有运送货物到船上的效率
float efficiency;
// 每个泊位轮船运走货物产生收益的时间
int revenue_time;

// 定义1*1的机器人
const int robot_rows = 1;
const int robot_cols = 1;
std::vector<std::vector<int>> robot_area(robot_rows, std::vector<int>(robot_cols));

// 定义运输函数
void transport()
