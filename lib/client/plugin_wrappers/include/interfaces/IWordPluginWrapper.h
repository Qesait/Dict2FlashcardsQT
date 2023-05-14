#ifndef IWORDPLUGINWRAPPER_H
#define IWORDPLUGINWRAPPER_H

#include <string>

#include "Card.h"
#include "interfaces/IBasicPluginWrapper.h"

class IWordPluginWrapper : virtual public IBasicPluginWrapper {
 public:
    virtual std::pair<std::vector<Card>, std::string>
                        get(const std::string &word,
                            const std::string &query,
                            size_t             batch_size) = 0;
    virtual std::pair<std::string, std::string> get_dict_scheme()      = 0;
};

#endif  // IWORDPLUGINWRAPPER_H
