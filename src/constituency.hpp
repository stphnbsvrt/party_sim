#include <vector>
#include <iostream>
#include "issue.hpp"

/// @brief Represents a series of positions on issues.
/// TODO: Currently assumed homogenous. Need strategy for internal disagreement on the issue within the constituency.
/// TODO: Record the "significance" or "size" of the constituency to compare against others.
class Constituency {

    /// @brief Name of the constituency
    std::string name;

    /// @brief Container for the constituency's position on issues
    std::vector<Issue*> issue_stances;

public:

    /// @brief Constructor
    Constituency(std::string name) : name(name) {}

    /// @brief Destructor
    ~Constituency() {
        while (issue_stances.size()) {
            delete issue_stances.back();
            issue_stances.pop_back();
        }
    }

    /// @brief Add an issue to the list of stances.
    /// Constituency destructor will delete these pointers
    void add_issue(Issue* issue) {issue_stances.push_back(issue);};

    /// @brief print constituency contents for debug
    std::ostream & print(std::ostream &stream) const {
        stream << name << std::endl;
        for (Issue* issue : issue_stances) {
            stream << "Issue: " << std::endl;
            stream << "  Name: " << issue->get_name() << std::endl;
            stream << "  Stance: " << issue->get_stance() << std::endl;
            stream << "  Importance: " << issue->get_importance() << std::endl;
        }
        return stream;
    }

    /// @brief  Everybody loves stream io
    friend std::ostream & operator<<(std::ostream &stream, const Constituency &constituency) {
      return constituency.print(stream);
    }
};

/// @brief Uses settable params to generate constituencies
class ConstituencyGenerator {

public:

    static Constituency* make_constituency() {
        /// TODO: This is just proof of concept. Need params to actually generate interesting distributions.
        Constituency* constituency = new Constituency("Test!");
        constituency->add_issue(new Issue("Issue0", 0, 0.5));
        constituency->add_issue(new Issue("Issue1", 1, 0.5));
        constituency->add_issue(new Issue("Issue2", 0, 0.1));
        return constituency;
    }

};