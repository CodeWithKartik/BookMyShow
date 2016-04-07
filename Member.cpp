#include "Member.h"
#include <cstring>

Member::Member(const char *uname, char *psswd):User(uname, psswd) {
    reward_points = InitialRewardPts;
}
Member::Member(const Member &cpy):User(cpy) {
    //do nothing
}
Member::~Member() {
    //do nothing
}
void Member::CallingRewardPointAlgorithm() {
    reward_points++;
}
void Member::UpdateRewardPoints() {
    CallingRewardPointAlgorithm();
}
