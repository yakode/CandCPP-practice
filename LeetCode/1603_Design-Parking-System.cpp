class ParkingSystem{
private:
    int capacity[3];
    int parking[3] = {0};
public:
    ParkingSystem(int big, int medium, int small){
        capacity[0] = big;
        capacity[1] = medium;
        capacity[2] = small;
    }
    
    bool addCar(int carType){
        if(carType > 0 && carType < 4){
            --carType;
            if(parking[carType] != capacity[carType]){
                parking[carType]++;
                return true;
            }
        }

        return false;
    }
};
