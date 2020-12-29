#if 0
12/23 18:06 AC
三角形の面積の出し方は色々ありますが、
とりあえず外積から求めました。
AOJの誘導通りに辺の長さから出すやり方も試したのですが、
complexの使い方がよくわかってなくてエラーになってしまったので、
後でもう一度トライしてみることにしました。
#endif

#include <bits/stdc++.h>
using namespace std;
typedef complex<double> xy_t;

xy_t P[110];

int main() {
    int N = 0;
    double x, y;
    while (scanf("%lf, %lf", &x, &y) != EOF) {
        P[N++] = xy_t(x, y);
    }

    double sum = 0.0;
    for (int i = 0; i < N - 2; i++) {
        xy_t a = P[0], b = P[i + 1], c = P[i + 2];
        xy_t bo = xy_t(b.real() - a.real(), b.imag() - a.imag());
        xy_t co = xy_t(c.real() - a.real(), c.imag() - a.imag());
        sum += abs((conj(bo) * co).imag() / 2.0);
    }
    printf("%.6f\n", abs(sum));
}