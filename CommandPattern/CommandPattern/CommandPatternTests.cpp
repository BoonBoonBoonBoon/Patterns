// CommandPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>

// Command interface
class Command
{
public:
    // Command constructor and destructor
    Command();
    ~Command();
    
    virtual void Execute() = 0;
};

class  UsePotionCommand : public Command
{
    UsePotionCommand():

    void Execute() override {std::cout << playerName << " used a "<< potionName << " potion."<< std::endl;}
};


// Class for a potion
class Potion
{
public:
    // Potion constructor and destructor
    Potion() {};
    ~Potion() {};

    // Name of the potion
    std::string potionName = "Health Potion";
    // Colour of the potion
    std::string Colour = "Grey";

    // Function to use the potion
    virtual void UsePotion() { std::cout << "You used a template potion, you feel no different"; };
};

// Player class
class Player 
{
public:
    // Potion constructor and destructor
    Player() {};
    ~Player() {};

    // Name of the player
    std::string playerName = "Balthazar";

    // The potion the player's holding
    Potion* HeldPotion = nullptr;

    // Function to drink a potion
    void DrinkPotion() { if (HeldPotion) this->HeldPotion->UsePotion(); };
};


int main()
{
    // Make a player
    Player player = Player();

    // Make a potion
    Potion potion = Potion();

    // Give the potion to the player
    player.HeldPotion = &potion;

    // Drink the potion
    player.DrinkPotion();

    return 0;
}

