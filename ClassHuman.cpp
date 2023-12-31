#include <iostream>
#include <string>
using namespace std;

class IWeapon
{
    public:
        void virtual Take() = 0;
        void virtual Hit() = 0 ;
        void virtual Brake() = 0;
    ;
};

class Axe: public virtual IWeapon
{
    int Strength;
    bool Type; // 0 - ближний бой; 1 - дальний бой;

    void Take() override
    {
        Strength = 100;
        Type = false;
        cout << "You took Axe." << endl;
    }
    void Hit() override
    {
        Strength -= 2;
        cout << "Bang!" << endl;
    }
    void Brake() override
    {
        Strength = 0;
        cout << "You broke Axe." << endl;
    }
};

class Bow: public virtual IWeapon
{
    int Strength;
    bool Type; // 0 - ближний бой; 1 - дальний бой;

    void Take() override
    {
        Strength = 100;
        Type = true;
        cout << "You took Bow." << endl;
    }

    void Hit() override
    {
        Strength -= 1;
        cout << "Fhooooooosh!" << endl;
    }
    void Brake() override
    {
        Strength = 0;
        cout << "You broke Bow." << endl;
    }
};


class GameCharacter
{
    public:
        string NameGame;
        string NickName;
        int Level;

        GameCharacter() // Constructor
        {
            NameGame = "none";
            NickName = "none";
            Level = 0;
        }

        GameCharacter(string namegame, string nickname, int level) // Operator copy
        {
            NameGame = namegame;
            NickName = nickname;
            Level = level;
        }
        // Get Something
        string GetNamegame() const { return NameGame; }
        string GetNickname() const { return NickName; }
        int GetLevel() const { return Level; }
        // Set Something
        void SetNamegame(string newNamegame) { NameGame = newNamegame; }
        void SetNickname(string newNickname) { NickName = newNickname; }
        void SetLevel(int newLevel) { Level = newLevel; }

        virtual void BattleCry()
        {
            cout << "none" << endl;
        }
    ;
};

class Human
{
    private:
        string Name;
        string Surname;
        int Age;
    public:
        Human() // Constructor
        {
            Age = 1;
            Surname = "Ivanov";
            Name = "Ivan";
        }
        
        Human(string name, string surname, int age) // Operator copy
        {
            Age = age;
            Surname = surname;
            Name = name;
        }
        // Get Something
        string GetName() const { return Name; }
        string GetSurname() const { return Surname; }
        int GetAge() const { return Age; }
        // Set Something
        void SetName(string newName) { Name = newName; }
        void SetSurname(string newSurname) { Surname = newSurname; }
        void SetAge(int newAge) { Age = newAge; }

        void TakeWeapon(IWeapon & weapon) { weapon.Take(); }
        void HitWeapon(IWeapon & weapon) { weapon.Hit(); }
        void BrokeWeapon(IWeapon & weapon) { weapon.Brake(); }
    ;
};

class Student: virtual public Human
{
    private:
        string Discipline;
        int Course;
    public:
        Student() // Constructor
        {
            Discipline = "none";
            Course = 0;
        }

        Student(string discipline, int course) // Operator copy
        {
            Discipline = discipline;
            Course = course;
        }
        // Get Something
        string GetDiscipline() const { return Discipline; }
        int GetCourse() const { return Course; }
        // Set Something
        void SetDiscipline(string newDiscipline) { Discipline = newDiscipline; }
        void SetCourse(int newCourse) { Course = newCourse; }
    ;
};

class CharacterHuman: public GameCharacter, public Human
{
    private:
        int Hitpoint;
        int Armor;
    public:
        CharacterHuman() // Constructor
        {
            Hitpoint = 100;
            Armor = 100;
        }

        CharacterHuman(int hitpoint, int armor) // Operator copy
        {
            Hitpoint = hitpoint;
            Armor = armor;
        }
        // Get Something
        int GetHitpoint() { return Hitpoint; }
        int GetArmor() { return Armor; }
        // Set Something
        void SetHitpoint(int newHitpoint) { Hitpoint = newHitpoint; }
        void SetArmor(int newArmor) { Armor = newArmor; }

        void BattleCry() override
        {
            cout << "For Azeroth!" << endl;
        }
    ;
};

class CharacterOrc: public GameCharacter, public Student
{
    private:
        string Rang;
        string Weapon;
    public:
        CharacterOrc() // Constructor
        {
            Rang = "Poor";
            Weapon = "Stone";
        }
        CharacterOrc(string rang, string weapon) // Operator copy
        {
            Rang = rang;
            Weapon = weapon;
        }
        // Get Something
        string GetRang() { return Rang; }
        string GetWeapon() { return Weapon; }
        // Set Somthing
        void SetRang(string newRang) { Rang = newRang; }
        void SetWeapon(string newWeapon) { Weapon = newWeapon; }

        void BattleCry() override
        {
            cout << "Lok tar!" << endl;
        }
    ;
};

class KnightDeath: virtual public CharacterHuman, virtual public CharacterOrc
{
    private:
        int Deathdegree;
        char Strong;
    public:
        KnightDeath() // Constructor
        {
            Deathdegree = 1;
            Strong = 'F';
        }

        KnightDeath(int deathdegree, char strong) // Operator copy
        {
            Deathdegree = deathdegree;
            Strong = strong;
        }
        // Get Something
        int GetDeathdegree() { return Deathdegree; }
        char GetStrong() { return Strong; }
        // Set Something
        void SetDeathdegree(int newDeathdegree) { Deathdegree = newDeathdegree; }
        void SetStrong(char newStrong) { Strong = newStrong; }
    ;
};

int main()
{
    Human humanOne("Jorge", "Vanovski", 34);
    Human humanTwo("Bera", "Tarlova", 22);

    Student B912206("Program Engineering", 2);

    Axe LittleAxe;
    Bow SimpleBow;

    humanOne.TakeWeapon(LittleAxe);
    humanOne.HitWeapon(LittleAxe);
    humanOne.BrokeWeapon(LittleAxe);

    humanTwo.TakeWeapon(SimpleBow);
    humanTwo.HitWeapon(SimpleBow);
    humanTwo.BrokeWeapon(SimpleBow);
    
    CharacterHuman Aslagor;
    Aslagor.SetName("Borge");
    Aslagor.SetLevel(10);

    CharacterOrc Trall;
    Trall.SetName("Vogdy");
    Trall.SetLevel(55);

    KnightDeath Artes;
    Artes.SetRang("Paladin");
    Artes.SetDeathdegree(100);
    Artes.SetStrong('A');

    GameCharacter *character1 = &Trall;
    character1->BattleCry();
    GameCharacter *character2 = &Aslagor;
    character2->BattleCry();
}
