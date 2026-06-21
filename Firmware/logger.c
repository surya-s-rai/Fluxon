typedef struct
{
    uint8_t sig;
    uint8_t hours;
    uint8_t minute;
    uint8_t second;
    uint16_t peak;
}EventRecord;
void Logger_SaveEvent(void);
{
    EventRecord record;
    RTC_Time t;
    RTC_ReadTime(&t);
    record.sig=0xAA;
    record.hours=t.hours;
    record.minute=t.minutes;
    record.second=t.seconds;
    record.peak=ADC_ReadPeak();
    Flash_WritePage(flashAddress,(uint8_t*)&record,sizeof(EventRecord));
    flashAddress+=sizeof(record);

}