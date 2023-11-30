#include <iostream>
#include <string>
using namespace std;

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
    ;
};

int main()
{
    Human humanOne("Jorge", "Vanovski", 34);
    Human humanTwo("Bera", "Tarlova", 22);

    Student B912206("Program Engineering", 2);

    CharacterHuman Aslagor;
    Aslagor.SetName("Borge");
    Aslagor.SetLevel(10);

    CharacterOrc Trall;
    Trall.SetName("Vogdy");
    Trall.SetLevel(55);
}
