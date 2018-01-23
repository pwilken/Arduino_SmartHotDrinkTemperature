#include "DrinkTemperatures.h"

int getHighTemperature(drinkType dt)
{
  switch(dt) 
  {
    case TEE:
      return TeeHighLevel;
      break;
    case WATER:
      return WaterHighLevel;
      break;
    case BABYDRINK:
      return BabyDrinksHighLevel;
      break;
    case REDWINE:
      return RedWineHighLevel;
      break;
    case BEER:
      return BeerHighLevel;
      break;
    case SPECIALDRINK:
      return SpecialDrinkHighLevel;
      break;
    default: return 0;
  }
}

int getLowTemperature(drinkType dt)
{
  switch(dt) 
  {
    case TEE:
      return TeeLowLevel;
      break;
    case WATER:
      return WaterLowLevel;
      break;
    case BABYDRINK:
      return BabyDrinksLowLevel;
      break;
    case REDWINE:
      return RedWineLowLevel;
      break;
    case BEER:
      return BeerLowLevel;
      break;
    case SPECIALDRINK:
      return SpecialDrinkLowLevel;
      break;
    default: return 0;
  }
}

