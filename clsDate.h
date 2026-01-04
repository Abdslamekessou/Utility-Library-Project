#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate
{

private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:

    clsDate() {

        time_t t = time(0);
        tm* now = localtime(&t);

        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;

    }

    clsDate(string sDate) {

        vector <string> vDate;
        vDate = clsString::Split(sDate, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    clsDate(short Day, short Month, short Year) {

        _Day = Day;
        _Month = Month;
        _Year = Year;

    }

    clsDate(short DateOrderInYear, short Year) {

        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);

        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;

    }

    void setDay(short Day) {
        _Day = Day;
    }

    short getDay() {
        return _Day;
    }

    void setMonth(short Month) {
        _Month = Month;
    }

    short getMonth() {
        return _Month;
    }

    void setYear(short Year) {
        _Year = Year;
    }

    short getYear() {
        return _Year;
    }

    __declspec(property(get = getDay, put = setDay)) short Day;
    __declspec(property(get = getMonth, put = setMonth)) short Month;
    __declspec(property(get = getYear, put = setYear)) short Year;


    void Print() {

        cout << DateToString() << endl;

    }

    static clsDate GetSystemDay() {

        time_t t = time(0);
        tm* now = localtime(&t);
        clsDate Date;

        Date.Day = now->tm_mday;
        Date.Month = now->tm_mon + 1;
        Date.Year = now->tm_year + 1900;

        return Date;
    }


    static bool IsValidDate(clsDate Date) {

        if (Date.Day < 1 || Date.Day > 31)
            return false;

        if (Date.Month < 1 || Date.Month > 12)
            return false;


        if (Date.Month == 2) {

            if (IsLeapYear(Date.Year)) {

                if (Date.Day > 29)
                    return false;

            }
            else {

                if (Date.Day > 28)
                    return false;

            }

        }



        int DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)
            return false;


        return true;


    }

    bool IsValid() {

        return IsValidDate(*this);

    }






    static string DateToString(clsDate Date) {

        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

    }


    string DateToString() {

        return DateToString(*this);

    }


    static bool IsLeapYear(short year) {

        return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

    }


    bool IsLeapYear() {

        return IsLeapYear(_Year);

    }


    static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year) {

        clsDate Date;
        short RemainingDays;
        short MonthDays = 0;

        RemainingDays = DayOrderInYear;
        Date.Year = Year;
        Date.Month = 1;

        while (true) {

            MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

            if (RemainingDays > MonthDays) {

                RemainingDays -= MonthDays;
                Date.Month++;

            }
            else
            {
                Date.Day = RemainingDays;
                break;
            }

        }

        return Date;

    }


    static short NumberOfDaysInAYear(short year) {

        return IsLeapYear(year) ? 366 : 365;

    }

    short NumberOfDaysInAYear() {

        return NumberOfDaysInAYear(_Year);

    }


    static short NumberOfHoursInAYear(short year) {

        return NumberOfDaysInAYear(year) * 24;

    }


    short NumberOfHoursInAYear() {

        return NumberOfHoursInAYear(_Year);

    }


    static int NumberOfMinutesInAYear(short year) {

        return NumberOfHoursInAYear(year) * 60;

    }


    int NumberOfMinutesInAYear() {

        return NumberOfMinutesInAYear(_Year);

    }

    static int NumberOfSecondesInAYear(int year) {

        return NumberOfMinutesInAYear(year) * 60;

    }

    int NumberOfSecondesInAYear() {

        return NumberOfSecondesInAYear(_Year);

    }


    static short NumberOfDaysInAMonth(short month, short year) {

        if (month < 1 || month > 12)
            return 0;


        int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 };

        return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

    }


    short NumberOfDaysInAMonth() {

        return NumberOfDaysInAMonth(_Month, _Year);

    }


    static short NumberOfHoursInAMonth(short month, short year) {

        return NumberOfDaysInAMonth(month, year) * 24;

    }

    short NumberOfHoursInAMonth() {

        return NumberOfHoursInAMonth(_Month, _Year);

    }


    static int NumberOfMinutesInAMonth(short month, short year) {

        return NumberOfHoursInAMonth(month, year) * 60;

    }

    int NumberOfMinutesInAMonth() {

        return NumberOfMinutesInAMonth(_Month, _Year);

    }


    static int NumberOfSecondesInAMonth(short month, short year) {

        return NumberOfMinutesInAMonth(month, year) * 60;

    }

    int NumberOfSecondesInAMonth() {

        return NumberOfSecondesInAMonth(_Month, _Year);

    }

    static short DayOfWeekOrder(short day, short month, short year) {

        short a, y, m;

        a = (14 - month) / 12;

        y = year - a;

        m = month + 12 * a - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    }


    short DayOfWeekOrder() {

        return DayOfWeekOrder(_Day, _Month, _Year);

    }

    static string DayShortName(short DayOfWeekOrder) {

        string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return arrDaysNames[DayOfWeekOrder];
    }

    static string DayShortName(short Day, short Month, short Year) {

        string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return arrDaysNames[DayOfWeekOrder(Day, Month, Year)];
    }

    string DayShortName() {

        string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return arrDaysNames[DayOfWeekOrder(_Day, _Month, _Year)];
    }


    static string MonthShortName(short MonthNumber) {

        string arrMonthNames[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };

        return arrMonthNames[MonthNumber - 1];

    }

    string MonthShortName() {

        return MonthShortName(_Month);

    }


    static void PrintMonthCalendar(short month, short year) {

        short NumberOfDays;

        short current = DayOfWeekOrder(1, month, year);

        NumberOfDays = NumberOfDaysInAMonth(month, year);

        printf("\n_________________%s_________________\n\n", MonthShortName(month).c_str());

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short i;

        for (i = 0; i < current; i++) {

            printf("     ");
        }


        for (short j = 1; j <= NumberOfDays; j++) {

            printf("%5d", j);

            if (++i == 7) {
                i = 0;
                printf("\n");
            }

        }


        printf("\n\n_____________________________________");
    }


    void PrintMonthCalendar() {

        return PrintMonthCalendar(_Month, _Year);

    }


    static void PrintYearCalendar(short year) {

        printf("\n_____________________________________\n");
        printf("\n              Calendar - %d", year);
        printf("\n_____________________________________\n");

        for (short i = 1; i <= 12; i++) {
            cout << "\n\n";
            PrintMonthCalendar(i, year);

        }

        return;
    }


    void PrintYearCalendar() {

        printf("\n_____________________________________\n");
        printf("\n              Calendar - %d", _Year);
        printf("\n_____________________________________\n");

        for (short i = 1; i <= 12; i++) {
            cout << "\n\n";
            PrintMonthCalendar(i, _Year);

        }

        return;
    }


    static short NumberOfDaysFromTheBeginningOfTheYear(short day, short month, short year) {

        short TotalDays = 0;


        for (short j = 1; j <= month - 1; j++) {

            TotalDays += NumberOfDaysInAMonth(j, year);
        }

        TotalDays += day;

        return TotalDays;

    }



    short NumberOfDaysFromTheBeginningOfTheYear() {

        short TotalDays = 0;


        for (short j = 1; j <= _Month - 1; j++) {

            TotalDays += NumberOfDaysInAMonth(j, _Year);
        }

        TotalDays += _Day;

        return TotalDays;

    }


    void AddDays(short Days) {

        short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
        short MonthDays = 0;

        _Month = 1;

        while (true) {

            MonthDays = NumberOfDaysInAMonth(_Month, _Year);

            if (RemainingDays > MonthDays) {

                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12) {

                    _Month = 1;
                    _Year++;

                }
            }
            else
            {
                _Day = RemainingDays;
                break;
            }

        }


    }


    static bool IsDate1BeforeThanDate2(clsDate Date1, clsDate Date2) {

        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

    }


    bool IsDate1BeforeThanDate2(clsDate Date2) {

        return IsDate1BeforeThanDate2(*this, Date2);

    }


    static bool IsDate1EqualsDate2(clsDate Date1, clsDate Date2) {

        return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false);
    }


    bool IsDate1EqualsDate2(clsDate Date2) {

        return IsDate1EqualsDate2(*this, Date2);

    }

    static bool IsLastDayInMonth(clsDate Date) {

        return NumberOfDaysInAMonth(Date.Month, Date.Year) == Date.Day;

    }


    bool IsLastDayInMonth() {

        return IsLastDayInMonth(*this);

    }


    static bool IsLastMonthInYear(short Month) {

        return Month == 12;

    }


    bool IsLastMonthInYear() {

        return IsLastMonthInYear(_Month);

    }


    static clsDate AddOneDay(clsDate Date) {

        if (IsLastDayInMonth(Date)) {

            if (IsLastMonthInYear(Date.Month)) {

                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else {
            Date.Day++;
        }

        return Date;

    }


    void AddOneDay() {

        *this = AddOneDay(*this);

    }


    static void SwapDates(clsDate& Date1, clsDate& Date2) {

        clsDate TempDate;

        TempDate = Date1;

        Date1 = Date2;

        Date2 = TempDate;

    }



    static int GetDiffrenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {

        int Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeThanDate2(Date1, Date2)) {

            SwapDates(Date1, Date2);
            SwapFlagValue = -1;

        }

        while (IsDate1BeforeThanDate2(Date1, Date2)) {

            Days++;
            Date1 = AddOneDay(Date1);

        }

        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

    }


    int GetDiffrenceInDays(clsDate Date2, bool IncludeEndDay = false) {

        return GetDiffrenceInDays(*this, Date2, IncludeEndDay);

    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth) {

        return GetDiffrenceInDays(DateOfBirth, clsDate::GetSystemDay(), true);

    }


    static clsDate IncreaseDateByOneWeek(clsDate& Date) {

        for (short i = 1; i <= 7; i++) {

            Date = AddOneDay(Date);

        }

        return Date;
    }


    void IncreaseDateByOneWeek() {

        IncreaseDateByOneWeek(*this);

    }


    static clsDate IncreaseDateByXWeeks(clsDate Date, int weeks) {

        for (short i = 0; i < weeks; i++) {

            IncreaseDateByOneWeek(Date);

        }

        return Date;
    }


    void IncreaseDateByXWeeks(int weeks) {

        *this = IncreaseDateByXWeeks(*this, weeks);

    }


    static clsDate IncreaseDateByOneMonth(clsDate Date) {

        if (Date.Month == 12) {

            Date.Month = 1;
            Date.Year++;

        }
        else {

            Date.Month++;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > NumberOfDaysInCurrentMonth) {

            Date.Day = NumberOfDaysInCurrentMonth;

        }

        return Date;
    }



    void IncreaseDateByOneMonth() {

        *this = IncreaseDateByOneMonth(*this);

    }


    static clsDate IncreaseDateByXDays(clsDate Date, short days) {

        for (short i = 1; i <= days; i++) {

            Date = AddOneDay(Date);

        }

        return Date;

    }


    void IncreaseDateByXDays(short days) {

        *this = IncreaseDateByXDays(*this, days);

    }


    static clsDate IncreaseDateByXMonths(clsDate Date, short months) {

        for (short i = 0; i < months; i++) {

            Date = IncreaseDateByOneMonth(Date);

        }

        return Date;

    }


    void IncreaseDateByXMonths(short months) {

        *this = IncreaseDateByXMonths(*this, months);

    }


    static clsDate IncreaseDateByOneYear(clsDate Date) {

        Date.Year++;
        return Date;

    }


    void IncreaseDateByOneYear() {

        *this = IncreaseDateByOneYear(*this);

    }


    static clsDate IncreaseDateByXYears(clsDate& Date, short years) {

        for (short i = 0; i < years; i++) {

            Date = IncreaseDateByOneYear(Date);

        }

        return Date;

    }


    void IncreaseDateByXYears(short years) {

        *this = IncreaseDateByXYears(*this, years);

    }


    static clsDate IncreaseDateByOneDecade(clsDate Date) {

        Date.Year += 10;

        return Date;
    }


    void IncreaseDateByOneDecade() {

        *this = IncreaseDateByOneDecade(*this);

    }

    static clsDate IncreaseDateByXDecades(clsDate Date, short decade) {

        for (short i = 0; i < decade * 10; i++) {

            Date = IncreaseDateByOneYear(Date);

        }

        return Date;
    }

    void IncreaseDateByXDecades(short decade) {

        *this = IncreaseDateByXDecades(*this, decade);

    }


    static clsDate IncreaseDateByOneCentury(clsDate Date) {

        Date.Year += 100;

        return Date;
    }

    void IncreaseDateByOneCentury() {

        *this = IncreaseDateByOneCentury(*this);

    }



    static clsDate IncreaseDateByOneMillennium(clsDate Date) {

        Date.Year += 1000;

        return Date;
    }


    void IncreaseDateByOneMillennium() {

        *this = IncreaseDateByOneMillennium(*this);

    }


    static clsDate DecreaseDateByOneDay(clsDate Date) {

        if (Date.Day == 1) {

            if (Date.Month == 1) {

                Date.Day = 31;
                Date.Month = 12;
                Date.Year--;
            }
            else {
                Date.Day = NumberOfDaysInAMonth(Date.Month - 1, Date.Year);
                Date.Month--;
            }
        }
        else {
            Date.Day--;
        }

        return Date;

    }


    void DecreaseDateByOneDay() {

        *this = DecreaseDateByOneDay(*this);

    }


    static clsDate DecreaseDateByXDays(clsDate Date, short Days) {

        for (short i = 1; i <= Days; i++) {

            Date = DecreaseDateByOneDay(Date);

        }

        return Date;

    }


    void DecreaseDateByXDays(short Days) {

        *this = DecreaseDateByXDays(*this, Days);

    }


    static clsDate DecreaseDateByOneWeek(clsDate Date) {

        for (short i = 1; i <= 7; i++) {

            Date = DecreaseDateByOneDay(Date);

        }

        return Date;

    }


    void  DecreaseDateByOneWeek() {

        *this = DecreaseDateByOneWeek(*this);

    }


    static clsDate DecreaseDateByXWeeks(clsDate Date, short Weeks) {

        for (short i = 1; i <= Weeks; i++) {

            Date = DecreaseDateByOneWeek(Date);

        }

        return Date;

    }


    void DecreaseDateByXWeeks(short Weeks) {

        *this = DecreaseDateByXWeeks(*this, Weeks);

    }


    static clsDate DecreaseDateByOneMonth(clsDate Date) {

        if (Date.Month == 1) {

            Date.Month = 12;
            Date.Year--;

        }
        else {

            Date.Month--;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > NumberOfDaysInCurrentMonth) {

            Date.Day = NumberOfDaysInCurrentMonth;

        }

        return Date;

    }


    void DecreaseDateByOneMonth() {

        *this = DecreaseDateByOneMonth(*this);

    }

    static clsDate DecreaseDateByXMonths(clsDate Date, short Months) {

        for (short i = 1; i <= Months; i++) {

            Date = DecreaseDateByOneMonth(Date);

        }

        return Date;

    }

    void DecreaseDateByXMonths(short Months) {

        *this = DecreaseDateByXMonths(*this, Months);

    }


    static clsDate DecreaseDateByOneYear(clsDate Date) {

        Date.Year--;

        return Date;

    }


    void DecreaseDateByOneYear() {

        *this = DecreaseDateByOneYear(*this);

    }




    static clsDate DecreaseDateByXYears(clsDate Date, short Years) {

        for (short i = 1; i <= Years; i++) {

            Date = DecreaseDateByOneYear(Date);

        }

        return Date;

    }

    void DecreaseDateByXYears(short Years) {

        *this = DecreaseDateByXYears(*this, Years);

    }

    static clsDate DecreaseDateByOneDecade(clsDate Date) {

        Date.Year -= 10;

        return Date;

    }


    void DecreaseDateByOneDecade() {

        *this = DecreaseDateByOneDecade(*this);

    }



    static clsDate DecreaseDateByXDecades(clsDate Date, short Decade) {

        for (short i = 1; i <= Decade * 10; i++) {

            Date = DecreaseDateByOneYear(Date);

        }

        return Date;

    }



    void DecreaseDateByXDecades(short Decade) {

        *this = DecreaseDateByXDecades(*this, Decade);

    }




    static clsDate DecreaseDateByOneCentury(clsDate Date) {

        Date.Year -= 100;

        return Date;

    }

    void DecreaseDateByOneCentury() {

        *this = DecreaseDateByOneCentury(*this);

    }


    static clsDate DecreaseDateByOneMillinium(clsDate Date) {

        Date.Year -= 1000;

        return Date;

    }


    void DecreaseDateByOneMillinium() {

        *this = DecreaseDateByOneMillinium(*this);

    }


    static short DayOfWeekOrder(clsDate Date) {

        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);

    }


    static bool IsEndOfWeek(clsDate Date) {

        return   DayOfWeekOrder(Date) == 6;

    }


    bool IsEndOfWeek() {

        return IsEndOfWeek(*this);

    }




    static bool IsWeekEnd(clsDate Date) {
        //Weekends are Fri and Sat

        short DayIndex = DayOfWeekOrder(Date);

        return (DayIndex == 5 || DayIndex == 6);

    }


    bool IsWeekEnd() {

        return IsWeekEnd(*this);

    }


    static bool IsBusinessDay(clsDate Date) {
        // Business days are Sun , Mon , Tue , Wed and Thur
        return !IsWeekEnd(Date);

    }

    bool IsBusinessDay() {

        return IsBusinessDay(*this);

    }



    static short DaysUtilEndOfWeek(clsDate Date) {

        return 6 - DayOfWeekOrder(Date);

    }


    short DaysUtilEndOfWeek() {

        return DaysUtilEndOfWeek(*this);

    }


    static short DaysUtilEndOfMonth(clsDate Date) {

        clsDate EndOfMonthDate;

        EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        EndOfMonthDate.Month = Date.Month;
        EndOfMonthDate.Year = Date.Year;


        return GetDiffrenceInDays(Date, EndOfMonthDate, true);

    }


    short DaysUtilEndOfMonth() {

        return DaysUtilEndOfMonth(*this);

    }


    static short DaysUtilEndOfYear(clsDate Date) {

        clsDate EndOfYearDate;

        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date.Year;


        return GetDiffrenceInDays(Date, EndOfYearDate, true);
    }


    short DaysUtilEndOfYear() {

        return DaysUtilEndOfYear(*this);

    }


    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {

        short DaysCount = 0;

        while (IsDate1BeforeThanDate2(DateFrom, DateTo)) {

            if (IsBusinessDay(DateFrom))
                DaysCount++;


            DateFrom = AddOneDay(DateFrom);
        }

        return DaysCount;
    }


    static short CalculatelVacationDays(clsDate DateFrom, clsDate DateTo) {

        return CalculateBusinessDays(DateFrom, DateTo);
    }


    static clsDate CalculatelVacationReturnDay(clsDate DateFrom, short VacationDays) {

        short WeekendCounter = 0;

        while (IsWeekEnd(DateFrom)) {

            DateFrom = AddOneDay(DateFrom);

        }

        for (short i = 1; i <= VacationDays + WeekendCounter; i++)
        {
            if (IsWeekEnd(DateFrom)) {

                WeekendCounter++;

            }

            DateFrom = AddOneDay(DateFrom);
        }

        while (IsWeekEnd(DateFrom)) {

            DateFrom = AddOneDay(DateFrom);

        }

        return DateFrom;
    }




    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {

        return (!IsDate1BeforeThanDate2(Date1, Date2) && !IsDate1EqualsDate2(Date1, Date2));

    }

    bool IsDate1AfterDate2(clsDate Date2) {

        return  IsDate1AfterDate2(*this, Date2);

    }

    enum enDateCompare {
        eBefore = -1,
        eEqual = 0,
        eAfter = 1
    };


    static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {

        if (IsDate1BeforeThanDate2(Date1, Date2))
            return enDateCompare::eBefore;

        if (IsDate1EqualsDate2(Date1, Date2))
            return enDateCompare::eEqual;


        return enDateCompare::eAfter;

    }


    enDateCompare CompareDates(clsDate Date2) {

        return CompareDates(*this, Date2);

    }


};
