class Solution {
public:
    double average(vector<int>& salary) {
        int mini = 1e6+1, maxi = 0;
        int sum = 0;

        for(int i = 0; i < salary.size(); ++i){
            sum += salary[i];

            if(salary[i] > maxi) maxi = salary[i];
            if(salary[i] < mini) mini = salary[i];
        }

        sum -= (maxi + mini);

        return (double)sum / (salary.size() - 2);
    }
};
