#include<iostream>
using namespace std;

class CVehicle
{
public:
    int max_speed;
    int speed;
    int weight;

    CVehicle(int ms, int s, int w)
    :max_speed(ms)
    ,speed(s)
    ,weight(w)
    {}

    void display()
    {
        printf("Vehicle:\nmax_speed:%d\nspeed:%d\nweight:%d\n\n", max_speed, speed, weight);
    }
};

class CBicycle: virtual public CVehicle
{
public:
    int height;

    CBicycle(int ms, int s, int w, int h)
    :CVehicle(ms, s, w)
    ,height(h)
    {}

    void display1()
    {
        printf("Bicycle:\nmax_speed:%d\nspeed:%d\nweight:%d\nheight:%d\n\n", max_speed, speed, weight, height);
    }

};

class CMotocar: virtual public CVehicle
{
public:
    int seat_num;

    CMotocar(int ms, int s, int w, int sn)
    :CVehicle(ms, s, w)
    ,seat_num(sn)
    {}

    void display2()
    {
        printf("Motocar:\nmax_speed:%d\nspeed:%d\nweight:%d\nseat_num:%d\n\n", max_speed, speed, weight, seat_num);
    }
};

class CMotocycle: public CBicycle, public CMotocar
{   
public:
    CMotocycle(int ms, int s, int w, int h, int sn)
    :CVehicle(ms, s, w)
    ,CBicycle(ms, s, w, h)
    ,CMotocar(ms, s, w, sn)
    {}
    void display3()
    {
        printf("Motocycle:\nmax_speed:%d\nspeed:%d\nweight:%d\nheight:%d\nseat_num:%d\n\n", max_speed, speed, weight, height, seat_num);
    }
};

int main()
{
    int ms, s, w, h, sn;
    cin >> ms >> s >> w >> h >> sn;

    CVehicle c1(ms, s, w);
    CBicycle c2(ms, s, w, h);
    CMotocar c3(ms, s, w, sn);
    CMotocycle c4(ms, s, w, h, sn);

    c1.display();
    c2.display1();
    c3.display2();
    c4.display3();

    return 0;
}