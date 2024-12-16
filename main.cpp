/**
 * ClassName: ${NAME}
 * package: ${PACKAGE_NAME}
 * Description:
 * @Author: innno
 * @Create: 2024/2/27 - 21:54
 * @Version: v1.0
 */
#include <bits/stdc++.h>
using namespace std;

const auto li = list{0, 90, 92, 93, 94, 94, 94, 94, 95, 95, 95, 95, 95, 96, 96, 96, 97, 97, 97, 98, 98};
const vector<double> Standard_force(li.begin(), li.end());

class round {
    double distance = 0;
    double wind = 0;
    double altitude = 0; //����Ϊ�ߴ��,����Ϊ�ʹ��
    double dynamics = 0; //����Ϊ˳��,����Ϊ���
    double angle = 0;

public:
    void initialization();

    void calculate();

    round() = default;
} Ro;

void round::initialization() {
    cout << "�������,����(����Ϊ˳��,����Ϊ���),�߲�(����Ϊ�ߴ��,����Ϊ�ʹ��)" << "\n";
    cin >> distance >> wind >> altitude;
}

void Decimal_screen_distance(auto &distance, auto &dynamics, auto &angle) { //�ȼ���С������,Ŀǰ�ǶԵ�
    if (distance - static_cast<int>(distance) > 0)
        {
            const auto distance_diff = 1 - distance + static_cast<int>(distance);
            distance = static_cast<int>(distance) + 1;
            angle = 90 - distance;
            dynamics = Standard_force[static_cast<int>(distance)];
            dynamics -= distance_diff * (60 / distance);
        } else //û��
        {
            angle = 90 - distance;
            dynamics = Standard_force[static_cast<int>(distance)];
        }
}

void Fractional_wind(auto &distance, auto &dynamics, auto &wind, auto &angle) { //�ټ���С������,Ŀǰû����
    angle += static_cast<int>(wind * 2);
    auto wind_diff = ((wind * 2) - static_cast<int>(wind * 2)) / 2;
    if (wind_diff<0)
        {
            wind_diff=-wind_diff;
        }
    dynamics -= (12 / distance) * wind_diff / 0.1;
}

void Height_difference_calculation(auto &altitude, auto &distance, auto &dynamics) { //�ټ���߲�Ӱ��,Ŀǰ�ǶԵ�
    if (altitude < 0)
        {
            altitude = -altitude;
            dynamics += altitude * 4;
        } else
        {
            if (distance <= 10)
                {
                    dynamics -= altitude * 3;
                } else
                {
                    dynamics -= altitude * 3.5;
                }
        }
}

void round::calculate() {
    Decimal_screen_distance(distance, dynamics, angle); //�ȼ���С������
    Fractional_wind(distance, dynamics, wind, angle); //�ټ���С������
    Height_difference_calculation(altitude, distance, dynamics); //�ټ���߲�Ӱ��
    cout << "�Ƕ�:" << angle << "����:" << dynamics;;
}

void bout() {
    Ro.initialization();
    Ro.calculate();
}

int main() {
    //ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _=1;
    while (_)
        {
            bout();
            cout<<"�Ƿ��˳�?�˳�������0,����������1";
            cin>>_;
        }
    return 0;
}
