#include <iostream>
#include <string>
using namespace std;
class WaterSupply {
public:
    void fill() {
        cout << "Наполнение водой...\n";
    }
    void drain() {
        cout << "Слив воды...\n";
    }
};
class Drum {
public:
    void rotateClockWise() {
        cout << "Вращение барабана по часовой стрелке...\n";
    }
    void rotateCounterClockwise() {
        cout << "Вращение барабана против часовой стрелки...\n";
    }
    void stop() {
        cout << "Остановка барабана...\n";
    }
};
class Heater {
public:
    void heatWater(int temperature) {
        cout << "Нагрев воды до " << temperature << " градусов...\n";
    }
};
class WashingMachineFacade {
private:
    WaterSupply waterSupply;
    Drum drum;
    Heater heater;
public: 
    void wash(int temperature) {
        cout << "Начинаем цикл стирки...\n";
        waterSupply.fill();
        heater.heatWater(temperature);
        drum.rotateClockWise();
        cout << "Стирка...";
        drum.rotateCounterClockwise();
        drum.stop();
        waterSupply.drain();
        cout << "Стирка завершена...\n";
    }
    void rinse() {
        cout << "Начало цикла полоскания...\n";
        waterSupply.fill();
        drum.rotateClockWise();
        cout << "Полоскание...\n";
        drum.rotateCounterClockwise();
        drum.stop();
        waterSupply.drain();
        cout << "Полоскание завершено...\n";
    }
    void spin() {
        cout << "Отжим...\n";
        drum.rotateClockWise();
        cout << "Отжим...\n";
        drum.rotateCounterClockwise();
        drum.stop();
        cout << "Цикл отжима завершен.\n";
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    WashingMachineFacade washingMachine;
    washingMachine.wash(40); 
    washingMachine.rinse();  
    washingMachine.spin();
}