#ifndef RTC_DS3231_H
#define RTC_DS3231_H
typedef struct {
    unsigned char seconds;
    unsigned char minutes;
    unsigned char hours;
}
RTC_Time;
void RTC_ReadTime(RTC_Time *t);
#endif
