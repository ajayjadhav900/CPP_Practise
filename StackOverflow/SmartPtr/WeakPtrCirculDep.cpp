#include <iostream>
#include <memory>
#include <vector>
class Member;

class Team
{
public:
    Team(const std::string &name) : name_(name) {}

    void addMember(std::shared_ptr<Member> member)
    {
        members_.push_back(member);
    }

    const std::string &getName() const { return name_; }

private:
    std::string name_;
    std::vector<std::shared_ptr<Member>> members_;
};

class Member
{
public:
    Member(const std::string &name, std::weak_ptr<Team> team) : name_(name), team_(team) {}

    const std::string &getName() const { return name_; }

    std::shared_ptr<Team> getTeam() const
    {
        return team_.lock();
    }

private:
    std::string name_;
    std::weak_ptr<Team> team_;
};

int main()
{
    // Create a Team
    auto team1 = std::make_shared<Team>("Team A");

    // Create Members and associate them with the Team
    auto member1 = std::make_shared<Member>("Member 1", team1);
    auto member2 = std::make_shared<Member>("Member 2", team1);

    team1->addMember(member1);
    team1->addMember(member2);

    // Access Team from Member
    if (auto team = member1->getTeam())
    {
        std::cout << member1->getName() << " belongs to " << team->getName() << std::endl;
    }

    return 0;
}