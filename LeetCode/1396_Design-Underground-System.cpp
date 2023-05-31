class UndergroundSystem{
private:
    unordered_map<int, pair<string, int>> check;
    unordered_map<string, unordered_map<string, pair<double, int>>> average;

public:
    UndergroundSystem(){}
    
    void checkIn(int id, string stationName, int t){
        check[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t){
        pair<string, int> in = check[id];

        if(average.count(in.first) && average[in.first].count(stationName)){
            pair<double, int> &tmp = average[in.first][stationName];
            tmp.first = (tmp.first * tmp.second + (double)(t - in.second))/ (tmp.second + 1);
            tmp.second++;
        }else{
            average[in.first][stationName] = make_pair((double)(t - in.second), 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation){
        if(average.count(startStation) && average[startStation].count(endStation))
            return average[startStation][endStation].first;
        return -1;
    }
};
