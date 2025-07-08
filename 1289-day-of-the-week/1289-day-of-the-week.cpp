class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int daysInMonth[12] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int daysCount=0;
        
        for(int yr=1971; yr<year; yr++)
        {
			//Leap year
            if((yr%4==0 && yr%100!=0) || yr%400==0)
            {
                daysCount+=366;
            }
            else
            {
                daysCount+=365;
            }
        }
        
        for(int mth=1; mth<month; mth++)
        {
            if(mth == 2)
            {
                if((year%4==0 && year%100!=0) || (year%400==0))
                {
                    daysCount+=29;
                }
                else
                {
                    daysCount+=28;
                }
            }
            else
            {
                daysCount+=daysInMonth[mth-1];
            }
        }
        
        daysCount += day;
        
        daysCount %= 7;
        
        vector<string> ans{"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
        
        return ans[daysCount];
    }
};