#include <iostream>
#include <cstring>

using namespace std;
int main(){
	char S[1000+5];
	char tmp[1000+5];
	int N;
	char cmd[20];
	int num;
	cin >> S;
	cin >> N;
	int len = strlen(S);
	while(N--){
		cin >> cmd;
		cin >> num;
		if(cmd[0] == 'l'){
			num = num % len;
			strcpy(tmp, S+num);
			strcat(tmp, S);
			tmp[len] = '\0';
			strcpy(S, tmp);
		}else if(cmd[0] == 'r'){
			num = num % len;
			strcpy(tmp, S+(len-num));
			strcat(tmp, S);
			tmp[len] = '\0';
			strcpy(S, tmp);
		}else if(cmd[0] == 'u'){
			num = num % 26;
			for(int i = 0; i < len; i++){
				if(S[i]+num > 122) S[i] += (num-26);
				else S[i] += num;
			}
		}else if(cmd[0] == 'd'){
			num = num % 26;
			for(int i = 0; i < len; i++){
				if(S[i]-num < 97) S[i] -= (num-26);
				else S[i] -= num;
			}
		}
		cout << S << endl;
	}
}
