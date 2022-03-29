#include <iostream>
#include <ctime>

using namespace std;

class Random_number_generator { 
private:
    int your_number = 0, Computer_number=0, correct_ans=0;
public:
    void generated_number() {
        srand((unsigned)time(0));
        Computer_number = ((rand() % 100));
    }
    int get_computer_number() {
        return Computer_number;
    }
    void set_computer_number(int Computer_number) {
        this->Computer_number = Computer_number;
    }
    int get_your_number() {
        return your_number;
    }
    void set_your_number(int your_number) {
        this->your_number = your_number;
    }
};

int main()
{
    int your_number, Computer_number;
    Random_number_generator s;
    s.generated_number();
    int count = 0;
    cout << "This is a Random Number Generator game! You VS Your Computer...Who will win?" << '\n' << "Try to guess the number in Five moves!\n";
    while (s.get_your_number() != s.get_computer_number()) {
        cout << "Please, enter your guess between 1 and 100.\n";
        cin >> your_number;
        s.set_your_number(your_number);
        s.set_computer_number(s.get_computer_number());
        count++;
        if (your_number < 1 || your_number>100) {
            cout << "You entered an ivalid number.\n";
        }
        if (your_number == s.get_computer_number()) {
            cout << "Your answer is CORRECT! You won this game ;)"<< '\n' << "Congrats mate, your total number of guesses : "<< count << '\n';
            return 0;
        }
        else if (abs(your_number - s.get_computer_number()) > 10 && your_number < s.get_computer_number()) {
            cout << "OOps, your number is too low :( , but you are close to the right answer!\n";
        }
        else if (abs(your_number - s.get_computer_number()) < 10 && your_number < s.get_computer_number()) {
            cout << "Almost there, try a higher number!\n";
        }
        else if (abs(your_number-s.get_computer_number()) > 10 && your_number > s.get_computer_number()) {
            cout << "Not right...your number is too high. Try again.\n";
        }
        else if (abs(your_number - s.get_computer_number()) <10 && your_number >s.get_computer_number()) {
            cout << "Still too high, but the right answer is close!\n";
        }
        if (count == 5) {
            cout << "You have reached the maximum amount of tries :( Your Computer won!" <<'\n'<<'\n' << "The Correct answer is " << s.get_computer_number();
            return 0;
        }
    }
}

