
#include <iostream>
#include <cstdlib> 

using namespace std;

void mainmenu();
void adminmenu();
void customermenu();
void guestmenu();
void shellSort();

class Admin {
private:
    string train_plan[3];
    int train_cost[3];

public:
    void insert_plan() {
        cin.ignore();
        for (int i = 0; i < 3; i++) {
            cout << "\nEnter Training Plan " << i + 1 << ": ";
            getline(cin, train_plan[i]);
            cout << "Enter Training Cost: ";
            cin >> train_cost[i];
            cin.ignore();
        }
    }
    void update_plan() {
        int choice;
        view_training_plan();
        cout << "Choose the training plan to update (1, 2, or 3): ";
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            cin.ignore();
            cout << "Enter the updated Training Plan " << choice << ": ";
            getline(cin, train_plan[choice - 1]);
            cout << "Enter the updated Training Cost for Plan " << choice << ": ";
            cin >> train_cost[choice - 1];
            cout << "Training Plan " << choice << " updated successfully!\n";
        } else {
            cout << "Invalid choice. Please choose between 1, 2, or 3.\n";
        }
    }

    void view_training_plan() {
        cout << "\nTraining Plan\t\tTraining Cost\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << train_plan[i] << "\t\t" << train_cost[i] << endl;
        }
    }

    int get_train_cost(int index) {
        return train_cost[index];
    }
};

Admin obj_admin;

class Customer : public Admin {
public:
    string customer_name;
    int t_plan;
    string cu_plan;
    string weight;
    char tution;
    int tution_hr;

    int tution_fees = 23000;
    int total_cost = 0;
    int private_t;
    string cur_weight;
    char competition;
    int race;
    int comp_fees = 5000;
    int comp = 0;

    int private_tution(char c) {
        if (c == 'y') {
            cout << "\nEnter private tuition hours: ";
            cin >> tution_hr;
            if (tution_hr < 5) {
                total_cost += (tution_fees * tution_hr);
            } else {
                cout << "\nYou exceed the limited private hours\n";
                return private_tution(c);
            }
        }
        return total_cost;
    }

    int weight_categories() {
        int race = 1;
        int current_weight;
        cout << "\n=========Competition Weight Categories========\n\n";
        cout << "Categories\t\t\tWeight Limit\n";
        cout << "1. Heavy Weight\t\t\tover 100\n";
        cout << "2. Light Heavy Weight\t\t100\n";
        cout << "3. Middle Weight\t\t90\n";
        cout << "4. Light MiddleWeight\t\t81\n";
        cout << "5. Light Weight\t\t\t73\n";
        cout << "6. Flyweight\t\t\t66\n";
        cout << "Enter your current weight: ";
        cin >> current_weight;
        if (current_weight > 100) {
            cout << "\nYou can join Heavy Weight Competition\n";
            cur_weight = "Heavy Weight";
        } else if (current_weight == 100) {
            cout << "\nYou can join Light Heavyweight Competition\n";
            cur_weight = "Light Heavy Weight";
        } else if ((current_weight < 100) && (current_weight >= 90)) {
            cout << "\nYou can join Middleweight Competition\n";
            cur_weight = "Middle Weight";
        } else if (current_weight < 90 && current_weight >= 81) {
            cout << "\nYou can join Light Middleweight Competition\n";
            cur_weight = "Light Middle Weight";
        } else if (current_weight < 81 && current_weight >= 73) {
            cout << "\nYou can join Lightweight Competition\n";
            cur_weight = "Lightweight";
        } else if (current_weight < 73 && current_weight >= 66) {
            cout << "\nYou can join Flyweight Competition\n";
            cur_weight = "Flyweight";
        } else {
            cout << "\nYou can't join the competition\n";
            race = 0;
        }
        return race;
    }

    void getdata() {
        cin.ignore();
        cout << "\nEnter customer name: ";
        getline(cin, customer_name);
        obj_admin.view_training_plan();
        cin >> t_plan;
        if (t_plan == 1) {
            cu_plan = "beginner";
            total_cost += obj_admin.get_train_cost(0);
        } else if (t_plan == 2) {
            cu_plan = "intermediate";
            total_cost += obj_admin.get_train_cost(1);
        } else if (t_plan == 3) {
            cu_plan = "Elite";
            total_cost += obj_admin.get_train_cost(2);
        }

        cout << "\nPrivate tuition (y/n): ";
        cin >> tution;
        private_t = private_tution(tution);

        cout << "\nCompetition (y/n): ";
        cin >> competition;

        if (competition == 'n') {
            race = 0; // Set race to 0 if 'n' is entered for tuition or competition
        } else if ((t_plan == 2 || t_plan == 3) && (competition == 'y')) {
            race = weight_categories();
            if (race == 1) {
               
                cout << "Enter number of competitions : ";
                cin >> comp;
                total_cost += (comp_fees * comp);
            } else {
                cout << "\nYou can't join the competition\n";
            }
        } else {
            cout << "\nYou can't compete, you are a beginner\n";
        }
    }

    void showdata() {
    
    	cout << "\t\t"<<customer_name <<"\t\t\t"<<total_cost<<" \t\t\t"<< cur_weight <<
		"\t\t\t"<<cu_plan<<"\n";
    
}

};

Customer obj_customer[3];
int s = 0;

int main() {
    mainmenu();
    return 0;
}

void mainmenu() {
    int user;
    
    cout << "\n1.Admin\n2.Customer\n3.Guest\n\n";
    cin >> user;
    if (user == 1) {
        adminmenu();
        
    } else if (user == 2) {
        customermenu();
    }
     else if (user == 3) {
        guestmenu();
    }
    
}

void adminmenu() {
    int admin_task;
    system("cls"); 
    cout << "\n1.insert plan\n2.update\n3.View Training Plan\n\n";
    cin >> admin_task;
    if (admin_task == 1) {
        obj_admin.insert_plan();
        mainmenu();
    } else if (admin_task == 2) {
        obj_admin.update_plan();
        mainmenu();
    } else if (admin_task == 3) {
        obj_admin.view_training_plan();
        mainmenu();
    }
}

void customermenu() {
    int customer_task;
    system("cls"); 
    char ch;
    cout << "\n1.Register\n2.View information\n\n";
    cin >> customer_task;
    if (customer_task == 1) {
        obj_customer[s].getdata();
        s++;
        cout << "Success inserted \n";
        customermenu();
    } else if (customer_task == 2) {
        shellSort();
        cout << "\t\tCustomer Name\t\tTotal Cost\t\tWeight\t\t\t\tTraining Plan\n\n";
        for (int i = 0; i < s; i++) {
            obj_customer[i].showdata();
        }
        mainmenu();
    }
}

void guestmenu() {
    int guest_task;
    system("cls"); 
    cout << "\nWelcome, Guest!\n";
    cout << "1.View Training Plans\n";
    cin >> guest_task;
    if (guest_task == 1) {
        obj_admin.view_training_plan();
        mainmenu();
    }
}

void shellSort() {
    int n = s;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Customer temp = obj_customer[i];
            int j;
            for (j = i; j >= gap && obj_customer[j - gap].customer_name >
			
			temp.customer_name; j -= gap) {
                obj_customer[j] = obj_customer[j - gap];
            }
            obj_customer[j] = temp;
        }
    }
}
