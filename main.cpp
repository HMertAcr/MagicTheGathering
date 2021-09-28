#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

class Card {
protected:
    std::string Name;
public:

    Card() : Name("Unnamed") {}

    Card(std::string N) : Name(N) {}

    Card(const Card &c) : Name(c.Name) {
    }

    ~Card() {}
    std::string giveCardName(){
        return Name;
    }
    virtual char giveCardType(){
        return 'B';
    }
    virtual char getCardColor(){
        return 'N';
    }
    virtual int getAttackDamage(){
        return 0;
    }
    virtual int getCardHP(){
        return 0;
    }
    virtual int getMaxCardHP(){
        return 0;
    }
    virtual char getCOMI(){
        return 0;
    }
    virtual std::string getCardDescription(){
        return 0;
    }
    virtual int getBlackManaCost(){
        return 0;
    }
    virtual int getWhiteManaCost(){
        return 0;
    }
    virtual int getRedManaCost(){
        return 0;
    }
    virtual int getGreenManaCost(){
        return 0;
    }
    virtual int getBlueManaCost(){
        return 0;
    }
    virtual int getColorlessManaCost(){
        return 0;
    }
    virtual int getEnchantmentNumber(){
        return 0;
    }
    virtual bool getIsTapped(){
        return 0;
    }
    virtual bool getCanTrample(){
        return 0;
    }
    virtual bool getCanFirstStrike(){
        return 0;
    }
    virtual void changeHealth(int hpIndex){}

    virtual void changeMaxHP(int MaxHPIndex){}

    virtual void changeAttack(int AttackIndex){}

    virtual void resetHP(){}

    virtual void resetHPUntap(){}

    virtual void tap(){}

    virtual void addTrample(){}

    virtual void removeTrample(){}

    virtual void removeFirstStrike() {}

    virtual void effectByRage(){}

    virtual void uneffectByRage(){}

    virtual bool isEffectedbyRage(){
        return 0;
    }

    virtual void effectByHolyWar(){}

    virtual void uneffectByHolyWar(){}

    virtual bool isEffectedbyHolyWar(){
        return 0;
    }

    virtual void effectByHolyLight(){}

    virtual void uneffectByHolyLight(){}

    virtual bool isEffectedbyHolyLight(){
        return 0;
    }

    virtual void effectByUnholyWar(){}

    virtual void uneffectByUnholyWar(){}

    virtual bool isEffectedbyUnhholyWar(){
        return 0;
    }

    virtual void effectByRestrain(){}

    virtual void uneffectByRestrain(){}

    virtual bool isEffectedbyRestrain(){
        return 0;
    }

    virtual void effectBySlow(){}

    virtual void uneffectBySlow(){}

    virtual bool isEffectedbySlow(){
        return 0;
    }
};

class LandCard:public Card{
public:
    char COMI; //color of mana increase
public:

    LandCard():Card(),COMI(0){}

    LandCard(std::string n, char COMI):Card(n),COMI(COMI){}

    LandCard(const LandCard &CL):Card(CL.Name),COMI(CL.COMI){}

    ~LandCard(){}

    char giveCardType(){
        return 'L';
    }

    char getCOMI(){
        return COMI;
    }

};

class CreatureCard:public Card{

protected:

    int maxHP;
    int cardHp;
    int cardAttackDamage;
    char color;
    int BlackManaCost;
    int WhiteManaCost;
    int RedManaCost;
    int GreenManaCost;
    int BlueManaCost;
    int ColorlessManaCost;
    bool canFirstStrike;
    bool canTrample;
    bool isTapped;
    bool affectedByRage;
    bool affectedByHolyWar;
    bool affectedByHolyLight;
    bool affectedByUnholyWar;
    bool affectedByRestrain;
    bool affectedBySlow;

public:

    CreatureCard():Card(),maxHP(0),cardHp(0),cardAttackDamage(0),color('N'),BlackManaCost(0),WhiteManaCost(0),RedManaCost(0),GreenManaCost(0),BlueManaCost(0),ColorlessManaCost(0),
                   canFirstStrike(false),canTrample(false),isTapped(true),affectedByRage(false),affectedByHolyWar(false),affectedByHolyLight(false),affectedByUnholyWar(false),affectedByRestrain(false),
                   affectedBySlow(false){}

    CreatureCard(std::string n,int hp,int attack,char color,int BlackMC,int WhiteMC,int RedMC,int GreenMC,int BlueMC,int ColorlessMC,bool FirstStrike, bool Trample):
            Card(n),maxHP(hp),cardHp(hp),cardAttackDamage(attack),color(color),BlackManaCost(BlackMC),WhiteManaCost(WhiteMC),RedManaCost(RedMC),GreenManaCost(GreenMC),BlueManaCost(BlueMC),
            ColorlessManaCost(ColorlessMC),canFirstStrike(FirstStrike),canTrample(Trample),isTapped(true),affectedByRage(false),affectedByHolyWar(false),affectedByHolyLight(false),
            affectedByUnholyWar(false),affectedByRestrain(false),affectedBySlow(0){}

    CreatureCard(const CreatureCard &CC):Card(CC.Name),maxHP(0),cardHp(CC.cardHp),cardAttackDamage(CC.cardAttackDamage),color(CC.color),BlackManaCost(CC.BlackManaCost),WhiteManaCost(CC.WhiteManaCost),
                                         RedManaCost(CC.RedManaCost),GreenManaCost(CC.GreenManaCost),BlueManaCost(CC.BlueManaCost),ColorlessManaCost(CC.ColorlessManaCost),canFirstStrike(CC.canFirstStrike),canTrample(CC.canTrample),isTapped(CC.canTrample),
                                         affectedByRage(CC.affectedByRage),affectedByHolyWar(CC.affectedByHolyWar),affectedByHolyLight(CC.affectedByHolyLight),affectedByUnholyWar(CC.affectedByUnholyWar),affectedByRestrain(CC.affectedByRestrain),affectedBySlow(CC.affectedBySlow){}

    ~CreatureCard()= default;

    void resetHPUntap(){
        if(cardHp>0){
            cardHp=maxHP;
            isTapped=false;
        }
    }

    void resetHP(){
        cardHp=maxHP;
    }

    char giveCardType(){
        return 'C';
    }
    char getCardColor(){
        return color;
    }
    int getBlackManaCost(){
        return BlackManaCost;
    }

    int getWhiteManaCost(){
        return WhiteManaCost;
    }

    int getRedManaCost(){
        return RedManaCost;
    }

    int getGreenManaCost(){
        return GreenManaCost;
    }

    int getBlueManaCost(){
        return BlueManaCost;
    }
    int getColorlessManaCost(){
        return ColorlessManaCost;
    }
    int getAttackDamage(){
        return cardAttackDamage;
    }
    int getCardHP(){
        return cardHp;
    }
    int getMaxCardHP(){
        return maxHP;
    }
    bool getIsTapped(){
        return isTapped;
    }
    bool getCanTrample(){
        return canTrample;
    }
    bool getCanFirstStrike(){
        return canFirstStrike;
    }
    void changeHealth(int hpIndex){
        cardHp+=hpIndex;
    }
    void changeMaxHP(int MaxHPIndex){
        maxHP+=MaxHPIndex;
    }
    void changeAttack(int AttackIndex){
        cardAttackDamage+=AttackIndex;
    }
    void tap(){
        isTapped= true;
    }
    void addTrample(){
        canTrample= true;
    }
    void removeTrample(){
        canTrample= false;
    }
    void removeFirstStrike(){
        canFirstStrike= false;
    }
    void effectByRage(){
        canTrample= true;
        affectedByRage=true;
    }

    void uneffectByRage(){
        canTrample= false;
        affectedByRage=false;
    }

    bool isEffectedbyRage(){
        return affectedByRage;
    }

    void effectByHolyWar(){
        maxHP++;
        cardHp++;
        cardAttackDamage++;
        affectedByHolyWar= true;
    }

    void uneffectByHolyWar(){
        if(cardHp==maxHP){
            maxHP--;
            cardHp--;
        }else{
            maxHP--;
        }
        cardAttackDamage--;
        affectedByHolyWar= false;
    }

    bool isEffectedbyHolyWar(){
        return affectedByHolyWar;
    }

    void effectByHolyLight(){
        maxHP--;
        cardHp--;
        cardAttackDamage--;
        affectedByHolyLight= true;

    }

    void uneffectByHolyLight(){
        maxHP++;
        cardHp++;
        cardAttackDamage++;
        affectedByHolyLight= false;
    }

    bool isEffectedbyHolyLight(){
        return affectedByHolyLight;
    }

    void effectByUnholyWar(){
        cardAttackDamage+=2;
        affectedByHolyLight= true;

    }

    void uneffectByUnholyWar(){
        cardAttackDamage-=2;
        affectedByHolyLight= false;
    }

    bool isEffectedbyUnhholyWar(){
        return affectedByUnholyWar;
    }

    void effectByRestrain(){
        canTrample= false;
        affectedByRestrain= true;
    }

    void uneffectByRestrain(){
        canTrample= true;
        affectedByRestrain= false;
    }

    bool isEffectedbyRestrain(){
        return affectedByRestrain;
    }
};


class SorceryCard:public Card{
protected:
    char color;
    int BlackManaCost;
    int WhiteManaCost;
    int RedManaCost;
    int GreenManaCost;
    int BlueManaCost;
    int ColorlessManaCost;
    std::string effectExplanation;
public:

    SorceryCard():color('N'),BlackManaCost(0),WhiteManaCost(0),RedManaCost(0),GreenManaCost(0),BlueManaCost(0),ColorlessManaCost(0),effectExplanation("Empty"){}

    SorceryCard(std::string Name,char color,int BlackMC,int WhiteMC,int RedMC,int GreenMC,int BlueMC,int ColorlessMC,std::string effectExp):Card(Name),color(color),BlackManaCost(BlackMC),WhiteManaCost(WhiteMC),
                                                                                                                                            RedManaCost(RedMC),GreenManaCost(GreenMC),BlueManaCost(BlueMC),ColorlessManaCost(ColorlessMC),effectExplanation(effectExp){}

    SorceryCard(const SorceryCard &SC):Card(SC.Name),color(SC.color),BlackManaCost(SC.BlackManaCost),WhiteManaCost(SC.WhiteManaCost),RedManaCost(SC.RedManaCost),
                                       GreenManaCost(SC.GreenManaCost),BlueManaCost(SC.BlueManaCost),ColorlessManaCost(SC.ColorlessManaCost),effectExplanation(SC.effectExplanation){}


    ~SorceryCard()= default;


    char giveCardType(){
        return 'S';
    }
    char getCardColor(){
        return color;
    }
    std::string getCardDescription(){
        return effectExplanation;
    }

    int getBlackManaCost(){
        return BlackManaCost;
    }

    int getWhiteManaCost(){
        return WhiteManaCost;
    }

    int getRedManaCost(){
        return RedManaCost;
    }

    int getGreenManaCost(){
        return GreenManaCost;
    }

    int getBlueManaCost(){
        return BlueManaCost;
    }
    int getColorlessManaCost(){
        return ColorlessManaCost;
    }



};

class EnchantmentCard:public Card{
protected:
    char color;
    int BlackManaCost;
    int WhiteManaCost;
    int RedManaCost;
    int GreenManaCost;
    int BlueManaCost;
    int ColorlessManaCost;
    int EnchantmentNumber;
    std::string effectExplanation;
public:
    EnchantmentCard():color('N'),BlackManaCost(0),WhiteManaCost(0),RedManaCost(0),GreenManaCost(0),BlueManaCost(0),ColorlessManaCost(0),EnchantmentNumber(0),effectExplanation("Empty"){}

    EnchantmentCard(std::string Name,char color,int BlackMC,int WhiteMC,int RedMC,int GreenMC,int BlueMC,int ColorlessMC,int EnchantmentN,std::string effectExp):Card(Name),color(color),BlackManaCost(BlackMC),WhiteManaCost(WhiteMC),
                                                                                                                                                                 RedManaCost(RedMC),GreenManaCost(GreenMC),BlueManaCost(BlueMC),ColorlessManaCost(ColorlessMC),EnchantmentNumber(EnchantmentN),effectExplanation(effectExp){}

    EnchantmentCard(const EnchantmentCard &EC):Card(EC.Name),color(EC.color),BlackManaCost(EC.BlackManaCost),WhiteManaCost(EC.WhiteManaCost),RedManaCost(EC.RedManaCost),
                                               GreenManaCost(EC.GreenManaCost),BlueManaCost(EC.BlueManaCost),ColorlessManaCost(EC.ColorlessManaCost),EnchantmentNumber(EC.EnchantmentNumber),effectExplanation(EC.effectExplanation){}

    ~EnchantmentCard()= default;

    char giveCardType(){
        return 'E';
    }
    char getCardColor(){
        return color;
    }
    std::string getCardDescription(){
        return effectExplanation;
    }

    int getBlackManaCost(){
        return BlackManaCost;
    }

    int getWhiteManaCost(){
        return WhiteManaCost;
    }

    int getRedManaCost(){
        return RedManaCost;
    }

    int getGreenManaCost(){
        return GreenManaCost;
    }

    int getBlueManaCost(){
        return BlueManaCost;
    }
    int getColorlessManaCost(){
        return ColorlessManaCost;
    }
    int getEnchantmentNumber(){
        return EnchantmentNumber;
    }
};

class player {
protected:

    std::string playerName;
    int HP;
    int MaxBlackMana;
    int MaxWhiteMana;
    int MaxRedMana;
    int MaxGreenMana;
    int MaxBlueMana;
    int BlackMana;
    int WhiteMana;
    int RedMana;
    int GreenMana;
    int BlueMana;
    bool playedLandCard;

    std::vector<Card*> Library;
    std::vector<Card*> Hand;
    std::vector<Card*> InPlay;
    std::vector<Card*> Discard;
    std::vector<Card*> Fighting;

public:

    player():playerName("Null"),HP(15),BlackMana(0),WhiteMana(0),RedMana(0),GreenMana(0),BlueMana(0),MaxBlackMana(0),MaxWhiteMana(0),MaxRedMana(0),MaxGreenMana(0),MaxBlueMana(0),playedLandCard(false){

        Library.reserve(30);
        Hand.reserve(7);
        InPlay.reserve(10);
        Discard.reserve(30);
        Fighting.reserve(7);

    }

    player(std::string name):playerName(name),HP(15),BlackMana(0),WhiteMana(0),RedMana(0),GreenMana(0),BlueMana(0),MaxBlackMana(0),MaxWhiteMana(0),MaxRedMana(0),MaxGreenMana(0),MaxBlueMana(0),playedLandCard(false){

        Library.reserve(30);
        Hand.reserve(7);
        InPlay.reserve(10);
        Discard.reserve(30);
        Fighting.reserve(7);


    }

    player(const player &P):playerName(P.playerName),HP(P.HP),MaxBlackMana(P.MaxBlackMana),MaxWhiteMana(P.MaxWhiteMana),MaxRedMana(P.MaxRedMana),MaxGreenMana(P.MaxGreenMana),
                            MaxBlueMana(P.MaxBlueMana),BlackMana(P.BlackMana),WhiteMana(P.WhiteMana),RedMana(P.RedMana),GreenMana(P.GreenMana),BlueMana(P.BlueMana),Library(P.Library),Hand(P.Hand),
                            InPlay(P.InPlay),Discard(P.Discard),Fighting(P.Fighting){}

    ~player()= default;

    int getHP(){
        return HP;
    }
    void changeHP(int hpIndex ){
        HP+=hpIndex;
    }
    void destroyLand(char COMD){
        if(COMD=='W'){
            MaxWhiteMana--;
            if(WhiteMana!=0){
                WhiteMana--;
            }
        }
        if(COMD=='B'){
            MaxBlackMana--;
            if(BlackMana!=0){
                BlackMana--;
            }
        }
        if(COMD=='R'){
            MaxRedMana--;
            if(RedMana!=0){
                RedMana--;
            }
        }
        if(COMD=='G'){
            MaxGreenMana--;
            if(GreenMana!=0){
                GreenMana--;
            }
        }
        if(COMD=='L'){
            MaxBlueMana--;
            if(BlueMana!=0){
                BlueMana--;
            }
        }
    }
    std::string getName(){
        return playerName;
    }
    int getLibrarySize(){
        return Library.size();
    }
    int getHandSize(){
        return Hand.size();
    }
    int getDiscardSize(){
        return Discard.size();
    }
    int getInplaySize(){
        return InPlay.size();
    }
    int getFightingSize(){
        return Fighting.size();
    }
    Card* getInLibrary(int i){
        return Library.at(i);
    }
    Card* getInHand(int i){
        return Hand.at(i);
    }
    Card* getCardInDiscard(int i){
        return Discard.at(i);
    }
    Card* getCardInplay(int i){
        return InPlay.at(i);
    }
    Card* getFighter(int i){
        return Fighting.at(i);
    }
    void addInplay(int i,Card*c){
        InPlay.insert(InPlay.begin()+i,c);
    }
    void eraseInplay(int i){
        InPlay.erase(InPlay.begin()+i);
    }
    void clearFighting(){
        Fighting.clear();
    }
    void  makeFirstInFighting(int cardPlace){
        Fighting.insert(Fighting.begin(),Fighting.at(cardPlace));
        Fighting.erase(Fighting.begin()+cardPlace);
    }
    bool checkForCreature(){
        bool temp=false;
        for(int i=0;i<InPlay.size();i++){
            if(InPlay.at(i)->giveCardType()=='C'){
                temp= true;
            }
        }
        return temp;
    }
    bool checkForEnchantment(){
        bool temp=false;
        for(int i=0;i<InPlay.size();i++){
            if(InPlay.at(i)->giveCardType()=='E'){
                temp= true;
            }
        }
        return temp;
    }
    bool checkForLand(){
        bool temp=false;
        for(int i=0;i<InPlay.size();i++){
            if(InPlay.at(i)->giveCardType()=='L'){
                temp= true;
            }
        }
        return temp;
    }
    bool checkForUntappedCreature(){
        bool temp=false;
        for(int i=0;i<InPlay.size();i++){
            if(InPlay.at(i)->giveCardType()=='C'&&(InPlay.at(i)->getIsTapped()==false)){
                temp= true;
            }
        }
        return temp;
    }
    bool checkForFirstStrikeCreature() {
        bool temp=false;
        for(int i=0;i<InPlay.size();i++){
            if(InPlay.at(i)->giveCardType()=='C'&&(InPlay.at(i)->getCanFirstStrike()== true)){
                temp= true;
            }
        }
        return temp;
    }

    void addCardToLibrary(Card *c){
        Library.push_back(c);
    }
    void addCardToDiscard(Card *c){
        Discard.push_back(c);
    }
    void reanimateCard(int Index){
        Hand.push_back(Discard.at(Index));
        Hand.at(Hand.size()-1)->resetHP();
        Discard.erase(Discard.begin()+Index);
    }
    void shuffleLibrary(){
        int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(Library.begin(), Library.end(), e);
    }

    void drawCard(){
        Hand.push_back(Library.at(0));
        Library.erase(Library.begin());
    }

    bool checkForVictory(player *p2){
        if(getHP()==0){
            return true;
        }else{
            if(p2->getHP()==0){
                return true;
            }else{
                return false;
            }
        }
    }

    void newRound(){

        BlackMana=MaxBlackMana;
        WhiteMana=MaxWhiteMana;
        RedMana=MaxRedMana;
        GreenMana=MaxGreenMana;
        BlueMana=MaxBlueMana;

        playedLandCard= false;

        Fighting.clear();

        for(int i=0;i<InPlay.size();i++){
            InPlay.at(i)->resetHPUntap();
        }

    }

    void printDiscardInfo(){
        for(int i=0;i<Discard.size();i++){
            std::cout<<i+1<<". "<<Discard.at(i)->giveCardName()<<":"<<std::endl;
        }
    }

    void printHandInfo(){
        std::cout<<playerName<<"'s Hand:"<<std::endl;
        std::cout<<"B:"<<MaxBlackMana<<"/"<<BlackMana<<" W:"<<MaxWhiteMana<<"/"<<WhiteMana<<" R:"<<MaxRedMana<<"/"<<RedMana<<" G:"<<MaxGreenMana<<"/"<< GreenMana<<" L:"<<MaxBlueMana<<"/"<<BlueMana<<std::endl;
        for(int i=0;i<Hand.size();i++){
            std::cout<<i+1<<". "<<Hand.at(i)->giveCardName()<<":";
            switch (Hand.at(i)->giveCardType()) {
                case 'C':{
                    std::cout<<" Attack Damage: "<<Hand.at(i)->getAttackDamage()<<" Health: "<<Hand.at(i)->getCardHP()<<" ";
                    if(Hand.at(i)->getCanFirstStrike()){
                        std::cout<<"Ability: FirstStrike ";
                    }
                    if(Hand.at(i)->getCanTrample()){
                        std::cout<<"Ability: Trample ";
                    }
                    std::cout<<"Cost:";
                    if(Hand.at(i)->getColorlessManaCost()>0){
                        std::cout<<Hand.at(i)->getColorlessManaCost();
                    }
                    for(int j=0;j<Hand.at(i)->getBlackManaCost();j++){
                        std::cout<<"B";
                    }
                    for(int j=0;j<Hand.at(i)->getWhiteManaCost();j++){
                        std::cout<<"W";
                    }
                    for(int j=0;j<Hand.at(i)->getRedManaCost();j++){
                        std::cout<<"R";
                    }
                    for(int j=0;j<Hand.at(i)->getGreenManaCost();j++){
                        std::cout<<"G";
                    }
                    for(int j=0;j<Hand.at(i)->getBlueManaCost();j++){
                        std::cout<<"L";
                    }
                    std::cout<<std::endl;
                    break;
                }
                case 'L':{
                    switch (Hand.at(i)->getCOMI()) {
                        case 'B':{
                            std::cout<<" Gives 1 Black Mana per turn"<<std::endl;
                            break;
                        }
                        case 'W':{
                            std::cout<<" Gives 1 White Mana per turn"<<std::endl;
                            break;
                        }
                        case 'R':{
                            std::cout<<" Gives 1 Red Mana per turn"<<std::endl;
                            break;
                        }
                        case 'G':{
                            std::cout<<" Gives 1 Green Mana per turn"<<std::endl;
                            break;
                        }
                        case 'L':{
                            std::cout<<" Gives 1 Blue Mana per turn"<<std::endl;
                            break;
                        }
                    }
                    break;
                }
                case 'S':{
                    std::cout<<Hand.at(i)->getCardDescription();

                    std::cout<<" Cost:";
                    if(Hand.at(i)->getColorlessManaCost()>0){
                        std::cout<<Hand.at(i)->getColorlessManaCost();
                    }
                    for(int j=0;j<Hand.at(i)->getBlackManaCost();j++){
                        std::cout<<"B";
                    }
                    for(int j=0;j<Hand.at(i)->getWhiteManaCost();j++){
                        std::cout<<"W";
                    }
                    for(int j=0;j<Hand.at(i)->getRedManaCost();j++){
                        std::cout<<"R";
                    }
                    for(int j=0;j<Hand.at(i)->getGreenManaCost();j++){
                        std::cout<<"G";
                    }
                    for(int j=0;j<Hand.at(i)->getBlueManaCost();j++){
                        std::cout<<"L";
                    }
                    std::cout<<std::endl;

                    break;
                }
                case 'E':{
                    std::cout<<" "<<Hand.at(i)->getCardDescription();

                    std::cout<<" Cost:";
                    if(Hand.at(i)->getColorlessManaCost()>0){
                        std::cout<<Hand.at(i)->getColorlessManaCost();
                    }
                    for(int j=0;j<Hand.at(i)->getBlackManaCost();j++){
                        std::cout<<"B";
                    }
                    for(int j=0;j<Hand.at(i)->getWhiteManaCost();j++){
                        std::cout<<"W";
                    }
                    for(int j=0;j<Hand.at(i)->getRedManaCost();j++){
                        std::cout<<"R";
                    }
                    for(int j=0;j<Hand.at(i)->getGreenManaCost();j++){
                        std::cout<<"G";
                    }
                    for(int j=0;j<Hand.at(i)->getBlueManaCost();j++){
                        std::cout<<"L";
                    }
                    std::cout<<std::endl;
                    break;
                }
            }
        }
    }
    void printInPlayInfo(){
        if(!InPlay.empty()){
            std::cout<<playerName<<" HP: "<<HP<<" Inplay:"<<std::endl;
            for(int i=0;i<InPlay.size();i++){
                std::cout<<i+1<<". "<<InPlay.at(i)->giveCardName();
                switch (InPlay.at(i)->giveCardType()) {
                    case 'C':{
                        std::cout<<" Attack Damage: "<<InPlay.at(i)->getAttackDamage()<<" Health: "<<InPlay.at(i)->getMaxCardHP()<<"/"<<InPlay.at(i)->getCardHP();

                        if(InPlay.at(i)->getCanFirstStrike()){
                            std::cout<<" Ability: FirstStrike ";
                        }
                        if(InPlay.at(i)->getCanTrample()){
                            std::cout<<" Ability: Trample ";
                        }
                        if(InPlay.at(i)->getIsTapped()){
                            std::cout<<"/tapped";
                        }else{
                            std::cout<<"/untapped";
                        }
                        std::cout<<std::endl;
                        break;
                    }
                    case 'L':{
                        std::cout<<std::endl;
                        break;
                    }
                    case 'E':{
                        std::cout<<std::endl;
                        break;
                    }
                }
            }
        }else{
            std::cout<<"There are no cards on "<<playerName<<"'s Inplay HP: "<<HP<<std::endl;
        }
    }

    void playSorcery(Card*s,player *p2,int BlackMS,int WhiteMS, int RedMS, int GreenMS, int BlueMS, int positionInHand){
        switch (s->giveCardName()[0]) {
            case 'D': {
                if(checkForEnchantment()||p2->checkForEnchantment()){
                    char Input1;
                    bool Continue1 = true;
                    while (Continue1) {
                        std::cout << "Enter 1 to choose en enchantment from this Inplay to destroy" << std::endl;
                        printInPlayInfo();
                        std::cout << "Enter 2 to choose en enchantment from this Inplay to destroy" << std::endl;
                        p2->printInPlayInfo();
                        std::cin >> Input1;
                        if(Input1=='0'||Input1=='1'){
                            Continue1= false;
                        }
                    }
                    char Input2;
                    bool Continue2 = true;
                    if(Input1=='1'){
                        printInPlayInfo();
                        std::cout << "Choose an enchantment card to destroy" << std::endl;
                        std::cin>>Input2;
                        if(Input2>'0'&&Input2<getInplaySize()+'0'){
                            if(getCardInplay(Input2-'1')->giveCardType()=='E'){
                                switch (getCardInplay(Input2-'1')->getEnchantmentNumber()) {
                                    case 1:{
                                        getCardInplay(Input2-'0')->uneffectByRage();
                                        addCardToDiscard(getCardInplay(Input2-'1'));
                                        eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 2:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyHolyWar()){
                                                getCardInplay(i)->uneffectByHolyWar();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyHolyWar()){
                                                p2->getCardInplay(i)->uneffectByHolyWar();
                                            }
                                        }
                                        addCardToDiscard(getCardInplay(Input2-'1'));
                                        eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 3:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyHolyLight()){
                                                getCardInplay(i)->uneffectByHolyLight();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyHolyLight()){
                                                p2->getCardInplay(i)->uneffectByHolyLight();
                                            }
                                        }
                                        addCardToDiscard(getCardInplay(Input2-'1'));
                                        eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 4:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyUnhholyWar()){
                                                getCardInplay(i)->uneffectByUnholyWar();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyUnhholyWar()){
                                                p2->getCardInplay(i)->uneffectByUnholyWar();
                                            }
                                        }
                                        addCardToDiscard(getCardInplay(Input2-'1'));
                                        eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 5:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyRestrain()){
                                                getCardInplay(i)->uneffectByRestrain();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyRestrain()){
                                                p2->getCardInplay(i)->uneffectByRestrain();

                                            }
                                        }
                                        addCardToDiscard(getCardInplay(Input2-'1'));
                                        eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 6:{
                                        getCardInplay(Input2-'0')->uneffectBySlow();
                                        addCardToDiscard(getCardInplay(Input2-'1'));
                                        eraseInplay(Input2-'1');
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(Input1=='2'){
                        p2->printInPlayInfo();
                        std::cout << "Choose an enchantment card to destroy" << std::endl;
                        std::cin>>Input2;
                        if(Input2>'0'&&Input2<p2->getInplaySize()+'0'){
                            if(p2->getCardInplay(Input2-'1')->giveCardType()=='E'){
                                switch (p2->getCardInplay(Input2-'1')->getEnchantmentNumber()) {
                                    case 1:{
                                        p2->getCardInplay(Input2-'0')->uneffectByRage();
                                        p2->addCardToDiscard(p2->getCardInplay(Input2-'1'));
                                        p2->eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 2:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyHolyWar()){
                                                getCardInplay(i)->uneffectByHolyWar();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyHolyWar()){
                                                p2->getCardInplay(i)->uneffectByHolyWar();
                                            }
                                        }
                                        p2->addCardToDiscard(p2->getCardInplay(Input2-'1'));
                                        p2->eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 3:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyHolyLight()){
                                                getCardInplay(i)->uneffectByHolyLight();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyHolyLight()){
                                                p2->getCardInplay(i)->uneffectByHolyLight();
                                            }
                                        }
                                        p2->addCardToDiscard(p2->getCardInplay(Input2-'1'));
                                        p2->eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 4:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyUnhholyWar()){
                                                getCardInplay(i)->uneffectByUnholyWar();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyUnhholyWar()){
                                                p2->getCardInplay(i)->uneffectByUnholyWar();
                                            }
                                        }
                                        p2->addCardToDiscard(p2->getCardInplay(Input2-'1'));
                                        p2->eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 5:{
                                        for(int i=0;i<getInplaySize();i++){
                                            if(getCardInplay(i)->isEffectedbyRestrain()){
                                                getCardInplay(i)->uneffectByRestrain();
                                            }
                                        }
                                        for(int i=0;i<p2->getInplaySize();i++){
                                            if(p2->getCardInplay(i)->isEffectedbyRestrain()){
                                                p2->getCardInplay(i)->uneffectByRestrain();
                                            }
                                        }
                                        p2->addCardToDiscard(p2->getCardInplay(Input2-'1'));
                                        p2->eraseInplay(Input2-'1');
                                        break;
                                    }
                                    case 6:{
                                        p2->getCardInplay(Input2-'0')->uneffectBySlow();
                                        p2->addCardToDiscard(p2->getCardInplay(Input2-'1'));
                                        p2->eraseInplay(Input2-'1');
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    addCardToDiscard(Hand.at(positionInHand));
                    Hand.erase(Hand.begin()+positionInHand);
                }else{
                    std::cout<<"There is no enchantment card played"<<std::endl;
                    BlackMana+=BlackMS;
                    WhiteMana+=WhiteMS;
                    GreenMana+=GreenMS;
                    RedMana+=RedMS;
                    BlueMana+=BlueMS;
                }

            }
            case 'L':{
                std::cout<<"Choose a card to attack or enter P to attack the opposing Player"<<std::endl;
                char Input;
                bool Continue=true;
                p2->printInPlayInfo();
                std::cin>>Input;
                while(Continue) {
                    if (Input == 'P') {
                        p2->changeHP(-2);
                        checkForVictory(p2);
                        Continue = false;
                    } else {
                        if (Input > '0' && Input <= p2->getInplaySize() + '0') {
                            if (p2->getCardInplay(Input - '1')->giveCardType() == 'C') {
                                p2->getCardInplay(Input - '1')->changeHealth(-2);
                                if (p2->getCardInplay(Input - '1')->getCardHP() <= 0) {
                                    std::cout<<p2->getCardInplay(Input - '1')->giveCardName()<<" took fatal damage and perished"<<std::endl;
                                    p2->addCardToDiscard(p2->getCardInplay(Input - '1'));
                                    p2->eraseInplay(Input - '1');
                                    if(Input - '2'>=0) {
                                        if (p2->getCardInplay(Input - '2')->giveCardType() == 'E' &&
                                            (p2->getCardInplay(Input - '2')->getEnchantmentNumber() == 1 ||
                                             p2->getCardInplay(Input - '2')->getEnchantmentNumber() == 6)) {
                                            p2->addCardToDiscard(getCardInplay(Input - '2'));
                                            p2->eraseInplay(Input - '2');
                                        }
                                    }

                                }else{
                                    std::cout<<p2->getCardInplay(Input - '1')->giveCardName()<<" took 2 damage but is still alive with "<<p2->getCardInplay(Input - '1')->getCardHP()<<"HP"<<std::endl;
                                }
                                Continue=false;
                                addCardToDiscard(Hand.at(positionInHand));
                                Hand.erase(Hand.begin()+positionInHand);
                            } else {
                                std::cout << "Please choose a creature card" << std::endl;
                            }
                        } else {
                            std::cout << "Please enter a valid character" << std::endl;
                        }
                    }
                }
                break;
            }
            case 'F': {
                std::cout << "Choose a land to destroy" << std::endl;
                char Input;
                bool Continue = true;
                p2->printInPlayInfo();
                if(checkForLand()){
                    while (Continue) {
                        std::cin >> Input;
                        if (Input > '0' && Input <= p2->getInplaySize() + '0') {
                            if (p2->getCardInplay(Input - '1')->giveCardType() == 'L') {
                                std::cout << p2->playerName << "'s" << p2->getCardInplay(Input - '1')->giveCardName()
                                          << " got flooded" << std::endl;
                                p2->destroyLand(p2->getCardInplay(Input - '1')->getCOMI());
                                p2->addCardToDiscard(p2->getCardInplay(Input - '1'));
                                p2->eraseInplay(Input - '1');
                                Continue = false;
                                addCardToDiscard(Hand.at(positionInHand));
                                Hand.erase(Hand.begin()+positionInHand);
                            } else {
                                std::cout << "Please choose a land card" << std::endl;
                            }
                        } else {
                            std::cout << "Please enter a valid number" << std::endl;
                        }
                    }
                }else{
                    BlackMana+=BlackMS;
                    WhiteMana+=WhiteMS;
                    GreenMana+=GreenMS;
                    RedMana+=RedMS;
                    BlueMana+=BlueMS;
                }
                break;
            }
            case'R': {
                printDiscardInfo();
                char Input;
                bool Continue = true;
                if(getDiscardSize()>0){
                    while (Continue) {
                        std::cout << "Choose a card from the discard pile to add to your hand" << std::endl;
                        std::cin >> Input;
                        if (Input > '0' && Input <= p2->getDiscardSize() + '0') {
                            reanimateCard(Input - '1');
                            Continue = false;
                            addCardToDiscard(Hand.at(positionInHand));
                            Hand.erase(Hand.begin()+positionInHand);
                        } else {
                            std::cout << "Please enter a valid number" << std::endl;
                        }
                    }
                }else{
                    BlackMana+=BlackMS;
                    WhiteMana+=WhiteMS;
                    GreenMana+=GreenMS;
                    RedMana+=RedMS;
                    BlueMana+=BlackMS;
                }
                break;
            }
            case 'P':{
                for(int i=0;i<getInplaySize();i++){
                    if(getCardInplay(i)->giveCardType()=='C') {
                        getCardInplay(i)->changeHealth(-1);
                        if (getCardInplay(i)->getCardHP() <= 0) {
                            std::cout<<playerName<<"'s"<<getCardInplay(i)->giveCardName()<<" perished"<<std::endl;
                            addCardToDiscard(p2->getCardInplay(i));
                            eraseInplay(i);
                            if(i-1>=0) {
                                if (getCardInplay(i - 1)->giveCardType() == 'E' &&(getCardInplay(i - 1)->getEnchantmentNumber() == 1 || getCardInplay(i - 1)->getEnchantmentNumber() == 6)) {
                                    addCardToDiscard(getCardInplay(i - 1));
                                    eraseInplay(i - 1);
                                }
                            }

                        }
                    }
                }
                for(int i=0;i<p2->getInplaySize();i++){
                    if(p2->getCardInplay(i)->giveCardType()=='C') {
                        p2->getCardInplay(i)->changeHealth(-1);
                        if (p2->getCardInplay(i)->getCardHP() <= 0) {
                            std::cout<<p2->playerName<<"'s"<<p2->getCardInplay(i)->giveCardName()<<" perished"<<std::endl;
                            p2->addCardToDiscard(p2->getCardInplay(i));
                            p2->eraseInplay(i);
                            if(i-1>=0) {
                                if (p2->getCardInplay(i - 1)->giveCardType() == 'E' && (p2->getCardInplay(i - 1)->getEnchantmentNumber() == 1 || p2->getCardInplay(i - 1)->getEnchantmentNumber() == 6)) {
                                    p2->addCardToDiscard(getCardInplay(i - 1));
                                    p2->eraseInplay(i - 1);
                                }
                            }

                        }
                    }
                }
                addCardToDiscard(Hand.at(positionInHand));
                Hand.erase(Hand.begin()+positionInHand);
                break;
            }
            case 'T': {
                std::cout << "Choose a creature to destroy" << std::endl;
                char Input;
                bool Continue = true;
                p2->printInPlayInfo();
                if(p2->checkForCreature()){
                    while (Continue) {
                        std::cin >> Input;
                        if (Input > '0' && Input <= p2->getInplaySize() + '0') {
                            if (p2->getCardInplay(Input - '1')->giveCardType() == 'C') {
                                p2->addCardToDiscard(p2->getCardInplay(Input - '1'));
                                p2->eraseInplay(Input - '1');
                                addCardToDiscard(Hand.at(positionInHand));
                                Hand.erase(Hand.begin()+positionInHand);
                                if (Input - '2' >= 0) {
                                    if ((p2->getCardInplay(Input - '2')->giveCardType() == 'E')){
                                        if((p2->getCardInplay(Input - '2')->getEnchantmentNumber() == 1)||((p2->getCardInplay(Input - '2')->getEnchantmentNumber() == 6))){
                                            p2->addCardToDiscard(p2->getCardInplay(Input - '2'));
                                            p2->eraseInplay(Input - '2');
                                        }
                                    }
                                }
                                Continue = false;
                            } else {
                                std::cout << "Please choose a creature card" << std::endl;
                            }
                        } else {
                            std::cout << "Please enter a valid number" << std::endl;
                        }
                    }
                }else{
                    BlackMana+=BlackMS;
                    WhiteMana+=WhiteMS;
                    GreenMana+=GreenMS;
                    RedMana+=RedMS;
                    BlueMana+=BlackMS;
                }
                break;
            }
        }
    }

    void playEnchantment(int BlackMS, int WhiteMS, int RedMS, int GreenMS, int BlueMS, int PositionInHand, Card *e, player *p2) {
        switch (e->getEnchantmentNumber()) {
            case 1:{
                bool Continue=true;
                char Input;
                std::cout << "Choose a creature card to gain trample or press S to stop" << std::endl;
                while (Continue) {
                    if (checkForCreature()) {
                        std::cin>>Input;
                        if(Input=='S'){
                            BlackMana+=BlackMS;
                            WhiteMana+=WhiteMS;
                            GreenMana+=GreenMS;
                            RedMana+=RedMS;
                            BlueMana+=BlueMS;
                            Continue=false;
                        }else{
                            if(Input>'0'&&Input<=getInplaySize()+'0'){
                                if(getCardInplay(Input-'1')->giveCardType()=='C'){
                                    getCardInplay(Input-'1')->effectByRage();
                                    InPlay.insert(InPlay.begin()+Input-'1',e);
                                    Hand.erase(Hand.begin()+PositionInHand);
                                    Continue=false;
                                }else{
                                    std::cout << "Please choose a creature card" << std::endl;
                                }
                            }else{
                                std::cout << "Please enter a valid character" << std::endl;
                            }
                        }
                    }else{
                        std::cout << "You don't have a creature card Inplay to gain trample" << std::endl;
                        Continue= false;
                        BlackMana+=BlackMS;
                        WhiteMana+=WhiteMS;
                        GreenMana+=GreenMS;
                        RedMana+=RedMS;
                        BlueMana+=BlueMS;
                    }
                }
                break;
            }
            case 2:{
                for(int i=0;i<getInplaySize();i++){
                    if(getCardInplay(i)->giveCardType()=='C'){
                        if(getCardInplay(i)->getCardColor()=='W'){
                            getCardInplay(i)->effectByHolyWar();

                        }
                    }
                }
                for(int i=0;i<p2->getInplaySize();i++){
                    if(p2->getCardInplay(i)->giveCardType()=='C'){
                        if(p2->getCardInplay(i)->getCardColor()=='W'){
                            p2->getCardInplay(i)->effectByHolyWar();
                        }
                    }
                }
                InPlay.push_back(e);
                Hand.erase(Hand.begin()+PositionInHand);
                break;
            }
            case 3:{
                for(int i=0;i<getInplaySize();i++){
                    if(getCardInplay(i)->giveCardType()=='C'){
                        if(getCardInplay(i)->getCardColor()=='B'){
                            getCardInplay(i)->effectByHolyLight();
                            if(getCardInplay(i)->getCardHP()==0){
                                addCardToDiscard(getCardInplay(i));
                                eraseInplay(i);
                                if(i-1>=0) {
                                    if (getCardInplay(i - 1)->giveCardType() == 'E' &&
                                        (getCardInplay(i - 1)->getEnchantmentNumber() == 1 ||
                                         getCardInplay(i - 1)->getEnchantmentNumber() == 6)) {
                                        addCardToDiscard(getCardInplay(i - 1));
                                        eraseInplay((i - 1));
                                    }
                                }

                            }
                        }
                    }
                }
                for(int i=0;i<p2->getInplaySize();i++){
                    if(p2->getCardInplay(i)->giveCardType()=='C'){
                        if(p2->getCardInplay(i)->getCardColor()=='B'){
                            p2->getCardInplay(i)->effectByHolyLight();
                            if(p2->getCardInplay(i)->getCardHP()==0) {
                                p2->addCardToDiscard(getCardInplay(i));
                                p2->eraseInplay(i);
                                if(i-1>=0) {
                                    if (p2->getCardInplay(i - 1)->giveCardType() == 'E' &&
                                        (p2->getCardInplay(i - 1)->getEnchantmentNumber() == 1 ||
                                         p2->getCardInplay(i - 1)->getEnchantmentNumber() == 6)) {
                                        p2->addCardToDiscard(getCardInplay(i - 1));
                                        p2->eraseInplay((i - 1));
                                    }
                                }

                            }
                        }
                    }
                }
                InPlay.push_back(e);
                Hand.erase(Hand.begin()+PositionInHand);
                break;
            }
            case 4:{
                for(int i=0;i<getInplaySize();i++){
                    if(getCardInplay(i)->giveCardType()=='C'){
                        if(getCardInplay(i)->getCardColor()=='B'){
                            getCardInplay(i)->effectByUnholyWar();
                        }
                    }
                }
                for(int i=0;i<p2->getInplaySize();i++){
                    if(p2->getCardInplay(i)->giveCardType()=='C'){
                        if(p2->getCardInplay(i)->getCardColor()=='B'){
                            p2->getCardInplay(i)->effectByUnholyWar();
                        }
                    }
                }
                InPlay.push_back(e);
                Hand.erase(Hand.begin()+PositionInHand);
                break;
            }
            case 5:{

                for(int i=0;i<getInplaySize();i++){
                    if(getCardInplay(i)->giveCardType()=='C'){
                        if(getCardInplay(i)->getCardColor()=='B'){
                            getCardInplay(i)->isEffectedbyRestrain();
                        }
                    }
                }
                for(int i=0;i<p2->getInplaySize();i++){
                    if(p2->getCardInplay(i)->giveCardType()=='C'){
                        if(p2->getCardInplay(i)->getCardColor()=='B'){
                            p2->getCardInplay(i)->isEffectedbyRestrain();
                        }
                    }
                }
                InPlay.push_back(e);
                Hand.erase(Hand.begin()+PositionInHand);
                break;
            }
            case 6: {
                bool Continue = true;
                char Input;
                p2->printInPlayInfo();
                std::cout << "Choose a creature to loose FirstStrike" << std::endl;
                while (Continue) {
                    if (p2->checkForFirstStrikeCreature()) {
                        std::cin >> Input;
                        if (Input == 'S') {
                            BlackMana += BlackMS;
                            WhiteMana += WhiteMS;
                            GreenMana += GreenMS;
                            RedMana += RedMS;
                            BlueMana += BlueMS;
                            Continue = false;
                        } else {
                            if (Input > '0' && Input <= p2->getInplaySize() + '0') {
                                if (p2->getCardInplay(Input - '0')->giveCardType() == 'C') {
                                    if (p2->getCardInplay(Input - '0')->getCanFirstStrike() == true) {
                                        p2->getCardInplay(Input - '0')->removeFirstStrike();
                                        p2->addInplay(Input - '1', e);
                                        Hand.erase(Hand.begin() + PositionInHand);
                                        Continue = false;
                                    } else {
                                        std::cout << "Please choose a creature card with FirstStrike" << std::endl;
                                    }
                                } else {
                                    std::cout << "Please choose a creature card" << std::endl;
                                }
                            } else {
                                std::cout << "Please enter a valid character" << std::endl;
                            }
                        }
                    } else {
                        std::cout << "There is no creature that can loose FirstStrike" << std::endl;
                        Continue = false;
                        BlackMana += BlackMS;
                        WhiteMana += WhiteMS;
                        GreenMana += GreenMS;
                        RedMana += RedMS;
                        BlueMana += BlueMS;
                    }
                }
                break;
            }
        }
    }

    void playCard(Card* c, int positionInHand, player *p2) {
        if(getInplaySize()<9){
            switch (c->giveCardType()) {
                case 'C': {
                    if (c->getBlackManaCost() <= BlackMana && c->getWhiteManaCost() <= WhiteMana &&
                        c->getRedManaCost() <= RedMana && c->getGreenManaCost() <= GreenMana &&
                        c->getBlueManaCost() <= BlueMana
                        && c->getBlackManaCost() + c->getWhiteManaCost() + c->getRedManaCost() + c->getGreenManaCost() +
                           c->getBlueManaCost() + c->getColorlessManaCost() <=
                           BlackMana + WhiteMana + RedMana + GreenMana + BlueMana) {
                        BlackMana -= c->getBlackManaCost();
                        WhiteMana -= c->getWhiteManaCost();
                        RedMana -= c->getRedManaCost();
                        GreenMana -= c->getGreenManaCost();
                        BlueMana -= c->getBlueManaCost();
                        if (c->getColorlessManaCost() > 0) {
                            int LoopIndex = c->getColorlessManaCost();
                            char temp;
                            std::cout << "Choose " << LoopIndex << " Mana to play " << c->giveCardName() << std::endl;
                            for (int i = 0; LoopIndex > i; i++) {
                                std::cin >> temp;
                                if (temp == 'B') {
                                    if (BlackMana >= 1) {
                                        BlackMana--;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have black mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'W') {
                                    if (WhiteMana >= 1) {
                                        WhiteMana--;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have white mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'R') {
                                    if (RedMana >= 1) {
                                        RedMana--;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have red mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'G') {
                                    if (GreenMana >= 1) {
                                        GreenMana--;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have green mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'L') {
                                    if (BlueMana >= 1) {
                                        BlueMana--;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have blue mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp != 'B' && temp != 'W' && temp != 'R' && temp != 'G' && temp != 'L') {
                                    std::cout << "Input a valid color" << std::endl;
                                    LoopIndex++;
                                }
                            }
                            InPlay.push_back(Hand.at(positionInHand));
                            Hand.erase(Hand.begin() + positionInHand);
                        } else {
                            InPlay.push_back(Hand.at(positionInHand));
                            Hand.erase(Hand.begin() + positionInHand);
                            break;
                        }
                    } else {
                        std::cout << "You don't have enough mana" << std::endl;
                    }
                    break;
                }


                case 'L': {
                    if (playedLandCard == false) {
                        switch (c->getCOMI()) {
                            case 'B': {
                                MaxBlackMana++;
                                BlackMana++;
                                playedLandCard = true;
                                break;
                            }
                            case 'W': {
                                MaxWhiteMana++;
                                WhiteMana++;
                                playedLandCard = true;
                                break;
                            }
                            case 'R': {
                                MaxRedMana++;
                                RedMana++;
                                playedLandCard = true;
                                break;
                            }
                            case 'G': {
                                MaxGreenMana++;
                                GreenMana++;
                                playedLandCard = true;
                                break;
                            }
                            case 'L': {
                                MaxBlueMana++;
                                BlueMana++;
                                playedLandCard = true;
                                break;
                            }
                        }
                        InPlay.push_back(Hand.at(positionInHand));
                        Hand.erase(Hand.begin() + positionInHand);
                    } else {
                        std::cout << "You can only play 1 LandCard per turn" << std::endl;
                    }
                    break;
                }
                case 'S': {
                    if (c->getBlackManaCost() <= BlackMana && c->getWhiteManaCost() <= WhiteMana &&
                        c->getRedManaCost() <= RedMana && c->getGreenManaCost() <= GreenMana &&
                        c->getBlueManaCost() <= BlueMana
                        && c->getBlackManaCost() + c->getWhiteManaCost() + c->getRedManaCost() + c->getGreenManaCost() +
                           c->getBlueManaCost() + c->getColorlessManaCost() <=
                           BlackMana + WhiteMana + RedMana + GreenMana + BlueMana) {
                        int BlackManaSpent = c->getBlackManaCost();
                        int WhiteManaSpent = c->getWhiteManaCost();
                        int RedManaSpent = c->getRedManaCost();
                        int GreenManaSpent = c->getGreenManaCost();
                        int BlueManaSpent = c->getBlueManaCost();
                        BlackMana -= c->getBlackManaCost();
                        WhiteMana -= c->getWhiteManaCost();
                        RedMana -= c->getRedManaCost();
                        GreenMana -= c->getGreenManaCost();
                        BlueMana -= c->getBlueManaCost();
                        if (c->getColorlessManaCost() > 0) {
                            int LoopIndex = c->getColorlessManaCost();
                            char temp;
                            std::cout << "Choose " << LoopIndex << " Mana to play " << c->giveCardName() << std::endl;
                            for (int i = 0; LoopIndex > i; i++) {
                                std::cin >> temp;
                                if (temp == 'B') {
                                    if (BlackMana >= 1) {
                                        BlackMana--;
                                        BlackManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have black mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'W') {
                                    if (WhiteMana >= 1) {
                                        WhiteMana--;
                                        WhiteManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have white mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'R') {
                                    if (RedMana >= 1) {
                                        RedMana--;
                                        RedManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have red mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'G') {
                                    if (GreenMana >= 1) {
                                        GreenMana--;
                                        GreenManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have green mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'L') {
                                    if (BlueMana >= 1) {
                                        BlueMana--;
                                        BlueManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have blue mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp != 'B' && temp != 'W' && temp != 'R' && temp != 'G' && temp != 'L') {
                                    std::cout << "Input a valid color" << std::endl;
                                    LoopIndex++;
                                }
                            }
                            playSorcery(Hand.at(positionInHand), p2, BlackManaSpent, WhiteManaSpent, RedManaSpent,
                                        GreenManaSpent, BlueManaSpent, positionInHand);
                        } else {
                            playSorcery(Hand.at(positionInHand), p2, BlackManaSpent, WhiteManaSpent, RedManaSpent,
                                        GreenManaSpent, BlueManaSpent, positionInHand);
                            break;
                        }
                    } else {
                        std::cout << "You don't have enough mana" << std::endl;
                    }
                    break;
                }
                case 'E': {
                    if (c->getBlackManaCost() <= BlackMana && c->getWhiteManaCost() <= WhiteMana &&
                        c->getRedManaCost() <= RedMana && c->getGreenManaCost() <= GreenMana &&
                        c->getBlueManaCost() <= BlueMana
                        && c->getBlackManaCost() + c->getWhiteManaCost() + c->getRedManaCost() + c->getGreenManaCost() +
                           c->getBlueManaCost() + c->getColorlessManaCost() <=
                           BlackMana + WhiteMana + RedMana + GreenMana + BlueMana) {
                        int BlackManaSpent = c->getBlackManaCost();
                        int WhiteManaSpent = c->getWhiteManaCost();
                        int RedManaSpent = c->getRedManaCost();
                        int GreenManaSpent = c->getGreenManaCost();
                        int BlueManaSpent = c->getBlueManaCost();
                        BlackMana -= c->getBlackManaCost();
                        WhiteMana -= c->getWhiteManaCost();
                        RedMana -= c->getRedManaCost();
                        GreenMana -= c->getGreenManaCost();
                        BlueMana -= c->getBlueManaCost();
                        if (c->getColorlessManaCost() > 0) {
                            int LoopIndex = c->getColorlessManaCost();
                            char temp;
                            std::cout << "Choose " << LoopIndex << " Mana to play " << c->giveCardName() << std::endl;
                            for (int i = 0; LoopIndex > i; i++) {
                                std::cin >> temp;
                                if (temp == 'B') {
                                    if (BlackMana >= 1) {
                                        BlackMana--;
                                        BlackManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have black mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'W') {
                                    if (WhiteMana >= 1) {
                                        WhiteMana--;
                                        WhiteManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have white mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'R') {
                                    if (RedMana >= 1) {
                                        RedMana--;
                                        RedManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have red mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'G') {
                                    if (GreenMana >= 1) {
                                        GreenMana--;
                                        GreenManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have green mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp == 'L') {
                                    if (BlueMana >= 1) {
                                        BlueMana--;
                                        BlueManaSpent++;
                                        std::cout << "Mana accepted" << std::endl;
                                    } else {
                                        std::cout << "You don't have blue mana" << std::endl;
                                        LoopIndex++;
                                    }
                                }
                                if (temp != 'B' && temp != 'W' && temp != 'R' && temp != 'G' && temp != 'L') {
                                    std::cout << "Input a valid color" << std::endl;
                                    LoopIndex++;
                                }
                            }
                            playEnchantment(BlackManaSpent, WhiteManaSpent, RedManaSpent, GreenManaSpent, BlueManaSpent,
                                            positionInHand, Hand.at(positionInHand), p2);
                        } else {
                            playEnchantment(BlackManaSpent, WhiteManaSpent, RedManaSpent, GreenManaSpent, BlueManaSpent,
                                            positionInHand, Hand.at(positionInHand), p2);
                            break;
                        }
                    } else {
                        std::cout << "You don't have enough mana" << std::endl;
                    }
                    break;
                }
            }
        }else{
            std::cout<<"You cant have more than 9 cards Inplay"<<std::endl;
        }
    }

    void cardPlayingPhase(player *p2,int turn) {
        std::cout << "Turn "<<turn<<": "<<playerName<<"'s card playing phase" << std::endl;
        std::cout << "To play a card input that cards number in your hand or enter 'S' to stop" << std::endl;
        char Input;
        int PositionInDeck;
        bool Continue= true;
        while(Continue) {
            printHandInfo();
            printInPlayInfo();
            p2->printInPlayInfo();
            std::cin >> Input;
            if (Input >= '0' && Input <= Hand.size()+'0') {
                PositionInDeck = Input - '1';
                playCard(Hand.at(PositionInDeck), PositionInDeck, p2);
            }else{
                if (Input == 'S') {
                    Continue= false;
                }else{
                    if((Input!='S')&&((Input >= '0' && Input <= Hand.size()+'0')==0)){
                        std::cout << "Please input a valid character" << std::endl;
                    }
                }
            }
        }
    }

    void attackers() {
        char Input;
        int PositionInDeck;
        bool Continue= true;
        if(checkForUntappedCreature()) {
            while (Continue) {
                if (checkForUntappedCreature()) {
                    std::cout << playerName << " Choose attackers by inputting that number or enter 'S' to stop"<< std::endl;
                    printInPlayInfo();
                    std::cin >> Input;
                    if (Input == 'S') {
                        Continue = false;
                    } else {
                        if (Input >= '1' && Input <= InPlay.size() + '0') {
                            PositionInDeck = Input - '1';
                            if (InPlay.at(PositionInDeck)->giveCardType() == 'C') {
                                if (InPlay.at(PositionInDeck)->getIsTapped() == false) {
                                    InPlay.at(PositionInDeck)->tap();
                                    Fighting.push_back(InPlay.at(PositionInDeck));
                                } else {
                                    std::cout << "That card is already tapped" << std::endl;
                                }
                            } else {
                                std::cout << "Please choose a creature card" << std::endl;
                            }
                        } else {
                            if ((Input != 'S') && ((Input >= '0' && Input <= InPlay.size() + '0') == 0)) {
                                std::cout << "Please input a valid character" << std::endl;
                            }
                        }
                    }
                }else{
                    Continue= false;
                }
            }
        }
    }

    void printAttackersFrom(int start){
        if(Fighting.size()>start){
            std::cout<<playerName<<"'s Attackers:"<<std::endl;
            for(int i=start;i<Fighting.size();i++){
                std::cout<<i+1-start<<"."<<Fighting.at(i)->giveCardName();
                std::cout<<" Attack Damage: "<<Fighting.at(i)->getAttackDamage()<<" Health: "<<Fighting.at(i)->getMaxCardHP()<<"/"<<Fighting.at(i)->getCardHP();
                if(Fighting.at(i)->getCanFirstStrike()){
                    std::cout<<" Ability: FirstStrike";
                }
                if(Fighting.at(i)->getCanTrample()){
                    std::cout<<" Ability: Trample";
                }
                std::cout<<std::endl;
            }
        }else{
            std::cout<<"There are no undefended from attackers"<<std::endl;
        }
    }

    void defenders(player *p1){
        if(!p1->Fighting.empty()){
            if(checkForUntappedCreature()){
                char Input1;
                char Input2;
                bool Continue=true;
                std::cout<<"First choose a defender and then choose a card to defend against or enter S to stop"<<std::endl;
                while (Continue){
                    if(checkForUntappedCreature()) {
                        p1->printAttackersFrom(Fighting.size());
                        printInPlayInfo();
                        std::cin >> Input1;
                        if (Fighting.size() < p1->Fighting.size()) {
                            if (Input1 == 'S') {
                                break;
                            } else {
                                if (Input1 > '0' && Input1 <= '0' + InPlay.size()) {
                                    if (InPlay.at(Input1 - '1')->giveCardType() == 'C' &&
                                        (InPlay.at(Input1 - '1')->getIsTapped() == false)) {
                                        std::cout << "Defender chosen" << std::endl;
                                        std::cin >> Input2;
                                        if (Input2 >= '0' && Input2 <= '9') {
                                            if (Input2 > '0' &&
                                                Input2 <= '0' + (p1->Fighting.size() - Fighting.size())) {
                                                p1->makeFirstInFighting(Input2 - '1');
                                                InPlay.at(Input1 - '1')->tap();
                                                Fighting.push_back(InPlay.at(Input1 - '1'));
                                            } else {
                                                std::cout << "Please enter a valid number" << std::endl;
                                            }
                                        } else {
                                            std::cout << "Please enter a number" << std::endl;
                                        }
                                    } else {
                                        std::cout << "Please choose an untapped creature card" << std::endl;
                                    }
                                } else {
                                    std::cout << "Please enter a valid character" << std::endl;
                                }
                            }
                        } else {
                            std::cout << "There are no undefended from attackers" << std::endl;
                            Continue = false;
                        }
                    }else{
                        std::cout << "There are no more defenders you can choose"<< std::endl;
                        Continue = false;
                    }
                }
            }else{
                std::cout<<"You have no untapped creatures to defend yourself"<<std::endl;
            }
        }
    }

    void getAttacked(Card *a){
        HP-=a->getAttackDamage();
    }

    void getAttackedAndDefend(Card *a,Card *d){
        if(a->getCanFirstStrike() == false && d->getCanFirstStrike()== false){
            a->changeHealth(d->getAttackDamage()*-1);
            d->changeHealth(a->getAttackDamage()*-1);
            if(a->getCanTrample()&&a->getCardHP()>0){
                HP-=a->getAttackDamage();
            }
        }
        if(a->getCanFirstStrike() == true && d->getCanFirstStrike()== true){
            a->changeHealth(d->getAttackDamage()*-1);
            d->changeHealth(a->getAttackDamage()*-1);
            if(a->getCanTrample()&&a->getCardHP()>0){
                HP-=a->getAttackDamage();
            }
        }
        if(a->getCanFirstStrike() == true && d->getCanFirstStrike()== false){
            d->changeHealth(a->getAttackDamage()*-1);
            if(d->getCardHP()>0){
                a->changeHealth(d->getAttackDamage()*-1);
            }
            if(a->getCanTrample()&&a->getCardHP()>0){
                HP-=a->getAttackDamage();
            }
        }
        if(a->getCanFirstStrike() == false && d->getCanFirstStrike()== true){
            a->changeHealth(d->getAttackDamage()*-1);
            if(a->getCardHP()>0){
                d->changeHealth(a->getAttackDamage()*-1);
            }
            if(a->getCanTrample()&&a->getCardHP()>0){
                HP-=a->getAttackDamage();
            }
        }
    }

    void clash(player *p2){
        if(p2->getFightingSize()>0){
            for(int i=0;i<Fighting.size();i++){
                getAttackedAndDefend(p2->getFighter(i),Fighting.at(i));
            }
            for(int i=0;i<(p2->Fighting.size()-Fighting.size());i++){
                getAttacked(p2->getFighter(i));
            }
            this->Fighting.clear();
            p2->clearFighting();
            if(!checkForVictory(p2)){
                printInPlayInfo();
            }
        }
    }
};

void checkForDead(player *p1, player *p2){
    for(int i=0;i<p1->getInplaySize();i++){
        if(p1->getCardInplay(i)->giveCardType()=='C'){
            if(p1->getCardInplay(i)->getCardHP()<=0){
                std::cout<<p1->getName()<<"'s "<<p1->getCardInplay(i)->giveCardName()<<" perished"<<std::endl;
                p1->addCardToDiscard(p1->getCardInplay(i));
                p1->eraseInplay(i);
                if(i-1>=0) {
                    if (p1->getCardInplay(i - 1)->giveCardType() == 'E' &&
                        (p1->getCardInplay(i - 1)->getEnchantmentNumber() == 1 ||
                         p1->getCardInplay(i - 1)->getEnchantmentNumber() == 6)) {
                        p1->addCardToDiscard(p1->getCardInplay(i - 1));
                        p1->eraseInplay(i - 1);
                    }
                }

                i--;
            }
        }
    }
    for(int i=0;i<p2->getInplaySize();i++){
        if(p2->getCardInplay(i)->giveCardType()=='C'){
            if(p2->getCardInplay(i)->getCardHP()<=0){
                std::cout<<p2->getName()<<"'s "<<p2->getCardInplay(i)->giveCardName()<<" perished"<<std::endl;
                p2->addCardToDiscard(p2->getCardInplay(i));
                p2->eraseInplay(i);
                if(i-1>=0) {
                    if (p2->getCardInplay(i - 1)->giveCardType() == 'E' &&
                        (p2->getCardInplay(i - 1)->getEnchantmentNumber() == 1 ||
                         p2->getCardInplay(i - 1)->getEnchantmentNumber() == 6)) {
                        p2->addCardToDiscard(p1->getCardInplay(i - 1));
                        p2->eraseInplay(i - 1);
                    }
                }

                i--;
            }
        }
    }
}

bool checkForVictory(player *p1, player *p2){
    if(p1->getHP()<=0){
        std::cout<<"Player 2 WON!!! with "<< p2->getHP() << " health left";
        return true;
    }else{
        if(p2->getHP()<=0){
            std::cout<<"Player 1 WON!!! with "<< p1->getHP() << " health left";
            return true;
        }else{
            return false;
        }
    }
}





int main() {


    LandCard Swamp1("Swamp",'B'), *ptSwamp1 = &Swamp1;
    LandCard Swamp2("Swamp",'B'), *ptSwamp2 = &Swamp2;
    LandCard Swamp3("Swamp",'B'), *ptSwamp3 = &Swamp3;
    LandCard Swamp4("Swamp",'B'), *ptSwamp4 = &Swamp4;
    LandCard Swamp5("Swamp",'B'), *ptSwamp5 = &Swamp5;

    LandCard Plains1("Plains",'W'), *ptPlains1 = &Plains1;
    LandCard Plains2("Plains",'W'), *ptPlains2 = &Plains2;
    LandCard Plains3("Plains",'W'), *ptPlains3 = &Plains3;
    LandCard Plains4("Plains",'W'), *ptPlains4 = &Plains4;
    LandCard Plains5("Plains",'W'), *ptPlains5 = &Plains5;

    LandCard Mountain1("Mountain",'R'), *ptMountain1=&Mountain1;
    LandCard Mountain2("Mountain",'R'), *ptMountain2=&Mountain2;
    LandCard Mountain3("Mountain",'R'), *ptMountain3=&Mountain3;

    LandCard Forest1("Forest",'G'), *ptForest1=&Forest1;
    LandCard  Forest2 ("Forest",'G'), *ptForest2=&Forest2;
    LandCard Forest3("Forest",'G'),*ptForest3=&Forest3;

    LandCard Island1("Island",'L'), *ptIsland1=&Island1;
    LandCard Island2("Island",'L'), *ptIsland2=&Island2;


    CreatureCard Soldier1("Soldier",1,1,'W',0,1,0,0,0,0,false,false),*ptSoldier1=&Soldier1;
    CreatureCard Soldier2("Soldier",1,1,'W',0,1,0,0,0,0,false,false),*ptSoldier2=&Soldier2;
    CreatureCard Soldier3("Soldier",1,1,'W',0,1,0,0,0,0,false,false),*ptSoldier3=&Soldier3;

    CreatureCard Armored_Pegasus1("Armored Pegasus",2,1,'W',0,1,0,0,0,1,false,false),*ptArmored_Pegasus1=&Armored_Pegasus1;
    CreatureCard Armored_Pegasus2("Armored Pegasus",2,1,'W',0,1,0,0,0,1,false,false),*ptArmored_Pegasus2=&Armored_Pegasus2;

    CreatureCard White_Knight1("White Knight",2,2,'W',0,2,0,0,0,0, true,false),*ptWhite_Knight1=&White_Knight1;
    CreatureCard White_Knight2("White Knight",2,2,'W',0,2,0,0,0,0, true,false),*ptWhite_Knight2=&White_Knight2;

    CreatureCard Angry_Bear1("Angry Bear",2,3,'G',0,0,0,1,0,2,false,true),*ptAngry_Bear1 =&Angry_Bear1;

    CreatureCard Guard1("Guard",5,2,'W',0,2,0,0,0,2,false,false),*ptGuard1=&Guard1;

    CreatureCard Werewolf1("Werewolf",6,4,'G',0,1,0,1,0,2,false, true),*ptWerewolf1=&Werewolf1;


    CreatureCard Skeleton1("Skeleton",1,1,'B',1,0,0,0,0,0,false,false),*ptSkeleton1=&Skeleton1;
    CreatureCard Skeleton2("Skeleton",1,1,'B',1,0,0,0,0,0,false,false),*ptSkeleton2=&Skeleton2;
    CreatureCard Skeleton3("Skeleton",1,1,'B',1,0,0,0,0,0,false,false),*ptSkeleton3=&Skeleton3;

    CreatureCard Ghost1("Ghost",1,2,'B',1,0,0,0,0,1,false,false),*ptGhost1=&Ghost1;
    CreatureCard Ghost2("Ghost",1,2,'B',1,0,0,0,0,1,false,false),*ptGhost2=&Ghost2;

    CreatureCard Black_Knight1("Black Knight",2,2,'B',2,0,0,0,0,0, true,false),*ptBlack_Knight1=&Black_Knight1;
    CreatureCard Black_Knight2("Black Knight",2,2,'B',2,0,0,0,0,0, true,false),*ptBlack_Knight2=&Black_Knight2;

    CreatureCard Orc_Maniac1("Orc Maniac",1,4,'R',0,0,1,0,0,2, false,false),*ptOrc_Maniac1=&Orc_Maniac1;

    CreatureCard Hobgoblin1("Hobgoblin",3,3,'R',1,0,1,0,0,1, false,false),*ptHobgoblin1=&Hobgoblin1;

    CreatureCard Vampire1("Vampire",3,6,'B',1,0,0,0,0,3, false,false),*ptVampire1=&Vampire1;

    SorceryCard Disenchant1("Disenchant",'W',0,1,0,0,0,1,"Destroy 1 Target Enchantment"),*ptDisenchant1=&Disenchant1;

    SorceryCard Lightning_Bolt1("Lightning Bolt",'G',0,0,0,1,0,1,"Deal 2 dmg to target creature or player" ),*ptLightning_Bolt1=&Lightning_Bolt1;

    SorceryCard Flood1("Flood",'G',0,1,0,1,0,1,"Destroy 1 Target Land"),*ptFlood1=&Flood1;
    SorceryCard Flood2("Flood",'G',0,1,0,1,0,1,"Destroy 1 Target Land"),*ptFlood2=&Flood2;

    SorceryCard Reanimate1("Reanimate",'B',1,0,0,0,0,0,"Return 1 character card from discard to hand"),*ptReanimate1=&Reanimate1;

    SorceryCard Plague1("Plague",'B',1,0,0,0,0,2, "Deal 1 dmg to all creatures"),*ptPlague1=&Plague1;

    SorceryCard Terror1("Terror",'B', 1, 0, 0, 0, 0, 1, "Destroy 1 Target Creature" ),*ptTerror1=&Terror1;
    SorceryCard Terror2("Terror",'B',1,0,0,0,0,1,"Destroy 1 Target Creature" ),*ptTerror2=&Terror2;

    EnchantmentCard Rage1("Rage",'G',0,0,0,1,0,0,1,"Give 1 Target Card Trample"),*ptRage1=&Rage1;

    EnchantmentCard Holy_War1("Holy War",'W',0,1,0,0,0,1,2,"All white creatures gain +1/+1"),*ptHoly_War1=&Holy_War1;

    EnchantmentCard Holy_Light1("Holy Light",'W',0,1,0,0,0,1,3,"All black creatures gain -1/-1"),*ptHoly_Light1=&Holy_Light1;

    EnchantmentCard Unholy_War1("Unholy War",'B',1,0,0,0,0,1,4,"All black creatures gain +0/+2"),*ptUnholy_War1=&Unholy_War1;

    EnchantmentCard Restrain1("Restrain",'R',0,0,1,0,0,2,5,"All green creatures lose Trample"),*ptRestrain1=&Restrain1;

    EnchantmentCard Slow1("Slow",'B',1,0,0,0,0,0,6,"1 Target creature loses First Strike"),*ptSlow1=&Slow1;



    std::cout<<"Who Is Player 1"<<std::endl;
    std::string p1Name;
    std::cin>>p1Name;
    player p1(p1Name);

    p1.addCardToLibrary(ptPlains1);
    p1.addCardToLibrary(ptPlains2);
    p1.addCardToLibrary(ptPlains3);
    p1.addCardToLibrary(ptPlains4);
    p1.addCardToLibrary(ptPlains5);
    p1.addCardToLibrary(ptForest1);
    p1.addCardToLibrary(ptForest2);
    p1.addCardToLibrary(ptForest3);
    p1.addCardToLibrary(ptIsland1);




    p1.addCardToLibrary(ptSoldier1);
    p1.addCardToLibrary(ptSoldier2);
    p1.addCardToLibrary(ptSoldier3);
    p1.addCardToLibrary(ptArmored_Pegasus1);
    p1.addCardToLibrary(ptArmored_Pegasus2);
    p1.addCardToLibrary(ptWhite_Knight1);
    p1.addCardToLibrary(ptWhite_Knight2);
    p1.addCardToLibrary(ptAngry_Bear1);
    p1.addCardToLibrary(ptGuard1);
    p1.addCardToLibrary(ptWerewolf1);

    p1.addCardToLibrary(ptDisenchant1);
    p1.addCardToLibrary(ptLightning_Bolt1);
    p1.addCardToLibrary(ptFlood1);
    p1.addCardToLibrary(ptFlood2);

    p1.addCardToLibrary(ptRage1);
    p1.addCardToLibrary(ptHoly_War1);
    p1.addCardToLibrary(ptHoly_Light1);

    std::cout<<"Who Is Player 2"<<std::endl;
    std::string p2Name;
    std::cin>>p2Name;
    player p2(p2Name);

    p2.addCardToLibrary(ptSwamp1);
    p2.addCardToLibrary(ptSwamp2);
    p2.addCardToLibrary(ptSwamp3);
    p2.addCardToLibrary(ptSwamp4);
    p2.addCardToLibrary(ptSwamp5);
    p2.addCardToLibrary(ptMountain1);
    p2.addCardToLibrary(ptMountain2);
    p2.addCardToLibrary(ptMountain3);
    p2.addCardToLibrary(ptIsland2);

    p2.addCardToLibrary(ptSkeleton1);
    p2.addCardToLibrary(ptSkeleton2);
    p2.addCardToLibrary(ptSkeleton3);
    p2.addCardToLibrary(ptGhost1);
    p2.addCardToLibrary(ptGhost2);
    p2.addCardToLibrary(ptBlack_Knight1);
    p2.addCardToLibrary(ptBlack_Knight2);
    p2.addCardToLibrary(ptOrc_Maniac1);
    p2.addCardToLibrary(ptHobgoblin1);
    p2.addCardToLibrary(ptVampire1);

    p2.addCardToLibrary(ptReanimate1);
    p2.addCardToLibrary(ptPlague1);
    p2.addCardToLibrary(ptTerror1);
    p2.addCardToLibrary(ptTerror2);

    p2.addCardToLibrary(ptUnholy_War1);
    p2.addCardToLibrary(ptRestrain1);
    p2.addCardToLibrary(ptSlow1);

    p1.shuffleLibrary();
    p2.shuffleLibrary();

    p1.drawCard();
    p1.drawCard();
    p1.drawCard();
    p1.drawCard();
    p1.drawCard();
    p1.drawCard();
    p2.drawCard();
    p2.drawCard();
    p2.drawCard();
    p2.drawCard();
    p2.drawCard();
    p2.drawCard();


    int turn=1;


    while(!checkForVictory(&p1,&p2)){

        if(p1.getLibrarySize()!=0){
            if(p1.getHandSize()<7){
                p1.drawCard();
            }
        }else{
            std::cout<<"Player 2 WON!!! with "<< p2.getHP() << " health left";
            break;
        }

        if(p2.getLibrarySize()!=0){
            if(p2.getHandSize()<7){
                p2.drawCard();
            }
        }else{
            std::cout<<"Player 1 WON!!! with"<< p1.getHP() << " health left";
            break;
        }

        p1.cardPlayingPhase(&p2,turn);
        p1.attackers();
        p2.defenders(&p1);
        p2.clash(&p1);
        if(checkForVictory(&p1,&p2)){
            break;
        }
        checkForDead(&p1,&p2);
        p2.cardPlayingPhase(&p1,turn);
        p2.attackers();
        p1.defenders(&p2);
        p1.clash(&p2);
        if(checkForVictory(&p1,&p2)){
            break;
        }
        checkForDead(&p1,&p2);
        p1.newRound();
        p2.newRound();
        turn++;
    }
}
