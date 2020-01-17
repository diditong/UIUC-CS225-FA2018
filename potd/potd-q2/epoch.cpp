/* Your code here! */
#include "epoch.h"

int hours(time_t a){
   int hours= a / 3600;
   return hours;

}

int days(time_t a){
int days= a / (3600*24);
return days;
}

int years(time_t a){
int years= a / (3600*24*365);
return years;
}
