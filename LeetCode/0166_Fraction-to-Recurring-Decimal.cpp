class Solution{
public:
    string itos(long long i){
        if(i == 0) return "";
        return itos(i / 10) + (char)((i % 10) + '0');
    }

    string fractionToDecimal(int numerator, int denominator){
        string ans, tmp;
        long long num, den;
        map<int, int> s;
        
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ans += '-';
        num = abs((long long)numerator);
        den = abs((long long)denominator);

        if(num / den == 0)
            ans += "0";
        else
            ans += itos(num/ den);
        num %= den;
        if(num != 0)
            ans +=  ".";
        while(num != 0){
            if(s.count(num) != 0){
                ans += string(tmp, 0, s[num]);
                ans += "(";
                ans += string(tmp, s[num], tmp.size() - s[num]);
                ans += ")";
                break;
            }
            s[num] = tmp.size();
            num *= 10;
            tmp += (num / den) + '0';
            num %= den;
        }
        if(num == 0)
            ans += tmp;

        return ans;
    }
};
