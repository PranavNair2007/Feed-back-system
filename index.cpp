#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Feedback {
    string customerName;
    int rating;
    string message;
};

void collectFeedback(vector<Feedback>& feedbackList) {
    Feedback fb;

    cout << "\n--- Give Feedback ---\n";
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, fb.customerName);

    cout << "Enter your rating (1-5): ";
    while (!(cin >> fb.rating) || fb.rating < 1 || fb.rating > 5) {
        cout << "Invalid rating. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Enter your feedback message: ";
    cin.ignore();
    getline(cin, fb.message);

    feedbackList.push_back(fb);
    cout << "\nThank You for Your Feedback!\n";
}

void displaySummary(const vector<Feedback>& feedbackList) {
    if (feedbackList.empty()) {
        cout << "\nNo feedback has been collected yet.\n";
        return;
    }

    cout << "\n--- Feedback Summary ---\n";
    double totalRating = 0;

    for (int i = 0; i < feedbackList.size(); i++) {
        cout << "\nFeedback #" << i + 1 << ":\n";
        cout << "  Customer : " << feedbackList[i].customerName << "\n";
        cout << "  Rating   : " << feedbackList[i].rating << " / 5\n";
        cout << "  Message  : " << feedbackList[i].message << "\n";
        totalRating += feedbackList[i].rating;
    }

    double average = totalRating / feedbackList.size();
    cout << "\n----------------------------------------\n";
    cout << "Total Responses : " << feedbackList.size() << "\n";
    cout << fixed << setprecision(1);
    cout << "Average Rating  : " << average << "\n";
    cout << "----------------------------------------\n";
}

void displayMenu() {
    cout << "\n==============================\n";
    cout << "  Customer Feedback System\n";
    cout << "==============================\n";
    cout << "1. Give Feedback\n";
    cout << "2. View Feedback Summary\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Feedback> feedbackList;
    int choice;

    cout << "Welcome to the Customer Feedback System!\n";

    do {
        displayMenu();

        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (choice) {
            case 1:
                collectFeedback(feedbackList);
                break;
            case 2:
                displaySummary(feedbackList);
                break;
            case 3:
                cout << "\nThank you for using the Customer Feedback System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please select 1, 2, or 3.\n";
        }

    } while (choice != 3);

    return 0;
}