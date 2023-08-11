#include "date.h"




//check if a given date is valid
int check_date(int day, int mon, int year){

    int is_valid = 1;
    int is_leap = 0;

    if(year >= 1800 && year <= 9999){

        //check if year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            is_leap = 1;
        }

        //check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12){

            //check for days in feb
            if(mon == 2){
                if(is_leap && day == 29){
                    is_valid = 1;
                }
                else if(day > 28){
                    is_valid = 0;
                }
            }
            //check for days in April, June, September and November
            else if(mon == 4 || mon == 6 || mon == 9 || mon == 11){
                if(day > 30){
                    is_valid = 0;
                }
            }

            //check for days in rest of the months
            //i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31){
                is_valid = 0;
            }
        }
        else{
            is_valid = 0;
        }
    }
    else{
        is_valid = 0;
    }

    return is_valid;
}

//check if the first date comes earlier than the second date; each date is broken down into its day, month and year
bool is_earlier(int day1, int mon1, int year1, int day2, int mon2, int year2){

    int is_leap = 0;
    int is_valid = 1;
    bool result = false;


   if(year1 < year2){
        result = true;
   }
    // year1 == year2
   else if(year1 == year2){
        //month fields are also equal
        if(mon1 == mon2){
            if(day1 < day2){
                result = true;
            }
        }
        //comparison using month field
        else if(mon1 < mon2){
            result = true;
        }

    }

    return result;

}
