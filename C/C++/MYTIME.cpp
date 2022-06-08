#include <iostream>
#include <iomanip>
using namespace std;

/* 你提交的代码将被嵌在这里 */

/*开始日期 2022/03/23
完成日期 2022/04/27
备注:呜呜呜终于做完了
*/

class MYTIME
{
    public:
        /*构造析构函数*/
        MYTIME();
        MYTIME(int h,int m=0,int s=0);
        MYTIME(const MYTIME &time);
        ~MYTIME();


        /*对象数据设置读取函数部分*/
        void Set(int h=0,int m=0,int s=0);
        void Hour(int h);
        int Hour();
        int Hour() const;
        void Minute(int m);
        int Minute();
        int Minute() const;
        void Second(int s);
        int Second();
        int Second() const;
        void Get(int &h,int &m,int &s);
        void Get(int &h,int &m,int &s) const;


        /*时刻转秒 秒转时刻函数声明部分*/
        void TotalSecond(int totalSecond);
        int TotalSecond();
        int TotalSecond()const;


        /*运算符重载声明部分*/
        MYTIME& operator=(const MYTIME &time);
        MYTIME& operator+(int augend);
        MYTIME operator+(int augend) const;
        MYTIME operator-(int minuend) const;
        int operator-(const MYTIME &time);
        int operator-(const MYTIME &time)const;
        MYTIME& operator+=(int s);
        MYTIME& operator-=(int s);
        MYTIME& operator--();
        MYTIME& operator++();
        MYTIME operator++(int);
        MYTIME operator--(int);
        bool operator<(const MYTIME &time)const;
        bool operator>(const MYTIME &time)const;
        bool operator<=(const MYTIME &time)const;
        bool operator>=(const MYTIME &time)const;
        bool operator==(const MYTIME &time)const;
        bool operator!=(const MYTIME &time)const;
        operator int();
        operator int()const;
        void operator=(int t);


        /*输入格式判断函数声明部分*/
        static int IsValidHour(int h);
        static int IsValidMinute(int m);
        static int IsValidSecond(int s);
        static int IsValid(int h,int m,int s);


        /*控制AM PM输出函数*/
        static void FlagOn();
        static void FlagOff();


        /*输入输出控制符重载部分*/
        friend ostream& operator<<(ostream &os,const MYTIME &time);
        friend istream& operator>>(istream &is,MYTIME &time);


        /*静态成员数据声明*/
        static const int hoursPerDay;
        static const int minutesPerHour;
        static const int secondsPerMinute;
        static const int secondsPerHour;
        static const int secondsPerDay;


    private:
        int hour, minute, second;
        static bool flag;
};
bool MYTIME::flag=false;
const int MYTIME::hoursPerDay=24;
const int MYTIME::minutesPerHour=60;
const int MYTIME::secondsPerMinute=60;
const int MYTIME::secondsPerHour=3600;
const int MYTIME::secondsPerDay=86400;

MYTIME::MYTIME(){
    hour=0;
    minute=0;
    second=0;
    cout<<"Create ";
    cout<<setfill('0')<<setw(2);
    cout<<hour<<":";
    cout<<setw(2)<<minute<<":";
    cout<<setw(2)<<second<<endl;
}

MYTIME::MYTIME(int h,int m,int s){
    if((IsValidHour(h)==0)||(IsValidMinute(m)==0)||(IsValidSecond(s)==0)){
        h=0;
        m=0;
        s=0;
    }
    hour=h;
    minute=m;
    second=s;
    hour=hour%24;
    cout<<"Create ";
    cout<<setfill('0')<<setw(2);
    cout<<hour<<":";
    cout<<setw(2)<<minute<<":";
    cout<<setw(2)<<second<<endl;
}

MYTIME::MYTIME(const MYTIME &time){
    hour=time.hour;
    minute=time.minute;
    second=time.second;
    cout<<"Clone ";
    cout<<setw(2)<<hour<<":";
    cout<<setw(2)<<minute<<":";
    cout<<setw(2)<<second<<endl;
}

MYTIME::~MYTIME(){
    cout<<"Destroy ";
    cout<<setw(2)<<hour<<":";
    cout<<setw(2)<<minute<<":";
    cout<<setw(2)<<second<<endl;
}

void MYTIME::Set(int h,int m,int s){
    if((IsValidHour(h)==1)&&(IsValidMinute(m)==1)&&(IsValidSecond(s)==1)){
        hour=h;
        minute=m;
        second=s;
    }
}

void MYTIME::Hour(int h){
    if(IsValidHour(h))
        hour=h;
}

int MYTIME::Hour(){
    return hour;
}

int MYTIME::Hour() const{
    return hour;
}

void MYTIME::Minute(int m){
    if(IsValidMinute(m))
        minute=m;
}

int MYTIME::Minute(){
    return minute;
}

int MYTIME::Minute() const{
    return minute;
}

void MYTIME::Second(int s){
    if(IsValidSecond(s))
        second=s;
}

int MYTIME::Second(){
    return second;
}

int MYTIME::Second() const{
    return second;
}

void MYTIME::Get(int &h,int &m,int &s){
    h=hour;
    m=minute;
    s=second;
}

void MYTIME::Get(int &h,int &m,int &s)const{
    h=hour;
    m=minute;
    s=second;
}

void MYTIME::TotalSecond(int totalSecond){
    int t = (86400 + totalSecond % 86400) % 86400;
    second = t % 60;
    t /= 60;
    minute = t % 60;
    hour = t / 60;
}

int MYTIME::TotalSecond(){
    return hour*3600+minute*60+second;
}

int MYTIME::TotalSecond()const{
    return hour*3600+minute*60+second;
}

MYTIME& MYTIME::operator=(const MYTIME &time){
    hour=time.hour;
    minute=time.minute;
    second=time.second;
    cout<<"Assign ";
    cout<<setw(2)<<hour<<":";
    cout<<setw(2)<<minute<<":";
    cout<<setw(2)<<second<<endl;
    return *this;
}

MYTIME& MYTIME::operator+(int augend){
    TotalSecond(TotalSecond()+augend% 86400);
    return *this;
}

MYTIME MYTIME::operator+(int augend) const{
    MYTIME result;
    result.TotalSecond(TotalSecond() + augend % 86400);
    return result;
}

MYTIME MYTIME::operator-(int minuend) const{
    MYTIME time;
    time.TotalSecond(TotalSecond()-minuend% 86400);
    return time;
}

int MYTIME::operator-(const MYTIME &time){
    return TotalSecond()-time.TotalSecond();
}

int MYTIME::operator-(const MYTIME &time)const{
    return TotalSecond()-time.TotalSecond();
}

MYTIME& MYTIME::operator+=(int s){
    TotalSecond(TotalSecond()+s);
    return *this;
}

MYTIME& MYTIME::operator-=(int s){
    TotalSecond(TotalSecond()-s);
    return *this;
}

MYTIME& MYTIME::operator--(){
    TotalSecond(TotalSecond()-1);
    return *this;
}

MYTIME& MYTIME::operator++(){
    TotalSecond(TotalSecond()+1);
    return *this;
}

MYTIME MYTIME::operator++(int){
    MYTIME temp(*this);
    TotalSecond(TotalSecond()+1);
    return temp;
}

MYTIME MYTIME::operator--(int){
    MYTIME temp(*this);
    TotalSecond(TotalSecond()-1);
    return temp;
}

bool MYTIME::operator<(const MYTIME &time)const{
    return TotalSecond()<time.TotalSecond();
}

bool MYTIME::operator>(const MYTIME &time)const{
    return TotalSecond()>time.TotalSecond();
}

bool MYTIME::operator<=(const MYTIME &time)const{
    return TotalSecond()<=time.TotalSecond();
}

bool MYTIME::operator>=(const MYTIME &time)const{
    return TotalSecond()>=time.TotalSecond();
}

bool MYTIME::operator==(const MYTIME &time)const{
    return TotalSecond()==time.TotalSecond();
}

bool MYTIME::operator!=(const MYTIME &time)const{
    return TotalSecond()!=time.TotalSecond();
}

MYTIME::operator int(){
    return hour;
}

MYTIME::operator int()const{
    return hour;
}

void MYTIME::operator=(int t){
    hour=t/3600;
    minute=(t-hour*3600)/60;
    second=t-hour*3600-minute*60;
}

//static int MYTIME::IsValidHour(int h)错误，声明时用了static，在外部定义就不用使用static
int MYTIME::IsValidHour(int h){
    if(h>=hoursPerDay||h<0)
        return 0;
    else
        return 1;
}

int MYTIME::IsValidMinute(int m){
    if(m>=minutesPerHour||m<0)
        return 0;
    else
        return 1;
}

int MYTIME::IsValidSecond(int s){
    if(s>=secondsPerMinute||s<0)
        return 0;
    else
        return 1;
}

int MYTIME::IsValid(int h,int m,int s){
    if(IsValidHour(h)&&IsValidMinute(m)&&IsValidSecond(s))
        return 1;
    else
        return 0;
}

void MYTIME::FlagOn(){
    flag=true;
}

void MYTIME::FlagOff(){
    flag=false;
}

ostream& operator<<(ostream &os,const MYTIME &time){
    os<<setw(2)<<time.hour<<":";
    os<<setw(2)<<time.minute<<":";
    os<<setw(2)<<time.second;
    if(MYTIME::flag){
        if(time.hour<12)
            os<<" am";
        else
            os<<" pm";
    }
    return os;
}

istream& operator>>(istream &is,MYTIME &time){
    int h,m,s;
    is>>h;
    getchar();
    is>>m;
    getchar();
    is>>s;
    if(MYTIME::IsValid(h,m,s)){
        time.hour=h;
        time.minute=m;
        time.second=s;
        return is;
    }
    else
        return is;
}

/* 你提交的代码将被嵌在这里 */

void Test1()
{
    int a;
    MYTIME b;
    cin >> a;
    b = MYTIME(a);
    cout << b << endl;
}

void Test2()
{
    int h, m, s, b;
    cin >> h >> m >> s;
    const MYTIME a(h, m, s);
    b = int(a);
    cout << b << endl;
}

int main()
{
    Test1();
    Test2();
    return 0;
}
