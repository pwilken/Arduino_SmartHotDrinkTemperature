/*************************************************
 * Ideal temperatures for different kind of drinks
 *************************************************/
#ifndef DRINKTEMPERAUTRES_H
#define DRINKTEMPERAUTRES_H

#define TeeLowLevel  60
#define TeeHighLevel  65

#define WaterLowLevel 6
#define WaterHighLevel 8

#define BabyDrinksHighLevel 37
#define BabyDrinksLowLevel 32 

#define RedWineHighLevel 18
#define RedWineLowLevel 12

#define BeerHighLevel 18
#define BeerLowLevel 12

#define SpecialDrinkHighLevel 42
#define SpecialDrinkLowLevel 40


typedef enum
{
    TEE,
    WATER,
    BABYDRINK,
    REDWINE,
    BEER,
    SPECIALDRINK
} drinkType;

extern int getHighTemperature(drinkType);
extern int getLowTemperature(drinkType);

#endif /* DRINKTEMPERAUTRES_H */
