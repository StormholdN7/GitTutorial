#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;

class InGameCurrency {
private:
    int gold = 0;
    int silver = 0;
    int copper = 0;
    int commendations = 0;
    int crystals = 0;
    string playerCredential = "- 1";

public:
    //GET/SET

    void setCopper(int copper);
    int getCopper() const;

    void setSilver(int silver);
    int getSilver() const;

    void setGold(int gold);
    int getGold() const;

    void setCommendations(int commendations);
    int getCommendations() const;

    void setCrystals(int crystals);
    int getCrystals() const;

    void setPlayerCredential(string playerCredential);
    string getPlayerCredential() const;
    
    //GET/SET End

    //Constructor
    InGameCurrency(int copper, int silver = 0, int gold = 0, int commendations = 0, int crystals = 0, string playerCredential = "-1");

    InGameCurrency();
    //END Constructor

    void recalculate()
    {
        if (copper < 0)
        {
            int SC = (copper * -1) % 100 + 1;
            silver -= SC;
            copper += SC * 100;
        }
        if (copper > 100)
        {
            silver += copper / 100;
            copper = copper % 100;
        }

        if (silver < 0)
        {
            int SC = (silver * -1) % 100 + 1;
            gold -= SC;
            silver += SC * 100;
        }
        if (silver > 100)
        {
            gold += silver / 100;
            silver = silver % 100;
        }
    }

    void addCoins(int sum)
    {
        copper += sum;
        recalculate();
    }

    void commend()
    {
        commendations++;
    }

    void spendCommendations(int coms)
    {
        if (coms > 0)
            commendations -= coms;
    }

    void buyCrystal()
    {
        if (getPlayerCredential() == "")
        {
            printf("Player must have confirmed number to complete the purchase");
            return;
        }
        if (gold >= 10)
        {
            gold -= 10;
            crystals++;
        }
    }

    void assignPlayer(string PhoneNumber)
    {
        playerCredential = PhoneNumber;
    }

};
