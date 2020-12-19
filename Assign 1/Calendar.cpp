#include<iostream>
#include<string>
using namespace std;

bool is_leap(int year){
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int print_month_horizontally(int n_days, int start_day){
    cout<<"Mon\tTue\tWed\tThu\tFri\tSat\tSun\n";
    for(int j=0; j<start_day; j++){
            cout<<"\t";
    }
    for (int i=1; i<=n_days; i++){
        cout<<i<<"\t";
        if ((i - 7 + start_day) % 7 == 0){
            cout<<"\n";
        }
    }
    int last_day = (start_day + n_days) % 7;
    return last_day;
}

int print_month_vertically(int n_days, int start_day){
    string week[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    for (int i=0; i<7; i++){
        cout<<week[i]<<"\t";
            if (i < start_day) {
                cout<<"\t";
                int a = 7-start_day +1 + i;
                while (a <= n_days){
                    cout<<a<<"\t";
                    a = 7+a;
                }
            }
            else
            {
                int b = i - start_day + 1;
                while (b <= n_days){
                    cout<<b<<"\t";
                    b = 7+b;
                }
            }
            cout<<"\n";

    }
    int last_day = (start_day + n_days) % 7;
    return last_day;
}

int first_day(int data, int year){
    if (year >= 2020){    // since data is of 2020 (reference year) we use 2020
        int x = year - 2020;
        int counter=0;
        for (int i=2020; i<year; i++){
            if (is_leap(i)){
                counter++;
            }
        }
        int norm = x - counter;
        return (data + norm + 2*counter) % 7;
    }else if(year == 2020){
        return data;
    } else {
        int x = 2020 - year;
        int counter = 0;
        for (int i=year; i<2020; i++){
            if (is_leap(i)){
                counter++;
            }
        }
        int norm = x - counter;
        return (7 - ((data - norm - 2*counter) % 7)) % 7;
    }
}


int main(){
    int data = 2;  // 2 means wednesday which was Jan 1, 2020
    int year, feb_day=28;
    cout<<"Enter year: ";
    cin>>year;
    if (is_leap(year)){
        feb_day=29;
    }
    int first = first_day(data, year);
    cout<<"\nHORIZONTAL CALENDAR\n--------------------------";
    cout<<"\n\nJanuary\n\n";
    first = print_month_horizontally(31, first);   //this function gives the day after last date in that month
    cout<<"\n\nFebruary\n\n";
    first = print_month_horizontally(feb_day, first);
    cout<<"\n\nMarch\n\n";
    first = print_month_horizontally(31, first);
    cout<<"\n\nApril\n\n";
    first = print_month_horizontally(30, first);
    cout<<"\n\nMay\n\n";
    first = print_month_horizontally(31, first);
    cout<<"\n\nJune\n\n";
    first = print_month_horizontally(30, first);
    cout<<"\n\nJuly\n\n";
    first = print_month_horizontally(31, first);
    cout<<"\n\nAugust\n\n";
    first = print_month_horizontally(31, first);
    cout<<"\n\nSeptember\n\n";
    first = print_month_horizontally(30, first);
    cout<<"\n\nOctober\n\n";
    first = print_month_horizontally(31, first);
    cout<<"\n\nNovember\n\n";
    first = print_month_horizontally(30, first);
    cout<<"\n\nDecember\n\n";
    first = print_month_horizontally(31, first);
    cout<<"\nVERTICAL CALENDAR\n--------------------------";
    first = first_day(data, year);
    cout<<"\n\nJanuary\n\n";
    first = print_month_vertically(31, first);   //this function gives the day after last date in that month
    cout<<"\n\nFebruary\n\n";
    first = print_month_vertically(feb_day, first);
    cout<<"\n\nMarch\n\n";
    first = print_month_vertically(31, first);
    cout<<"\n\nApril\n\n";
    first = print_month_vertically(30, first);
    cout<<"\n\nMay\n\n";
    first = print_month_vertically(31, first);
    cout<<"\n\nJune\n\n";
    first = print_month_vertically(30, first);
    cout<<"\n\nJuly\n\n";
    first = print_month_vertically(31, first);
    cout<<"\n\nAugust\n\n";
    first = print_month_vertically(31, first);
    cout<<"\n\nSeptember\n\n";
    first = print_month_vertically(30, first);
    cout<<"\n\nOctober\n\n";
    first = print_month_vertically(31, first);
    cout<<"\n\nNovember\n\n";
    first = print_month_vertically(30, first);
    cout<<"\n\nDecember\n\n";
    first = print_month_vertically(31, first);

    return 0;
}
