#include "../inc/fdf.h"

int        geo_mode_color(int z)
{
    if (z <= -10)
        return (MIDNIGHT_BLUE);
    if (-10 < z && z < 0)
        return (AQUA_MARINE);
    if (z == 0)
        return (SPRING_GREEN);
    if (0 < z && z <= 10)
        return (DARK_GREEN);
    if (10 < z && z <= 20)
        return (SADDLEBROWN);
    if (20 < z && z <= 30)
        return (CORAL);
    if (30 < z)
        return (geo_mode_color2(z));
    return (WHITE);
}

int        geo_mode_color2(int z)
{
    if (30 < z && z <= 40)
        return (GOLDEN_ROD);
    if (40 < z && z <= 50)
        return (BEIGE);
    if (50 < z && z <= 100)
        return (WHITE_SMOKE);
    if (100 < z)
        return (WHITE);
    return (WHITE);
}