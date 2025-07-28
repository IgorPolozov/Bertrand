#include <iostream>
#include <cmath>
#include<chrono>
#include <random>
#include <utility>

constexpr int nmin=1;

constexpr int nmax=1000000;

constexpr double Pi=2*std::asin(1);

constexpr double chord=2*std::cos(Pi/6);

std::pair<int, int> rnd_pair_1_gen()
{
    const int m_seed1 {static_cast<int>(std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    static std::mt19937 m_rng1 {m_seed1};

    std::uniform_int_distribution<> rng1{int(nmin), int(nmax)};
    return {rng1(m_rng1), rng1(m_rng1)};
}

double probability1()
{
    double alpha1, alpha2, x1, x2, Dx, y1, y2, Dy, len;
    int good_event_cnt(0),  all_event_cnt(0);

    for(int n=nmin; n<nmax; ++n)
    {
        auto pr= rnd_pair_1_gen();
        alpha1=double(pr.first)*2*Pi/nmax;
        alpha2=double(pr.second)*2*Pi/nmax;

        x1=cos(alpha1);
        x2=cos(alpha2);
        Dx=x2-x1;

        y1=sin(alpha1);
        y2=sin(alpha2);
        Dy=y2-y1;

        len= sqrt(Dx*Dx+Dy*Dy);

        if(len>chord)++good_event_cnt;
        ++all_event_cnt;
    }

    return double(good_event_cnt)/all_event_cnt;

}


int main()
{

     std::cout << "Probability1=" << probability1() ;

    return 0;
}
