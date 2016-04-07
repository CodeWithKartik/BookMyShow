#include "UserDatabase.h"
#include "Member.h"
#include <cstring>
#include <math.h>

UserDatabase::UserDatabase() {
    //Maybe make this a singleton object
    database = new BMSUsers<User>();
    user_count = 0;
}
UserDatabase::UserDatabase(const UserDatabase &cpy) {
    database = new BMSUsers<User>(*(cpy.GetDatabase()));
}
UserDatabase::~UserDatabase() {
    delete database;
}
void UserDatabase::RemoveUser(const char *username) {
    BMSLink<User> *t = database->GetStart();
    while (t != NULL) {
        if (strcmp((t->GetLink())->GetName(), username) == 0) {
            database->SetStart(database->DeleteLink(t));
            user_count--;
            break;
        }
        t = t->GetNext();
    }
}
void UserDatabase::ModifyUser(const char *username, char *new_psswd) {
    BMSLink<User> *t = database->GetStart();
    while (t != NULL) {
        if (strcmp((t->GetLink())->GetName(), username) == 0) {
            (t->GetLink())->SetPsswd(new_psswd);
            break;
        }
        t = t->GetNext();
    }
}
User *UserDatabase::FindUser(User *usr) {
    BMSLink<User> *t = database->GetStart();
    while (t != NULL) {
        if (strcmp((t->GetLink())->GetName(), usr->GetName()) == 0)
            return t->GetLink();
        t = t->GetNext();
    }
    return NULL;
}
User *UserDatabase::AddUser(User *usr) {
    User *tmp = FindUser(usr);
    if (tmp == NULL) {
        BMSLink<User> *t = new BMSLink<User>(usr);
        t->GetLink()->SetUserID(user_count);
        database->SetStart(database->InsertLink(t));
        tmp = FindUser(usr);
        user_count++;
    }else {
        if (strcmp(tmp->GetPsswd(), usr->GetPsswd()) != 0) {
            std::cout<<"Sorry: The password is incorrect. Please try again!\n";
            return NULL;
        }
    }
    return tmp;
}
static unsigned long int char_to_count_converter(std::vector<char> char_num) {
    unsigned long int ct = 0;
    int ind = char_num.size() - 1;
    const int char_to_int = 48;
    while (ind >= 0) {
        ct += (char_num[ind] - char_to_int)*pow(10, char_num.size() - ind - 1);
        ind--;
    }
    return ct;
}
void UserDatabase::PopulateDatabase(std::vector<char> file_array) {
    if (file_array.size() != 0) {
        int user_counts_ind = 73;
        std::vector<char> t_ct;
        register int kct = 0;
        while (file_array[user_counts_ind+kct] != '\n') {
            t_ct.push_back(file_array[user_counts_ind+kct]);
            kct++;
        }
        register unsigned long int ct = char_to_count_converter(t_ct);

        int str_ind = user_counts_ind + kct + 2;
        int utype_ind = 42;
        int uind_ind = 57;
        int details_ind = 70;
        int title_shift = 33;
        int reward_points_offset = 16;
        int a = str_ind;
        register int uid = 0;
        char uname[100], psswd[100];

        for (register int i = 0; i < ct; i++) {
            if (file_array[a+utype_ind] == 'M') {
                register int kt = 0, kp = 0, ku = 0, krw = 0;
                while (file_array[a+uind_ind+ku] != '\n')
                    ku++;
                ku--;
                while (file_array[a+details_ind+ku+kt] != '\n') {
                    uname[kt] = file_array[a+details_ind+ku+kt];
                    kt++;
                }
                uname[kt] = '\0';
                while (file_array[a+details_ind+ku+kt+11+kp] != '\n') {
                    psswd[kp] = file_array[a+details_ind+ku+kt+11+kp];
                    kp++;
                }
                psswd[kp] = '\0';
                std::vector<char> rd_pts;
                while (file_array[a+details_ind+ku+kt+11+kp+reward_points_offset+krw] != '\n') {
                    rd_pts.push_back(file_array[a+details_ind+ku+kt+11+kp+reward_points_offset+krw]);
                    krw++;
                }
                int reward_pts = char_to_count_converter(rd_pts);
                a = a+details_ind+ku+kt+11+kp+reward_points_offset+krw+title_shift;
                Member *new_member = new Member(uname, psswd);
                new_member->SetRewardPoints(reward_pts);
                AddUser(new_member);
            } else {
                register int kt = 0, kp = 0, ku = 0;
                while (file_array[a+uind_ind+ku] != '\n')
                    ku++;
                ku--;
                while (file_array[a+details_ind+ku+kt-1] != '\n') {
                    uname[kt] = file_array[a+details_ind+ku+kt-1];
                    kt++;
                }
                uname[kt] = '\0';
                while (file_array[a+details_ind+ku+kt+11+kp-1] != '\n') {
                    psswd[kp] = file_array[a+details_ind+ku+kt+11+kp-1];
                    kp++;
                }
                psswd[kp] = '\0';
                a = a+details_ind-1+ku+kt+11+kp+title_shift;
                Admin *admin = new Admin(psswd);
                AddUser(admin);
            }
        }
    }
}
void Admin::UpdateUserDatabase(const char *username, char *new_psswd, UserDatabase &obj) {
    obj.ModifyUser(username, new_psswd);
}
std::ostream& operator<<(std::ostream& os, const UserDatabase &udb) {
    os<<"--------------------USER DATABASE STARTS--------------------\n";
    os<<"User count: "<<udb.GetUserCount()<<"\n\n";
    os<<udb.GetDatabase()<<"\n";
    os<<"--------------------USER DATABASE ENDS----------------------\n";
    return os;
}

