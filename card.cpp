#include "card.hpp"

card::card(int card, int pin):CardNo(card),CardPin(pin)
{
}

bool card::CardAuthentication()
{
    return false;
}