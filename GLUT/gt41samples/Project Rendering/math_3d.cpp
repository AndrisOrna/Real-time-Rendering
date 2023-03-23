#include "math_3d.h"

float RandomFloat()
{
    float Max = RAND_MAX;
    return ((float)RANDOM() / Max);
}

float RandomFloatRange(float Start, float End)
{
    if (End == Start) {
        printf("Invalid random range: (%f, %f)\n", Start, End);
        exit(0);
    }

    float Delta = End - Start;

    float RandomValue = RandomFloat() * Delta + Start;

    return RandomValue;
}
