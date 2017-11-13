
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;

int main(const int argc, const char* const argv[])
{
    if (argc < 4)
        cerr << "Error: Insufficient arguments; Expecting at least 3 arguments" << endl;

    else if (argc > 4)
        cerr << "Warning: Expecting three command-line arguments; received " << argc - 1 << "; ignoring extraneous arguments." << endl;

    else {
        float velocity;
        float distance;
        float maxDeceleration;
        float time;
        float deceleration;
        float v;
        float t;
        velocity = atof(argv[1]);
        distance = atof(argv[2]);
        maxDeceleration = fabs(atof(argv[3]));
        deceleration = fabs((velocity * velocity) / (2 * distance));
        time = distance * 2 / velocity;

        if (distance != 0) {
            if (velocity > 0) {
                if (distance < 0)
                    cout << "There is no possibility of collision because velocity is in the opposite direction of the object." << endl;
                else if (distance > 0) {
                    if (deceleration <= maxDeceleration) {
                        cout << "Initial car velocity: " << velocity << "m/s" << endl;
                        cout << "Distance to obstacle: " << distance << "m" << endl;
                        cout << "Minimum deceleration: " << deceleration << "m/s/s" << endl;
                        cout << "Maximum stopping time: " << time << "s" << endl;
                    }
                    else if (deceleration > maxDeceleration) {
                        v = sqrt((velocity * velocity) - (2 * maxDeceleration * distance));
                        t = fabs((velocity - v) / maxDeceleration);
                        cout << "Crash will occur in " << t << " seconds at velocity " << v << "m/s; deploying airbags." << endl;
                    }
                }
            }

            if (velocity < 0) {
                if (distance > 0)
                    cout << "There is no possibility of collision because velocity is in the opposite direction of the object." << endl;
                else if (distance < 0) {
                    if (deceleration <= maxDeceleration) {
                        cout << "Initial car velocity: " << velocity << "m/s" << endl;
                        cout << "Distance to obstacle: " << distance << "m" << endl;
                        cout << "Minimum deceleration: " << deceleration << "m/s/s" << endl;
                        cout << "Maximum stopping time: " << time << "s" << endl;
                    }
                    else if (deceleration > maxDeceleration) {
                        v = -sqrt((velocity * velocity) + (2 * maxDeceleration * distance));
                        t = fabs((velocity - v) / maxDeceleration);
                        cout << "Crash will occur in " << t << " seconds at velocity " << v << "m/s; deploying airbags." << endl;
                    }
                }
            }

            if (velocity == 0)
                cout << "There is no possibility of collision because the car is stationary." << endl;
        }

        else if (distance == 0)
            cout << "infinite deceleration is needed to avoid collision and therefore not feasible" << endl;
    }
    return 0;
}