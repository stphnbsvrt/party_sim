#include <string>

class Issue {

    /// @brief  Title for the issue
    std::string name;

    /// @brief Int representing an n-option opinion on the particular issue
    uint32_t stance;

    /// @brief 0 - 1 continuous multiplier for the perceived importance of the issue
    float importance;

public:

    /// @brief Constructor (see params for explanation)
    Issue(std::string name, uint32_t stance, float importance) :
        name(name), stance(stance), importance(importance)
    {}

    /// @brief Accessors
    std::string get_name() {return name;};
    uint32_t get_stance() {return stance;};
    float get_importance() {return importance;};
};