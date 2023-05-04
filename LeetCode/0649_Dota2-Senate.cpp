// Simulation
class Solution {
public:
    string predictPartyVictory(string senate) {
        // i-th senate would prioritize banning the first enemy senate behind him/her
        int Rcnt = 0, Dcnt = 0;
        for(int i = 0; i < senate.size(); ++i){
            if(senate[i] == 'R') Rcnt++;
            else Dcnt++;
        }

        int Rban = 0, Dban = 0;
        while(1){
            for(int i = 0; i < senate.size(); ++i){
                if(senate[i] == '-') continue;

                if(senate[i] == 'R'){
                    if(Rban > 0){
                        senate[i] = '-';
                        Rban--;
                    }else{
                        Dcnt--; 
                        Dban++;
                    }
                }else{
                    if(Dban > 0){
                        senate[i] = '-';
                        Dban--;
                    }else{
                        Rcnt--;
                        Rban++;
                    }
                }
            }

            if(Dcnt <= 0) return "Radiant";
            if(Rcnt <= 0) return "Dire";
        }

        return "Hi";
    }
};

// Simulation with queue
// This solution is slower.
// I guess that queue operation takes more time
// than iterating whole string senate does.
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<unsigned int> posR, posD;

        for(int i = 0; i < senate.size(); ++i){
            if(senate[i] == 'R') posR.push(i);
            else posD.push(i);
        }

        while(!posR.empty() && !posD.empty()){
            if(posR.front() < posD.front()){
                posD.pop();
                posR.push(posR.front()+senate.size());
                posR.pop();
            }else{
                posR.pop();
                posD.push(posD.front()+senate.size());
                posD.pop();
            }
        }

        if(posR.empty()) return "Dire";
        return "Radiant";
    }
};
