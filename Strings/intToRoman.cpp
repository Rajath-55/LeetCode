class Solution {
public:
    string intToRoman(int num) {
              unordered_map<int,string>map;
        map[1]="I";
        map[2]="II";
        map[3]="III";
        map[4]="IV";
        map[5]="V";
        map[6]="VI";
        map[7]="VII";
        map[8]="VIII";
        map[9]="IX";
        string res;
        while(num)
        {
            if(num/1000)
            {
                int x=num/1000;
                num=num%1000;
                while(x)
                {
                    x--;
                   res+="M"; 
                }
            }
            else if(num/900)
            {
                int x=num/900;
                num=num%900;
                res+="CM";
            }
            else if(num/500)
            {
                int x=num/500;
                num=num%500;
                res+="D";
            }
            else if(num/400)
            {
                int x=num/400;
                num=num%400;
                res+="CD";
            }
            else if(num/100)
            {
                int x=num/100;
                num=num%100;
                while(x)
                {
                    x--;
                   res+="C"; 
                }
            }
            else if(num/90)
            {
                int x=num/90;
                num=num%90;
                res+="XC";
            }
            else if(num/50)
            {
                int x=num/50;
                num=num%50;
                res+="L";
            }
            else if(num/40)
            {
                int x=num/40;
                num=num%40;
                res+="XL";
            }
            else if(num/10)
            {
                int x=num/10;
                num=num%10;
                while(x)
                {
                    x--;
                   res+="X"; 
                }
            }
            else
            {
                res+=map[num];
                num=num/10;
            }
        }
        return res;
    }
    
};