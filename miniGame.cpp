#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <ctime>

using namespace std;



class StunSkill{
protected:
    bool stunEffect;
    double stunBase;
public:
    StunSkill(){
        stunEffect=true;
        stunBase=100.0;}
    bool getStunEffect(){
        return stunEffect;}
    double getStunBase(){
        return stunBase;}
    ~StunSkill(){}

};
class Skill{
protected:
    string name;
public:
Skill(){}
Skill(string name){
    this->name=name;}
void setName(string name){
    this->name=name;}
string getName(){
return name;}

~Skill(){}
};


class UtilitySkill:public Skill{
protected:
public:
    UtilitySkill(string name):Skill(name){}
    ~UtilitySkill(){}
};


class AttackSkill:public Skill{
protected:
    double dmgMod,baseAcc,critMod;
public:
    AttackSkill(){}
    AttackSkill(double dmgMod,double baseAcc,double critMod,string name):Skill(name){
        this->dmgMod=dmgMod;
        this->baseAcc=baseAcc;
        this->critMod=critMod;}
    double getDmgMod(){
        return dmgMod;}
    double getBaseAcc(){
        return baseAcc;}
    double getcritMod(){
        return critMod;}
    ~AttackSkill(){}
};

class Move{
protected:
    int changePosition;
public:
    Move(){
        changePosition=1;
    }
    int getChangePosition(){
        return changePosition;}
    ~Move(){}
};

class Smite:public AttackSkill{
protected:
public:
    Smite():AttackSkill(0.0,85.0,0.0,"Smite"){}
    ~Smite(){}

};
class StunningBlow:public AttackSkill,public StunSkill{
protected:
public:
    StunningBlow():AttackSkill(-50.0,90.0,0.0,"StunningBlow"),StunSkill(){}
    ~StunningBlow(){}
};
class HolyLance:public AttackSkill,public Move{
protected:
public:
    HolyLance():AttackSkill(0.0,85.0,6.5,"HolyLance"),Move(){}
    ~HolyLance(){}
};
class MaceBash:public AttackSkill{
protected:
public:
    MaceBash():AttackSkill(0.0,85.0,0.0,"MaceBash"){}
    ~MaceBash(){}
};
class DazzlingLight:public AttackSkill,public StunSkill{
protected:
public:
    DazzlingLight():AttackSkill(-75.0,90.0,5.0,"DazzlingLight"),StunSkill(){}
    ~DazzlingLight(){}
};
class GraveyardSlash:public AttackSkill{
protected:
public:
    GraveyardSlash():AttackSkill(0.0,85.0,6.0,"GraveyardSlash"){}
    ~GraveyardSlash(){}
};
class GraveyardStumble:public AttackSkill,public Move{
protected:
public:
    GraveyardStumble():AttackSkill(-50.0,45.0,0.0,"GraveyardStumble"),Move(){}
    ~GraveyardStumble(){}
};
class Axeblade:public AttackSkill{
protected:
public:
    Axeblade():AttackSkill(0.0,72.0,6.0,"Axeblade"){}
    ~Axeblade(){}
};
class DeadWeight:public AttackSkill,public StunSkill{
protected:
public:
    DeadWeight():AttackSkill(-25.0,82.0,6.0,"DeadWeight"),StunSkill(){}
    ~DeadWeight(){}
};

class BulwarkOfFaith:public UtilitySkill{
protected:
    double prot;
    int protRound;
public:
    BulwarkOfFaith():UtilitySkill("BulwarkOfFaith"){
        this->prot=20.0;
        this->protRound=3;
    }
    double getProt(){
        return prot;}
    int getProtRound(){
        return protRound;}
    ~BulwarkOfFaith(){}
};
class DivineGrace:public UtilitySkill{
protected:
    int heal;
public:
    DivineGrace():UtilitySkill("DivineGrace"){
        this->heal=rand()%2+4;}
    int getHeal(){
        return heal;}
    ~DivineGrace(){}
};
class DivineComfort:public UtilitySkill{
protected:
    int heal;
public:
    DivineComfort():UtilitySkill("DivineComfort"){
        this->heal=rand()%3+1;}
    int getHeal(){
        return heal;}
    ~DivineComfort(){}
};
class KnittingBones:public UtilitySkill{
protected:
    int heal;
public:
    KnittingBones():UtilitySkill("KnittingBones"){
        this->heal=rand()%2+2;}
    int getHeal(){
        return heal;}
    ~KnittingBones(){}
};





class Unit{
protected:
    int position,maxHp,hp,speed,order,minDmg,maxDmg;
    string name,type;
    double prot,accMod,baseCrit,stunResist,dodge;
    bool stun;
public:
    Unit(){}
    Unit(int position,int maxHp,int hp,int speed,string name,string type,double prot,double accMod,double baseCrit,int minDmg,int maxDmg,double stunResist,double dodge){
        this->position=position;
        this->maxHp=maxHp;
        this->hp=hp;
        this->speed=speed;
        this->name=name;
        this->type=type;
        this->prot=prot;
        this->accMod=accMod;
        this->baseCrit=baseCrit;
        this->minDmg=minDmg;
        this->maxDmg=maxDmg;
        this->stunResist=stunResist;
        this->dodge=dodge;
        this->order=0;
        this->stun=false;}
    void setPosition(int position){
        this->position=position;}
    int getPosition(){
        return position;}
    void setMaxHp(int maxHp){
        this->maxHp=maxHp;}
    int getMaxHp(){
        return maxHp;}
    void setHp(int hp){
        this->hp=hp;
        if(this->hp <= 0){
            this->hp=0;
        }
        else if(this->hp >= this->getMaxHp()){
            this->hp=this->getMaxHp();
        }
    }

    int getHp(){
        return hp;}
    void setName(string name){
        this->name=name;}
    string getName(){
        return name;}
    void setType(string type){
        this->type=type;}
    string getType(){
        return type;}
    void setDodge(double dodge){
        this->dodge=dodge;}
    double getDodge(){
        return dodge;}
    void setProt(double prot){
        this->prot=prot;}
    double getProt(){
        return prot;}
    void setSpeed(int speed){
        this->speed=speed;}
    int getSpeed(){
        return speed;}
    void setAccMod(double accMod){
        this->accMod=accMod;}
    double getAccMod(){
        return accMod;}
    void setBaseCrit(double baseCrit){
        this->baseCrit=baseCrit;}
    double getBaseCrit(){
        return baseCrit;}
    void setMinDmg(int minDmg){
        this->minDmg=minDmg;}
    int getMinDmg(){
        return minDmg;}
    void setMaxDmg(int maxDmg){
        this->maxDmg=maxDmg;}
    int getMaxDmg(){
        return maxDmg;}
    void setStunResist(double stunResist){
        this->stunResist=stunResist;}
    double getStunResist(){
        return stunResist;}
    void setOrder(int order){
        this->order=order;}
    int getOrder(){
        return order;}
    void setStun(bool stun){
        this->stun=stun;}
    bool getStun(){
        return stun;}
    ~Unit(){}
};


class Monster:public Unit{
protected:
public:
    Monster(){}
    Monster(int position,int maxHp,int hp,int speed,string name,string type,double prot,double accMod,double baseCrit,int minDmg,int maxDmg,double stunResist,double dodge):Unit(position,maxHp,hp,speed,name,type,prot,accMod,baseCrit,minDmg,maxDmg,stunResist,dodge){}
    ~Monster(){}
};

class Hero:public Unit{
protected:
    double deathBlowResist;
    int protBonus,deathsDoor,protRound;
public:
    Hero(){}
    Hero(double deathBlowResist,int position,int maxHp,int hp,int speed,string name,string type,double prot,double accMod,double baseCrit,int minDmg,int maxDmg,double stunResist,double dodge):Unit(position,maxHp,hp,speed,name,type,prot,accMod,baseCrit,minDmg,maxDmg,stunResist,dodge){
        this->deathBlowResist=deathBlowResist;
        this->protBonus=0;
        this->deathsDoor=1;}
    void setDeathBlowResist(double deathBlowResist){
        this->deathBlowResist=deathBlowResist;}
    double getDeathBlowResist(){
        return deathBlowResist;}
    void setDeathsDoor(int deathsDoor){
        this->deathsDoor=deathsDoor;}
    int getDeathsDoor(){
        return deathsDoor;}
    void setProtBonus(int protBonus){
        this->protBonus=protBonus;
    }
    void setProtRound(int protRound){
        this->protRound=protRound;
        if(this->protRound<0){
            this->protRound=0;
        }
    }
    int getProtRound(){
        return protRound;
    }
    ~Hero(){}

};


template<class S,class A,class B>
void functionDamage(S skill,vector<A>&a,vector<B>&b,bool &finisher,int aIndex,int bIndex,bool &ifCritic,bool &ifHit){
	///monsters[0]
    double hitChance=skill.getBaseAcc()+a[aIndex].getAccMod()-b[bIndex].getDodge();
    int N=rand()%99+1;
    if(b[bIndex].getHp()>0){
        if(hitChance>=N){
            int criticChance=a[aIndex].getBaseCrit()+skill.getcritMod();
            int X=rand()%99+1;
            double rawDmg;
            double actualDmg;
            double dmg=(rand()%(a[aIndex].getMaxDmg()+a[aIndex].getMinDmg()+1))+a[aIndex].getMinDmg();
            if(criticChance>=X){///critic vurur
                rawDmg=a[aIndex].getMaxDmg()*1.5*(100.0+skill.getDmgMod())/100.0;
                actualDmg=rawDmg-rawDmg*(b[bIndex].getProt()/100.0);
                b[bIndex].setHp(b[bIndex].getHp()-(int)actualDmg);
                cout<<a[aIndex].getName()<<" use "<<skill.getName()<<" on "<<b[bIndex].getName()<<"(Critic Damage:"<<(int)actualDmg<<") "<<b[bIndex].getName()<<" has "<<b[bIndex].getHp()<<" hp"<<endl;
                finisher=false;
                ifCritic=true;
                ifHit=true;

            }
            else if(criticChance<X){///normal vurur
                rawDmg=dmg*(100.0+skill.getDmgMod())/100.0;
                actualDmg=rawDmg-rawDmg*(b[bIndex].getProt()/100.0);
                b[bIndex].setHp(b[bIndex].getHp()-(int)actualDmg);
                cout<<a[aIndex].getName()<<" use "<<skill.getName()<<" on "<<b[bIndex].getName()<<"(Damage:"<<(int)actualDmg<<") "<<b[bIndex].getName()<<" has "<<b[bIndex].getHp()<<" hp"<<endl;
                finisher=false;
                ifCritic=false;
                ifHit=true;
            }


        }
        else if(hitChance<N){
            cout<<a[aIndex].getName()<<" missed the target "<<b[bIndex].getName()<<endl;
            ifHit=false;
            finisher=false;
        }
    }

}



template<class W,class Y,class Z>
void monstersDamage(W skill,vector<Y>&a,vector<Z>&b,bool &finisher,int aIndex,int bIndex,bool &ifCritic,bool &ifHit){
	///monsters[0]
    double hitChance=skill.getBaseAcc()+a[aIndex].getAccMod()-b[bIndex].getDodge();
    int N=rand()%99+1;
    if(b[bIndex].getHp()>0){
        if(hitChance>=N){
            int criticChance=a[aIndex].getBaseCrit()+skill.getcritMod();
            int X=rand()%99+1;
            double rawDmg;
            double actualDmg;
            double dmg=(rand()%(a[aIndex].getMaxDmg()+a[aIndex].getMinDmg()+1))+a[aIndex].getMinDmg();
            if(criticChance>=X){///critic vurur
                rawDmg=a[aIndex].getMaxDmg()*1.5*(100.0+skill.getDmgMod())/100.0;
                actualDmg=rawDmg-rawDmg*(b[bIndex].getProt()/100.0);
                b[bIndex].setHp(b[bIndex].getHp()-(int)actualDmg);
                cout<<a[aIndex].getName()<<" use "<<skill.getName()<<" on "<<b[bIndex].getName()<<"(Critic Damage:"<<(int)actualDmg<<") "<<b[bIndex].getName()<<" has "<<b[bIndex].getHp()<<" hp"<<endl;
                finisher=false;
                ifCritic=true;
                ifHit=true;

            }
            else if(criticChance<X){///normal vurur
                rawDmg=dmg*(100.0+skill.getDmgMod())/100.0;
                actualDmg=rawDmg-rawDmg*(b[bIndex].getProt()/100.0);
                b[bIndex].setHp(b[bIndex].getHp()-(int)actualDmg);
                cout<<a[aIndex].getName()<<" use "<<skill.getName()<<" on "<<b[bIndex].getName()<<"(Damage:"<<(int)actualDmg<<") "<<b[bIndex].getName()<<" has "<<b[bIndex].getHp()<<" hp"<<endl;
                finisher=false;
                ifCritic=false;
                ifHit=true;
            }


        }
        else if(hitChance<N){
            cout<<a[aIndex].getName()<<" missed the target "<<b[bIndex].getName()<<endl;
            ifHit=false;
            finisher=false;
        }
    }

    else if(b[bIndex].getHp()==0){
        if(hitChance>=N){
                b[bIndex].setDeathsDoor(0);
                cout<<a[aIndex].getName()<<" use "<<skill.getName()<<" on "<<b[bIndex].getName()<<" which is on Death's Door"<<endl;
                finisher=false;
                ifCritic=false;
                ifHit=false;
        }
        else if(hitChance<N){
            cout<<a[aIndex].getName()<<" missed the target "<<b[bIndex].getName()<<endl;
            ifHit=false;
            finisher=false;
        }

    }
}

template<class P>
void heroesDeleting(vector<P>&a,int i){
    if(a[i].getHp()==0 && a[i].getDeathsDoor()==0){
        cout<<a[i].getName()<<" died"<<endl;
        a.push_back(a[i]);
        a.erase(a.begin()+i);
        a.erase(a.end());
    }
    else if(a[i].getHp()==0){
        cout<<a[i].getName()<<" on Death's Door"<<endl;
    }
}

void KnittingBonesHeal(vector<Monster>&a,int i,bool &finisher){
    int heal=rand()%2+2;
    int chance=rand()%(a.size());
    a[chance].setHp(a[chance].getHp()+heal);
    cout<<a[i].getName()<<" use KnittingBones on "<<a[chance].getName()<<"(New hp:"<<a[chance].getHp()<<")"<<endl;
    finisher=false;
}


template<class C>
void deleting(vector<C>&a,int i){
    if(a[i].getHp()==0){
        cout<<a[i].getName()<<" died"<<endl;
        a.push_back(a[i]);
        a.erase(a.begin()+i);
        a.erase(a.end());

    }
}


template<class D,class E>
void stunFunction(D skill,vector<E>&b,int bIndex,bool ifCritic,bool ifHit){
    int randomNumber;
    if(ifHit==true){
        int stunSuccessChance;
        if(ifCritic==true){
            stunSuccessChance=20.0+skill.getStunBase()-b[bIndex].getStunResist();
            randomNumber=rand()%99+1;
            if(randomNumber<=stunSuccessChance){
                b[bIndex].setStun(true);
                cout<<b[bIndex].getName()<<" is stunned!"<<endl;
            }
            else{
                cout<<b[bIndex].getName()<<" is not stunned!"<<endl;
            }
        }
        else if(ifCritic==false){
            stunSuccessChance=skill.getStunBase()-b[bIndex].getStunResist();
            randomNumber=rand()%99+1;
            if(randomNumber<=stunSuccessChance){
                b[bIndex].setStun(true);
                cout<<b[bIndex].getName()<<" is stunned!"<<endl;
            }
            else{
                cout<<b[bIndex].getName()<<" is not stunned!"<<endl;
            }
        }
    }

}

template<class F,class G>
void moveFunction(vector<F>&a,int i,G skill){
    if(a.size()>(i+1)){
        cout<<a[i].getName()<<" chance the position with "<<a[i+skill.getChangePosition()].getName()<<endl;
        swap(a[i],a[i+skill.getChangePosition()]);
    }
    else{
        cout<<a[i].getName()<<" can not move! There is no one behind!"<<endl;
    }
}



void DivineGraceFunction(vector<Hero>&a,int i,bool &finisher){
    int heal=rand()%2+4;
    int chance=rand()%(a.size());
    a[chance].setHp(a[chance].getHp()+heal);
    cout<<a[i].getName()<<" use DivineGrace on "<<a[chance].getName()<<"(New hp:"<<a[chance].getHp()<<")"<<endl;
    finisher=false;
}


void DivineComfortFunction(vector<Hero>&a,int i,bool &finisher){
    int heal=rand()%3+1;
    cout<<a[i].getName()<<" use DivineComfort on all friends"<<endl;
    for(unsigned int j=0;j<a.size();j++){
        a[j].setHp(a[j].getHp()+heal);
        cout<<a[j].getName()<<"(New hp:"<<a[j].getHp()<<")"<<endl;
    }
    finisher=false;
}





class Crusader:public Hero{
protected:
    Smite s;
    StunningBlow sb;
    HolyLance hl;
    BulwarkOfFaith bof;
public:
    Crusader():Hero(67.0,0,33,33,1,"","Crusader",0.0,0.0,3.0,6.0,12.0,40.0,5.0){}
    void crusaderAttack(vector<Hero>&heroes,vector<Monster>&monsters,int i){
        if((heroes[i].getHp()!=0)&&(heroes[i].getStun()==false)){
            int chance;///hangi indexteki yaratiga vuracagi...
            bool ifCritic,ifHit;
            ///double hitChance;
            bool finisher=true;
            while(finisher){
            if(monsters.size()==0){
                finisher=false;
            }
            else{
                if(((i+1)==1)||((i+1)==2)){
                    chance=rand()%20+1;
                    if(chance>0 && chance<10){ ///smite
                        ///int N;
                        if(monsters.size()==0){
                            finisher=false;
                        }
                        else if(monsters.size()==1){
                            functionDamage(s,heroes,monsters,finisher,i,0,ifCritic,ifHit);
                            deleting(monsters,0);
                        }
                        else if(monsters.size()>1){
                            chance=rand()%2;
                            functionDamage(s,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                            deleting(monsters,chance);
                            ///monsters[chance] buna saldiricaz

                        }

                    }
                    else if(chance>9 && chance<19){///stunning blow
                        if(monsters.size()==0){
                            finisher=false;
                        }
                        else if(monsters.size()==1){
                            functionDamage(sb,heroes,monsters,finisher,i,0,ifCritic,ifHit);
                            ///stun fonksiyonu gelecek
                            stunFunction(sb,monsters,0,ifCritic,ifHit);
                            deleting(monsters,0);
                        }
                        else if(monsters.size()>1){
                            chance=rand()%2;
                            functionDamage(sb,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                            ///stun fonksiyonu gelicek
                            stunFunction(sb,monsters,0,ifCritic,ifHit);
                            deleting(monsters,chance);
                        }
                    }
                    else if(chance>18 && chance<21){///bof
                        cout<<heroes[i].getName()<<" use "<<bof.getName()<<endl;
                        heroes[i].setProt(bof.getProt());
                        heroes[i].setProtRound(bof.getProtRound());
                        finisher=false;
                    }
                }
                else if(((i+1)==3)||((i+1)==4)){///holylance
                    if(monsters.size()==0){
                        finisher=false;
                    }

                    else if(monsters.size()==1){
                        finisher=false;
                    }

                    else if(monsters.size()==2){
                        functionDamage(hl,heroes,monsters,finisher,i,1,ifCritic,ifHit);
                        ///move fonksiyonu
                        moveFunction(heroes,i,hl);
                        deleting(monsters,1);
                    }
                    else if(monsters.size()==3){
                        chance=rand()%2+1;
                        functionDamage(hl,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                        ///move fonksiyonu
                        moveFunction(heroes,i,hl);
                        deleting(monsters,chance);
                    }
                    else if(monsters.size()==4){
                        chance=rand()%3+1;
                        functionDamage(hl,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                        ///move fonksiyonu
                        moveFunction(heroes,i,hl);
                        deleting(monsters,chance);
                    }

                }

            }

        }
    }
    }
    ~Crusader(){}
};


class Vestal:public Hero{
protected:
    MaceBash mb;
    DazzlingLight dl;
    DivineGrace dg;
    DivineComfort dc;
public:
    Vestal():Hero(77.0,0,24,24,4,"","Vestal",0.0,0.0,1.0,4.0,8.0,30.0,0.0){}
    void vestalAttack(vector<Hero>&heroes,vector<Monster>&monsters,int i){
        if((heroes[i].getHp()!=0)&&(heroes[i].getStun()==false)){
            int chance;///hangi indexteki yaratiga vuracagi...
            bool ifCritic,ifHit;
            ///double hitChance;
            bool finisher=true;
            while(finisher){
                if(monsters.size()==0){
                    finisher=false;
                }
                else{
                    if((i+1)==1){
                        chance=rand()%10+1;
                        if(chance==1){///divine comfort
                            DivineComfortFunction(heroes,i,finisher);
                        }
                        else {///macebash
                            if(monsters.size()==1){
                                functionDamage(mb,heroes,monsters,finisher,i,0,ifCritic,ifHit);
                                deleting(monsters,0);
                            }
                            else if(monsters.size()>1){
                                chance=rand()%2;
                                functionDamage(mb,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                                deleting(monsters,chance);
                            ///monsters[chance] buna saldiricaz

                            }
                        }
                    }

                    else if((i+1)==2){
                        chance=rand()%20+1;
                        if(chance>0 && chance<10){///mace bash
                            if(monsters.size()==1){
                                functionDamage(mb,heroes,monsters,finisher,i,0,ifCritic,ifHit);
                                deleting(monsters,0);
                            }
                            else if(monsters.size()>1){
                                chance=rand()%2;
                                functionDamage(mb,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                                deleting(monsters,chance);
                            ///monsters[chance] buna saldiricaz

                            }
                        }
                        else if(chance>9 && chance<19){///dazzling light
                            if(monsters.size()==1){
                                functionDamage(dl,heroes,monsters,finisher,i,0,ifCritic,ifHit);
                                ///stun fonksiyonu gelecek
                                stunFunction(dl,monsters,0,ifCritic,ifHit);
                                deleting(monsters,0);
                            }
                            else if(monsters.size()==2){
                                chance=rand()%2;
                                functionDamage(dl,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                                ///stun fonksiyonu gelecek
                                stunFunction(dl,monsters,chance,ifCritic,ifHit);
                                deleting(monsters,chance);
                            }
                            else if(monsters.size()>=3){
                                chance=rand()%3;
                                functionDamage(dl,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                                ///stun fonksiyonu gelecek
                                stunFunction(dl,monsters,chance,ifCritic,ifHit);
                                deleting(monsters,chance);
                            }
                        }
                        else if(chance>18 && chance<21){///divine comfort
                            DivineComfortFunction(heroes,i,finisher);
                        }
                    }
                    else if(((i+1)==3)||(i+1)==4){
                        chance=rand()%20+1;
                        if(chance<19 && chance>0){///dazzling light
                            if(monsters.size()==1){
                                functionDamage(dl,heroes,monsters,finisher,i,0,ifCritic,ifHit);
                                ///stun fonksiyonu gelecek
                                stunFunction(dl,monsters,0,ifCritic,ifHit);
                                deleting(monsters,0);
                            }
                            else if(monsters.size()==2){
                                chance=rand()%2;
                                functionDamage(dl,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                                ///stun fonksiyonu gelecek
                                stunFunction(dl,monsters,chance,ifCritic,ifHit);
                                deleting(monsters,chance);
                            }
                            else if(monsters.size()>=3){
                                chance=rand()%3;
                                functionDamage(dl,heroes,monsters,finisher,i,chance,ifCritic,ifHit);
                                ///stun fonksiyonu gelecek
                                stunFunction(dl,monsters,chance,ifCritic,ifHit);
                                deleting(monsters,chance);
                            }
                        }

                        else if(chance==19){///divine grace
                            DivineGraceFunction(heroes,i,finisher);
                        }
                        else if(chance==20){/// divine comfort
                            DivineComfortFunction(heroes,i,finisher);
                        }
                    }

                }

            }
        }
    }
    ~Vestal(){}
};

class Bone_Soldier:public Monster{
protected:
    GraveyardSlash gs;
    GraveyardStumble gsb;
public:
    Bone_Soldier():Monster(0,10,10,2,"","Bone_Soldier",15.0,0.0,0.0,3.0,8.0,25.0,10.0){}
    void boneSoldierAttack(vector<Monster>&monsters,vector<Hero>&heroes,int i){
        if((monsters[i].getHp()!=0)&&(monsters[i].getStun()==false)){
            int chance;///hangi indexteki yaratiga vuracagi...
            bool ifCritic,ifHit;
            ///double hitChance;
            bool finisher=true;
            while(finisher){
                if(heroes.size()==0){
                    finisher=false;
                }
                else{
                    if((i+1)==1 || (i+1)==2 || (i+1)==3){///graveyard slash
                        if(heroes.size()==1){
                            monstersDamage(gs,monsters,heroes,finisher,i,0,ifCritic,ifHit);
                            heroesDeleting(heroes,0);
                        }
                        else if(heroes.size()==2){
                            chance=rand()%2;
                            monstersDamage(gs,monsters,heroes,finisher,i,chance,ifCritic,ifHit);
                            heroesDeleting(heroes,chance);
                        }
                        else if(heroes.size()>=3){
                            chance=rand()%3;
                            monstersDamage(gs,monsters,heroes,finisher,i,chance,ifCritic,ifHit);
                            heroesDeleting(heroes,chance);
                        }
                    }
                    else if((i+1)==4){///graveyard stumble
                        if(heroes.size()==1){
                            monstersDamage(gsb,monsters,heroes,finisher,i,0,ifCritic,ifHit);
                            ///move fonksiyonu
                            moveFunction(monsters,i,gsb);
                            heroesDeleting(heroes,0);
                        }
                        else if(heroes.size()>=2){
                            chance=rand()%2;
                            monstersDamage(gsb,monsters,heroes,finisher,i,chance,ifCritic,ifHit);
                            ///move fonksiyonu
                            moveFunction(monsters,i,gsb);
                            heroesDeleting(heroes,chance);

                        }
                    }

                }
            }
        }

    }
    ~Bone_Soldier(){}
};
class Bone_Defender:public Monster{
protected:
    Axeblade ab;
    DeadWeight dw;
    KnittingBones kb;
public:
    Bone_Defender():Monster(0,22,22,1,"","Bone_Defender",45.0,0.0,0.0,2.0,4.0,45.0,8.0){}
    void boneDefenderAttack(vector<Monster>&monsters,vector<Hero>&heroes,int i){
        if((monsters[i].getHp()!=0)&&(monsters[i].getStun()==false)){
            int chance;///hangi indexteki yaratiga vuracagi...
            bool ifCritic,ifHit;
            ///double hitChance;
            bool finisher=true;
            while(finisher){
                if(heroes.size()==0){
                    finisher=false;
                }
                else{
                    if((i+1)==1 || (i+1)==2){
                        if(heroes.size()==1){
                            chance=rand()%2;
                            if(chance==0){///axeblade
                                monstersDamage(ab,monsters,heroes,finisher,i,0,ifCritic,ifHit);
                                heroesDeleting(heroes,0);
                            }
                            else if(chance==1){///deadweight
                                monstersDamage(ab,monsters,heroes,finisher,i,0,ifCritic,ifHit);
                                stunFunction(dw,heroes,0,ifCritic,ifHit);
                                heroesDeleting(heroes,0);
                            }
                        }
                        else if(heroes.size()>=2){
                             chance=rand()%2;
                             if(chance==0){///axeblade
                                chance=rand()%2;
                                monstersDamage(ab,monsters,heroes,finisher,i,chance,ifCritic,ifHit);
                                heroesDeleting(heroes,chance);
                             }
                             else if(chance==1){///deadweight
                                chance=rand()%2;
                                monstersDamage(ab,monsters,heroes,finisher,i,chance,ifCritic,ifHit);
                                stunFunction(dw,heroes,chance,ifCritic,ifHit);
                                heroesDeleting(heroes,chance);
                             }
                        }
                    }
                    else if((i+1)==3){
                        chance=rand()%10;
                        if(chance==0){///knitting bones
                            KnittingBonesHeal(monsters,i,finisher);
                        }
                        else{///deadweight
                            chance=rand()%2;
                            monstersDamage(ab,monsters,heroes,finisher,i,chance,ifCritic,ifHit);
                            stunFunction(dw,heroes,chance,ifCritic,ifHit);
                            heroesDeleting(heroes,chance);
                        }
                    }
                    else if((i+1)==4){///knittingbones
                        KnittingBonesHeal(monsters,i,finisher);
                    }
                }

            }
        }

    }

    ~Bone_Defender(){}
};

int main()
{
    srand(time(NULL));
    Crusader c1,c2;
    Vestal v1,v2;
    Bone_Soldier bs1,bs2;
    Bone_Defender bd1,bd2;
    c1.setName("Crusader#1");
    c1.setPosition(1);
    c2.setName("Crusader#2");
    c2.setPosition(2);
    v1.setName("Vestal#1");
    v1.setPosition(3);
    v2.setName("Vestal#2");
    v2.setPosition(4);
    bs1.setName("Bone_Soldier#1");
    bs1.setPosition(1);
    bs2.setName("Bone_Soldier#2");
    bs2.setPosition(3);
    bd1.setName("Bone_Defender#1");
    bd1.setPosition(2);
    bd2.setName("Bone_Defender#2");
    bd2.setPosition(4);
    vector<Hero>heroes;
    vector<Monster>monsters;
    heroes.push_back(c1);
    heroes.push_back(c2);
    heroes.push_back(v1);
    heroes.push_back(v2);
    monsters.push_back(bs1);
    monsters.push_back(bd1);
    monsters.push_back(bs2);
    monsters.push_back(bd2);
    vector<Hero>::iterator vPtr;
    vector<Monster>::iterator mPtr;
    vPtr=heroes.begin();
    mPtr=monsters.begin();

    ///swap(heroes[0],heroes[1]);
    ///mPtr->asdsad();
    ///myVector.erase(myVector.begin()+4);

    int roundIndex=0;
    bool control=true;
    ///while döngüsü olacak
while(control){
    roundIndex++;
    int total=heroes.size()+monsters.size();
    int randomSpeed[total];

    for(unsigned int i=0;i<heroes.size();i++){
        heroes[i].setSpeed(heroes[i].getSpeed()+rand()%8+1);
        randomSpeed[i]=heroes[i].getSpeed();
    }
    for(unsigned int i=0;i<monsters.size();i++){
        monsters[i].setSpeed(monsters[i].getSpeed()+rand()%8+1);
        randomSpeed[heroes.size()+i]=monsters[i].getSpeed();
    }
    int temp;
    for(int i=0;i<(total-1);i++){
        for(int j=0;j<(total-1);j++){
            if(randomSpeed[j]<randomSpeed[j+1]){
                temp=randomSpeed[j];
                randomSpeed[j]=randomSpeed[j+1];
                randomSpeed[j+1]=temp;
            }
        }
    }

    for(int i=0;i<total;i++){
        bool x=false;
        for(unsigned int j=0;j<heroes.size();j++){
            if((heroes[j].getSpeed()==randomSpeed[i])&&(heroes[j].getOrder()==0)){
                heroes[j].setOrder(i+1);
                x=true;
                break;
            }
        }
        if(x){
            continue;
        }
        for(unsigned int k=0;k<monsters.size();k++){
            if((monsters[k].getSpeed()==randomSpeed[i])&&(monsters[k].getOrder()==0)){
                monsters[k].setOrder(i+1);
                break;
            }
        }
    }

    cout<<roundIndex<<". Round Start*****"<<endl;
    for(int i=0;i<total;i++){///burasi sirayla saldirma yeri
        for(unsigned j=0;j<heroes.size();j++){
            if(heroes[j].getOrder()==(i+1)){
                if(heroes[j].getType()=="Crusader"){
                    ///cout<<heroes[j].getName()<<endl;
                    c1.crusaderAttack(heroes,monsters,j);
                }
                else if(heroes[j].getType()=="Vestal"){
                    ///cout<<heroes[j].getName()<<endl;
                    v1.vestalAttack(heroes,monsters,j);
                }
            }
        }
        for(unsigned int k=0;k<monsters.size();k++){
            if(monsters[k].getOrder()==(i+1)){
                if(monsters[k].getType()=="Bone_Soldier"){
                    ///cout<<monsters[k].getName()<<endl;
                    bs1.boneSoldierAttack(monsters,heroes,k);
                }
                else if(monsters[k].getType()=="Bone_Defender"){
                    ///cout<<monsters[k].getName()<<endl;
                    bd1.boneDefenderAttack(monsters,heroes,k);
                }
            }
        }
    }
    cout<<roundIndex<<". Round End*****"<<endl;
    cout<<endl;
    if(heroes.size()==0 || monsters.size()==0){///oyunu bitirme
        if(heroes.size()==0){
            cout<<"All heroes dead"<<endl;
        }
        else if(monsters.size()==0){
            cout<<"All monsters dead"<<endl;
        }
        control=false;
    }
    ///asagisi stunlari sifirlama
    for(unsigned int i=0;i<heroes.size();i++){
        heroes[i].setStun(false);
    }
    for(unsigned int i=0;i<monsters.size();i++){
        monsters[i].setStun(false);
    }

    ///asagisi crusader protlarinin roundunu azaltma
    for(int i=0;i<heroes.size();i++){
        if(heroes[i].getType()=="Crusader"){
            heroes[i].setProtRound(heroes[i].getProtRound()-1);
            if(heroes[i].getProtRound()==0){
                heroes[i].setProt(0.0);
            }
        }
    }
    if(roundIndex==50){
        control=false;
    }

}
std::unique_ptr<Unit>ptrA=std::make_unique<Unit>();



return 0;
}
