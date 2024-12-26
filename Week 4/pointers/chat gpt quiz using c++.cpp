#include <iostream>
#include <string>
#include <array>

using namespace std;

// Function for the introduction
int introduction() {
    int choice;
    cout << "Hey there, welcome to my mini friendship quiz!\n";
    cout << "I would love to confirm your interest in playing first.\n";
    cout << "Input 1 to start\nInput 2 to quit\n";
    cin >> choice;
    return choice;
}

// Function to play the game
std::array<string, 5> game(const array<string, 5>& questions, const array<array<string, 4>, 5>& options) {
    std::array<string, 5> user_answers;

    cout << "The rules for this quiz are listed below:\n";
    cout << "\t- To answer the question, input the capital letter of the option you believe to be correct.\n";
    cout << "\t- To skip a question, input N.\n";
    cout << "\t- To submit your answers, input S.\n";
    
    for (int i = 0; i < 5; i++) {
        cout << "\n" << questions[i] << "\n";
        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << "\n";
        }
        cout << "Enter your answer: ";
        cin >> user_answers[i];
        if (user_answers[i] == "S") {
            cout << "Submission complete. Ending quiz.\n";
            break;
        } else if (user_answers[i] == "N") {
            cout << "Question skipped.\n";
            user_answers[i] = "N/A";
        }
    }
    return user_answers;
}

int main() {
    // Questions and options
    array<string, 5> questions = {
        "What is my name?",
        "How old am I?",
        "What is my favorite sport?",
        "What are my hobbies?",
        "What is my favorite color?"
    };

    array<array<string, 4>, 5> options = {{
        {"A. Johnpaul", "B. John", "C. Kayden", "D. Obama"},
        {"A. 20", "B. 19", "C. 23", "D. 11"},
        {"A. Tennis", "B. Golf", "C. Basketball", "D. Hockey"},
        {"A. Gaming and sleeping", "B. Gaming and watching anime", "C. Gaming and hooping", "D. Driving and playing golf"},
        {"A. Blue", "B. Black", "C. Purple", "D. Grey"}
    }};

    array<string, 5> correct_answers = {"A", "B", "C", "B", "B"};

    // Start the game
    int start = introduction();
    if (start == 1) {
        auto user_answers = game(questions, options);

        // Compare user answers to correct answers
        int score = 0;
        for (size_t i = 0; i < user_answers.size(); i++) {
            if (user_answers[i] == correct_answers[i]) {
                score++;
            }
        }
        cout << "\nYour total score: " << score << "/5\n";
    } else {
        cout << "Thank you for your time. Goodbye!\n";
    }

    return 0;
}
