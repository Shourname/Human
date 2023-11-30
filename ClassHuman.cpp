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

int main()
{
    Human humanOne("Jorge", "Vanovski", 34);
    Human humanTwo("Bera", "Tarlova", 22);

    Student B912206("Program Engineering", 2);
}
