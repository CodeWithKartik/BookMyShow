#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

#include <iostream>
#include "User.h"

static const int InitialRewardPts = 0;
class Member : public User {
protected:
    int reward_points;

    void CallingRewardPointAlgorithm();
public:
    Member(const char *uname, char *psswd);
    Member(const Member &cpy);
    ~Member();
    //Getters
    int GetRewardPoints() const {return reward_points;}
    //Setters
    void SetRewardPoints(int pts) {reward_points = pts;}
    void UpdateRewardPoints();
};
#endif // MEMBER_H_INCLUDED
