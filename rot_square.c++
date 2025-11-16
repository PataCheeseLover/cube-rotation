#include <iostream>
#include <vector>
#include <cmath>
#include<thread>

using namespace std;

struct Point {
    double x, y, z;
};

Point rotateX(double A,double x,double y, double z){

    Point r;

    r.x = x;
    r.y = y*cos(A) - z*sin(A);
    r.z = y*sin(A) + z*cos(A);

    return r;
}

Point rotateY(double A, double x, double y, double z){

    Point r;

    r.x = x*cos(A) + z*sin(A);
    r.y = y;
    r.z = z*cos(A) - x*sin(A);

    return r;
}

Point rotateZ(double A, double x, double y, double z){

    Point r;

    r.x = x*cos(A) - y*sin(A);
    r.y = y*cos(A) + x*sin(A);
    r.z = z;

    return r;
}

int main(){

    const int WIDTH = 25;
    const int HEIGHT = 25;
    double angle = 0;
    double z_front = -5;
    double z_back = 5;
    double cx = 5;
    double cy = 5;
    double cz = 0;

    vector<Point> points;

    for(double i = 0; i<=10; i++){
        for(double j = 1; j<= 10; j++){
            points.push_back({i, j, z_front});
            points.push_back({i, j, z_back});
        }
    }
    for(double i = 0; i<=10; i++){
        for(double k = z_front; k<=z_back; k++){
            points.push_back({i, 10, k});
            points.push_back({i, 0, k});
        }
    }
    for (double j = 0; j<=10; j++){
        for (double k = z_front; k <= z_back; k++){
            points.push_back({0, j, k});
            points.push_back({10, j, k});
        }
    }


    while (1){

        system("clear");
        
        vector<string> grid(HEIGHT, string(WIDTH, ' '));

        for(auto& p : points){

            double x = p.x - cx;
            double y = p.y - cy;
            double z = p.z - cz;

            Point r1 = rotateX(angle, x, y, z);
            Point r2 = rotateY(angle, r1.x, r1.y, r1.z);
            Point r3 = rotateZ(angle, r2.x, r2.y, r2.z);


            double X = r3.x + cx;
            double Y = r3.y + cy;
            double Z = r3.z + cz;
            double F = 25;
            
            double xp = X*(F/(Z+F));
            double yp = Y*(F/(Z+F));
            
            int col = int(xp + WIDTH/3);
            int row = int(yp + HEIGHT/3);

            if (row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH){
                grid[row][col] = '*';
            }
        }

        for(auto& line : grid){
            cout << line << "\n";
        }


        angle += 0.05;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}