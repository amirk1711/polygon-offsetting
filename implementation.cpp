#include <bits/stdc++.h>
using namespace std;

pair<double, double> normalize(double x, double y){
    pair<double, double> p;
    double d = sqrt(x*x + y*y);
    p.first = x/d;
    p.second = y/d;
    return p;
}

vector<vector<double>> inflate(vector<vector<double>> points, int d){
    vector<vector<double>> ans;
    int n = points.size();
    for(int i = 0; i < n; i++){
        double next = (i+1)%n, prev = (i+n-1)%n;

        pair<double, double>p;

        double vnX = points[next][0] - points[i][0];
        double vnY = points[next][1] - points[i][1];
        p = normalize(vnX, vnY);
        double nnnX = p.second, nnnY = -1*p.first;

        double vpX = points[i][0] - points[prev][0];
        double vpY = points[i][1] - points[prev][1];
        p = normalize(vpX, vpY);
        double npnX = p.second, npnY = -1*p.first;

        double bisectorX = nnnX + npnX, bisectorY = nnnY + npnY;
        p = normalize(bisectorX, bisectorY);

        double l = (sqrt(2)*d)/sqrt(1 + nnnX*npnX + nnnY*npnY);

        vector<double> temp;
        temp.push_back(points[i][0] + l*p.first);
        temp.push_back(points[i][1] + l*p.second);
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<vector<double>> points;
    cout << "Enter no of points in polygon: ";
    int n; cin >> n;
    cout << "Enter co-ordinates of points(x, y):\n";
    for(int i = 0; i < n; i++){
        double x, y; cin >> x >> y;
        vector<double> temp;
        temp.push_back(x);
        temp.push_back(y);
        points.push_back(temp);
    }
    cout << "Enter length by which you want to inflate the polygon: ";
    int d; cin >> d;

    cout << "New points are : \n";
    vector<vector<double>> inflated_points = inflate(points, d);
    for(int i = 0; i < n; i++){
        cout << inflated_points[i][0] << " " << inflated_points[i][1] << endl;
    }
    return 0;
}