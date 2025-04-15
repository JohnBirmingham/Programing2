#include <iostream>

struct Point {
    float x;
    float y;
};

// Function to calculate the midpoint between two points (returns a Point object)
Point calcMidpoint(const Point* p1, const Point* p2) {
    Point tempPoint{ (p1->x + p2->x) / 2,(p1->y + p2->y) / 2 };
    return tempPoint;  // Placeholder return value
}

int main() {
    // Step 1: Create two points with example coordinates
    Point a{ 1.0f, 2.0f };
    Point b{ 5.0f, 6.0f };

    Point mid = calcMidpoint(&a, &b);

    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl; // Should be (3, 4)

    return 0;
}