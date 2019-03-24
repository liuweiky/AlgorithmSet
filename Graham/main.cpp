/**
Graham Scan

N = 6

Points = [
1 1
3 6
4 2
5 6
7 1
4 -2
]

6
1 1
3 6
4 2
5 6
7 1
4 -2

*/

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1024

using namespace std;

struct Point
{
    double x, y;
    Point operator- (const Point& rhs) const
    {
        Point p;
        p.x = x - rhs.x;
        p.y = y - rhs.y;
        return p;
    }
};

int N;
vector<Point> pts;
Point ans[MAX_N];
int ptr = 0;

bool cmp(Point& p1, Point& p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

double det(Point p1, Point p2, Point p3, Point p4)
{
    Point vec1 = p1 - p2;
    Point vec2 = p3 - p4;
    return vec1.x * vec2.y - vec2.x * vec1.y;
}

void Graham()
{
    sort(pts.begin(), pts.end(), cmp);
    /// up
    for (int i = 0; i < N; i++)
    {
        Point p = pts[i];

        while (ptr >= 2 && det(ans[ptr - 2], ans[ptr - 1], ans[ptr - 1], p) >= 0)
            ptr--;
        ans[ptr++] = p;
    }
    int t = ptr;
    /// down
    for (int i = N - 2; i >= 0; i--)
    {
        Point p = pts[i];

        while (ptr >= t + 1 && det(ans[ptr - 2], ans[ptr - 1], ans[ptr - 1], p) >= 0)
            ptr--;
        ans[ptr++] = p;
    }

    ptr--;

}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        Point p;
        scanf("%lf %lf", &p.x, &p.y);
        pts.push_back(p);
    }

    Graham();

    /*for (int i = 0; i < N; i++)
        printf("%f %f\n", pts[i].x, pts[i].y);*/

    for (int i = 0; i < ptr; i++)
        printf("(%.1f, %.1f)\n", ans[i].x, ans[i].y);

    return 0;
}
